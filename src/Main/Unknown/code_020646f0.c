#include "Main/Unknown/code_020646f0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_02040de0.h"
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
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02147cd8.h"

void PlaceKartAtStartPlacement(Kart *kart, s32 useCourseMapRecord) {
    MtxFx43 *rotationMatrix;
    CourseMap *courseMap;
    Vec3 startRotation;
    Vec3 pushOut;
    Vec3 hitNormal;
    Vec3 raisedPos;
    Vec3 normalOffset;
    ModelAnimation *characterAnimation;
    s16 snappedX;
    s16 snappedY;
    s16 snappedZ;
    Vec3 *kartPos;

    if (useCourseMapRecord == 0) {
        GetCourseMapKartStartPlacement(&kart->mPos, &startRotation, kart->mIndex);
        if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
            kart->mPos = data_0216549c[kart->mIndex];
        }
    } else {
        courseMap = gCourseMap;
        if (courseMap->mRaceEndPlacements != NULL) {
            kartPos = &kart->mPos;
            if (kartPos != NULL) {
                *kartPos = courseMap->mRaceEndPlacements->mPos;
            }
            startRotation = courseMap->mRaceEndPlacements->mRotation;
        }
    }
    if ((kart->mUnk_7c & 0x600) != 0) {
        snappedX = kart->mPos.x >> 10;
        snappedY = kart->mPos.y >> 10;
        snappedZ = kart->mPos.z >> 10;
        kart->mPos.x = snappedX << 10;
        kart->mPos.y = snappedY << 10;
        kart->mPos.z = snappedZ << 10;
    }
    raisedPos = kart->mPos;
    raisedPos.y = raisedPos.y + 0x1000;
    kart->mPos.y = kart->mPos.y - 0x1400;
    if (CollideSphereWithCourse(&kart->mPos, &raisedPos, &kart->mTurnedForward, 0x5000, 1, -2, &pushOut, &hitNormal,
                                NULL, NULL, NULL, NULL, NULL, NULL) != 0) {
        normalOffset.x = MUL_FIXED12_NO_ROUND(hitNormal.x, 0x5000);
        normalOffset.y = MUL_FIXED12_NO_ROUND(hitNormal.y, 0x5000);
        normalOffset.z = MUL_FIXED12_NO_ROUND(hitNormal.z, 0x5000);
        VEC_Subtract(&pushOut, &normalOffset, &pushOut);
        VEC_Add(&kart->mPos, &pushOut, &kart->mPos);
    }
    kart->mPos.y = kart->mPos.y - 0x1000;
    kart->mHeadingAngle = (u32) (startRotation.y * 0xb6) >> 12;
    QuaternionFromAxisAngle(&data_02154a3c, kart->mHeadingAngle, &kart->mUnk_e0_m);
    kart->mUnk_110_q = kart->mUnk_e0_m;
    Matrix4x3FromQuaternion(&kart->mUnk_120_m, &kart->mUnk_110_q);
    kart->mUnk_150_m = kart->mUnk_120_m;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mUnk_174.x = kart->mDrawMatrixPos.x;
    kart->mUnk_174.y = kart->mDrawMatrixPos.y;
    kart->mUnk_174.z = kart->mDrawMatrixPos.z;
    rotationMatrix = &kart->mUnk_120_m;
    kart->mForward.x = rotationMatrix->mRows[2].x;
    kart->mForward.y = rotationMatrix->mRows[2].y;
    kart->mForward.z = rotationMatrix->mRows[2].z;
    kart->mTurnedForward = kart->mForward;
    kart->mDrawMatrix = &kart->mUnk_150_m;
    characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
    if (characterAnimation == NULL) {
        return;
    }
    if (characterAnimation->mAnmObjCount != 0) {
        characterAnimation->mHead.mFrameIndex = kart->mKartModelsEntry->mAnimationState.mMiddleFrame;
    }
}
