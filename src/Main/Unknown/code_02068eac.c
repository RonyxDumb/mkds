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
#include "Main/Kart/KartTurnEffects.h"
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
#include "Main/Item/ItemInUse.h"
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
#include "Main/System/SoundFalloff.h"
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
#include "Main/Kart/KartStates.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Kart/KartTimes.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020681f0.h"

BOOL driver_startDossunFlatEffect(Kart *kart) {
    KartItemEffectState *effectState;
    s32 mode;

    effectState = &kart->mUnk_538;
    if ((kart->mUnk_4c & 0x10000040) || (kart->mUnk_48 & 0x10000)) {
        return FALSE;
    }
    effectState->mUnk_0c = 0;
    effectState->mUnk_0e = 0x258;
    kart->mScaleFactor.x = 0x1000;
    kart->mScaleFactor.y = 0x1000;
    kart->mScaleFactor.z = 0x1000;
    kart->mTireSpinAngle = 0;
    kart->mUnk_4c |= 0x10000;
    kart->mUnk_48 |= 0x4000000;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        cam_setPlayerCameraTargetFov(0x1f40);
    }
    kart->mUnk_394 = 0xb33;
    it_dropDriverItem(&(it_sDriverItemStatus)[kart->mIndex]);
    mode = gRaceMultiConfig->mMode;
    if (mode == MODE_MISSION_RUN) {
        if (mode == MODE_MISSION_RUN) {
            mrcnt_notifyPlayerDamage();
        }
    }
    if (!(kart->mUnk_48 & 0x840)) {
        sfx_emitDriverVoice(kart, kart->mSoundIndex, 0);
    }
    return TRUE;
}

void driver_updateDossunFlatEffect(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->mUnk_538;
    if (effectState->mUnk_0e <= 0) {
        if (effectState->mUnk_0c == 0) {
            sfx_21090C4(&kart->mSoundSource, 0xed, 0x7f, 0);
        }
        effectState->mUnk_0c++;
        if (effectState->mUnk_0c >= 0x19) {
            kart->mUnk_398 = 0x1000;
            kart->mScaleYFactor = 0x1000;
            kart->mScaleFactor.x = 0x1000;
            kart->mScaleFactor.y = 0x1000;
            kart->mScaleFactor.z = 0x1000;
            kart->mScale.x = ((s64) kart->mScaleBase.x * kart->mScaleFactor.x) >> 12;
            kart->mScale.y = ((s64) kart->mScaleBase.y * kart->mScaleFactor.y) >> 12;
            kart->mScale.z = ((s64) kart->mScaleBase.z * kart->mScaleFactor.z) >> 12;
            kart->mScale.y = ((s64) kart->mScaleYFactor * kart->mScale.y) >> 12;
            if (effectState->mUnk_0c > 0x19) {
                kart->mUnk_4c &= ~0x10000;
                if (!(kart->mUnk_4c & 0x10080)) {
                    kart->mUnk_394 = 0x1000;
                }
                return;
            }
            kart->mUnk_4c |= 0x100;
            return;
        }
        kart->mUnk_398 = 0x1000;
        kart->mUnk_4c |= 0x100;
        kart->mScaleFactor.x = gKartScaleFactorXTable[effectState->mUnk_0c];
        kart->mScaleFactor.y = gKartScaleFactorYTable[effectState->mUnk_0c];
        kart->mScaleFactor.z = gKartScaleFactorZTable[effectState->mUnk_0c];
        kart->mScaleYFactor = 0x1000;
        kart->mScale.x = ((s64) kart->mScaleBase.x * kart->mScaleFactor.x) >> 12;
        kart->mScale.y = ((s64) kart->mScaleBase.y * kart->mScaleFactor.y) >> 12;
        kart->mScale.z = ((s64) kart->mScaleBase.z * kart->mScaleFactor.z) >> 12;
        kart->mScale.y = ((s64) kart->mScaleYFactor * kart->mScale.y) >> 12;
        return;
    }
    effectState->mUnk_0e--;
    if (effectState->mUnk_0e == 0x1c2) {
        kart->mUnk_48 &= ~0x4000000;
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            cam_resetPlayerCameraTargetFov();
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
    kart->mScale.x = ((s64) kart->mScaleBase.x * kart->mScaleFactor.x) >> 12;
    kart->mScale.y = ((s64) kart->mScaleBase.y * kart->mScaleFactor.y) >> 12;
    kart->mScale.z = ((s64) kart->mScaleBase.z * kart->mScaleFactor.z) >> 12;
    kart->mScale.y = ((s64) kart->mScaleYFactor * kart->mScale.y) >> 12;
}

void driver_resetScaleEffects(Kart *kart) {
    kart->mUnk_398 = 0x1000;
    kart->mScaleYFactor = 0x1000;
    kart->mScale.y = 0x1000;
    kart->mUnk_4c &= ~0x10000;
    if (kart->mUnk_4c & KART_4C_THUNDER_SHRINK) {
        kart->mUnk_4c &= ~KART_4C_THUNDER_SHRINK;
        kart->mScaleBase.x = 0x1000;
        kart->mScaleBase.y = 0x1000;
        kart->mScaleBase.z = 0x1000;
        if (kart->mIndex == gRaceMultiConfig->mEntryIndex) {
            func_0210fa74(0);
        }
        func_0210a664(kart);
    }
    kart->mScale.x = 0x1000;
    kart->mScale.y = 0x1000;
    kart->mScale.z = 0x1000;
    kart->mScaleFactor.x = 0x1000;
    kart->mScaleFactor.y = 0x1000;
    kart->mScaleFactor.z = 0x1000;
    if (!(kart->mUnk_4c & 0x10080)) {
        kart->mUnk_394 = 0x1000;
    }
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        cam_resetPlayerCameraTargetFov();
    }
}

void driver_invokeThunder(Kart *kart) {
    u16 kartIndex;
    u32 bit200;

    kartIndex = 0;
    race_startDarkening();
    StartEffectsAtOtherKarts(kart->mIndex);
    bit200 = kart->mUnk_7c & 0x200;
    if (bit200 != 0) {
        if (bit200 != 0) {
            kart->mUnk_514->mUnk_2c ^= 0x4000;
        }
        return;
    }
    for (; kartIndex < (u32) gRaceMultiConfig->mKartCount; kartIndex++) {
        if (kartIndex != kart->mIndex) {
            driver_startThunderShrinkEffect(driver_getById(kartIndex));
        }
    }
}

void driver_startShroomBoost(Kart *kart) {
    driver_addBoost(kart, KART_BOOST_ITEM_OR_SURFACE, 0x5a);
    kart->mUnk_48 |= 0x100000;
    kart->mUnk_538.mUnk_00 = 0x5a;
    if (gRaceMultiConfig->mMode != MODE_BATTLE) {
        return;
    }
    mgcnt_20A1DDC(kart->mIndex);
}

void driver_startStarInvincibility(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->mUnk_538;
    if (kart->mUnk_4c & 0x10000000) {
        return;
    }
    if (kart->mUnk_7c & 0x2000) {
        kart->mUnk_7c &= ~0x2000;
        kart->mUnk_7c &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            dptc_showAll(dptc_getControllerForDriver(kart->mIndex));
        } else {
            sfx_21090C4(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        func_0210fa40(0, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
    if (kart->mUnk_4c & 0x8000000) {
        kart->mUnk_4c &= ~0x8020000;
        if (kart->mUnk_4c & 0x2000) {
            driver_enableSlipStreamToonMode(kart);
        }
        chkrt_applyKartCrsMat(kart->mKartModelsEntry);
    }
    cspl_clearSplashes(kart->mIndex);
    effectState->mUnk_06 = 0;
    kart->mUnk_4c |= 0x40;
    kart->mItemEffect = 1;
    driver_enableStarToonMode(kart);
    rptc_startRainbowEffect(kart->mIndex);
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
        snd_startStarMusic();
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        mgcnt_notifyStarInvincibilityStart(kart->mIndex);
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mUnk_514->mUnk_2c ^= 0x2000;
    }
    driver_2068A64(kart, 2, 1);
}

// Teresa: the Boo item (mItemEffect 2).
void driver_startTeresaEffect(Kart *kart) {
    KartItemEffectState *effectState;
    KartItemEffectState *effectStateAgain;
    u32 kartBits;

    effectState = &kart->mUnk_538;
    effectState->mTeresaFrames = 0;
    if (kart->mUnk_4c & 0x10000040) {
        kart->mUnk_4c &= ~0x40;
        driver_disableStarToonMode(kart);
        kart->mItemEffect = 0;
        rptc_stopRainbowEffect(kart->mIndex);
        driver_2068A64(kart, 0, 1);
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
            snd_stopStarMusic();
        }
        if (kart->mUnk_4c & 0x2000) {
            driver_enableSlipStreamToonMode(kart);
        }
    }
    kart->mUnk_7c |= 0x2000;
    kart->mItemEffect = 2;
    cspl_clearSplashes(kart->mIndex);
    kartBits = kart->mUnk_4c;
    if (!(kartBits & 0x20000) && (kartBits & 0x8000000)) {
        effectStateAgain = &kart->mUnk_538;
        if (effectStateAgain->mUnk_1c <= 0x190) {
            effectStateAgain->mUnk_1c = 0x190;
            kart->mUnk_4c |= 0x20000;
            chkrt_setTargetColors(kart->mKartModelsEntry, chkrt_getKartCrsMatDiffuse(), chkrt_getKartCrsMatEmission(),
                                     chkrt_getKartCrsMatAmbient());
        }
    }
    func_0210fa40(1, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        kart->mUnk_7c |= 0x4000;
    } else {
        effectState->mUnk_12 = 2;
        effectState->mUnk_14 = 0;
        effectState->mUnk_18 = 10;
        effectState->mUnk_16 = 0;
        effectState->mUnk_1a = 1;
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mUnk_514->mUnk_2c ^= 0x4000000;
    }
}

void driver_updateTeresaEffect(Kart *kart) {
    KartItemEffectState *effectState;
    Vec3 entryPos;
    Vec3 kartPos;
    u32 kartBits;
    s32 diffX;
    s32 diffY;
    s32 diffZ;

    kartBits = kart->mUnk_7c;
    if (kartBits & 0x400000) {
        return;
    }
    effectState = &kart->mUnk_538;
    if (!(kartBits & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        if (effectState->mUnk_16 < 0x50) {
            effectState->mUnk_16++;
            effectState->mUnk_14++;
            if (effectState->mUnk_14 > effectState->mUnk_18) {
                effectState->mUnk_14 = 0;
                effectState->mUnk_12 = effectState->mUnk_12 + effectState->mUnk_1a;
                effectState->mUnk_18 = effectState->mUnk_18 + effectState->mUnk_1a * 5;
            }
            if (effectState->mUnk_16 % effectState->mUnk_12 == 0) {
                kart->mUnk_7c &= ~0x8000;
            } else {
                kart->mUnk_7c |= 0x8000;
            }
            if (effectState->mUnk_16 >= 0x50) {
                kart->mUnk_7c |= 0x8000;
            }
        }
        if (effectState->mTeresaFrames == 0x172) {
            effectState->mUnk_1a = -1;
            effectState->mUnk_16 = 0;
        }
        dptc_hideAll(dptc_getControllerForDriver(kart->mIndex));
    }
    effectState->mTeresaFrames++;
    if (effectState->mTeresaFrames > KART_TERESA_MAX_FRAMES && (kart->mUnk_7c & 0x2000)) {
        kart->mUnk_7c &= ~0x2000;
        kart->mUnk_7c &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            dptc_showAll(dptc_getControllerForDriver(kart->mIndex));
        } else {
            sfx_21090C4(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        func_0210fa40(0, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        return;
    }
    driver_getPosition(&entryPos, (u16) gRaceMultiConfig->mEntryIndex);
    driver_getPosition(&kartPos, kart->mIndex);
    diffX = (entryPos.x - kartPos.x) >> 12;
    diffY = (entryPos.y - kartPos.y) >> 12;
    diffZ = (entryPos.z - kartPos.z) >> 12;
    SetMinKartDistanceSquared(diffX * diffX + diffY * diffY + diffZ * diffZ);
}

// Killer: the Bullet Bill item (mItemEffect 3).
void driver_startKillerMode(Kart *kart) {
    KartItemEffectState *effectState;
    KartKillerEndRankOffsets rankOffsets;
    KartFollowEffectIds effectIds;
    s32 i;
    u8 kartCount;

    rankOffsets = driver_sKillerPlaceImprovement;
    effectState = &kart->mUnk_538;
    effectState->mKillerFrames = 0;
    effectState->mUnk_20 = 0;
    effectState->mKillerEnding = FALSE;
    SetupKartKillerCursor(&effectState->mKillerCursor, kart->mIndex);
    kart->mUnk_4c |= 0x10000000;
    kartCount = gRaceMultiConfig->mKartCount;
    effectState->mKillerEndRank = rstat_getPlace(kart->mIndex) - rankOffsets.mUnk_00[kartCount - 1];
    if (effectState->mKillerEndRank <= 0) {
        effectState->mKillerEndRank = 1;
    }
    kart->mKartModelsEntry->mUnk_0a4 = 0;
    if (kart->mUnk_7c & 0x2000) {
        kart->mUnk_7c &= ~0x2000;
        kart->mUnk_7c &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            dptc_showAll(dptc_getControllerForDriver(kart->mIndex));
        } else {
            sfx_21090C4(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        func_0210fa40(0, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
    if (kart->mUnk_4c & 0x8000000) {
        kart->mUnk_4c &= ~0x8020000;
        if (kart->mUnk_4c & 0x2000) {
            driver_enableSlipStreamToonMode(kart);
        }
        chkrt_applyKartCrsMat(kart->mKartModelsEntry);
    }
    cspl_speedClearSplashes(kart->mIndex);
    if (kart->mUnk_4c & 0x40) {
        kart->mUnk_4c &= ~0x40;
        driver_disableStarToonMode(kart);
        kart->mItemEffect = 0;
        rptc_stopRainbowEffect(kart->mIndex);
        driver_2068A64(kart, 0, 1);
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
            snd_stopStarMusic();
        }
        if (kart->mUnk_4c & 0x2000) {
            driver_enableSlipStreamToonMode(kart);
        }
    }
    kart->mItemEffect = 3;
    if (kart->mUnk_4c & 0x2000) {
        kart->mUnk_4c &= ~0x2000;
        kart->mUnk_d8 = 0x1000;
        if (!(kart->mUnk_4c & 0x8000000)) {
            driver_disableSlipStreamToonMode(kart);
        }
        rptc_stopSlipstreamEffect(kart);
    }
    if (kart->mKartModelsEntry->mUnk_058 == 0) {
        effectIds = gKartFollowEffectIds;
        for (i = 0; i < 3; i++) {
            rptc_2081F10(ptcm_createEmitter(effectIds.mEffectIds[i], &kart->mPos), kart->mIndex, 0x14);
        }
    }
    rptc_startKillerEffect(kart->mIndex);
    driver_resetScaleEffects(kart);
    if (kart->mUnk_7c & 0x200) {
        kart->mUnk_514->mUnk_2c ^= 0x100000;
    }
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        cam_setPlayerCameraTargetFov(0x1d4c);
    }
}

void driver_updateKillerMode(Kart *kart) {
    KartItemEffectState *effectState;
    KartItemEffectState *effectStateAgain;
    s32 i;
    BOOL rankReached;
    BOOL endEarly;
    KartFollowEffectIds effectIds;

    effectState = &kart->mUnk_538;
    effectState->mKillerFrames++;
    if (!(kart->mUnk_7c & 0x400)) {
        if (func_0209081c(&effectState->mKillerCursor) != 0) {
            effectStateAgain = &kart->mUnk_538;
            if ((kart->mUnk_4c & 0x10000000) && effectStateAgain->mKillerEnding == FALSE) {
                effectStateAgain->mKillerEnding = TRUE;
                if (kart->mUnk_7c & 0x200) {
                    kart->mUnk_514->mUnk_2c ^= 0x200000;
                }
            }
        }
    }
    anim_updateAnimator((ModelAnimation *) &kart->mKartModelsEntry->mUnk_098);
    if (effectState->mKillerEnding != FALSE) {
        kart->mRadiusFactor -= 0x52;
        if (kart->mRadiusFactor > 0x1000) {
            return;
        }
        kart->mUnk_4c &= ~0x10000000;
        func_0210515c(kart->mIndex);
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            cam_resetPlayerCameraTargetFov();
        }
        kart->mRadiusFactor = 0x1000;
        kart->mSurfaceGroup = -1;
        i = 0;
        kart->mItemEffect = 0;
        if (kart->mKartModelsEntry->mUnk_058 == 0) {
            effectIds = gKartFollowEffectIds;
            for (i = 0; i < 3; i++) {
                rptc_2081F10(ptcm_createEmitter(effectIds.mEffectIds[i], &kart->mPos), kart->mIndex, 0x14);
            }
        }
        rptc_stopBulletBillEffect(kart->mIndex);
        sfx_21090C4(&kart->mSoundSource, 0xfd, 0x7f, 0);
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
        if (rstat_getPlace(kart->mIndex) == 1) {
            rankReached = TRUE;
        } else if ((s32) rstat_getPlace(kart->mIndex) <= effectState->mKillerEndRank) {
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
        kart->mUnk_514->mUnk_2c ^= 0x200000;
    }
}

void driver_startGessoInk(Kart *kart, u32 orthoQuadCount) {
    u32 kartBits;

    if (kart->mUnk_7c & 0x400) {
        return;
    }
    if (rstat_hasDriverFinished(kart->mIndex) != 0) {
        return;
    }
    kartBits = kart->mUnk_7c;
    if (kartBits & 0x60) {
        return;
    }
    if (kart->mUnk_4c & 0x10000040) {
        return;
    }
    if (kartBits & 0x2000) {
        return;
    }
    kart->mUnk_538.mUnk_1c = 0;
    kart->mUnk_4c |= 0x8000000;
    kart->mUnk_4c &= ~0x20000;
    if (kart->mUnk_4c & 0x2000) {
        driver_disableSlipStreamToonMode(kart);
    }
    chkrt_setTargetColors(kart->mKartModelsEntry, 0, 0x1084, 0);
    if (kart->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
        driver_setAnimation(kart, 1, 0);
        driver_setFaceExpression(kart->mKartModelsEntry, 1);
    }
    if (!(kart->mUnk_48 & 0x840)) {
        sfx_emitDriverVoice(kart, kart->mSoundIndex, 0);
    }
    cspl_emitGessoSplash(kart->mIndex, orthoQuadCount);
    if (kart->mUnk_7c & 0x200) {
        kart->mUnk_514->mUnk_2c ^= 0x80000;
    }
}

void driver_updateGessoInk(Kart *kart) {
    KartItemEffectState *effectState;
    u32 kartBits;

    kartBits = kart->mUnk_4c;
    effectState = &kart->mUnk_538;
    if (!(kartBits & 0x40)) {
        if (effectState->mUnk_1c == 0x190 && !(kartBits & 0x20000) && (kartBits & 0x8000000) &&
            effectState->mUnk_1c <= 0x190) {
            effectState->mUnk_1c = 0x190;
            kart->mUnk_4c |= 0x20000;
            chkrt_setTargetColors(kart->mKartModelsEntry, chkrt_getKartCrsMatDiffuse(), chkrt_getKartCrsMatEmission(),
                                     chkrt_getKartCrsMatAmbient());
        }
        chkrt_progressColorInterpolation(kart->mKartModelsEntry, (kart->mUnk_4c & 0x20000) ? 0x52 : 0x19a);
    }
    effectState->mUnk_1c++;
    if (effectState->mUnk_1c <= 0x1c2) {
        return;
    }
    if (!(kart->mUnk_4c & 0x8000000)) {
        return;
    }
    kart->mUnk_4c &= ~0x8020000;
    if (kart->mUnk_4c & 0x2000) {
        driver_enableSlipStreamToonMode(kart);
    }
    chkrt_applyKartCrsMat(kart->mKartModelsEntry);
}

void driver_startSlipstream(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->mUnk_538;
    effectState->mUnk_0a = 0;
    effectState->mUnk_08 = 0;
    kart->mUnk_d8 = data_021654dc;
    kart->mUnk_4c &= ~0x4000;
    if (!(kart->mUnk_4c & 0x2000)) {
        kart->mUnk_4c |= 0x2000;
        if (!(kart->mUnk_4c & 0x8000000)) {
            driver_enableSlipStreamToonMode(kart);
        }
    }
    if (kart->mUnk_4c & 0x48000) {
        rptc_startSlipstreamEffect(kart);
    }
    rptc_stopSlipstreamBeginEffect(kart);
    StopKartSoundWhileRequested(kart);
    if (!(kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        sfx_21090C4(&kart->mSoundSource, 0xa4, 0x7f, 0);
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mUnk_514->mUnk_2c ^= 0x40000;
    }
}

void func_02069044(Kart *kart) {
    func_02068ec0(kart, 1);
    kart->mUnk_7c |= 0x800000;
}

s32 func_02068ec0(Kart *kart, s32 a) {
    BOOL removed;
    u32 kartBits;
    NNSSndSeqPlayer **seqPlayerHandle;

    removed = FALSE;
    if (a != 0) {
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
        kart->mUnk_7c |= 0x20;
        if (kart->mCollisionSlot != -1) {
            kart->mCollisionSlot = col_deleteColEntry(kart->mCollisionSlot);
        }
        if (kart->mUnk_2ca != -1) {
            kart->mUnk_2ca = col_deleteColEntry(kart->mUnk_2ca);
        }
        if (gRaceMultiConfig->mMode == MODE_BATTLE && a == 0) {
            sfx_21090C4(&kart->mSoundSource, 0xd3, 0x7f, 0);
            if (gRaceMultiConfig->mBattleKind == BATTLE_KIND_BALLOON && (data_0217c780 & 1)) {
                seqPlayerHandle = sp_acquireElement(sound_getPoolById(0));
                if (SoundHandle_217D084.mUnk_0c != 0) {
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
        kart->mUnk_3c8 = 0;
        driver_reset(kart);
    }
    return removed;
}

BOOL func_02068eac(Kart *kart) {
    return (kart->mUnk_7c & 0x60) != 0;
}
