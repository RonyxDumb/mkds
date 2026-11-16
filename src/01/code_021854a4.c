#include "01/code_021854a4.h"
#include "01/code_021854d8.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_021173e4.h"
#include "gx.h"
#include "code_02148950.h"

void menu_state7Vblank(void) {
    int screenChanged;
    screenChanged = menu_getField4();
    if (screenChanged != 0) {
        moverlay_menu_GX_SetVisiblePlane(0x19);
        GX_SetGraphicsMode(1, 0, 0);
        moverlay_menu_GXS_SetVisiblePlane(0x16);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectCupGridRegisters();
}
