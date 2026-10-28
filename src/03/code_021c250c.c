#include "03/code_021c250c.h"

void *func_ov003_021c250c(Unk021c250c *table, u32 index, s32 column, s32 value) {
    u16 *cell = (u16 *) (table->mData + table->mOffsets[index & 0xffff]);
    if (column >= 0) {
        cell[column] = value + 0x30;
    }
    return cell;
}
