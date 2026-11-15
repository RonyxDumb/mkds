#include "Main/MapObjects/map_object_list.h"

#include "Main/MapObjects/view_frustum.h"
#include "ITCM/collision_slots.h"
#include "Main/MapObjects/woodbox.h"
#include "Main/MapObjects/group_follower.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/item_in_use.h"
#include "matrix_3x3_basic.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/MapObjects/does_map_object.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/sound_if_kart_star_or.h"
#include "Main/MapObjects/map_object_scale_sound_source.h"
#include "Main/MapObjects/map_object.h"
#include "Main/MapObjects/water.h"
#include "Main/MapObjects/map_objects_work.h"

#pragma thumb on

void ClearMapObjectListSlots(void) {
    int index;
    MapObjectList **drawListSlot;
    void **listSlot;
    MapObjectList **updateListSlot;
    drawListSlot = gMapObjects->mDrawLists;
    updateListSlot = gMapObjects->mUpdateLists;
    index = 0;
    do {
        if (*drawListSlot != NULL) {
            listSlot = *(void ***) ((s32) *drawListSlot + 0x28);
            if (listSlot != NULL) {
                *listSlot = NULL;
            }
            *drawListSlot = NULL;
        }
        drawListSlot = drawListSlot + 1;
        index = index + 1;
    } while (index < 0x18);
    index = 0;
    do {
        if (*updateListSlot != NULL) {
            listSlot = (*updateListSlot)->mDrawOrder;
            if (listSlot != NULL) {
                *listSlot = NULL;
            }
            *updateListSlot = NULL;
        }
        updateListSlot = updateListSlot + 1;
        index = index + 1;
    } while (index < 0x10);
}

#pragma thumb off

#pragma thumb on

s32 CollideSphereWithMapObjects(Vec3 *position, Vec3 *velocity, s32 radius, s16 collisionSlotIndex, s32 itemKind,
                                Vec3 *hitOffset) {
    s32 bestResponse;
    s32 foundIndex;
    bestResponse = 0;
    FindCollisionSlotsOverlappingSlot(collisionSlotIndex, 0x2000);
    foundIndex = 0;
    if (gFoundCollisionSlotCount != 0) {
        Vec3 overlapOffset;
        Vec3 lowest;
        Vec3 highest;
        ItemObject *itemObject;
        MapObject *mapObject;
        s32 response;
        s32 overlapX;
        {
            Vec3 zeroLow = {0, 0, 0};
            lowest = zeroLow;
        }
        {
            Vec3 zeroHigh = {0, 0, 0};
            highest = zeroHigh;
        }
        itemObject = &gMapObjects->mProbeItemObject;
        for (; foundIndex < gFoundCollisionSlotCount; foundIndex++) {
            mapObject = gFoundCollisionSlotObjects[foundIndex];
            if (IsSphereHittingMapObject(position, radius, mapObject, &overlapOffset) != FALSE) {
                if (!(mapObject->mFlags & MAP_OBJECT_FLAG_NOT_COLLIDABLE) &&
                    DoesItemObjectRespondToMapObject(itemKind, mapObject) != 0) {
                    overlapX = overlapOffset.x;
                    lowest.x = ((const Vec3 *) &overlapOffset)->x < lowest.x ? overlapX : lowest.x;
                    lowest.y = overlapOffset.y < lowest.y ? overlapOffset.y : lowest.y;
                    lowest.z = overlapOffset.z < lowest.z ? overlapOffset.z : lowest.z;
                    highest.x = overlapX > highest.x ? overlapX : highest.x;
                    highest.y = overlapOffset.y > highest.y ? overlapOffset.y : highest.y;
                    highest.z = overlapOffset.z > highest.z ? overlapOffset.z : highest.z;
                }
                itemObject->mPos = *position;
                itemObject->mVelocity = *velocity;
                itemObject->mKind = itemKind;
                response = CollideItemObjectWithMapObject(itemObject, mapObject, NULL);
                if (response > bestResponse) {
                    bestResponse = response;
                }
            }
        }
        if (bestResponse != 0 && hitOffset != NULL) {
            hitOffset->x = highest.x + lowest.x;
            hitOffset->y = highest.y + lowest.y;
            if (hitOffset->y < 0) {
                hitOffset->y = 0;
            }
            hitOffset->z = highest.z + lowest.z;
        }
    }
    return bestResponse;
}

#pragma thumb off

#pragma thumb on

u32 GetMapObjectKindCount(void) {
    return (gMapObjectKindCount);
}

// The water_efct.nsbmd file: WaterEfct's if gCourseWaterEfct exists, else the Water's own when mIsHeightUsed is
// non-zero, else NULL; passed as an effect model file to SetupModelEffectKind.
void *GetWaterEfctNsbmdFile(void) {
    Water *water;
    if (gCourseWaterEfct != NULL) {
        return gCourseWaterEfct->mNsbmdFile;
    }
    water = gCourseWater;
    if ((water != NULL) && (water->mIsHeightUsed != 0)) {
        return water->mEfctNsbmdFile;
    }
    return NULL;
}

// The water_efct.nsbca file, same rule as GetWaterEfctNsbmdFile.
void *GetWaterEfctNsbcaFile(void) {
    Water *water;
    if (gCourseWaterEfct != NULL) {
        return gCourseWaterEfct->mNsbcaFile;
    }
    water = gCourseWater;
    if ((water != NULL) && (water->mIsHeightUsed != 0)) {
        return water->mEfctNsbcaFile;
    }
    return NULL;
}

// The water_efct.nsbma file, same rule as GetWaterEfctNsbmdFile.
void *GetWaterEfctNsbmaFile(void) {
    Water *water;
    if (gCourseWaterEfct != NULL) {
        return gCourseWaterEfct->mNsbmaFile;
    }
    water = gCourseWater;
    if ((water != NULL) && (water->mIsHeightUsed != 0)) {
        return water->mEfctNsbmaFile;
    }
    return NULL;
}

#pragma thumb off
