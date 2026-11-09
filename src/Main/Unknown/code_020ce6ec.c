#include "Main/Unknown/code_020ce6ec.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "Main/Unknown/code_020ce778.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "gx.h"
#include "code_02148950.h"

#pragma thumb on

void WriteVsSelectCupMRegisters(void) {
    int flag;
    flag = GetMenuScreenSwitched();
    if (flag != 0) {
        flag = VsSelectCupIsDownloadBootWrapper();
        if (flag == 0) {
            GxDispCntBits8To12Write(0x19);
            GX_SetGraphicsMode(1, 0, 0);
            GxsDispCntBits8To12Write(0x1e);
            GXS_SetGraphicsMode(0);
        } else {
            GxDispCntBits8To12Write(0x18);
            GX_SetGraphicsMode(1, 0, 0);
            GxsDispCntBits8To12Write(0x12);
            GXS_SetGraphicsMode(0);
        }
    }
    WriteSelectCupMBgOffsets();
}

#pragma thumb off
