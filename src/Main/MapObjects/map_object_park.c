#include "Main/MapObjects/map_object_park.h"

#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/rock.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"

struct RandomState64 *gMapObjectRandom;
struct RandomState64 *gRaceRandom;

// Puts a pooled map object aside: saves the low flag nibble in the high nibble, sets flags 1, 2, 8 and 4 (the update
// walk skips flag 4) and the parked bit 0x100, and disables its collision slot if it has one.
void ParkMapObject(MapObject *mapObject) {
    mapObject->mFlags &= ~0xf000;
    mapObject->mFlags |= (mapObject->mFlags & 0xf) << 12;
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
    mapObject->mFlags &= ~0xf;
    mapObject->mFlags |= (mapObject->mFlags & 0xf000) >> 12;
    if (!(mapObject->mFlags & 2)) {
        mapObject->mAlpha = 0x1f;
    }
    if (mapObject->mCollisionSlotIndex != -1) {
        EnableCollisionSlot(mapObject->mCollisionSlotIndex);
    }
    mapObject->mFlags &= ~0x100;
}

void SetRaceRandomPointers(void) {
    gMapObjectRandom = gRaceSetup->mMode == MODE_WIFI ? &gRaceProgress->mFixedSeedRandom : &gRaceProgress->mRandom;
    gRaceRandom = &gRaceProgress->mRandom;
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
