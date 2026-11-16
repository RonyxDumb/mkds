#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct SoundParams SoundParams;

// Five words of constant data used by sfx_2109468.
typedef struct SoundFalloffSettings {
    /* 00 */ s32 mOuterDistance;
    /* 04 */ s32 field4;
    /* 08 */ s32 field8;
    /* 0c */ s32 mInnerDistance;
    /* 10 */ s32 mMaxVolume;
} SoundFalloffSettings;

void StopKartSoundWhileRequested(Kart *a);
void sfx_2109468(void);
// Returns the volume of a source from the distance in the field10 member of p and the forward distance in its field8
// member, by the SoundFalloff of the source: the maximum up to the inner distance, falling to 0 at the outer distance.
// Writes nothing.
s32 sfx_21092B0(SoundParams *p);
s32 sfx_210920C(SoundParams *p);
u32 sfx_2109184(SoundParams *p);
