#include "01/code_0218b298.h"
#include "01/code_02188218.h"

#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/MapObjects/map_object_sound.h"

u16 GetAbsoluteCounterWrapper(MissionRunMapObject *mapObject) {
    return GetAbsoluteCounter(mapObject);
}

void BombKingJumpKartCollisionCallback(MissionRunMapObject *mapObject) {
    mapObject->mUnk_2d8 = 0xb;
    mapObject->mUnk_000.mDistanceSquaredAndFlags |= gBombKingSkipKindSoundFlag;
}

void BombKingFirstSoundCallback(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x237);
}

void BombKingSecondSoundCallback(MissionRunMapObject *mapObject) {
    StartMapObjectSound(&mapObject->mUnk_000, 0x237);
}
