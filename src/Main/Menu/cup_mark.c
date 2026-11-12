#include "Main/Menu/cup_mark.h"

#include "Main/Menu/data_0215c000.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/data_0216d000.h"
#include "gfd_VramTransferManager.h"

char *gCommonCupMarkNcerName = "common/cup_mark.nce.ncer";
const u8 gCupMarkBnclIndices[16] = {0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0};
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
    Unk02021dc8 *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gCupMarkNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gCupMarkNcerName);
    LoadNcerData(&cells, sceneFile);
    sceneFile = FindSceneFile(gCupMarkNclrName);
    LoadNclrData(palette, sceneFile);
}

void LoadCommonCupMarkData(void) {
    void *sceneFile;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gCommonCupMarkNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gCommonCupMarkNcerName);
    LoadNcerData(&cells, sceneFile);
    sceneFile = FindSceneFile(gCommonCupMarkNclrName);
    LoadNclrData(palette, sceneFile);
}

void CreateCupMark(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) HeapAlloc(heap, 0x10));
    *(s32 *) &gCupMark = allocation;
    sceneFile = FindSceneFile(gCupMarkNcgrName);
    LocateNcgr2(&gCupMark->mNcgr, sceneFile);
    sceneFile = FindSceneFile(gCupMarkNcerName);
    LocateNcer(&gCupMark->mNcer, sceneFile);
    sceneFile = FindSceneFile(gCupMarkNclrName);
    LocateNclr(&gCupMark->mNclr, sceneFile);
    sceneFile = FindSceneFile(gCupMarkBnclName);
    gCupMark->mBncl = sceneFile;
}

void CreateCommonCupMark(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) HeapAlloc(heap, 0x10));
    *(s32 *) &gCupMark = allocation;
    sceneFile = FindSceneFile(gCommonCupMarkNcgrName);
    LocateNcgr2(&gCupMark->mNcgr, sceneFile);
    sceneFile = FindSceneFile(gCommonCupMarkNcerName);
    LocateNcer(&gCupMark->mNcer, sceneFile);
    sceneFile = FindSceneFile(gCommonCupMarkNclrName);
    LocateNclr(&gCupMark->mNclr, sceneFile);
    sceneFile = FindSceneFile(gCommonCupMarkBnclName);
    gCupMark->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on
void ClearCupMarkPointer(void) {
    gCupMark = NULL;
}
#pragma thumb off

#pragma thumb on

void QueueCupMark(u32 cupMarkIndex, Unk02021dc8 *cells, LayoutEntryTable *cellLayout, u32 destIndex, u16 paletteSlot,
                  s32 queueSelector) {
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
    id = ((u16 *) gCupMarkBnclIndices)[cupMarkIndex];
    cupMark = gCupMark;
    QueueCellChars(id, cupMark->mNcer, cupMark->mNcgr, cupMark->mBncl, queueSelector, destIndex, cells, cellLayout);
    cupMark = gCupMark;
    dst = (u8 *) cupMark->mNclr->mData;
    paletteIndex = GetCellPaletteIndex(id, cupMark->mNcer, cupMark->mBncl);
    NNS_GfdRegisterNewVramTransferTask(transferKind, paletteSlot << 5, dst + (paletteIndex << 5), 32);
}

void LoadSelectCupNameMData(void) {
    void *sceneFile;
    Ncgr *chars;
    Unk02021dc8 *cells[1];
    chars = NULL;
    cells[0] = NULL;
    sceneFile = FindSceneFile(gSelectCupNameMNcgrName);
    LoadNcgrData2(&chars, sceneFile);
    sceneFile = FindSceneFile(gSelectCupNameMNcerName);
    LoadNcerData(cells, sceneFile);
}

void CreateSelectCupNameM(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) HeapAlloc(heap, 0xc));
    *(s32 *) &gSelectCupNameM = allocation;
    sceneFile = FindSceneFile(gSelectCupNameMNcgrName);
    LocateNcgr2(&gSelectCupNameM->mNcgr, sceneFile);
    sceneFile = FindSceneFile(gSelectCupNameMNcerName);
    LocateNcer(&gSelectCupNameM->mNcer, sceneFile);
    sceneFile = FindSceneFile(gSelectCupNameMBnclName);
    gSelectCupNameM->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on
void ClearSelectCupNameMPointer(void) {
    gSelectCupNameM = NULL;
}
#pragma thumb off

#pragma thumb on

void QueueSelectCupNameM(u32 nameIndex, Unk02021dc8 *cells, LayoutEntryTable *cellLayout, u32 destIndex,
                         u32 queueSelector) {
    QueueCellChars(gSelectCupNameMBnclIndices[nameIndex], gSelectCupNameM->mNcer, gSelectCupNameM->mNcgr,
                   gSelectCupNameM->mBncl, queueSelector, destIndex, cells, cellLayout);
}

#pragma thumb off
