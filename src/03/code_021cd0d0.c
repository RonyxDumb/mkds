#include "03/code_021cd0d0.h"
#include "03/unk_021d6000.h"
#include "string.h"
#include "code_02134398.h"
#include "03/code_021cd000.h"

#include "03/types_021da26c.h"
#include "03/code_021cce78.h"
#include "code_02142eac.h"
#include "code_0214cfe4.h"
#include "03/ExpHeap.h"
#include "03/unk_021da000.h"

const Unk021da26c_1648 data_ov003_021d6640 = {{NULL, 0x400, 0x3fff, 0, {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, 0, 0, {0}, 0}, {0}};

void func_ov003_021cd2a4(void) {
    if (data_ov003_021da26c == NULL) {
        data_ov003_021da26c = AllocZeroedExpHeapBlock(0x1e60, 32);
    }
}

void func_ov003_021cd27c(void) {
    if (data_ov003_021da26c != NULL) {
        while (WM_GetAllowedChannel() != 0x8000) {
        }
        FreeExpHeapBlockAndClearPointer(&data_ov003_021da26c);
    }
}

u32 func_ov003_021cd1c4(void) {
    Unk021da26c *p;
    // volatile: the only spelling found that stores and reloads the argument on the stack.
    volatile u16 a = 0;
    MIi_CpuClear16(a, data_ov003_021da26c->field1300, 0x348);
    if (WM_Initialize(data_ov003_021da26c, func_ov003_021cd080, 3) != 2) {
        return 0;
    }
    do {
        WM_ReadStatus(&data_ov003_021da26c->field168C);
    } while (data_ov003_021da26c->field168C.mState != 2);
    p = data_ov003_021da26c;
    p->field1648 = data_ov003_021d6640;
    p->field1648.field0.field0 = p->fieldF00;
    data_ov003_021da26c->field1648.field0.field8 = WM_GetDispersionScanPeriod();
    if (func_ov003_021cd190() != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021cd190(void) {
    int v1;
    v1 = WM_StartScanEx(func_ov003_021cd080, &data_ov003_021da26c->field1648.field0);
    if (v1 == 2) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021cd118(void) {
    data_ov003_021da26c->field1E48 = 1;
    WM_ReadStatus(&data_ov003_021da26c->field168C);
    if (data_ov003_021da26c->field168C.mState != 2) {
        if (WM_Reset(func_ov003_021cd080) != 2) {
            return 0;
        }
        do {
            WM_ReadStatus(&data_ov003_021da26c->field168C);
        } while (data_ov003_021da26c->field168C.mState != 2);
    }
    if (WM_End(func_ov003_021cd080) != 2) {
        return 0;
    }
    return 1;
}

int func_ov003_021cd0d0(int *a) {
    int v1;
    int v2;
    int v3;
    int v4;
    v2 = 0;
    *a = (s32) data_ov003_021da26c->field1300;
    v1 = 0;
    v3 = *a;
    do {
        v4 = memcmp((const u8 *) (v3 + 0x20), data_ov003_021d6638, 6);
        if (v4 != 0) {
            v2 = v2 + 1;
        }
        v3 = v3 + 0x2a;
        v1 = v1 + 1;
    } while (v1 < 0x14);
    return v2;
}
