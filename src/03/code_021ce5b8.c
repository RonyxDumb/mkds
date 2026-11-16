#include "03/code_021ce5b8.h"
#include "03/unk_021d6000.h"

#include "03/code_021ce000.h"
#include "03/unk_021da000.h"
#include "code_02142eac.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "03/Tasks.h"
#include "03/ExpHeap.h"
#include "code_0200f5ac.h"
#include "registers.h"
#include "03/code_021ce110.h"

const u8 data_ov003_021d66c4[9] = "NWCUSBAP";
const Unk021d66d0 data_ov003_021d66d0 = {{0, 0x3fff0400, 0xffff0000, 0xffffffff, 0x200002, 0, 0, 0, 0, 0, 0, 0, 0, 8}};

u32 func_ov003_021ce920(void (*a)(u32)) {
    Unk021da280 *d;
    Unk0200fddc s;
    u64 t;

    data_ov003_021da280 = AllocZeroedExpHeapBlock(0x1ba0, 0x20);
    data_ov003_021da280->field1370 = a;
    d = data_ov003_021da280;
    t = OS_GetTick();
    d->field1B74 = t;
    d->field1B78 = t >> 32;
    if (WM_Initialize(d, func_ov003_021ce7c0, 3) == 2) {
        do {
            WM_ReadStatus(&data_ov003_021da280->field13B8);
        } while (data_ov003_021da280->field13B8.mState != 2);
        d = data_ov003_021da280;
        *(Unk021d66d0 *) &d->field1374 = data_ov003_021d66d0;
        d->field1374.field0 = d->fieldF00;
        data_ov003_021da280->field1374.field8 = WM_GetDispersionScanPeriod();
        OS_GetOwnerInfo(&s);
        MI_CpuCopy8(data_ov003_021d66c4, &data_ov003_021da280->field1374.field14[0], 8);
        data_ov003_021da280->field1374.field14[9] = 1;
        MI_CpuCopy8(s.field4, &data_ov003_021da280->field1374.field14[0xc], s.field18 * 2);
        if (func_ov003_021ce8ec() != 0) {
            data_ov003_021da280->field1B7C = AddTask(0, func_ov003_021ce4d4, NULL, 0x78);
            return 1;
        }
    }
    FreeExpHeapBlockAndClearPointer(&data_ov003_021da280);
    return 0;
}

u32 func_ov003_021ce8ec(void) {
    int v1;
    v1 = WM_StartScanEx(func_ov003_021ce7c0, &data_ov003_021da280->field1374);
    if (v1 == 2) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021ce848(void) {
    Unk021da280 *d;

    data_ov003_021da280->field1B80 = 1;
    WM_ReadStatus(&data_ov003_021da280->field13B8);
    if (data_ov003_021da280->field13B8.mState != 2) {
        if (WM_Reset(func_ov003_021ce7c0) != 2) {
            return 0;
        }
        do {
            WM_ReadStatus(&data_ov003_021da280->field13B8);
        } while (data_ov003_021da280->field13B8.mState != 2);
    }
    if (WM_End(func_ov003_021ce7c0) != 2) {
        return 0;
    }
    d = data_ov003_021da280;
    if (d->field1B7C != 0) {
        RemoveTaskEntryWrapper(0, d->field1B7C);
    }
    d = data_ov003_021da280;
    while (*(vu8 *) &d->field1B80 != 2) {
    }
    FreeExpHeapBlockAndClearPointer(&data_ov003_021da280);
    return 1;
}

void func_ov003_021ce834(u32 a) {
    data_ov003_021da280->field1370 = (void (*)(u32)) a;
}

void func_ov003_021ce7c0(Unk021425e8 *a) {
    Unk021da280 *d;

    if (a->mResultCode != 0) {
        return;
    }
    d = data_ov003_021da280;
    if (d->field1B80 != 0) {
        if (a->mCommand == 2) {
            d->field1B80 = 2;
        }
        return;
    }
    if (a->mCommand != 0x26) {
        return;
    }
    switch (a->field8_0) {
        case 5:
            if (d->field1B82 != 0) {
                func_ov003_021ce5b8((Unk021ce5b8 *) a);
            } else {
                func_ov003_021ce6ac((Unk021ce5b8 *) a);
            }
            func_ov003_021ce8ec();
            break;
        case 4:
            func_ov003_021ce8ec();
            break;
        default:
            OS_Terminate();
            break;
    }
}

void func_ov003_021ce6ac(Unk021ce5b8 *a) {
    s32 i;

    for (i = 0; i < a->fieldE; i++) {
        Unk021ce5b8_10 *e;
        s32 j;
        u8 *p;
        u8 *q;
        s32 k;
        Unk021da280 *d;

        e = a->field10[i];
        DC_InvalidateRange(e, 0xc0);
        if (memcmp(e->fieldC, data_ov003_021d66c4, 8) != 0) {
            continue;
        }
        j = 0;
        d = data_ov003_021da280;
        p = d->field1300[0].field0;
        for (; j < 16; j++) {
            if (memcmp(e->field4, p, 6) == 0) {
                if (d->field1300[j].field6 != 0) {
                    goto next;
                }
                if ((e->field15 & 1) == 0) {
                    goto next;
                }
                if (d->field1370 != NULL) {
                    d->field1370(1);
                }
                return;
            }
            p += 7;
        }
        k = 0;
        q = d->field1300[0].field0;
        for (; k < 16; k++) {
            if (memcmp(q, data_ov003_021d66bc, 6) == 0) {
                MI_CpuCopy8(e->field4, d->field1300[k].field0, 6);
                data_ov003_021da280->field1300[k].field6 = (e->field15 & 1) ? 1 : 0;
                goto next;
            }
            q += 7;
        }
    next:;
    }
}

void func_ov003_021ce5b8(Unk021ce5b8 *a) {
    s32 i;
    Unk021da280 *q;
    s32 n;
    Unk021da280 *d;

    d = data_ov003_021da280;
    if (d->field1B81 != 0) {
        if (d->field1370 != NULL) {
            d->field1370(d->field1B81);
        }
        return;
    }
    DC_InvalidateRange(d->fieldF00, 0x400);
    i = 0;
    n = a->fieldE;
    if (n > 0) {
        q = data_ov003_021da280;
        do {
            s32 j;
            u8 *p;
            Unk021ce5b8_10 *e;

            e = a->field10[i];
            if (memcmp(e->fieldC, data_ov003_021d66c4, 8) != 0) {
                continue;
            }
            if ((e->field15 & 1) == 0) {
                continue;
            }
            for (j = 0, p = q->field1300[0].field0; j < 16; j++) {
                if (memcmp(e->field4, p, 6) == 0) {
                    if (q->field1300[j].field6 != 0) {
                        break;
                    }
                    if (q->field1370 != NULL) {
                        q->field1370(1);
                        return;
                    }
                    q->field1B81 = 1;
                    return;
                }
                p += 7;
            }
        } while (++i < n);
    }
}
