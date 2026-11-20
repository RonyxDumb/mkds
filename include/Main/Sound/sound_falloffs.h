#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct SoundParams SoundParams;

// Distances and volumes InitSoundFalloffs gives five falloffs in a replay: gSoundFalloffs[0], gOtherKartSoundFalloff
// and gSoundFalloffs[1] to [3] (the wide distances go to gSoundFalloffs[1] only).
#define SOUND_FALLOFF_REPLAY_OUTER_DISTANCE 0x44c
#define SOUND_FALLOFF_REPLAY_MID_DISTANCE 0x226
#define SOUND_FALLOFF_REPLAY_WIDE_OUTER_DISTANCE 0x514
#define SOUND_FALLOFF_REPLAY_WIDE_MID_DISTANCE 0x28a
#define SOUND_FALLOFF_REPLAY_MID_VOLUME 0x2f
#define SOUND_FALLOFF_REPLAY_MAX_VOLUME 0x5f

// The outer, mid and inner distance and the mid and max volume of one volume curve; InitSoundFalloffs turns it into a
// SoundFalloff.
typedef struct SoundFalloffSettings {
    /* 00 */ s32 mOuterDistance;
    /* 04 */ s32 mMidDistance;
    /* 08 */ s32 mMidVolume;
    /* 0c */ s32 mInnerDistance;
    /* 10 */ s32 mMaxVolume;
} SoundFalloffSettings;

void StopKartSoundWhileRequested(Kart *kart);
void InitSoundFalloffs(void);
// Returns the volume of a source from soundParams.mDistance and soundParams.mCameraForwardDistance by the SoundFalloff
// of the source (gOtherKartSoundFalloff for the Karts other than the entry kart whose mFalloffIndex is 0): the maximum
// up to the inner distance, falling to 0 at the outer distance, lowered for sources behind the camera. Writes nothing.
s32 ComputeSoundVolume(SoundParams *soundParams);
s32 ComputeSoundPan(SoundParams *soundParams);
u32 ComputeSoundDistanceAndOffsets(SoundParams *soundParams);
