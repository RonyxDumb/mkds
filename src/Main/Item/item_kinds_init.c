#include "Main/Item/item_kinds_init.h"
#include "Main/Item/item_kinds.h"

#pragma thumb on

void InitItemKinds(void) {
    CreateItemKinds();
    ComputeItemKindObjectCounts();
}

#pragma thumb off
