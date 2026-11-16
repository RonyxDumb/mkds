#include "01/code_021854d8.h"
#include "registers.h"

#pragma thumb off

void moverlay_menu_GX_SetVisiblePlane(int bits) {
    (*(u32 *) 0x4000000u) = (*(u32 *) 0x4000000u) & 0xffffe0ff | bits << 8;
}

void moverlay_menu_GXS_SetVisiblePlane(int bits) {
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffffe0ff | bits << 8;
}

#pragma thumb on
