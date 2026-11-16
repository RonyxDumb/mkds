#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"

// KartSoundQueue.mVolume: the first sound of a run starts at the start volume; each next one that starts exactly the
// gap frames after the one before is quieter by the step, down to the minimum. After a run the queue waits the delay.
#define KART_SOUND_QUEUE_VOLUME_START 0x5f
#define KART_SOUND_QUEUE_VOLUME_STEP 0xf
#define KART_SOUND_QUEUE_VOLUME_MIN 0x1e
#define KART_SOUND_QUEUE_GAP_FRAMES 0x14
#define KART_SOUND_QUEUE_DELAY_FRAMES 0x19

// The queue of kart sounds: up to eight karts with their sound index and frames since start, the volume and delay.
typedef struct KartSoundQueue {
    /* 00 */ Kart *mKarts[8];
    /* 20 */ s32 mSoundIndices[8];
    /* 40 */ u32 mFramesSinceStart[8];
    /* 60 */ s32 mCount;
    /* 64 */ BOOL mDisabled;
    /* 68 */ s32 mVolume;
    /* 6c */ s32 mDelayFrames;
} KartSoundQueue;


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
