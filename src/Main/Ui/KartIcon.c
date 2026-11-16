#include "Main/Ui/KartIcon.h"
#include "Main/System/Heap.h"

#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_02117224.h"
#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/code_02047104.h"

#pragma thumb on

void kic_unpackDataForGhost(void) {
    void *sceneFile;
    int paletteCount;
    const char **nclrNameCursor;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[2];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = arc_getSceneArcFile(kic_sGhostNcgrName);
    g2du_unpackCharacterDataBG(&chars, sceneFile);
    sceneFile = arc_getSceneArcFile(kic_sGhostNcerName);
    g2du_unpackCellBankData(&cells, sceneFile);
    paletteCount = 0;
    nclrNameCursor = kic_sGhostNclrNames;
    do {
        sceneFile = arc_getSceneArcFile(*nclrNameCursor);
        g2du_unpackPaletteData(palette, sceneFile);
        nclrNameCursor = nclrNameCursor + 1;
        paletteCount = paletteCount + 1;
    } while (paletteCount < 3);
}

void kic_unpackDataForMenu(void) {
    void *sceneFile;
    int paletteCount;
    const char **nclrNameCursor;
    Ncgr *chars;
    Unk02021dc8 *cells;
    Nclr *palette[2];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = arc_getSceneArcFile(kic_sMenuNcgrName);
    g2du_unpackCharacterDataBG(&chars, sceneFile);
    sceneFile = arc_getSceneArcFile(kic_sMenuNcerName);
    g2du_unpackCellBankData(&cells, sceneFile);
    paletteCount = 0;
    nclrNameCursor = kic_sMenuNclrNames;
    do {
        sceneFile = arc_getSceneArcFile(*nclrNameCursor);
        g2du_unpackPaletteData(palette, sceneFile);
        nclrNameCursor = nclrNameCursor + 1;
        paletteCount = paletteCount + 1;
    } while (paletteCount < 3);
}

#pragma thumb off

#pragma thumb on

void kic_initForGhost(void *heap) {
    int i;

    sKartIconData = heap_alloc(heap, 0x18);
    g2du_getCharacterData(&sKartIconData->mNcgr, arc_getSceneArcFile(kic_sGhostNcgrName));
    g2du_getCellBankData(&sKartIconData->mNcer, arc_getSceneArcFile(kic_sGhostNcerName));
    for (i = 0; i < 3; i++) {
        g2du_getPaletteData(&sKartIconData->mNclrs[i], arc_getSceneArcFile(kic_sGhostNclrNames[i]));
    }
    sKartIconData->mBncl = arc_getSceneArcFile(kic_sGhostBnclName);
}

#pragma thumb off

#pragma thumb on

void kic_initForMenu(void *heap) {
    s32 i;

    sKartIconData = heap_alloc(heap, 0x18);
    g2du_getCharacterData(&sKartIconData->mNcgr, arc_getSceneArcFile(kic_sMenuNcgrName));
    g2du_getCellBankData(&sKartIconData->mNcer, arc_getSceneArcFile(kic_sMenuNcerName));
    for (i = 0; i < 3; i++) {
        g2du_getPaletteData(&sKartIconData->mNclrs[i], arc_getSceneArcFile(kic_sMenuNclrNames[i]));
    }
    sKartIconData->mBncl = arc_getSceneArcFile(kic_sMenuBnclName);
}

#pragma thumb off

#pragma thumb on
void kic_free(void) {
    u32 pointerAddress;
    u32 zero;
    zero = 0u;
    pointerAddress = (u32) &sKartIconData;
    *(u32 *) ((pointerAddress) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on

void kic_putIconInLayout(s32 iconIndex, Unk02021dc8 *destinationNcer, Unk0201ea30 *destinationBncl, u32 destinationBnclIndex,
                   u16 paletteIndex, s32 f) {
    int queueKind;

    queueKind = 0x12;
    switch (f) {
        case 0:
            queueKind = 0xe;
            break;
        case 1:
            queueKind = 0x1e;
            break;
    }
    jn_ui_fillPlaceholder(sKartIconConfig[iconIndex].mBnclIndex, sKartIconData->mNcer, sKartIconData->mNcgr, sKartIconData->mBncl, f,
                   destinationBnclIndex, destinationNcer, destinationBncl);
    NNS_GfdRegisterNewVramTransferTask(
        queueKind, paletteIndex * 32,
        sKartIconData->mNclrs[sKartIconConfig[iconIndex].mNclrIndex]->mData + sKartIconConfig[iconIndex].mNclrStart * 16, 0x20);
}

#pragma thumb off
