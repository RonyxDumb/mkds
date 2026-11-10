// Build information block, kept in .text after NitroStartUp: the addresses the startup code reads (the list of blocks
// to copy and clear, the range of words to clear) and the version strings.
//
// Hand-written asm: the data has to sit in .text.

    .text
    .extern data_usa_021773a0
    .extern data_usa_021773b8
    .extern data_0216f340

    .global BuildInfo
    .type BuildInfo, @object
BuildInfo:
    // Start and end of the block list, the source of the copied words, then the start of the range of words to clear and
    // its end.
    .word data_usa_021773a0
    .word data_usa_021773b8
    .word data_0216f340
    .word data_0216f340
    .word 0x021804c0
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
