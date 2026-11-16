#include "Main/Unknown/code_020e6f58.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"

#include "Main/Unknown/code_020d6000.h"

#pragma thumb on
// While still unset, also fills the list's words 0x18 to 0x20.
void mobj_logicPartAddInstance(MapObjectList *p, MapObject *q) {
    u16 n;
    MapObjectKindData *t;

    n = p->mMapObjectCount;
    p->mMapObjectCount = n + 1;
    p->mMapObjects[n] = q;
    if (p->field18 == 3) {
        t = q->mKindData;
        p->field18 = t->field20;
    }
    if (p->field1C == NULL) {
        t = q->mKindData;
        p->field1C = t->field4;
    }
    if (p->field20 == 3) {
        p->field20 = mobj_getItemHitObjResponseForMObj(6, q);
    }
}
#pragma thumb off
