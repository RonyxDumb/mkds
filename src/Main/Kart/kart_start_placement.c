#include "Main/Kart/kart_start_placement.h"
#include "ITCM/kart_motion.h"
#include "ITCM/collision_slots.h"
#include "ITCM/sphere_collision.h"
#include "Main/Course/course_map_shapes.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_in_use.h"
#include "fixed_vector_math.h"
#include "Main/Kart/course_models.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/System/init_after_startup.h"

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
            kart->mPos = gKartAwardStartPositions[kart->mIndex];
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
    QuaternionFromAxisAngle(&gKartStartPlacementHeadingAxis, kart->mHeadingAngle, &kart->mHeadingQuaternion);
    kart->mCombinedQuaternion = kart->mHeadingQuaternion;
    Matrix4x3FromQuaternion(&kart->mRotationMatrix, &kart->mCombinedQuaternion);
    kart->mDrawBaseMatrix = kart->mRotationMatrix;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mDrawBaseRow3.x = kart->mDrawMatrixPos.x;
    kart->mDrawBaseRow3.y = kart->mDrawMatrixPos.y;
    kart->mDrawBaseRow3.z = kart->mDrawMatrixPos.z;
    rotationMatrix = &kart->mRotationMatrix;
    kart->mForward.x = rotationMatrix->mRows[2].x;
    kart->mForward.y = rotationMatrix->mRows[2].y;
    kart->mForward.z = rotationMatrix->mRows[2].z;
    kart->mTurnedForward = kart->mForward;
    kart->mDrawMatrix = &kart->mDrawBaseMatrix;
    characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
    if (characterAnimation == NULL) {
        return;
    }
    if (characterAnimation->mAnmObjCount != 0) {
        characterAnimation->mHead.mFrameIndex = kart->mKartModelsEntry->mAnimationState.mMiddleFrame;
    }
}
