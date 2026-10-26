#include "00/code_021ac3a8.h"

u32 func_ov000_021ac3a8(u32 arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    u32 value4;
    u32 value5;
    u32 value6;
    value5 = (value0 << 2);
    value4 = (u32) * (const u32 *) ((value1) + (value5));
    value3 = (value0) + (2u);
    value2 = 15u;
    value3 = (value3) & (value2);
    value3 = (value3 << 2);
    value3 = (u32) * (const u32 *) ((value1) + (value3));
    value6 = (value0) + (0u);
    value6 = (value6) + 13u;
    value6 = (value6) & (value2);
    value2 = (value6 << 2);
    value2 = (u32) * (const u32 *) ((value1) + (value2));
    value6 = 8u;
    value0 = (value0) ^ (value6);
    value0 = (value0 << 2);
    value0 = (u32) * (const u32 *) ((value1) + (value0));
    value2 = (value2) ^ (value0);
    value3 = (value3) ^ (value2);
    value4 = (value4) ^ (value3);
    value2 = (value4 << 1);
    value0 = (value4 >> 31);
    value2 = (value2) | (value0);
    *(u32 *) ((value1) + (value5)) = (u32) value2;
    value0 = (u32) * (const u32 *) ((value1) + (value5));
    return (u32) value0;
}
