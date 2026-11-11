#include "Main/Unknown/code_020e3b08.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_020e3618.h" // Bridge

u32 GetFirstBridgeAnimationFrame(void) {
    Bridge *firstBridge = gBridgeDrawList->mMapObjectList.mMapObjects[0];

    return FROM_FIXED12(firstBridge->mAnimationFrameIndex);
}
