#include "code_020109c4.h"

void func_02010bc8(Unk02010b50 **a, Unk02010b50 *b) {
    Unk02010b50 *cur;
    Unk02010b50 *next;
    Unk02010b50 *t;

    cur = *a;
    if (cur == 0) {
        *a = b;
        return;
    }
    next = cur->mUnk_10;
    if (next == 0) {
        if (cur->mUnk_18 > b->mUnk_18) {
            t = b;
            if (b->mUnk_10 != 0) {
                do {
                    t = t->mUnk_10;
                } while (t->mUnk_10 != 0);
            }
            t->mUnk_10 = cur;
            *a = b;
            return;
        }
        cur->mUnk_10 = b;
        return;
    }
    while (next != 0) {
        if (next->mUnk_18 >= b->mUnk_18) {
            t = b;
            if (b->mUnk_10 != 0) {
                do {
                    t = t->mUnk_10;
                } while (t->mUnk_10 != 0);
            }
            cur->mUnk_10 = b;
            t->mUnk_10 = next;
            return;
        }
        cur = next;
        next = next->mUnk_10;
    }
    cur->mUnk_10 = b;
}

void func_02010b50(u32 *a, Unk02010b50 *b) {
    int i;

    while (b != 0) {
        for (i = 0; i < b->mUnk_19; i++) {
            if ((b->mUnk_1a[i] & 0x100) != 0) {
                a[i >> 5] |= 1 << (i & 31);
            }
        }
        b = b->mUnk_10;
    }
}

void func_02010ab4(Unk02010ab4 *a, Unk02010b50 *b) {
    switch (b->mUnk_08[0]) {
        case 0x4d:
            func_02010b50(a->mUnk_3c, b);
            func_02010bc8(&a->mUnk_08, b);
            break;
        case 0x4a:
            func_02010b50(a->mUnk_44, b);
            func_02010bc8(&a->mUnk_10, b);
            break;
        case 0x56:
            func_02010b50(a->mUnk_4c, b);
            func_02010bc8(&a->mUnk_18, b);
            break;
    }
}

int func_02010a40(Unk02010b50 **a, Unk02010b50 *b) {
    Unk02010b50 *next;
    Unk02010b50 *cur;

    cur = *a;
    if (cur == 0) {
        return 0;
    }
    if (cur == b) {
        *a = cur->mUnk_10;
        b->mUnk_10 = 0;
        return 1;
    }
    next = cur->mUnk_10;
    while (next != 0) {
        if (next == b) {
            cur->mUnk_10 = next->mUnk_10;
            next->mUnk_10 = 0;
            return 1;
        }
        cur = next;
        next = next->mUnk_10;
    }
    return 0;
}

void func_020109d8(Unk02010ab4 *a, Unk02010b50 *b) {
    if (func_02010a40(&a->mUnk_08, b) != 0 || func_02010a40(&a->mUnk_10, b) != 0 ||
        func_02010a40(&a->mUnk_18, b) != 0) {
        a->mUnk_00 |= 0x10;
    }
}

void func_020109c4(Unk020109c4 *a, void (*b)(void *), u32 c, u32 d, u32 e) {
    a->mUnk_20 = b;
    a->mUnk_24 = d;
    a->mUnk_25 = e;
}
