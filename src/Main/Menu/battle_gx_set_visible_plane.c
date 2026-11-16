#include "Main/Menu/battle_gx_set_visible_plane.h"
#include "registers.h"

void BattleGX_SetVisiblePlane(int bits) {
    u32 newDispcnt = bits;
    u32 maskedDispcnt;
    maskedDispcnt = reg_GX_DISPCNT;
    maskedDispcnt = (maskedDispcnt) & ~(0x1f00u);
    newDispcnt = (maskedDispcnt) | ((newDispcnt << 8));
    reg_GX_DISPCNT = newDispcnt;
}

void BattleGXS_SetVisiblePlane(int bits) {
    u32 newDispcnt = bits;
    u32 maskedDispcnt;
    maskedDispcnt = reg_GXS_DB_DISPCNT;
    maskedDispcnt = (maskedDispcnt) & ~(0x1f00u);
    newDispcnt = (maskedDispcnt) | ((newDispcnt << 8));
    reg_GXS_DB_DISPCNT = newDispcnt;
}
