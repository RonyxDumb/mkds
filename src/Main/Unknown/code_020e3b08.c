#include "Main/Unknown/code_020e3b08.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e0680.h"

u32 GetFirstBridgeAnimationFrame(void) {
    Unk020e3ef4 *firstBridge = gBridgeDrawList->mMapObjectList.mMapObjects[0];

    return firstBridge->mUnk_154 >> 12;
}
