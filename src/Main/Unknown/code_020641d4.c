#include "Main/Unknown/code_020641d4.h"
#include "Main/Unknown/unk_02175628.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02010c84.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02066000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020738f4.h"
#include "Main/Unknown/code_0207a7ec.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02147000.h"
#include "code_02147288.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "code_021471bc.h"
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
    s32 j;
    s32 k;
    u16 l;
    u32 kartBits;
    MtxFx43 *drawMatrix;
    Vec3 *q;
    CharacterAnimationState *animationState;
    enum { K0 } entryIndex;

    Matrix4x3FromQuaternion(&kart->mUnk_120_m, kart->mUnk_50c);
    kartBits = kart->mUnk_4c;
    if ((kartBits & 0x10) != 0) {
        drawMatrix = &kart->mUnk_150_m;
        MTX_Identity43_(&offsetMatrix);
        negatedOffsetMatrix = offsetMatrix;
        Matrix4x3FromQuaternion(&rotationMatrix, &kart->mRotationQuaternion);
        q = &kart->mUnk_12c;
        pivotOffset.x = MUL_FIXED12_NO_ROUND(q->x, -0x5000);
        pivotOffset.y = MUL_FIXED12_NO_ROUND(q->y, -0x5000);
        pivotOffset.z = MUL_FIXED12_NO_ROUND(q->z, -0x5000);
        offsetMatrix.mRows[3] = pivotOffset;
        pivotOffset.x = -pivotOffset.x;
        pivotOffset.y = -pivotOffset.y;
        pivotOffset.z = -pivotOffset.z;
        negatedOffsetMatrix.mRows[3] = pivotOffset;
        MTX_Concat43(&kart->mUnk_120_m, &offsetMatrix, drawMatrix);
        MTX_Concat43(drawMatrix, &rotationMatrix, drawMatrix);
        MTX_Concat43(drawMatrix, &negatedOffsetMatrix, drawMatrix);
        if ((kart->mUnk_4c & 0x20) != 0) {
            MTX_RotY43_(&extraYRotationMatrix, SIN_OF_ANGLE(kart->mYRotationAngle),
                        COS_OF_ANGLE(kart->mYRotationAngle));
            MTX_Concat43(drawMatrix, &extraYRotationMatrix, drawMatrix);
        }
        drawMatrix->mRows[3].x = drawMatrix->mRows[3].x + kart->mPosSource->x;
        drawMatrix->mRows[3].y = drawMatrix->mRows[3].y + kart->mPosSource->y;
        drawMatrix->mRows[3].z = drawMatrix->mRows[3].z + kart->mPosSource->z;
    } else if ((kartBits & 0x20) != 0) {
        MTX_RotY43_(&yRotationMatrix, SIN_OF_ANGLE(kart->mYRotationAngle), COS_OF_ANGLE(kart->mYRotationAngle));
        MTX_Concat43(&yRotationMatrix, &kart->mUnk_120_m, &kart->mUnk_150_m);
        q = kart->mPosSource;
        kart->mUnk_174.x = q->x;
        kart->mUnk_174.y = q->y;
        kart->mUnk_174.z = q->z;
    } else {
        kart->mUnk_150_m = kart->mUnk_120_m;
        q = kart->mPosSource;
        kart->mUnk_174.x = q->x;
        kart->mUnk_174.y = q->y;
        kart->mUnk_174.z = q->z;
    }
    kart->mDrawMatrixPos = kart->mUnk_174;
    kart->mUnk_174.x = kart->mUnk_174.x >> 4;
    kart->mUnk_174.y = kart->mUnk_174.y >> 4;
    kart->mUnk_174.z = kart->mUnk_174.z >> 4;
    if ((kart->mUnk_4c & 0x2000000) == 0) {
        kart->mDrawMatrix = &kart->mUnk_150_m;
    } else {
        AdvanceKartWobble(kart);
        kart->mDrawMatrix = &kart->mWobbleMatrix;
    }
    modelsEntry = kart->mKartModelsEntry;
    if (modelsEntry->mModels[2] != NULL) {
        animationState = &modelsEntry->mAnimationState;
        j = MUL_FIXED12_NO_ROUND(animationState->mMiddleFrameReciprocal, animationState->mTurnFrameOffset);
        l = MUL_FIXED12_NO_ROUND(j, 0xce4);
        k = kart->mVelocityLengthRatio;
        if (kart->mUnk_4d4 > k) {
            kart->mTireSpinAngle = kart->mTireSpinAngle + (u16) MUL_FIXED12_NO_ROUND(kart->mUnk_4d4, 0x7d0);
        } else {
            k = MUL_FIXED12_NO_ROUND(k, 0xfa0);
            if (GetAbsoluteValue(GetKartForwardSpeedRatio()) < 0x29) {
                k = 0;
                if ((u16) (gInputSlots[entryIndex = kart->mEntryIndex].mBits & (PAD_KEY_A | PAD_KEY_B)) != 0 &&
                    IsRaceStarted() == 1) {
                    k = k + 0x190;
                }
            } else if ((kart->mUnk_44 & KART_44_REVERSING) != 0) {
                k *= -1;
            }
            if (k > 0xfa0) {
                k = 0xfa0;
            }
            kart->mTireSpinAngle = kart->mTireSpinAngle + (u16) k;
        }
        kart->mUnk_4cc = l;
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
    if ((kart->mUnk_4c & KART_4C_BLINK_GUARD) != 0) {
        kart->mBlinkFrames = kart->mBlinkFrames + 1;
        kart->mBlinkCycleFrames = kart->mBlinkCycleFrames + 1;
        if (kart->mBlinkCycleFrames > 8) {
            kart->mBlinkCycleFrames = 0;
        }
        if (kart->mBlinkCycleFrames >= 4) {
            kart->mUnk_4c = kart->mUnk_4c | KART_4C_BLINK_HIDDEN;
        } else {
            kart->mUnk_4c = kart->mUnk_4c & ~KART_4C_BLINK_HIDDEN;
        }
        if (kart->mBlinkFrames > 0x5a) {
            kart->mUnk_4c = kart->mUnk_4c & ~(KART_4C_BLINK_HIDDEN | KART_4C_BLINK_GUARD);
        }
    }
    AdvanceKartEffects(kart);
}

void AdvanceKartCollisionSlot(Kart *kart) {
    AdvanceKartCollision(kart);
    AdvanceKartDrawState(kart);
}
