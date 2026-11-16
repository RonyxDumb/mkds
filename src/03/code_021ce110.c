#include "03/code_021ce110.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1790.h"
#include "03/OamRanges.h"
#include "03/unk_021da000.h"
#include "03/code_021cdcb8.h"
#include "03/code_021d1000.h"
#include "03/Tasks.h"
#include "03/code_021d1770.h"
#include "03/code_021d1970.h"
#include "03/ExpHeap.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0200f5ac.h"
#include "03/unk_021d6000.h"

void func_ov003_021ce4d4(u32 a) {
    u32 f;
    Unk021ce4d4 *o;
    u32 g;
    s32 i;
    u64 t = OS_GetTick();
    o = (Unk021ce4d4 *) data_ov003_021da280;
    if (t >= *(u64 *) o->field1B74 + 0x17f898) {
        g = 0;
        f = 0;
        for (i = 0; i < 0x10; i++) {
            if (memcmp(o->field1300[i].field0, data_ov003_021d66bc, 6) != 0) {
                if (o->field1300[i].field6 != 0) {
                    f = 1;
                } else {
                    g = 1;
                }
            }
        }
        if (f != 0 && g != 0) {
            if (o->field1370 != NULL) {
                o->field1370(2);
            }
        } else if (f != 0) {
            if (o->field1370 != NULL) {
                o->field1370(1);
            }
        } else if (g == 0) {
            if (o->field1370 != NULL) {
                o->field1370(0);
            }
        }
        ((Unk021ce4d4 *) data_ov003_021da280)->field1B7C = 0;
        ((Unk021ce4d4 *) data_ov003_021da280)->field1B82 = 1;
        RequestTaskRemoval(0, a);
    }
}

void func_ov003_021ce408(u32 a) {
    s32 i;
    data_ov003_021da27c = AllocZeroedExpHeapBlock(0x1c, 4);
    for (i = 0; i < 5; i++) {
        data_ov003_021da27c->field0[i] = CreateOamRangeFromNceImage(1, data_ov003_021d6688[a][i], 1);
        func_ov003_021d1790(data_ov003_021da27c->field0[i], -1, 0);
        SetOamRangePosition(data_ov003_021da27c->field0[i], -1, -0x2a, data_ov003_021d66a8[i].field2);
        func_ov003_021d1890(data_ov003_021da27c->field0[i], -1, 0, data_ov003_021d6698[a][i]);
    }
    data_ov003_021da27c->mTask = AddTask(0, func_ov003_021ce370, NULL, 0x78);
    func_ov003_021cdcf0(a);
    StartSoundSeq(0xd);
}

void func_ov003_021ce370(TaskEntry *a) {
    s32 i;
    s32 w;
    s32 h;
    GetOamRangeEntryPosition(data_ov003_021da27c->field0[0], 0, (u32 *) &w, &h);
    w += 8;
    if (w < data_ov003_021d66a8[0].field0 || w > 0x100) {
        for (i = 0; i < 5; i++) {
            SetOamRangePosition(data_ov003_021da27c->field0[i], -1, w, data_ov003_021d66a8[i].field2);
        }
        return;
    }
    w = data_ov003_021d66a8[0].field0;
    for (i = 0; i < 5; i++) {
        SetOamRangePosition(data_ov003_021da27c->field0[i], -1, w, data_ov003_021d66a8[i].field2);
    }
    SetTaskCallback(a, func_ov003_021ce2d0);
}

void func_ov003_021ce2d0(TaskEntry *a) {
    s32 i;
    s32 w;
    s32 h;
    GetOamRangeEntryPosition(data_ov003_021da27c->field0[1], 0, (u32 *) &w, &h);
    w += 8;
    if (w < data_ov003_021d66a8[1].field0 || w > 0x100) {
        for (i = 1; i < 5; i++) {
            SetOamRangePosition(data_ov003_021da27c->field0[i], -1, w, data_ov003_021d66a8[i].field2);
        }
        return;
    }
    w = data_ov003_021d66a8[1].field0;
    for (i = 1; i < 5; i++) {
        SetOamRangePosition(data_ov003_021da27c->field0[i], -1, w, data_ov003_021d66a8[i].field2);
    }
    SetTaskCallback(a, func_ov003_021ce230);
}

void func_ov003_021ce230(TaskEntry *a) {
    s32 i;
    s32 w;
    s32 h;
    GetOamRangeEntryPosition(data_ov003_021da27c->field0[2], 0, (u32 *) &w, &h);
    w += 8;
    if (w < data_ov003_021d66a8[2].field0 || w > 0x100) {
        for (i = 2; i < 5; i++) {
            SetOamRangePosition(data_ov003_021da27c->field0[i], -1, w, data_ov003_021d66a8[i].field2);
        }
        return;
    }
    w = data_ov003_021d66a8[2].field0;
    for (i = 2; i < 5; i++) {
        SetOamRangePosition(data_ov003_021da27c->field0[i], -1, w, data_ov003_021d66a8[i].field2);
    }
    SetTaskCallback(a, func_ov003_021ce190);
}

void func_ov003_021ce190(TaskEntry *a) {
    s32 i;
    s32 w;
    s32 h;
    GetOamRangeEntryPosition(data_ov003_021da27c->field0[3], 0, (u32 *) &w, &h);
    w += 8;
    if (w < data_ov003_021d66a8[3].field0 || w > 0x100) {
        for (i = 3; i < 5; i++) {
            SetOamRangePosition(data_ov003_021da27c->field0[i], -1, w, data_ov003_021d66a8[i].field2);
        }
        return;
    }
    w = data_ov003_021d66a8[3].field0;
    for (i = 3; i < 5; i++) {
        SetOamRangePosition(data_ov003_021da27c->field0[i], -1, w, data_ov003_021d66a8[i].field2);
    }
    SetTaskCallback(a, func_ov003_021ce110);
}

void func_ov003_021ce110(TaskEntry *a) {
    s32 i;
    s32 w;
    s32 h;
    GetOamRangeEntryPosition(data_ov003_021da27c->field0[4], 0, (u32 *) &w, &h);
    w += 8;
    if (w < data_ov003_021d66a8[4].field0 || w > 0x100) {
        for (i = 4; i < 5; i++) {
            SetOamRangePosition(data_ov003_021da27c->field0[i], -1, w, data_ov003_021d66a8[i].field2);
        }
        return;
    }
    w = data_ov003_021d66a8[4].field0;
    for (i = 4; i < 5; i++) {
        SetOamRangePosition(data_ov003_021da27c->field0[i], -1, w, data_ov003_021d66a8[i].field2);
    }
    SetTaskCallback(a, func_ov003_021ce0f0);
}
