#include "Main/Unknown/code_0200007e.h"
#include "Main/Unknown/code_02000000.h"

#pragma thumb on

// clang-format off
// BIOS call 0x15.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void RLUnCompReadByCallbackWrite16bit(void) {
    swi 0x15
    bx lr
}

// BIOS call 0x0.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void SoftReset(void) {
    swi 0x0
    bx lr
}

// Clears r2, then BIOS call 0x5.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void VBlankIntrWait(void) {
    mov r2, #0x0
    swi 0x5
    bx lr
}

// BIOS call 0x12.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void LZ77UnCompReadByCallbackWrite16bit(void) {
    swi 0x12
    bx lr
}

// BIOS call 0x13.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void HuffUnCompReadByCallback(void) {
    swi 0x13
    bx lr
}

// BIOS call 0x11.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void LZ77UnCompReadNormalWrite8bit(void) {
    swi 0x11
    bx lr
}

// BIOS call 0xd.
// Not compiled code: C has no way to make a BIOS call (swi).
asm u32 Sqrt(u32 a) {
    swi 0xd
    bx lr
}

// BIOS call 0x14.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void RLUnCompReadNormalWrite8bit(void) {
    swi 0x14
    bx lr
}

// BIOS call 0xb.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void CpuSet(const void *src, void *dst, u32 ctrl) {
    swi 0xb
    bx lr
}

// BIOS call 0x10.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void BitUnPack(void) {
    swi 0x10
    bx lr
}

// BIOS call 0x3.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void WaitByLoop(s32 n) {
    swi 0x3
    bx lr
}

// BIOS call 0x9 (division), then returns the remainder (r1).
// Not compiled code: C has no way to make a BIOS call (swi).
asm s32 Mod(s32 a, s32 b) {
    swi 0x9
    add r0, r1, #0x0
    bx lr
}

// BIOS call 0xf.
// Not compiled code: C has no way to make a BIOS call (swi).
asm s32 IsDebugger(void) {
    swi 0xf
    bx lr
}

// BIOS call 0x9.
// Not compiled code: C has no way to make a BIOS call (swi).
asm s32 Div(s32 a, s32 b) {
    swi 0x9
    bx lr
}

// BIOS call 0xe.
// Not compiled code: C has no way to make a BIOS call (swi).
asm u16 GetCRC16(void) {
    swi 0xe
    bx lr
}

// BIOS call 0x6.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void Halt(void) {
    swi 0x6
    bx lr
}

// BIOS call 0xc.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void CpuFastSet(void) {
    swi 0xc
    bx lr
}

// BIOS call 0x4.
// Not compiled code: C has no way to make a BIOS call (swi).
asm void IntrWait(void) {
    swi 0x4
    bx lr
}
// clang-format on

#pragma thumb off
