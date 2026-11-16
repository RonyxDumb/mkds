#pragma once

#include "types.h"
#include "code_02003024.h" // FSFile
#include "code_0212f788.h" // NNSSndFader
#include "pm.h" // PMSleepCallbackInfo

// 0x5c bytes: a stream. mActiveFlag is set while it is set up, mStartFlag while its timers run.
typedef struct NNSSndStrm {
    /* 00 */ u8 mLink[8];
    /* 08 */ PMSleepCallbackInfo mPreSleepInfo;
    /* 14 */ PMSleepCallbackInfo mPostSleepInfo;
    /* 20 */ u32 mFormat;
    /* 24 */ s32 mActiveFlag : 1;
    /* 24 */ s32 mStartFlag : 1;
    /* 24 */ s32 field24_2 : 30;
    /* 28 */ u32 mChBufLen;
    /* 2c */ s32 mInterval;
    /* 30 */ UnkFunc *mCallback;
    /* 34 */ void *mCallbackArg;
    /* 38 */ s32 mCurBuffer;
    /* 3c */ s32 mVolume;
    /* 40 */ u32 mAlarmNo;
    /* 44 */ u32 mChBitMask;
    /* 48 */ s32 mNumChannels;
    /* 4c */ u8 mChannelNo[0x10];
} NNSSndStrm;

// 0x160 bytes; data_0217e404 holds four. Bits of field110: 0 is tested by ShutdownPlayer_, ForceStopStrm_ and
// NNSi_SndArcStrmMain, 1 by ForceStopStrm_ and NNSi_SndArcStrmMain, 2 and 3 by NNSi_SndArcStrmMain.
typedef struct Unk0212c7f0 {
    /* 00 */ NNSSndStrm mStream;
    /* 5c */ FSFile mFile;
    /* a4 */ u8 fieldA4[0x44];
    /* e8 */ NNSSndFader fieldE8;
    /* f8 */ u8 fieldF8[0x18];
    /* 110 */ s32 field110_0 : 1;
    /* 110 */ s32 field110_1 : 1;
    /* 110 */ s32 field110_2 : 1;
    /* 110 */ s32 field110_3 : 1;
    /* 110 */ s32 field110_4 : 28;
    /* 114 */ s32 field114;
    /* 118 */ s32 field118;
    /* 11c */ u8 field11C[4];
    /* 120 */ s32 field120;
    /* 124 */ u8 field124[0x28];
    /* 14c */ u32 *field14C;
    /* 150 */ u8 field150[4];
    /* 154 */ s32 field154;
    /* 158 */ s32 field158;
    /* 15c */ u8 field15C[4];
} Unk0212c7f0;

// 8 bytes; NNS_SndStrmSetVolume reads mVolume of the element a byte of NNSSndStrm.mChannelNo selects in data_0217dd28.
typedef struct NNSSndStrmChannel {
    /* 00 */ void *mBuffer;
    /* 04 */ s32 mVolume;
} NNSSndStrmChannel;

void ShutdownStrm(NNSSndStrm *stream);
void ForceStopStrm(NNSSndStrm *stream);
void NNS_SndStrmSetVolume(NNSSndStrm *stream, s32 volume);
void NNS_SndStrmStop(NNSSndStrm *stream);
void NNS_SndStrmStart(NNSSndStrm *stream);
void NNS_SndStrmFreeChannel(NNSSndStrm *stream);
