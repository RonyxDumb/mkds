#include "Main/Unknown/code_0211db90.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02116dd4.h"
#include "Main/Unknown/unk_0216d000.h"
#include "code_02016468.h"

#pragma thumb on

void LoadSelectRaceRuleAndWaitData(void) {
    void *sceneFile;
    Ncgr *cellChars;
    Unk02021dc8 *cells;
    Nclr *cellPalette;
    Ncgr *bgChars;
    Nscr *screenMap;
    Nclr *bgPalette[1];
    cellChars = NULL;
    cells = NULL;
    cellPalette = NULL;
    bgChars = NULL;
    screenMap = NULL;
    bgPalette[0] = NULL;
    sceneFile = arc_getSceneArcFile(data_0216dbe4);
    g2du_unpackCharacterDataBG(&bgChars, sceneFile);
    sceneFile = arc_getSceneArcFile(data_0216dbf0);
    g2du_unpackScreenData(&screenMap, sceneFile);
    sceneFile = arc_getSceneArcFile(data_0216dbd8);
    g2du_unpackPaletteData(bgPalette, sceneFile);
    sceneFile = arc_getSceneArcFile(data_0216dc08);
    g2du_unpackCharacterDataBG(&bgChars, sceneFile);
    sceneFile = arc_getSceneArcFile(data_0216dbdc);
    g2du_unpackScreenData(&screenMap, sceneFile);
    sceneFile = arc_getSceneArcFile(data_0216dbf8);
    g2du_unpackCharacterData(&cellChars, sceneFile);
    sceneFile = arc_getSceneArcFile(data_0216dc04);
    g2du_unpackCellBankData(&cells, sceneFile);
    sceneFile = arc_getSceneArcFile(data_0216dbec);
    g2du_unpackPaletteData(&cellPalette, sceneFile);
    wait_unpackData();
}

void LocateAndQueueSelectRaceRule(void) {
    void *sceneFile;
    Ncgr *cellChars;
    Ncgr *bgChars;
    Nclr *bgPalette;
    cellChars = NULL;
    bgChars = NULL;
    bgPalette = NULL;
    if (gSelectRaceRule->mMode == 3) {
        sceneFile = arc_getSceneArcFile(data_0216dc08);
        g2du_getCharacterDataBG(&bgChars, sceneFile);
        sceneFile = arc_getSceneArcFile(data_0216dbdc);
        g2du_getScreenData(&gSelectRaceRule->mNscr, sceneFile);
        sceneFile = arc_getSceneArcFile(data_0216dbe0);
        gSelectRaceRule->mBncl = sceneFile;
        sceneFile = arc_getSceneArcFile(data_0216dc00);
        gSelectRaceRule->mBnbl = sceneFile;
        sceneFile = arc_getSceneArcFile(data_0216dbfc);
        gSelectRaceRule->mBnll = sceneFile;
    } else {
        sceneFile = arc_getSceneArcFile(data_0216dbe4);
        g2du_getCharacterDataBG(&bgChars, sceneFile);
        sceneFile = arc_getSceneArcFile(data_0216dbf0);
        g2du_getScreenData(&gSelectRaceRule->mNscr, sceneFile);
        sceneFile = arc_getSceneArcFile(data_0216dbf4);
        gSelectRaceRule->mBncl = sceneFile;
        sceneFile = arc_getSceneArcFile(data_0216dbd4);
        gSelectRaceRule->mBnbl = sceneFile;
        sceneFile = arc_getSceneArcFile(data_0216dbe8);
        gSelectRaceRule->mBnll = sceneFile;
    }
    sceneFile = arc_getSceneArcFile(data_0216dbd8);
    g2du_getPaletteData(&bgPalette, sceneFile);
    sceneFile = heap_alloc(gSelectRaceRule->mHeap, (0x00000800u));
    gSelectRaceRule->mUnk_24 = sceneFile;
    sceneFile = arc_getSceneArcFile(data_0216dbf8);
    g2du_getCharacterData(&cellChars, sceneFile);
    sceneFile = arc_getSceneArcFile(data_0216dc04);
    g2du_getCellBankData(&gSelectRaceRule->mNcer, sceneFile);
    sceneFile = arc_getSceneArcFile(data_0216dbec);
    g2du_getPaletteData(&gSelectRaceRule->mNclr, sceneFile);
    NNS_GfdRegisterNewVramTransferTask(0x14, 0, bgChars->mData, bgChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, gSelectRaceRule->mNscr->mData, gSelectRaceRule->mNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, (0x00000800u), gSelectRaceRule->mUnk_24, (0x00000800u));
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, bgPalette->mData, 0x80);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, cellChars->mData, cellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gSelectRaceRule->mNclr->mData, gSelectRaceRule->mNclr->mDataSize);
}

#pragma thumb off
