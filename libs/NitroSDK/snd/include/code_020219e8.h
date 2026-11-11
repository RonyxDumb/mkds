#pragma once

#include "types.h"
#include "code_0212d214.h"

// Two halfwords.
typedef struct Unk02021a5c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk02021a5c;

// 10 bytes that SND_GetNextInstData copies to mUnk_02..mUnk_0a of its record.
typedef struct Unk02021a60 {
    /* 00 */ Unk02021a5c mUnk_00;
    /* 04 */ Unk02021a5c mUnk_04;
    /* 08 */ u16 mUnk_08;
} Unk02021a60;

// 12 bytes that SND_GetNextInstData copies over the start of its record.
typedef struct Unk02021ab0 {
    /* 00 */ Unk02021a5c mUnk_00;
    /* 04 */ Unk02021a5c mUnk_04;
    /* 08 */ Unk02021a5c mUnk_08;
} Unk02021ab0;

// Two bytes (the second minus the first plus one is the number of entries), then the 12-byte entries.
typedef struct Unk02021aa8 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ Unk02021ab0 mUnk_02[1];
} Unk02021aa8;

// Eight bytes (0 for an unused entry), then eight 12-byte entries.
typedef struct Unk02021b24 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk02021ab0 mUnk_08[8];
} Unk02021b24;

// Record SND_GetNextInstData writes: a type byte then 10 bytes, or the 12-byte entry copied whole.
typedef union Unk020219f0 {
    Unk02021ab0 mEntry;
    struct {
        /* 00 */ u8 mUnk_00;
        /* 02 */ Unk02021a5c mUnk_02;
        /* 06 */ Unk02021a5c mUnk_06;
        /* 0a */ u16 mUnk_0a;
    };
} Unk020219f0;

u32 SND_GetWaveDataCount(Unk02021968 *waveArc);
u32 SND_GetNextInstData(Unk02021968 *bank, Unk020219f0 *inst, SNDInstPos *pos);
void SND_GetFirstInstDataPos(SNDInstPos *pos);
void SND_DestroyWaveArc(Unk02021968 *waveArc);
void SND_DestroyBank(Unk02021968 *bank);
void SND_AssignWaveArc(Unk02021968 *bank, s32 index, Unk02021968 *waveArc);
