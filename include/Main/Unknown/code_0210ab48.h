#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"

// Object behind gKartSoundQueue: eight objects, a value for each of them, eight words, then four words.
typedef struct KartSoundQueue {
    /* 00 */ Kart *mKarts[8];
    /* 20 */ s32 mUnk_20[8];
    /* 40 */ u32 mFramesSinceStart[8];
    /* 60 */ s32 mCount;
    /* 64 */ BOOL mDisabled;
    /* 68 */ s32 mVolume;
    /* 6c */ s32 mDelayFrames;
} KartSoundQueue;

extern KartSoundQueue gKartSoundQueue;

void func_0210b4e0(Kart *kart, s32 withSurfaceSound, s32 surfaceKind, s32 surfaceVariant);
void StartKartSurfaceSoundWhileRequested(Kart *kart, s32 entryIndex, s32 surfaceKind, s32 surfaceVariant,
                                         u32 waterDepth);
void func_0210b234(Kart *kart, s32 entryIndex, s32 surfaceKind, s32 surfaceVariant, s32 unused);
void func_0210b198(s32 soundIndex, s32 soundOffset, u32 volume, s32 playerNo, s32 playerPrio);
void StartKartCollisionSound(Kart *kart, s32 soundIndex, s16 unused);
void StartKartSeqArcSound(Kart *kart, s32 soundIndex, s32 soundOffset);
void InitKartSoundQueue(void);
void UpdateKartSoundQueue(void);
void QueueKartSound(Kart *kart, s32 soundIndex);
void StartQueuedKartSound(Kart *kart, s32 soundIndex, s32 useKartSource, s32 volume);
void func_0210ab48(s32 soundIndex, s32 b);
