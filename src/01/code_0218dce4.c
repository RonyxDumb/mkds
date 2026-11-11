#include "01/code_0218dce4.h"

#include "01/code_02185ef4.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_02188000.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209bef0.h"

void HanachanItemHitCallback(Unk02188950 *mapObject) {
    mapObject->mUnk_2e0 = 0;
    SetItemCollisionCallback(mapObject, HanachanItemHitCallback);
}

void HanachanFirstSoundCallback(Unk02188950 *mapObject) {
    if (GetAbsoluteCounter(mapObject) >= 2) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x248);
    } else if (GetAbsoluteCounter(mapObject) >= 1) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x249);
    } else {
        StartMapObjectSound(&mapObject->mUnk_000, 0x24a);
    }
}

void HanachanSecondSoundCallback(Unk02188950 *mapObject) {
    if (GetAbsoluteCounter(mapObject) >= 2) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x248);
    } else if (GetAbsoluteCounter(mapObject) >= 1) {
        StartMapObjectSound(&mapObject->mUnk_000, 0x249);
    } else {
        StartMapObjectSound(&mapObject->mUnk_000, 0x24a);
    }
}

void SetHanachanSoundCallbacks(Unk02188950 *mapObject) {
    SetTwoAnimationFrameCallbacks(mapObject, 0xc, HanachanFirstSoundCallback, 0x20, HanachanSecondSoundCallback);
}
