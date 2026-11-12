#include "03/code_021cc8d4.h"
#include "03/code_021d3000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "gx_load2d.h"

#include "03/code_021d3488.h"
#include "03/unk_021da000.h"
#include "code_0214cfe4.h"
#include "03/code_021d27d8.h"
#include "code_0214d018.h"

void CreateBg2ScrBuffer(const void *scr) {
    Bg2ScrBuffer *bg2ScrBuffer = AllocZeroedExpHeapBlock(0x608, 4);
    gBg2ScrBuffer = bg2ScrBuffer;
    MIi_CpuCopyFast(scr, bg2ScrBuffer->mScr, 0x600);
    gBg2ScrBuffer->mTask = AddTask(1, AdvanceBg2ScrUpload, NULL, 0x78);
}

void ReleaseBg2ScrBuffer(void) {
    RemoveTaskEntryWrapper(1, gBg2ScrBuffer->mTask);
    FreeExpHeapBlockAndClearPointer(&gBg2ScrBuffer);
}

void RequestBg2ScrUpload(void) {
    gBg2ScrBuffer->mUploadRequested = 1;
}

void CopyBg2ScrBufferRect(int source, int destOffset, int width, int rowCount) {
    int dest;
    int row;
    dest = (s32) gBg2ScrBuffer + 4 + destOffset * 2;
    row = 0;
    if (rowCount > 0) {
        do {
            MIi_CpuCopy16((const void *) source, (void *) dest, (u32) (width << 1));
            row = row + 1;
            source = source + 0x40;
            dest = dest + 0x40;
        } while (row < rowCount);
    }
}

void AdvanceBg2ScrUpload(void) {
    if (gBg2ScrBuffer->mUploadRequested != 0) {
        DC_FlushRange(gBg2ScrBuffer->mScr, (0x00000600u));
        GX_LoadBG2Scr(gBg2ScrBuffer->mScr, 0, (0x00000600u));
        gBg2ScrBuffer->mUploadRequested = 0;
    }
}

void RequestBgPaletteRowCopy(u8 *palette, u32 srcRow, u32 dstRow) {
    ((u8 **) gBgPaletteCopyRequest)[0] = palette + (srcRow << 5);
    ((u8 **) gBgPaletteCopyRequest)[1] = (u8 *) 0x5000000 + (dstRow << 5);
    AddTask(1, AdvanceBgPaletteRowCopy, NULL, 0x78);
}

void AdvanceBgPaletteRowCopy(u32 entry) {
    MIi_CpuCopy16(((const void **) gBgPaletteCopyRequest)[0], ((void **) gBgPaletteCopyRequest)[1], 0x20);
    RequestTaskRemoval(1, entry);
}

void RequestBgPaletteCopy(u32 palette) {
    *(u32 *) &gBgPaletteCopyRequest = palette;
    AddTask(1, &AdvanceBgPaletteCopy, NULL, 0x78);
}

void AdvanceBgPaletteCopy(u32 entry) {
    MIi_CpuCopy16((const void *) ((*(u32 *) &gBgPaletteCopyRequest)), (void *) ((0x05000000u)), (0x00000200u));
    RequestTaskRemoval(1, entry);
}
