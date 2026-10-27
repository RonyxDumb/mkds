#include "Main/Unknown/code_02114cb0.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_021156d4.h"
#include "Main/Unknown/code_02116084.h"
#include "Main/Unknown/code_0211606c.h"
#include "Main/Unknown/code_02116174.h"
#include "Main/Unknown/code_02116844.h"
#include "Main/Unknown/code_02116870.h"
#include "code_0212df7c.h"
#include "code_0201ea58.h"

#pragma thumb on

void func_0211553c(void) {
    s16 v;
    u32 w;
    u16 n;
    s32 i;

    func_02116084();
    data_0217d350->mUnk_5c++;
    v = func_020ae4c0(1, 0x100, 0, data_0217d350->mUnk_5c, 0xa);
    w = func_020ae4c0(1, ~0xbf, 0, data_0217d350->mUnk_5c, 0xa);
    n = data_0217d350->mUnk_30->mUnk_06;
    data_0217d350->mUnk_70 = w;
    data_0217d350->mUnk_3c[30].mUnk_04 = v;
    data_0217d350->mUnk_3c[31].mUnk_04 = v;
    data_0217d350->mUnk_3c[n + 5].mUnk_06 = w;
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[n + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (data_0217d350->mUnk_5c >= 0xa) {
        if (func_02128294() != 0) {
            func_02115e0c();
        }
    }
}

void func_02115204(void) {
    s32 s;
    s32 v;
    u32 w;
    Unk02175628Index i;
    s32 n;

    v = -1;
    w = v;
    i = UNK_02175628_INDEX_8;
    func_02116084();
    func_02115fd4();
    s = func_02116870();
    n = (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) || data_02175674[i].mUnk_00 != 0;
    if (n) {
        v = func_0201ea84(data_0217d350->mUnk_34, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    n = !(data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) &&
        (data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0);
    if (n) {
        w = func_0201ea84(data_0217d350->mUnk_34, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    if (v != 5) {
        data_0217d350->mUnk_98 = 0;
    }
    if (v != 6) {
        data_0217d350->mUnk_9c = 0;
    }
    if ((u16) (data_02175628[i].mUnk_00 & 2) != 0 ||
        ((n = !(data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) &&
              (data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0)) &&
         func_02128210(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) != 0)) {
        if (func_0211606c() != 0) {
            return;
        }
        func_02115c8c();
        data_0217d350->mUnk_a0 = 3;
        func_02128310(0);
        return;
    }
    if ((v == 5 && data_0217d350->mUnk_98 != 0) || (w == 5 && data_0217d350->mUnk_98 == 0) ||
        (u16) (data_0217562a[i].mUnk_00 & 0x20) != 0) {
        if (func_0211606c() != 0) {
            return;
        }
        if (data_0217d350->mUnk_3c[30].mUnk_00 == 0) {
            return;
        }
        data_0217d350->mUnk_78 = 1;
        data_0217d350->mUnk_90[0] = 6;
        data_0217d350->mUnk_98 = 1;
        func_02115df8();
        func_0212ecc0(data_0217d068, 0, 2);
        return;
    }
    if ((v == 6 && data_0217d350->mUnk_9c != 0) || (w == 6 && data_0217d350->mUnk_9c == 0) ||
        (u16) (data_0217562a[i].mUnk_00 & 0x10) != 0) {
        if (func_0211606c() != 0) {
            return;
        }
        if (data_0217d350->mUnk_3c[31].mUnk_00 == 0) {
            return;
        }
        data_0217d350->mUnk_78 = 0;
        data_0217d350->mUnk_90[1] = 6;
        data_0217d350->mUnk_9c = 1;
        func_02115df8();
        func_0212ecc0(data_0217d068, 0, 2);
        return;
    }
    if (w <= 4) {
        i = (Unk02175628Index) data_0215c4d0[w];
        if (i == data_0217d350->mUnk_74) {
            if (func_02114398(s + i) == 0) {
                if (func_0211606c() == 0) {
                    func_02115d90();
                }
                return;
            }
            if (func_0211606c() == 0) {
                func_0212ecc0(data_0217d068, 0, 0x16);
            }
            return;
        }
        if (func_02116844(i) != 0) {
            data_0217d350->mUnk_74 = i;
            func_0212ecc0(data_0217d068, 0, 0);
        }
    } else {
        if ((u16) (data_02175628[i].mUnk_00 & 1) != 0) {
            if (func_02114398(s + data_0217d350->mUnk_74) == 0) {
                if (func_0211606c() == 0) {
                    func_02115d90();
                }
                return;
            }
            if (func_0211606c() == 0) {
                func_0212ecc0(data_0217d068, 0, 0x16);
            }
            return;
        }
        if (func_020ae408(8, 0x40) != 0) {
            func_02116174();
            return;
        }
        if (func_020ae408(8, 0x80) != 0) {
            func_021161d0();
        }
    }
}

void func_02115000(void) {
    s32 k;
    u16 a;
    s32 i;
    u16 b;
    u16 c;
    s32 j;
    s16 v;

    k = 0;
    func_02116084();
    switch (data_0217d350->mUnk_78) {
        case 0:
            k = ~0xff;
            break;
        case 1:
            k = 0x100;
            break;
    }
    data_0217d350->mUnk_5c++;
    a = data_0217d350->mUnk_08->mUnk_06;
    b = data_0217d350->mUnk_18->mUnk_06;
    c = data_0217d350->mUnk_30->mUnk_06;
    v = func_020ae4c0(1, 0, k, data_0217d350->mUnk_5c, 0xa);
    data_0217d350->mUnk_60 = v;
    data_0217d350->mUnk_68 = v;
    data_0217d350->mUnk_14[1].mUnk_04 = v;
    data_0217d350->mUnk_14[2].mUnk_04 = v;
    data_0217d350->mUnk_14[3].mUnk_04 = v;
    data_0217d350->mUnk_14[a].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 1].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 0xb].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 0xc].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_0217d350->mUnk_14[a + data_0215c530[i][j]].mUnk_04 = v;
        }
    }
    data_0217d350->mUnk_24[1].mUnk_04 = v;
    data_0217d350->mUnk_24[b].mUnk_04 = v;
    data_0217d350->mUnk_24[b + 1].mUnk_04 = v;
    data_0217d350->mUnk_24[b + 0xe].mUnk_04 = v;
    for (i = 0; i < 0xc; i++) {
        data_0217d350->mUnk_24[b + data_0215c584[i]].mUnk_04 = v;
    }
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[c + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (data_0217d350->mUnk_5c >= 0xa) {
        func_02115dc0();
    }
}

void func_02114dfc(void) {
    s32 k;
    u16 a;
    s32 i;
    u16 b;
    u16 c;
    s32 j;
    s16 v;

    k = 0;
    func_02116084();
    switch (data_0217d350->mUnk_78) {
        case 0:
            k = 0x100;
            break;
        case 1:
            k = ~0xff;
            break;
    }
    data_0217d350->mUnk_5c++;
    a = data_0217d350->mUnk_08->mUnk_06;
    b = data_0217d350->mUnk_18->mUnk_06;
    c = data_0217d350->mUnk_30->mUnk_06;
    v = func_020ae4c0(1, k, 0, data_0217d350->mUnk_5c, 0xa);
    data_0217d350->mUnk_60 = v;
    data_0217d350->mUnk_68 = v;
    data_0217d350->mUnk_14[1].mUnk_04 = v;
    data_0217d350->mUnk_14[2].mUnk_04 = v;
    data_0217d350->mUnk_14[3].mUnk_04 = v;
    data_0217d350->mUnk_14[a].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 1].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 0xb].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 0xc].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_0217d350->mUnk_14[a + data_0215c530[i][j]].mUnk_04 = v;
        }
    }
    data_0217d350->mUnk_24[1].mUnk_04 = v;
    data_0217d350->mUnk_24[b].mUnk_04 = v;
    data_0217d350->mUnk_24[b + 1].mUnk_04 = v;
    data_0217d350->mUnk_24[b + 0xe].mUnk_04 = v;
    for (i = 0; i < 0xc; i++) {
        data_0217d350->mUnk_24[b + data_0215c584[i]].mUnk_04 = v;
    }
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[c + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (data_0217d350->mUnk_5c >= 0xa) {
        func_02115e0c();
    }
}

void func_02114cb0(void) {
    s16 v;
    u32 w;
    u16 n;
    s32 i;

    data_0217d350->mUnk_5c++;
    v = func_020ae4c0(1, 0, 0x100, data_0217d350->mUnk_5c, 0xa);
    w = func_020ae4c0(1, 0, ~0xbf, data_0217d350->mUnk_5c, 0xa);
    n = data_0217d350->mUnk_30->mUnk_06;
    data_0217d350->mUnk_70 = w;
    data_0217d350->mUnk_3c[30].mUnk_04 = v;
    data_0217d350->mUnk_3c[31].mUnk_04 = v;
    data_0217d350->mUnk_3c[n + 5].mUnk_06 = w;
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[n + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (data_0217d350->mUnk_5c > 0xa) {
        if (func_02128274() != 0) {
            func_02115d08();
        }
    }
}

#pragma thumb off
