#include "03/code_021cce78.h"
#include "03/code_021cca74.h"
#include "03/code_021cd000.h"
#include "03/code_021d1790.h"
#include "03/OamRanges.h"
#include "03/unk_021da000.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"
#include "03/code_021cd0d0.h"
#include "03/code_021d1000.h"
#include "03/code_021d250c.h"
#include "03/ExpHeap.h"
#include "03/code_021d3000.h"
#include "03/Tasks.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0214d018.h"
#include "code_0200eddc.h"

const u8 data_ov003_021d6634[4] = {0, 0x50, 0xf2, 1};

void func_ov003_021cd080(Unk021425e8 *a) {
    if (a->mResultCode == 0 && *((u8 *) data_ov003_021da26c + 0x1e48) == 0 && a->mCommand == 0x26) {
        switch (a->field8_0) {
            case 5:
                func_ov003_021ccf30((Unk021ccf30 *) a);
                func_ov003_021cd190();
                break;
            case 4:
                func_ov003_021cd190();
                break;
            default:
                OS_Terminate();
                break;
        }
    }
}

void func_ov003_021ccf30(Unk021ccf30 *a) {
    Unk021ccf30_1300 *v1 = data_ov003_021da26c->field1300;
    s32 i;
    s32 j;
    DC_InvalidateRange(data_ov003_021da26c->fieldF00, 0x400);
    for (i = 0; i < a->fieldE; i++) {
        Unk021ccf30_10 *p = a->field10[i];
        if (p->fieldC[0] != 0 && p->field3C == 0) {
            Unk021ccf30_1300 *e;
            Unk021ccf30_1300 *q;
            j = 0;
            e = v1;
            for (; j < 0x14; j++) {
                if (memcmp(p->field4, e->field20, 6) == 0) {
                    break;
                }
                e++;
            }
            if (j == 0x14) {
                j = 0;
                e = v1;
                for (; j < 0x14; j++) {
                    if (memcmp(e->field20, data_ov003_021d6638, 6) == 0) {
                        break;
                    }
                    e++;
                }
                if (j == 0x14) {
                    return;
                }
            }
            q = &v1[j];
            MI_CpuCopy8(p->field4, q->field20, 6);
            MI_CpuCopy8(p->fieldC, q, 0x20);
            q->field26 = a->field50[i];
            if ((p->field2C & 0x10) == 0) {
                q->field28 = 0;
            } else {
                WMOtherElements v2;
                s32 k;
                s32 n;
                q->field28 = 1;
                v2 = WM_GetOtherElements((const u16 *) p);
                k = 0;
                n = v2.field0;
                for (; k < n; k++) {
                    if (v2.field4[k].field0 == 0x30) {
                        q->field28 = 2;
                        break;
                    }
                    if (v2.field4[k].field0 == 0xdd && v2.field4[k].field1 >= 4 &&
                        memcmp(v2.field4[k].field4, data_ov003_021d6634, 4) == 0) {
                        q->field28 = 2;
                        break;
                    }
                }
            }
        }
    }
}

void func_ov003_021ccea4(u32 a, u32 b, u16 c, u16 d, u32 e) {
    (data_ov003_021da268 = AllocZeroedExpHeapBlock(0x20, 4))->field1B = a;
    data_ov003_021da268->field19 = b;
    data_ov003_021da268->mOffset = e;
    SetPosition(c, d, &data_ov003_021da268->mX);
    data_ov003_021da268->mResource = CreateOamRangeFromNceImage(0, data_ov003_021d662c[a], 1);
    SetOamRangePosition(data_ov003_021da268->mResource, -1, c, d + e);
    func_ov003_021d1790(data_ov003_021da268->mResource, -1, 1);
    data_ov003_021da268->fieldC = AddTask(0, func_ov003_021ccd18, NULL, 0x80);
}

void func_ov003_021cce78(void) {
    RemoveTaskEntryWrapper(0, data_ov003_021da268->fieldC);
    DeleteOamRange(data_ov003_021da268->mResource);
    FreeExpHeapBlockAndClearPointer(&data_ov003_021da268);
}
