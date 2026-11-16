#include "code_0201ea58.h"

s32 sub_201EBE8(Unk0201ea84 a, s32 b) {
    s32 v;

    v = a.field0_0;
    switch (a.field0_12) {
        case 1:
            v -= (b + 1) / 2;
            break;
        case 2:
            v -= b;
            break;
    }
    return v;
}

s32 sub_201EBA0(Unk0201ea84 a, s32 b) {
    s32 v;

    v = a.field0_0;
    switch (a.field0_12) {
        case 1:
            v -= (b + 1) / 2;
            break;
        case 2:
            v -= b;
            break;
    }
    return v;
}

u16 sub_201EB98(Unk0201ea30 *a) {
    return a->field6;
}

Unk0201eb54 *RectTableGetEntry(Unk0201ea30 *a, s32 b) {
    Unk0201eb54 *p;

    p = (Unk0201eb54 *) (a + 1);
    if (b < 0 || b >= sub_201EB98(a)) {
        return 0;
    }
    return p + b;
}

s32 RectTableFindContaining(Unk0201ea30 *a, s32 b, s32 c) {
    s32 i;
    Unk0201eb54 *p;
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;

    p = (Unk0201eb54 *) (a + 1);
    for (i = 0; i < sub_201EB98(a); i++) {
        x = sub_201EBE8(p->field0, p->field4);
        y = sub_201EBA0(p->field2, p->field5);
        x2 = x + p->field4;
        y2 = y + p->field5;
        if (x <= b && b <= x2 && y <= c && c <= y2) {
            return i;
        }
        p++;
    }
    return -1;
}

void *sub_201EA58(Unk0201ea30 *a, s32 b) {
    u8 *p;
    s32 n;

    p = (u8 *) (a + 1);
    n = a->field6;
    if (b < 0 || b >= n) {
        return 0;
    }
    return p + b * 12;
}
