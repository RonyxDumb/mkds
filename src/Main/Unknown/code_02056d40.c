#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on
void savd_flushNksy(void) {
    u32 value0;
    u32 value3;
    value0 = (u32) &gSaveData;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = *(const u32 *) ((value0) + 0u);
    savd_writeNksy((void *) value0);
}
#pragma thumb off
