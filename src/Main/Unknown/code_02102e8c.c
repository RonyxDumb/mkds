#include "Main/Unknown/code_02102e8c.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02102eb8.h"

u32 InitItemGesso(Unk02101d18 *itemInUse, u32 gesso) {
    Kart *kart = itemInUse->mUnk_10;
    u32 v4 = SetupItemGesso(gesso, 0x0u);
    func_020f8e3c(kart, 0xf2u);
    return 0x1u;
}
