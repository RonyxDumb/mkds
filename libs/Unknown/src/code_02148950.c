#include "code_02148950.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02180000.h"

// Sets data_0216f070 to 1. When data_021802ac is 0, sets bit 16 of the word at 0x4000000; otherwise replaces bits
// 16-17 of that word with data_021802ac.
void func_021489c4(void) {
    u32 a;

    *(u16 *) data_0216f070 = 1;
    a = *(u16 *) data_021802ac;
    if (a != 0) {
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & ~0x30000) | (a << 16);
    } else {
        *(vu32 *) 0x4000000 |= 0x10000;
    }
}

// Stores a in data_021802ac, then replaces the word at 0x4000000 by (word & 0xfff0fff0) | (a << 16) | b | (c << 3),
// with a taken as 0 when data_0216f070 is 0. Clears data_0216f070 when data_021802ac is 0.
void func_02148950(u16 a, u32 b, s32 c) {
    u32 v;
    u32 x;

    x = *(vu32 *) 0x4000000;
    v = *(u16 *) data_0216f070;
    *(u16 *) data_021802ac = a;
    if (v == 0) {
        a = 0;
    }
    *(vu32 *) 0x4000000 = ((x & 0xfff0fff0) | (a << 16) | b) | (c << 3);
    if (*(u16 *) data_021802ac == 0) {
        *(u16 *) data_0216f070 = 0;
    }
}
