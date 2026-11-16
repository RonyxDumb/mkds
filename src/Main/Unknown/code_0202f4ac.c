#include "Main/Unknown/code_0202f4ac.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void sub_202F530(void *dest, u32 fillValue, u32 size) {
    volatile u32 value = fillValue;

    MIi_CpuClearFast(value, dest, size);
}

void sub_202F51C(void *dest, u32 size) {
    sub_202F530(dest, 0, size);
}

void DisplayConfig_SetTopEngineBg1Config_0(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    dc_setBg1Config(displaySettings->mMainBgRecords, b, c, d, e, f, g, h);
}

void DisplayConfig_SetBottomEngineBg3Config_0(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    dc_setBg3Config(displaySettings->mSubBgRecords, b, c, d, e, f, g);
}
