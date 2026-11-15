#include "Main/Kart/kart_level.h"
#include "Main/System/heap.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Graphics/effects.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_02147cd8.h"

const Vec3 gKartTurnEffectsStartPosition = {0, 0, 0};
struct KartTurnEffects *gKartTurnEffects;

void InitKartTurnEffects(void *heap) {
    u16 kartIndex;
    u16 sideIndex;
    KartTurnEffects *turnEffects;

    gKartTurnEffects = HeapAlloc(heap, gRaceSetup->mKartCount * 0x88);
    for (kartIndex = 0; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        turnEffects = &gKartTurnEffects[kartIndex];
        turnEffects->mIndex = kartIndex;
        if (kartIndex == gRaceSetup->mEntryIndex || gRaceSetup->mRaceKind == RACE_KIND_AWARD ||
            gRaceSetup->mMode == MODE_TIME_ATTACK) {
            turnEffects->mTurnStartEffectId = 0x14;
            turnEffects->mLevel4FirstEffectId = 0x11;
            turnEffects->mLevel4SecondEffectId = 0x12;
            turnEffects->mStartLevel4Effects = StartKartLevel4EffectsWithSecond;
            turnEffects->mStopLevel4Emission = StopKartLevel4EmissionWithSecond;
            turnEffects->mStartLevel4Emission = StartKartLevel4EmissionWithSecond;
            turnEffects->mReleaseLevel4Effects = ReleaseKartLevel4EffectsWithSecond;
            turnEffects->mStopLevel4Effects = StopKartLevel4EffectsWithSecond;
            turnEffects->mPlaceLevel4Effects = PlaceKartLevel4EffectsWithSecond;
            turnEffects->mHideEffects = HideKartEffectsWithSecond;
            turnEffects->mShowEffects = ShowKartEffectsWithSecond;
        } else {
            turnEffects->mTurnStartEffectId = 0x15;
            turnEffects->mLevel4FirstEffectId = 0x13;
            turnEffects->mLevel4SecondEffectId = -1;
            turnEffects->mStartLevel4Effects = StartKartLevel4EffectsFirstOnly;
            turnEffects->mStopLevel4Emission = StopKartLevel4EmissionFirstOnly;
            turnEffects->mStartLevel4Emission = StartKartLevel4EmissionFirstOnly;
            turnEffects->mReleaseLevel4Effects = ReleaseKartLevel4EffectsFirstOnly;
            turnEffects->mStopLevel4Effects = StopKartLevel4EffectsFirstOnly;
            turnEffects->mPlaceLevel4Effects = PlaceKartLevel4EffectsFirstOnly;
            turnEffects->mHideEffects = HideKartEffectsFirstOnly;
            turnEffects->mShowEffects = ShowKartEffectsFirstOnly;
        }
        turnEffects->mLevel3FirstEffectId = 0x16;
        turnEffects->mLevel3SecondEffectId = 0x17;
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            turnEffects->mLevel4FirstEffects[sideIndex] = NULL;
            turnEffects->mLevel4SecondEffects[sideIndex] = NULL;
            turnEffects->mTurnStartEffects[sideIndex] = NULL;
            turnEffects->mLevel3FirstEffects[sideIndex] = NULL;
            turnEffects->mLevel3SecondEffects[sideIndex] = NULL;
        }
        turnEffects->mLevel4StopFrames = 0;
        turnEffects->mLevel4StopRequested = FALSE;
        turnEffects->mLevel4Present = 0;
        turnEffects->mTurnStartPresent = 0;
        turnEffects->mLevel3Present = 0;
        turnEffects->mLevel2Present = FALSE;
        turnEffects->mLevel3Frames = 0;
        turnEffects->mLevel2Frames = 0;
        turnEffects->mLevel4RestartFrames = 0;
        turnEffects->mLevel4RestartRequested = 0;
    }
}

void StartKartTurnStartEffects(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    if (turnEffects->mTurnStartPresent != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            DeleteEffectAndClearPointer(&turnEffects->mTurnStartEffects[sideIndex]);
        }
    }
    turnEffects->mTurnStartPresent = 0;
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mTurnStartEffects[sideIndex] =
            StartEffect(turnEffects->mTurnStartEffectId, &gKartTurnEffectsStartPosition);
        turnEffects->mTurnStartEffects[sideIndex]->mColor = 0x7fff;
        turnEffects->mTurnStartEffects[sideIndex]->mAlpha = 0x1c;
        turnEffects->mTurnStartEffects[sideIndex]->mSizeScale = 0x1000;
    }
    turnEffects->mTurnStartPresent = 1;
}

void StopKartTurnStartEffects(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    if (turnEffects->mTurnStartPresent == 0) {
        return;
    }
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mTurnStartEffects[sideIndex]->mFlags.mEnding = 1;
        turnEffects->mTurnStartEffects[sideIndex] = NULL;
    }
    turnEffects->mTurnStartPresent = 0;
}

void AdvanceKartTurnStartEffects(KartTurnEffects *turnEffects, Kart *kart) {
    u16 sideIndex;
    KartEffects *kartEffects;
    Vec3 velocity;
    Vec3 negVelocity;
    Vec3 position;
    ParticleEmitter *effect;

    if (turnEffects->mTurnStartPresent == 0) {
        return;
    }
    kartEffects = GetKartEffects(kart->mIndex);
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        velocity.x = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.x, 0xb33);
        velocity.y = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.y, 0xb33);
        velocity.z = MUL_FIXED12_NO_ROUND(kart->mEffectVelocity.z, 0xb33);
        turnEffects->mTurnStartEffects[sideIndex]->mVelocity = velocity;
        negVelocity.x = -velocity.x;
        negVelocity.y = -velocity.y;
        negVelocity.z = -velocity.z;
        VEC_Add(&kartEffects->mSidePositions[sideIndex], &negVelocity, &position);
        effect = turnEffects->mTurnStartEffects[sideIndex];
        effect->mPosition.x = position.x + effect->mResource->mHeader->mPositionOffset.x;
        effect->mPosition.y = position.y + effect->mResource->mHeader->mPositionOffset.y;
        effect->mPosition.z = position.z + effect->mResource->mHeader->mPositionOffset.z;
        if ((kart->mMotionFlags & KART_MOTION_ON_GROUND) == 0) {
            turnEffects->mTurnStartEffects[sideIndex]->mFlags.mEmissionStopped = 1;
        } else {
            turnEffects->mTurnStartEffects[sideIndex]->mFlags.mEmissionStopped = 0;
        }
    }
}

void StartKartLevel4EffectsWithSecond(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel4FirstEffects[sideIndex] =
            StartEffect(turnEffects->mLevel4FirstEffectId, &gKartTurnEffectsStartPosition);
        turnEffects->mLevel4SecondEffects[sideIndex] =
            StartEffect(turnEffects->mLevel4SecondEffectId, &gKartTurnEffectsStartPosition);
    }
}

void StartKartLevel4EffectsFirstOnly(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel4FirstEffects[sideIndex] =
            StartEffect(turnEffects->mLevel4FirstEffectId, &gKartTurnEffectsStartPosition);
    }
}

void StopKartLevel4EmissionWithSecond(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel4FirstEffects[sideIndex]->mFlags.mEmissionStopped = 1;
        turnEffects->mLevel4SecondEffects[sideIndex]->mFlags.mEmissionStopped = 1;
    }
}

void StopKartLevel4EmissionFirstOnly(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel4FirstEffects[sideIndex]->mFlags.mEmissionStopped = 1;
    }
}

void StartKartLevel4EmissionWithSecond(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel4FirstEffects[sideIndex]->mFlags.mEmissionStopped = 0;
        turnEffects->mLevel4SecondEffects[sideIndex]->mFlags.mEmissionStopped = 0;
    }
}

void StartKartLevel4EmissionFirstOnly(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel4FirstEffects[sideIndex]->mFlags.mEmissionStopped = 0;
    }
}

void ReleaseKartLevel4EffectsWithSecond(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        DeleteEffect(turnEffects->mLevel4FirstEffects[sideIndex]);
        DeleteEffect(turnEffects->mLevel4SecondEffects[sideIndex]);
        turnEffects->mLevel4FirstEffects[sideIndex] = NULL;
        turnEffects->mLevel4SecondEffects[sideIndex] = NULL;
    }
}

void ReleaseKartLevel4EffectsFirstOnly(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        DeleteEffect(turnEffects->mLevel4FirstEffects[sideIndex]);
        turnEffects->mLevel4FirstEffects[sideIndex] = NULL;
    }
}

void StopKartLevel4EffectsWithSecond(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    if (turnEffects->mLevel4Present == 0) {
        return;
    }
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel4FirstEffects[sideIndex]->mFlags.mEmissionStopped = 1;
        turnEffects->mLevel4SecondEffects[sideIndex]->mFlags.mEmissionStopped = 1;
    }
}

void StopKartLevel4EffectsFirstOnly(KartTurnEffects *turnEffects) {
    if (turnEffects->mLevel4Present == 0) {
        return;
    }
    if (turnEffects->mLevel4Present != 0) {
        turnEffects->mReleaseLevel4Effects(turnEffects);
    }
    turnEffects->mLevel4Present = 0;
    turnEffects->mLevel4StopFrames = 0;
    turnEffects->mLevel4StopRequested = FALSE;
    turnEffects->mLevel4RestartFrames = 0;
    turnEffects->mLevel4RestartRequested = 0;
}

void PlaceKartLevel4EffectsWithSecond(KartTurnEffects *turnEffects, Vec3s16 *sideDirections, Vec3 *sidePositions) {
    u16 sideIndex;
    ParticleEmitter *effect;
    s32 coord;

    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel4FirstEffects[sideIndex]->mDirection = sideDirections[sideIndex];
        turnEffects->mLevel4SecondEffects[sideIndex]->mDirection = sideDirections[sideIndex];
        effect = turnEffects->mLevel4FirstEffects[sideIndex];
        coord = sidePositions[sideIndex].x;
        effect->mPosition.x = coord + effect->mResource->mHeader->mPositionOffset.x;
        coord = sidePositions[sideIndex].y;
        effect->mPosition.y = coord + effect->mResource->mHeader->mPositionOffset.y;
        coord = sidePositions[sideIndex].z;
        effect->mPosition.z = coord + effect->mResource->mHeader->mPositionOffset.z;
        effect = turnEffects->mLevel4SecondEffects[sideIndex];
        coord = sidePositions[sideIndex].x;
        effect->mPosition.x = coord + effect->mResource->mHeader->mPositionOffset.x;
        coord = sidePositions[sideIndex].y;
        effect->mPosition.y = coord + effect->mResource->mHeader->mPositionOffset.y;
        coord = sidePositions[sideIndex].z;
        effect->mPosition.z = coord + effect->mResource->mHeader->mPositionOffset.z;
    }
}

void PlaceKartLevel4EffectsFirstOnly(KartTurnEffects *turnEffects, Vec3s16 *sideDirections, Vec3 *sidePositions) {
    u16 sideIndex;
    ParticleEmitter *effect;
    s32 coord;

    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        effect = turnEffects->mLevel4FirstEffects[sideIndex];
        effect->mDirection = sideDirections[sideIndex];
        effect = turnEffects->mLevel4FirstEffects[sideIndex];
        coord = sidePositions[sideIndex].x;
        effect->mPosition.x = coord + effect->mResource->mHeader->mPositionOffset.x;
        coord = sidePositions[sideIndex].y;
        effect->mPosition.y = coord + effect->mResource->mHeader->mPositionOffset.y;
        coord = sidePositions[sideIndex].z;
        effect->mPosition.z = coord + effect->mResource->mHeader->mPositionOffset.z;
    }
}

void HideKartNonLevel4Effects(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    if (turnEffects->mTurnStartPresent != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            turnEffects->mTurnStartEffects[sideIndex]->mFlags.mHidden = 1;
        }
    }
    if (turnEffects->mLevel3Present != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            turnEffects->mLevel3FirstEffects[sideIndex]->mFlags.mHidden = 1;
            turnEffects->mLevel3SecondEffects[sideIndex]->mFlags.mHidden = 1;
        }
    }
    if (turnEffects->mLevel2Present == FALSE) {
        return;
    }
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel2Effects[sideIndex]->mFlags.mHidden = 1;
    }
}

void HideKartEffectsWithSecond(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    if (turnEffects->mLevel4Present != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            turnEffects->mLevel4FirstEffects[sideIndex]->mFlags.mHidden = 1;
            turnEffects->mLevel4SecondEffects[sideIndex]->mFlags.mHidden = 1;
        }
    }
    HideKartNonLevel4Effects(turnEffects);
}

void HideKartEffectsFirstOnly(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    if (turnEffects->mLevel4Present != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            turnEffects->mLevel4FirstEffects[sideIndex]->mFlags.mHidden = 1;
        }
    }
    HideKartNonLevel4Effects(turnEffects);
}

void ShowKartNonLevel4Effects(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    if (turnEffects->mTurnStartPresent != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            turnEffects->mTurnStartEffects[sideIndex]->mFlags.mHidden = 0;
        }
    }
    if (turnEffects->mLevel3Present != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            turnEffects->mLevel3FirstEffects[sideIndex]->mFlags.mHidden = 0;
            turnEffects->mLevel3SecondEffects[sideIndex]->mFlags.mHidden = 0;
        }
    }
    if (turnEffects->mLevel2Present == FALSE) {
        return;
    }
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel2Effects[sideIndex]->mFlags.mHidden = 0;
    }
}

void ShowKartEffectsWithSecond(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    if (turnEffects->mLevel4Present != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            turnEffects->mLevel4FirstEffects[sideIndex]->mFlags.mHidden = 0;
            turnEffects->mLevel4SecondEffects[sideIndex]->mFlags.mHidden = 0;
        }
    }
    ShowKartNonLevel4Effects(turnEffects);
}

void ShowKartEffectsFirstOnly(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    if (turnEffects->mLevel4Present != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            turnEffects->mLevel4FirstEffects[sideIndex]->mFlags.mHidden = 0;
        }
    }
    ShowKartNonLevel4Effects(turnEffects);
}

void ResetKartLevel4Effects(KartTurnEffects *turnEffects) {
    if (turnEffects->mLevel4Present != 0) {
        turnEffects->mReleaseLevel4Effects(turnEffects);
    }
    turnEffects->mLevel4Present = 0;
    turnEffects->mLevel4StopFrames = 0;
    turnEffects->mLevel4StopRequested = FALSE;
    turnEffects->mLevel4RestartFrames = 0;
    turnEffects->mLevel4RestartRequested = 0;
}

void AdvanceKartLevel4Effects(KartTurnEffects *turnEffects, Kart *kart) {
    KartEffects *kartEffects;

    if (turnEffects->mLevel4StopRequested != FALSE) {
        turnEffects->mLevel4StopFrames++;
        if (turnEffects->mLevel4StopFrames > 10) {
            if (turnEffects->mLevel4Present != 0) {
                turnEffects->mReleaseLevel4Effects(turnEffects);
            }
            turnEffects->mLevel4Present = 0;
            turnEffects->mLevel4StopFrames = 0;
            turnEffects->mLevel4StopRequested = FALSE;
            turnEffects->mLevel4RestartFrames = 0;
            turnEffects->mLevel4RestartRequested = 0;
        }
    }
    if ((kart->mMotionFlags & KART_MOTION_DRIFTING) && turnEffects->mLevel4RestartRequested != 0) {
        turnEffects->mLevel4RestartFrames++;
        if (turnEffects->mLevel4RestartFrames > 10) {
            if (turnEffects->mLevel4Present != 0) {
                turnEffects->mReleaseLevel4Effects(turnEffects);
            }
            turnEffects->mLevel4Present = 0;
            turnEffects->mLevel4StopFrames = 0;
            turnEffects->mLevel4StopRequested = FALSE;
            turnEffects->mLevel4RestartFrames = 0;
            turnEffects->mLevel4RestartRequested = 0;
            turnEffects->mStartLevel4Effects(turnEffects);
            turnEffects->mLevel4Present = 1;
            turnEffects->mLevel4RestartFrames = 0;
            turnEffects->mLevel4RestartRequested = 0;
        }
    }
    if (turnEffects->mLevel4Present == 0) {
        return;
    }
    kartEffects = GetKartEffects(kart->mIndex);
    turnEffects->mPlaceLevel4Effects(turnEffects, kartEffects->mSideDirections, kartEffects->mSidePositions);
    if ((kart->mMotionFlags & KART_MOTION_ON_GROUND) == 0) {
        turnEffects->mStopLevel4Emission(turnEffects);
        return;
    }
    if (turnEffects->mLevel4StopRequested == FALSE) {
        turnEffects->mStartLevel4Emission(turnEffects);
    }
}

void StartKartLevel3Effects(KartTurnEffects *turnEffects, int enable) {
    u16 sideIndex;

    if (enable == 0) {
        return;
    }
    if (turnEffects->mLevel3Present != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            DeleteEffect(turnEffects->mLevel3FirstEffects[sideIndex]);
            DeleteEffect(turnEffects->mLevel3SecondEffects[sideIndex]);
            turnEffects->mLevel3FirstEffects[sideIndex] = NULL;
            turnEffects->mLevel3SecondEffects[sideIndex] = NULL;
        }
    }
    turnEffects->mLevel3Present = 0;
    turnEffects->mLevel3Frames = 0;
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel3FirstEffects[sideIndex] =
            StartEffect(turnEffects->mLevel3FirstEffectId, &gKartTurnEffectsStartPosition);
        turnEffects->mLevel3SecondEffects[sideIndex] =
            StartEffect(turnEffects->mLevel3SecondEffectId, &gKartTurnEffectsStartPosition);
    }
    turnEffects->mLevel3Present = 1;
}

void AdvanceKartLevel3Effects(KartTurnEffects *turnEffects, Vec3s16 *sideDirections, Vec3 *sidePositions) {
    u16 sideIndex;
    ParticleEmitter *effect;
    s32 coord;

    if (turnEffects->mLevel3Present == 0) {
        return;
    }
    turnEffects->mLevel3Frames++;
    if (turnEffects->mLevel3Frames > 10) {
        if (turnEffects->mLevel3Present != 0) {
            for (sideIndex = 0; sideIndex < 2; sideIndex++) {
                DeleteEffect(turnEffects->mLevel3FirstEffects[sideIndex]);
                DeleteEffect(turnEffects->mLevel3SecondEffects[sideIndex]);
                turnEffects->mLevel3FirstEffects[sideIndex] = NULL;
                turnEffects->mLevel3SecondEffects[sideIndex] = NULL;
            }
        }
        turnEffects->mLevel3Present = 0;
        turnEffects->mLevel3Frames = 0;
        return;
    }
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel3FirstEffects[sideIndex]->mDirection = sideDirections[sideIndex];
        turnEffects->mLevel3SecondEffects[sideIndex]->mDirection = sideDirections[sideIndex];
        effect = turnEffects->mLevel3FirstEffects[sideIndex];
        coord = sidePositions[sideIndex].x;
        effect->mPosition.x = coord + effect->mResource->mHeader->mPositionOffset.x;
        coord = sidePositions[sideIndex].y;
        effect->mPosition.y = coord + effect->mResource->mHeader->mPositionOffset.y;
        coord = sidePositions[sideIndex].z;
        effect->mPosition.z = coord + effect->mResource->mHeader->mPositionOffset.z;
        effect = turnEffects->mLevel3SecondEffects[sideIndex];
        coord = sidePositions[sideIndex].x;
        effect->mPosition.x = coord + effect->mResource->mHeader->mPositionOffset.x;
        coord = sidePositions[sideIndex].y;
        effect->mPosition.y = coord + effect->mResource->mHeader->mPositionOffset.y;
        coord = sidePositions[sideIndex].z;
        effect->mPosition.z = coord + effect->mResource->mHeader->mPositionOffset.z;
    }
}

void StartKartLevel2Effects(KartTurnEffects *turnEffects, int enable) {
    u16 sideIndex;

    if (enable == 0) {
        return;
    }
    if (turnEffects->mLevel2Present != FALSE) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            DeleteEffect(turnEffects->mLevel2Effects[sideIndex]);
            turnEffects->mLevel2Effects[sideIndex] = NULL;
        }
    }
    turnEffects->mLevel2Present = FALSE;
    turnEffects->mLevel2Frames = 0;
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mLevel2Effects[sideIndex] = StartEffect(0x7e, &gKartTurnEffectsStartPosition);
    }
    turnEffects->mLevel2Present = TRUE;
}

void AdvanceKartLevel2Effects(KartTurnEffects *turnEffects, Vec3s16 *sideDirections, Vec3 *sidePositions) {
    u16 sideIndex;
    ParticleEmitter *effect;
    s32 coord;

    if (turnEffects->mLevel2Present == FALSE) {
        return;
    }
    turnEffects->mLevel2Frames++;
    if (turnEffects->mLevel2Frames > 8) {
        if (turnEffects->mLevel2Present != FALSE) {
            for (sideIndex = 0; sideIndex < 2; sideIndex++) {
                DeleteEffect(turnEffects->mLevel2Effects[sideIndex]);
                turnEffects->mLevel2Effects[sideIndex] = NULL;
            }
        }
        turnEffects->mLevel2Present = FALSE;
        turnEffects->mLevel2Frames = 0;
        if (turnEffects->mTurnStartPresent == 0) {
            return;
        }
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            turnEffects->mTurnStartEffects[sideIndex]->mFlags.mEmissionStopped = 0;
        }
        return;
    }
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        effect = turnEffects->mLevel2Effects[sideIndex];
        effect->mDirection = sideDirections[sideIndex];
        effect = turnEffects->mLevel2Effects[sideIndex];
        coord = sidePositions[sideIndex].x;
        effect->mPosition.x = coord + effect->mResource->mHeader->mPositionOffset.x;
        coord = sidePositions[sideIndex].y;
        effect->mPosition.y = coord + effect->mResource->mHeader->mPositionOffset.y;
        coord = sidePositions[sideIndex].z;
        effect->mPosition.z = coord + effect->mResource->mHeader->mPositionOffset.z;
    }
    if (turnEffects->mTurnStartPresent == 0) {
        return;
    }
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mTurnStartEffects[sideIndex]->mFlags.mEmissionStopped = 1;
    }
}

void ReleaseKartTurnEffects(KartTurnEffects *turnEffects) {
    u16 sideIndex;
    u16 level2SideIndex;

    if (turnEffects->mTurnStartPresent != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            DeleteEffectAndClearPointer(&turnEffects->mTurnStartEffects[sideIndex]);
        }
    }
    turnEffects->mTurnStartPresent = 0;
    if (turnEffects->mLevel4Present != 0) {
        turnEffects->mReleaseLevel4Effects(turnEffects);
    }
    turnEffects->mLevel4Present = 0;
    turnEffects->mLevel4StopFrames = 0;
    turnEffects->mLevel4StopRequested = FALSE;
    turnEffects->mLevel4RestartFrames = 0;
    turnEffects->mLevel4RestartRequested = 0;
    if (turnEffects->mLevel3Present != 0) {
        for (sideIndex = 0; sideIndex < 2; sideIndex++) {
            DeleteEffect(turnEffects->mLevel3FirstEffects[sideIndex]);
            DeleteEffect(turnEffects->mLevel3SecondEffects[sideIndex]);
            turnEffects->mLevel3FirstEffects[sideIndex] = NULL;
            turnEffects->mLevel3SecondEffects[sideIndex] = NULL;
        }
    }
    turnEffects->mLevel3Present = 0;
    turnEffects->mLevel3Frames = 0;
    if (turnEffects->mLevel2Present != FALSE) {
        for (level2SideIndex = 0; level2SideIndex < 2; level2SideIndex++) {
            DeleteEffect(turnEffects->mLevel2Effects[level2SideIndex]);
            turnEffects->mLevel2Effects[level2SideIndex] = NULL;
        }
    }
    turnEffects->mLevel2Present = FALSE;
    turnEffects->mLevel2Frames = 0;
}

KartTurnEffects *GetKartTurnEffects(int kartIndex) {
    return gKartTurnEffects + kartIndex;
}

void StopKartTurnEffects(KartTurnEffects *turnEffects) {
    u16 sideIndex;

    if (turnEffects->mLevel4Present == 0) {
        turnEffects->mLevel4StopRequested = FALSE;
    } else {
        turnEffects->mStopLevel4Effects(turnEffects);
        turnEffects->mLevel4StopRequested = TRUE;
    }
    turnEffects->mLevel4RestartFrames = 0;
    turnEffects->mLevel4RestartRequested = 0;
    if (turnEffects->mTurnStartPresent == 0) {
        return;
    }
    for (sideIndex = 0; sideIndex < 2; sideIndex++) {
        turnEffects->mTurnStartEffects[sideIndex]->mFlags.mEnding = 1;
        turnEffects->mTurnStartEffects[sideIndex] = NULL;
    }
    turnEffects->mTurnStartPresent = 0;
}

void RequestKartLevel4EffectsRestart(KartTurnEffects *kartTurnEffects) {
    kartTurnEffects->mLevel4RestartFrames = 0x0u;
    kartTurnEffects->mLevel4RestartRequested = 0x1u;
}

void HideKartTurnEffects(KartTurnEffects *kartTurnEffects) {
    kartTurnEffects->mHideEffects(kartTurnEffects);
}

void ShowKartTurnEffects(KartTurnEffects *kartTurnEffects) {
    u32 showFunction = (*(u32 *) (((u32) kartTurnEffects) + (128)));
    u32 showResult = ((u32(*)(u32))(showFunction))((u32) kartTurnEffects);
}
