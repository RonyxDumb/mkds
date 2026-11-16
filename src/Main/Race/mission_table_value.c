#include "Main/Race/mission_table_value.h"

u32 GetMissionTableRowCount(MissionTable *table) {
    return table->mRowCount;
}

u32 GetMissionTableColumnCount(MissionTable *table) {
    return table->mColumnCount;
}

u32 GetMissionTableValue(MissionTable *table, u32 row, u32 column) {
    u32 columnCount = table->mColumnCount;
    column = column - 1;
    row = row - 1;
    return table->mValues[row * columnCount + column];
}
