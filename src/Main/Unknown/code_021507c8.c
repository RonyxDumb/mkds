#include "Main/Unknown/code_021507c8.h"

void func_021507c8(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0x67452301u;
    value1 = 0xefcdab89u;
    *(u32 *) ((value0) + (0)) = (u32) value2;
    value2 = 0x98badcfeu;
    *(u32 *) ((value0) + (4)) = (u32) value1;
    value1 = 0x10325476u;
    *(u32 *) ((value0) + (8)) = (u32) value2;
    *(u32 *) ((value0) + (12)) = (u32) value1;
    value1 = 0u;
    *(u32 *) ((value0) + (16)) = (u32) value1;
    *(u32 *) ((value0) + (20)) = (u32) value1;
}
