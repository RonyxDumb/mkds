#pragma once
#include "types.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "matrix44_concat.h" // MtxFx44
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"

// SoundSource.mFalloffIndex of the map object curves: the kinds pick one by comparing mFarDistanceSquared with the
// words of gSoundFalloffs[2] and [3] (outer distances 380 and 800 against 1100 for the long one).
#define SOUND_FALLOFF_SHORT_RANGE 2
#define SOUND_FALLOFF_MEDIUM_RANGE 3
#define SOUND_FALLOFF_LONG_RANGE 4

// The other curves the course sound objects use, named by the outer distance gSoundFalloffs gives them (600, 1200 and
// 3000, against 380, 800 and 1100 above; InitSoundFalloffs).
#define SOUND_FALLOFF_SHORT_MEDIUM_RANGE 6
#define SOUND_FALLOFF_LONGER_RANGE 8
#define SOUND_FALLOFF_VERY_LONG_RANGE 5

typedef struct NNSSndSeqPlayer NNSSndSeqPlayer;

typedef struct NNSSndHeap NNSSndHeap;

// The volume curve of one kind of sound source: full volume to the inner distance, falling to 0 at the outer one.
typedef struct SoundFalloff {
    // Distance beyond which the sound is silent.
    /* 00 */ s32 mOuterDistance;
    /* 04 */ s32 mMidDistance;
    /* 08 */ s32 mMidVolume;
    // Distance up to which the sound has its maximum volume.
    /* 0c */ s32 mInnerDistance;
    // Highest volume of the curve.
    /* 10 */ s32 mMaxVolume;
    /* 14 */ s32 mInnerToMidSlope;
    /* 18 */ s32 mMidToOuterSlope;
    /* 1c */ s32 mForwardDistanceSlope;
    /* 20 */ s32 mFarDistanceSquared;
} SoundFalloff;

// Volume curves by sound source number (SoundSource.mFalloffIndex); filled by InitSoundFalloffs.
extern SoundFalloff gSoundFalloffs[16];

extern NNSSndSeqPlayer *gMatchingEntrySeqHandle;

extern u32 gMissionRunSelMode;

extern NNSSndSeqPlayer *gSeqZeroLoopHandle;

extern s32 gSeqZeroLoopOn;

extern NNSSndSeqPlayer *gSndHandleSlots[12];

extern struct NNSSndArc g_MainSdat;

extern u32 gRaceSoundKind;

extern s32 gOrthoQuadHoldFrameCount;

extern s32 gOrthoQuadFrames;

extern OrthoQuad *gOrthoQuads;

extern u16 g_AnotherRacerId;

// TRUE for the cream effect, FALSE for geso_sumi; chosen by the call that started the quads.
extern BOOL gOrthoQuadUseCreamEffect;

extern u16 gOrthoQuadFirstPolygonId;

// Polygon alpha: 0x1f when the quads start, falls by 1 every second frame after the hold and ends them at 0.
extern u16 gOrthoQuadAlpha;

// One byte per row, one bit per column; marked when a quad is placed so later quads avoid the same cells.

extern u32 gBouncingItemBoxTimers[8];

static inline void SetBouncingItemBoxTimer(u16 kartIndex, u32 timer) {
    gBouncingItemBoxTimers[kartIndex] = timer;
}

extern s32 gOrthoQuadMoveStartFrameCount;

extern NNSSndHeap *g_SomeSoundContext;

extern u32 gSceneSeqRestartAfterStar;

extern NNSSndHeap *g_AnotherSoundContext;

extern u32 gSoundStartedThisFrame;

extern u32 g_BackupSoundHeapStateId[];

extern u32 gKartStarSeqStartPending;

struct NNSSndSeqPlayer;

extern struct NNSSndSeqPlayer *gChoisesSSeqHandle;

extern u32 gRaceSeqStarted;

extern u16 gMissionRunMSselSeqIndex;

extern s32 gMissionRunMSselStep32Count;

extern s32 gMissionRunMSselStep0Count;
