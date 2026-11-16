#include "Main/Unknown/code_0211f240.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"

#include "Main/Unknown/code_0211f2ac.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "code_02016468.h"

#pragma thumb on

void LoadTrophyIconData(void) {
    void *sceneFile;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = arc_getSceneArcFile(gTrophyIconNcgrName);
    g2du_unpackCharacterDataBG(&chars, sceneFile);
    sceneFile = arc_getSceneArcFile(gTrophyIconNcerName);
    g2du_unpackCellBankData(&cells, sceneFile);
    sceneFile = arc_getSceneArcFile(gTrophyIconNclrName);
    g2du_unpackPaletteData(palette, sceneFile);
}

void CreateTrophyIcon(void *heap) {
    int allocation;
    void *sceneFile;
    allocation = ((u32) heap_alloc(heap, 0x10));
    *(s32 *) &gTrophyIcon = allocation;
    sceneFile = arc_getSceneArcFile(gTrophyIconNcgrName);
    g2du_getCharacterData(&gTrophyIcon->mNcgr, sceneFile);
    sceneFile = arc_getSceneArcFile(gTrophyIconNcerName);
    g2du_getCellBankData(&gTrophyIcon->mNcer, sceneFile);
    sceneFile = arc_getSceneArcFile(gTrophyIconNclrName);
    g2du_getPaletteData(&gTrophyIcon->mNclr, sceneFile);
    sceneFile = arc_getSceneArcFile(gTrophyIconBnclName);
    gTrophyIcon->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on

void ClearTrophyIconPointer(void) {
    gTrophyIcon = NULL;
}

#pragma thumb off

#pragma thumb on

void QueueTrophyIcon(int iconIndex, int paletteIndex, void *cells, void *cellLayout, u32 e, u16 paletteSlot, int g) {
    u32 v1;
    TrophyIcon *trophyIcon;
    v1 = 0xe;
    if ((g != 0) && (g == 1)) {
        v1 = 0x1e;
    }
    trophyIcon = gTrophyIcon;
    jn_ui_fillPlaceholder(gTrophyIconBnclIndices[iconIndex], trophyIcon->mNcer, trophyIcon->mNcgr, trophyIcon->mBncl, g, e,
                   cells, cellLayout);
    NNS_GfdRegisterNewVramTransferTask(v1, paletteSlot << 5, (u8 *) gTrophyIcon->mNclr->mData + gTrophyIconNclrStarts[paletteIndex] * 0x20,
                    0x20);
}

void func_0211f240(void) {}

#pragma thumb off
