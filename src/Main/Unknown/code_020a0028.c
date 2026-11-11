#include "Main/Unknown/code_020a0028.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_0209b000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"

void CreateAirship(void *mapObjectList) {
    gAirship = CreateMapObjectModelAnimated(mapObjectList, gAirshipNsbmdName);
    SetMapObjectModelPolygonId(gAirship, 0x3f);
}

void DrawAirship(void *mapObjectList, Airship *airship) {
    s32 gxParam;
    MtxFx33 rotationMatrix;
    Vec3 translation;

    gxParam = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &gxParam, 1);
    translation.y = (airship->mUnk_a0 + airship->mWobbleOffset) >> 4;
    translation.x = 0;
    translation.z = 0;
    NNS_G3dGeBufferOP_N(0x1c, &translation, 3);
    airship->mMapObject.mMatrix.mRows[3].x = airship->mMapObject.mPos.x >> 4;
    airship->mMapObject.mMatrix.mRows[3].y = airship->mMapObject.mPos.y >> 4;
    airship->mMapObject.mMatrix.mRows[3].z = airship->mMapObject.mPos.z >> 4;
    NNS_G3dGeBufferOP_N(0x19, &airship->mMapObject.mMatrix, 0xc);
    if (airship->mMapObject.mAngle != 0) {
        MTX_RotY33_(&rotationMatrix, SIN_OF_ANGLE(airship->mMapObject.mAngle),
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
    for (mapObjectIndex = 0; mapObjectIndex < list->mUnk_04 && (airship = list->mUnk_00[mapObjectIndex]) != NULL;
         mapObjectIndex++) {
        InitGroupFollower(&airship->mUnk_c8, airship->mMapObject.mCourseMapRow, followerSpeed);
        airship->mUnk_a4 = (airship->mMapObject.mCourseMapRow->mSettings[0] * 0x5000L) / 100;
        speed = airship->mUnk_a4;
        airship->mUnk_c8.mSpeed = speed;
        airship->mUnk_c8.mProgressStep = MUL_FIXED12_NO_ROUND(
            speed, airship->mUnk_c8.mPath->mSegments[airship->mUnk_c8.mSegmentIndex].mInverseProgressLength);
        airship->mUnk_a0 = airship->mMapObject.mPos.y;
        GetGroupFollowerCurvePosStep(&airship->mUnk_c8, &airship->mMapObject.mPos, &airship->mMapObject.mPosStep);
        airship->mUnk_a0 = airship->mUnk_a0 - airship->mMapObject.mPos.y;
        airship->mWobbleAngle = 0;
        airship->mWobbleMid = 0;
        airship->mWobbleAmplitude = 0x50000;
        airship->mWobbleAmplitudePerFrame = 0;
        airship->mWobbleAnglePerFrame = 0xb6;
        airship->mUnk_c4 = 0;
        if (airship->mMapObject.mCourseMapRow->mSettings[1] != 0) {
            airship->mState = 0;
        } else {
            airship->mState = 2;
        }
    }
}

s32 AirshipFX_CosIdx(s32 angle) {
    return COS_OF_ANGLE(angle);
}

s32 AirshipFX_MulInline(s32 multiplicand, s32 multiplier) {
    return MUL_FIXED12_ROUNDED(multiplicand, multiplier);
}
