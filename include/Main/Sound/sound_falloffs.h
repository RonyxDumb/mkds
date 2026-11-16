#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct SoundParams SoundParams;

// Distances and volumes InitSoundFalloffs puts in the first five falloffs in a replay (the wide ones replace the outer
// and mid distance of one of them).
#define SOUND_FALLOFF_REPLAY_OUTER_DISTANCE 0x44c
#define SOUND_FALLOFF_REPLAY_MID_DISTANCE 0x226
#define SOUND_FALLOFF_REPLAY_WIDE_OUTER_DISTANCE 0x514
#define SOUND_FALLOFF_REPLAY_WIDE_MID_DISTANCE 0x28a
#define SOUND_FALLOFF_REPLAY_MID_VOLUME 0x2f
#define SOUND_FALLOFF_REPLAY_MAX_VOLUME 0x5f

// Five words of constant data used by InitSoundFalloffs.
typedef struct SoundFalloffSettings {
    /* 00 */ s32 mOuterDistance;
    /* 04 */ s32 mMidDistance;
    /* 08 */ s32 mMidVolume;
    /* 0c */ s32 mInnerDistance;
    /* 10 */ s32 mMaxVolume;
} SoundFalloffSettings;

void StructMQRacerEntry_SomeFn_70(Kart *kart);
void InitSoundFalloffs(void);
// Returns the volume of a source from the distance in the mDistance member of soundParams and the forward distance in
// its mUnk_08 member, by the SoundFalloff of the source: the maximum up to the inner distance, falling to 0 at the
// outer distance. Writes nothing.
s32 ComputeSoundVolume(SoundParams *soundParams);
s32 ComputeSoundPan(SoundParams *soundParams);
u32 ComputeSoundDistanceAndOffsets(SoundParams *soundParams);
