#pragma once

#include "types.h"
#include "code_0212bcac.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_021035ac.h"

typedef struct NNSSndSeqPlayer NNSSndSeqPlayer;
typedef struct NNSSndHeap NNSSndHeap;

// Volume curve of one kind of sound source. The volume is the maximum up to the inner distance, falls to a mid volume
// at the mid distance and to 0 at the outer distance. SoundSource.mFalloffIndex picks the element of gSfxParams.
// 0x24-byte entries of the array at gSfxParams; sfx_2109468 fills elements 0 to 15 of it.
// 0x24-byte entries of the array at gSfxParams; sfx_2109468 fills the first one.
typedef struct SoundFalloff {
    // Distance beyond which the sound is silent.
    /* 00 */ s32 mOuterDistance;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
    // Distance up to which the sound has its maximum volume.
    /* 0c */ s32 mInnerDistance;
    // Highest volume of the curve.
    /* 10 */ s32 mMaxVolume;
    /* 14 */ s32 field14;
    /* 18 */ s32 field18;
    /* 1c */ s32 field1C;
    /* 20 */ s32 field20;
} SoundFalloff;

// Volume curves by sound source number (SoundSource.mFalloffIndex); filled by sfx_2109468.
extern SoundFalloff gSfxParams[];
// Volume curve of the Karts other than the selected entry whose sound source number is 0.
extern SoundFalloff gOtherKartSoundFalloff;

// Objects whose layout isn't known yet.
extern NNSSndSeqPlayer *data_0217c778;
extern u32 data_0217c784;
extern NNSSndSeqPlayer *data_0217c788;
extern s32 data_0217c7a4;
extern NNSSndSeqPlayer *data_0217c838[];
extern NNSSndSeqPlayer *data_0217c83c;
extern NNSSndSeqPlayer *data_0217c840;
extern struct NNSSndArc SDATFile;
extern u8 data_0217c91c[];
extern u32 data_0217cbec[];
extern u32 data_0217c780;
extern u32 data_0217cc6c[];
extern u32 data_0217c7fc[];
extern u8 data_0217ccac[];
extern u32 csfx_sSfxOverrides[];
extern s32 cspl_sSplashDuration;
extern s32 cspl_sSplashTimer;
extern s32 cspl_sSplashCount;
extern s32 data_0217ccb0;
extern s32 gSoundPitchSwing;
extern u8 gSoundPitchSwingAngle[];
extern s32 data_0217ccbc;
extern u16 *gItemTeresaFrameScales;
extern s32 gItemGessoFrameCount;
extern OrthoQuad *cspl_sSplashes;
extern u16 cspl_sDriverId;
// TRUE for the cream effect, FALSE for geso_sumi; chosen by the call that started the quads.
extern BOOL cspl_sUseCustomSplash;
extern u16 cspl_sPolygonId;
extern u8 cspl_sProjMtx[];
// Polygon alpha: 0x1f when the quads start, falls by 1 every second frame after the hold and ends them at 0.
extern u16 cspl_sSplashAlpha;
// One byte per row, one bit per column; marked when a quad is placed so later quads avoid the same cells.
extern u8 cspl_sScreenCoverageFlags[];
extern u32 gBouncingItemBoxTimers[];
extern u32 gBouncingItemBoxTimerRunning[];
extern s32 gOrthoQuadMoveStartFrameCount;
extern u16 data_0217c76c[];
extern u16 data_0217c770[];
extern NNSSndHeap *snd_sDriverVoiceHeap;
extern u32 data_0217c78c;
extern NNSSndHeap *data_0217c790;
extern u32 gSoundStartedThisFrame;
extern u32 data_0217c798[];
extern u32 data_0217c7a8;
struct NNSSndSeqPlayer;
extern struct NNSSndSeqPlayer *data_0217c7ac;
extern u32 data_0217c7b0;
extern u8 data_0217c7d8[];
extern s32 data_0217c804[];
extern u32 data_0217c80c[];
extern NNSSndSeqPlayer *sound_sStarMusicHandle;
extern u32 gPooledMapObjectNextIndex;
extern struct MapObject **gPooledMapObjects;
extern s32 gPooledMapObjectCount;
extern u16 data_0217c774;
extern s32 data_0217c79c;
extern s32 data_0217c7a0;
extern void *dram_sModel;
