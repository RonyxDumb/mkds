#include "Main/Unknown/code_020ce9c4.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "code_02148950.h"

#pragma thumb on

void WriteVsSelectKartRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        VsSelectGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(1, 0, 1);
    }
    VsSelectGXS_SetVisiblePlane(0x12);
    WriteSelectKartRegisters();
}

#pragma thumb off
