#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_0201c528.h" // ParticleEmitter
#include "Main/Graphics/nsbmd_render_obj.h" // Nsbmd
#include "Main/Graphics/model_animation.h" // ModelAnimation
#include "Main/MapObjects/teresa.h" // TeresaWobble

// Object behind gTrophy (a 0x124-byte allocation).
typedef struct Trophy {
    /* 000 */ u16 mModelIndex;
    /* 002 */ u16 mRankIndex;
    /* 004 */ u16 mRotateYAngle;
    /* 008 */ TeresaWobble mRotateZWobble;
    /* 028 */ Nsbmd mModel;
    /* 094 */ ModelAnimation mModelAnimation;
    /* 0cc */ MtxFx43 mEffectMatrix;
    /* 0fc */ s16 mLight0X;
    /* 0fe */ s16 mLight1X;
    /* 100 */ s16 mLight0Y;
    /* 102 */ s16 mLight1Y;
    /* 104 */ s16 mLight0Z;
    /* 106 */ s16 mLight1Z;
    /* 108 */ Vec3 mEffectOffset;
    /* 114 */ s32 mUnk_114;
    /* 118 */ ParticleEmitter *mEffect0;
    /* 11c */ ParticleEmitter *mEffect4;
    /* 120 */ ParticleEmitter *mEffect5;
} Trophy;

extern Trophy *gTrophy;
