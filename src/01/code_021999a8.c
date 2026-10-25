#include "01/code_021999a8.h"
#include "01/unk_021a6000.h"

void func_ov001_02199bb0(void) {
    u32 r;
    s32 b;
    s32 a;
    u16 v;
    s32 oldv;
    Unk021a9bec *p;
    Unk02175628Index i;

    i = UNK_02175628_INDEX_8;
    r = -1;
    b = 0;
    a = 0;
    v = data_02175628[i].mUnk_4c;
    if (v == 0 && data_02175628[i].mUnk_58 < 5) {
        a = 1;
    }
    if (a == 0 && data_02175628[i].mUnk_54 == 0 && v != 0) {
        b = 1;
    }
    if (b != 0) {
        r = func_0201ea84(data_ov001_021a9bec->mUnk_30, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    if ((u16)(data_02175628[i].mUnk_00 & 2) == 0) {
        b = 0;
        a = 0;
        v = data_02175628[i].mUnk_4c;
        if (v == 0 && data_02175628[i].mUnk_58 < 5) {
            a = 1;
        }
        if (a == 0 && data_02175628[i].mUnk_54 == 0 && v != 0) {
            b = 1;
        }
        if (b != 0 && func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) != 0) {
            goto leave;
        }
    } else {
leave:
        data_ov001_021a9bec->mUnk_04 = 5;
        data_ov001_021a9bec->mUnk_10 = 0;
        func_02128310(0);
        return;
    }
    if ((u16)(data_02175628[i].mUnk_00 & 1) != 0 || r <= 1) {
        p = data_ov001_021a9bec;
        oldv = p->mUnk_08;
        if ((u16)(data_02175628[i].mUnk_00 & 1) == 0) {
            switch (r) {
            case 0:
                p->mUnk_08 = 0;
                break;
            case 1:
                p->mUnk_08 = 1;
                break;
            }
        }
        data_ov001_021a9bec->mUnk_04 = 4;
        p = data_ov001_021a9bec;
        switch (p->mUnk_08) {
        case 0:
            p->mUnk_10 = 5;
            break;
        case 1:
            if (data_0217aa08->mUnk_04->mUnk_004 != 0) {
                p->mUnk_10 = 3;
            } else {
                p->mUnk_10 = 6;
                data_0217b488->mUnk_18 = 0;
            }
            break;
        }
        if (data_ov001_021a9bec->mUnk_08 == oldv) {
            data_ov001_021a9bec->mUnk_14 = 0;
        }
        func_02105ac0(5);
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        if (data_ov001_021a9bec->mUnk_08 > 0) {
            data_ov001_021a9bec->mUnk_08--;
            func_02105ac0(0);
            return;
        }
    }
    if (func_020ae408(8, 0x80) != 0) {
        if (data_ov001_021a9bec->mUnk_08 < 1) {
            data_ov001_021a9bec->mUnk_08++;
            func_02105ac0(0);
        }
    }
}

void func_ov001_02199b6c(void) {
    data_ov001_021a9bec->mUnk_0c++;
    if (data_ov001_021a9bec->mUnk_0c >= 10) {
        data_ov001_021a9bec->mUnk_04 = 5;
        data_ov001_021a9bec->mUnk_0c = 0;
        if (data_ov001_021a9bec->mUnk_10 == 5) {
            func_021282c8();
        }
    } else if (data_ov001_021a9bec->mUnk_0c >= 5) {
        data_ov001_021a9bec->mUnk_14 = 1;
    }
}

void func_ov001_02199a8c(void) {
    s32 i;
    s32 j;
    s32 v;
    if (func_ov001_02192e84() == -1) {
        if (data_ov001_021a9bec->mUnk_10 == 5) {
            func_ov001_02192e78(0xe);
        } else if (data_ov001_021a9bec->mUnk_10 == 6) {
            func_ov001_02192e78(3);
        }
    }
    data_ov001_021a9bec->mUnk_0c++;
    if (data_ov001_021a9bec->mUnk_0c <= 10) {
        v = func_020ae4c0(1, 0, 0xfa, data_ov001_021a9bec->mUnk_0c, 10);
    } else {
        v = 0xfa;
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6a8c[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = v;
            } else {
                data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a94[i][j]].mUnk_04 = -v;
            }
        }
    }
    if (data_ov001_021a9bec->mUnk_0c >= 10) {
        if (data_ov001_021a9bec->mUnk_10 == 0 || data_ov001_021a9bec->mUnk_10 == 3 || func_02128274() != 0) {
            if (func_ov001_02192e84() == -1) {
                func_ov001_02192ea0(data_ov001_021a9bec->mUnk_10);
            }
        }
    }
}

void func_ov001_02199a20(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (i == data_ov001_021a9bec->mUnk_08 && data_ov001_021a9bec->mUnk_14 != 0) {
            data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a88[i]].mUnk_00 = 1;
            func_02124a20(data_ov001_021a6a80[i], 0xe, data_ov001_021a9bec->mUnk_20, data_ov001_021a9bec->mUnk_2c);
        } else {
            data_ov001_021a9bec->mUnk_1c[data_ov001_021a6a88[i]].mUnk_00 = 0;
            func_02124a20(data_ov001_021a6a80[i], 0xf, data_ov001_021a9bec->mUnk_20, data_ov001_021a9bec->mUnk_2c);
        }
    }
}

void func_ov001_021999a8(void) {
    Unk021a9bec *p;
    data_ov001_021a9bec->mUnk_00 = data_ov001_021a9bec->mUnk_04;
    switch (data_ov001_021a9bec->mUnk_00) {
    case 0:
        func_ov001_02199e1c();
        break;
    case 1:
        func_ov001_02199d88();
        break;
    case 2:
        func_ov001_02199d68();
        break;
    case 3:
        func_ov001_02199bb0();
        break;
    case 4:
        func_ov001_02199b6c();
        break;
    case 5:
        func_ov001_02199a8c();
        break;
    }
    func_ov001_02199a20();
    p = data_ov001_021a9bec;
    func_02124c30(p->mUnk_2c, p->mUnk_20, 0, func_ov001_0219e90c(), p->mUnk_1c);
}
