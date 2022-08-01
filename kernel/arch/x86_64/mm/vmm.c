/*
 * Copyright 2021, 2022 NSG650
 * Copyright 2021, 2022 Sebastian
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cpu/cr.h>
#include <cpu_features.h>
#include <cpuid.h>
#include <debug/debug.h>
#include <mm/pmm.h>
#include <mm/slab.h>
#include <mm/vmm.h>
#include <sys/prcb.h>

struct pagemap kernel_pagemap;

extern char text_start_addr[], text_end_addr[];
extern char rodata_start_addr[], rodata_end_addr[];
extern char data_start_addr[], data_end_addr[];

static uint64_t *get_next_level(uint64_t *current_level, size_t entry) {
	uint64_t *ret;
	if (current_level[entry] & 1) {
		// Present flag set
		ret = (uint64_t *)(size_t)(current_level[entry] & ~((uint64_t)0xFFF));
	} else {
		// Allocate a table for the next level
		ret = pmm_allocz(1);
		// Present + writable + user (0b111)
		current_level[entry] = (size_t)ret | 0b111;
	}

	return ret;
}

volatile struct limine_hhdm_request hhdm_request = {.id = LIMINE_HHDM_REQUEST,
													.revision = 0};

static volatile struct limine_kernel_address_request kernel_address_request = {
	.id = LIMINE_KERNEL_ADDRESS_REQUEST, .revision = 0};

static volatile struct limine_5_level_paging_request five_level_paging_request =
	{.id = LIMINE_5_LEVEL_PAGING_REQUEST, .revision = 0};

void vmm_init(struct limine_memmap_entry **memmap, size_t memmap_entries) {
	kernel_pagemap.top_level = pmm_allocz(1);
	for (uint64_t p = 256; p < 512; p++)
		get_next_level(kernel_pagemap.top_level, p);

	for (uint64_t p = 0; p < 0x200000; p += PAGE_SIZE) {
		if (p != 0) {
			vmm_map_page(&kernel_pagemap, p, p, 0b111, Size4KiB);
		}
		vmm_map_page(&kernel_pagemap, p + MEM_PHYS_OFFSET, p, 0b111, Size4KiB);
	}

	for (uint64_t p = 0x200000; p < 0x40000000; p += 0x200000) {
		vmm_map_page(&kernel_pagemap, p, p, 0b111, Size2MiB);
		vmm_map_page(&kernel_pagemap, p + MEM_PHYS_OFFSET, p, 0b111, Size2MiB);
	}

	for (uint64_t p = 0x40000000; p < 4096UL * 1024 * 1024; p += 0x40000000) {
		vmm_map_page(&kernel_pagemap, p, p, 0b111, Size1GiB);
		vmm_map_page(&kernel_pagemap, p + MEM_PHYS_OFFSET, p, 0b111, Size1GiB);
	}

	for (size_t i = 0; i < memmap_entries; i++) {
		uint64_t base = memmap[i]->base;
		uint64_t length = memmap[i]->length;
		uint64_t top = base + length;

		if (base < 0x100000000)
			base = 0x100000000;

		if (base >= top)
			continue;

		uint64_t aligned_base = ALIGN_DOWN(base, 0x40000000);
		uint64_t aligned_top = ALIGN_UP(top, 0x40000000);
		uint64_t aligned_length = aligned_top - aligned_base;

		for (uint64_t j = 0; j < aligned_length; j += 0x40000000) {
			uint64_t page = aligned_base + j;
			vmm_map_page(&kernel_pagemap, page, page, 0b111, Size1GiB);
			vmm_map_page(&kernel_pagemap, page + MEM_PHYS_OFFSET, page, 0b111,
						 Size1GiB);
		}
	}

	uintptr_t text_start = ALIGN_DOWN((uintptr_t)text_start_addr, PAGE_SIZE),
			  rodata_start =
				  ALIGN_DOWN((uintptr_t)rodata_start_addr, PAGE_SIZE),
			  data_start = ALIGN_DOWN((uintptr_t)data_start_addr, PAGE_SIZE),
			  text_end = ALIGN_UP((uintptr_t)text_end_addr, PAGE_SIZE),
			  rodata_end = ALIGN_UP((uintptr_t)rodata_end_addr, PAGE_SIZE),
			  data_end = ALIGN_UP((uintptr_t)data_end_addr, PAGE_SIZE);

	uint64_t paddr = kernel_address_request.response->physical_base;
	uint64_t vaddr = kernel_address_request.response->virtual_base;

	for (uintptr_t text_addr = text_start; text_addr < text_end;
		 text_addr += PAGE_SIZE) {
		uintptr_t phys = text_addr - vaddr + paddr;
		vmm_map_page(&kernel_pagemap, text_addr, phys, 1, Size4KiB);
	}

	for (uintptr_t rodata_addr = rodata_start; rodata_addr < rodata_end;
		 rodata_addr += PAGE_SIZE) {
		uintptr_t phys = rodata_addr - vaddr + paddr;
		vmm_map_page(&kernel_pagemap, rodata_addr, phys, 1 | 1ull << 63ull,
					 Size4KiB);
	}

	for (uintptr_t data_addr = data_start; data_addr < data_end;
		 data_addr += PAGE_SIZE) {
		uintptr_t phys = data_addr - vaddr + paddr;
		vmm_map_page(&kernel_pagemap, data_addr, phys, 0b11 | 1ull << 63ull,
					 Size4KiB);
	}
	// Switch to the new page map, dropping Limine's default one
	vmm_switch_pagemap(&kernel_pagemap);
}

void vmm_switch_pagemap(struct pagemap *pagemap) {
	asm volatile("mov cr3, %0" : : "r"(pagemap->top_level) : "memory");
}

// Creates a new dynamically allocated page map
struct pagemap *vmm_new_pagemap(void) {
	struct pagemap *pagemap = kmalloc(sizeof(struct pagemap));
	pagemap->top_level = pmm_allocz(1);
	for (size_t i = 256; i < 512; i++)
		pagemap->top_level[i] = kernel_pagemap.top_level[i];
	return pagemap;
}

// Maps a page, without the present bit in "flags" (bit 0), unmaps a page
void vmm_map_page(struct pagemap *pagemap, uint64_t virt_addr,
				  uint64_t phys_addr, uint64_t flags, enum page_size pg_size) {
	// Calculate the indices in the various tables using the virtual address
	size_t pml5_entry = (virt_addr & ((uint64_t)0x1FF << 48)) >> 48;
	size_t pml4_entry = (virt_addr & ((uint64_t)0x1FF << 39)) >> 39;
	size_t pml3_entry = (virt_addr & ((uint64_t)0x1FF << 30)) >> 30;
	size_t pml2_entry = (virt_addr & ((uint64_t)0x1FF << 21)) >> 21;
	size_t pml1_entry = (virt_addr & ((uint64_t)0x1FF << 12)) >> 12;

	uint64_t *pml5, *pml4, *pml3, *pml2, *pml1;

	if (five_level_paging_request.response != NULL) {
		pml5 = pagemap->top_level;
		goto level5;
	} else {
		pml4 = pagemap->top_level;
		goto level4;
	}

level5:
	pml4 = get_next_level(pml5, pml5_entry);
level4:
	pml3 = get_next_level(pml4, pml4_entry);

	if (pg_size == Size1GiB) {
		uint32_t a = 0, b = 0, c = 0, d = 0;
		__get_cpuid(0x80000001, &a, &b, &c, &d);
		// Check for 1GiB pages support.
		if (d & CPUID_GBPAGE) {
			pml3[pml3_entry] = phys_addr | flags | (1 << 7);
			return;
		} else {
			// If 1GiB pages are not supported then emulate it by splitting
			// them into 2MiB pages.
			for (uint64_t i = 0; i < 0x40000000; i += 0x200000) {
				vmm_map_page(pagemap, virt_addr + i, phys_addr + i, flags,
							 Size2MiB);
			}
		}
	}

	pml2 = get_next_level(pml3, pml3_entry);

	if (pg_size == Size2MiB) {
		pml2[pml2_entry] = phys_addr | flags | (1 << 7);
		return;
	}

	pml1 = get_next_level(pml2, pml2_entry);

	pml1[pml1_entry] = phys_addr | flags;
}

// Only works for 4KiB pages
uint64_t vmm_virt_to_phys(struct pagemap *pagemap, uint64_t virt_addr) {
	size_t pml5_entry = (virt_addr & ((uint64_t)0x1FF << 48)) >> 48;
	size_t pml4_entry = (virt_addr & ((uint64_t)0x1FF << 39)) >> 39;
	size_t pml3_entry = (virt_addr & ((uint64_t)0x1FF << 30)) >> 30;
	size_t pml2_entry = (virt_addr & ((uint64_t)0x1FF << 21)) >> 21;
	size_t pml1_entry = (virt_addr & ((uint64_t)0x1FF << 12)) >> 12;

	uint64_t *pml5, *pml4, *pml3, *pml2, *pml1;

	if (five_level_paging_request.response != NULL) {
		pml5 = pagemap->top_level;
		goto level5;
	} else {
		pml4 = pagemap->top_level;
		goto level4;
	}

level5:
	pml4 = get_next_level(pml5, pml5_entry);
level4:
	pml3 = get_next_level(pml4, pml4_entry);

	pml2 = get_next_level(pml3, pml3_entry);
	pml1 = get_next_level(pml2, pml2_entry);

	if (!(pml1[pml1_entry] & 1))
		return 0;

	return (pml1[pml1_entry]) & ~((uintptr_t)0xfff);
}

uint64_t vmm_virt_to_kernel(struct pagemap *pagemap, uint64_t virt_addr) {
	uint64_t aligned_virtual_address = ALIGN_DOWN(virt_addr, PAGE_SIZE);
	uint64_t phys_addr = vmm_virt_to_phys(pagemap, virt_addr);
	return (phys_addr + MEM_PHYS_OFFSET + virt_addr - aligned_virtual_address);
}

void vmm_page_fault_handler(registers_t *reg) {
	uint64_t faulting_address = read_cr("2");
	bool present = reg->errorCode & 0x1;
	bool read_write = reg->errorCode & 0x2;
	bool user_supervisor = reg->errorCode & 0x4;
	bool reserved = reg->errorCode & 0x8;
	bool execute = reg->errorCode & 0x10;
	if (reg->cs & 0x3) {
		struct thread *thrd = prcb_return_current_cpu()->running_thread;
		kprintf("Killing user thread tid %d under process %s for\n", thrd->tid,
				thrd->mother_proc->name);
		kprintf("Page fault at 0x%p present: %s, read/write: %s, "
				"user/supervisor: %s, reserved: %s, execute: %s\n",
				faulting_address, present ? "P" : "NP", read_write ? "R" : "RW",
				user_supervisor ? "U" : "S", reserved ? "R" : "NR",
				execute ? "X" : "NX");
		thread_kill(thrd, 1);
	}
	panic_((void *)reg->rip, (void *)reg->rbp,
		   "Page fault at 0x%p present: %s, read/write: %s, "
		   "user/supervisor: %s, reserved: %s, execute: %s\n",
		   faulting_address, present ? "P" : "NP", read_write ? "R" : "RW",
		   user_supervisor ? "U" : "S", reserved ? "R" : "NR",
		   execute ? "X" : "NX");
}
