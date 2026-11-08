#include "Main/Unknown/code_0203b680.h"

u32 GetMissionTableValue(u32 table, u32 row, u32 column) {
    u32 columnCount = *OFFSET_PTR(const u16, table, 6);
    column = column - 1;
    row = row - 1;
    table = table + (row * columnCount + column);
    return *OFFSET_PTR(const u8, table, 8);
}
