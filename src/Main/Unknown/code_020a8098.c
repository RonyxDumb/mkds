#include "Main/Unknown/code_020a8098.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a826c.h"
#include "Main/Unknown/code_020a8a6c.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0215d000.h"

void *CreateCourseSoundObjectUpdateList(void) {
    return CreateMapObjectUpdateList(InitCourseSoundObjects, UpdateCourseSoundObject, NULL);
}

void StartSanboLaunch(Sanbo *sanbo) {
    s32 i;
    RandomState64 *mapObjectRandom;
    u16 randomAngle;
    u16 randomBit;

    for (i = 0; i < sanbo->mPieceCount; i++) {
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue =
            (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        randomAngle = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 0x10000) >> 32;
        sanbo->mPieces[i].mPos.x = sanbo->mMapObject.mPos.x;
        sanbo->mPieces[i].mPos.y = sanbo->mMapObject.mPos.y + i * 0x14000;
        sanbo->mPieces[i].mPos.z = sanbo->mMapObject.mPos.z;
        sanbo->mPieces[i].mVelocity.x = MUL_FIXED12_NO_ROUND(gPairsByAngle[(randomAngle >> 4) * 2], 0x2000);
        sanbo->mPieces[i].mVelocity.y = 0x4000;
        sanbo->mPieces[i].mVelocity.z = MUL_FIXED12_NO_ROUND(gPairsByAngle[(randomAngle >> 4) * 2 + 1], 0x2000);
        mapObjectRandom = GetMapObjectRandom();
        mapObjectRandom->mValue =
            (s64) mapObjectRandom->mMultiplier * (s64) mapObjectRandom->mValue + mapObjectRandom->mIncrement;
        randomBit = ((u64) (u32) (mapObjectRandom->mValue >> 32) * 2) >> 32;
        sanbo->mPieces[i].mRotateZAnglePerFrame = (randomBit != 0 ? 1 : -1) * 0xaab;
    }
    sanbo->mState2Timer = 300;
    sanbo->mState = 2;
}
