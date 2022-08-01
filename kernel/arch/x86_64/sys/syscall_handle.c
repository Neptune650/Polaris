#include <mm/vmm.h>
#include <sched/sched.h>
#include <sched/syscall.h>
#include <sys/isr.h>
#include <sys/prcb.h>

void syscall_handler(registers_t *reg) {
	struct syscall_arguments args = {.syscall_nr = reg->rax,
									 .args0 = reg->rdi,
									 .args1 = reg->rsi,
									 .args2 = reg->rdx,
									 .args3 = reg->r10,
									 .args4 = reg->r8,
									 .args5 = reg->r9,
									 .ret = reg->rax};
	syscall_handle(&args);
	reg->rax = args.ret;
}

void syscall_install_handler(void) {
	isr_register_handler(0x80, syscall_handler);
}

void syscall_helper_copy_to_user(uintptr_t user_addr, void *buffer,
								 size_t count) {
	vmm_switch_pagemap(&kernel_pagemap);

	struct process *proc =
		prcb_return_current_cpu()->running_thread->mother_proc;
	struct pagemap *target_pagemap = proc->process_pagemap;

	uint64_t kernel_addr = vmm_virt_to_kernel(target_pagemap, user_addr);

	memcpy((void *)kernel_addr, buffer, count);

	vmm_switch_pagemap(target_pagemap);
}