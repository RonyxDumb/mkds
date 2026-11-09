#include "Main/Unknown/code_020ed578.h"
#include "Main/Unknown/code_020e66e4.h"

#include "Main/Unknown/code_020ed588.h"
#include "Main/Unknown/code_020f36d8.h"

void DrawItemModelAtObjectPos(ItemObject *item, NsbmdModel *model) {
    QueueNsbmdModelMaterial(model);
    DrawNsbmdModelWithMaxAlpha(model, &item->mPos, 1, 0x1f);
}

NsbmdModel *GetItemModel(u32 kind) {
    return gItemModels[kind];
}
