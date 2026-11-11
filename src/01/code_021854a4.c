#include "01/code_021854a4.h"
#include "01/code_021854d8.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_021173e4.h"
#include "gx.h"
#include "code_02148950.h"

void WriteSelectCupGridScreenRegisters(void) {
    int screenChanged;
    screenChanged = GetMenuScreenSwitched();
    if (screenChanged != 0) {
        SelectGX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        SelectGXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectCupGridRegisters();
}
