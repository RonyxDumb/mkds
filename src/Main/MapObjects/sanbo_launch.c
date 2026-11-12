#include "Main/MapObjects/sanbo_launch.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Course/course_sound_object.h"
#include "Main/MapObjects/map_object_park.h"
#include "code_02147cd8.h"

void *CreateCourseSoundObjectUpdateList(void) {
    return CreateMapObjectUpdateList(InitCourseSoundObjects, UpdateCourseSoundObject, NULL);
}

void StartSanboLaunch(Sanbo *sanbo) {
    s32 pieceIndex;
    RandomState64 *mapObjectRandom;
    u16 randomAngle;
    u16 randomBit;

    for (pieceIndex = 0; pieceIndex < sanbo->mPieceCount; pieceIndex++) {
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue =
            (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        randomAngle = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 0x10000) >> 32;
        sanbo->mPieces[pieceIndex].mPos.x = sanbo->mMapObject.mPos.x;
        sanbo->mPieces[pieceIndex].mPos.y = sanbo->mMapObject.mPos.y + pieceIndex * 0x14000;
        sanbo->mPieces[pieceIndex].mPos.z = sanbo->mMapObject.mPos.z;
        sanbo->mPieces[pieceIndex].mVelocity.x = MUL_FIXED12_NO_ROUND(FX_SinIdx(randomAngle), 0x2000);
        sanbo->mPieces[pieceIndex].mVelocity.y = 0x4000;
        sanbo->mPieces[pieceIndex].mVelocity.z = MUL_FIXED12_NO_ROUND(FX_CosIdx(randomAngle), 0x2000);
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue =
            (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        randomBit = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 2) >> 32;
        sanbo->mPieces[pieceIndex].mRotateZAnglePerFrame = (randomBit != 0 ? 1 : -1) * 0xaab;
    }
    sanbo->mState2Timer = 300;
    sanbo->mState = 2;
}
