#include "Main/Unknown/code_020917d0.h"
#include "Main/Unknown/code_02090354.h"

#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"

void InitSman(MapObject *mapObject) {
    mapObject->mFlags = (((mapObject->mFlags)) | ((data_0215645c)));
}

u8 CollideKartWithSman(Sman *sman, Kart *kart, u8 *firstResponse, u8 *secondResponse) {
    u8 response;
    response = *secondResponse;
    if (*firstResponse == 1) {
        sman->mTopHeight = 0xf333;
        sman->mTopHeightPerFrame = 0x8000;
        sman->mTopRiseProgress = 0;
        sman->mBottomScale = 0;
        sman->mMapObject.mFlags = sman->mMapObject.mFlags | *(u16 *) &gSmanHitFlag;
        sman->mState = 1;
        StartSoundIfKartStarOrKiller(&sman->mMapObject, kart);
    }
    return response;
}

u8 CollideItemObjectWithSman(Sman *sman, ItemObject *itemObject, u8 *firstResponse, u8 *secondResponse) {
    u8 response;
    response = *secondResponse;
    if (*firstResponse == 1) {
        sman->mTopHeight = 0xf333;
        sman->mTopHeightPerFrame = 0x8000;
        sman->mTopRiseProgress = 0;
        sman->mBottomScale = 0;
        sman->mMapObject.mFlags = sman->mMapObject.mFlags | *(u16 *) &gSmanHitFlag;
        sman->mState = 1;
    }
    return response;
}
