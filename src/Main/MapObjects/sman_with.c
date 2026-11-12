#include "Main/MapObjects/sman_with.h"
#include "Main/Race/gp_records_killer.h"

#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"

void InitSman(MapObject *mapObject) {
    mapObject->mFlags = (((mapObject->mFlags)) | ((gSmanInitMapObjectFlag)));
}

u8 CollideKartWithSman(Sman *sman, Kart *kart, u8 *firstResponse, u8 *secondResponse) {
    u8 response;
    response = *secondResponse;
    if (*firstResponse == 1) {
        sman->mTopHeight = 0xf333;
        sman->mTopHeightPerFrame = 0x8000;
        sman->mTopRiseProgress = 0;
        sman->mBottomScale = 0;
        sman->mMapObject.mFlags = sman->mMapObject.mFlags | gSmanHitFlag;
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
        sman->mMapObject.mFlags = sman->mMapObject.mFlags | gSmanHitFlag;
        sman->mState = 1;
    }
    return response;
}

const u16 gSmanHitFlag = 1;
const u16 gSmanInitMapObjectFlag = 0x200;
