#include "Main/Item/item_f_box_park.h"
#include "Main/Item/pooled_map_object.h"
#include "Main/Item/dram_box.h"

void ParkItemFBoxMapObject(ItemFBox *fbox) {
    ParkPooledMapObject(fbox->mPooledMapObject);
}
