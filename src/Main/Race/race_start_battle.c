#include "Main/Race/race_start_battle.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/data_0217b000.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Race/data_020b837c.h"
#include "g2d_Animation.h"
#include "code_020222ec.h"
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

    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xe000;
    cell = GetRaceStartBattleMNcerEntry(gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON ? VALUE_0 : VALUE_1);
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
