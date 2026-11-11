#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02087934.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0208c4e8.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02103840.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_02109184.h"
#include "Main/Unknown/code_0210a664.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/code_021035ac.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "01/code_0218155c.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020681f0.h"

BOOL TryStartKartScaleTableEffect(Kart *kart) {
    KartItemEffectState *effectState;
    s32 mode;

    effectState = &kart->mItemEffectData;
    if ((kart->mUnk_4c & 0x10000040) || (kart->mUnk_48 & 0x10000)) {
        return FALSE;
    }
    effectState->mScaleTableIndex = 0;
    effectState->mScaleEffectTimer = 0x258;
    kart->mScaleFactor.x = 0x1000;
    kart->mScaleFactor.y = 0x1000;
    kart->mScaleFactor.z = 0x1000;
    kart->mTireSpinAngle = 0;
    kart->mUnk_4c |= 0x10000;
    kart->mUnk_48 |= 0x4000000;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetCameraHalfFovAngleGoal(0x1f40);
    }
    kart->mShrinkFactor = 0xb33;
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    mode = gRaceSetup->mMode;
    if (mode == MODE_MISSION_RUN) {
        if (mode == MODE_MISSION_RUN) {
            func_ov001_0218173c();
        }
    }
    if (!(kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT))) {
        StartKartSeqArcSound(kart, kart->mSoundIndex, 0);
    }
    return TRUE;
}

void AdvanceKartScaleTableEffect(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->mItemEffectData;
    if (effectState->mScaleEffectTimer <= 0) {
        if (effectState->mScaleTableIndex == 0) {
            StartSound(&kart->mSoundSource, 0xed, 0x7f, 0);
        }
        effectState->mScaleTableIndex++;
        if (effectState->mScaleTableIndex >= 0x19) {
            kart->mUnk_398 = 0x1000;
            kart->mScaleYFactor = 0x1000;
            kart->mScaleFactor.x = 0x1000;
            kart->mScaleFactor.y = 0x1000;
            kart->mScaleFactor.z = 0x1000;
            kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
            kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
            kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
            kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
            if (effectState->mScaleTableIndex > 0x19) {
                kart->mUnk_4c &= ~0x10000;
                if (!(kart->mUnk_4c & 0x10080)) {
                    kart->mShrinkFactor = 0x1000;
                }
                return;
            }
            kart->mUnk_4c |= 0x100;
            return;
        }
        kart->mUnk_398 = 0x1000;
        kart->mUnk_4c |= 0x100;
        kart->mScaleFactor.x = gKartScaleFactorXTable[effectState->mScaleTableIndex];
        kart->mScaleFactor.y = gKartScaleFactorYTable[effectState->mScaleTableIndex];
        kart->mScaleFactor.z = gKartScaleFactorZTable[effectState->mScaleTableIndex];
        kart->mScaleYFactor = 0x1000;
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
        return;
    }
    effectState->mScaleEffectTimer--;
    if (effectState->mScaleEffectTimer == 0x1c2) {
        kart->mUnk_48 &= ~0x4000000;
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            ResetCameraHalfFovAngleGoal();
        }
    }
    if (kart->mUnk_48 & 0x4000000) {
        kart->mForwardSpeed = 0;
    }
    if (kart->mScaleYFactor > 0.3f / 4096.0f) {
        kart->mScaleYFactor -= 0x4cd;
        if (kart->mScaleYFactor < 0.3f / 4096.0f) {
            kart->mScaleYFactor = 0x4cd;
        }
    }
    kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
    kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
    kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
    kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
}

void ResetKartScaleEffects(Kart *kart) {
    kart->mUnk_398 = 0x1000;
    kart->mScaleYFactor = 0x1000;
    kart->mScale.y = 0x1000;
    kart->mUnk_4c &= ~0x10000;
    if (kart->mUnk_4c & KART_4C_THUNDER_SHRINK) {
        kart->mUnk_4c &= ~KART_4C_THUNDER_SHRINK;
        kart->mScaleBase.x = 0x1000;
        kart->mScaleBase.y = 0x1000;
        kart->mScaleBase.z = 0x1000;
        if (kart->mIndex == gRaceSetup->mEntryIndex) {
            SetThunderShrinkSoundFlag(0);
        }
        ResetKartTrackParamsFunction(kart);
    }
    kart->mScale.x = 0x1000;
    kart->mScale.y = 0x1000;
    kart->mScale.z = 0x1000;
    kart->mScaleFactor.x = 0x1000;
    kart->mScaleFactor.y = 0x1000;
    kart->mScaleFactor.z = 0x1000;
    if (!(kart->mUnk_4c & 0x10080)) {
        kart->mShrinkFactor = 0x1000;
    }
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        ResetCameraHalfFovAngleGoal();
    }
}

void StartKartThunder(Kart *kart) {
    u16 kartIndex;
    u32 bit200;

    kartIndex = 0;
    StartFadeFog();
    StartEffectsAtOtherKarts(kart->mIndex);
    bit200 = kart->mUnk_7c & 0x200;
    if (bit200 != 0) {
        if (bit200 != 0) {
            kart->mParticipantRecordData->mEventToggleFlags ^= 0x4000;
        }
        return;
    }
    for (; kartIndex < (u32) gRaceSetup->mKartCount; kartIndex++) {
        if (kartIndex != kart->mIndex) {
            StartKartThunderShrink(GetKart(kartIndex));
        }
    }
}

void StartKartKinokoBoost(Kart *kart) {
    StartKartBoost(kart, KART_BOOST_ITEM_OR_SURFACE, 0x5a);
    kart->mUnk_48 |= 0x100000;
    kart->mItemEffectData.mKinokoBoostTimer = 0x5a;
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    ClearStandingsHitSeenFromKart(kart->mIndex);
}

void StartKartStar(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->mItemEffectData;
    if (kart->mUnk_4c & 0x10000000) {
        return;
    }
    if (kart->mUnk_7c & KART_7C_TERESA) {
        kart->mUnk_7c &= ~KART_7C_TERESA;
        kart->mUnk_7c &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            ShowKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else {
            StartSound(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        SetTeresaSoundFlag(0, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
    if (kart->mUnk_4c & 0x8000000) {
        kart->mUnk_4c &= ~0x8020000;
        if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
            SetKartModelsGrayColors(kart);
        }
        SetKartModelsEntryCourseColors(kart->mKartModelsEntry);
    }
    SkipOrthoQuadsHold(kart->mIndex);
    effectState->mStarFrames = 0;
    kart->mUnk_4c |= 0x40;
    kart->mItemEffect = 1;
    StartKartStarModels(kart);
    StartKartStarEffects(kart->mIndex);
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        StartKartStarSeq();
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        StandingsReturnArgument(kart->mIndex);
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x2000;
    }
    SetKartCharacterAnimation(kart, 2, 1);
}

// Teresa: the Boo item (mItemEffect 2).
void StartKartTeresa(Kart *kart) {
    KartItemEffectState *effectState;
    KartItemEffectState *effectStateAgain;
    u32 kartBits;

    effectState = &kart->mItemEffectData;
    effectState->mTeresaFrames = 0;
    if (kart->mUnk_4c & 0x10000040) {
        kart->mUnk_4c &= ~0x40;
        StopKartStarModels(kart);
        kart->mItemEffect = 0;
        StopKartStarEffects(kart->mIndex);
        SetKartCharacterAnimation(kart, 0, 1);
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
            StopKartStarSeq();
        }
        if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
            SetKartModelsGrayColors(kart);
        }
    }
    kart->mUnk_7c |= KART_7C_TERESA;
    kart->mItemEffect = 2;
    SkipOrthoQuadsHold(kart->mIndex);
    kartBits = kart->mUnk_4c;
    if (!(kartBits & 0x20000) && (kartBits & 0x8000000)) {
        effectStateAgain = &kart->mItemEffectData;
        if (effectStateAgain->mGessoFrames <= 0x190) {
            effectStateAgain->mGessoFrames = 0x190;
            kart->mUnk_4c |= 0x20000;
            StartKartModelColorBlend(kart->mKartModelsEntry, GetKartCourseDiffColor(), GetKartCourseEmiColor(),
                                     GetKartCourseAmbColor());
        }
    }
    SetTeresaSoundFlag(1, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        kart->mUnk_7c |= 0x4000;
    } else {
        effectState->mTeresaToggleDivisor = 2;
        effectState->mTeresaStepFrames = 0;
        effectState->mTeresaStepLimit = 10;
        effectState->mTeresaToggleFrames = 0;
        effectState->mTeresaDivisorStep = 1;
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x4000000;
    }
}

void AdvanceKartTeresa(Kart *kart) {
    KartItemEffectState *effectState;
    Vec3 entryPos;
    Vec3 kartPos;
    u32 kartBits;
    s32 diffX;
    s32 diffY;
    s32 diffZ;

    kartBits = kart->mUnk_7c;
    if (kartBits & KART_4C_BLINK_GUARD) {
        return;
    }
    effectState = &kart->mItemEffectData;
    if (!(kartBits & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        if (effectState->mTeresaToggleFrames < 0x50) {
            effectState->mTeresaToggleFrames++;
            effectState->mTeresaStepFrames++;
            if (effectState->mTeresaStepFrames > effectState->mTeresaStepLimit) {
                effectState->mTeresaStepFrames = 0;
                effectState->mTeresaToggleDivisor = effectState->mTeresaToggleDivisor + effectState->mTeresaDivisorStep;
                effectState->mTeresaStepLimit = effectState->mTeresaStepLimit + effectState->mTeresaDivisorStep * 5;
            }
            if (effectState->mTeresaToggleFrames % effectState->mTeresaToggleDivisor == 0) {
                kart->mUnk_7c &= ~0x8000;
            } else {
                kart->mUnk_7c |= 0x8000;
            }
            if (effectState->mTeresaToggleFrames >= 0x50) {
                kart->mUnk_7c |= 0x8000;
            }
        }
        if (effectState->mTeresaFrames == 0x172) {
            effectState->mTeresaDivisorStep = -1;
            effectState->mTeresaToggleFrames = 0;
        }
        HideKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    }
    effectState->mTeresaFrames++;
    if (effectState->mTeresaFrames > KART_TERESA_MAX_FRAMES && (kart->mUnk_7c & KART_7C_TERESA)) {
        kart->mUnk_7c &= ~KART_7C_TERESA;
        kart->mUnk_7c &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            ShowKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else {
            StartSound(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        SetTeresaSoundFlag(0, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        return;
    }
    GetKartPos(&entryPos, (u16) gRaceSetup->mEntryIndex);
    GetKartPos(&kartPos, kart->mIndex);
    diffX = (entryPos.x - kartPos.x) >> 12;
    diffY = (entryPos.y - kartPos.y) >> 12;
    diffZ = (entryPos.z - kartPos.z) >> 12;
    SetMinKartDistanceSquared(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

// Killer: the Bullet Bill item (mItemEffect 3).
void StartKartKiller(Kart *kart) {
    KartItemEffectState *effectState;
    KartKillerEndRankOffsets rankOffsets;
    KartFollowEffectIds effectIds;
    s32 i;
    u8 kartCount;

    rankOffsets = data_usa_0216557c;
    effectState = &kart->mItemEffectData;
    effectState->mKillerFrames = 0;
    effectState->mUnk_20 = 0;
    effectState->mKillerEnding = FALSE;
    SetupKartKillerCursor(&effectState->mKillerCursor, kart->mIndex);
    kart->mUnk_4c |= 0x10000000;
    kartCount = gRaceSetup->mKartCount;
    effectState->mKillerEndRank = GetKartRank(kart->mIndex) - rankOffsets.mOffsets[kartCount - 1];
    if (effectState->mKillerEndRank <= 0) {
        effectState->mKillerEndRank = 1;
    }
    kart->mKartModelsEntry->mKillerItemAnimation.mFrameIndex = 0;
    if (kart->mUnk_7c & KART_7C_TERESA) {
        kart->mUnk_7c &= ~KART_7C_TERESA;
        kart->mUnk_7c &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            ShowKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else {
            StartSound(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        SetTeresaSoundFlag(0, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
    if (kart->mUnk_4c & 0x8000000) {
        kart->mUnk_4c &= ~0x8020000;
        if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
            SetKartModelsGrayColors(kart);
        }
        SetKartModelsEntryCourseColors(kart->mKartModelsEntry);
    }
    SkipOrthoQuadsHoldAndSetVelocities(kart->mIndex);
    if (kart->mUnk_4c & 0x40) {
        kart->mUnk_4c &= ~0x40;
        StopKartStarModels(kart);
        kart->mItemEffect = 0;
        StopKartStarEffects(kart->mIndex);
        SetKartCharacterAnimation(kart, 0, 1);
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
            StopKartStarSeq();
        }
        if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
            SetKartModelsGrayColors(kart);
        }
    }
    kart->mItemEffect = 3;
    if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
        kart->mUnk_4c &= ~KART_4C_AHEAD_BOOST;
        kart->mAheadSpeedLimitFactor = 0x1000;
        if (!(kart->mUnk_4c & 0x8000000)) {
            ResetKartModelsCourseColors(kart);
        }
        StopKartNearRankEffect(kart);
    }
    if (kart->mKartModelsEntry->mKartModelHidden == 0) {
        effectIds = gKartFollowEffectIds;
        for (i = 0; i < 3; i++) {
            SetupKartFollowEffect(StartEffect(effectIds.mEffectIds[i], &kart->mPos), kart->mIndex, 0x14);
        }
    }
    StartKartKillerEffect(kart->mIndex);
    ResetKartScaleEffects(kart);
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x100000;
    }
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetCameraHalfFovAngleGoal(0x1d4c);
    }
}

void AdvanceKartKiller(Kart *kart) {
    KartItemEffectState *effectState;
    KartItemEffectState *effectStateAgain;
    s32 i;
    BOOL rankReached;
    BOOL endEarly;
    KartFollowEffectIds effectIds;

    effectState = &kart->mItemEffectData;
    effectState->mKillerFrames++;
    if (!(kart->mUnk_7c & 0x400)) {
        if (AdvanceKartKillerCursor(&effectState->mKillerCursor) != 0) {
            effectStateAgain = &kart->mItemEffectData;
            if ((kart->mUnk_4c & 0x10000000) && effectStateAgain->mKillerEnding == FALSE) {
                effectStateAgain->mKillerEnding = TRUE;
                if (kart->mUnk_7c & 0x200) {
                    kart->mParticipantRecordData->mEventToggleFlags ^= 0x200000;
                }
            }
        }
    }
    AdvanceModelAnimationFrame(&kart->mKartModelsEntry->mKillerItemAnimation);
    if (effectState->mKillerEnding != FALSE) {
        kart->mRadiusFactor -= 0x52;
        if (kart->mRadiusFactor > 0x1000) {
            return;
        }
        kart->mUnk_4c &= ~0x10000000;
        ResetKartActiveItemAfterKiller(kart->mIndex);
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            ResetCameraHalfFovAngleGoal();
        }
        kart->mRadiusFactor = 0x1000;
        kart->mSurfaceGroup = -1;
        i = 0;
        kart->mItemEffect = 0;
        if (kart->mKartModelsEntry->mKartModelHidden == 0) {
            effectIds = gKartFollowEffectIds;
            for (i = 0; i < 3; i++) {
                SetupKartFollowEffect(StartEffect(effectIds.mEffectIds[i], &kart->mPos), kart->mIndex, 0x14);
            }
        }
        StopKartKillerEffect(kart->mIndex);
        StartSound(&kart->mSoundSource, 0xfd, 0x7f, 0);
        return;
    }
    kart->mRadiusFactor += 0x52;
    if (kart->mRadiusFactor > 0x1666) {
        kart->mRadiusFactor = 0x1666;
    }
    if (effectState->mKillerEnding != FALSE) {
        return;
    }
    rankReached = FALSE;
    endEarly = FALSE;
    if (!(kart->mUnk_7c & 0x400)) {
        if (GetKartRank(kart->mIndex) == 1) {
            rankReached = TRUE;
        } else if ((s32) GetKartRank(kart->mIndex) <= effectState->mKillerEndRank) {
            rankReached = TRUE;
        }
        if (effectState->mKillerFrames > KART_KILLER_RANK_END_FRAMES && rankReached != FALSE) {
            endEarly = TRUE;
        }
    }
    if (effectState->mKillerFrames <= KART_KILLER_MAX_FRAMES && endEarly == FALSE) {
        return;
    }
    effectState->mKillerEnding = TRUE;
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x200000;
    }
}

void StartKartGesso(Kart *kart, u32 orthoQuadCount) {
    u32 kartBits;

    if (kart->mUnk_7c & 0x400) {
        return;
    }
    if (IsKartEnded(kart->mIndex) != 0) {
        return;
    }
    kartBits = kart->mUnk_7c;
    if (kartBits & 0x60) {
        return;
    }
    if (kart->mUnk_4c & 0x10000040) {
        return;
    }
    if (kartBits & KART_7C_TERESA) {
        return;
    }
    kart->mItemEffectData.mGessoFrames = 0;
    kart->mUnk_4c |= 0x8000000;
    kart->mUnk_4c &= ~0x20000;
    if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
        ResetKartModelsCourseColors(kart);
    }
    StartKartModelColorBlend(kart->mKartModelsEntry, 0, 0x1084, 0);
    if (kart->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
        StartKartCharacterAnimationOnce(kart, 1, 0);
        SetCharacterFaceFrameIndex(kart->mKartModelsEntry, 1);
    }
    if (!(kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT))) {
        StartKartSeqArcSound(kart, kart->mSoundIndex, 0);
    }
    StartOrthoQuadsGesoSumi(kart->mIndex, orthoQuadCount);
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x80000;
    }
}

void AdvanceKartGesso(Kart *kart) {
    KartItemEffectState *effectState;
    u32 kartBits;

    kartBits = kart->mUnk_4c;
    effectState = &kart->mItemEffectData;
    if (!(kartBits & 0x40)) {
        if (effectState->mGessoFrames == 0x190 && !(kartBits & 0x20000) && (kartBits & 0x8000000) &&
            effectState->mGessoFrames <= 0x190) {
            effectState->mGessoFrames = 0x190;
            kart->mUnk_4c |= 0x20000;
            StartKartModelColorBlend(kart->mKartModelsEntry, GetKartCourseDiffColor(), GetKartCourseEmiColor(),
                                     GetKartCourseAmbColor());
        }
        AdvanceKartModelColorBlend(kart->mKartModelsEntry, (kart->mUnk_4c & 0x20000) ? 0x52 : 0x19a);
    }
    effectState->mGessoFrames++;
    if (effectState->mGessoFrames <= 0x1c2) {
        return;
    }
    if (!(kart->mUnk_4c & 0x8000000)) {
        return;
    }
    kart->mUnk_4c &= ~0x8020000;
    if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
        SetKartModelsGrayColors(kart);
    }
    SetKartModelsEntryCourseColors(kart->mKartModelsEntry);
}

void StartKartAheadBoost(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->mItemEffectData;
    effectState->mAheadBoostFrames = 0;
    effectState->mAheadCount = 0;
    kart->mAheadSpeedLimitFactor = data_usa_021654dc;
    kart->mUnk_4c &= ~KART_4C_AHEAD_BUILD_UP;
    if (!(kart->mUnk_4c & KART_4C_AHEAD_BOOST)) {
        kart->mUnk_4c |= KART_4C_AHEAD_BOOST;
        if (!(kart->mUnk_4c & 0x8000000)) {
            SetKartModelsGrayColors(kart);
        }
    }
    if (kart->mUnk_4c & 0x48000) {
        StartKartNearRankEffect(kart);
    }
    StopKartAheadEffect(kart);
    StopKartSoundWhileRequested(kart);
    if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        StartSound(&kart->mSoundSource, 0xa4, 0x7f, 0);
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x40000;
    }
}

void StartKartRemovalFromProgress(Kart *kart) {
    StartKartRemoval(kart, 1);
    kart->mUnk_7c |= 0x800000;
}

// Takes the kart out of play unless it is out already; returns whether it did.
BOOL StartKartRemoval(Kart *kart, s32 fromRaceProgress) {
    BOOL removed;
    u32 kartBits;
    NNSSndSeqPlayer **seqPlayerHandle;

    removed = FALSE;
    if (fromRaceProgress != 0) {
        kartBits = kart->mUnk_7c;
        if (!(kartBits & 0x800000)) {
            removed = TRUE;
        }
    } else {
        kartBits = kart->mUnk_7c;
        if (!(kartBits & 0x900020)) {
            removed = TRUE;
        }
    }
    if (removed != FALSE) {
        if (!(kartBits & 0x4000000)) {
            DecrementKartAiNonCpuCount(kart->mIndex);
            kart->mUnk_7c |= 0x4000000;
        }
        kart->mUnk_7c |= KART_7C_REMOVED;
        if (kart->mCollisionSlot != -1) {
            kart->mCollisionSlot = FreeCollisionSlot(kart->mCollisionSlot);
        }
        if (kart->mSecondCollisionSlot != -1) {
            kart->mSecondCollisionSlot = FreeCollisionSlot(kart->mSecondCollisionSlot);
        }
        if (gRaceSetup->mMode == MODE_BATTLE && fromRaceProgress == 0) {
            StartSound(&kart->mSoundSource, 0xd3, 0x7f, 0);
            if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON && (gRaceSoundKind & 1)) {
                seqPlayerHandle = TakeSoundHandleEntry(GetSoundHandlePool(0));
                if (gSoundModeHolder.mSeqStartEnabled != 0) {
                    if (seqPlayerHandle[0] != NULL) {
                        NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
                    }
                    if (seqPlayerHandle[0] != NULL) {
                        NNS_SndPlayerStopSeq(seqPlayerHandle, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(seqPlayerHandle, 0, 0x4c);
                }
            }
        }
        kart->mFramesSinceRemovalOrReset = 0;
        StopKartItemsAndEffects(kart);
    }
    return removed;
}

BOOL IsKartRemoved(Kart *kart) {
    return (kart->mUnk_7c & 0x60) != 0;
}
