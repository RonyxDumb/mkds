#include "Main/Unknown/code_020d1158.h"
#include "Main/Unknown/code_020d129c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d12b0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d1298.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020b837c.h"
#include "code_020222ec.h"
#include "registers.h"
#include "Main/Unknown/code_0211d4a8.h"

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
