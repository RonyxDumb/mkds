#include "00/code_021884d8.h"

#include "00/unk_021b4000.h"
#include "00/code_02188008.h"

void func_ov000_021885ec(void) {
    Unk021884e4 *p;
    void *q;

    p = (Unk021884e4 *) func_ov000_02188584(1);
    if ((p->field8 & 0x10) != 0) {
        q = (void *) func_ov000_02188584(0x10);
        p->field8 &= ~0x10;
        p->field4(0x10, q, 0xd18);
    }
    if ((p->field8 & 8) != 0) {
        q = (void *) func_ov000_02188584(8);
        p->field8 &= ~8;
        p->field4(8, q, 0xc);
    }
    if ((p->field8 & 4) != 0) {
        q = (void *) func_ov000_02188584(4);
        p->field8 &= ~4;
        p->field4(4, q, 0x58);
    }
    if ((p->field8 & 2) != 0) {
        q = (void *) func_ov000_02188584(2);
        p->field8 &= ~2;
        p->field4(2, q, 0x2300);
    }
    if ((p->field8 & 1) != 0) {
        p->field8 &= ~1;
        p->field4(1, p, 0x18);
    }
}

u32 func_ov000_02188584(u32 a) {
    if ((a & 1) != 0) {
        return (u32) data_ov000_021b4d10;
    }
    if ((a & 2) != 0) {
        return *(u32 *) &data_ov000_021b4d04;
    }
    if ((a & 4) != 0) {
        return *(u32 *) &data_ov000_021b4d08;
    }
    if ((a & 8) != 0) {
        return *(u32 *) &data_ov000_021b4d0c;
    }
    if ((a & 0x10) != 0) {
        return *(u32 *) &data_ov000_021b4d00;
    }
    return 0;
}

void func_ov000_02188534(u8 a) {
    Unk021884e4 *p;
    Unk02188408 *q;

    p = (Unk021884e4 *) func_ov000_02188584(1);
    q = (Unk02188408 *) func_ov000_02188584(0x10);
    p->field9 = a;
    if (a < 0x10) {
        if (a > p->field16) {
            p->field16 = a;
            if (a > 7) {
                p->field15 = func_ov000_021884d8(q->fieldD0D);
                p->field14 = q->field444[q->fieldD13].field0;
            }
        }
    }
}

u8 func_ov000_02188528(void) {
    u32 value0;
    value0 = data_ov000_021b4d10->field9;
    return value0;
}

void func_ov000_02188508(u32 arg0) {
    u32 value0 = arg0;
    u32 value4;
    u32 value5;
    value5 = (value0) + (0u);
    value0 = 1u;
    value0 = func_ov000_02188584(value0);
    value4 = (value0) + (0u);
    *(u32 *) ((value4) + 12u) = value5;
    value0 = func_ov000_02188528();
    *(u8 *) ((value4) + 10u) = value0;
}

u32 func_ov000_021884fc(void) {
    u32 value0;
    value0 = data_ov000_021b4d10->fieldC;
    return value0;
}

void func_ov000_021884e4(u8 value) {
    data_ov000_021b4d10->field17 = func_ov000_021884d8(value);
}

u8 func_ov000_021884d8(u8 value) {
    if (value > 2) {
        value -= 3;
    }
    return value;
}
