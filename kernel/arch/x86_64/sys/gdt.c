#include <sys/gdt.h>
#include <klibc/mem.h>
#include <locks/spinlock.h>
struct gdt_desc {
	uint16_t limit;
	uint16_t base_low;
	uint8_t base_mid;
	uint8_t access;
	uint8_t granularity;
	uint8_t base_hi;
} __attribute__((packed));

struct tss_desc {
	uint16_t length;
	uint16_t base_low;
	uint8_t base_mid;
	uint8_t flags1;
	uint8_t flags2;
	uint8_t base_hi;
	uint32_t base_upper32;
	uint32_t reserved;
} __attribute__((packed));

struct gdt_ptr {
	uint16_t limit;
	uint64_t ptr;
} __attribute__((packed));

struct gdtr {
	struct gdt_desc entries[5];
	struct tss_desc tss;
} __attribute__((packed));

struct gdtr gdt = {0};
struct gdt_ptr gdt_pointer = {0};
lock_t gdt_lock = {0};

extern void gdt_reload(void);
extern void tss_reload(void);

void gdt_init(void) {
	spinlock_acquire(gdt_lock);
	// Kernel code
	gdt.entries[1].access = 0b10011010;
	gdt.entries[1].granularity = 0b00100000;

	// Kernel data
	gdt.entries[2].access = 0b10010010;

	// User data
	gdt.entries[3].access = 0b11110010;

	// User code
	gdt.entries[4].access = 0b11111010;
	gdt.entries[4].granularity = 0b00100000;

	// TSS
	gdt.tss.length = sizeof(struct tss);
	gdt.tss.flags1 = 0b10001001;

	// Set the pointer
	gdt_pointer.limit = sizeof(gdt) - 1;
	gdt_pointer.ptr = (uint64_t)&gdt;

	gdt_reload();
	tss_reload();
	spinlock_drop(gdt_lock);
}

void gdt_load_tss(size_t addr) {
	spinlock_acquire(gdt_lock);
	gdt.tss.base_low = (uint16_t)addr;
	gdt.tss.base_mid = (uint8_t)(addr >> 16);
	gdt.tss.flags1 = 0b10001001;
	gdt.tss.base_hi = (uint8_t)(addr >> 24);
	gdt.tss.base_upper32 = (uint32_t)(addr >> 32);

	tss_reload();
	spinlock_drop(gdt_lock);
}

