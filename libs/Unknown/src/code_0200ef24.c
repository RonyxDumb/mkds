#include "code_0200ef24.h"
#include "code_0200c914.h"
#include "code_0200e77c.h"
#include "Main/Unknown/unk_02170000.h"

// non-matching: 0xec bytes against 0x130. The original loads 0x2800 and 0xc00 from words in the code with no
// relocation, keeps them as register values (tests the first against 0 twice and subtracts both); written as
// constants here, they are folded.
u32 func_0200f038(u32 i) {
    u32 a;
    s32 n;
    u32 c;

    switch (i) {
        case 0:
            return 0x23e0000;
        case 2:
            if (data_021701b8 == 0 || (func_0200e884() & 3) == 1) {
                return 0;
            }
            return 0x2700000;
        case 3:
            return 0x2000000;
        case 4:
            a = (u32) &data_027e0000;
            n = 0x2800;
            c = a + 0x3f80 - 0xc00;
            if (n == 0) {
                return a < 0x27e00e0 ? 0x27e00e0 : a;
            }
            if (n < 0) {
                return 0x27e00e0 - n;
            }
            return c - n;
        case 5:
            return 0x27ff680;
        case 6:
            return 0x37f8000;
    }
    return 0;
}

// non-matching: 0xe8 bytes against 0xec. Case 2 returns 0x2400000 loaded from a word in the code with no relocation
// (ldr r0); written as a constant it is mov r0, #0x2400000.
u32 func_0200ef4c(u32 i) {
    switch (i) {
        case 0:
            return 0x21da300;
        case 2:
            if (data_021701b8 == 0 || (func_0200e884() & 3) == 1) {
                return 0;
            }
            return 0x2400000;
        case 3:
            return 0x1ffffa0;
        case 4:
            return 0x27e00e0;
        case 5:
            return 0x27ff000;
        case 6:
            return 0x37f8000;
    }
    return 0;
}

void func_0200ef38(u32 i, u32 v) {
    ((vu32 *) 0x027ffdc4)[i] = v;
}

void func_0200ef24(u32 i, u32 v) {
    ((vu32 *) 0x027ffda0)[i] = v;
}
