#include "Main/Item/item_f_box_park.h"
#include "Main/Unknown/code_021053d8.h"
#include "Main/Item/dram_box.h"

void ParkItemFBoxMapObject(ItemFBox *fbox) {
    ParkPooledMapObject(fbox->mPooledMapObject);
}
