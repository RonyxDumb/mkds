#include "Main/MapObjects/bridge_animation_frame.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/bridge.h" // Bridge
#include "Main/MapObjects/rotary.h"

const MapObjectList gBridgeUpdateListData = {NULL, 0, {0, 0}, NULL, NULL, UpdateBridge, NULL, 0, NULL, 0, NULL};
const BridgeDrawList gBridgeDrawListData = {{NULL, 0, {0, 0}, (void (*)(MapObjectList *)) CreateBridge, NULL, NULL, NULL, 1, NULL, 0, NULL}, 0, 0};
const MapObjectKindData gBridgeKindData = {NULL, NULL, 5, 0x5a000, 0x1e000, 0x15e000, NULL, 1, 0, 0, 0, 0, 0, 0, 0, 0};

u32 GetFirstBridgeAnimationFrame(void) {
    Bridge *firstBridge = gBridgeDrawList->mMapObjectList.mMapObjects[0];

    return FROM_FIXED12(firstBridge->mAnimationFrameIndex);
}
