/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define CARDi_SetRomOp Card_WriteRomOperation
#include "nitro/types.h"
#include "CARD_pullOut.h"
#include "CARD_rom.h"
#include "MI_dma_card.h"
#include "MI_memory.h"
#include "OS_cache.h"
#include "OS_interrupt.h"
#include "code32.h"

#pragma thumb off
void CARDi_SetRomOp(u32 cmd1, u32 cmd2)
{
    while ((reg_CARD_CNT & CARD_START) != 0) {}

    reg_CARD_MASTERCNT = CARDMST_SEL_ROM | CARDMST_ENABLE | CARDMST_IF_ENABLE;
    {
        vu8 *const p_cmd = &reg_CARD_CMD;
        p_cmd[0] = (u8)(cmd1 >> (8 * 3));
        p_cmd[1] = (u8)(cmd1 >> (8 * 2));
        p_cmd[2] = (u8)(cmd1 >> (8 * 1));
        p_cmd[3] = (u8)(cmd1 >> (8 * 0));
        p_cmd[4] = (u8)(cmd2 >> (8 * 3));
        p_cmd[5] = (u8)(cmd2 >> (8 * 2));
        p_cmd[6] = (u8)(cmd2 >> (8 * 1));
        p_cmd[7] = (u8)(cmd2 >> (8 * 0));
    }
}
