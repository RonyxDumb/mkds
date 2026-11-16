#pragma once

#include "types.h"
#include "sound_player_control.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_seq.h"

// Update lists of a SoundSource (SoundSource.mUpdateListIndex): list 0 is walked every call of the sound pass, list 1
// in turns over four calls; a source with no sound that needs updating is on neither. On the calls in between, a source
// on list 1 only has the track volume and pitch of its sounds set, on every second call.
#define SOUND_SOURCE_LIST_EVERY_CALL 0
#define SOUND_SOURCE_LIST_IN_TURNS 1
#define SOUND_SOURCE_LIST_NONE 3

// Bits of SoundSource.mSourceFlags. SOUND_SOURCE_FLAG_ENABLED: sounds may be started on the source.
// SOUND_SOURCE_FLAG_WAS_ENABLED: set by ExpireWhileRequestedSounds while enabled, so that the sounds started while
// requested are stopped once it is not. SOUND_SOURCE_FLAG_TOGGLE_ENABLED: flips the enabled bit at the next
// ExpireWhileRequestedSounds call.
#define SOUND_SOURCE_FLAG_ENABLED 1
#define SOUND_SOURCE_FLAG_WAS_ENABLED 2
#define SOUND_SOURCE_FLAG_TOGGLE_ENABLED 4

// Bits of PlayingSound.mFlags. PLAYING_SOUND_FLAG_START_PENDING: set when the sound is started, cleared once
// SetPlayingSoundsParams has started its sequence or the sound is stopped. PLAYING_SOUND_FLAG_WHILE_REQUESTED: started
// by StartSoundWhileRequestedEx. PLAYING_SOUND_FLAG_REQUESTED_AGAIN: set by each request of such a sound, cleared by
// ExpireWhileRequestedSounds. PLAYING_SOUND_FLAG_UPDATE_IN_TURNS: keeps the source on the in-turns update list; no code
// in this build sets it. PLAYING_SOUND_FLAG_SKIP_SHRINK_PITCH: SetKartThunderShrinkSoundTrackParams does not raise its
// pitch. PLAYING_SOUND_FLAG_KART_COLLISION and PLAYING_SOUND_FLAG_KART_COLLISION_VARIANT: both set by
// StartKartCollisionSound, and only both together start the sound as the kart variant sequence.
// PLAYING_SOUND_FLAG_KART_SOUND_RECORD: started from a KartSound record (StartKartSound, StartKartLowRatioSound).
#define PLAYING_SOUND_FLAG_UPDATE_IN_TURNS 1
#define PLAYING_SOUND_FLAG_START_PENDING 2
#define PLAYING_SOUND_FLAG_WHILE_REQUESTED 4
#define PLAYING_SOUND_FLAG_REQUESTED_AGAIN 8
#define PLAYING_SOUND_FLAG_SKIP_SHRINK_PITCH 0x10
#define PLAYING_SOUND_FLAG_KART_COLLISION 0x20
#define PLAYING_SOUND_FLAG_KART_COLLISION_VARIANT 0x40
#define PLAYING_SOUND_FLAG_KART_SOUND_RECORD 0x80

// PlayingSound.mSeqArcNo of the kart sounds whose mSoundId is the character's KART_SOUND_SET_* index * 14 plus the
// sound's offset.
#define PLAYING_SOUND_SEQ_ARC_PER_CHARACTER 2

// Largest volume of a sound (PlayingSound.mVolume, SoundParams.mVolume).
#define SOUND_VOLUME_MAX 0x7f

// A sound source: the object a sound is started on, with its playing sounds and owner position; karts, item objects and
// map object sounds embed it.
typedef struct SoundSource {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[8];
    // The sounds started on this source, as a list of PlayingSound entries.
    /* 0c */ NNSFndList mPlayingSounds;
    /* 18 */ u32 mUpdateListIndex;
    /* 1c */ u32 mUnk_1c[3];
    // Pointer to the owner's position; the camera's forward and side distance to it set the volume and pan. Without one
    // (0) a sound gets full volume and pan 0.
    /* 28 */ Vec3 *mOwnerPosSource;
    /* 2c */ void (*mStartSeqFunction)(void *source, void *sound, u32 priority);
    /* 30 */ void (*mTrackParamsFunction)(void *source, void *sound, void *unused);
    /* 34 */ u16 mSourceFlags;
    /* 36 */ u8 mUnk_36[2];
    /* 38 */ u32 mRegistered;
    // Index of the volume curve in gSoundFalloffs; a kart that is not the entry kart and has 0 uses
    // gOtherKartSoundFalloff instead.
    /* 3c */ u8 mFalloffIndex;
    /* 3d */ u8 mUnk_3d[3];
    // Squared distance from the camera to the owner of the sound source. For a Kart it is the three-axis one, for map
    // and item objects the horizontal one with the low 5 and top 2 bits cleared; InitSoundSource stores 0xffffffff. The
    // sound pass takes its square root. Map objects without a view test store the plain horizontal squared distance
    // (not masked).
    /* 40 */ u32 mDistanceSquared;
} SoundSource;

// One sound started on a SoundSource, linked into the source's list from a pool of twelve until it is stopped.
typedef struct PlayingSound {
    /* 00 */ NNSSndSeqPlayer *mSeqPlayer;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ NNSFndList *mSourceList;
    /* 14 */ s16 mPitch;
    // Index of the sound inside the sequence archive entry mSeqArcNo.
    /* 16 */ u16 mSoundId;
    /* 18 */ u8 mSeqArcNo;
    /* 19 */ u8 mFlags;
    // Volume of the sound, 0 to 0x7f, set when it is started and again when it is requested again; the track volume is
    // its entry in a table of 128 values.
    /* 1a */ u8 mVolume;
} PlayingSound;

// The request to start a sound: its id, the position it comes from, the falloff index and the squared distance.
typedef struct SoundStartParams {
    /* 00 */ s32 mSoundId;
    /* 04 */ Vec3 *mPositionSource;
    /* 08 */ s32 mFalloffIndex;
    /* 0c */ u32 mDistanceSquared;
} SoundStartParams;

// Held on the stack by StartOrUpdateSndHandleSound and SetPlayingSoundsParams and passed to the three functions
// gSoundDistanceFunction, gSoundVolumeFunction and gSoundPanFunction point at.
typedef struct SoundParams {
    /* 00 */ SoundSource *mSource;
    /* 04 */ Vec3 *mPositionSource;
    /* 08 */ s32 mCameraForwardDistance;
    /* 0c */ s32 mCameraSideDistance;
    /* 10 */ s32 mDistance;
    /* 14 */ s32 mVolume;
    /* 18 */ u32 mPan;
    /* 1c */ u32 mVolumeForPriority;
    /* 20 */ SoundStartParams *mStartParams;
} SoundParams;

u32 StartOrUpdateSndHandleSound(u32 seqArcNo, u32 soundId, Vec3 *positionSource, NNSSndSeqPlayer **handle,
                                void *request);
u32 StartOrUpdateSndHandleSoundIfEnabled(u32 seqArcNo, u32 soundId, Vec3 *positionSource, NNSSndSeqPlayer **handle,
                                         void *request);
void StartSoundOnPoolEntry(u32 seqArcNo, u32 soundId, Vec3 *positionSource, void *request);
void RefreshSoundSourceUpdateList(SoundSource *source);
void StopPlayingSoundSeq(PlayingSound *sound, u32 fadeSteps);
void UnlinkSoundSourceSounds(SoundSource *source);
void ItemObjectInitAndRegisterSoundSource(SoundSource *source, Vec3 *positionSource);

extern void (*gStartSoundSeqArcTable[1])(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 soundId, u32 priority);

extern u32 gSoundSourceUpdatePass[1];
extern u32 (*gSoundDistanceFunction)(SoundParams *);
extern u32 gSoundUpdateCountThisPass[1];
extern s32 (*gSoundVolumeFunction)(SoundParams *);
extern s32 (*gSoundPanFunction)(SoundParams *);
extern u32 gExpireWhileRequestedSounds;
extern NNSFndList gSoundSources;
extern SoundHandlePool gPlayingSoundPool;
