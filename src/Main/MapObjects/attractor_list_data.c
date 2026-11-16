#include "Main/MapObjects/attractor_list_data.h"
#include "Main/MapObjects/attractor.h"

const MapObjectList gAttractorUpdateListData = {
    NULL, 0, {0, 0}, (void (*)(MapObjectList *)) BuildAttractorTables, NULL, NULL, NULL, 0, NULL, 0, NULL};
const MapObjectKindData gAttractorKindData = {NULL, NULL, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, 0, 0, 0, 0};
