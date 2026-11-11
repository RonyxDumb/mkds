#include "code_02133458.h"

// clang-format off
// Shifts the 64-bit value r1:r0 right (logical) by r2 modulo 64 and returns it in r1:r0.
// Hand-written asm: it tests the result of `subs r3, r2, #32` with ge.
asm u64 ShiftRightLogical64(u64 operand, u32 bitCount) {
    // A shift of 0 returns the value.
    ands r2, r2, #0x3f
    bxeq lr
    subs r3, r2, #32
    bge shift_32_or_more
    // Below 32: both words shift, bits moving from the high word into the low one.
    rsb r3, r2, #32
    mov r0, r0, lsr r2
    orr r0, r0, r1, lsl r3
    mov r1, r1, lsr r2
    bx lr
    // 32 or more: only the high word remains.
shift_32_or_more:
    mov r0, r1, lsr r3
    mov r1, #0
    bx lr
}
// clang-format on
