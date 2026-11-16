#include "Main/MapObjects/mkd_ef_bubble.h"
#include "Main/MapObjects/item_box.h"
#include "Main/MapObjects/group_item_box.h"
#include "Main/Kart/kart_drift.h"

#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/star_or_killer_hit_sound.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object_list.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/koopa_block.h"

void EnterMkdEfBubbleWait(void *stateObject) {
    MkdEfBubbleObject *bubble = stateObject;
    bubble->mMapObject.mFlags |= gMkdEfBubbleWaitFlag;
    bubble->mMapObject.mFlags |= gMkdEfBubbleWaitSecondFlag;
}

void UpdateMkdEfBubbleWait(void *stateObject) {
    MkdEfBubbleObject *bubble = stateObject;
    if (bubble->mMapObject.mStateMachine.mStateFrames >= bubble->mDelayFrameCount) {
        bubble->mMapObject.mStateMachine.mNextState = MKD_EF_BUBBLE_STATE_LEAP;
        bubble->mMapObject.mStateMachine.mNextStateRequested = 1;
    }
}

u8 CollideKartWithMkdEfBubble(MkdEfBubbleObject *bubble, Kart *kart, void *unused, u8 *secondResponsePtr) {
    u32 kartBit;

    kartBit = (1 << kart->mIndex) & 0xff;
    if ((bubble->mKartMask & kartBit) == 0) {
        if (StartSoundIfKartStarOrKiller(&bubble->mMapObject, kart) != 0) {
            bubble->mMapObject.mDistanceSquaredAndFlags |= gMkdEfBubbleHitFlag;
            bubble->mKartMask |= kartBit;
        }
    }
    return *secondResponsePtr;
}

u32 CollideItemObjectWithMkdEfBubble(u32 unused0, u32 unused1, u32 unused2, const u8 *secondResponsePtr) {
    return *secondResponsePtr;
}

const u32 gMkdEfBubbleHitFlag = 0x40000000;