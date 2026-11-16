#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_020b4000.h"

#pragma thumb on
u32 mutil2_loadPortraits(u32 arg0, void *arg1) {
    u32 value0 = arg0;
    u32 value1 = (u32) arg1;
    u32 value4;
    u32 value5;
    value5 = (value0) + (0u);
    value4 = (value1) + (0u);
    value0 = (u32) m2d_getPortraitNceNcgr(value0);
    *(u32 *) ((value4) + 0u) = value0;
    value0 = (value5) + (0u);
    value0 = (u32) m2d_getPortraitNceNcer(value0);
    *(u32 *) ((value4) + 8u) = value0;
    value0 = (value5) + (0u);
    value0 = (u32) m2d_getPortraitONclr(value0);
    *(u32 *) ((value4) + 4u) = value0;
    value0 = (value5) + (0u);
    value0 = (u32) m2d_getPortraitBncl(value0);
    *(u32 *) ((value4) + 12u) = value0;
    return value0;
}
#pragma thumb off
