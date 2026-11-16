#pragma once

#include "types.h"
#include "file_command_handlers.h" // FSFile
#include "sound_fader.h" // NNSSndFader
#include "power_management_commands.h" // PMSleepCallbackInfo
#include "sound_archive_load.h"

// 0x5c bytes: a stream. mActiveFlag is set while it is set up, mStartFlag while its timers run.
typedef void (*NNSSndStrmCallback)(s32 status, s32 numChannels, void *buffer[], u32 len, u32 format, void *arg);

typedef struct NNSSndStrm {
    /* 00 */ u8 mLink[8];
    /* 08 */ PMSleepCallbackInfo mPreSleepInfo;
    /* 14 */ PMSleepCallbackInfo mPostSleepInfo;
    /* 20 */ u32 mFormat;
    /* 24 */ s32 mActiveFlag : 1;
    /* 24 */ s32 mStartFlag : 1;
    /* 24 */ s32 mUnk_24_2 : 30;
    /* 28 */ u32 mChBufLen;
    /* 2c */ s32 mInterval;
    /* 30 */ NNSSndStrmCallback mCallback;
    /* 34 */ void *mCallbackArg;
    /* 38 */ s32 mCurBuffer;
    /* 3c */ s32 mVolume;
    /* 40 */ u32 mAlarmNo;
    /* 44 */ u32 mChBitMask;
    /* 48 */ s32 mNumChannels;
    /* 4c */ u8 mChannelNo[0x10];
} NNSSndStrm;

// A stream player: its stream, file, fader and the active, play, start and fade out flags.
typedef struct NNSSndStrmPlayer {
    /* 00 */ NNSSndStrm mStream;
    /* 5c */ FSFile mFile;
    /* a4 */ u8 mUnk_a4[0x44];
    /* e8 */ NNSSndFader mFader;
    /* f8 */ u8 mUnk_f8[0x18];
    /* 110 */ s32 mActiveFlag : 1;
    /* 110 */ s32 mPlayFlag : 1;
    /* 110 */ s32 mStartFlag : 1;
    /* 110 */ s32 mFadeOutFlag : 1;
    /* 110 */ s32 mUnk_110_4 : 28;
    /* 114 */ s32 mFinishCounter;
    /* 118 */ s32 mPrepareFlag;
    /* 11c */ u8 mCommandCount[4];
    /* 120 */ s32 mAllocChannelCount;
    /* 124 */ u8 mUnk_124[0x28];
    /* 14c */ u32 *mHandle;
    /* 150 */ u8 mPrio[4];
    /* 154 */ s32 mInitVolume;
    /* 158 */ s32 mVolume;
    /* 15c */ u8 mUnk_15c[4];
} NNSSndStrmPlayer;

// A stream channel: its buffer and its volume.
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

extern NNSFndList sStrmList;
extern NNSSndStrmChannel sStrmChannel[16];
