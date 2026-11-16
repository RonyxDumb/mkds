#include "Main/MapObjects/dram_draw_list_initial.h"
#include "Main/Item/dram_box.h"
#include "Main/MapObjects/dram.h"

const MapObjectDrawList gDramDrawListInitial = {
    {NULL, 0, {0, 0}, (void (*)(MapObjectList *)) CreateDram, NULL, DrawDram, NULL, 1, NULL, 0, NULL}, 0};