#include "01/code_0218b034.h"
#include "01/code_02185ef4.h"
#include "01/code_02187bfc.h"
#include "01/code_02187c4c.h"
#include "01/code_02187d14.h"
#include "01/code_02188218.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/MapObjects/map_object_sound.h"
#include "Main/Item/item_bomb.h"
#include "code_02147cd8.h"

void ThrowStoredItemBomb(MissionRunMapObject *mapObject) {
    Vec3 velocity;

    if (IsItemBombStored(mapObject)) {
        velocity.x = (MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_134, FX_SinIdx((u16) mapObject->mMoveAngle)));
        velocity.y = mapObject->mPrm->mUnk_138;
        velocity.z = (MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_134, FX_CosIdx((u16) mapObject->mMoveAngle)));
        ThrowOrReleaseStoredItemBomb(mapObject, &velocity, mapObject->mPrm->mUnk_13c);
    }
}

void ThrowItemBombsInRing(MissionRunMapObject *mapObject) {
    RandomState64 *rng;
    s32 angle;
    s32 i;
    Vec3 pos;

    rng = GetMapObjectRandom();
    rng->mValue = (s64) rng->mMultiplier * (s64) rng->mValue + rng->mIncrement;
    angle = (u16) (((rng->mValue >> 32) << 16) >> 32);
    for (i = 0; i < 3; i++) {
        Vec3 vel = {0, 0, 0};
        angle += 0x5555;
        if (GetAbsoluteCounter(mapObject) == 0) {
            pos.x =
                mapObject->mUnk_000.mPos.x + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_14c, SIN_OF_ANGLE((u16) angle));
            pos.y = mapObject->mUnk_000.mPos.y + mapObject->mPrm->mUnk_150;
            pos.z =
                mapObject->mUnk_000.mPos.z + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_14c, COS_OF_ANGLE((u16) angle));
        } else {
            pos.x =
                mapObject->mUnk_000.mPos.x + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_154, SIN_OF_ANGLE((u16) angle));
            pos.y = mapObject->mUnk_000.mPos.y + mapObject->mPrm->mUnk_158;
            pos.z =
                mapObject->mUnk_000.mPos.z + MUL_FIXED12_NO_ROUND(mapObject->mPrm->mUnk_154, COS_OF_ANGLE((u16) angle));
        }
        if (i == 0) {
            ThrowItemBombFromPosition(StartItemBomb(), &pos, &vel, mapObject->mPrm->mUnk_15c);
        } else {
            ThrowItemBombFromPosition(StartItemBombWithParkedItemBox(9), &pos, &vel, mapObject->mPrm->mUnk_160);
        }
    }
    StartEffectAtRowHeight(mapObject, 0x2000, 0, 0x3ae, 0x410, 0);
    StartMapObjectSound(&mapObject->mUnk_000, 0x236);
}
