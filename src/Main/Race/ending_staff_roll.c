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

struct EndingStaffRollObject *gEndingStaffRoll;

void UploadEndingStaffRollOam(void) {
    DC_FlushRange(&gEndingStaffRoll->mOamBuffer, 0x400);
    GX_LoadOAM(&gEndingStaffRoll->mOamBuffer, 0, 0x400);
    if (gEndingStaffRoll->mStaffRollFrames == ENDING_STAFF_ROLL_FRAME_FADE_START) {
        StartFadeToFadedNegativeOneScreen(ENDING_STAFF_ROLL_FADE_FRAMES, 1);
        return;
    }
    if (gEndingStaffRoll->mStaffRollFrames != ENDING_STAFF_ROLL_FRAME_FADE_END) {
        return;
    }
    StartFadeToClearNegativeOneScreen(ENDING_STAFF_ROLL_FADE_FRAMES, 1);
}

void InitEndingStaffRoll(void) {
    s32 oamIndex;
    NNSG2dCellDataBank *cells;
    RaceHudOamBits *oamBits;

    gEndingStaffRoll = HeapAlloc(GetHeap(GetCurrentHeapCall()), sizeof(*gEndingStaffRoll));
    for (oamIndex = 0; oamIndex < 0x80; oamIndex++) {
        oamBits = &gEndingStaffRoll->mOamBuffer.mOamBits[oamIndex];
        oamBits->mObjMode = RACE_HUD_OBJ_MODE_BITMAP;
    }
    gEndingStaffRoll->mStaffRollFrames = 0;
    LoadNclrData(&gEndingStaffRoll->mEndingStaffRollMO00Nclr, FindSceneFileWrapper("ending_staffRoll_m_o_00.NCLR"));
    LoadNcgrData2(&gEndingStaffRoll->mEndingStaffRollM00Ncgr, FindSceneFileWrapper("ending_staffRoll_m_00.nce.ncgr"));
    cells = NULL;
    LoadNcerData(&cells, FindSceneFileWrapper("ending_staffRoll_m_00.nce.ncer"));
    gEndingStaffRoll->mCell = NNS_G2dGetCellDataByIdx(cells, 0);
    GX_LoadOBJPltt(gEndingStaffRoll->mEndingStaffRollMO00Nclr->mData, 0,
                   gEndingStaffRoll->mEndingStaffRollMO00Nclr->mDataSize);
    GX_LoadOBJ(gEndingStaffRoll->mEndingStaffRollM00Ncgr->mData, 0,
               gEndingStaffRoll->mEndingStaffRollM00Ncgr->mDataSize);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) |
                     REG_GX_DISPCNT_OBJMAP_CH_MASK;
}

void ClearEndingStaffRollPointer(void) {
    gEndingStaffRoll = NULL;
}

u16 UpdateEndingStaffRoll(void) {
    if (gEndingStaffRoll->mStaffRollFrames < ENDING_STAFF_ROLL_FRAME_CAP) {
        gEndingStaffRoll->mStaffRollFrames++;
    }
    if (gEndingStaffRoll->mStaffRollFrames == ENDING_STAFF_ROLL_FRAME_TEXT_START) {
        StartStaffRollText();
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

    gEndingStaffRoll->mOamBuffer.mOamCount = 0;
    staffRoll = gEndingStaffRoll;
    if (staffRoll->mStaffRollFrames < ENDING_STAFF_ROLL_FRAME_PICTURE_END) {
        oamBuffer = &staffRoll->mOamBuffer;
        oamIndex = oamBuffer->mOamCount;
        cell = staffRoll->mCell;
        position[0] = 0x80000;
        position[1] = 0x60000;
        oamBits = &oamBuffer->mOamBits[oamIndex];
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, position, 0, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++) {
            oamBits->mObjMode = RACE_HUD_OBJ_MODE_TRANSLUCENT;
            oamBits->mPriority = 1;
            oamBits++;
        }
    }
    DC_FlushRange(&gEndingStaffRoll->mOamBuffer, 0x400);
    MI_DmaFill32(3, &gEndingStaffRoll->mOamBuffer.mOams[gEndingStaffRoll->mOamBuffer.mOamCount], 0xc0,
                 (0x80 - gEndingStaffRoll->mOamBuffer.mOamCount) << 3);
}
