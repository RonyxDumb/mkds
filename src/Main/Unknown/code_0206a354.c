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

void StartKartState2(Kart *kart, int spinCount, int skipSound) {
    int direction = 1;

    StartKartState(kart, KART_STATE_SPIN);
    if (kart->mUnk_44 & 0xa) {
        if (kart->mTurnDirection == 1) {
            direction = -1;
        }
    } else if (kart->mTurnRatio < 0) {
        direction = -1;
    }
    kart->mYRotationAnglePerFrame = 0x750;
    kart->mYRotationAnglePerFrame = kart->mYRotationAnglePerFrame * direction;
    kart->mYRotationAngle = 0;
    kart->mYRotationAngleSum = 0;
    kart->mYRotationCount = spinCount;
    kart->mUnk_4c |= 0x20;
    StartKartItemInUseOneCountdown(&(gKartItems)[kart->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDropOnKartHit();
    }
    if (skipSound != 0) {
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
        AddMissionRunPendingDropOnKartHit();
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
    Vec3 launchAxis;
    s32 value;
    u16 swingAngle;

    if (kart->mRotationEndFrames == 0) {
        MtxFx33 swingMtx;

        kart->mForwardSpeed = 0;
        if ((kart->mRotationAngleSum > 0 ? kart->mRotationAngleSum : -kart->mRotationAngleSum) < 0x1ffff) {
            kart->mRotationAngle = kart->mRotationAngle - kart->mRotationAnglePerFrame;
            kart->mRotationAngleSum = kart->mRotationAngleSum + kart->mRotationAnglePerFrame;
            value = kart->mRotationAnglePerFrame;
            if (value <= 0xc8) {
                kart->mRotationAnglePerFrame = 0xc8;
            } else {
                kart->mRotationAnglePerFrame = MUL_FIXED12_NO_ROUND(value, 0xf85);
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
        swingAngle = MUL_FIXED12_NO_ROUND(kart->mLaunchAxisSwing, 0xce4);
        MTX_RotAxis33(&swingMtx, &kart->mLaunchForward, FX_SinIdx(swingAngle), FX_CosIdx(swingAngle));
        MTX_MultVec33(&kart->mRotationAxis, &swingMtx, &launchAxis);
        QuaternionFromAxisAngle(&launchAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
    } else {
        Vec4 targetQuaternion;

        targetQuaternion = data_usa_0216556c;
        QuaternionBlend(&kart->mRotationQuaternion, &targetQuaternion, &kart->mRotationQuaternion, 0x266);
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
            value = kart->mRotationEndFrames;
            kart->mUnk_48 |= KART_48_STATE_END_TIMER | KART_48_INPUT_LOCKED;
            kart->mStateEndTimer = value;
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
    BOOL allowed;
    BOOL blocked;
    BOOL hasOtherState;
    int state;
    u32 flags = kart->mUnk_4c;

    if (flags & KART_4C_BLINK_GUARD) {
        allowed = FALSE;
    } else if (kart->mUnk_7c & 0x200) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mUnk_48 & 0x1800) && !(flags & 0x10000040)) {
            allowed = TRUE;
        } else {
            allowed = FALSE;
        }
    } else {
        blocked = TRUE;
        if (!(flags & 0x10000040) && !(kart->mUnk_48 & 0x1800)) {
            state = kart->mState;
            hasOtherState = FALSE;
            if (state != KART_STATE_NORMAL && state != KART_STATE_1 && state != KART_STATE_SPIN) {
                hasOtherState = TRUE;
            }
            if (hasOtherState == FALSE) {
                blocked = FALSE;
            }
        }
        allowed = blocked == FALSE;
    }
    if (!allowed) {
        return FALSE;
    }
    StartKartState3(kart);
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x10;
    }
    return TRUE;
}

void StartKartState3(Kart *kart) {
    Vec3 forward;

    StartKartState(kart, KART_STATE_FLIP);
    kart->mUnk_4c |= 0x10;
    kart->mRotationAngle = 0;
    kart->mRotationAnglePerFrame = 0x666;
    kart->mVerticalSpeedStepCount = 0;
    kart->mRotationEndFrames = 0;
    kart->mRotationAngleSum = 0;
    kart->mForwardSpeed = kart->mForwardSpeed + 0x800;
    GetKartMatrixRow0(kart, &kart->mRotationAxis);
    GetKartForward(kart, &forward);
    VEC_MultAdd(0x2e2, &forward, &kart->mRotationAxis, &kart->mRotationAxis);
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
        AddMissionRunPendingDropOnKartHit();
    }
}

void AdvanceKartState3(Kart *kart) {
    s16 endFrames;

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
    endFrames = kart->mRotationEndFrames;
    if (endFrames == 0) {
        kart->mUnk_48 |= KART_48_STATE_END_TIMER | KART_48_INPUT_LOCKED;
        kart->mStateEndTimer = endFrames;
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
    Vec3 pushDirection;
    Vec3 offset;
    Vec3 cross;
    BOOL allowed;
    BOOL blocked;
    BOOL hasOtherState;
    int state;
    u32 flags = kart->mUnk_4c;

    if (flags & KART_4C_BLINK_GUARD) {
        allowed = FALSE;
    } else if (kart->mUnk_7c & 0x200) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mUnk_48 & 0x1800) && !(flags & 0x10000040)) {
            allowed = TRUE;
        } else {
            allowed = FALSE;
        }
    } else {
        blocked = TRUE;
        if (!(flags & 0x10000040) && !(kart->mUnk_48 & 0x1800)) {
            state = kart->mState;
            hasOtherState = FALSE;
            if (state != KART_STATE_NORMAL && state != KART_STATE_1 && state != KART_STATE_SPIN) {
                hasOtherState = TRUE;
            }
            if (hasOtherState == FALSE) {
                blocked = FALSE;
            }
        }
        allowed = blocked == FALSE;
    }
    if (!allowed) {
        return FALSE;
    }
    pushDirection = mapObject->mMatrix.mRows[0];
    VEC_Subtract(&kart->mPos, &mapObject->mPos, &offset);
    VEC_CrossProduct(&mapObject->mMatrix.mRows[2], &offset, &cross);
    if (VEC_DotProduct(&cross, &mapObject->mMatrix.mRows[1]) < 0) {
        pushDirection.x = -pushDirection.x;
        pushDirection.y = -pushDirection.y;
        pushDirection.z = -pushDirection.z;
    }
    StartKartState4(kart, &pushDirection, 0);
    return TRUE;
}

void StartKartState4(Kart *kart, const Vec3 *pushDirection, s32 record) {
    Vec3 unitY;
    s32 dot;
    s32 pushX;
    s32 pushY;
    s32 pushZ;

    StartKartState(kart, KART_STATE_PUSH_FLIP);
    kart->mUnk_4c |= 0x10;
    kart->mRotationAngle = 0;
    kart->mRotationAngleSum = 0;
    kart->mRotationAnglePerFrame = data_usa_021654d4;
    kart->mVerticalSpeedStepCount = 0;
    kart->mRotationEndFrames = 0;
    unitY = gKartVec3UnitY;
    Vec3CrossUnrounded(&unitY, pushDirection, &kart->mRotationAxis);
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDropOnKartHit();
    }
    if (!(kart->mUnk_7c & 0x400)) {
        pushX = MUL_FIXED12_NO_ROUND(pushDirection->x, 0x1b33);
        pushY = MUL_FIXED12_NO_ROUND(pushDirection->y, 0x1b33);
        pushZ = MUL_FIXED12_NO_ROUND(pushDirection->z, 0x1b33);
        kart->mHitVelocity.x += pushX;
        kart->mHitVelocity.z += pushZ;
        kart->mVerticalSpeed += pushY;
        dot = Vec3DotUnrounded(&kart->mTurnedForward, pushDirection);
        if (dot <= 0) {
            kart->mForwardSpeed = 0;
        } else {
            kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, dot) >> 2;
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
    if (record == 0) {
        return;
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x20;
    }
    if (kart->mUnk_7c & 0x200) {
        kart->mParticipantRecordData->mPushDirection = *pushDirection;
        kart->mParticipantRecordData->mStartedStateKind = 4;
    }
}

void AdvanceKartState4(Kart *kart) {
    s16 endFrames;

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
    endFrames = kart->mRotationEndFrames;
    if (endFrames == 0) {
        kart->mUnk_48 |= KART_48_STATE_END_TIMER | KART_48_INPUT_LOCKED;
        kart->mStateEndTimer = endFrames;
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

s32 StartKartState5(Kart *kart, const Vec3 *pushDirection, s32 record) {
    Vec3 flatDirection;
    Vec3 unitY;
    s32 value;
    s32 pushX;
    s32 pushY;
    s32 pushZ;

    StartKartState(kart, KART_STATE_PUSH_DOUBLE_FLIP);
    flatDirection = *pushDirection;
    flatDirection.y = 0;
    if (LENGTH_SQUARED(flatDirection) >= 16) {
        value = Vec3NormalizeAndGetLengthUnchecked(&flatDirection, &flatDirection);
    } else {
        value = 0;
    }
    if (value == 0) {
        flatDirection = data_02154f88;
    }
    kart->mUnk_4c |= 0x10;
    kart->mRotationAngle = 0;
    kart->mRotationAngleSum = 0;
    kart->mRotationAnglePerFrame = data_usa_021654e0;
    kart->mVerticalSpeedStepCount = 0;
    kart->mRotationEndFrames = 0;
    unitY = gKartVec3UnitY;
    Vec3CrossUnrounded(&unitY, &flatDirection, &kart->mRotationAxis);
    if (!(kart->mUnk_7c & 0x400)) {
        pushX = ((s64) flatDirection.x << 14) >> 12;
        pushY = ((s64) flatDirection.y << 14) >> 12;
        pushZ = ((s64) flatDirection.z << 14) >> 12;
        kart->mHitVelocity.x += pushX;
        kart->mHitVelocity.z += pushZ;
        kart->mVerticalSpeed += pushY;
        value = Vec3DotUnrounded(&kart->mTurnedForward, &flatDirection);
        if (value <= 0) {
            kart->mForwardSpeed = 0;
        } else {
            kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, value) >> 2;
        }
    }
    QuaternionFromAxisAngle(&kart->mRotationAxis, kart->mRotationAngle, &kart->mRotationQuaternion);
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDropOnKartHit();
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
    if (record != 0) {
        if (kart->mUnk_7c & 0x200) {
            kart->mParticipantRecordData->mEventToggleFlags ^= 0x40;
        }
        if (kart->mUnk_7c & 0x200) {
            kart->mParticipantRecordData->mPushDirection = *pushDirection;
            kart->mParticipantRecordData->mStartedStateKind = 5;
        }
    }
    return 1;
}

void AdvanceKartState5(Kart *kart) {
    s16 endFrames;

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
    endFrames = kart->mRotationEndFrames;
    if (endFrames == 0) {
        kart->mUnk_48 |= KART_48_STATE_END_TIMER | KART_48_INPUT_LOCKED;
        kart->mStateEndTimer = endFrames;
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
    KartItemEffectState *itemEffect = &kart->mItemEffectData;

    if (kart->mUnk_4c & 0x10000040) {
        return;
    }
    if (kart->mUnk_7c & 0x402000) {
        return;
    }
    if (kart->mUnk_48 & 0x10040) {
        return;
    }
    itemEffect->mThunderShrinkTimer = data_usa_02154a54[GetKartRank(kart->mIndex) - 1];
    itemEffect->mThunderShrinkFrameIndex = 0;
    kart->mShrinkFactor = 0xb33;
    kart->mUnk_4c |= KART_4C_THUNDER_SHRINK;
    TrySpinKart(kart, 2, 1);
    RequestThunderShrinkSound(kart);
    StartKartItemObjectCountdowns(&(gKartItems)[kart->mIndex]);
    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
        AddMissionRunPendingDropOnKartHit();
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
    KartItemEffectState *itemEffect = &kart->mItemEffectData;

    if (itemEffect->mThunderShrinkTimer <= 0) {
        if (itemEffect->mThunderShrinkFrameIndex == 0) {
            StartSound(&kart->mSoundSource, 0xed, 0x7f, 0);
        }
        itemEffect->mThunderShrinkFrameIndex = itemEffect->mThunderShrinkFrameIndex + 1;
        if (itemEffect->mThunderShrinkFrameIndex >= 0x19) {
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
            if (itemEffect->mThunderShrinkFrameIndex > 0x19) {
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
        kart->mScaleFactor.x = gKartScaleFactorXTable[itemEffect->mThunderShrinkFrameIndex];
        kart->mScaleFactor.y = gKartScaleFactorYTable[itemEffect->mThunderShrinkFrameIndex];
        kart->mScaleFactor.z = gKartScaleFactorZTable[itemEffect->mThunderShrinkFrameIndex];
        kart->mScaleBase.x = 0x1000;
        kart->mScaleBase.y = 0x1000;
        kart->mScaleBase.z = 0x1000;
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
        return;
    }
    itemEffect->mThunderShrinkTimer = itemEffect->mThunderShrinkTimer - 1;
    if (kart->mScaleBase.y > 0x800) {
        s32 scale = kart->mScaleBase.y;

        if (scale < 0x800) {
            scale += 0x29;
            if (scale > 0x800) {
                scale = 0x800;
            }
        } else {
            scale -= 0x29;
            if (scale <= 0x800) {
                scale = 0x800;
            }
        }
        kart->mScaleBase.y = scale;
        kart->mScaleBase.z = kart->mScaleBase.y;
        kart->mScaleBase.x = kart->mScaleBase.z;
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
    }
    KartThunderShrinkNop();
}
