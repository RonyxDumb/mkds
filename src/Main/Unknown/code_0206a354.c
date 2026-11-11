#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "01/code_0218155c.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02063b50.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210a644.h"
#include "Main/Unknown/code_0210a664.h"
#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/code_0210fa3c.h"
#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020681f0.h"

void StartKartState2(Kart *kart, int a, int b) {
    int d = 1;

    StartKartState(kart, KART_STATE_SPIN);
    if (kart->mUnk_44 & 0xa) {
        if (kart->mTurnDirection == 1) {
            d = -1;
        }
    } else if (kart->mTurnRatio < 0) {
        d = -1;
    }
    kart->mYRotationAnglePerFrame = 0x750;
    kart->mYRotationAnglePerFrame = kart->mYRotationAnglePerFrame * d;
    kart->mYRotationAngle = 0;
    kart->mYRotationAngleSum = 0;
    kart->mYRotationCount = a;
    kart->mUnk_4c |= 0x20;
    StartKartItemInUseOneCountdown(&(gKartItems)[kart->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
    if (b != 0) {
        return;
    }
    if (kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT)) {
        return;
    }
    StartKartSeqArcSound(kart, kart->mSoundIndex, 1);
}

void AdvanceKartState1And2(Kart *kart) {
    if (kart->mUnk_4c & 0x20) {
        return;
    }
    kart->mUnk_48 |= KART_48_STATE_END_TIMER | KART_48_INPUT_LOCKED;
    kart->mStateEndTimer = 0xa;
    kart->mState = KART_STATE_NORMAL;
    kart->mUnk_4c &= ~0x30;
    kart->mUnk_48 &= ~0x20000;
    SetKartCharacterAnimation(kart, 0, 1);
    kart->mUnk_44 |= 0x80000000;
    if ((kart->mUnk_7c & 0x2) && gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(kart->mAi);
    }
}

BOOL TryStartKartState6(Kart *kart) {
    if (!TryStartKartState(kart, KART_STATE_LAUNCH_DOUBLE_FLIP)) {
        return FALSE;
    }
    StartKartState6(kart);
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x20000;
    }
    return TRUE;
}

void StartKartState6(Kart *kart) {
    kart->mForwardSpeed = 0;
    kart->mTurnAngle = 0;
    kart->mUnk_48 &= 0xdfe77fdf;
    kart->mBoostTimer = 0;
    kart->mItemEffectData.mKinokoBoostTimer = 0;
    kart->mMiniTurboTimer = 0;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(kart->mUnk_4c & 0x10000000) && !(kart->mUnk_48 & 0x4000000)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    if (kart->mUnk_4c & KART_4C_AHEAD_BOOST) {
        kart->mUnk_4c &= ~KART_4C_AHEAD_BOOST;
        kart->mAheadSpeedLimitFactor = 0x1000;
        if (!(kart->mUnk_4c & 0x8000000)) {
            ResetKartModelsCourseColors(kart);
        }
        StopKartNearRankEffect(kart);
    }
    kart->mState = KART_STATE_LAUNCH_DOUBLE_FLIP;
    kart->mUnk_4c |= 0x10;
    kart->mVerticalSpeed = 0x6000;
    kart->mRotationAngleSum = 0;
    kart->mRotationAngle = 0;
    kart->mRotationAnglePerFrame = 0xfa0;
    kart->mRotationEndFrames = 0;
    GetKartMatrixRow0(kart, &kart->mRotationAxis);
    GetKartForward(kart, &kart->mLaunchForward);
    kart->mLaunchAxisSwing = 0;
    kart->mLaunchAxisSwingAngle = 0;
    kart->mLaunchAxisSwingAngleSum = 0;
    kart->mUnk_344 = 0;
    kart->mLaunchStartY = kart->mPos.y;
    kart->mLaunchFrames = 0;
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
    if (!(kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT))) {
        StartKartSeqArcSound(kart, kart->mSoundIndex, 2);
    }
    kart->mUnk_4c &= ~0x80000000;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetCameraHeightHold(1);
    }
}

void AdvanceKartState6(Kart *kart) {
    Vec3 a;
    s32 c;
    u16 i;

    if (kart->mRotationEndFrames == 0) {
        MtxFx33 m;

        kart->mForwardSpeed = 0;
        if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) < 0x1ffff) {
            kart->mRotationAngle = kart->mRotationAngle - kart->mRotationAnglePerFrame;
            kart->mRotationAngleSum = kart->mRotationAngleSum + kart->mRotationAnglePerFrame;
            c = kart->mRotationAnglePerFrame;
            if (c <= 0xc8) {
                kart->mRotationAnglePerFrame = 0xc8;
            } else {
                kart->mRotationAnglePerFrame = MUL_FIXED12_NO_ROUND(c, 0xf85);
            }
        } else {
            kart->mRotationAngle = 0;
        }
        if (kart->mUnk_44 & KART_44_LANDED) {
            if (kart->mRotationAngleSum < 0x13000) {
                kart->mVerticalSpeed += 0x1800;
            }
        }
        if ((kart->mLaunchAxisSwingAngleSum > 0 ? kart->mLaunchAxisSwingAngleSum : -kart->mLaunchAxisSwingAngleSum) >=
            0xffff) {
            kart->mLaunchAxisSwingAngle = 0;
            kart->mLaunchAxisSwing = 0;
        } else {
            kart->mLaunchAxisSwingAngle += 0x3e8;
            kart->mLaunchAxisSwingAngleSum += 0x3e8;
            kart->mLaunchAxisSwing = FX_SinIdx(kart->mLaunchAxisSwingAngle);
        }
        i = MUL_FIXED12_NO_ROUND(kart->mLaunchAxisSwing, 0xce4);
        MTX_RotAxis33(&m, &kart->mLaunchForward, FX_SinIdx(i), FX_CosIdx(i));
        MTX_MultVec33(&kart->mRotationAxis, &m, &a);
        QuaternionFromAxisAngle(&a, kart->mRotationAngle, &kart->mRotationQuaternion);
    } else {
        Vec4 q;

        q = data_usa_0216556c;
        QuaternionBlend(&kart->mRotationQuaternion, &q, &kart->mRotationQuaternion, 0x266);
    }
    QuaternionNormalize(&kart->mRotationQuaternion, &kart->mRotationQuaternion);
    if (!(kart->mUnk_4c & 0x80000000)) {
        if ((u32) kart->mLaunchFrames > 2 &&
            (kart->mLaunchStartY >= kart->mPos.y || (kart->mUnk_44 & KART_44_ON_GROUND))) {
            if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                SetCameraHeightHold(0);
            }
            if (kart->mRotationEndFrames != 0) {
                return;
            }
            kart->mCollisionStepFrames = 0x46;
            c = kart->mRotationEndFrames;
            kart->mUnk_48 |= KART_48_STATE_END_TIMER | KART_48_INPUT_LOCKED;
            kart->mStateEndTimer = c;
            kart->mUnk_4c |= 0x80000000;
            return;
        }
        kart->mLaunchFrames = kart->mLaunchFrames + 1;
        return;
    }
    kart->mRotationEndFrames++;
    if (kart->mRotationEndFrames < 0x1e) {
        return;
    }
    kart->mState = KART_STATE_NORMAL;
    kart->mUnk_4c &= ~0x30;
    kart->mUnk_48 &= ~0x20000;
    SetKartCharacterAnimation(kart, 0, 1);
    kart->mUnk_44 |= 0x80000000;
    if ((kart->mUnk_7c & 0x2) && gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(kart->mAi);
    }
    kart->mUnk_4c &= ~0x80000010;
    if (kart->mUnk_44 & KART_44_ON_GROUND) {
        kart->mTurnAngle = 0;
    }
}

BOOL TryStartKartState3(Kart *kart) {
    BOOL v1;
    BOOL v2;
    BOOL c;
    int v;
    u32 f = kart->mUnk_4c;

    if (f & KART_4C_BLINK_GUARD) {
        v1 = FALSE;
    } else if (kart->mUnk_7c & 0x200) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mUnk_48 & 0x1800) && !(f & 0x10000040)) {
            v1 = TRUE;
        } else {
            v1 = FALSE;
        }
    } else {
        v2 = TRUE;
        if (!(f & 0x10000040) && !(kart->mUnk_48 & 0x1800)) {
            v = kart->mState;
            c = FALSE;
            if (v != KART_STATE_NORMAL && v != KART_STATE_1 && v != KART_STATE_SPIN) {
                c = TRUE;
            }
            if (c == FALSE) {
                v2 = FALSE;
            }
        }
        v1 = v2 == FALSE;
    }
    if (!v1) {
        return FALSE;
    }
    StartKartState3(kart);
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x10;
    }
    return TRUE;
}

void StartKartState3(Kart *kart) {
    Vec3 v;

    StartKartState(kart, KART_STATE_FLIP);
    kart->mUnk_4c |= 0x10;
    kart->mRotationAngle = 0;
    kart->mRotationAnglePerFrame = 0x666;
    kart->mVerticalSpeedStepCount = 0;
    kart->mRotationEndFrames = 0;
    kart->mRotationAngleSum = 0;
    kart->mForwardSpeed = kart->mForwardSpeed + 0x800;
    GetKartMatrixRow0(kart, &kart->mRotationAxis);
    GetKartForward(kart, &v);
    VEC_MultAdd(0x2e2, &v, &kart->mRotationAxis, &kart->mRotationAxis);
    Vec3NormalizeAndGetLengthUnchecked(&kart->mRotationAxis, &kart->mRotationAxis);
    QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
    kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, 0x99a);
    if (kart->mKartModelsEntry->mKartModelHidden == 0) {
        StartEffect(0xc, &kart->mPos);
        StartEffect(0xd, &kart->mPos);
        StartEffect(0xe, &kart->mPos);
    }
    if (!(kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT))) {
        StartKartSeqArcSound(kart, kart->mSoundIndex, 2);
    }
    StartKartItemInUseOneCountdown(&(gKartItems)[kart->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
}

void AdvanceKartState3(Kart *kart) {
    s16 n;

    if (kart->mRotationAngleSum == 0) {
        kart->mVerticalSpeed = data_usa_021654e8;
    } else if (kart->mUnk_44 & 0x10000) {
        switch (kart->mVerticalSpeedStepCount) {
            case 0:
                kart->mVerticalSpeed = data_usa_021654f0;
                break;
            case 1:
                kart->mVerticalSpeed = data_usa_02165508;
                break;
        }
        kart->mVerticalSpeedStepCount++;
    }
    if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) <= 0xffff) {
        kart->mRotationAngleSum = kart->mRotationAngleSum + kart->mRotationAnglePerFrame;
        if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) > 0xffff) {
            kart->mRotationAngle = 0;
        } else {
            kart->mRotationAngle = kart->mRotationAngle + kart->mRotationAnglePerFrame;
        }
        kart->mRotationAnglePerFrame = kart->mRotationAnglePerFrame - 0xa;
        QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
        QuaternionNormalize(&kart->mRotationQuaternion, &kart->mRotationQuaternion);
        return;
    }
    n = kart->mRotationEndFrames;
    if (n == 0) {
        kart->mUnk_48 |= KART_48_STATE_END_TIMER | KART_48_INPUT_LOCKED;
        kart->mStateEndTimer = n;
        kart->mUnk_4c &= ~0x10;
    }
    kart->mRotationEndFrames++;
    if (kart->mRotationEndFrames < data_usa_021654c4) {
        return;
    }
    kart->mState = KART_STATE_NORMAL;
    kart->mUnk_4c &= ~0x30;
    kart->mUnk_48 &= ~0x20000;
    SetKartCharacterAnimation(kart, 0, 1);
    kart->mUnk_44 |= 0x80000000;
    if ((kart->mUnk_7c & 0x2) && gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(kart->mAi);
    }
}

BOOL TryStartKartState4(Kart *kart, MapObject *mapObject) {
    Vec3 t;
    Vec3 u;
    Vec3 w;
    BOOL v1;
    BOOL v2;
    BOOL c;
    int v;
    u32 f = kart->mUnk_4c;

    if (f & KART_4C_BLINK_GUARD) {
        v1 = FALSE;
    } else if (kart->mUnk_7c & 0x200) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mUnk_48 & 0x1800) && !(f & 0x10000040)) {
            v1 = TRUE;
        } else {
            v1 = FALSE;
        }
    } else {
        v2 = TRUE;
        if (!(f & 0x10000040) && !(kart->mUnk_48 & 0x1800)) {
            v = kart->mState;
            c = FALSE;
            if (v != KART_STATE_NORMAL && v != KART_STATE_1 && v != KART_STATE_SPIN) {
                c = TRUE;
            }
            if (c == FALSE) {
                v2 = FALSE;
            }
        }
        v1 = v2 == FALSE;
    }
    if (!v1) {
        return FALSE;
    }
    t = mapObject->mMatrix.mRows[0];
    VEC_Subtract(&kart->mPos, &mapObject->mPos, &u);
    VEC_CrossProduct(&mapObject->mMatrix.mRows[2], &u, &w);
    if (VEC_DotProduct(&w, &mapObject->mMatrix.mRows[1]) < 0) {
        t.x = -t.x;
        t.y = -t.y;
        t.z = -t.z;
    }
    StartKartState4(kart, &t, 0);
    return TRUE;
}

void StartKartState4(Kart *kart, const Vec3 *a, s32 b) {
    Vec3 v;
    s32 r;
    s32 x;
    s32 y;
    s32 z;

    StartKartState(kart, KART_STATE_PUSH_FLIP);
    kart->mUnk_4c |= 0x10;
    kart->mRotationAngle = 0;
    kart->mRotationAngleSum = 0;
    kart->mRotationAnglePerFrame = data_usa_021654d4;
    kart->mVerticalSpeedStepCount = 0;
    kart->mRotationEndFrames = 0;
    v = data_02154f7c;
    Vec3CrossUnrounded(&v, a, &kart->mRotationAxis);
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
    if (!(kart->mUnk_7c & 0x400)) {
        x = MUL_FIXED12_NO_ROUND(a->x, 0x1b33);
        y = MUL_FIXED12_NO_ROUND(a->y, 0x1b33);
        z = MUL_FIXED12_NO_ROUND(a->z, 0x1b33);
        kart->mHitVelocity.x += x;
        kart->mHitVelocity.z += z;
        kart->mVerticalSpeed += y;
        r = Vec3DotUnrounded(&kart->mTurnedForward, a);
        if (r <= 0) {
            kart->mForwardSpeed = 0;
        } else {
            kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, r) >> 2;
        }
    }
    QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
    if (kart->mKartModelsEntry->mKartModelHidden == 0) {
        StartEffect(0xc, &kart->mPos);
        StartEffect(0xd, &kart->mPos);
        StartEffect(0xe, &kart->mPos);
    }
    kart->mUnk_4c |= 0x1;
    if (!(kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT))) {
        StartKartSeqArcSound(kart, kart->mSoundIndex, 2);
    }
    if (b == 0) {
        return;
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x20;
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mPushDirection = *a;
        kart->mParticipantRecordData->mStartedStateKind = 4;
    }
}

void AdvanceKartState4(Kart *kart) {
    s16 n;

    if (kart->mRotationAngleSum == 0) {
        kart->mVerticalSpeed = data_usa_0216550c;
    }
    if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) <= 0xffff) {
        kart->mRotationAngleSum = kart->mRotationAngleSum + kart->mRotationAnglePerFrame;
        if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) > 0xffff) {
            kart->mRotationAngle = 0;
            kart->mUnk_4c &= ~0x1;
        } else {
            kart->mRotationAngle = kart->mRotationAngle + kart->mRotationAnglePerFrame;
        }
        kart->mRotationAnglePerFrame =
            kart->mRotationAnglePerFrame - (kart->mRotationAnglePerFrame > 0 ? data_usa_021654d0 : -data_usa_021654d0);
        QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
        QuaternionNormalize(&kart->mRotationQuaternion, &kart->mRotationQuaternion);
        return;
    }
    n = kart->mRotationEndFrames;
    if (n == 0) {
        kart->mUnk_48 |= KART_48_STATE_END_TIMER | KART_48_INPUT_LOCKED;
        kart->mStateEndTimer = n;
        kart->mUnk_4c &= ~0x10;
    }
    kart->mRotationEndFrames++;
    if (kart->mRotationEndFrames < 0x1e) {
        return;
    }
    kart->mState = KART_STATE_NORMAL;
    kart->mUnk_4c &= ~0x30;
    kart->mUnk_48 &= ~0x20000;
    SetKartCharacterAnimation(kart, 0, 1);
    kart->mUnk_44 |= 0x80000000;
    if ((kart->mUnk_7c & 0x2) && gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(kart->mAi);
    }
    if (kart->mUnk_44 & KART_44_ON_GROUND) {
        kart->mTurnAngle = 0;
    }
}

s32 StartKartState5(Kart *kart, const Vec3 *a, s32 b) {
    Vec3 v;
    Vec3 w;
    s32 r;
    s32 x;
    s32 y;
    s32 z;

    StartKartState(kart, KART_STATE_PUSH_DOUBLE_FLIP);
    v = *a;
    v.y = 0;
    if (LENGTH_SQUARED(v) >= 16) {
        r = Vec3NormalizeAndGetLengthUnchecked(&v, &v);
    } else {
        r = 0;
    }
    if (r == 0) {
        v = data_02154f88;
    }
    kart->mUnk_4c |= 0x10;
    kart->mRotationAngle = 0;
    kart->mRotationAngleSum = 0;
    kart->mRotationAnglePerFrame = data_usa_021654e0;
    kart->mVerticalSpeedStepCount = 0;
    kart->mRotationEndFrames = 0;
    w = data_02154f7c;
    Vec3CrossUnrounded(&w, &v, &kart->mRotationAxis);
    if (!(kart->mUnk_7c & 0x400)) {
        x = ((s64) v.x << 14) >> 12;
        y = ((s64) v.y << 14) >> 12;
        z = ((s64) v.z << 14) >> 12;
        kart->mHitVelocity.x += x;
        kart->mHitVelocity.z += z;
        kart->mVerticalSpeed += y;
        r = Vec3DotUnrounded(&kart->mTurnedForward, &v);
        if (r <= 0) {
            kart->mForwardSpeed = 0;
        } else {
            kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, r) >> 2;
        }
    }
    QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
    if (kart->mKartModelsEntry->mKartModelHidden == 0) {
        StartEffect(0xc, &kart->mPos);
        StartEffect(0xd, &kart->mPos);
        StartEffect(0xe, &kart->mPos);
    }
    if (!(kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT))) {
        StartKartSeqArcSound(kart, kart->mSoundIndex, 2);
    }
    kart->mUnk_4c |= 0x1;
    if (b != 0) {
        if (kart->mUnk_7c & 0x200) {
            kart->mParticipantRecordData->mEventToggleFlags ^= 0x40;
        }
        if (kart->mUnk_7c & 0x200) {
            kart->mParticipantRecordData->mPushDirection = *a;
            kart->mParticipantRecordData->mStartedStateKind = 5;
        }
    }
    return 1;
}

void AdvanceKartState5(Kart *kart) {
    s16 n;

    if (kart->mRotationAngleSum == 0) {
        kart->mVerticalSpeed = data_usa_0216550c;
    } else if (kart->mUnk_44 & KART_44_LANDED) {
        if (kart->mVerticalSpeedStepCount == 0) {
            kart->mVerticalSpeed = data_usa_021654e4;
        }
        kart->mVerticalSpeedStepCount++;
    }
    if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) <= 0x1fffe) {
        kart->mRotationAngleSum = kart->mRotationAngleSum + kart->mRotationAnglePerFrame;
        if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) > 0x1fffe) {
            kart->mRotationAngle = 0;
            kart->mUnk_4c &= ~0x1;
        } else {
            kart->mRotationAngle = kart->mRotationAngle + kart->mRotationAnglePerFrame;
        }
        kart->mRotationAnglePerFrame =
            kart->mRotationAnglePerFrame - (kart->mRotationAnglePerFrame > 0 ? data_usa_021654d0 : -data_usa_021654d0);
        QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
        QuaternionNormalize(&kart->mRotationQuaternion, &kart->mRotationQuaternion);
        return;
    }
    n = kart->mRotationEndFrames;
    if (n == 0) {
        kart->mUnk_48 |= KART_48_STATE_END_TIMER | KART_48_INPUT_LOCKED;
        kart->mStateEndTimer = n;
        kart->mUnk_4c &= ~0x10;
    }
    kart->mRotationEndFrames++;
    if (kart->mRotationEndFrames < 10) {
        return;
    }
    kart->mState = KART_STATE_NORMAL;
    kart->mUnk_4c &= ~0x30;
    kart->mUnk_48 &= ~0x20000;
    SetKartCharacterAnimation(kart, 0, 1);
    kart->mUnk_44 |= 0x80000000;
    if ((kart->mUnk_7c & 0x2) && gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        PickKartAiBalloonCountGoal(kart->mAi);
    }
    if (kart->mUnk_44 & KART_44_ON_GROUND) {
        kart->mTurnAngle = 0;
    }
}

void StartKartThunderShrink(Kart *kart) {
    KartItemEffectState *q = &kart->mItemEffectData;

    if (kart->mUnk_4c & 0x10000040) {
        return;
    }
    if (kart->mUnk_7c & 0x402000) {
        return;
    }
    if (kart->mUnk_48 & 0x10040) {
        return;
    }
    q->mThunderShrinkTimer = data_usa_02154a54[GetKartRank(kart->mIndex) - 1];
    q->mThunderShrinkFrameIndex = 0;
    kart->mShrinkFactor = 0xb33;
    kart->mUnk_4c |= KART_4C_THUNDER_SHRINK;
    TrySpinKart(kart, 2, 1);
    RequestThunderShrinkSound(kart);
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        func_ov001_0218173c();
    }
    kart->mScaleFactor.x = 0x1000;
    kart->mScaleFactor.y = 0x1000;
    kart->mScaleFactor.z = 0x1000;
    SetKartThunderShrinkTrackParamsFunction(kart);
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        SetThunderShrinkSoundFlag(1);
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x8000;
    }
}

void AdvanceKartThunderShrink(Kart *kart) {
    KartItemEffectState *q = &kart->mItemEffectData;

    if (q->mThunderShrinkTimer <= 0) {
        if (q->mThunderShrinkFrameIndex == 0) {
            StartSound(&kart->mSoundSource, 0xed, 0x7f, 0);
        }
        q->mThunderShrinkFrameIndex = q->mThunderShrinkFrameIndex + 1;
        if (q->mThunderShrinkFrameIndex >= 0x19) {
            kart->mScaleBase.x = 0x1000;
            kart->mScaleBase.y = 0x1000;
            kart->mScaleBase.z = 0x1000;
            kart->mScaleFactor.x = 0x1000;
            kart->mScaleFactor.y = 0x1000;
            kart->mScaleFactor.z = 0x1000;
            kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
            kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
            kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
            kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
            if (q->mThunderShrinkFrameIndex > 0x19) {
                kart->mUnk_4c &= ~KART_4C_THUNDER_SHRINK;
                if (!(kart->mUnk_4c & 0x10080)) {
                    kart->mShrinkFactor = 0x1000;
                }
                if (kart->mIndex == gRaceSetup->mEntryIndex) {
                    SetThunderShrinkSoundFlag(0);
                }
                ResetKartTrackParamsFunction(kart);
                return;
            }
            kart->mUnk_4c |= 0x100;
            return;
        }
        kart->mUnk_4c |= 0x100;
        kart->mScaleFactor.x = gKartScaleFactorXTable[q->mThunderShrinkFrameIndex];
        kart->mScaleFactor.y = gKartScaleFactorYTable[q->mThunderShrinkFrameIndex];
        kart->mScaleFactor.z = gKartScaleFactorZTable[q->mThunderShrinkFrameIndex];
        kart->mScaleBase.x = 0x1000;
        kart->mScaleBase.y = 0x1000;
        kart->mScaleBase.z = 0x1000;
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
        return;
    }
    q->mThunderShrinkTimer = q->mThunderShrinkTimer - 1;
    if (kart->mScaleBase.y > 0x800) {
        s32 v = kart->mScaleBase.y;

        if (v < 0x800) {
            v += 0x29;
            if (v > 0x800) {
                v = 0x800;
            }
        } else {
            v -= 0x29;
            if (v <= 0x800) {
                v = 0x800;
            }
        }
        kart->mScaleBase.y = v;
        kart->mScaleBase.z = kart->mScaleBase.y;
        kart->mScaleBase.x = kart->mScaleBase.z;
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
    }
    KartThunderShrinkNop();
}
