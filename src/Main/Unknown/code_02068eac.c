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

    effectState = &kart->field538;
    if ((kart->field4C & 0x10000040) || (kart->field48 & 0x10000)) {
        return FALSE;
    }
    effectState->fieldC = 0;
    effectState->fieldE = 0x258;
    kart->mScaleFactor.x = 0x1000;
    kart->mScaleFactor.y = 0x1000;
    kart->mScaleFactor.z = 0x1000;
    kart->mTireSpinAngle = 0;
    kart->field4C |= 0x10000;
    kart->field48 |= 0x4000000;
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        cam_setPlayerCameraTargetFov(0x1f40);
    }
    kart->field394 = 0xb33;
    it_dropDriverItem(&(it_sDriverItemStatus)[kart->mIndex]);
    mode = gRaceMultiConfig->mMode;
    if (mode == MODE_MISSION_RUN) {
        if (mode == MODE_MISSION_RUN) {
            mrcnt_notifyPlayerDamage();
        }
    }
    if (!(kart->field48 & 0x840)) {
        sfx_emitDriverVoice(kart, kart->mSoundIndex, 0);
    }
    return TRUE;
}

void driver_updateDossunFlatEffect(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->field538;
    if (effectState->fieldE <= 0) {
        if (effectState->fieldC == 0) {
            sfx_21090C4(&kart->mSoundSource, 0xed, 0x7f, 0);
        }
        effectState->fieldC++;
        if (effectState->fieldC >= 0x19) {
            kart->field398 = 0x1000;
            kart->mScaleYFactor = 0x1000;
            kart->mScaleFactor.x = 0x1000;
            kart->mScaleFactor.y = 0x1000;
            kart->mScaleFactor.z = 0x1000;
            kart->mScale.x = ((s64) kart->mScaleBase.x * kart->mScaleFactor.x) >> 12;
            kart->mScale.y = ((s64) kart->mScaleBase.y * kart->mScaleFactor.y) >> 12;
            kart->mScale.z = ((s64) kart->mScaleBase.z * kart->mScaleFactor.z) >> 12;
            kart->mScale.y = ((s64) kart->mScaleYFactor * kart->mScale.y) >> 12;
            if (effectState->fieldC > 0x19) {
                kart->field4C &= ~0x10000;
                if (!(kart->field4C & 0x10080)) {
                    kart->field394 = 0x1000;
                }
                return;
            }
            kart->field4C |= 0x100;
            return;
        }
        kart->field398 = 0x1000;
        kart->field4C |= 0x100;
        kart->mScaleFactor.x = gKartScaleFactorXTable[effectState->fieldC];
        kart->mScaleFactor.y = gKartScaleFactorYTable[effectState->fieldC];
        kart->mScaleFactor.z = gKartScaleFactorZTable[effectState->fieldC];
        kart->mScaleYFactor = 0x1000;
        kart->mScale.x = ((s64) kart->mScaleBase.x * kart->mScaleFactor.x) >> 12;
        kart->mScale.y = ((s64) kart->mScaleBase.y * kart->mScaleFactor.y) >> 12;
        kart->mScale.z = ((s64) kart->mScaleBase.z * kart->mScaleFactor.z) >> 12;
        kart->mScale.y = ((s64) kart->mScaleYFactor * kart->mScale.y) >> 12;
        return;
    }
    effectState->fieldE--;
    if (effectState->fieldE == 0x1c2) {
        kart->field48 &= ~0x4000000;
        if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            cam_resetPlayerCameraTargetFov();
        }
    }
    if (kart->field48 & 0x4000000) {
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
    kart->field398 = 0x1000;
    kart->mScaleYFactor = 0x1000;
    kart->mScale.y = 0x1000;
    kart->field4C &= ~0x10000;
    if (kart->field4C & KART_4C_THUNDER_SHRINK) {
        kart->field4C &= ~KART_4C_THUNDER_SHRINK;
        kart->mScaleBase.x = 0x1000;
        kart->mScaleBase.y = 0x1000;
        kart->mScaleBase.z = 0x1000;
        if (kart->mIndex == gRaceMultiConfig->mEntryIndex) {
            sub_210FA74(0);
        }
        sub_210A664(kart);
    }
    kart->mScale.x = 0x1000;
    kart->mScale.y = 0x1000;
    kart->mScale.z = 0x1000;
    kart->mScaleFactor.x = 0x1000;
    kart->mScaleFactor.y = 0x1000;
    kart->mScaleFactor.z = 0x1000;
    if (!(kart->field4C & 0x10080)) {
        kart->field394 = 0x1000;
    }
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        cam_resetPlayerCameraTargetFov();
    }
}

void driver_invokeThunder(Kart *kart) {
    u16 kartIndex;
    u32 bit200;

    kartIndex = 0;
    race_startDarkening();
    StartEffectsAtOtherKarts(kart->mIndex);
    bit200 = kart->field7C & 0x200;
    if (bit200 != 0) {
        if (bit200 != 0) {
            kart->field514->field2C ^= 0x4000;
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
    kart->field48 |= 0x100000;
    kart->field538.field0 = 0x5a;
    if (gRaceMultiConfig->mMode != MODE_BATTLE) {
        return;
    }
    mgcnt_20A1DDC(kart->mIndex);
}

void driver_startStarInvincibility(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->field538;
    if (kart->field4C & 0x10000000) {
        return;
    }
    if (kart->field7C & 0x2000) {
        kart->field7C &= ~0x2000;
        kart->field7C &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            dptc_showAll(dptc_getControllerForDriver(kart->mIndex));
        } else {
            sfx_21090C4(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        sub_210FA40(0, (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
    if (kart->field4C & 0x8000000) {
        kart->field4C &= ~0x8020000;
        if (kart->field4C & 0x2000) {
            driver_enableSlipStreamToonMode(kart);
        }
        chkrt_applyKartCrsMat(kart->mKartModelsEntry);
    }
    cspl_clearSplashes(kart->mIndex);
    effectState->field6 = 0;
    kart->field4C |= 0x40;
    kart->mItemEffect = 1;
    driver_enableStarToonMode(kart);
    rptc_startRainbowEffect(kart->mIndex);
    if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
        snd_startStarMusic();
    }
    if (gRaceMultiConfig->mMode == MODE_BATTLE) {
        mgcnt_notifyStarInvincibilityStart(kart->mIndex);
    }
    if (kart->field7C & 0x200) {
        kart->field514->field2C ^= 0x2000;
    }
    driver_2068A64(kart, 2, 1);
}

// Teresa: the Boo item (mItemEffect 2).
void driver_startTeresaEffect(Kart *kart) {
    KartItemEffectState *effectState;
    KartItemEffectState *effectStateAgain;
    u32 kartBits;

    effectState = &kart->field538;
    effectState->mTeresaFrames = 0;
    if (kart->field4C & 0x10000040) {
        kart->field4C &= ~0x40;
        driver_disableStarToonMode(kart);
        kart->mItemEffect = 0;
        rptc_stopRainbowEffect(kart->mIndex);
        driver_2068A64(kart, 0, 1);
        if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
            snd_stopStarMusic();
        }
        if (kart->field4C & 0x2000) {
            driver_enableSlipStreamToonMode(kart);
        }
    }
    kart->field7C |= 0x2000;
    kart->mItemEffect = 2;
    cspl_clearSplashes(kart->mIndex);
    kartBits = kart->field4C;
    if (!(kartBits & 0x20000) && (kartBits & 0x8000000)) {
        effectStateAgain = &kart->field538;
        if (effectStateAgain->field1C <= 0x190) {
            effectStateAgain->field1C = 0x190;
            kart->field4C |= 0x20000;
            chkrt_setTargetColors(kart->mKartModelsEntry, chkrt_getKartCrsMatDiffuse(), chkrt_getKartCrsMatEmission(),
                                     chkrt_getKartCrsMatAmbient());
        }
    }
    sub_210FA40(1, (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        kart->field7C |= 0x4000;
    } else {
        effectState->field12 = 2;
        effectState->field14 = 0;
        effectState->field18 = 10;
        effectState->field16 = 0;
        effectState->field1A = 1;
    }
    if (kart->field7C & 0x200) {
        kart->field514->field2C ^= 0x4000000;
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

    kartBits = kart->field7C;
    if (kartBits & 0x400000) {
        return;
    }
    effectState = &kart->field538;
    if (!(kartBits & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        if (effectState->field16 < 0x50) {
            effectState->field16++;
            effectState->field14++;
            if (effectState->field14 > effectState->field18) {
                effectState->field14 = 0;
                effectState->field12 = effectState->field12 + effectState->field1A;
                effectState->field18 = effectState->field18 + effectState->field1A * 5;
            }
            if (effectState->field16 % effectState->field12 == 0) {
                kart->field7C &= ~0x8000;
            } else {
                kart->field7C |= 0x8000;
            }
            if (effectState->field16 >= 0x50) {
                kart->field7C |= 0x8000;
            }
        }
        if (effectState->mTeresaFrames == 0x172) {
            effectState->field1A = -1;
            effectState->field16 = 0;
        }
        dptc_hideAll(dptc_getControllerForDriver(kart->mIndex));
    }
    effectState->mTeresaFrames++;
    if (effectState->mTeresaFrames > KART_TERESA_MAX_FRAMES && (kart->field7C & 0x2000)) {
        kart->field7C &= ~0x2000;
        kart->field7C &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            dptc_showAll(dptc_getControllerForDriver(kart->mIndex));
        } else {
            sfx_21090C4(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        sub_210FA40(0, (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
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
    effectState = &kart->field538;
    effectState->mKillerFrames = 0;
    effectState->field20 = 0;
    effectState->mKillerEnding = FALSE;
    SetupKartKillerCursor(&effectState->mKillerCursor, kart->mIndex);
    kart->field4C |= 0x10000000;
    kartCount = gRaceMultiConfig->mKartCount;
    effectState->mKillerEndRank = rstat_getPlace(kart->mIndex) - rankOffsets.field0[kartCount - 1];
    if (effectState->mKillerEndRank <= 0) {
        effectState->mKillerEndRank = 1;
    }
    kart->mKartModelsEntry->fieldA4 = 0;
    if (kart->field7C & 0x2000) {
        kart->field7C &= ~0x2000;
        kart->field7C &= ~0xc000;
        kart->mItemEffect = 0;
        if (!(kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            dptc_showAll(dptc_getControllerForDriver(kart->mIndex));
        } else {
            sfx_21090C4(&kart->mSoundSource, 0xf9, 0x7f, 0);
        }
        sub_210FA40(0, (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 1 : 0);
    }
    if (kart->field4C & 0x8000000) {
        kart->field4C &= ~0x8020000;
        if (kart->field4C & 0x2000) {
            driver_enableSlipStreamToonMode(kart);
        }
        chkrt_applyKartCrsMat(kart->mKartModelsEntry);
    }
    cspl_speedClearSplashes(kart->mIndex);
    if (kart->field4C & 0x40) {
        kart->field4C &= ~0x40;
        driver_disableStarToonMode(kart);
        kart->mItemEffect = 0;
        rptc_stopRainbowEffect(kart->mIndex);
        driver_2068A64(kart, 0, 1);
        if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
            snd_stopStarMusic();
        }
        if (kart->field4C & 0x2000) {
            driver_enableSlipStreamToonMode(kart);
        }
    }
    kart->mItemEffect = 3;
    if (kart->field4C & 0x2000) {
        kart->field4C &= ~0x2000;
        kart->fieldD8 = 0x1000;
        if (!(kart->field4C & 0x8000000)) {
            driver_disableSlipStreamToonMode(kart);
        }
        rptc_stopSlipstreamEffect(kart);
    }
    if (kart->mKartModelsEntry->field58 == 0) {
        effectIds = gKartFollowEffectIds;
        for (i = 0; i < 3; i++) {
            rptc_2081F10(ptcm_createEmitter(effectIds.mEffectIds[i], &kart->mPos), kart->mIndex, 0x14);
        }
    }
    rptc_startKillerEffect(kart->mIndex);
    driver_resetScaleEffects(kart);
    if (kart->field7C & 0x200) {
        kart->field514->field2C ^= 0x100000;
    }
    if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
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

    effectState = &kart->field538;
    effectState->mKillerFrames++;
    if (!(kart->field7C & 0x400)) {
        if (sub_209081C(&effectState->mKillerCursor) != 0) {
            effectStateAgain = &kart->field538;
            if ((kart->field4C & 0x10000000) && effectStateAgain->mKillerEnding == FALSE) {
                effectStateAgain->mKillerEnding = TRUE;
                if (kart->field7C & 0x200) {
                    kart->field514->field2C ^= 0x200000;
                }
            }
        }
    }
    anim_updateAnimator((ModelAnimation *) &kart->mKartModelsEntry->field98);
    if (effectState->mKillerEnding != FALSE) {
        kart->mRadiusFactor -= 0x52;
        if (kart->mRadiusFactor > 0x1000) {
            return;
        }
        kart->field4C &= ~0x10000000;
        sub_210515C(kart->mIndex);
        if (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            cam_resetPlayerCameraTargetFov();
        }
        kart->mRadiusFactor = 0x1000;
        kart->mSurfaceGroup = -1;
        i = 0;
        kart->mItemEffect = 0;
        if (kart->mKartModelsEntry->field58 == 0) {
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
    if (!(kart->field7C & 0x400)) {
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
    if (kart->field7C & 0x200) {
        kart->field514->field2C ^= 0x200000;
    }
}

void driver_startGessoInk(Kart *kart, u32 orthoQuadCount) {
    u32 kartBits;

    if (kart->field7C & 0x400) {
        return;
    }
    if (rstat_hasDriverFinished(kart->mIndex) != 0) {
        return;
    }
    kartBits = kart->field7C;
    if (kartBits & 0x60) {
        return;
    }
    if (kart->field4C & 0x10000040) {
        return;
    }
    if (kartBits & 0x2000) {
        return;
    }
    kart->field538.field1C = 0;
    kart->field4C |= 0x8000000;
    kart->field4C &= ~0x20000;
    if (kart->field4C & 0x2000) {
        driver_disableSlipStreamToonMode(kart);
    }
    chkrt_setTargetColors(kart->mKartModelsEntry, 0, 0x1084, 0);
    if (kart->field7C & KART_7C_MODELS_ENTRY_008_SET) {
        driver_setAnimation(kart, 1, 0);
        driver_setFaceExpression(kart->mKartModelsEntry, 1);
    }
    if (!(kart->field48 & 0x840)) {
        sfx_emitDriverVoice(kart, kart->mSoundIndex, 0);
    }
    cspl_emitGessoSplash(kart->mIndex, orthoQuadCount);
    if (kart->field7C & 0x200) {
        kart->field514->field2C ^= 0x80000;
    }
}

void driver_updateGessoInk(Kart *kart) {
    KartItemEffectState *effectState;
    u32 kartBits;

    kartBits = kart->field4C;
    effectState = &kart->field538;
    if (!(kartBits & 0x40)) {
        if (effectState->field1C == 0x190 && !(kartBits & 0x20000) && (kartBits & 0x8000000) &&
            effectState->field1C <= 0x190) {
            effectState->field1C = 0x190;
            kart->field4C |= 0x20000;
            chkrt_setTargetColors(kart->mKartModelsEntry, chkrt_getKartCrsMatDiffuse(), chkrt_getKartCrsMatEmission(),
                                     chkrt_getKartCrsMatAmbient());
        }
        chkrt_progressColorInterpolation(kart->mKartModelsEntry, (kart->field4C & 0x20000) ? 0x52 : 0x19a);
    }
    effectState->field1C++;
    if (effectState->field1C <= 0x1c2) {
        return;
    }
    if (!(kart->field4C & 0x8000000)) {
        return;
    }
    kart->field4C &= ~0x8020000;
    if (kart->field4C & 0x2000) {
        driver_enableSlipStreamToonMode(kart);
    }
    chkrt_applyKartCrsMat(kart->mKartModelsEntry);
}

void driver_startSlipstream(Kart *kart) {
    KartItemEffectState *effectState;

    effectState = &kart->field538;
    effectState->fieldA = 0;
    effectState->field8 = 0;
    kart->fieldD8 = data_021654dc;
    kart->field4C &= ~0x4000;
    if (!(kart->field4C & 0x2000)) {
        kart->field4C |= 0x2000;
        if (!(kart->field4C & 0x8000000)) {
            driver_enableSlipStreamToonMode(kart);
        }
    }
    if (kart->field4C & 0x48000) {
        rptc_startSlipstreamEffect(kart);
    }
    rptc_stopSlipstreamBeginEffect(kart);
    StopKartSoundWhileRequested(kart);
    if (!(kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        sfx_21090C4(&kart->mSoundSource, 0xa4, 0x7f, 0);
    }
    if (kart->field7C & 0x200) {
        kart->field514->field2C ^= 0x40000;
    }
}

void StructMQRacerEntry_SomeFn_34(Kart *kart) {
    StructMQRacerEntry_SomeFn_35(kart, 1);
    kart->field7C |= 0x800000;
}

s32 StructMQRacerEntry_SomeFn_35(Kart *kart, s32 a) {
    BOOL removed;
    u32 kartBits;
    NNSSndSeqPlayer **seqPlayerHandle;

    removed = FALSE;
    if (a != 0) {
        kartBits = kart->field7C;
        if (!(kartBits & 0x800000)) {
            removed = TRUE;
        }
    } else {
        kartBits = kart->field7C;
        if (!(kartBits & 0x900020)) {
            removed = TRUE;
        }
    }
    if (removed != FALSE) {
        if (!(kartBits & 0x4000000)) {
            DecrementKartAiNonCpuCount(kart->mIndex);
            kart->field7C |= 0x4000000;
        }
        kart->field7C |= 0x20;
        if (kart->mCollisionSlot != -1) {
            kart->mCollisionSlot = col_deleteColEntry(kart->mCollisionSlot);
        }
        if (kart->field2CA != -1) {
            kart->field2CA = col_deleteColEntry(kart->field2CA);
        }
        if (gRaceMultiConfig->mMode == MODE_BATTLE && a == 0) {
            sfx_21090C4(&kart->mSoundSource, 0xd3, 0x7f, 0);
            if (gRaceMultiConfig->mBattleKind == BATTLE_KIND_BALLOON && (data_0217c780 & 1)) {
                seqPlayerHandle = sp_acquireElement(sound_getPoolById(0));
                if (SoundHandle_217D084.fieldC != 0) {
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
        kart->field3C8 = 0;
        driver_reset(kart);
    }
    return removed;
}

BOOL StructMQRacerEntry_HasFlags0x60(Kart *kart) {
    return (kart->field7C & 0x60) != 0;
}
