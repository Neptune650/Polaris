#include "symbols.h"

sym_table_t symbol_table[] = {
	{0xffffffff80000000, "acpi_checksum"},
	{0xffffffff8000001b, "init_ec"},
	{0xffffffff800007c3, "ioapic_read"},
	{0xffffffff800007dc, "ioapic_write"},
	{0xffffffff800007f5, "get_gsi_count"},
	{0xffffffff8000080b, "get_ioapic_by_gsi"},
	{0xffffffff80000871, "lapic_read"},
	{0xffffffff800008b4, "lapic_write"},
	{0xffffffff800008f9, "lapic_set_nmi"},
	{0xffffffff80000df4, "wrxcr"},
	{0xffffffff80000e04, "xsave"},
	{0xffffffff80000e0f, "xrstor"},
	{0xffffffff80000e1a, "fxsave"},
	{0xffffffff80000e1e, "fxrstor"},
	{0xffffffff80000f36, "cpu_init"},
	{0xffffffff80002a38, "pic_disable"},
	{0xffffffff80002c42, "octal_to_int"},
	{0xffffffff80002dc1, "devtmpfs_mount"},
	{0xffffffff80002dc9, "devtmpfs_populate"},
	{0xffffffff80002dcf, "devtmpfs_mkdir"},
	{0xffffffff80002e34, "devtmpfs_open"},
	{0xffffffff8000300e, "devtmpfs_close"},
	{0xffffffff80002faa, "devtmpfs_read"},
	{0xffffffff80002f04, "devtmpfs_write"},
	{0xffffffff80003076, "tmpfs_populate"},
	{0xffffffff8000307c, "tmpfs_mkdir"},
	{0xffffffff800030ee, "tmpfs_open"},
	{0xffffffff8000330e, "tmpfs_close"},
	{0xffffffff800032aa, "tmpfs_read"},
	{0xffffffff80003204, "tmpfs_write"},
	{0xffffffff800031bf, "tmpfs_mount"},
	{0xffffffff80003340, "fstype2fs"},
	{0xffffffff8000376e, "path2node"},
	{0xffffffff800041df, "lookup"},
	{0xffffffff8000434a, "_out_buffer"},
	{0xffffffff80004354, "_out_null"},
	{0xffffffff80004355, "_out_fct"},
	{0xffffffff8000436e, "_atoi"},
	{0xffffffff80004396, "_out_rev"},
	{0xffffffff8000444f, "_ntoa_format"},
	{0xffffffff800045dc, "_ntoa_long"},
	{0xffffffff800046b2, "_ntoa_long_long"},
	{0xffffffff80004788, "_etoa"},
	{0xffffffff80004b09, "_ftoa"},
	{0xffffffff80004efc, "_vsnprintf"},
	{0xffffffff8000597c, "_out_char"},
	{0xffffffff80005c75, "twist"},
	{0xffffffff80005e73, "stub_close"},
	{0xffffffff80005e79, "stub_read"},
	{0xffffffff80005e81, "stub_write"},
	{0xffffffff80005e89, "stub_ioctl"},
	{0xffffffff8000641e, "inner_alloc"},
	{0xffffffff80006643, "get_next_level"},
	{0xffffffff80006bb9, "alloc_new_process"},
	{0xffffffff80007a92, "is_transmit_empty"},
	{0xffffffff80007ba2, "bcdtobin"},
	{0xffffffff80007bb1, "is_updating"},
	{0xffffffff80007bd3, "read"},
	{0xffffffff80007c04, "rtc_get_time"},
	{0xffffffff80007c4d, "rtc_get_date_time"},
	{0xffffffff80008657, "make_pci_address"},
	{0xffffffff80008674, "mcfg_pci_write"},
	{0xffffffff80008784, "mcfg_pci_read"},
	{0xffffffff800088b7, "legacy_pci_write"},
	{0xffffffff80008965, "legacy_pci_read"},
	{0xffffffff8000982f, "lai_read_buffer"},
	{0xffffffff800098c2, "lai_write_buffer"},
	{0xffffffff8000a3b6, "lai_parse_u32"},
	{0xffffffff8000a3fc, "lai_exec_pop_blkstack_back"},
	{0xffffffff8000a41f, "lai_exec_pop_stack_back"},
	{0xffffffff8000a442, "lai_exec_push_ctxstack"},
	{0xffffffff8000a497, "lai_exec_push_blkstack"},
	{0xffffffff8000a4ee, "lai_exec_push_stack"},
	{0xffffffff8000a520, "lai_exec_push_opstack"},
	{0xffffffff8000a57f, "lai_parse_varint"},
	{0xffffffff8000a69f, "lai_exec_commit_pc"},
	{0xffffffff8000a6ca, "lai_exec_reserve_ctxstack"},
	{0xffffffff8000a765, "lai_exec_reserve_blkstack"},
	{0xffffffff8000a806, "lai_exec_reserve_stack"},
	{0xffffffff8000a8b2, "lai_parse_name"},
	{0xffffffff8000a8d6, "lai_exec_reduce_node"},
	{0xffffffff8000b023, "lai_exec_reduce_op"},
	{0xffffffff8000e92c, "lai_cleanup_free_string"},
	{0xffffffff8000e957, "lai_exec_parse"},
	{0xffffffff80014b09, "lai_exec_process"},
	{0xffffffff80016a7a, "lai_exec_run"},
	{0xffffffff80017b7b, "lai_hash_string"},
	{0xffffffff80017b9e, "lai_load_table"},
	{0xffffffff80017c25, "lai_hashtable_grow"},
	{0xffffffff80019567, "lai_object_type_of_objref"},
	{0xffffffff800195ac, "lai_object_type_of_node"},
	{0xffffffff80019662, "lai_clone_string"},
	{0xffffffff800197e4, "lai_clone_buffer"},
	{0xffffffff8001ac6e, "lai_clone_package"},
	{0xffffffff8001b0c4, "lai_buffer_put_at"},
	{0xffffffff8001b132, "lai_buffer_get_at"},
	{0xffffffff8001b1a9, "lai_calculate_access_width"},
	{0xffffffff8001b251, "lai_find_parent_root_of"},
	{0xffffffff8001b338, "lai_get_pci_params"},
	{0xffffffff8001b5ac, "lai_perform_read"},
	{0xffffffff8001b9c3, "lai_perform_write"},
	{0xffffffff8001c5f6, "laihost_free_package"},
	{0xffffffff8001c7ce, "is_digit"},
	{0xffffffff8001c7dc, "num_fmt"},
	{0xffffffff8001cd44, "poll_ibf"},
	{0xffffffff8001cd62, "poll_obf"},
	{0xffffffff8001cd80, "disable_burst"},
	{0xffffffff8001cdb0, "enable_burst"},
	{0xffffffff8001d23c, "readq"},
	{0xffffffff8001d328, "readd"},
	{0xffffffff8001d3ab, "readw"},
	{0xffffffff8001d403, "readb"},
	{0xffffffff8001d4dc, "writeq"},
	{0xffffffff8001d5c4, "writed"},
	{0xffffffff8001d647, "writew"},
	{0xffffffff8001d69c, "writeb"},
	{0xffffffff8001d8f5, "lai_bios_calc_checksum"},
	{0xffffffff8001eca2, "lai_get_header_info"},
	{0xffffffff8001faad, "liballoc_memset"},
	{0xffffffff8001fac7, "liballoc_memcpy"},
	{0xffffffff8001fb02, "allocate_new_page"},
	{0xffffffff80017e44, "lai_uninstall_nsnode"},
	{0xffffffff8000751f, "running_thrd"},
	{0xffffffff800176a7, "lai_eval_vargs"},
	{0xffffffff8001c2d4, "lai_write_indexfield"},
	{0xffffffff80005fdb, "strcpy"},
	{0xffffffff8001d437, "lai_write_ec"},
	{0xffffffff80007b4d, "write_serial"},
	{0xffffffff80009400, "_putchar"},
	{0xffffffff8002011d, "krealloc"},
	{0xffffffff80000d0a, "apic_init"},
	{0xffffffff800011f2, "smp_init"},
	{0xffffffff80000532, "laihost_sleep"},
	{0xffffffff8000964c, "bswap16"},
	{0xffffffff80000375, "laihost_unmap"},
	{0xffffffff8000972d, "lai_eisaid"},
	{0xffffffff80004268, "alloc"},
	{0xffffffff8000341f, "vfs_get_absolute_path"},
	{0xffffffff80007913, "thread_exit"},
	{0xffffffff80019409, "lai_ns_child_iterate"},
	{0xffffffff8000a32c, "lai_exec_get_integer"},
	{0xffffffff80009621, "lai_is_name"},
	{0xffffffff8000a304, "lai_exec_get_objectref"},
	{0xffffffff80000c7f, "apic_timer_init"},
	{0xffffffff80009680, "bswap64"},
	{0xffffffff80016abd, "lai_init_state"},
	{0xffffffff8000860f, "hpet_counter_value"},
	{0xffffffff80002b28, "port_dword_out"},
	{0xffffffff80019884, "lai_create_pkg"},
	{0xffffffff80000544, "laihost_timer"},
	{0xffffffff80005b8b, "vprintf_"},
	{0xffffffff80003fa0, "user_test_shit"},
	{0xffffffff8001798b, "lai_panic"},
	{0xffffffff8001f2b7, "lai_resource_irq_is_active_low"},
	{0xffffffff800177f9, "lai_enable_tracing"},
	{0xffffffff80017a5b, "lai_calloc"},
	{0xffffffff80003d73, "stivale2_get_tag"},
	{0xffffffff8000056b, "init_madt"},
	{0xffffffff80009707, "char_to_hex"},
	{0xffffffff80009bd6, "lai_exec_ref_store"},
	{0xffffffff8000433c, "liballoc_unlock"},
	{0xffffffff8001a6d5, "lai_obj_to_buffer"},
	{0xffffffff800004ee, "laihost_pci_readw"},
	{0xffffffff800004cc, "laihost_pci_readb"},
	{0xffffffff8001c4f7, "lai_var_finalize"},
	{0xffffffff80009981, "lai_exec_string_length"},
	{0xffffffff80002a29, "isr_register_handler"},
	{0xffffffff80018b09, "lai_do_resolve_new_node"},
	{0xffffffff80004244, "symbols_return_function_name"},
	{0xffffffff80017dea, "lai_current_instance"},
	{0xffffffff8001f5a3, "lai_disable_acpi"},
	{0xffffffff8001aa87, "lai_obj_to_integer"},
	{0xffffffff80006b09, "vmm_page_fault_handler"},
	{0xffffffff800063b2, "vec_swapsplice_"},
	{0xffffffff80003d6f, "user_halt"},
	{0xffffffff800067b3, "vmm_init"},
	{0xffffffff8001991b, "lai_obj_resize_string"},
	{0xffffffff80009b8f, "lai_store_ns"},
	{0xffffffff80000376, "laihost_scan"},
	{0xffffffff800178d1, "lai_warn"},
	{0xffffffff80017df2, "lai_create_nsnode"},
	{0xffffffff800099c4, "lai_exec_pkg_var_store"},
	{0xffffffff8001ef00, "lai_resource_iterate"},
	{0xffffffff8001c4c8, "lai_do_rev_method"},
	{0xffffffff80017817, "lai_debug"},
	{0xffffffff80019efa, "lai_obj_to_string"},
	{0xffffffff8001ff88, "kfree"},
	{0xffffffff80001347, "set_idt"},
	{0xffffffff80008546, "gdt_load_tss"},
	{0xffffffff80000146, "acpi_init"},
	{0xffffffff80007b26, "write_serial_char"},
	{0xffffffff80002b24, "port_dword_in"},
	{0xffffffff80006679, "vmm_switch_pagemap"},
	{0xffffffff800195cf, "lai_create_string"},
	{0xffffffff8000861e, "hpet_usleep"},
	{0xffffffff800070bf, "process_sleep"},
	{0xffffffff8001c6b7, "lai_var_move"},
	{0xffffffff80005a62, "sprintf_"},
	{0xffffffff800035bd, "vfs_new_node"},
	{0xffffffff80000a1e, "lapic_init"},
	{0xffffffff80007130, "process_wait"},
	{0xffffffff8001ed00, "lai_read_resource"},
	{0xffffffff800065a1, "pmm_alloc"},
	{0xffffffff800062aa, "vec_compact_"},
	{0xffffffff800196f2, "lai_create_c_string"},
	{0xffffffff80019755, "lai_create_buffer"},
	{0xffffffff8001eb82, "lai_acpi_reset"},
	{0xffffffff800084e5, "gdt_init"},
	{0xffffffff800191be, "lai_resolve_search"},
	{0xffffffff8000368b, "vfs_mkdir"},
	{0xffffffff8001817e, "lai_ns_get_child"},
	{0xffffffff8001853f, "lai_stringify_node_path"},
	{0xffffffff8000926c, "putchar_at"},
	{0xffffffff8001f67f, "lai_evaluate_sta"},
	{0xffffffff80007759, "thread_init"},
	{0xffffffff80016cff, "lai_populate"},
	{0xffffffff8001f771, "lai_init_children"},
	{0xffffffff800063e3, "vec_swap_"},
	{0xffffffff80016b37, "lai_finalize_state"},
	{0xffffffff80000bc9, "ioapic_redirect_irq"},
	{0xffffffff8001c258, "lai_read_indexfield"},
	{0xffffffff8001c3c6, "lai_do_osi_method"},
	{0xffffffff80000452, "laihost_pci_writeb"},
	{0xffffffff80000c20, "apic_send_ipi"},
	{0xffffffff80000346, "laihost_malloc"},
	{0xffffffff8001705d, "lai_eval_args"},
	{0xffffffff8001d764, "lai_read_pm_timer_value"},
	{0xffffffff80006680, "vmm_new_pagemap"},
	{0xffffffff80005bb2, "vsnprintf_"},
	{0xffffffff80007aa8, "serial_install"},
	{0xffffffff80004312, "liballoc_lock"},
	{0xffffffff80007d47, "get_unix_timestamp"},
	{0xffffffff80019a48, "lai_obj_resize_pkg"},
	{0xffffffff8000637f, "vec_splice_"},
	{0xffffffff8001943b, "lai_ns_override_notify"},
	{0xffffffff80007903, "thread_unblock"},
	{0xffffffff80019bd3, "lai_obj_get_integer"},
	{0xffffffff80018420, "lai_stringify_amlname"},
	{0xffffffff80003d8b, "kernel_main"},
	{0xffffffff80007f78, "load_elf"},
	{0xffffffff80009ab6, "lai_operand_load"},
	{0xffffffff80006621, "pmm_free"},
	{0xffffffff8001c0c2, "lai_read_field"},
	{0xffffffff80005bd0, "fctprintf"},
	{0xffffffff80007df6, "dump_section_table"},
	{0xffffffff8001ce01, "lai_early_init_ec"},
	{0xffffffff80006f66, "process_exit"},
	{0xffffffff80009c43, "lai_exec_mutate_ns"},
	{0xffffffff8001ad3f, "lai_objecttype_ns"},
	{0xffffffff80007a2a, "thread_sleep"},
	{0xffffffff800061cd, "vec_expand_"},
	{0xffffffff8000965b, "bswap32"},
	{0xffffffff800078dd, "thread_block"},
	{0xffffffff80017764, "lai_eval_largs"},
	{0xffffffff80000510, "laihost_pci_readd"},
	{0xffffffff8000047c, "laihost_pci_writew"},
	{0xffffffff800094d2, "kprint"},
	{0xffffffff80006c8e, "process_create"},
	{0xffffffff80019060, "lai_resolve_path"},
	{0xffffffff80003fd8, "_start"},
	{0xffffffff8001d9f3, "lai_bios_detect_rsdp"},
	{0xffffffff80008a03, "pci_init"},
	{0xffffffff80005ddd, "rand"},
	{0xffffffff80006f50, "process_unblock"},
	{0xffffffff80018970, "lai_do_resolve"},
	{0xffffffff8001923e, "lai_check_device_pnp_id"},
	{0xffffffff8001f227, "lai_resource_irq_is_level_triggered"},
	{0xffffffff80017ac9, "lai_strcmp"},
	{0xffffffff8001d7a1, "lai_start_pm_timer"},
	{0xffffffff80005f4e, "strncmp"},
	{0xffffffff800042dd, "liballoc_alloc"},
	{0xffffffff80003a9f, "vfs_mount"},
	{0xffffffff80001366, "isr_install"},
	{0xffffffff80001307, "return_installed_cpus"},
	{0xffffffff80006049, "strncpy"},
	{0xffffffff800182db, "lai_amlname_parse"},
	{0xffffffff8001ada5, "lai_obj_exec_match_op"},
	{0xffffffff8001a046, "lai_mutate_string"},
	{0xffffffff800039bd, "vfs_open"},
	{0xffffffff800040f9, "panic"},
	{0xffffffff8001c899, "lai_vsnprintf"},
	{0xffffffff80009469, "kprintbgc"},
	{0xffffffff80018638, "lai_install_nsnode"},
	{0xffffffff80009131, "knewline"},
	{0xffffffff800065e4, "pmm_allocz"},
	{0xffffffff80018179, "lai_ns_get_parent"},
	{0xffffffff80007257, "process_kill"},
	{0xffffffff80002b55, "syscall_init"},
	{0xffffffff80000e3f, "wsmp_cpu_init"},
	{0xffffffff80017afc, "lai_snprintf"},
	{0xffffffff800183cf, "lai_amlname_done"},
	{0xffffffff800003f7, "laihost_outb"},
	{0xffffffff80009107, "draw_px"},
	{0xffffffff8001d910, "lai_bios_detect_rsdp_within"},
	{0xffffffff80006d56, "process_init"},
	{0xffffffff8001c1cd, "lai_write_field"},
	{0xffffffff800093cf, "putchar_color"},
	{0xffffffff80005d8a, "srand"},
	{0xffffffff800193c6, "lai_ns_iterate"},
	{0xffffffff8000041a, "laihost_outd"},
	{0xffffffff800033a4, "vfs_install_fs"},
	{0xffffffff80019547, "lai_ns_get_opregion_address_space"},
	{0xffffffff8001f450, "lai_get_sci_event"},
	{0xffffffff80002b0e, "port_byte_in"},
	{0xffffffff8001acde, "lai_objecttype_obj"},
	{0xffffffff8000032c, "laihost_panic"},
	{0xffffffff80002b1d, "port_word_out"},
	{0xffffffff80019520, "lai_set_acpi_revision"},
	{0xffffffff800075c4, "alloc_new_thread"},
	{0xffffffff8001a62f, "lai_obj_clone"},
	{0xffffffff800029a3, "isr_handler"},
	{0xffffffff8000942b, "kprint_color"},
	{0xffffffff8001a91c, "lai_obj_to_hex_string"},
	{0xffffffff80006286, "vec_reserve_po2_"},
	{0xffffffff8001f345, "lai_resource_next_irq"},
	{0xffffffff80005f2d, "strcmp"},
	{0xffffffff80008b34, "pci_write"},
	{0xffffffff8001d6dd, "lai_query_ec"},
	{0xffffffff80006e2f, "process_fork"},
	{0xffffffff80003985, "vfs_new_node_deep"},
	{0xffffffff80006f24, "process_block"},
	{0xffffffff80017e28, "lai_create_nsnode_or_die"},
	{0xffffffff800183de, "lai_amlname_iterate"},
	{0xffffffff80019cd5, "lai_mutate_buffer"},
	{0xffffffff80017a8e, "lai_strlen"},
	{0xffffffff80002bda, "dev_new_id"},
	{0xffffffff80018c6a, "lai_resolve_new_node"},
	{0xffffffff80002a5c, "pic_init"},
	{0xffffffff80008583, "hpet_init"},
	{0xffffffff8001dad1, "lai_pci_parse_prt"},
	{0xffffffff8001d885, "lai_busy_wait_pm_timer"},
	{0xffffffff80000c6a, "apic_eoi"},
	{0xffffffff80000563, "acpi_get_lapic"},
	{0xffffffff80005edb, "resource_create"},
	{0xffffffff80006489, "pmm_init"},
	{0xffffffff80005afc, "snprintf_"},
	{0xffffffff80005d25, "get_rdseed"},
	{0xffffffff80002b12, "port_byte_out"},
	{0xffffffff80000b19, "ioapic_redirect_gsi"},
	{0xffffffff8001e15a, "lai_pci_find_bus"},
	{0xffffffff80019c3e, "lai_obj_get_handle"},
	{0xffffffff8001d1a5, "lai_read_ec"},
	{0xffffffff8000096b, "timer_interrupt"},
	{0xffffffff800042f5, "liballoc_free"},
	{0xffffffff8001e044, "lai_pci_find_device"},
	{0xffffffff80000e30, "wrmsr"},
	{0xffffffff800094e7, "draw_rect"},
	{0xffffffff8000035c, "laihost_free"},
	{0xffffffff800099e1, "lai_exec_access"},
	{0xffffffff80018caf, "lai_create_root"},
	{0xffffffff8000a094, "lai_operand_emplace"},
	{0xffffffff800194a9, "lai_ns_get_node_type"},
	{0xffffffff80008b5e, "ssfn_utf8"},
	{0xffffffff800177e3, "lai_eval"},
	{0xffffffff800099aa, "lai_exec_pkg_var_load"},
	{0xffffffff8001e6e7, "lai_enter_sleep"},
	{0xffffffff8001e670, "lai_pci_route"},
	{0xffffffff80005991, "printf_"},
	{0xffffffff80008c0e, "ssfn_putc"},
	{0xffffffff80003c09, "vfs_dump_nodes"},
	{0xffffffff8001bf23, "lai_write_field_internal"},
	{0xffffffff80009a49, "lai_exec_ref_load"},
	{0xffffffff8001a24e, "lai_obj_to_type_string"},
	{0xffffffff8001a4ba, "lai_mutate_integer"},
	{0xffffffff80000444, "laihost_ind"},
	{0xffffffff80002b18, "port_word_in"},
	{0xffffffff8000907b, "vid_reset"},
	{0xffffffff8001f862, "lai_enable_acpi"},
	{0xffffffff800004a6, "laihost_pci_writed"},
	{0xffffffff80019b31, "lai_obj_get_type"},
	{0xffffffff8000130f, "set_idt_gate"},
	{0xffffffff80006232, "vec_reserve_"},
	{0xffffffff8001fb77, "kmalloc"},
	{0xffffffff80008b13, "pci_read"},
	{0xffffffff8001c38e, "lai_write_opregion"},
	{0xffffffff800074ee, "running_proc"},
	{0xffffffff800199ae, "lai_obj_resize_buffer"},
	{0xffffffff80000351, "laihost_realloc"},
	{0xffffffff80002b2e, "syscall_handler"},
	{0xffffffff80003cbe, "vfs_stat"},
	{0xffffffff80019463, "lai_ns_override_opregion"},
	{0xffffffff8001e442, "lai_pci_route_pin"},
	{0xffffffff8001be13, "lai_read_field_internal"},
	{0xffffffff800072e6, "sched_init"},
	{0xffffffff8001d859, "lai_stop_pm_timer"},
	{0xffffffff800066ac, "vmm_map_page"},
	{0xffffffff80018ec7, "lai_create_namespace"},
	{0xffffffff80005f8b, "strlen"},
	{0xffffffff800095aa, "lai_api_error_to_string"},
	{0xffffffff80002c64, "initramfs_init"},
	{0xffffffff800002e5, "laihost_log"},
	{0xffffffff80009e24, "lai_operand_mutate"},
	{0xffffffff80000428, "laihost_inb"},
	{0xffffffff8001a7bc, "lai_obj_to_decimal_string"},
	{0xffffffff800061ac, "strchr"},
	{0xffffffff80006315, "vec_insert_"},
	{0xffffffff80007810, "thread_create"},
	{0xffffffff8000094f, "sci_interrupt"},
	{0xffffffff80019c05, "lai_obj_get_pkg"},
	{0xffffffff8001f4fe, "lai_set_sci_event"},
	{0xffffffff80003040, "devtmpfs_add_device"},
	{0xffffffff80009090, "video_init"},
	{0xffffffff8001c481, "lai_do_os_method"},
	{0xffffffff8001f13d, "lai_resource_get_type"},
	{0xffffffff800200ed, "kcalloc"},
	{0xffffffff80009549, "clear_screen"},
	{0xffffffff80017aac, "lai_strcpy"},
	{0xffffffff80007550, "yield_to_scheduler"},
	{0xffffffff800060fe, "strchrnul"},
	{0xffffffff80000e22, "rdmsr"},
	{0xffffffff80018166, "lai_ns_get_root"},
	{0xffffffff80000210, "acpi_find_sdt"},
	{0xffffffff80000436, "laihost_inw"},
	{0xffffffff80000409, "laihost_outw"},
	{0xffffffff8001cea3, "lai_init_ec"},
	{0xffffffff800093eb, "putcharx"},
	{0xffffffff80002c17, "dev_add_new"},
	{0xffffffff80000367, "laihost_map"},
	{0xffffffff800042ba, "free"},
	{0xffffffff8001c64e, "lai_swap_object"},
	{0xffffffff8001c353, "lai_read_opregion"},
	{0xffffffff8001c71d, "lai_var_assign"},
	{0xffffffff, ""}};

static sym_table_t lookup(uint64_t address) {
	size_t i;
	for (i = 0; symbol_table[i].address != 0xffffffff; i++)
		if ((symbol_table[i].address << 52) == (address << 52))
			return symbol_table[i];
	return symbol_table[i];
}

const char *symbols_return_function_name(uint64_t address) {
	sym_table_t table = lookup(address);
	if (table.address == 0xffffffff)
		return "UNKNOWN";
	return table.function_name;
}
