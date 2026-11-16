#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_020e6fd4.h"

void **mobj_logicPartGetInstanceList(MapObjectList *list) {
    return list->mMapObjects;
}

void *mobj_renderPartGetInstanceList(MapObjectList *list) {
    return list->mMapObjects;
}
