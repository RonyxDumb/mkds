#include "Main/Unknown/code_02000920.h"
#include "Main/Unknown/unk_02000000.h"
#include "Main/Unknown/code_02000a58.h"

// clang-format off
// Fills c bytes at b with the word a.
// Not compiled code: it stores with a conditional `stmlt r1!, {r0}`; 1.2 builds ldm/stm only in prologues,
// epilogues and block moves (docs/compiler.md).
asm void func_02000920(u32 a, u32 *b, u32 c) {
    add ip, r1, r2
loop:
    cmp r1, ip
    stmltia r1!, {r0}
    blt loop
    bx lr
}

// Unpacks the compressed block that ends at p0, working backwards from its end: the two words before p0 give the
// packed and unpacked extents; each flag byte selects, per bit from the top, a literal byte or a copy of 3 to 18
// earlier bytes. Then cleans and invalidates the cache lines of the unpacked range.
// Not compiled code: it reads the two words with `ldmdb`, writes coprocessor 15 (mcr) and tests with `tst`, none of
// which 1.2 builds from C (docs/compiler.md).
asm void func_02000934(void *p0) {
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
// Not compiled code: it writes coprocessor 15 (mcr), tests a `cmp` with mi, and ends in a plain branch to another
// function; none of these come from C in 1.2 (docs/compiler.md).
asm void func_020009e0(void) {
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
