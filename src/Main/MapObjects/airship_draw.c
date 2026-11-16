#include "Main/MapObjects/airship_draw.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/MapObjects/group_follower_advance.h"
#include "Main/MapObjects/group_follower_init.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "Main/Menu/keyboard_char_tables.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "matrix_3x3_basic.h"
#include "fixed_vector_math.h"
#include "Main/MapObjects/chandelier.h"
#include "Main/MapObjects/bound.h"
#include "Main/MapObjects/map_object_kind_update_list.h"

MapObjectModel *gAirship;

MapObjectKindDescriptor gCourseMapRowKindDescriptor = {0,
                                             {0, 0},
                                             0xa0,
                                             InitCourseMapRowKindData,
                                             CreateCourseMapRowKindData};
MapObjectKindDescriptor gAirshipKindDescriptor = {
    0, {0, 0}, 0xf0, 0, CreateEmptyMapObjectKindData, CreateAirshipDrawList, 0, 0, CreateAirshipUpdateList};

void LoadAirshipMapObject(void *mapObjectList) {
    gAirship = CreateMapObjectFromModel_from_thumb(mapObjectList, "airship.nsbmd");
    StructMapObject_MaybeSetPolygonId(gAirship, 0x3f);
}

void DrawAirship(void *mapObjectList, Airship *airship) {
    s32 gxParam;
    MtxFx33 rotationMatrix;
    Vec3 translation;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    translation.y = (airship->mModelHeightOffset + airship->mWobbleOffset) >> 4;
    translation.x = 0;
    translation.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &translation, 3);
    airship->mMapObject.mMatrix.mRows[3].x = airship->mMapObject.mPos.x >> 4;
    airship->mMapObject.mMatrix.mRows[3].y = airship->mMapObject.mPos.y >> 4;
    airship->mMapObject.mMatrix.mRows[3].z = airship->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &airship->mMapObject.mMatrix, 0xc);
    if (airship->mMapObject.mAngle != 0) {
        MTX_RotY33__from_thumb(&rotationMatrix, SIN_OF_ANGLE(airship->mMapObject.mAngle),
                    COS_OF_ANGLE(airship->mMapObject.mAngle));
        NNS_G3dGeBufferOP_N(0x1a, &rotationMatrix, 9);
    }
    NNS_G3dGeBufferOP_N(0x1b, &airship->mMapObject.mScale, 3);
    DrawMapObjectModel(mapObjectList, gAirship, airship);
}

void InitAirshipObjects(AirshipObjectList *list) {
    s32 mapObjectIndex;
    Airship *airship;
    BOOL followerSpeed;
    s32 speed;

    if (list == NULL) {
        return;
    }
    followerSpeed = FALSE;
    for (mapObjectIndex = 0; mapObjectIndex < list->mCount && (airship = list->mAirships[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        InitGroupFollower(&airship->mGroupFollower, airship->mMapObject.mCourseMapRow, followerSpeed);
        airship->mPathSpeed = (airship->mMapObject.mCourseMapRow->mSettings[0] * 0x5000L) / 100;
        speed = airship->mPathSpeed;
        airship->mGroupFollower.mSpeed = speed;
        airship->mGroupFollower.mProgressStep = MUL_FIXED12_NO_ROUND(
            speed,
            airship->mGroupFollower.mPath->mSegments[airship->mGroupFollower.mSegmentIndex].mInverseProgressLength);
        airship->mModelHeightOffset = airship->mMapObject.mPos.y;
        GetGroupFollowerCurvePosStep(&airship->mGroupFollower, &airship->mMapObject.mPos,
                                     &airship->mMapObject.mPosStep);
        airship->mModelHeightOffset = airship->mModelHeightOffset - airship->mMapObject.mPos.y;
        airship->mWobbleAngle = 0;
        airship->mWobbleMid = 0;
        airship->mWobbleAmplitude = AIRSHIP_WOBBLE_AMPLITUDE;
        airship->mWobbleAmplitudePerFrame = 0;
        airship->mWobbleAnglePerFrame = AIRSHIP_WOBBLE_ANGLE_PER_FRAME;
        airship->mWobbleAnglePerFrameStep = 0;
        if (airship->mMapObject.mCourseMapRow->mSettings[1] != 0) {
            airship->mState = AIRSHIP_STATE_WAIT_SECOND_LAP;
        } else {
            airship->mState = AIRSHIP_STATE_FOLLOW_PATH;
        }
    }
}

s32 AirshipFX_CosIdx(s32 angle) {
    return COS_OF_ANGLE(angle);
}

s32 AirshipFX_MulInline(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_ROUNDED(multiplicand, multiplier);
}
