#include "Main/Graphics/sub_bg1_cnt.h"
#include "registers.h"

void SetSubBg1Cnt(int cntVal14, int cntVal7, int cntVal8, int cntVal2, int cntVal13) {
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) |
                        (cntVal14 << 14) | (cntVal7 << 7) | (cntVal8 << 8) | (cntVal2 << 2) | (cntVal13 << 13);
}
