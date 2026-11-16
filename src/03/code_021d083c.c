#include "03/code_021d083c.h"

#include "03/unk_021da000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02009adc.h"
#include "03/code_021cf260.h"
#include "03/code_021cef90.h"
#include "03/code_021cfa68.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02007624.h"
#include "Main/Unknown/code_02007e38.h"
#include "03/code_021d0dd8.h"
#include "03/code_021d0df8.h"
#include "03/code_021cd2e0.h"
#include "03/code_021d0000.h"
#include "code_0200f5ac.h"
#include "code_02142eac.h"
#include "Main/Unknown/code_02151718.h"

Unk021da2ac *data_ov003_021da2ac;

void func_ov003_021d1358(Unk021da2ac *a, Unk021d1358 *b) {
    data_ov003_021da2ac = a;
    func_ov003_021cfa30(a->fieldB00);
    data_ov003_021da2ac->field648 = 0;
    data_ov003_021da2ac->field64A = 0;
    data_ov003_021da2ac->fieldA90 = 1;
    data_ov003_021da2ac->fieldA91 = 1;
    data_ov003_021da2ac->fieldA9C = 0;
    func_ov003_021d0a18();
    data_ov003_021da2ac->fieldAB4 = b->field0;
    data_ov003_021da2ac->fieldAB8 = b->field4;
    data_ov003_021da2ac->fieldABC = b->field8;
    data_ov003_021da2ac->fieldAC0 = b->fieldC;
    data_ov003_021da2ac->fieldAC4 = b->field10;
    data_ov003_021da2ac->fieldAC8 = b->field14;
    data_ov003_021da2ac->fieldA92 = b->field18;
    data_ov003_021da2ac->fieldACC = 2;
    OS_GetTick();
    DWCi_BACKUPlRead(data_ov003_021da2ac->field64C);
    OS_GetTick();
    data_ov003_021da2ac->fieldAA0[1] = (u8 *) func_ov003_021cd4dc();
}

u32 func_ov003_021d1290(void) {
    Unk021da2ac *a = data_ov003_021da2ac;
    u8 *p = &a->fieldA90;
    u8 b = *p;

    if (b == 1 || b == 0x14 || b == 0x17 || b == 0x1a || b == 0x1d) {
        a->fieldA90 = 0x22;
        data_ov003_021da2ac->fieldAAC = 0;
        return 1;
    }
    if (b == 4 || b == 5 || b == 6 || b == 0xd) {
        if (b == 4 && a->fieldA98 < 6) {
            return 0;
        }
        func_02009c04();
        data_ov003_021da2ac->fieldA90 = 0x10;
        data_ov003_021da2ac->fieldAAC = 2;
        return 1;
    }
    if (b == 9 || b == 10) {
        *p = 0x20;
        return 1;
    }
    if (b == 0xc) {
        *p = 0x22;
        return 1;
    }
    switch (b) {
        case 2:
            return 0;
        default:
            return 0;
    }
}

void func_ov003_021d1218(void) {
    func_ov003_021d0128(data_ov003_021da2ac->fieldAC8);
    data_ov003_021da2ac->fieldA90 = 1;
    data_ov003_021da2ac->field648 = WM_GetNextTgid();
    MI_CpuCopy8(data_ov003_021da2ac->fieldAA0[1], data_ov003_021da2ac->fieldA50, 0x40);
    data_ov003_021da2ac->fieldA93 = 0;
    data_ov003_021da2ac->field204 = 0;
    data_ov003_021da2ac->field648++;
}

u32 func_ov003_021d11d4(void) {
    if (data_ov003_021da2ac->fieldA90 == 1 || data_ov003_021da2ac->fieldA90 == 0x1a ||
        data_ov003_021da2ac->fieldA90 == 0x1d) {
        func_ov003_021d1218();
        func_ov003_021cfde4();
        data_ov003_021da2ac->fieldA90 = 2;
        return 1;
    }
    return 0;
}

u32 func_ov003_021d11a0(void) {
    if (data_ov003_021da2ac->fieldA90 == 5) {
        data_ov003_021da2ac->fieldA90 = 6;
        func_ov003_021cf69c();
        return 1;
    }
    return 0;
}

void func_ov003_021d0ee0(void) {
    switch (data_ov003_021da2ac->fieldA90) {
        case 1:
            if (data_ov003_021da2ac->fieldAAC == 1) {
                data_ov003_021da2ac->fieldAAC = 0;
                func_ov003_021d11d4();
                return;
            }
            if (data_ov003_021da2ac->fieldAAC == 2) {
                data_ov003_021da2ac->fieldAAC = 0;
                data_ov003_021da2ac->fieldA90 = 0x22;
            }
            return;
        case 2:
            func_ov003_021d0df8();
            return;
        case 3:
            func_ov003_021d0dd8();
            data_ov003_021da2ac->fieldA90 = 4;
            return;
        case 4:
            data_ov003_021da2ac->fieldA98++;
            func_ov003_021d0c84();
            return;
        case 5:
        case 6:
            func_ov003_021d0c84();
            return;
        case 7:
            func_ov003_021d0c58();
            return;
        case 8:
        case 9:
        case 10:
            func_ov003_021d0acc();
            return;
        case 11:
            func_ov003_021d0ab8();
            return;
        case 16:
            data_ov003_021da2ac->fieldA9C = 0;
            data_ov003_021da2ac->fieldA90 = 0x11;
            return;
        case 17:
            if (data_ov003_021da2ac->fieldA9C++ > 0x1e) {
                func_ov003_021d0a88();
            }
            return;
        case 18:
            func_02009c04();
            data_ov003_021da2ac->fieldA9C = 0;
            data_ov003_021da2ac->fieldA90 = 0x16;
            return;
        case 19:
            if (data_ov003_021da2ac->fieldA9C++ > 0x1e) {
                if (func_ov003_021d010c() == 1) {
                    func_ov003_021cfa68();
                    data_ov003_021da2ac->fieldA90 = 0x14;
                }
            }
            return;
        case 21:
            func_ov003_021cfaa8();
            data_ov003_021da2ac->fieldA9C = 0;
            data_ov003_021da2ac->fieldA90 = 0x16;
            return;
        case 22:
            if (data_ov003_021da2ac->fieldA9C++ > 0x1e) {
                if (func_ov003_021d010c() == 1) {
                    func_ov003_021cfa68();
                    data_ov003_021da2ac->fieldA90 = 0x17;
                }
            }
            return;
        case 24:
            func_ov003_021cfaa8();
            data_ov003_021da2ac->fieldA9C = 0;
            data_ov003_021da2ac->fieldA90 = 0x19;
            return;
        case 25:
            if (data_ov003_021da2ac->fieldA9C++ > 0x1e) {
                if (func_ov003_021d010c() == 1) {
                    func_ov003_021cfa68();
                    data_ov003_021da2ac->fieldA90 = 0x1a;
                }
            }
            return;
        case 27:
            func_ov003_021cfaa8();
            data_ov003_021da2ac->fieldA9C = 0;
            data_ov003_021da2ac->fieldA90 = 0x1c;
            return;
        case 28:
            if (data_ov003_021da2ac->fieldA9C++ > 0x1e) {
                if (func_ov003_021d010c() == 1) {
                    func_ov003_021cfa68();
                    data_ov003_021da2ac->fieldA90 = 0x1d;
                    return;
                } else {
                    u32 a = data_ov003_021da2ac->fieldA9C;

                    if (a % 0x1e == 1 && a > 0x37) {
                        func_ov003_021cfaa8();
                    }
                }
            }
            return;
        case 32:
            func_ov003_021cfaa8();
            data_ov003_021da2ac->fieldA9C = 0;
            data_ov003_021da2ac->fieldA90 = 0x21;
            return;
        case 33:
            if (data_ov003_021da2ac->fieldA9C++ > 0x1e) {
                if (func_ov003_021d010c() == 1) {
                    func_ov003_021cfa68();
                    data_ov003_021da2ac->fieldA90 = 0x22;
                }
            }
            return;
        case 30:
            func_ov003_021cfaa8();
            return;
        case 34:
            return;
    }
}

void func_ov003_021d0e9c(u8 *a, u8 *b) {
    *a = data_ov003_021da2ac->fieldA90;
    if (data_ov003_021da2ac->fieldA90 != data_ov003_021da2ac->fieldA91) {
        *b = 1;
    } else {
        *b = 0;
    }
    data_ov003_021da2ac->fieldA91 = data_ov003_021da2ac->fieldA90;
}

void *func_ov003_021d0e90(void) {
    return func_02007e38(1);
}

void func_ov003_021d0df8(void) {
    switch (func_ov003_021d010c()) {
        case 1:
            func_ov003_021d0078();
            return;
        case 7:
            data_ov003_021da2ac->field64A = func_ov003_021cfed8();
            data_ov003_021da2ac->fieldA98 = 0;
            data_ov003_021da2ac->fieldA90 = 3;
            return;
        case 0:
            data_ov003_021da2ac->fieldA98 = 0;
            data_ov003_021da2ac->fieldA90 = 3;
            return;
        case 9:
            func_ov003_021cfb80();
            return;
        case 3:
            break;
        default:
            OS_Terminate();
            break;
    }
}

void func_ov003_021d0dd8(void) {
    func_ov003_021cf978(data_ov003_021da2ac->fieldAC8, data_ov003_021da2ac->field648);
}

void func_ov003_021d0c84(void) {
    switch (func_ov003_021cf360()) {
        case 1:
            func_ov003_021cf93c((Unk021cf8ac *) &data_ov003_021da2ac->fieldAB4, data_ov003_021da2ac->field64A);
            return;
        case 2:
            if (func_ov003_021cf32c(2) != 0) {
                data_ov003_021da2ac->fieldA90 = 5;
                return;
            }
            if (func_ov003_021cf32c(3) != 0 || func_ov003_021cf32c(4) != 0) {
                data_ov003_021da2ac->fieldA90 = 6;
                return;
            }
            if (data_ov003_021da2ac->fieldA90 == 5) {
                if (func_ov003_021cf32c(2) == 0) {
                    data_ov003_021da2ac->fieldA90 = 0xd;
                    return;
                }
            }
            break;
        case 3:
            if (func_ov003_021cf64c() != 0) {
                func_ov003_021cf5ac();
                return;
            }
            if ((u8) (data_ov003_021da2ac->fieldA90 + 250) <= 1) {
                if (func_ov003_021cf32c(3) == 0) {
                    data_ov003_021da2ac->fieldA90 = 0x12;
                    return;
                }
            }
            break;
        case 5:
            data_ov003_021da2ac->fieldA90 = 7;
            return;
        case 7:
            func_ov003_021cf598();
            data_ov003_021da2ac->fieldA90 = 1;
            return;
        case 0:
            switch (func_ov003_021d010c()) {
                case 1:
                    func_ov003_021cfa68();
                    return;
                case 0:
                    data_ov003_021da2ac->fieldA90 = 0x1f;
                    return;
                case 3:
                    break;
                default:
                    data_ov003_021da2ac->fieldA90 = 0x1f;
                    break;
            }
            break;
    }
}

void func_ov003_021d0c58(void) {
    func_ov003_021d0a18();
    func_ov003_021cfc40((u32) &func_ov003_021d0a50);
    data_ov003_021da2ac->fieldA90 = 8;
}

void func_ov003_021d0acc(void) {
    u16 a;
    s32 b;

    switch (func_ov003_021d010c()) {
        case 1:
            func_ov003_021cfc4c(4, data_ov003_021da2ac->field648 + 1, data_ov003_021da2ac->field64A);
            break;
        case 4:
        case 5:
        case 6:
            a = data_ov003_021da2ac->field200;
            b = a % 16;
            func_ov003_021d0900(0, a, data_ov003_021da2ac->fieldAA0[1] + (b << 6));
            func_ov003_021d0850();
            if (data_ov003_021da2ac->fieldA90 != 0x1b) {
                if (data_ov003_021da2ac->field204 > 0x1e0) {
                    data_ov003_021da2ac->fieldA90 = 0x1b;
                    return;
                }
                if (func_ov003_021d083c() == 0x10 || func_ov003_021d083c() == 0x20) {
                    func_ov003_021d083c();
                    data_ov003_021da2ac->fieldA90 = 0xa;
                } else if (func_ov003_021d083c() == 0x40) {
                    data_ov003_021da2ac->fieldA90 = 0xb;
                } else if (func_ov003_021d083c() == 0xff) {
                    data_ov003_021da2ac->fieldA90 = 0x1b;
                } else if (func_ov003_021d083c() == 0x50) {
                    data_ov003_021da2ac->fieldA90 = 0x15;
                } else if (func_ov003_021d083c() == 0x60) {
                    data_ov003_021da2ac->fieldA90 = 0x18;
                } else if (func_ov003_021d083c() == 0x70) {
                    data_ov003_021da2ac->fieldA90 = 0x1b;
                } else if (func_ov003_021d083c() == 0) {
                    data_ov003_021da2ac->fieldA90 = 8;
                } else if (func_ov003_021d083c() == 0xbd) {
                    data_ov003_021da2ac->fieldA90 = 9;
                } else {
                    data_ov003_021da2ac->fieldA90 = 0x1f;
                }
            }
            break;
    }
}

void func_ov003_021d0ab8(void) {
    data_ov003_021da2ac->fieldA90 = 0xc;
}

u32 func_ov003_021d0a88(void) {
    int v1;
    v1 = func_ov003_021d010c();
    if (v1 == 1) {
        func_ov003_021cfa68();
        data_ov003_021da2ac->fieldA90 = 1;
        return 1;
    }
    return 0;
}

u32 func_ov003_021d0a50(Unk021425e8 *v1) {
    u16 r = func_ov003_021cf1e8(v1->fieldA);
    if (r == 0) {
        return 0;
    }
    data_ov003_021da2ac->fieldAA0[r - 1] = func_ov003_021cf260(r);
    return 1;
}

void func_ov003_021d0a18(void) {
    MI_CpuFill8(data_ov003_021da2ac->field100, 0, 0x100);
    MI_CpuFill8(data_ov003_021da2ac, 0, 0x100);
    data_ov003_021da2ac->fieldAB0 = (Unk021da2ac_100 *) data_ov003_021da2ac;
}

void func_ov003_021d0900(u16 param_1, u16 param_2, u8 *param_3) {
    u16 i;

    if (data_ov003_021da2ac->fieldA93 == 1) {
        data_ov003_021da2ac->fieldAB0->field0 = param_1;
        data_ov003_021da2ac->fieldAB0->field2 = param_2;
        MI_CpuCopy8(param_3, data_ov003_021da2ac->fieldAB0->field4, 0x40);
    } else {
        data_ov003_021da2ac->field204 = data_ov003_021da2ac->field204 + 1;
        data_ov003_021da2ac->fieldAB0->field0 = 0xbc;
        data_ov003_021da2ac->fieldAB0->field4[0] = data_ov003_021da2ac->fieldA92;
    }
    if (func_ov003_021d010c() == 5) {
        if (func_ov003_021cfb98(data_ov003_021da2ac) == FALSE) {
            data_ov003_021da2ac->field204 = data_ov003_021da2ac->field204 + 4;
            return;
        }
        if (data_ov003_021da2ac->fieldA93 == 0) {
            data_ov003_021da2ac->field204 = data_ov003_021da2ac->field204 + 1;
        } else {
            data_ov003_021da2ac->field204 = 0;
            if (func_ov003_021d0118() != 3) {
                data_ov003_021da2ac->fieldA90 = 0x1b;
                return;
            }
        }
        for (i = 0; i < 2; i++) {
            u8 *p = func_ov003_021cfc1c(i);
            if (p != NULL) {
                MI_CpuCopy8(p, &data_ov003_021da2ac->field100[i], 0x44);
                data_ov003_021da2ac->field208[i] = 1;
            } else {
                data_ov003_021da2ac->field208[i] = 0;
            }
        }
    }
}

void func_ov003_021d0850(void) {
    s32 i;
    Unk021da2ac *p;
    Unk021da2ac_100 *e;

    for (i = 0; i < 16; i++) {
        p = data_ov003_021da2ac;
        if (p->field208[i] != 0) {
            e = &p->field100[(u32) i];
            if (i == 1) {
                if (p->fieldA93 == 1) {
                    if (e->field0 != 0x10) {
                        return;
                    }
                    p->fieldA94 = p->fieldA94 + 1;
                    if ((data_ov003_021da2ac->fieldA94 & 1) == 0) {
                        data_ov003_021da2ac->field200 = data_ov003_021da2ac->field200 + 1;
                        if (data_ov003_021da2ac->field200 >= 0x24) {
                            data_ov003_021da2ac->field200 = 0;
                        }
                    }
                } else {
                    p->field202 = 0xbc;
                    if (e->field0 == 0xbd) {
                        data_ov003_021da2ac->fieldA93 = 1;
                        data_ov003_021da2ac->field200 = 0;
                        data_ov003_021da2ac->fieldA94 = 0;
                    }
                }
            }
        }
    }
}

u16 func_ov003_021d083c(void) {
    return data_ov003_021da2ac->field100[1].field0;
}
