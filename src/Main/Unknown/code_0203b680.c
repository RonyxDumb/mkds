#include "Main/Unknown/code_0203b680.h"

u32 GetMissionTableValue(Unk0203b680 *table, u32 row, u32 column) {
    u32 columnCount = table->mUnk_06;
    column = column - 1;
    row = row - 1;
    return table->mUnk_08[row * columnCount + column];
}
