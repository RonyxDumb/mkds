#include "Main/Unknown/code_02148cd0.h"

u32 func_02148cd0(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    u32 compareLeft2;
    u32 compareRight2;
    u32 compareLeft3;
    u32 compareRight3;
    u32 compareLeft4;
    u32 compareRight4;
    u32 compareLeft5;
    u32 compareRight5;
    u32 compareLeft6;
    u32 compareRight6;
    u32 compareLeft7;
    u32 compareRight7;
    u32 compareLeft8;
    u32 compareRight8;
    value2 = 0u;
    value1 = (value0) & (1u);
    compareLeft0 = value1;
    compareRight0 = 0u;
    if ((u32) compareLeft0 != (u32) compareRight0) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (2u);
    compareLeft1 = value1;
    compareRight1 = 0u;
    if ((u32) compareLeft1 != (u32) compareRight1) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (4u);
    compareLeft2 = value1;
    compareRight2 = 0u;
    if ((u32) compareLeft2 != (u32) compareRight2) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (8u);
    compareLeft3 = value1;
    compareRight3 = 0u;
    if ((u32) compareLeft3 != (u32) compareRight3) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (0x10u);
    compareLeft4 = value1;
    compareRight4 = 0u;
    if ((u32) compareLeft4 != (u32) compareRight4) {
        value2 = (value2) + (0x10000u);
    }
    value1 = (value0) & (0x20u);
    compareLeft5 = value1;
    compareRight5 = 0u;
    if ((u32) compareLeft5 != (u32) compareRight5) {
        value2 = (value2) + (0x4000u);
    }
    value1 = (value0) & (0x40u);
    compareLeft6 = value1;
    compareRight6 = 0u;
    if ((u32) compareLeft6 != (u32) compareRight6) {
        value2 = (value2) + (0x4000u);
    }
    value1 = (value0) & (0x80u);
    compareLeft7 = value1;
    compareRight7 = 0u;
    if ((u32) compareLeft7 != (u32) compareRight7) {
        value2 = (value2) + (0x8000u);
    }
    value0 = (value0) & (0x100u);
    compareLeft8 = value0;
    compareRight8 = 0u;
    if ((u32) compareLeft8 != (u32) compareRight8) {
        value2 = (value2) + (0x4000u);
    }
    value0 = value2;
    return (u32) value0;
}
