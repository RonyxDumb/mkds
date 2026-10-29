#include "Main/Unknown/code_02026120.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_020270d0.h"
#include "Main/Unknown/code_02027188.h"
#include "Main/Unknown/code_02029930.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_0202b888.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02077f0c.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae5d4.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_021106a8.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0201ea58.h"

#pragma thumb on

static inline s32 func_02026120_inline(u16 i) {
    s32 a = 0;
    if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
        a = 1;
    }
    return a;
}

static inline s32 func_02026120_inline_2(u16 i) {
    s32 b = 0;
    if (func_02026120_inline(i) == 0 && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
        b = 1;
    }
    return b;
}

int func_02026120(void) {
    int r;
    Unk02174e14 *g;
    Unk02174e14_00 *s;
    s32 n;
    Unk02174e14 *p;
    u16 i;
    s32 a;
    s32 j;
    s32 k;
    s32 x;
    s32 y;
    u16 v;
    u8 c;
    s16 t;
    s16 m;

    r = 0;
    i = func_020435bc();
    g = data_02174e14;
    s = &g->mUnk_01c;
    switch (g->mUnk_06c) {
        case 0:
            if (func_02036c5c() != 0) {
                data_02174e14->mUnk_06c = 1;
            }
            break;
        case 1:
            if (g->mUnk_068 == 0) {
                func_0202734c(1);
            }
            data_02174e14->mUnk_068++;
            p = data_02174e14;
            if (p->mUnk_068 < 10) {
                p->mUnk_070 = (p->mUnk_068 << 12) / 10;
            } else {
                p->mUnk_070 = 0x1000;
                data_02174e14->mUnk_068 = 0;
                if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                    a = 2;
                } else {
                    a = 3;
                }
                data_02174e14->mUnk_06c = a;
            }
            func_02027084();
            break;
        case 2:
            g->mUnk_0f0 = 0xc;
            data_02174e14->mUnk_0f4 = 0x24;
            data_02174e14->mUnk_068 = 0;
            data_02174e14->mUnk_08c = 1;
            if (func_02029930()->mUnk_c8 == 3) {
                c = data_02174e14->mUnk_0f0 | 0x40;
                if (data_0217aa00->mUnk_0004 == 8) {
                    data_0217aa00->mUnk_15f7 = c;
                }
                func_02027424(1);
                data_02174e14->mUnk_06c = 8;
            } else if (func_02029930()->mUnk_c8 == 2) {
                c = data_02174e14->mUnk_0f0 | 0xc0;
                if (data_0217aa00->mUnk_0004 == 8) {
                    data_0217aa00->mUnk_15f7 = c;
                }
                data_02174e14->mUnk_06c = 6;
            }
            break;
        case 3:
            n = g->mUnk_060;
            if (func_02026120_inline_2(i) != 0) {
                x = data_02175670[i].mUnk_00;
                y = data_02175672[i].mUnk_00;
                k = func_0201ea84(s->mUnk_10, x, y);
                if (k >= 0) {
                    for (j = 0; j < data_02174e14->mUnk_07c; j++) {
                        if (k == data_usa_02153554[j].mUnk_06) {
                            data_02174e14->mUnk_060 = j;
                            break;
                        }
                    }
                    func_020270fc(n);
                    func_021106a8(func_02025eb0(data_02174e14->mUnk_0f0), 0);
                    data_02174e14->mUnk_068 = 0;
                    data_02174e14->mUnk_06c = 5;
                } else if (data_02174e14->mUnk_080 == 0 && func_02128210(x, y) != 0) {
                    func_020273c0();
                }
            } else if (func_020270d0() != 0) {
                data_02174e14->mUnk_068 = 0;
                data_02174e14->mUnk_08c = 3;
                data_02174e14->mUnk_06c = 6;
                func_021106a8(func_02025eb0(data_02174e14->mUnk_0f0), 0);
                func_02077f48(1);
                p = data_02174e14;
                switch (p->mUnk_080) {
                    case 2:
                        func_02121f1c(p->mUnk_0f0);
                        func_02121eb4(data_02174e14->mUnk_0f4);
                        break;
                    case 1:
                        c = p->mUnk_0f0 | 0xc0;
                        if (data_0217aa00->mUnk_0004 == 8) {
                            data_0217aa00->mUnk_15f7 = c;
                        }
                        break;
                }
            } else {
                v = data_02175628[i].mUnk_00;
                if ((u16) (v & 1) != 0) {
                    data_02174e14->mUnk_068 = 0;
                    data_02174e14->mUnk_06c = 5;
                    func_02027188();
                    func_021106a8(func_02025eb0(data_02174e14->mUnk_0f0), 0);
                } else if (data_02174e14->mUnk_080 == 0 && (u16) (v & 2) != 0) {
                    func_020273c0();
                } else {
                    if (func_020ae408(i, 0x40) != 0) {
                        p = data_02174e14;
                        t = p->mUnk_084;
                        if (t != -1) {
                            p->mUnk_060 = t;
                        }
                    } else if (func_020ae408(i, 0x80) != 0) {
                        p = data_02174e14;
                        t = p->mUnk_086;
                        if (t != -1) {
                            p->mUnk_060 = t;
                        }
                    } else if (func_020ae408(i, 0x10) != 0) {
                        p = data_02174e14;
                        t = p->mUnk_088;
                        if (t != -1) {
                            p->mUnk_060 = t;
                        }
                    } else if (func_020ae408(i, 0x20) != 0) {
                        p = data_02174e14;
                        t = p->mUnk_08a;
                        if (t != -1) {
                            p->mUnk_060 = t;
                        }
                    }
                    if (data_02174e14->mUnk_060 != n) {
                        func_02110698();
                        func_020270fc(n);
                        data_02174e14->mUnk_06c = 4;
                    }
                }
            }
            break;
        case 4:
            g->mUnk_068++;
            if (data_02174e14->mUnk_068 > 5) {
                func_020272ec();
                data_02174e14->mUnk_068 = 0;
                data_02174e14->mUnk_06c = 3;
            }
            break;
        case 5:
            g->mUnk_068++;
            p = data_02174e14;
            if (p->mUnk_068 > 5) {
                p->mUnk_068 = 0;
                data_02174e14->mUnk_08c = 1;
                func_020272ec();
                p = data_02174e14;
                switch (p->mUnk_080) {
                    case 0:
                        func_02029930()->mUnk_00[data_02174e14->mUnk_078].mUnk_00 = p->mUnk_0f0;
                        func_02029930()->mUnk_00[data_02174e14->mUnk_078].mUnk_04 = data_02174e14->mUnk_0f4;
                        func_02116fb0();
                        if (func_02029930()->mUnk_c8 == 2) {
                            func_02029930()->mUnk_00[data_02174e14->mUnk_078].mUnk_14 = 1;
                            func_02077f48(1);
                            data_02174e14->mUnk_06c = 7;
                            func_02117060();
                            func_02116ec0();
                        } else {
                            func_02027424(1);
                            func_02077f5c();
                            data_02174e14->mUnk_06c = 8;
                            func_02025f14(&data_02174e14->mUnk_108, 2);
                        }
                        break;
                    case 1:
                        if (func_02029930()->mUnk_c8 == 3) {
                            c = data_02174e14->mUnk_0f0 | 0x40;
                            if (data_0217aa00->mUnk_0004 == 8) {
                                data_0217aa00->mUnk_15f7 = c;
                            }
                            func_02025f14(&data_02174e14->mUnk_108, 2);
                            func_02027424(1);
                            data_02174e14->mUnk_06c = 8;
                            func_02077f5c();
                        } else if (func_02029930()->mUnk_c8 == 2) {
                            c = data_02174e14->mUnk_0f0 | 0xc0;
                            if (data_0217aa00->mUnk_0004 == 8) {
                                data_0217aa00->mUnk_15f7 = c;
                            }
                            func_02077f48(1);
                            data_02174e14->mUnk_06c = 6;
                        }
                        break;
                    case 2:
                        func_02121f1c(p->mUnk_0f0);
                        func_02025f14(&data_02174e14->mUnk_108, 2);
                        func_02027424(1);
                        data_02174e14->mUnk_06c = 8;
                        func_02077f5c();
                        break;
                }
            }
            break;
        case 6:
            if ((g->mUnk_080 == 1 && func_0202b888() != 0) || (data_02174e14->mUnk_080 == 2 && func_02121d0c() != 0)) {
                if (data_02174e14->mUnk_080 == 2) {
                    func_021219cc();
                }
                if (func_02029930()->mUnk_c8 == 2 || func_020270d0() != 0) {
                    data_02174e14->mUnk_06c = 7;
                } else {
                    func_02027424(1);
                    func_02025f14(&data_02174e14->mUnk_108, 2);
                    data_02174e14->mUnk_06c = 8;
                }
            }
            break;
        case 7:
            g->mUnk_068++;
            p = data_02174e14;
            if (p->mUnk_068 > 60) {
                if (p->mUnk_080 == 2) {
                    func_02027424(3);
                } else {
                    func_02027424(2);
                }
                func_02025f14(&data_02174e14->mUnk_108, 2);
                if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                    func_020789d4();
                } else if (func_02029930()->mUnk_c8 == 2) {
                    func_0211f378();
                }
                data_02174e14->mUnk_068 = 0;
                data_02174e14->mUnk_06c = 8;
            }
            break;
        case 8:
            g->mUnk_068++;
            p = data_02174e14;
            if (p->mUnk_068 < 10) {
                p->mUnk_070 = ((10 - p->mUnk_068) << 12) / 10;
            } else {
                func_02029930()->mUnk_00[data_02174e14->mUnk_078].mUnk_00 = p->mUnk_0f0;
                func_02029930()->mUnk_00[data_02174e14->mUnk_078].mUnk_04 = data_02174e14->mUnk_0f4;
                data_02174e14->mUnk_06c = 9;
            }
            data_02174e14->mUnk_074 += 0x1000;
            func_02027084();
            break;
        case 9:
            r = g->mUnk_08c;
            break;
    }

    func_02025edc(&data_02174e14->mUnk_0f8);
    func_02025edc(&data_02174e14->mUnk_108);
    func_02025edc(&data_02174e14->mUnk_118);
    func_0202728c(func_02025ebc(&data_02174e14->mUnk_0f8));
    m = func_02025ebc(&data_02174e14->mUnk_108);
    func_020272c0(m, func_02025ebc(&data_02174e14->mUnk_118));
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        p = data_02174e14;
        if (p->mUnk_08c != 2) {
            func_02078a9c(p->mUnk_0f0);
            func_02078a34(data_02174e14->mUnk_0f4);
        }
        func_02078420(func_02029930()->mUnk_d8);
    }
    if (data_02174e14->mUnk_128 != 0) {
        func_0202bb80();
    } else {
        func_02124c30(g->mUnk_000.mUnk_0c, g->mUnk_000.mUnk_08, 0, data_02174e14->mUnk_054, g->mUnk_000.mUnk_18);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02124bf0(s->mUnk_0c, s->mUnk_08, 0, data_02174e14->mUnk_058, s->mUnk_18);
        func_020ae5d4((u32) data_02174e14->mUnk_058);
    } else if (func_02029930()->mUnk_c8 == 2) {
        func_0211f39c();
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_020780f4();
    }
    switch (r) {
        case 1:
            if (func_02029930()->mUnk_c8 == 2) {
                func_02029930()->mUnk_108 = 0;
            } else {
                func_02029930()->mUnk_108 = 1;
            }
            break;
        case 2:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                func_02078a9c(-1);
                func_02078a34(-1);
            }
            func_02029930()->mUnk_108 = 0;
            break;
    }
    return r;
}

#pragma thumb off
