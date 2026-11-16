#include "Main/Unknown/code_020cae38.h"
#include "Main/Unknown/unk_02175000.h"

u32 menu_sysdat_getIsMBChild(void) {
    u32 value0;
    value0 = (u32) &gSystemData;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = *(const u32 *) ((value0) + (28));
    value0 = (value0 << 29);
    value0 = ((s32) value0 >> 31);
    return value0;
}
