#include "Main/Unknown/code_020e3b08.h"
#include "Main/Unknown/unk_0217b000.h"

u32 bridge_getProgress(void) {
    u32 value0;
    value0 = (u32) &bridge_sRenderPart;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = *(const u32 *) ((value0) + (0));
    value0 = *(const u32 *) ((value0) + (0));
    value0 = *(const u32 *) ((value0) + (340));
    value0 = ((s32) value0 >> 12);
    return value0;
}
