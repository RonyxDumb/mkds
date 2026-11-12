#include "Main/Item/item_model.h"
#include "Main/MapObjects/code_020e66e4.h"

#include "Main/Race/data_020f36d8.h"

void DrawItemModelAtObjectPos(ItemObject *item, NsbmdModel *model) {
    QueueNsbmdModelMaterial(model);
    DrawNsbmdModelWithMaxAlpha(model, &item->mPos, 1, 0x1f);
}

NsbmdModel *GetItemModel(u32 kind) {
    return gItemModels[kind];
}
