#pragma once

#include "types.h"
#include "code_0212d214.h"

void SND_SetWaveDataAddress(SNDWaveArc *waveArc, u32 index, void *address);

typedef struct UnsignedHalfwordPair {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} UnsignedHalfwordPair;

// 10 bytes that SND_GetNextInstData copies to mUnk_02..mUnk_0a of its record.
typedef struct InstSimple {
    /* 00 */ UnsignedHalfwordPair mWave;
    /* 04 */ UnsignedHalfwordPair mUnk_04;
    /* 08 */ u16 mUnk_08;
} InstSimple;

// 12-byte instrument entry: a type byte then 10 bytes. SND_GetNextInstData writes it to its record.
typedef struct SNDInstData {
    /* 00 */ u8 mType;
    /* 02 */ UnsignedHalfwordPair mWave;
    /* 06 */ UnsignedHalfwordPair mUnk_06;
    /* 0a */ u16 mUnk_0a;
} SNDInstData;

// Two bytes (the second minus the first plus one is the number of entries), then the 12-byte entries.
typedef struct InstDrumSet {
    /* 00 */ u8 mMin;
    /* 01 */ u8 mMax;
    /* 02 */ SNDInstData mInstOffset[1];
} InstDrumSet;

// Eight bytes (0 for an unused entry), then eight 12-byte entries.
typedef struct InstKeySplit {
    /* 00 */ u8 mKey[8];
    /* 08 */ SNDInstData mInstOffset[8];
} InstKeySplit;

u32 SND_GetWaveDataCount(SNDWaveArc *waveArc);
u32 SND_GetNextInstData(SNDBankData *bank, SNDInstData *inst, SNDInstPos *pos);
void SND_GetFirstInstDataPos(SNDInstPos *pos);
void SND_DestroyWaveArc(SNDWaveArc *waveArc);
void SND_DestroyBank(SNDBankData *bank);
void SND_AssignWaveArc(SNDBankData *bank, s32 index, SNDWaveArc *waveArc);
