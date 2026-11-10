#include "Main/Unknown/code_0201ea58.h"

s32 GetLayoutAxisStartX(LayoutAxis a, s32 b) {
    s32 v;

    v = a.mUnk_00_0;
    switch (a.mUnk_00_12) {
        case 1:
            v -= (b + 1) / 2;
            break;
        case 2:
            v -= b;
            break;
    }
    return v;
}

s32 GetLayoutAxisStartY(LayoutAxis a, s32 b) {
    s32 v;

    v = a.mUnk_00_0;
    switch (a.mUnk_00_12) {
        case 1:
            v -= (b + 1) / 2;
            break;
        case 2:
            v -= b;
            break;
    }
    return v;
}

u16 RectTableGetCount(LayoutEntryTable *a) {
    return a->mUnk_06;
}

RectTableEntry *RectTableGetEntry(LayoutEntryTable *a, s32 b) {
    RectTableEntry *p;

    p = (RectTableEntry *) (a + 1);
    if (b < 0 || b >= RectTableGetCount(a)) {
        return 0;
    }
    return p + b;
}

s32 RectTableFindContaining(LayoutEntryTable *a, s32 b, s32 c) {
    s32 i;
    RectTableEntry *p;
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;

    p = (RectTableEntry *) (a + 1);
    for (i = 0; i < RectTableGetCount(a); i++) {
        x = GetLayoutAxisStartX(p->mAxisX, p->mWidth);
        y = GetLayoutAxisStartY(p->mAxisY, p->mHeight);
        x2 = x + p->mWidth;
        y2 = y + p->mHeight;
        if (x <= b && b <= x2 && y <= c && c <= y2) {
            return i;
        }
        p++;
    }
    return -1;
}

void *GetLabelLayoutEntry(LayoutEntryTable *a, s32 b) {
    u8 *p;
    s32 n;

    p = (u8 *) (a + 1);
    n = a->mUnk_06;
    if (b < 0 || b >= n) {
        return 0;
    }
    return p + b * 12;
}
