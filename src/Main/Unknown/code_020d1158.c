#include "Main/Unknown/code_020d1158.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020b837c.h"
#include "code_020222ec.h"
#include "registers.h"

void r2d_renderBattleIntro(RaceHudOamBuffer *oamBuffer) {
    Unk020224e0_c *cell;
    s32 positions[2][2];

    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xe000;
    cell = r2d_getRaceStartBattleMCell(gRaceMultiConfig->mBattleKind == BATTLE_KIND_BALLOON ? VALUE_0 : VALUE_1);
    positions[0][0] = 0x80000;
    positions[0][1] = 0x60000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, positions[0], 0, 1);
    cell = r2d_getRaceStartBattleMCell(2);
    positions[1][0] = 0x80000;
    positions[1][1] = 0x60000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, NULL, positions[1], 0, 1);
}

u16 *cpic_MB_GetMultiBootParam(void) {
    return (u16 *) 0x27ffc40;
}

u32 cpic_MB_IsMultiBootChild(void) {
    return *cpic_MB_GetMultiBootParam() == 2;
}

u32 cpic_MB_IsMultiBootChild_2(void) {
    return cpic_MB_IsMultiBootChild();
}
