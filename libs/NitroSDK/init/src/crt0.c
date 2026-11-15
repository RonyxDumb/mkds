#include "crt0.h"
#include "code_02000a58.h"
#include "unk_02000000.h"
#include "ITCM/code_01ff8000.h"

asm void _start(void) {
    mov ip, #0x4000000
    str ip, [ip, #0x208]
    bl init_cp15
    mov r0, #0x13
    msr cpsr_c, r0
    ldr r0, =OSi_IrqThreadQueue
    add r0, r0, #0x3fc0
    mov sp, r0
    mov r0, #0x12
    msr cpsr_c, r0
    ldr r0, =OSi_IrqThreadQueue
    add r0, r0, #0x3fc0
    sub r0, r0, #0x40
    sub sp, r0, #0x4
    ldr r1, =0xc00
    sub r1, r0, r1
    mov r0, #0x1f
    msr cpsr_fsxc, r0
    sub sp, r1, #0x4
    mov r0, #0x0
    ldr r1, =OSi_IrqThreadQueue
    mov r2, #0x4000
    bl INITi_CpuClear32
    mov r0, #0x0
    ldr r1, =0x5000000
    mov r2, #0x400
    bl INITi_CpuClear32
    mov r0, #0x200
    ldr r1, =0x7000000
    mov r2, #0x400
    bl INITi_CpuClear32
    ldr r1, =BuildInfo
    ldr r0, [r1, #0x14]
    bl MIi_UncompressBackward
    bl do_autoload
    ldr r0, =BuildInfo
    ldr r1, [r0, #0xc]
    ldr r2, [r0, #0x10]
    mov r3, r1
    mov r0, #0x0
clear_bss:
    cmp r1, r2
    strlo r0, [r1], #0x4
    blo clear_bss
    bic r1, r3, #0x1f
flush_line:
    mcr p15, 0, r0, c7, c10, 4
    mcr p15, 0, r1, c7, c5, 1
    mcr p15, 0, r1, c7, c14, 1
    add r1, r1, #0x20
    cmp r1, r2
    blt flush_line
    ldr r1, =0x27fff9c
    str r0, [r1, #0x0]
    ldr r1, =OSi_IrqThreadQueue
    add r1, r1, #0x3fc0
    add r1, r1, #0x3c
    ldr r0, =OS_IrqHandler
    str r0, [r1, #0x0]
    bl _fp_init
    bl NitroStartUp
    bl __call_static_initializers
    ldr r1, =main
    ldr lr, =0xffff0000
    bx r1
}

asm void INITi_CpuClear32(u32 value, u32 *dest, u32 byteCount) {
    add ip, r1, r2
loop:
    cmp r1, ip
    stmltia r1!, {r0}
    blt loop
    bx lr
}

// Unpacks the compressed block that ends at compressedEnd, working backwards from its end: the two words before it give
// the packed and unpacked extents; each flag byte selects, per bit from the top, a literal byte or a copy of 3 to 18
// earlier bytes. Then cleans and invalidates the cache lines of the unpacked range.
// Kept as asm: it reads the two words with `ldmdb`, writes coprocessor 15 (mcr) and tests with `tst`.
asm void MIi_UncompressBackward(void *compressedEnd) {
    cmp r0, #0x0
    beq done
    stmdb sp!, {r4, r5, r6, r7}
    ldmdb r0, {r1, r2}
    add r2, r0, r2
    sub r3, r0, r1, lsr #24
    bic r1, r1, #0xff000000
    sub r1, r0, r1
    mov r4, r2
next_flags:
    cmp r3, r1
    ble flush
    ldrb r5, [r3, #-0x1]!
    mov r6, #0x8
next_bit:
    subs r6, r6, #0x1
    blt next_flags
    tst r5, #0x80
    bne copy
    ldrb r0, [r3, #-0x1]!
    strb r0, [r2, #-0x1]!
    b bit_done
copy:
    ldrb ip, [r3, #-0x1]!
    ldrb r7, [r3, #-0x1]!
    orr r7, r7, ip, lsl #8
    bic r7, r7, #0xf000
    add r7, r7, #0x2
    add ip, ip, #0x20
copy_byte:
    ldrb r0, [r2, r7]
    strb r0, [r2, #-0x1]!
    subs ip, ip, #0x10
    bge copy_byte
bit_done:
    cmp r3, r1
    mov r5, r5, lsl #1
    bgt next_bit
flush:
    mov r0, #0x0
    bic r3, r1, #0x1f
flush_line:
    mcr p15, 0, r0, c7, c10, 4
    mcr p15, 0, r3, c7, c5, 1
    mcr p15, 0, r3, c7, c14, 1
    add r3, r3, #0x20
    cmp r3, r4
    blt flush_line
    ldmia sp!, {r4, r5, r6, r7}
done:
    bx lr
}

// Walks the block list in BuildInfo (start, end, source): for each block copies its words from the source, clears
// the words after them and cleans and invalidates the cache lines; then continues in AutoloadCallback.
// Kept as asm: it writes coprocessor 15 (mcr), tests a `cmp` with mi, and ends in a branch to another function.
asm void do_autoload(void) {
    ldr r0, =BuildInfo
    ldr r1, [r0, #0x0]
    ldr r2, [r0, #0x4]
    ldr r3, [r0, #0x8]
next_block:
    cmp r1, r2
    beq finish
    ldr r5, [r1], #0x4
    ldr r7, [r1], #0x4
    add r6, r5, r7
    mov r4, r5
copy_word:
    cmp r4, r6
    ldrmi r7, [r3], #0x4
    strmi r7, [r4], #0x4
    bmi copy_word
    ldr r7, [r1], #0x4
    add r6, r4, r7
    mov r7, #0x0
clear_word:
    cmp r4, r6
    strlo r7, [r4], #0x4
    blo clear_word
    bic r4, r5, #0x1f
flush_line:
    mcr p15, 0, r7, c7, c10, 4
    mcr p15, 0, r4, c7, c5, 1
    mcr p15, 0, r4, c7, c14, 1
    add r4, r4, #0x20
    cmp r4, r6
    blt flush_line
    b next_block
finish:
    b AutoloadCallback
}

// clang-format on

// clang-format on
