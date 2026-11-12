#include "Main/Menu/battle_stage_entry.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/battle_gx_set_visible_plane.h"
#include "01/Menu/select_battle_stage_screen.h"
#include "code_02148950.h"
#include "gx.h"
#include "00/Menu/wi_fi_vs_setting.h"

#pragma optimize_for_size on
#pragma thumb on
void WriteBattleStageScreenRegisters(void) {
    if (GetMenuScreenSwitched() != 0) {
        BattleGX_SetVisiblePlane(0x1e);
        GX_SetGraphicsMode(1, 0, 0);
        BattleGXS_SetVisiblePlane(0x1f);
        GXS_SetGraphicsMode(0);
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
