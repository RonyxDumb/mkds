#pragma once

#include "types.h"

typedef struct SoundSharedPlayer {
    /* 00 */ s16 mVariable[16];
    /* 20 */ u32 mTickCounter;
} SoundSharedPlayer;

// The work area the sound processor fills in: the finished command tag, player, channel and capture status, variables.
typedef struct SNDSharedWork {
    /* 000 */ u32 mFinishCommandTag;
    /* 004 */ u32 mPlayerStatus;
    /* 008 */ u16 mChannelStatus;
    /* 00a */ u16 mCaptureStatus;
    /* 00c */ u8 mPadding[0x14];
    /* 020 */ SoundSharedPlayer mPlayer[16];
    /* 260 */ s16 mGlobalVariable[16];
} SNDSharedWork;

extern SNDSharedWork *SNDi_SharedWork;

u32 IncreaseMDCounter(u32 alarmNo);
void Sound_InitializeAlarms(void);
void SNDi_InitSharedWork(SNDSharedWork *work);
u32 SNDi_GetFinishedCommandTag(void);
s16 SND_GetPlayerLocalVariable(s32 playerNo, s32 varNo);
u32 SND_GetPlayerStatus(void);
