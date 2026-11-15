#pragma once

#include "types.h"
#include "code_0212d214.h"

void SND_SetWaveDataAddress(SNDWaveArc *waveArc, u32 index, void *address);

typedef struct UnsignedHalfwordPair {
    /* 00 */ u16 mFirst;
    /* 02 */ u16 mSecond;
} UnsignedHalfwordPair;

// 10 bytes that SND_GetNextInstData copies to mWave..mReleaseAndPan of its record (original key, attack, decay, sustain; release, pan).
typedef struct InstSimple {
    /* 00 */ UnsignedHalfwordPair mWave;
    /* 04 */ UnsignedHalfwordPair mKeyAndEnvelope;
    /* 08 */ u16 mReleaseAndPan;
} InstSimple;

// Values of SNDInstData.mType. The five simple types share the InstSimple layout; the code does not tell them apart.
// Types 1 to 5 are the simple ones (bare case labels in SND_GetNextInstData).
enum {
    INSTRUMENT_TYPE_DRUM_SET = 0x10,
    INSTRUMENT_TYPE_KEY_SPLIT,
};

// 12-byte instrument entry: a type byte then 10 bytes. SND_GetNextInstData writes it to its record.
typedef struct SNDInstData {
    /* 00 */ u8 mType;
    /* 02 */ UnsignedHalfwordPair mWave;
    /* 06 */ UnsignedHalfwordPair mKeyAndEnvelope;
    /* 0a */ u16 mReleaseAndPan;
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
