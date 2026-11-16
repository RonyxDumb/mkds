#include "Main/Unknown/code_0211de00.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_0211df44.h"

#pragma thumb on

void LoadCupMarkData(void) {
    void *sceneFile;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = arc_getSceneArcFile(gCupMarkNcgrName);
    g2du_unpackCharacterDataBG(&chars, sceneFile);
    sceneFile = arc_getSceneArcFile(gCupMarkNcerName);
    g2du_unpackCellBankData(&cells, sceneFile);
    sceneFile = arc_getSceneArcFile(gCupMarkNclrName);
    g2du_unpackPaletteData(palette, sceneFile);
}

void LoadCommonCupMarkData(void) {
    void *sceneFile;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = arc_getSceneArcFile(gCommonCupMarkNcgrName);
    g2du_unpackCharacterDataBG(&chars, sceneFile);
    sceneFile = arc_getSceneArcFile(gCommonCupMarkNcerName);
    g2du_unpackCellBankData(&cells, sceneFile);
    sceneFile = arc_getSceneArcFile(gCommonCupMarkNclrName);
    g2du_unpackPaletteData(palette, sceneFile);
}

void CreateCupMark(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) heap_alloc(heap, 0x10));
    *(s32 *) &gCupMark = allocation;
    sceneFile = arc_getSceneArcFile(gCupMarkNcgrName);
    g2du_getCharacterData(&gCupMark->mNcgr, sceneFile);
    sceneFile = arc_getSceneArcFile(gCupMarkNcerName);
    g2du_getCellBankData(&gCupMark->mNcer, sceneFile);
    sceneFile = arc_getSceneArcFile(gCupMarkNclrName);
    g2du_getPaletteData(&gCupMark->mNclr, sceneFile);
    sceneFile = arc_getSceneArcFile(gCupMarkBnclName);
    gCupMark->mBncl = sceneFile;
}

void CreateCommonCupMark(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) heap_alloc(heap, 0x10));
    *(s32 *) &gCupMark = allocation;
    sceneFile = arc_getSceneArcFile(gCommonCupMarkNcgrName);
    g2du_getCharacterData(&gCupMark->mNcgr, sceneFile);
    sceneFile = arc_getSceneArcFile(gCommonCupMarkNcerName);
    g2du_getCellBankData(&gCupMark->mNcer, sceneFile);
    sceneFile = arc_getSceneArcFile(gCommonCupMarkNclrName);
    g2du_getPaletteData(&gCupMark->mNclr, sceneFile);
    sceneFile = arc_getSceneArcFile(gCommonCupMarkBnclName);
    gCupMark->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on
void ClearCupMarkPointer(void) {
    u32 pointerAddress;
    u32 zero;
    zero = 0u;
    pointerAddress = (u32) &gCupMark;
    *(u32 *) ((pointerAddress) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on

void QueueCupMark(u32 cupMarkIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, u32 d, u16 paletteSlot, s32 f) {
    CupMark *cupMark;
    u8 *dst;
    u32 v0 = 14;
    u32 id;
    u32 paletteIndex;

    if (f != 0) {
        if (f == 1) {
            v0 = 30;
        }
    }
    id = ((u16 *) gCupMarkBnclIndices)[cupMarkIndex];
    cupMark = gCupMark;
    jn_ui_fillPlaceholder(id, cupMark->mNcer, cupMark->mNcgr, cupMark->mBncl, f, d, cells, cellLayout);
    cupMark = gCupMark;
    dst = (u8 *) cupMark->mNclr->mData;
    paletteIndex = GetCellPaletteIndex(id, cupMark->mNcer, cupMark->mBncl);
    NNS_GfdRegisterNewVramTransferTask(v0, paletteSlot << 5, dst + (paletteIndex << 5), 32);
}

void LoadSelectCupNameMData(void) {
    void *sceneFile;
    Ncgr *chars;
    Unk02021dc8 *cells[1];
    chars = NULL;
    cells[0] = NULL;
    sceneFile = arc_getSceneArcFile(gSelectCupNameMNcgrName);
    g2du_unpackCharacterData(&chars, sceneFile);
    sceneFile = arc_getSceneArcFile(gSelectCupNameMNcerName);
    g2du_unpackCellBankData(cells, sceneFile);
}

void CreateSelectCupNameM(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) heap_alloc(heap, 0xc));
    *(s32 *) &gSelectCupNameM = allocation;
    sceneFile = arc_getSceneArcFile(gSelectCupNameMNcgrName);
    g2du_getCharacterData((Ncgr **) gSelectCupNameM, sceneFile);
    sceneFile = arc_getSceneArcFile(gSelectCupNameMNcerName);
    g2du_getCellBankData(&gSelectCupNameM->mNcer, sceneFile);
    sceneFile = arc_getSceneArcFile(gSelectCupNameMBnclName);
    gSelectCupNameM->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on
void ClearSelectCupNameMPointer(void) {
    u32 pointerAddress;
    u32 zero;
    zero = 0u;
    pointerAddress = (u32) &gSelectCupNameM;
    *(u32 *) ((pointerAddress) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on

void QueueSelectCupNameM(u32 nameIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout, u32 d, u32 e) {
    jn_ui_fillPlaceholder(gSelectCupNameMBnclIndices[nameIndex], gSelectCupNameM->mNcer, gSelectCupNameM->mNcgr,
                   gSelectCupNameM->mBncl, e, d, cells, cellLayout);
}

#pragma thumb off
