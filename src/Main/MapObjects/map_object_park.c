#include "Main/MapObjects/map_object_park.h"

#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/MapObjects/rock.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/System/init_after_startup.h"

struct RandomState64 *gMapObjectRandom;
struct RandomState64 *gRaceRandom;

// Puts a pooled map object aside: saves the low flag nibble in the high nibble, sets flags 1, 2, 8 and 4 (the update
// walk skips flag 4) and the parked bit 0x100, and disables its collision slot if it has one.
void ParkMapObject(MapObject *mapObject) {
    mapObject->mFlags &= ~MAP_OBJECT_FLAGS_SAVED_NIBBLE;
    mapObject->mFlags |= (mapObject->mFlags & MAP_OBJECT_FLAGS_LOW_NIBBLE) << 12;
    mapObject->mFlags |= gParkMapObjectFlag;
    mapObject->mFlags |= gParkMapObjectSecondFlag;
    mapObject->mFlags |= gParkMapObjectThirdFlag;
    mapObject->mFlags |= gParkMapObjectFourthFlag;
    if (mapObject->mCollisionSlotIndex != -1) {
        DisableCollisionSlot(mapObject->mCollisionSlotIndex);
    }
    mapObject->mFlags |= gParkMapObjectLastFlag;
}

// Brings a parked map object back: restores the low flag nibble from the high one, sets mUnk_66 to 0x1f unless the
// restored flags contain 2, enables its collision slot if it has one and clears the parked bit 0x100.
void UnparkMapObject(MapObject *mapObject) {
    mapObject->mFlags &= ~MAP_OBJECT_FLAGS_LOW_NIBBLE;
    mapObject->mFlags |= (mapObject->mFlags & MAP_OBJECT_FLAGS_SAVED_NIBBLE) >> 12;
    if (!(mapObject->mFlags & MAP_OBJECT_FLAG_NO_VIEW_TEST)) {
        mapObject->mAlpha = MAP_OBJECT_ALPHA_MAX;
    }
    if (mapObject->mCollisionSlotIndex != -1) {
        EnableCollisionSlot(mapObject->mCollisionSlotIndex);
    }
    mapObject->mFlags &= ~MAP_OBJECT_FLAG_PARKED;
}

void SetRaceRandomPointers(void) {
    gMapObjectRandom = g_GlobalCO->mMode == MODE_WIFI ? &g_GlobalMV->mFixedSeedRandom : &g_GlobalMV->mRandom;
    gRaceRandom = &g_GlobalMV->mRandom;
}

RandomState64 *GetMapObjectRandom(void) {
    return gMapObjectRandom;
}

RandomState64 *GetRaceRandom(void) {
    return gRaceRandom;
}

const u16 gParkMapObjectFlag = 1;
const u16 gParkMapObjectLastFlag = 0x100;
const u16 gParkMapObjectFourthFlag = 4;
const u16 gParkMapObjectThirdFlag = 8;
const u16 gParkMapObjectSecondFlag = 2;
