#pragma once

#include "types.h"
#include "sound_archive_load.h"

void SND_SetWaveDataAddress(SNDWaveArc *waveArc, u32 index, void *address);

typedef struct UnsignedHalfwordPair {
    /* 00 */ u16 mFirst;
    /* 02 */ u16 mSecond;
} UnsignedHalfwordPair;

// A simple instrument: mWave, then the pair mSecondPair and the halfword mLastHalfword, copied unchanged.
typedef struct InstSimple {
    /* 00 */ UnsignedHalfwordPair mWave;
    /* 04 */ UnsignedHalfwordPair mKeyAndEnvelope;
    /* 08 */ u16 mReleaseAndPan;
} InstSimple;

// Values of SNDInstData.mType. The five simple types share the InstSimple layout; the code does not tell them apart.
enum {
    INSTRUMENT_TYPE_PCM = 1,
    INSTRUMENT_TYPE_PSG,
    INSTRUMENT_TYPE_NOISE,
    INSTRUMENT_TYPE_DIRECT_PCM,
    INSTRUMENT_TYPE_EMPTY,
    INSTRUMENT_TYPE_DRUM_SET = 0x10,
    INSTRUMENT_TYPE_KEY_SPLIT,
};

// An instrument entry: mType, then mWave, mKeyAndEnvelope and mReleaseAndPan as in InstSimple.
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

// Entries of a key split instrument.
#define KEY_SPLIT_ENTRY_COUNT 8

// Eight bytes (0 for an unused entry), then eight 12-byte entries.
typedef struct InstKeySplit {
    /* 00 */ u8 mKey[KEY_SPLIT_ENTRY_COUNT];
    /* 08 */ SNDInstData mInstOffset[KEY_SPLIT_ENTRY_COUNT];
} InstKeySplit;

u32 SND_GetWaveDataCount(SNDWaveArc *waveArc);
u32 SND_GetNextInstData(SNDBankData *bank, SNDInstData *inst, SNDInstPos *pos);
void SND_GetFirstInstDataPos(SNDInstPos *pos);
void SND_DestroyWaveArc(SNDWaveArc *waveArc);
void SND_DestroyBank(SNDBankData *bank);
void SND_AssignWaveArc(SNDBankData *bank, s32 index, SNDWaveArc *waveArc);
