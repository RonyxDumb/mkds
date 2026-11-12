#include "01/code_02187bfc.h"

#include "Main/Graphics/effects.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Item/item_bomb.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_02147000.h"

void ThrowOrReleaseStoredItemBomb(MissionRunMapObject *mapObject, Vec3 *velocity, s32 timer) {
    Vec3 zeroVelocity;
    s32 *zeroWords;

    if (mapObject->mItemBomb != NULL) {
        if (((ItemBomb *) mapObject->mItemBomb)->mBouncingItemObject.mItemObject.mPos.y < 0x64000) {
            ReleaseItemBomb(&mapObject->mItemBomb);
        } else if (velocity != NULL) {
            ThrowItemBombFromSlot(&mapObject->mItemBomb, velocity, timer);
        } else {
            zeroWords = (s32 *) &zeroVelocity;
            zeroWords[0] = 0;
            zeroWords[1] = 0;
            zeroWords[2] = 0;
            ThrowItemBombFromSlot(&mapObject->mItemBomb, &zeroVelocity, timer);
        }
    }
}
