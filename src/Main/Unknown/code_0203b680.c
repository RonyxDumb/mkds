#include "Main/Unknown/code_0203b680.h"

u32 GetMissionTableValue(MissionTable *table, u32 row, u32 column) {
    u32 columnCount = table->mColumnCount;
    column = column - 1;
    row = row - 1;
    return table->mValues[row * columnCount + column];
}
