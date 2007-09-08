# -----------------------------------------------------------------------------
#   iphone-binutils: development tools for the Apple iPhone        07/13/2007
#   Copyright (c) 2007 Patrick Walton <pcwalton@uchicago.edu> but freely
#   redistributable under the terms of the GNU General Public License v2.
#
#   arm-dyld-glue-pic.s: ARM PIC binding helper routines, part of crt1.o
# -----------------------------------------------------------------------------

    .text
    .private_extern dyld_stub_binding_helper
    .align 2 
dyld_stub_binding_helper:
#ifdef __PIC__
    str r12,[sp,#-4]!
    ldr r12,Ldyld_stub_binding_helper$mhsn
Ldyld_stub_binding_helper$mhsn_scv:
    ldr r12,[pc,r12]
    str r12,[sp,#-4]!
    ldr r12,Ldyld_stub_binding_helper$dclb
Ldyld_stub_binding_helper$dclb_scv:
    ldr pc,[pc,r12]

Ldyld_stub_binding_helper$mhsn:
    .long dyld__mh_dylib_header-(Ldyld_stub_binding_helper$mhsn_scv+8)
Ldyld_stub_binding_helper$dclb:
    .long dyld_content_lazy_binder-(Ldyld_stub_binding_helper$dclb_scv+8)
#else
    str ip,[sp,#-4]!
    ldr ip,Ldyld_stub_binding_helper$mhsn
    str ip,[sp,#-4]!
    ldr ip,Ldyld_stub_binding_helper$dclb
    ldr pc,[ip,#0]

Ldyld_stub_binding_helper$mhsn:
    .long MACH_HEADER_SYMBOL_NAME
Ldyld_stub_binding_helper$dclb:
    .long dyld_content_lazy_binder
#endif

    .text
    .private_extern __dyld_func_lookup
    .align 2 
__dyld_func_lookup:
#ifdef __PIC__
    ldr r12,[pc,#0]
Ldyld_func_lookup$dcfl_scv:
    ldr pc,[pc,r12]

Ldyld_func_lookup$dcfl:
    .long dyld_func_lookup_pointer-(Ldyld_func_lookup$dcfl_scv+8)
#else
    ldr ip,Ldyld_func_lookup$dcfl
    ldr pc,[ip,#0]

Ldyld_func_lookup$dcfl:
    .long dyld_func_lookup_pointer
#endif

    .data
    .align 2 
#ifdef __PIC__
dyld__mh_dylib_header:
    .long MACH_HEADER_SYMBOL_NAME
#else
dyld__mh_execute_header:
    .long MACH_HEADER_SYMBOL_NAME
#endif

    .dyld
    .align 2 
dyld_content_lazy_binder:
    .long 0x8fe01000
dyld_func_lookup_pointer:
    .long 0x8fe01008

    .subsections_via_symbols

