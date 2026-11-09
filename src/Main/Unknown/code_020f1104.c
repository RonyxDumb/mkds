#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f1104.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"

void SetItemKouraRKartItemsAndClearTowardKartVelocity(ItemKouraR *item, int kartIndex) {
    item->mKartItems = &gKartItems[kartIndex];
    item->mTowardKartVelocity.x = 0;
    item->mTowardKartVelocity.y = 0;
    item->mTowardKartVelocity.z = 0;
    item->mNearKartFrames = 0;
}

void SetItemKouraRKartItems(ItemKouraR *item, int kartIndex) {
    item->mKartItems = &gKartItems[kartIndex];
    item->mNearKartFrames = 0;
}

void AddItemKouraRTowardKartToVelocity(ItemKouraR *item) {
    VEC_Add(&item->mTowardKartVelocity, &item->mUnk_000.mUnk_000.mUnk_000.mVelocity,
            &item->mUnk_000.mUnk_000.mUnk_000.mVelocity);
    SetItemObjectDirectionFromVelocity(item);
}
