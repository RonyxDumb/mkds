#include "01/code_0218b298.h"
#include "01/code_02188218.h"

#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d275c.h"

u16 GetAbsoluteCounterWrapper(Unk02188950 *mapObject) {
    return GetAbsoluteCounter(mapObject);
}

void BombKingJumpKartCollisionCallback(Unk02188950 *mapObject) {
    mapObject->mUnk_2d8 = 0xb;
    mapObject->mUnk_000.mDistanceSquaredAndFlags |= gBombKingSkipKindSoundFlag;
}

void BombKingFirstSoundCallback(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x237);
}

void BombKingSecondSoundCallback(Unk02188950 *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x237);
}
