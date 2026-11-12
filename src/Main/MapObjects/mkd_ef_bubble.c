#include "Main/MapObjects/mkd_ef_bubble.h"
#include "Main/MapObjects/item_box.h"
#include "Main/MapObjects/group_item_box.h"
#include "Main/Kart/kart_drift.h"

#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "fx_mtx33.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"

void EnterMkdEfBubbleState1(MkdEfBubbleObject *bubble) {
    bubble->mMapObject.mFlags |= data_0215877c;
    bubble->mMapObject.mFlags |= data_02158780;
}

void UpdateMkdEfBubbleState1(MkdEfBubbleObject *bubble) {
    if (bubble->mMapObject.mStateMachine.mStateFrames >= bubble->mDelayFrameCount) {
        bubble->mMapObject.mStateMachine.mNextState = 0;
        bubble->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u8 CollideKartWithMkdEfBubble(MkdEfBubbleObject *bubble, Kart *kart, void *unused, u8 *secondResponsePtr) {
    u32 kartBit;

    kartBit = (1 << kart->mIndex) & 0xff;
    if ((bubble->mKartMask & kartBit) == 0) {
        if (StartSoundIfKartStarOrKiller(&bubble->mMapObject, kart) != 0) {
            bubble->mMapObject.mDistanceSquaredAndFlags |= data_02158778;
            bubble->mKartMask |= kartBit;
        }
    }
    return *secondResponsePtr;
}

u32 CollideItemObjectWithMkdEfBubble(u32 unused0, u32 unused1, u32 unused2, u32 secondResponsePtr) {
    return (*OFFSET_PTR(const u8, secondResponsePtr, 0));
}
