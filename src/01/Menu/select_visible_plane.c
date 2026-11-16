#include "01/Menu/select_visible_plane.h"
#include "registers.h"

#pragma thumb off

void SelectGX_SetVisiblePlane(int bits) {
    (*(u32 *) 0x4000000u) = (*(u32 *) 0x4000000u) & 0xffffe0ff | bits << 8;
}

void SelectGXS_SetVisiblePlane(int bits) {
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK | bits << 8;
}

#pragma thumb on
