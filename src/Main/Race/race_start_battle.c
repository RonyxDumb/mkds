#include "Main/Race/race_start_battle.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Race/race_ncer_entry_getters.h"
#include "sprite_animation_control.h"
#include "cell_animation.h"
#include "registers.h"
#include "Main/Menu/select_race_rule_state.h"

void *gRaceStartBattle;

void InitRaceStartBattle(void) {
    gRaceStartBattle = HeapAlloc(GetHeap(GetCurrentHeapCall()), 4);
}

void ClearRaceStartBattlePointer(void) {
    gRaceStartBattle = NULL;
}

void UpdateRaceStartBattleNop(void) {}

void DrawRaceStartBattle(RaceHudOamBuffer *oamBuffer) {
    NNSG2dCellDataWithBR *cell;
    s32 positions[2][2];

    reg_GX_DISPCNT = reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
    cell = GetRaceStartBattleMNcerEntry(gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON ? RACE_START_BATTLE_BALLOON_CELL
                                                                                       : RACE_START_BATTLE_OTHER_CELL);
    positions[0][0] = 0x80000;
    positions[0][1] = 0x60000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, positions[0], 0, 1);
    cell = GetRaceStartBattleMNcerEntry(2);
    positions[1][0] = 0x80000;
    positions[1][1] = 0x60000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, positions[1], 0, 1);
}

u16 *CupPictureMB_GetMultiBootParam(void) {
    return &gBootInfo->mBootType;
}

u32 CupPictureMB_IsMultiBootChild(void) {
    return *CupPictureMB_GetMultiBootParam() == 2;
}

u32 CupPictureMB_IsMultiBootChildWrapper(void) {
    return CupPictureMB_IsMultiBootChild();
}
