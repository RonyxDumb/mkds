#include "Main/Menu/wait_load.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"

#include "Main/Menu/select_cup_name_files.h"

#pragma thumb on

char *g_str_common_wait_nclr = "common/wait.nclr";
Wait *gWait = NULL;
char *g_str_common_wait_nce_ncer = "common/wait.nce.ncer";
char *gWaitBnclName = "common/wait.bncl";
char *g_str_common_wait_nce_ncgr = "common/wait.nce.ncgr";

void VerifyCommonWaitFiles_from_thumb(void) {
    void *sceneFile;
    NNSG2dCellDataBank *cells;
    Ncgr *chars;
    Nclr *palette[1];
    cells = NULL;
    chars = NULL;
    palette[0] = NULL;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_wait_nce_ncer);
    LoadCellBankFrom(&cells, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_wait_nce_ncgr);
    Gfx_ReadCharGraphics(&chars, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_wait_nclr);
    Gfx_ReadPalette(palette, sceneFile);
}

void CreateWait(void *heap, NNSG2dCellDataBank *destinationNcer, LayoutEntryTable *destinationBncl,
                u32 destinationBnclIndex, u16 paletteIndex, u32 queueSelector) {
    Wait *wait;
    Wait *newWait;
    void *sceneFile;
    newWait = Mem_AllocateHeap(heap, sizeof(Wait));
    gWait = newWait;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_wait_nce_ncer);
    LocateNcer(&gWait->mNcer, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_wait_nce_ncgr);
    Gfx_ReadCharGraphicsRelative(&gWait->mNcgr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_common_wait_nclr);
    Gfx_ReadPaletteRelative(&gWait->mNclr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gWaitBnclName);
    gWait->mBncl = sceneFile;
    gWait->mDestinationNcer = destinationNcer;
    gWait->mDestinationBncl = destinationBncl;
    gWait->mDestinationBnclIndex = destinationBnclIndex;
    gWait->mPaletteIndex = paletteIndex;
    gWait->mQueueSelector = queueSelector;
    gWait->mFrameIndex = WAIT_FRAME_COUNT - 1;
    gWait->mFrameIndexFrames = WAIT_FRAME_TICKS - 1;
}

#pragma thumb off

#pragma thumb on
void ClearWaitPointer(void) {
    gWait = NULL;
}
#pragma thumb off
