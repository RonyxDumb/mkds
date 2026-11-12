#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"

// Object behind gKartSoundQueue: eight objects, a value for each of them, eight words, then four words.
typedef struct KartSoundQueue {
    /* 00 */ Kart *mKarts[8];
    /* 20 */ s32 mSoundIndices[8];
    /* 40 */ u32 mFramesSinceStart[8];
    /* 60 */ s32 mCount;
    /* 64 */ BOOL mDisabled;
    /* 68 */ s32 mVolume;
    /* 6c */ s32 mDelayFrames;
} KartSoundQueue;

extern KartSoundQueue gKartSoundQueue;

void StartKartLowSpeedTurnSound(Kart *kart, s32 withSurfaceSound, s32 surfaceKind, s32 surfaceVariant);
void StartKartSurfaceSoundWhileRequested(Kart *kart, s32 entryIndex, s32 surfaceKind, s32 surfaceVariant,
                                         u32 waterDepth);
void StartKartSurfaceSound(Kart *kart, s32 entryIndex, s32 surfaceKind, s32 surfaceVariant, s32 unused);
void StartKartSeqArcSoundWithVolume(s32 soundIndex, s32 soundOffset, u32 volume, s32 playerNo, s32 playerPrio);
void StartKartCollisionSound(Kart *kart, s32 soundIndex, s16 unused);
void StartKartSeqArcSound(Kart *kart, s32 soundIndex, s32 soundOffset);
void InitKartSoundQueue(void);
void UpdateKartSoundQueue(void);
void QueueKartSound(Kart *kart, s32 soundIndex);
void StartQueuedKartSound(Kart *kart, s32 soundIndex, s32 useKartSource, s32 volume);
void StartBattleWinOrLoseSound(s32 soundIndex, s32 isWinner);
