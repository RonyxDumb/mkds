#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02146d78.h"
#include "code_0201c528.h" // ParticleEmitter
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of StartSunFireball: after the shared part, a halfword at 0xa0, a counter at 0xa4, a position at 0xa8, a
// halfword at 0xb4, a state at 0xb8 and two objects at 0xbc and 0xc0.
typedef struct SunFireball {
    /* 00 */ MapObject mMapObject;
    /* a0 */ u16 mTimer;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mState0Timer;
    /* a8 */ Vec3 mStartPos;
    /* b4 */ u16 mMoveAngle;
    /* b6 */ u8 mUnk_b6[2];
    /* b8 */ u32 mState;
    /* bc */ ParticleEmitter *mUnk_bc;
    /* c0 */ ParticleEmitter *mUnk_c0;
} SunFireball;

void StartSunFireball(Vec3 *startPos, Vec3 *direction);
void CreateSunFireballUpdateList(void);
void CreateSunFireballKindData(void);
void UpdateSunFireball(void *mapObjectList, SunFireball *sunFireball);
