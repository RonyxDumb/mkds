#pragma avoid_byte all

#include "float_status_flags.h"
#include "debugger_calls.h"

// clang-format off
// Clears the floating-point status word (GetFloatStatus) and the five words from offset 4 of the block
// GetFloatTrapTable
// returns.
// Kept as asm: it saves lr alone with `stmdb sp!, {lr}`, a 4-byte frame with no padding word.
asm void _fp_init(void) {
    stmdb sp!, {lr}
    bl GetFloatStatus
    mov r1, #0
    str r1, [r0]
    bl GetFloatTrapTable
    mov r1, #0
    str r1, [r0, #4]
    str r1, [r0, #8]
    str r1, [r0, #12]
    str r1, [r0, #16]
    str r1, [r0, #20]
    ldmia sp!, {lr}
    bx lr
}

// Updates the floating-point status word: clears the bits in clearMask, then flips the bits in xorMask; returns the old
// value.
// Kept as asm: it saves r0-r2, ip and lr around its call, inside the body (a 20-byte frame).
asm u32 FloatStatusClearXor(u32 clearMask, u32 xorMask) {
    stmfd sp!, {r0, r1, r2, ip, lr}
    bl GetFloatStatus
    mov r3, r0
    ldmfd sp!, {r0, r1, r2, ip, lr}
    ldr r2, [r3]
    bic ip, r2, r0
    eor ip, ip, r1
    str ip, [r3]
    mov r0, r2
    bx lr
}

// Like FloatStatusClearXor, for the flag bits only: clearFlags and xorFlags hold flags in bits 0-4 and trap enables in
// bits 16-20, which are
// moved down to bits 8-12 first. Returns the old flags (bits 0-4), the old trap enables moved up to bits 16-20, and bit
// 30 set.
// Kept as asm: it saves r0-r2, ip and lr around its call, inside the body.
asm u32 FloatFlagsClearXor(u32 clearFlags, u32 xorFlags) {
    and r2, r0, #0x1f
    and r3, r0, #0x1f0000
    orr r0, r2, r3, lsr #8
    and r2, r1, #0x1f
    and r3, r1, #0x1f0000
    orr r1, r2, r3, lsr #8
    stmfd sp!, {r0, r1, r2, ip, lr}
    bl GetFloatStatus
    mov r3, r0
    ldmfd sp!, {r0, r1, r2, ip, lr}
    ldr r2, [r3]
    bic ip, r2, r0
    eor ip, ip, r1
    str ip, [r3]
    and r0, r2, #0x1f
    and r2, r2, #0x1f00
    orr r0, r0, r2, lsl #8
    orr r0, r0, #0x40000000
    bx lr
}
// clang-format on
