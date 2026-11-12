#pragma once
#include "types.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h" // MtxFx44
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"

typedef struct NNSSndSeqPlayer NNSSndSeqPlayer;

typedef struct NNSSndHeap NNSSndHeap;

// Volume curve of one kind of sound source. The volume is the maximum up to the inner distance, falls to a mid volume
// at the mid distance and to 0 at the outer distance. SoundSource.mFalloffIndex picks the element of gSoundFalloffs.
// 0x24-byte entries of the array at gSoundFalloffs; InitSoundFalloffs fills elements 0 to 15 of it.
// 0x24-byte entries of the array at gSoundFalloffs; InitSoundFalloffs fills the first one.
typedef struct SoundFalloff {
    // Distance beyond which the sound is silent.
    /* 00 */ s32 mOuterDistance;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    // Distance up to which the sound has its maximum volume.
    /* 0c */ s32 mInnerDistance;
    // Highest volume of the curve.
    /* 10 */ s32 mMaxVolume;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mFarDistanceSquared;
} SoundFalloff;

// Volume curves by sound source number (SoundSource.mFalloffIndex); filled by InitSoundFalloffs.
extern SoundFalloff gSoundFalloffs[];

// Volume curve of the Karts other than the selected entry whose sound source number is 0.
extern SoundFalloff gOtherKartSoundFalloff;

// Objects whose layout isn't known yet.
extern NNSSndSeqPlayer *gMatchingEntrySeqHandle;

extern u32 gMissionRunSelMode;

extern NNSSndSeqPlayer *gSeqZeroLoopHandle;

extern s32 gSeqZeroLoopOn;

extern NNSSndSeqPlayer *gSndHandleSlots[];

extern NNSSndSeqPlayer *data_0217c83c;

extern NNSSndSeqPlayer *data_0217c840;

extern struct NNSSndArc gOnMemorySndArc;


extern u32 gRaceSoundKind;

extern u32 gPlayerVolumeTargets[];

extern s32 gMapObjectSoundCounter;


extern s32 gOrthoQuadHoldFrameCount;

extern s32 gOrthoQuadFrames;






extern u16 *gItemTeresaFrameScales;


extern OrthoQuad *gOrthoQuads;

extern u16 gOrthoQuadKartIndex;

// TRUE for the cream effect, FALSE for geso_sumi; chosen by the call that started the quads.
extern BOOL gOrthoQuadUseCreamEffect;

extern u16 gOrthoQuadFirstPolygonId;


// Polygon alpha: 0x1f when the quads start, falls by 1 every second frame after the hold and ends them at 0.
extern u16 gOrthoQuadAlpha;

// One byte per row, one bit per column; marked when a quad is placed so later quads avoid the same cells.

extern u32 gBouncingItemBoxTimers[];

static inline void SetBouncingItemBoxTimer(u16 kartIndex, u32 timer) {
    gBouncingItemBoxTimers[kartIndex] = timer;
}

extern u32 gBouncingItemBoxTimerRunning[];

extern s32 gOrthoQuadMoveStartFrameCount;

extern u16 gMissionRunLimitSeqNo[];

extern u16 gMissionRunCountSeqNo[];

extern NNSSndHeap *gSndHeap;

extern u32 gSceneSeqRestartAfterStar;

extern NNSSndHeap *gSeqRowSndHeap;

extern u32 gSoundStartedThisFrame;

extern u32 gSndHeapSavedState[];

extern u32 gKartStarSeqStartPending;

struct NNSSndSeqPlayer;

extern struct NNSSndSeqPlayer *gChoisesSSeqHandle;

extern u32 gRaceSeqStarted;

extern u8 data_0217c7d8[];

extern s32 gPlayerVolumeMasks[];

extern u32 gPlayerVolumeSteps[];




extern u16 gMissionRunMSselSeqIndex;

extern s32 gMissionRunMSselStep32Count;

extern s32 gMissionRunMSselStep0Count;

extern struct Nsbmd *gDram;
