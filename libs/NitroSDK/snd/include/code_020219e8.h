#pragma once

#include "types.h"
#include "code_0212d214.h"

// Two halfwords.
typedef struct Unk02021a5c {
    /* 00 */ u16 field0;
    /* 02 */ u16 field2;
} Unk02021a5c;

// 10 bytes that SND_GetNextInstData copies to field2..fieldA of its record.
typedef struct Unk02021a60 {
    /* 00 */ Unk02021a5c field0;
    /* 04 */ Unk02021a5c field4;
    /* 08 */ u16 field8;
} Unk02021a60;

// 12 bytes that SND_GetNextInstData copies over the start of its record.
typedef struct Unk02021ab0 {
    /* 00 */ Unk02021a5c field0;
    /* 04 */ Unk02021a5c field4;
    /* 08 */ Unk02021a5c field8;
} Unk02021ab0;

// Two bytes (the second minus the first plus one is the number of entries), then the 12-byte entries.
typedef struct Unk02021aa8 {
    /* 00 */ u8 field0;
    /* 01 */ u8 field1;
    /* 02 */ Unk02021ab0 field2[1];
} Unk02021aa8;

// Eight bytes (0 for an unused entry), then eight 12-byte entries.
typedef struct Unk02021b24 {
    /* 00 */ u8 field0[8];
    /* 08 */ Unk02021ab0 field8[8];
} Unk02021b24;

u32 SND_GetWaveDataCount(Unk02021968 *waveArc);
u32 SND_GetNextInstData(Unk02021968 *bank, Unk020219f0 *inst, Unk02021bc8 *pos);
void SND_GetFirstInstDataPos(Unk02021bc8 *pos);
void SND_DestroyWaveArc(Unk02021968 *waveArc);
void SND_DestroyBank(Unk02021968 *bank);
void SND_AssignWaveArc(Unk02021968 *bank, s32 index, Unk02021968 *waveArc);
