#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020e6fd4.h"

#pragma thumb on

void mobj_logicPartSetThisPointer(void *listSlot) {
    (*(MapObjectList **) listSlot)->mUnk_24 = listSlot;
}

#pragma thumb off
