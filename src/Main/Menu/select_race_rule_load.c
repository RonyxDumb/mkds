#include "Main/Menu/select_race_rule_load.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/wait_load.h"
#include "Main/Menu/data_0216d000.h"
#include "gfd_VramTransferManager.h"

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
    sceneFile = FindSceneFile(gSelectRaceRuleSBNcgrName);
    LoadNcgrData(&bgChars, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleSMenuNscrName);
    LoadNscrData(&screenMap, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleSBNclrName);
    LoadNclrData(bgPalette, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleMultiSimpleSBNcgrName);
    LoadNcgrData(&bgChars, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleMultiSimpleSNscrName);
    LoadNscrData(&screenMap, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleSNcgrName);
    LoadNcgrData2(&cellChars, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleSNcerName);
    LoadNcerData(&cells, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleSONclrName);
    LoadNclrData(&cellPalette, sceneFile);
    LoadWaitData();
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
        sceneFile = FindSceneFile(gSelectRaceRuleMultiSimpleSBNcgrName);
        LocateNcgr(&bgChars, sceneFile);
        sceneFile = FindSceneFile(gSelectRaceRuleMultiSimpleSNscrName);
        LocateNscr(&gSelectRaceRule->mNscr, sceneFile);
        sceneFile = FindSceneFile(gSelectRaceRuleMultiSimpleSBnclName);
        gSelectRaceRule->mBncl = sceneFile;
        sceneFile = FindSceneFile(gSelectRaceRuleMultiSimpleSBnblName);
        gSelectRaceRule->mBnbl = sceneFile;
        sceneFile = FindSceneFile(gSelectRaceRuleMultiSimpleSBnllName);
        gSelectRaceRule->mBnll = sceneFile;
    } else {
        sceneFile = FindSceneFile(gSelectRaceRuleSBNcgrName);
        LocateNcgr(&bgChars, sceneFile);
        sceneFile = FindSceneFile(gSelectRaceRuleSMenuNscrName);
        LocateNscr(&gSelectRaceRule->mNscr, sceneFile);
        sceneFile = FindSceneFile(gSelectRaceRuleSBnclName);
        gSelectRaceRule->mBncl = sceneFile;
        sceneFile = FindSceneFile(gSelectRaceRuleSBnblName);
        gSelectRaceRule->mBnbl = sceneFile;
        sceneFile = FindSceneFile(gSelectRaceRuleSBnllName);
        gSelectRaceRule->mBnll = sceneFile;
    }
    sceneFile = FindSceneFile(gSelectRaceRuleSBNclrName);
    LocateNclr(&bgPalette, sceneFile);
    sceneFile = HeapAlloc(gSelectRaceRule->mHeap, (0x00000800u));
    gSelectRaceRule->mSecondScreenMapBuffer = sceneFile;
    sceneFile = FindSceneFile(gSelectRaceRuleSNcgrName);
    LocateNcgr2(&cellChars, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleSNcerName);
    LocateNcer(&gSelectRaceRule->mNcer, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleSONclrName);
    LocateNclr(&gSelectRaceRule->mNclr, sceneFile);
    NNS_GfdRegisterNewVramTransferTask(0x14, 0, bgChars->mData, bgChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, gSelectRaceRule->mNscr->mData, gSelectRaceRule->mNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, (0x00000800u), gSelectRaceRule->mSecondScreenMapBuffer, (0x00000800u));
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, bgPalette->mData, 0x80);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, cellChars->mData, cellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gSelectRaceRule->mNclr->mData, gSelectRaceRule->mNclr->mDataSize);
}

#pragma thumb off
