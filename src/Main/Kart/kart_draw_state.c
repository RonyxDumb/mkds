#include "Main/Kart/kart_draw_state.h"
#include "Main/Menu/data_02175628.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/kart_ground_contact.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Kart/code_02066ac0.h"
#include "Main/Item/item_in_use.h"
#include "code_02010c84.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Kart/kart_state0_return.h"
#include "Main/Kart/karts.h"
#include "Main/Item/item_pool.h"
#include "code_02012b30.h"
#include "fx_mtx43.h"
#include "Main/Race/kart.h"
#include "code_02147cd8.h"

void AdvanceKartDrawState(Kart *kart) {
    KartModelsEntry *modelsEntry;
    ModelAnimation *characterAnimation;
    Vec3 pivotOffset;
    MtxFx43 offsetMatrix;
    MtxFx43 negatedOffsetMatrix;
    MtxFx43 rotationMatrix;
    MtxFx43 extraYRotationMatrix;
    MtxFx43 yRotationMatrix;
    s32 turnFraction;
    s32 tireSpinStep;
    u16 tireTurnAngle;
    u32 kartBits;
    MtxFx43 *drawMatrix;
    Vec3 *source;
    CharacterAnimationState *animationState;
    enum { K0 } entryIndex;

    Matrix4x3FromQuaternion(&kart->mUnk_120_m, kart->mRotationSource);
    kartBits = kart->mEffectFlags;
    if ((kartBits & KART_EFFECT_TUMBLING) != 0) {
        drawMatrix = &kart->mUnk_150_m;
        MTX_Identity43_(&offsetMatrix);
        negatedOffsetMatrix = offsetMatrix;
        Matrix4x3FromQuaternion(&rotationMatrix, &kart->mRotationQuaternion);
        source = &kart->mUnk_12c;
        pivotOffset.x = MUL_FIXED12_NO_ROUND(source->x, -0x5000);
        pivotOffset.y = MUL_FIXED12_NO_ROUND(source->y, -0x5000);
        pivotOffset.z = MUL_FIXED12_NO_ROUND(source->z, -0x5000);
        offsetMatrix.mRows[3] = pivotOffset;
        pivotOffset.x = -pivotOffset.x;
        pivotOffset.y = -pivotOffset.y;
        pivotOffset.z = -pivotOffset.z;
        negatedOffsetMatrix.mRows[3] = pivotOffset;
        MTX_Concat43(&kart->mUnk_120_m, &offsetMatrix, drawMatrix);
        MTX_Concat43(drawMatrix, &rotationMatrix, drawMatrix);
        MTX_Concat43(drawMatrix, &negatedOffsetMatrix, drawMatrix);
        if ((kart->mEffectFlags & KART_EFFECT_Y_SPIN) != 0) {
            MTX_RotY43_(&extraYRotationMatrix, SIN_OF_ANGLE(kart->mYRotationAngle),
                        COS_OF_ANGLE(kart->mYRotationAngle));
            MTX_Concat43(drawMatrix, &extraYRotationMatrix, drawMatrix);
        }
        drawMatrix->mRows[3].x = drawMatrix->mRows[3].x + kart->mPosSource->x;
        drawMatrix->mRows[3].y = drawMatrix->mRows[3].y + kart->mPosSource->y;
        drawMatrix->mRows[3].z = drawMatrix->mRows[3].z + kart->mPosSource->z;
    } else if ((kartBits & KART_EFFECT_Y_SPIN) != 0) {
        MTX_RotY43_(&yRotationMatrix, SIN_OF_ANGLE(kart->mYRotationAngle), COS_OF_ANGLE(kart->mYRotationAngle));
        MTX_Concat43(&yRotationMatrix, &kart->mUnk_120_m, &kart->mUnk_150_m);
        source = kart->mPosSource;
        kart->mUnk_174.x = source->x;
        kart->mUnk_174.y = source->y;
        kart->mUnk_174.z = source->z;
    } else {
        kart->mUnk_150_m = kart->mUnk_120_m;
        source = kart->mPosSource;
        kart->mUnk_174.x = source->x;
        kart->mUnk_174.y = source->y;
        kart->mUnk_174.z = source->z;
    }
    kart->mDrawMatrixPos = kart->mUnk_174;
    kart->mUnk_174.x = kart->mUnk_174.x >> 4;
    kart->mUnk_174.y = kart->mUnk_174.y >> 4;
    kart->mUnk_174.z = kart->mUnk_174.z >> 4;
    if ((kart->mEffectFlags & KART_EFFECT_WOBBLE) == 0) {
        kart->mDrawMatrix = &kart->mUnk_150_m;
    } else {
        AdvanceKartWobble(kart);
        kart->mDrawMatrix = &kart->mWobbleMatrix;
    }
    modelsEntry = kart->mKartModelsEntry;
    if (modelsEntry->mModels[2] != NULL) {
        animationState = &modelsEntry->mAnimationState;
        turnFraction = MUL_FIXED12_NO_ROUND(animationState->mMiddleFrameReciprocal, animationState->mTurnFrameOffset);
        tireTurnAngle = MUL_FIXED12_NO_ROUND(turnFraction, 0xce4);
        tireSpinStep = kart->mVelocityLengthRatio;
        if (kart->mRevLevel > tireSpinStep) {
            kart->mTireSpinAngle = kart->mTireSpinAngle + (u16) MUL_FIXED12_NO_ROUND(kart->mRevLevel, 0x7d0);
        } else {
            tireSpinStep = MUL_FIXED12_NO_ROUND(tireSpinStep, 0xfa0);
            if (GetAbsoluteValue(GetKartForwardSpeedRatio()) < 0x29) {
                tireSpinStep = 0;
                if ((u16) (gInputSlots[entryIndex = kart->mEntryIndex].mBits & (PAD_KEY_A | PAD_KEY_B)) != 0 &&
                    IsRaceStarted() == 1) {
                    tireSpinStep = tireSpinStep + 0x190;
                }
            } else if ((kart->mMotionFlags & KART_MOTION_REVERSING) != 0) {
                tireSpinStep *= -1;
            }
            if (tireSpinStep > 0xfa0) {
                tireSpinStep = 0xfa0;
            }
            kart->mTireSpinAngle = kart->mTireSpinAngle + (u16) tireSpinStep;
        }
        kart->mTireTurnAngle = tireTurnAngle;
    }
    characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
    if (characterAnimation != NULL && characterAnimation->mAnmObjCount != 0) {
        AdvanceKartCharacterAnimation(kart);
        if (IsKartEnded(kart->mIndex) != 0) {
            AdvanceKartAnimationChangeTimer(kart);
        }
        characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
        characterAnimation->mAnmObjs[characterAnimation->mCurrentIndex]->mFrame = characterAnimation->mHead.mFrameIndex;
    }
    if ((kart->mEffectFlags & KART_EFFECT_BLINK_GUARD) != 0) {
        kart->mBlinkFrames = kart->mBlinkFrames + 1;
        kart->mBlinkCycleFrames = kart->mBlinkCycleFrames + 1;
        if (kart->mBlinkCycleFrames > 8) {
            kart->mBlinkCycleFrames = 0;
        }
        if (kart->mBlinkCycleFrames >= 4) {
            kart->mEffectFlags = kart->mEffectFlags | KART_EFFECT_BLINK_HIDDEN;
        } else {
            kart->mEffectFlags = kart->mEffectFlags & ~KART_EFFECT_BLINK_HIDDEN;
        }
        if (kart->mBlinkFrames > 0x5a) {
            kart->mEffectFlags = kart->mEffectFlags & ~(KART_EFFECT_BLINK_HIDDEN | KART_EFFECT_BLINK_GUARD);
        }
    }
    AdvanceKartEffects(kart);
}

void AdvanceKartCollisionSlot(Kart *kart) {
    AdvanceKartCollision(kart);
    AdvanceKartDrawState(kart);
}
