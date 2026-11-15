#include "Main/Item/item_model.h"
#include "Main/MapObjects/nsbmd_model_draw_variants.h"

#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Item/item_link_following.h"

void DrawItemModelAtObjectPos(ItemObject *item, NsbmdModel *model) {
    QueueNsbmdModelMaterial(model);
    DrawNsbmdModelWithMaxAlpha(model, &item->mPos, 1, 0x1f);
}

NsbmdModel *GetItemModel(u32 kind) {
    return gItemModels[kind];
}
