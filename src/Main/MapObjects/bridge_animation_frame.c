#include "Main/MapObjects/bridge_animation_frame.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/MapObjects/choropu.h"
#include "Main/MapObjects/bridge.h" // Bridge

u32 GetFirstBridgeAnimationFrame(void) {
    Bridge *firstBridge = gBridgeDrawList->mMapObjectList.mMapObjects[0];

    return FROM_FIXED12(firstBridge->mAnimationFrameIndex);
}
