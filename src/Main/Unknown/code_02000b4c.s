// Build information block, kept in .text after func_02000b48: the addresses the startup code reads (the list of blocks
// to copy and clear, the range of words to clear) and the SDK version strings.
//
// Not compiled code: a C file can't place data in .text. 1.2 puts C tables in .rodata, also with `#pragma section`
// or a section attribute (docs/compiler.md).

    .text
    .extern data_021773c0
    .extern data_021773d8
    .extern data_0216f340
    .extern ARM9_BSS_END

    .global BuildInfo
    .type BuildInfo, @object
BuildInfo:
    // Start and end of the block list, the source of the copied words, then the start of the range of words to clear and
    // its end.
    .word data_021773c0
    .word data_021773d8
    .word data_0216f340
    .word data_0216f340
    .word ARM9_BSS_END
    .word 0x00000000
    .word 0x030028a0
    .word 0xdec00621
    .word 0x2106c0de
sdk_backup:
    .asciz "[SDK+NINTENDO:BACKUP]"
    .space 2
sdk_dwc:
    .asciz "[SDK+NINTENDO:DWC20051007-1634_DWC20051007_NOTOUCH]"
sdk_wifi:
    .asciz "[SDK+NINTENDO:WiFi1.0.10200.0510061936]"
sdk_ssl:
    .asciz "[SDK+UBIQUITOUS:SSL]"
    .space 3
sdk_cps:
    .ascii "[SDK+UBIQUITOUS:CPS]"
    .space 1008
    .size BuildInfo, . - BuildInfo
