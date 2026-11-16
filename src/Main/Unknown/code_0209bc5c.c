#include "Main/Unknown/code_0209bc5c.h"

void *mobj_getInstanceByIdx(MapObjectList *list, s32 index) {
    return mobj_logicPartGetInstanceList(list)[index];
}
