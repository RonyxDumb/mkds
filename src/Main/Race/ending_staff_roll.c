#include "Main/Race/ending_staff_roll.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"

#include "thread_scheduler.h"
#include "Main/Graphics/palette_blend.h"
#include "arena_cache_init.h"
#include "cell_animation.h"
#include "dma_copy_fill_wait.h"
#include "Main/System/heap_call.h"
#include "Main/System/file_in_loaded.h"
#include "cell_data_unpack.h"
#include "vram_load_2d_graphics.h"
#include "Main/Graphics/font_and_player_character.h"
#include "registers.h"

struct EndingStaffRollObject *g_StaffRoll;

void LoadStaffRollDataOam(void) {
    Arm_FlushRange(&g_StaffRoll->mOamBuffer, 0x400);
    CopyToOamA(&g_StaffRoll->mOamBuffer, 0, 0x400);
    if (g_StaffRoll->mStaffRollFrames == ENDING_STAFF_ROLL_FRAME_FADE_START) {
        BrightCtx_SomeFn_0(ENDING_STAFF_ROLL_FADE_FRAMES, 1);
        return;
    }
    if (g_StaffRoll->mStaffRollFrames != ENDING_STAFF_ROLL_FRAME_FADE_END) {
        return;
    }
    BrightCtx_SomeFn_1(ENDING_STAFF_ROLL_FADE_FRAMES, 1);
}

void LoadSomeEndingStaffRollStuff(void) {
    s32 oamIndex;
    NNSG2dCellDataBank *cells;
    RaceHudOamBits *oamBits;

    g_StaffRoll = Mem_AllocateHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), sizeof(*g_StaffRoll));
    for (oamIndex = 0; oamIndex < 0x80; oamIndex++) {
        oamBits = &g_StaffRoll->mOamBuffer.mOamBits[oamIndex];
        oamBits->mObjMode = RACE_HUD_OBJ_MODE_BITMAP;
    }
    g_StaffRoll->mStaffRollFrames = 0;
    Gfx_ReadPalette(&g_StaffRoll->mEndingStaffRollMO00Nclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("ending_staffRoll_m_o_00.NCLR"));
    Gfx_ReadCharGraphics(&g_StaffRoll->mEndingStaffRollM00Ncgr, j_FindFileBuffer_K2D_LOC_R2D_R2L("ending_staffRoll_m_00.nce.ncgr"));
    cells = NULL;
    LoadCellBankFrom(&cells, j_FindFileBuffer_K2D_LOC_R2D_R2L("ending_staffRoll_m_00.nce.ncer"));
    g_StaffRoll->mCell = CellBank_GetMetatileEntry(cells, 0);
    CopySomePaletteData(g_StaffRoll->mEndingStaffRollMO00Nclr->mData, 0,
                   g_StaffRoll->mEndingStaffRollMO00Nclr->mDataSize);
    CopyTileDataTop_0(g_StaffRoll->mEndingStaffRollM00Ncgr->mData, 0,
               g_StaffRoll->mEndingStaffRollM00Ncgr->mDataSize);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) |
                     REG_GX_DISPCNT_OBJMAP_CH_MASK;
}

void ResetStaffRoll(void) {
    g_StaffRoll = NULL;
}

u16 IncrementStaffRollFrameCount(void) {
    if (g_StaffRoll->mStaffRollFrames < ENDING_STAFF_ROLL_FRAME_CAP) {
        g_StaffRoll->mStaffRollFrames++;
    }
    if (g_StaffRoll->mStaffRollFrames == ENDING_STAFF_ROLL_FRAME_TEXT_START) {
        RunWhenStaffRollCount();
    }
    return reg_GX_POWCNT;
}

void DrawEndingStaffRoll(void) {
    RaceHudOamBuffer *oamBuffer;
    s32 oamIndex;
    EndingStaffRollObject *staffRoll;
    NNSG2dCellDataWithBR *cell;
    RaceHudOamBits *oamBits;
    s32 position[2];

    g_StaffRoll->mOamBuffer.mOamCount = 0;
    staffRoll = g_StaffRoll;
    if (staffRoll->mStaffRollFrames < ENDING_STAFF_ROLL_FRAME_PICTURE_END) {
        oamBuffer = &staffRoll->mOamBuffer;
        oamIndex = oamBuffer->mOamCount;
        cell = staffRoll->mCell;
        position[0] = 0x80000;
        position[1] = 0x60000;
        oamBits = &oamBuffer->mOamBits[oamIndex];
        oamBuffer->mOamCount +=
            MaybeMakeOamSlot(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, position, 0, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++) {
            oamBits->mObjMode = RACE_HUD_OBJ_MODE_TRANSLUCENT;
            oamBits->mPriority = 1;
            oamBits++;
        }
    }
    Arm_FlushRange(&g_StaffRoll->mOamBuffer, 0x400);
    Mem_DmaFill32(3, &g_StaffRoll->mOamBuffer.mOams[g_StaffRoll->mOamBuffer.mOamCount], 0xc0,
                 (0x80 - g_StaffRoll->mOamBuffer.mOamCount) << 3);
}
