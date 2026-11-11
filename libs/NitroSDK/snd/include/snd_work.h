#pragma once

#include "types.h"

typedef struct SoundSharedPlayer {
    /* 00 */ s16 mVariable[16];
    /* 20 */ u32 mTickCounter;
} SoundSharedPlayer;

// 0x280 bytes; the shared work area that the sound processor fills in.
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

u32 SNDi_IncAlarmId(u32 alarmNo);
void SND_AlarmInit(void);
void SNDi_InitSharedWork(SNDSharedWork *work);
u32 SNDi_GetFinishedCommandTag(void);
s16 SND_GetPlayerLocalVariable(s32 playerNo, s32 varNo);
u32 SND_GetPlayerStatus(void);
