#include "Main/Menu/cup_mark.h"

#include "Main/Menu/kart_icon_row.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/select_cup_name_files.h"
#include "vram_transfer_queue.h"

char *gCommonCupMarkNcerName = "common/cup_mark.nce.ncer";
const u16 gCupMarkBnclIndices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char *gCommonCupMarkBnclName = "common/cup_mark.bncl";
char *gCupMarkNcgrName = "cup_mark.nce.ncgr";
char *gCupMarkNclrName = "cup_mark_o.nclr";
char *gCommonCupMarkNcgrName = "common/cup_mark.nce.ncgr";
char *gCupMarkNcerName = "cup_mark.nce.ncer";
const u16 gSelectCupNameMBnclIndices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char *gCommonCupMarkNclrName = "common/cup_mark_o.nclr";
char *gCupMarkBnclName = "cup_mark.bncl";
SelectCupNameM *gSelectCupNameM;
CupMark *gCupMark;

#pragma thumb on

void LoadCupMarkData(void) {
    void *sceneFile;
    Ncgr *chars;
    NNSG2dCellDataBank *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCupMarkNcgrName);
    Gfx_ReadCharGraphicsV2(&chars, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCupMarkNcerName);
    LoadCellBankFrom(&cells, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCupMarkNclrName);
    Gfx_ReadPalette(palette, sceneFile);
}

void VerifyCupMarkFiles_from_thumb(void) {
    void *sceneFile;
    Ncgr *chars;
    NNSG2dCellDataBank *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCommonCupMarkNcgrName);
    Gfx_ReadCharGraphicsV2(&chars, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCommonCupMarkNcerName);
    LoadCellBankFrom(&cells, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCommonCupMarkNclrName);
    Gfx_ReadPalette(palette, sceneFile);
}

void CreateCupMark(void *heap) {
    void *sceneFile;
    gCupMark = Mem_AllocateHeap(heap, sizeof(*gCupMark));
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCupMarkNcgrName);
    Gfx_ReadCharGraphicsRelative(&gCupMark->mNcgr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCupMarkNcerName);
    LocateNcer(&gCupMark->mNcer, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCupMarkNclrName);
    Gfx_ReadPaletteRelative(&gCupMark->mNclr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCupMarkBnclName);
    gCupMark->mBncl = sceneFile;
}

void CreateCommonCupMark(void *heap) {
    void *sceneFile;
    gCupMark = Mem_AllocateHeap(heap, sizeof(*gCupMark));
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCommonCupMarkNcgrName);
    Gfx_ReadCharGraphicsRelative(&gCupMark->mNcgr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCommonCupMarkNcerName);
    LocateNcer(&gCupMark->mNcer, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCommonCupMarkNclrName);
    Gfx_ReadPaletteRelative(&gCupMark->mNclr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gCommonCupMarkBnclName);
    gCupMark->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on
void ClearCupMarkPointer(void) {
    gCupMark = NULL;
}
#pragma thumb off

#pragma thumb on

void QueueCupMark(u32 cupMarkIndex, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout, u32 destIndex,
                  u16 paletteSlot, s32 queueSelector) {
    CupMark *cupMark;
    u8 *dst;
    u32 transferKind = 14;
    u32 id;
    u32 paletteIndex;

    if (queueSelector != 0) {
        if (queueSelector == 1) {
            transferKind = 30;
        }
    }
    id = gCupMarkBnclIndices[cupMarkIndex];
    cupMark = gCupMark;
    QueueCellChars(id, cupMark->mNcer, cupMark->mNcgr, cupMark->mBncl, queueSelector, destIndex, cells, cellLayout);
    cupMark = gCupMark;
    dst = cupMark->mNclr->mBytes;
    paletteIndex = GetCellPaletteIndex(id, cupMark->mNcer, cupMark->mBncl);
    AllocateReserveTEQSub(transferKind, paletteSlot << 5, dst + (paletteIndex << 5), 32);
}

void VerifySelectCupNameFiles_from_thumb(void) {
    void *sceneFile;
    Ncgr *chars;
    NNSG2dCellDataBank *cells[1];
    chars = NULL;
    cells[0] = NULL;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectCupNameMNcgrName);
    Gfx_ReadCharGraphics(&chars, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectCupNameMNcerName);
    LoadCellBankFrom(cells, sceneFile);
}

void CreateSelectCupNameM(void *heap) {
    void *sceneFile;
    gSelectCupNameM = Mem_AllocateHeap(heap, 0xc);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectCupNameMNcgrName);
    Gfx_ReadCharGraphicsRelative(&gSelectCupNameM->mNcgr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectCupNameMNcerName);
    LocateNcer(&gSelectCupNameM->mNcer, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gSelectCupNameMBnclName);
    gSelectCupNameM->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on
void ClearSelectCupNameMPointer(void) {
    gSelectCupNameM = NULL;
}
#pragma thumb off

#pragma thumb on

void QueueSelectCupNameM(u32 nameIndex, NNSG2dCellDataBank *cells, LayoutEntryTable *cellLayout, u32 destIndex,
                         u32 queueSelector) {
    QueueCellChars(gSelectCupNameMBnclIndices[nameIndex], gSelectCupNameM->mNcer, gSelectCupNameM->mNcgr,
                   gSelectCupNameM->mBncl, queueSelector, destIndex, cells, cellLayout);
}

#pragma thumb off
