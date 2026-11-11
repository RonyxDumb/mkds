#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020646f0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02075000.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/code_02040de0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0208c4e8.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_020a1e40.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210ab30.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210fb10.h"
#include "Main/Unknown/code_0210fb54.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_021112fc.h"
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
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0203c5f8.h"

void AdvanceKartRemovalShrink(Kart *kart) {
    u32 kartBits;
    s32 value;
    BOOL winnerDecidedAndEndReached;
    vu32 *bitsPointer;
    u32 currentBits;
    vu32 *bitsPointerAgain;
    s32 scaleIndex;
    Vec3 *collisionCenter;

    kartBits = kart->mEntryFlags;
    if ((kartBits & KART_ENTRY_HIDDEN) != 0) {
        if ((kartBits & KART_ENTRY_BATTLE_REMOVAL) == 0) {
            return;
        }
        if ((kartBits & KART_ENTRY_REMOVED_BY_PROGRESS) != 0) {
            return;
        }
    }
    value = kart->mFramesSinceRemovalOrReset;
    if (value >= 0x19 || (kartBits & KART_ENTRY_GHOST) != 0) {
        winnerDecidedAndEndReached = FALSE;
        if (gRaceSetup->mMode == MODE_BATTLE) {
            if (IsWinnerDecidedAndEndReached() != 0) {
                winnerDecidedAndEndReached = TRUE;
            }
        }
        kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_HIDDEN;
        bitsPointer = &kart->mEntryFlags;
        currentBits = *bitsPointer;
        if ((currentBits & 0x800006) == 0 && winnerDecidedAndEndReached == FALSE && (currentBits & 0x40000) != 0) {
            if (kart->mFramesSinceRemovalOrReset >= 0xb9) {
                *bitsPointer = *bitsPointer | KART_ENTRY_BATTLE_RESPAWNED;
                CallKartSlot6AndToggleFlag(kart);
                collisionCenter = gRaceSetup->mMode == MODE_WIFI ? &kart->mPointAlongUp : &kart->mCollisionCenter;
                if (kart->mCollisionSlot == -1) {
                    kart->mCollisionSlot =
                        CreateCollisionSlot(collisionCenter, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
                }
                if (kart->mSecondCollisionSlot == -1) {
                    value = kart->mPhysicalParam->mRadius;
                    kart->mSecondCollisionSlot =
                        CreateCollisionSlot(&kart->mSecondCollisionCenter, (s64) value << 15 >> 12, 0x800, kart);
                }
                bitsPointerAgain = &kart->mEntryFlags;
                kart->mEntryFlags =
                    kart->mEntryFlags & ~(KART_ENTRY_REMOVED | KART_ENTRY_HIDDEN | KART_ENTRY_OUT_OF_ROUND);
                kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_PARKED;
                if ((kart->mEntryFlags & KART_ENTRY_SELECTED) == 0) {
                    *bitsPointerAgain = *bitsPointerAgain | KART_ENTRY_NOT_DRAWN_PARKED;
                }
                if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
                    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_TRANSLUCENT;
                } else {
                    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_NOT_DRAWN;
                }
                ReleaseEliminatedKartItems(kart->mIndex);
                if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
                    StartKartRemovalSeqEffect();
                }
                SetKartStartSeqNop(kart);
                return;
            }
            if ((currentBits & 1) != 0) {
                value = kart->mFramesSinceRemovalOrReset;
                if (value == 0x70) {
                    SetDispCapFadeFlag();
                } else if (value == 0x73) {
                    StartDispCapFadeToFaded(0x3c);
                    FadeSeqVolumeToZeroAfterKartRemoval();
                }
            }
            kart->mFramesSinceRemovalOrReset = kart->mFramesSinceRemovalOrReset + 1;
            return;
        }
        kart->mPos.x = 0x1000000;
        kart->mPos.y = 0xff000000;
        kart->mPos.z = 0x1000000;
        kart->mScale = gKartVec3Zero;
    } else {
        scaleIndex = 0x18 - value;
        kart->mScaleFactor.x = gKartScaleFactorXTable[scaleIndex];
        kart->mScaleFactor.y = gKartScaleFactorYTable[scaleIndex];
        kart->mScaleFactor.z = gKartScaleFactorZTable[scaleIndex];
        kart->mScale.x = MUL_FIXED12_NO_ROUND(kart->mScaleBase.x, kart->mScaleFactor.x);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleBase.y, kart->mScaleFactor.y);
        kart->mScale.z = MUL_FIXED12_NO_ROUND(kart->mScaleBase.z, kart->mScaleFactor.z);
        kart->mScale.y = MUL_FIXED12_NO_ROUND(kart->mScaleYFactor, kart->mScale.y);
        kart->mFramesSinceRemovalOrReset = kart->mFramesSinceRemovalOrReset + 1;
    }
}

void StartBattleKartRemoval(Kart *kart) {
    if ((kart->mEntryFlags & KART_ENTRY_BATTLE_REMOVAL) != 0) {
        return;
    }
    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_BATTLE_REMOVAL;
    StartKartRemoval(kart, 0);
}

void SetKartCharacterAnimation(Kart *kart, s32 animationIndex, s32 useBlend) {
    u32 kartBits;
    u32 currentBits;
    KartModelsEntry *modelsEntry;
    BOOL faceFrame;
    BOOL changeAnimation;
    CharacterAnimationState *animationState;
    s32 currentAnimation;

    kartBits = kart->mEntryFlags;
    if ((kartBits & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0) {
        modelsEntry = kart->mKartModelsEntry;
        faceFrame = FALSE;
        animationState = &modelsEntry->mAnimationState;
        currentAnimation = modelsEntry->mCharacterAnimation->mCurrentIndex;
        changeAnimation = TRUE;
        if (animationState->mNextAnimationPending != 0) {
            if (currentAnimation != 0) {
                SetModelAnimationEntryLoopMode(modelsEntry->mCharacterAnimation, (u16) currentAnimation, 1);
            }
            animationState->mNextAnimationPending = 0;
        }
        if (animationIndex == 1) {
            animationIndex = 1;
            faceFrame = TRUE;
        } else {
            currentBits = kart->mEntryFlags;
            if ((currentBits & KART_ENTRY_RESULT_WON) != 0) {
                if (currentAnimation == animationIndex) {
                    changeAnimation = FALSE;
                }
                animationIndex = 2;
            } else if ((currentBits & KART_ENTRY_RESULT_LOST) != 0) {
                if (currentAnimation == animationIndex) {
                    changeAnimation = FALSE;
                }
                animationIndex = 3;
                faceFrame = TRUE;
            }
        }
        if (changeAnimation != FALSE) {
            SetCharacterAnimation(kart->mKartModelsEntry, animationIndex, useBlend);
        }
        SetCharacterFaceFrameIndex(kart->mKartModelsEntry, faceFrame);
    } else {
        faceFrame = FALSE;
        if (animationIndex == 1 || (kartBits & KART_ENTRY_RESULT_LOST) != 0) {
            faceFrame = TRUE;
        }
        SetCharacterFaceFrameIndex(kart->mKartModelsEntry, faceFrame);
    }
}

// Animation, face frame and voice of a kart that was robbed of its item or hit by an object.
void StartKartHitReaction(Kart *kart) {
    if ((kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0) {
        StartKartCharacterAnimationOnce(kart, 1, 0);
        SetCharacterFaceFrameIndex(kart->mKartModelsEntry, 1);
    }
    if ((kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT)) != 0) {
        return;
    }
    StartKartSeqArcSound(kart, kart->mSoundIndex, 0);
}

void QueueKartOwnSoundIndex(Kart *kart) {
    QueueKartSound(kart, kart->mSoundIndex);
}

void FinishKartAtMissionRunEnd(Kart *kart) {
    s32 endKind;
    u32 kartBits;
    u32 finishResult;

    if ((kart->mEntryFlags & KART_ENTRY_MISSION_END_DONE) != 0) {
        return;
    }
    kart->mEntryFlags = kart->mEntryFlags | (KART_ENTRY_ENDED | KART_ENTRY_MISSION_END_DONE);
    kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_SLOWING_STOP;
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0) {
            endKind = gRaceProgress->mEntryEndKind;
        } else {
            endKind = 6;
        }
        switch (endKind) {
            case 0:
                StartEntryCameraKind8Entry();
                ResetKartAtRaceEnd(kart, 1, 1);
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            default:
                if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
                    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                        EliminateKartAndCheckWinner(kart->mIndex);
                    }
                    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_RESULT_LOST;
                    SetKartCharacterAnimation(kart, 3, 1);
                }
                break;
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            EliminateKartsUntilWinnerDecided();
        }
    }
    kartBits = kart->mEntryFlags;
    if ((kartBits & KART_ENTRY_SELECTED) == 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE || gRaceSetup->mMode == MODE_MISSION_RUN) {
        finishResult = 1;
        if ((kartBits & KART_ENTRY_RESULT_WON) != 0) {
            finishResult = 0;
        } else if ((kartBits & KART_ENTRY_RESULT_LOST) != 0) {
            finishResult = 2;
        }
        SetEntryKartFinishResult(finishResult);
    }
}

void FinishKartAtBattleEnd(Kart *kart, s32 isWinner) {
    Vec3 startPos;
    Vec3 forward;
    Vec3 startAngles;
    Vec3 *collisionCenter;
    s32 radius;
    u32 kartBits;
    u32 finishResult;
    vu32 *bitsPointer;

    if ((kart->mEntryFlags & KART_ENTRY_BATTLE_END_DONE) != 0) {
        return;
    }
    ReleaseItemsAtFinish();
    if (isWinner != 0) {
        kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_WINNER;
    }
    kart->mEntryFlags = kart->mEntryFlags | (KART_ENTRY_BATTLE_END_MARK | KART_ENTRY_BATTLE_END_DONE);
    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_ENDED;
    kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_SLOWING_STOP;
    kart->mEntryFlags =
        kart->mEntryFlags & ~(KART_ENTRY_TERESA | KART_ENTRY_TRANSLUCENT | KART_ENTRY_NOT_DRAWN | KART_ENTRY_PARKED);
    if ((kart->mEntryFlags & KART_ENTRY_REMOVED) != 0) {
        GetCourseMapKartStartPlacement(&startPos, &startAngles, kart->mIndex);
        kart->mHeadingAngle = (u32) (startAngles.y * 0xb6) >> 12;
        QuaternionFromAxisAngle(&gKartVec3UnitY, kart->mHeadingAngle, &kart->mUnk_e0_m);
        Matrix4x3FromQuaternion(&kart->mUnk_120_m, &kart->mUnk_e0_m);
        GetKartForward(kart, &forward);
        ResetKartAndSetPos(kart, &startPos, &forward, NULL);
        collisionCenter = gRaceSetup->mMode == MODE_WIFI ? &kart->mPointAlongUp : &kart->mCollisionCenter;
        if (kart->mCollisionSlot == -1) {
            kart->mCollisionSlot =
                CreateCollisionSlot(collisionCenter, kart->mPhysicalParam->mRadius + 0xd000, 0x8000, kart);
        }
        if (kart->mSecondCollisionSlot == -1) {
            radius = kart->mPhysicalParam->mRadius;
            kart->mSecondCollisionSlot =
                CreateCollisionSlot(&kart->mSecondCollisionCenter, (s64) radius << 15 >> 12, 0x800, kart);
        }
        kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_SCALING_IN;
        kart->mEntryFlags = kart->mEntryFlags & ~(KART_ENTRY_REMOVED | KART_ENTRY_HIDDEN);
        kart->mScale = gKartVec3Zero;
    }
    bitsPointer = &kart->mEntryFlags;
    kart->mEntryFlags = kart->mEntryFlags & ~KART_ENTRY_SCALING_IN;
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) == 0) {
        *bitsPointer = *bitsPointer | KART_ENTRY_HIDDEN;
    } else {
        StartEntryCameraKind6Entry();
    }
    ResetKartAtRaceEnd(kart, 0, isWinner);
    kartBits = kart->mEntryFlags;
    if ((kartBits & KART_ENTRY_SELECTED) != 0) {
        if (gRaceSetup->mMode == MODE_BATTLE || gRaceSetup->mMode == MODE_MISSION_RUN) {
            finishResult = 1;
            if ((kartBits & KART_ENTRY_RESULT_WON) != 0) {
                finishResult = 0;
            } else if ((kartBits & KART_ENTRY_RESULT_LOST) != 0) {
                finishResult = 2;
            }
            SetEntryKartFinishResult(finishResult);
        }
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) == 0) {
        return;
    }
    StartBattleWinOrLoseSound(kart->mSoundIndex, isWinner);
}

void ResetKartAtRaceEnd(Kart *kart, s32 useCourseMapRecord, s32 isWinner) {
    KartRaceEndPlacement placement;
    s32 savedForwardSpeed;
    BOOL hasCourseData;
    CourseMap *courseMap;

    savedForwardSpeed = kart->mForwardSpeed;
    placement.mOldPos = kart->mPos;
    if (useCourseMapRecord != 0) {
        courseMap = gCourseMap;
        if (courseMap->mRaceEndPlacements == NULL) {
            hasCourseData = FALSE;
        } else {
            placement.mRecordPos = courseMap->mRaceEndPlacements->mPos;
            placement.mRecordRotation = courseMap->mRaceEndPlacements->mRotation;
            placement.mKeepSpeedFlag = courseMap->mRaceEndPlacements->mKeepSpeedFlag;
            hasCourseData = TRUE;
        }
        if (hasCourseData == FALSE) {
            return;
        }
    }
    StopKartItemsAndEffects(kart);
    SetKartModelsEntryCourseColors(kart->mKartModelsEntry);
    kart->mSlotFunctions[1](kart);
    kart->mEntryFlags = kart->mEntryFlags & ~(KART_ENTRY_TERESA | KART_ENTRY_TRANSLUCENT | KART_ENTRY_NOT_DRAWN);
    StopOrthoQuads(kart->mIndex);
    PlaceKartAtStartPlacement(kart, useCourseMapRecord);
    kart->mPos.y = kart->mPos.y - 0x1000;
    if (useCourseMapRecord != 0) {
        if (placement.mKeepSpeedFlag != 0) {
            kart->mForwardSpeed = savedForwardSpeed;
            kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_SLOWING_STOP;
        }
    }
    kart->mMotionFlags = kart->mMotionFlags | KART_MOTION_ON_GROUND;
    if ((kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0) {
        if (isWinner != 0) {
            kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_RESULT_WON;
            SetKartCharacterAnimation(kart, 2, 1);
        } else {
            kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_RESULT_LOST;
            SetKartCharacterAnimation(kart, 3, 1);
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        VEC_Subtract(&kart->mPos, &placement.mOldPos, &placement.mPosChange);
        CallStandingsKartOffsetCallback(kart->mIndex, &placement.mPosChange);
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) == 0) {
        return;
    }
    StartDispCapFadeToClear(0);
    ReleaseJg();
}

void SetKartDriftCharge(Kart *kart, s32 charge) {
    KartTurnEffects *turnEffects;

    kart->mDriftCharge = charge;
    if (kart->mDriftCharge != 2) {
        return;
    }
    turnEffects = GetKartTurnEffects(kart->mIndex);
    StartKartLevel2Effects(turnEffects, (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0 ? 1 : 0);
    StartSound(&kart->mSoundSource, 0xd2, 0x7f, 0);
}

void AdvanceKartDriftCharge(Kart *kart) {
    KartTurnEffects *turnEffects;
    u16 *leftTurnCounts;
    u16 *rightTurnCounts;
    u32 pressedBits;
    enum { K0 } entryIndex;

    if ((kart->mEntryFlags & (KART_ENTRY_CPU | KART_ENTRY_WIFI_PEER)) == 0) {
        if (kart->mDriftCharge >= 3) {
            return;
        }
        kart->mTurnCountTimer = kart->mTurnCountTimer - 1;
        if (kart->mTurnCountTimer > 0) {
            return;
        }
        entryIndex = kart->mEntryIndex;
        pressedBits = gInputSlots[entryIndex].mPressedBits;
        if ((u16) (pressedBits & PAD_KEY_LEFT) != 0) {
            leftTurnCounts = &kart->mLeftTurnCount;
            if (kart->mAwayTurnCounter == leftTurnCounts) {
                if (leftTurnCounts[1] == leftTurnCounts[0]) {
                    leftTurnCounts[0]++;
                    kart->mTurnCountTimer = 10;
                }
            } else if (leftTurnCounts[1] > leftTurnCounts[0]) {
                leftTurnCounts[0]++;
                kart->mDriftCharge = kart->mDriftCharge + 1;
                kart->mTurnCountTimer = 10;
                if (kart->mDriftCharge == 2) {
                    turnEffects = GetKartTurnEffects(kart->mIndex);
                    StartKartLevel2Effects(turnEffects,
                                           (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0 ? 1 : 0);
                    StartSound(&kart->mSoundSource, 0xd2, 0x7f, 0);
                }
            }
        } else if ((u16) (pressedBits & PAD_KEY_RIGHT) != 0) {
            rightTurnCounts = &kart->mRightTurnCount;
            if (kart->mTowardTurnCounter == rightTurnCounts) {
                leftTurnCounts = &kart->mLeftTurnCount;
                if (leftTurnCounts[0] > leftTurnCounts[1]) {
                    rightTurnCounts[0] = rightTurnCounts[0] + 1;
                    kart->mDriftCharge = kart->mDriftCharge + 1;
                    kart->mTurnCountTimer = 10;
                    if (kart->mDriftCharge == 2) {
                        turnEffects = GetKartTurnEffects(kart->mIndex);
                        StartKartLevel2Effects(turnEffects,
                                               (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0 ? 1 : 0);
                        StartSound(&kart->mSoundSource, 0xd2, 0x7f, 0);
                    }
                }
            } else {
                leftTurnCounts = &kart->mLeftTurnCount;
                if (leftTurnCounts[1] == leftTurnCounts[0]) {
                    rightTurnCounts[0] = rightTurnCounts[0] + 1;
                    kart->mTurnCountTimer = 10;
                }
            }
        }
    }
    if (kart->mDriftCharge != 3) {
        return;
    }
    turnEffects = GetKartTurnEffects(kart->mIndex);
    if ((kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK) != 0) {
        StopKartTurnStartEffects(turnEffects);
        RequestKartLevel4EffectsRestart(turnEffects);
        StartKartLevel3Effects(turnEffects, (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) != 0 ? 1 : 0);
    } else {
        StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    }
    kart->mDriftCharge = kart->mDriftCharge + 1;
}
