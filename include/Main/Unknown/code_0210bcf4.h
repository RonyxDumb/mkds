#pragma once

#include "types.h"
#include "code_0212bcac.h"
#include "code_0212d214.h"

// Sound source: the object a sound is started on. Kart, ItemObject and the object behind MapObject.field94 embed it as
// their first member. It holds the list of the sounds started on it, the pointer to the position the distance to the
// camera is measured to, and the number of its volume curve. A sound is started on it only while bit 0 of its field34
// member is set; InitSoundSource clears that bit. data_0217d048 is addressed in rows of twelve bytes;
// sfx_updateEmitterStatus and func_0210c0bc address the container of one of those rows. Kart and the it_sItemsets
// elements (ItemObject) start with it: StartSoundWhileRequested and sfx_21090C4 pass either one to
// StartSoundWhileRequestedEx and sfx_emitSfx. InitSoundSource writes the byte at 0x3c and the word at 0x40.
typedef struct SoundSource {
    /* 00 */ u8 field0[2];
    /* 02 */ u16 field2;
    /* 04 */ u8 field4[8];
    // The sounds started on this source, as a list of PlayingSound entries.
    /* 0c */ NNSFndList mPlayingSounds;
    /* 18 */ u32 mUpdateListIndex;
    /* 1c */ u32 field1C[3];
    // Pointer to the owner's position (declared u32); the distance and the direction to the camera are measured to it.
    // Without one (0) a sound gets full volume and no direction.
    /* 28 */ u32 mOwnerPosSource;
    /* 2c */ void (*mStartSeqFunction)(void *a, void *b, u32 c);
    /* 30 */ void (*mTrackParamsFunction)(void *a, void *b, void *c);
    /* 34 */ u16 mSourceFlags;
    /* 36 */ u8 field36[2];
    /* 38 */ u32 field38;
    // Number of the volume curve (element of gSfxParams) of this source.
    /* 3c */ u8 mFalloffIndex;
    /* 3d */ u8 field3D[3];
    // Squared distance from the camera to the owner of the sound source. For a Kart it is the three-axis one, for map
    // and item objects the horizontal one with the low 5 and top 2 bits cleared; InitSoundSource stores 0xffffffff. The
    // sound pass takes its square root.
    /* 40 */ u32 mDistanceSquared;
} SoundSource;

// One sound started on a SoundSource, from the start request until it is stopped. The entries are taken from a pool of
// twelve and linked into the list of the source. The field0 member is the library player handle, NULL until the player
// is started. Returned by sp_acquireElement and passed to func_0210bcf4; sfx_stopSfxStandalone writes its byte at 0x19.
// sfx_210BF24 subtracts one NNSFndList from field10 to reach the SoundSource holding it.
typedef struct PlayingSound {
    /* 00 */ NNSSndSeqPlayer *mSeqPlayer;
    /* 04 */ s32 field4;
    /* 08 */ u32 field8;
    /* 0c */ u32 fieldC;
    /* 10 */ NNSFndList *field10;
    /* 14 */ s16 mPitch;
    // Number of the sound this entry plays.
    /* 16 */ u16 mSoundId;
    /* 18 */ u8 mSeqArcNo;
    /* 19 */ u8 mFlags;
    // Volume the sound was started with, 0 to 0x7f; the library turns it into a track volume through a table of 128
    // entries.
    /* 1a */ u8 mVolume;
} PlayingSound;

// Object at 0x20 of SoundParams: words at 0x08 and 0x0c.
typedef struct Unk0210bcf4_20 {
    /* 00 */ u8 field0[8];
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
} Unk0210bcf4_20;

// Held on the stack by func_0210bcf4 and sfx_updateEmitter and passed to the three functions
// data_0217d018, sfx_sCalcVolumeFunc and sfx_sCalcPanFunc point at.
typedef struct SoundParams {
    /* 00 */ SoundSource *mSource;
    /* 04 */ u32 mPositionSource;
    /* 08 */ s32 field8;
    /* 0c */ s32 fieldC;
    /* 10 */ s32 mDistance;
    /* 14 */ s32 mVolume;
    /* 18 */ u32 mPan;
    /* 1c */ u32 field1C;
    /* 20 */ Unk0210bcf4_20 *field20;
} SoundParams;

u32 func_0210bcf4(u32 seqArcNo, u32 soundId, u32 positionSource, NNSSndSeqPlayer **handle, void *request);
u32 func_0210bee8(u32 seqArcNo, u32 soundId, u32 positionSource, NNSSndSeqPlayer **handle, void *request);
void sfx_210BF24(u32 seqArcNo, u32 soundId, u32 positionSource, void *request);
void sfx_updateEmitterStatus(SoundSource *source);
void sfx_stopSfxStandalone(PlayingSound *sound, u32 fadeSteps);
void func_0210c0bc(SoundSource *source);
void sfx_initEmitter2(SoundSource *source, u32 positionSource);
