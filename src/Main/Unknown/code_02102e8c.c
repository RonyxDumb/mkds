#include "Main/Unknown/code_02102e8c.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02102eb8.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_020ed5c0.h"

u32 InitItemGesso(ItemInUse *itemInUse, ItemGesso *gesso) {
    Kart *kart = itemInUse->mKart;
    u32 v4 = SetupItemGesso(gesso, 0x0u);
    func_020f8e3c(kart, 0xf2u);
    return 0x1u;
}
