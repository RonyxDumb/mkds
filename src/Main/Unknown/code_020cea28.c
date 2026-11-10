#include "Main/Unknown/code_020cea28.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "gx.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02025f80.h"

#pragma thumb on

void WriteVsSelectCharacterRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        VsSelectGX_SetVisiblePlane(0xb);
        GX_SetGraphicsMode(1, 0, 1);
        VsSelectGXS_SetVisiblePlane(8);
        GXS_SetGraphicsMode(0);
    }
    VsSelectGXS_SetVisiblePlane(0x12);
    WriteSelectCharacterRegisters();
}

#pragma thumb off
