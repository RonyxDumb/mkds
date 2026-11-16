// BIOS call stubs in the first 0x800 bytes of the ARM9 binary, between filler bytes taken from the extracted ROM.
//
// Kept as asm: many of the eighteen Thumb stubs start at addresses that are 2 mod 4.
// The bytes around the stubs (0xE7FFDEFF words first, then
// bytes with no structure) are not code and come from the user's ROM at build time.
// Each version places the stubs in its own order (tools/expand_incbin.py keeps the version's branch).

    .text
    .thumb
#ifdef version_EUR
    .incbin "extract/eur/arm9/arm9.bin", 0x0, 0x56

// BIOS call 0xd.
    .global Sqrt
    .type Sqrt, @function
Sqrt:
    swi 0xd
    bx lr
    .size Sqrt, . - Sqrt
    .incbin "extract/eur/arm9/arm9.bin", 0x5a, 0x64

// BIOS call 0x11.
    .global LZ77UnCompReadNormalWrite8bit
    .type LZ77UnCompReadNormalWrite8bit, @function
LZ77UnCompReadNormalWrite8bit:
    swi 0x11
    bx lr
    .size LZ77UnCompReadNormalWrite8bit, . - LZ77UnCompReadNormalWrite8bit
    .incbin "extract/eur/arm9/arm9.bin", 0xc2, 0x6e

// BIOS call 0x4.
    .global IntrWait
    .type IntrWait, @function
IntrWait:
    swi 0x4
    bx lr
    .size IntrWait, . - IntrWait
    .incbin "extract/eur/arm9/arm9.bin", 0x134, 0x64

// BIOS call 0x6.
    .global Halt
    .type Halt, @function
Halt:
    swi 0x6
    bx lr
    .size Halt, . - Halt
    .incbin "extract/eur/arm9/arm9.bin", 0x19c, 0x72

// BIOS call 0x0.
    .global SoftReset
    .type SoftReset, @function
SoftReset:
    swi 0x0
    bx lr
    .size SoftReset, . - SoftReset
    .incbin "extract/eur/arm9/arm9.bin", 0x212, 0x60

// BIOS call 0x15.
    .global RLUnCompReadByCallbackWrite16bit
    .type RLUnCompReadByCallbackWrite16bit, @function
RLUnCompReadByCallbackWrite16bit:
    swi 0x15
    bx lr
    .size RLUnCompReadByCallbackWrite16bit, . - RLUnCompReadByCallbackWrite16bit
    .incbin "extract/eur/arm9/arm9.bin", 0x276, 0x82

// BIOS call 0x9.
    .global Div
    .type Div, @function
Div:
    swi 0x9
    bx lr
    .size Div, . - Div
    .incbin "extract/eur/arm9/arm9.bin", 0x2fc, 0x58

// BIOS call 0x13.
    .global HuffUnCompReadByCallback
    .type HuffUnCompReadByCallback, @function
HuffUnCompReadByCallback:
    swi 0x13
    bx lr
    .size HuffUnCompReadByCallback, . - HuffUnCompReadByCallback
    .incbin "extract/eur/arm9/arm9.bin", 0x358, 0x6e

// BIOS call 0xf.
    .global IsDebugger
    .type IsDebugger, @function
IsDebugger:
    swi 0xf
    bx lr
    .size IsDebugger, . - IsDebugger
    .incbin "extract/eur/arm9/arm9.bin", 0x3ca, 0x5e

// BIOS call 0x12.
    .global LZ77UnCompReadByCallbackWrite16bit
    .type LZ77UnCompReadByCallbackWrite16bit, @function
LZ77UnCompReadByCallbackWrite16bit:
    swi 0x12
    bx lr
    .size LZ77UnCompReadByCallbackWrite16bit, . - LZ77UnCompReadByCallbackWrite16bit
    .incbin "extract/eur/arm9/arm9.bin", 0x42c, 0x6c

// BIOS call 0x14.
    .global RLUnCompReadNormalWrite8bit
    .type RLUnCompReadNormalWrite8bit, @function
RLUnCompReadNormalWrite8bit:
    swi 0x14
    bx lr
    .size RLUnCompReadNormalWrite8bit, . - RLUnCompReadNormalWrite8bit
    .incbin "extract/eur/arm9/arm9.bin", 0x49c, 0x68

// BIOS call 0x10.
    .global BitUnPack
    .type BitUnPack, @function
BitUnPack:
    swi 0x10
    bx lr
    .size BitUnPack, . - BitUnPack
    .incbin "extract/eur/arm9/arm9.bin", 0x508, 0x78

// BIOS call 0x9 (division), then returns the remainder (r1).
    .global Mod
    .type Mod, @function
Mod:
    swi 0x9
    add r0, r1, #0x0
    bx lr
    .size Mod, . - Mod
    .incbin "extract/eur/arm9/arm9.bin", 0x586, 0x72

// Clears r2, then BIOS call 0x5.
    .global VBlankIntrWait
    .type VBlankIntrWait, @function
VBlankIntrWait:
    mov r2, #0x0
    swi 0x5
    bx lr
    .size VBlankIntrWait, . - VBlankIntrWait
    .incbin "extract/eur/arm9/arm9.bin", 0x5fe, 0x66

// BIOS call 0x3.
    .global WaitByLoop
    .type WaitByLoop, @function
WaitByLoop:
    swi 0x3
    bx lr
    .size WaitByLoop, . - WaitByLoop
    .incbin "extract/eur/arm9/arm9.bin", 0x668, 0x5a

// BIOS call 0xb.
    .global CpuSet
    .type CpuSet, @function
CpuSet:
    swi 0xb
    bx lr
    .size CpuSet, . - CpuSet
    .incbin "extract/eur/arm9/arm9.bin", 0x6c6, 0x6e

// BIOS call 0xc.
    .global CpuFastSet
    .type CpuFastSet, @function
CpuFastSet:
    swi 0xc
    bx lr
    .size CpuFastSet, . - CpuFastSet
    .incbin "extract/eur/arm9/arm9.bin", 0x738, 0x62

// BIOS call 0xe.
    .global GetCRC16
    .type GetCRC16, @function
GetCRC16:
    swi 0xe
    bx lr
    .size GetCRC16, . - GetCRC16
    .incbin "extract/eur/arm9/arm9.bin", 0x79e, 0x62
#else
    .incbin "extract/usa/arm9/arm9.bin", 0x0, 0x7e

// BIOS call 0x15.
    .global SVC_UncompressRL16FromDevice
    .type SVC_UncompressRL16FromDevice, @function
SVC_UncompressRL16FromDevice:
    swi 0x15
    bx lr
    .size SVC_UncompressRL16FromDevice, . - SVC_UncompressRL16FromDevice
    .incbin "extract/usa/arm9/arm9.bin", 0x82, 0x4e

// BIOS call 0x0.
    .global SVC_SoftReset
    .type SVC_SoftReset, @function
SVC_SoftReset:
    swi 0x0
    bx lr
    .size SVC_SoftReset, . - SVC_SoftReset
    .incbin "extract/usa/arm9/arm9.bin", 0xd4, 0x6e

// Clears r2, then BIOS call 0x5.
    .global SVC_WaitVBlankIntr
    .type SVC_WaitVBlankIntr, @function
SVC_WaitVBlankIntr:
    mov r2, #0x0
    swi 0x5
    bx lr
    .size SVC_WaitVBlankIntr, . - SVC_WaitVBlankIntr
    .incbin "extract/usa/arm9/arm9.bin", 0x148, 0x70

// BIOS call 0x12.
    .global SVC_UncompressLZ16FromDevice
    .type SVC_UncompressLZ16FromDevice, @function
SVC_UncompressLZ16FromDevice:
    swi 0x12
    bx lr
    .size SVC_UncompressLZ16FromDevice, . - SVC_UncompressLZ16FromDevice
    .incbin "extract/usa/arm9/arm9.bin", 0x1bc, 0x5e

// BIOS call 0x13.
    .global SVC_UncompressHuffmanFromDevice
    .type SVC_UncompressHuffmanFromDevice, @function
SVC_UncompressHuffmanFromDevice:
    swi 0x13
    bx lr
    .size SVC_UncompressHuffmanFromDevice, . - SVC_UncompressHuffmanFromDevice
    .incbin "extract/usa/arm9/arm9.bin", 0x21e, 0x7e

// BIOS call 0x11.
    .global SVC_UncompressLZ8
    .type SVC_UncompressLZ8, @function
SVC_UncompressLZ8:
    swi 0x11
    bx lr
    .size SVC_UncompressLZ8, . - SVC_UncompressLZ8
    .incbin "extract/usa/arm9/arm9.bin", 0x2a0, 0x54

// BIOS call 0xd.
    .global SVC_Sqrt
    .type SVC_Sqrt, @function
SVC_Sqrt:
    swi 0xd
    bx lr
    .size SVC_Sqrt, . - SVC_Sqrt
    .incbin "extract/usa/arm9/arm9.bin", 0x2f8, 0x80

// BIOS call 0x14.
    .global SVC_UncompressRL8
    .type SVC_UncompressRL8, @function
SVC_UncompressRL8:
    swi 0x14
    bx lr
    .size SVC_UncompressRL8, . - SVC_UncompressRL8
    .incbin "extract/usa/arm9/arm9.bin", 0x37c, 0x58

// BIOS call 0xb.
    .global SVC_CpuSet
    .type SVC_CpuSet, @function
SVC_CpuSet:
    swi 0xb
    bx lr
    .size SVC_CpuSet, . - SVC_CpuSet
    .incbin "extract/usa/arm9/arm9.bin", 0x3d8, 0x38

// BIOS call 0x10.
    .global SVC_UnpackBits
    .type SVC_UnpackBits, @function
SVC_UnpackBits:
    swi 0x10
    bx lr
    .size SVC_UnpackBits, . - SVC_UnpackBits
    .incbin "extract/usa/arm9/arm9.bin", 0x414, 0x5e

// BIOS call 0x3.
    .global SVC_WaitByLoop
    .type SVC_WaitByLoop, @function
SVC_WaitByLoop:
    swi 0x3
    bx lr
    .size SVC_WaitByLoop, . - SVC_WaitByLoop
    .incbin "extract/usa/arm9/arm9.bin", 0x476, 0x74

// BIOS call 0x9 (division), then returns the remainder (r1).
    .global SVC_DivRem
    .type SVC_DivRem, @function
SVC_DivRem:
    swi 0x9
    add r0, r1, #0x0
    bx lr
    .size SVC_DivRem, . - SVC_DivRem
    .incbin "extract/usa/arm9/arm9.bin", 0x4f0, 0x50

// BIOS call 0xf.
    .global SVC_IsMmemExpanded
    .type SVC_IsMmemExpanded, @function
SVC_IsMmemExpanded:
    swi 0xf
    bx lr
    .size SVC_IsMmemExpanded, . - SVC_IsMmemExpanded
    .incbin "extract/usa/arm9/arm9.bin", 0x544, 0x7a

// BIOS call 0x9.
    .global SVC_Div
    .type SVC_Div, @function
SVC_Div:
    swi 0x9
    bx lr
    .size SVC_Div, . - SVC_Div
    .incbin "extract/usa/arm9/arm9.bin", 0x5c2, 0x7c

// BIOS call 0xe.
    .global SVC_GetCRC16
    .type SVC_GetCRC16, @function
SVC_GetCRC16:
    swi 0xe
    bx lr
    .size SVC_GetCRC16, . - SVC_GetCRC16
    .incbin "extract/usa/arm9/arm9.bin", 0x642, 0x7c

// BIOS call 0x6.
    .global SVC_Halt
    .type SVC_Halt, @function
SVC_Halt:
    swi 0x6
    bx lr
    .size SVC_Halt, . - SVC_Halt
    .incbin "extract/usa/arm9/arm9.bin", 0x6c2, 0x70

// BIOS call 0xc.
    .global SVC_CpuSetFast
    .type SVC_CpuSetFast, @function
SVC_CpuSetFast:
    swi 0xc
    bx lr
    .size SVC_CpuSetFast, . - SVC_CpuSetFast
    .incbin "extract/usa/arm9/arm9.bin", 0x736, 0x64

// BIOS call 0x4.
    .global SVC_WaitIntr
    .type SVC_WaitIntr, @function
SVC_WaitIntr:
    swi 0x4
    bx lr
    .size SVC_WaitIntr, . - SVC_WaitIntr
    .incbin "extract/usa/arm9/arm9.bin", 0x79e, 0x62
#endif
