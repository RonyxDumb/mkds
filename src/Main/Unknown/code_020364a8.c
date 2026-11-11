#include "Main/Unknown/code_020364a8.h"
#include "registers.h"

void SetSubBg1Cnt(int cntVal14, int cntVal7, int cntVal8, int cntVal2, int cntVal13) {
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | (cntVal14 << 14) | (cntVal7 << 7) | (cntVal8 << 8) |
                        (cntVal2 << 2) | (cntVal13 << 13);
}
