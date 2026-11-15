#include "Main/Menu/battle_stage_entry.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/battle_gx_set_visible_plane.h"
#include "01/Menu/select_battle_stage_screen.h"
#include "vram_bank_assign.h"
#include "fixed_point_graphics_setup.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/menu_shared_clear.h"

#pragma optimize_for_size on
#pragma thumb on
void WriteBattleStageScreenRegisters(void) {
    if (GetMenuScreenSwitched() != 0) {
        BattleGX_SetVisiblePlane(0x1e);
        GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
        BattleGXS_SetVisiblePlane(0x1f);
        GXS_SetGraphicsMode(GX_BGMODE_0);
    }
    WriteSelectBattleStageRegisters();
}
#pragma thumb off

void BattleStageSetMenuEntryKind(u32 entryKind) {
    gMenuShared->mMenuEntryKind = entryKind;
}

void BattleStageSetRaceSetupRequested(u32 requested) {
    gMenuShared->mRaceSetupRequested = requested;
}
