#include "03/code_021cea3c.h"

#include "03/unk_021d6000.h"
#include "03/code_021ce5b8.h"
#include "03/OamRanges.h"
#include "03/unk_021da000.h"
#include "03/code_021ce000.h"
#include "03/code_021d1770.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/TextCanvas.h"
#include "03/ExpHeap.h"
#include "03/Tasks.h"
#include "code_0214a348.h"
#include "registers.h"
#include "03/code_021d1790.h"
#include "03/code_021d1c18.h"
#include "03/code_021d1970.h"
#include "03/code_021d250c.h"
#include "03/Input.h"
#include "03/types_021d299c.h"

int func_ov003_021cef80(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_ov003_021da284;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 27u;
    value0 = *(const s8 *) ((value1) + (value0));
    return value0;
}

u32 func_ov003_021cef6c(void) {
    if (data_ov003_021da284 != NULL) {
        return 1;
    }
    return 0;
}

void func_ov003_021cef28(TaskEntry *a) {
    data_ov003_021da284->field1A--;
    G2x_ChangeBlendBrightness_(&reg_G2_BLDCNT, data_ov003_021da284->field1A);
    if (data_ov003_021da284->field1A <= -12) {
        SetTaskCallback(a, func_ov003_021cee98);
    }
}

void func_ov003_021cee98(u32 a) {
    u32 w;
    s32 h;

    GetOamRangeEntryPosition(data_ov003_021da284->field0, 0, &w, &h);
    h -= 0xc;
    if (h > data_ov003_021d6780[data_ov003_021da284->field1C][1]) {
        func_ov003_021cec50(h);
        return;
    }
    func_ov003_021cec50(data_ov003_021d6780[data_ov003_021da284->field1C][1]);
    if (data_ov003_021da284->field1C == 5) {
        data_ov003_021da284->field14 = AddTask(0, func_ov003_021ced78, NULL, 0x78);
    } else {
        data_ov003_021da284->field14 = AddTask(0, func_ov003_021cedbc, NULL, 0x78);
    }
    RequestTaskRemoval(1, a);
}

void func_ov003_021cedbc(void) {
    s32 i;
    s32 j;
    Rect v1;

    for (i = 0; i < data_ov003_021d6720[data_ov003_021da284->field1C]; i++) {
        ComputeRectFromOriginAndSize(
            data_ov003_021d67b0[data_ov003_021da284->field1C][data_ov003_021d6730[data_ov003_021da284->field1C][i]],
            data_ov003_021d6754[data_ov003_021da284->field1C], &v1);
        if (IsTouchPressedInRect(&v1) != 0) {
            data_ov003_021da284->field1B = i;
            break;
        }
    }
    if (AreKeysPressed(1) != 0) {
        data_ov003_021da284->field1B = data_ov003_021d673c[data_ov003_021da284->field1C][0];
    }
    if (AreKeysPressed(2) != 0) {
        data_ov003_021da284->field1B = data_ov003_021d673c[data_ov003_021da284->field1C][1];
    }
    for (j = 0; j < data_ov003_021d6720[data_ov003_021da284->field1C]; j++) {
        if (j == data_ov003_021da284->field1B) {
            func_ov003_021ceb80(j);
            return;
        }
    }
    data_ov003_021da284->field1B = -1;
}

void func_ov003_021ced78(u32 a) {
    data_ov003_021da284->field1B = -1;
    data_ov003_021da284->field18++;
    if (data_ov003_021da284->field18 >= 0x78) {
        RequestTaskRemoval(0, a);
        data_ov003_021da284->field14 = AddTask(1, func_ov003_021ceb54, NULL, 0x78);
    }
}

void func_ov003_021cec50(s32 a) {
    s32 i;
    u8 m;
    u16 v1[4];
    s32 x;
    s32 y;

    SetOamRangePosition(data_ov003_021da284->field0, -1, data_ov003_021d6780[data_ov003_021da284->field1C][0], a);
    SetOamRangePosition(data_ov003_021da284->field4, -1,
                        data_ov003_021d6714[0] + data_ov003_021d6780[data_ov003_021da284->field1C][0],
                        a + data_ov003_021d6714[1]);
    func_ov003_021cec00(data_ov003_021da284->field0, a);
    func_ov003_021cec00(data_ov003_021da284->field4, a);
    for (i = 0; i < data_ov003_021d6720[data_ov003_021da284->field1C]; i++) {
        SetOamRangePosition(
            data_ov003_021da284->field8[i], -1,
            data_ov003_021d67b0[data_ov003_021da284->field1C][data_ov003_021d6730[data_ov003_021da284->field1C][i]][0],
            a +
                data_ov003_021d67b0[data_ov003_021da284->field1C][data_ov003_021d6730[data_ov003_021da284->field1C][i]]
                                   [1] -
                data_ov003_021d6780[data_ov003_021da284->field1C][1]);
        func_ov003_021cec00(data_ov003_021da284->field8[i], a);
    }
    m = data_ov003_021da284->field1C;
    y = a & 0xff;
    if (y >= 0xc0) {
        x = 0;
        y = 0;
    } else {
        x = y + data_ov003_021d6798[m][1];
    }
    if (x > 0xc0) {
        x = 0xc0;
    }
    SetRectCorners(data_ov003_021d6780[m][0], y, data_ov003_021d6780[m][0] + data_ov003_021d6798[m][0], x, v1);
    WriteWinRect(0, 0, v1);
}

void func_ov003_021cec00(OamRange *a, s32 b) {
    s32 n;
    s32 i;
    u32 w;
    s32 h;
    s32 x;

    n = GetOamRangeEntryCount(a);
    for (i = 0; i < n; i++) {
        GetOamRangeEntryPosition(a, i, &w, &h);
        if (h >= b && h < 0xc0) {
            x = 0;
        } else {
            x = 0x200;
        }
        SetOamRangeEffect(a, i, x, 0);
    }
}

void func_ov003_021ceb80(s32 a) {
    CopyNceImageToOamEntries(0, data_ov003_021d6748[data_ov003_021da284->field1C][a] + 1,
                             GetOamRangeEntry(data_ov003_021da284->field8[a], 0));
    SetOamRangePosition(
        data_ov003_021da284->field8[a], -1,
        data_ov003_021d67b0[data_ov003_021da284->field1C][data_ov003_021d6730[data_ov003_021da284->field1C][a]][0],
        data_ov003_021d67b0[data_ov003_021da284->field1C][data_ov003_021d6730[data_ov003_021da284->field1C][a]][1]);
    func_ov003_021d1790(data_ov003_021da284->field8[a], -1, 0);
}

void func_ov003_021ceb54(TaskEntry *a) {
    data_ov003_021da284->field1D++;
    if (data_ov003_021da284->field1D >= 8) {
        SetTaskCallback(a, func_ov003_021ceaf8);
    }
}

void func_ov003_021ceaf8(TaskEntry *a) {
    u32 w;
    s32 h;

    GetOamRangeEntryPosition(data_ov003_021da284->field0, 0, &w, &h);
    h += 0xc;
    func_ov003_021cec50(h);
    if (h >= 192) {
        if (data_ov003_021da284->field1E != 0) {
            SetTaskCallback(a, func_ov003_021ceab8);
            return;
        }
        SetTaskCallback(a, func_ov003_021cea3c);
    }
}

void func_ov003_021ceab8(TaskEntry *a) {
    data_ov003_021da284->field1A++;
    G2x_ChangeBlendBrightness_(&reg_G2_BLDCNT, data_ov003_021da284->field1A);
    if (data_ov003_021da284->field1A >= 0) {
        SetTaskCallback(a, func_ov003_021cea3c);
    }
}

void func_ov003_021cea3c(u32 a) {
    s32 i;

    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    DeleteOamRange(data_ov003_021da284->field0);
    DeleteOamRange(data_ov003_021da284->field4);
    for (i = 0; i < data_ov003_021d6720[data_ov003_021da284->field1C]; i++) {
        if (data_ov003_021da284->field8[i] != NULL) {
            DeleteOamRange(data_ov003_021da284->field8[i]);
        }
    }
    DeleteObjTextCanvas(data_ov003_021da284->field10);
    RequestTaskRemoval(1, a);
    FreeExpHeapBlockAndClearPointer(&data_ov003_021da284);
}
