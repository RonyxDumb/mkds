#include "Main/Kart/kart_start_placement.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/collision_slots.h"
#include "ITCM/code_01ffd000.h"
#include "ITCM/sphere_collision.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_in_use.h"
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
    if ((kart->mEntryFlags & KART_ENTRY_WIFI_ANY) != 0) {
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
