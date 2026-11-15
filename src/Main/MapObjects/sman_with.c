#include "Main/MapObjects/sman_with.h"
#include "Main/Race/gp_records_killer.h"

#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"

void InitSman(MapObject *mapObject) {
    mapObject->mFlags = (((mapObject->mFlags)) | ((gSmanInitMapObjectFlag)));
}

u8 CollideKartWithSman(Sman *sman, Kart *kart, u8 *firstResponse, u8 *secondResponse) {
    u8 response;
    response = *secondResponse;
    if (*firstResponse == 1) {
        sman->mTopHeight = SMAN_TOP_HEIGHT;
        sman->mTopHeightPerFrame = SMAN_TOP_HEIGHT_PER_FRAME;
        sman->mTopRiseProgress = 0;
        sman->mBottomScale = 0;
        sman->mMapObject.mFlags = sman->mMapObject.mFlags | gSmanHitFlag;
        sman->mState = SMAN_STATE_TOP_FLIGHT;
        StartSoundIfKartStarOrKiller(&sman->mMapObject, kart);
    }
    return response;
}

u8 CollideItemObjectWithSman(Sman *sman, ItemObject *itemObject, u8 *firstResponse, u8 *secondResponse) {
    u8 response;
    response = *secondResponse;
    if (*firstResponse == 1) {
        sman->mTopHeight = SMAN_TOP_HEIGHT;
        sman->mTopHeightPerFrame = SMAN_TOP_HEIGHT_PER_FRAME;
        sman->mTopRiseProgress = 0;
        sman->mBottomScale = 0;
        sman->mMapObject.mFlags = sman->mMapObject.mFlags | gSmanHitFlag;
        sman->mState = SMAN_STATE_TOP_FLIGHT;
    }
    return response;
}

const u16 gSmanHitFlag = 1;
const u16 gSmanInitMapObjectFlag = 0x200;
