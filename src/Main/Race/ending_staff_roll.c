#include "Main/Race/ending_staff_roll.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"

#include "Main/Unknown/code_0200e000.h"
#include "Main/Graphics/palette_blend.h"
#include "code_0200eddc.h"
#include "code_020222ec.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020d1450.h"
#include "Main/Unknown/code_020d1464.h"
#include "Main/System/heap_call.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/System/file_in_loaded.h"
#include "g2d_NOB_load.h"
#include "code_0214b824.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02037000.h"
#include "registers.h"

void UploadEndingStaffRollOam(void) {
    DC_FlushRange(&gEndingStaffRoll->mOamBuffer, 0x400);
    GX_LoadOAM(&gEndingStaffRoll->mOamBuffer, 0, 0x400);
    if (gEndingStaffRoll->mStaffRollFrames == 0x1a4) {
        StartFadeToFadedNegativeOneScreen(0x78, 1);
        return;
    }
    if (gEndingStaffRoll->mStaffRollFrames != 0x77a) {
        return;
    }
    StartFadeToClearNegativeOneScreen(0x78, 1);
}

void InitEndingStaffRoll(void) {
    s32 oamIndex;
    Unk02021dc8 *cells;
    RaceHudOamBits *oamBits;

    gEndingStaffRoll = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x414);
    for (oamIndex = 0; oamIndex < 0x80; oamIndex++) {
        oamBits = &gEndingStaffRoll->mOamBuffer.mOamBits[oamIndex];
        oamBits->mUnk_0a = 3;
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
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
}

void ClearEndingStaffRollPointer(void) {
    gEndingStaffRoll = NULL;
}

u16 UpdateEndingStaffRoll(void) {
    if (gEndingStaffRoll->mStaffRollFrames < 0x7fffffff) {
        gEndingStaffRoll->mStaffRollFrames++;
    }
    if (gEndingStaffRoll->mStaffRollFrames == 0x30c) {
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
    if (staffRoll->mStaffRollFrames < 0x21c) {
        oamBuffer = &staffRoll->mOamBuffer;
        oamIndex = oamBuffer->mOamCount;
        cell = staffRoll->mCell;
        position[0] = 0x80000;
        position[1] = 0x60000;
        oamBits = &oamBuffer->mOamBits[oamIndex];
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cell, NULL, position, 0, 1);
        for (; oamIndex < oamBuffer->mOamCount; oamIndex++) {
            oamBits->mUnk_0a = 1;
            oamBits->mUnk_0e = 1;
            oamBits++;
        }
    }
    DC_FlushRange(&gEndingStaffRoll->mOamBuffer, 0x400);
    MI_DmaFill32(3, &gEndingStaffRoll->mOamBuffer.mOams[gEndingStaffRoll->mOamBuffer.mOamCount], 0xc0,
                 (0x80 - gEndingStaffRoll->mOamBuffer.mOamCount) << 3);
}
