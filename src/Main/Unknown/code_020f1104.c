#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f1104.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"

void func_020f1150(ItemKouraR *item, int kartIndex) {
    item->mKartItems = &gKartItems[kartIndex];
    item->mUnk_22c.x = 0;
    item->mUnk_22c.y = 0;
    item->mUnk_22c.z = 0;
    item->mUnk_238 = 0;
}

void SetItemKouraRKartItems(ItemKouraR *item, int kartIndex) {
    item->mKartItems = &gKartItems[kartIndex];
    item->mUnk_238 = 0;
}

void func_020f1104(ItemKouraR *item) {
    VEC_Add(&item->mUnk_22c, &item->mUnk_000.mUnk_000.mUnk_000.mVelocity, &item->mUnk_000.mUnk_000.mUnk_000.mVelocity);
    func_020f29e8(item);
}
