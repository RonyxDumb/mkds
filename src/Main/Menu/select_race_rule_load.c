#include "Main/Menu/select_race_rule_load.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/wait_load.h"
#include "Main/Menu/data_0216d000.h"
#include "gfd_VramTransferManager.h"
#include "Main/Menu/select_race_rule_state.h"

#pragma thumb on

const u16 gSelectRaceRuleStepCellsChanging[5][2] = {{0xa, 0xf}, {0xb, 0x10}, {0xc, 0x11}, {0xd, 0x12}, {0xe, 0x13}};
const u16 gSelectRaceRuleStepCellsPlain[5][2] = {{0x14, 0x19}, {0x15, 0x1a}, {0x16, 0x1b}, {0x17, 0x1c}, {0x18, 0x1d}};
const char *gSelectCupNameMBnclName = "common/select_cup_name_m.bncl";
const u32 gSelectRaceRulePreviousRectRows[5] = {0, 1, 2, 3, 4};
const u32 gSelectRaceRuleEntryInputSlots[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const SelectRaceRuleNscrRect gSelectRaceRuleSMenuNscrRects[5] = {{0, 0, 0x20, 4, 0, 1},
                                                                 {0, 3, 0x20, 4, 0, 2},
                                                                 {0, 7, 0x20, 4, 0, 1},
                                                                 {0, 0xa, 0x20, 6, 0, 2},
                                                                 {0, 0xf, 0x20, 5, 0, 1}};
const SelectRaceRuleNscrRect gSelectRaceRuleMultiSimpleNscrRects[5] = {
    {0, 0, 0, 0, 0, 0}, {0, 0, 0x20, 5, 0, 1}, {0, 0, 0, 0, 0, 0}, {0, 4, 0x20, 8, 0, 2}, {0, 0xb, 0x20, 7, 0, 1}};
const char *gSelectCupNameMNcgrName = "common/select_cup_name_m.nce.ncgr";
const char *gSelectCupNameMNcerName = "common/select_cup_name_m.nce.ncer";

void LoadSelectRaceRuleAndWaitData(void) {
    void *sceneFile;
    Ncgr *cellChars;
    NNSG2dCellDataBank *cells;
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
    if (gSelectRaceRule->mMode == SELECT_RACE_RULE_MODE_BATTLE_MULTI_SIMPLE) {
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
