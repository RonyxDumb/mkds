#include "g3d_color_mask_tables.h"

const u32 matColorMask_[8] = {0, 0x7fff, 0x7fff0000, 0x7fff7fff, 0x8000, 0xffff, 0x7fff8000, 0x7fffffff};
const u8 pivotUtil_[9][4] = {{4, 5, 7, 8}, {3, 5, 6, 8}, {3, 4, 6, 7}, {1, 2, 7, 8}, {0, 2, 6, 8},
                             {0, 1, 6, 7}, {1, 2, 4, 5}, {0, 2, 3, 5}, {0, 1, 3, 4}};
