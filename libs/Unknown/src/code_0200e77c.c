#include "code_0200e77c.h"
#include "code_0200cdc0.h"
#include "code_0200ce60.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200f000.h"

u32 data_021617cc = 0xffffffff;

u32 func_0200e8fc(void) {
    return 0;
}

// On the first call stores func_0200e7b0's result with one bit added in the top bits (0x10000000 when
// func_0200e8fc is nonzero, else 0x40000000 when func_0200e77c is nonzero, else 0x20000000 when bit 24 of the
// result is set, else 0x80000000), or-ed with a halfword read from a fixed address. The stored value is -1 until
// then.
u32 func_0200e884(void) {
    u32 a;

    if (data_021617cc == 0xffffffff) {
        a = func_0200e7b0();
        if (func_0200e8fc() != 0) {
            a |= 0x10000000;
        } else if (func_0200e77c() != 0) {
            a |= 0x40000000;
        } else if (a & 0x1000000) {
            a |= 0x20000000;
        } else {
            a |= 0x80000000;
        }
        data_021617cc = a | *(u16 *) 0x27ffffa;
    }
    return data_021617cc;
}

// Repeats, each pass between func_0200fca0 and func_0200fcb4, until func_0200ce80 has been called (it is when
// func_0200ce60 returns 0). The result has bit 24 set when two words at fixed addresses are 0x544e494e and
// 0x4f444e45, else bit 25.
u32 func_0200e7b0(void) {
    u32 a;
    s32 d;
    u32 h;
    s32 v;
    u32 s;

    d = 0;
    h = (u16) func_0200cd28();
    a = 0;
    do {
        v = -1;
        s = func_0200fca0();
        if ((func_0200cdc0((Unk0200ce60 *) 0x27fffe8) & 0x40) != 0 || (v = func_0200ce60(h)) == 0) {
            if (*(u32 *) 0x8000000 == 0x544e494e && *(u32 *) 0x8000004 == 0x4f444e45) {
                a = 0x1000000;
            } else {
                a = 0x2000000;
            }
            if (v == 0) {
                func_0200ce80(h);
                d = 1;
            }
        }
        func_0200fcb4(s);
    } while (d == 0);
    return a;
}

// 1 when a halfword is 1; which of two fixed addresses it is read from depends on whether another halfword is 0.
u32 func_0200e77c(void) {
    u16 *p;

    if (*(u16 *) 0x27ffc10 == 0) {
        p = (u16 *) 0x27ff814;
    } else {
        p = (u16 *) 0x27ffc14;
    }
    return *p == 1;
}
