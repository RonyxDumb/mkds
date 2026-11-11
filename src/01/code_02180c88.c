#include "01/code_02180c88.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb off

u32 GetDisplaySettings(void) {
    return ((u32) gDisplaySettings);
}

void TestSceneMTX_Identity22_(s32 *matrix) {
    matrix[0] = 0x1000u;
    matrix[1] = 0x0u;
    matrix[2] = 0x0u;
    matrix[3] = 0x1000u;
}

#pragma thumb on
