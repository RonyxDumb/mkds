#include "Main/Unknown/code_02103840.h"

u32 func_02103840(u32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    u32 compareLeft2;
    u32 compareRight2;
    value1 = (u32) &data_021759c0;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    value1 = (u32) * (const s8 *) ((value1) + (98));
    compareLeft0 = value0;
    compareRight0 = value1;
    if ((u32) compareLeft0 != (u32) compareRight0) {
        return (u32) value0;
    }
    value0 = (u32) &data_0217c658;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    compareLeft1 = value0;
    compareRight1 = 0u;
    if ((u32) compareLeft1 == (u32) compareRight1) {
        return (u32) value0;
    }
    value1 = (u32) &data_0217c644;
    value0 = (u32) &data_0217c650;
    value2 = (u32) * (const u32 *) ((value1) + (0));
    value1 = (u32) * (const u32 *) ((value0) + (0));
    compareLeft2 = value1;
    compareRight2 = value2;
    if ((s32) compareLeft2 < (s32) compareRight2) {
        *(u32 *) ((value0) + (0)) = (u32) value2;
    }
    return (u32) value0;
}
