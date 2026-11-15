#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/wait_load.h"
#include "Main/Menu/wait.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/data_0216e000.h"
#include "code_02134398.h"
#include "output_effect.h"
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
#include "Main/Graphics/locate_bmg_sections.h"
#include "code_02148950.h"
#include "Main/System/result_archive_path.h"

char *gSelectRaceRuleWaitNcerName = "common/select_race_rule_s.nce.ncer";
char *gSelectRaceRuleWaitBnclName = "common/select_race_rule_s.bncl";
char *gSelectRaceRuleWaitNclrName = "common/select_race_rule_s_o.nclr";
char *gSelectRaceRuleWaitBnllName = "common/select_race_rule_s.bnll";
char *gSelectRaceRuleWaitNcgrName = "common/select_race_rule_s.nce.ncgr";
SelectRaceRuleWait *gSelectRaceRuleWait;

#pragma thumb on

void LocateAndQueueSelectRaceRuleWait(void) {
    void *sceneFile;
    Ncgr *cellChars;
    Nclr *cellPalette[1];
    cellChars = NULL;
    cellPalette[0] = NULL;
    sceneFile = FindSceneFile(gSelectRaceRuleWaitNcerName);
    LocateNcer(&gSelectRaceRuleWait->mNcer, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleWaitNcgrName);
    LocateNcgr2(&cellChars, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleWaitNclrName);
    LocateNclr(cellPalette, sceneFile);
    sceneFile = FindSceneFile(gSelectRaceRuleWaitBnclName);
    gSelectRaceRuleWait->mBncl = sceneFile;
    sceneFile = FindSceneFile(gSelectRaceRuleWaitBnllName);
    gSelectRaceRuleWait->mBnll = sceneFile;
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_TILES, 0, cellChars->mData, cellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_PALETTE, 0, cellPalette[0]->mData,
                                       cellPalette[0]->mDataSize);
}

#pragma thumb off

#pragma thumb on

void RequestSelectRaceRuleWaitSlideIn(void) {
    u16 cellEntryCount;

    gSelectRaceRuleWait->mNextState = SELECT_RACE_RULE_WAIT_SLIDE_IN;
    gSelectRaceRuleWait->mStateFrames = 0;
    cellEntryCount = gSelectRaceRuleWait->mBncl->mCount;
    gSelectRaceRuleWait->mTable[0x2a].mOffsetY = SELECT_RACE_RULE_WAIT_OFFSCREEN_Y;
    gSelectRaceRuleWait->mTable[cellEntryCount + 0xe].mOffsetY = SELECT_RACE_RULE_WAIT_OFFSCREEN_Y;
}

void RequestSelectRaceRuleWaitRest(void) {
    gSelectRaceRuleWait->mNextState = SELECT_RACE_RULE_WAIT_REST;
    gSelectRaceRuleWait->mStateFrames = 0;
}

void RequestSelectRaceRuleWaitSlideOut(void) {
    u16 cellEntryCount;

    gSelectRaceRuleWait->mNextState = SELECT_RACE_RULE_WAIT_SLIDE_OUT;
    gSelectRaceRuleWait->mStateFrames = 0;
    cellEntryCount = gSelectRaceRuleWait->mBncl->mCount;
    gSelectRaceRuleWait->mTable[0x2a].mOffsetY = 0;
    gSelectRaceRuleWait->mTable[cellEntryCount + 0xe].mOffsetY = 0;
}

void InitSelectRaceRuleWait(void *heap, void *oamList) {
    SelectRaceRuleWait *selectRaceRuleWait;
    s32 entryIndex;
    u16 cellEntryCount;
    u32 subObjSize;

    gSelectRaceRuleWait = HeapAlloc(heap, sizeof(*gSelectRaceRuleWait));
    gSelectRaceRuleWait->mState = SELECT_RACE_RULE_WAIT_REST;
    gSelectRaceRuleWait->mOamList = oamList;
    LocateAndQueueSelectRaceRuleWait();
    InitLayoutTable(heap, gSelectRaceRuleWait->mBncl, gSelectRaceRuleWait->mBnll, &gSelectRaceRuleWait->mTable);
    gSelectRaceRuleWait->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    subObjSize = GX_GetSizeOfSubOBJ();
    InitLabelCanvas(heap, 0xe, gSelectRaceRuleWait->mBnll, 0xc8, 0xd, 0, gSelectRaceRuleWait->mNcer,
                    gSelectRaceRuleWait->mBncl, gSelectRaceRuleWait->mTable, subObjSize);
    selectRaceRuleWait = gSelectRaceRuleWait;
    PrintLabelLayoutTextNoFixedAdvance(1, 0xe, gSelectRaceRuleWait->mBnll,
                                       GetBmgEntry(selectRaceRuleWait->mCommonMessages, 0x79),
                                       selectRaceRuleWait->mBncl, selectRaceRuleWait->mTable);
    entryIndex = 0;
    cellEntryCount = gSelectRaceRuleWait->mBncl->mCount;
    for (; entryIndex < cellEntryCount; entryIndex++) {
        gSelectRaceRuleWait->mTable[entryIndex].mVisible = 0;
    }
    gSelectRaceRuleWait->mTable[0x2a].mVisible = 1;
    CreateWait(heap, gSelectRaceRuleWait->mNcer, gSelectRaceRuleWait->mBncl, 0x2a, 0xe, 1);
    RequestSelectRaceRuleWaitSlideIn();
    RequestSelectRaceRuleWaitRest();
    AdvanceSelectRaceRuleWait();
}

#pragma thumb off

#pragma thumb on

void ClearSelectRaceRuleWaitPointer(void) {
    ClearWaitPointer();
    gSelectRaceRuleWait = NULL;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleWaitSlideIn(void) {
    u16 cellEntryCount;
    s16 offsetY;

    cellEntryCount = gSelectRaceRuleWait->mBncl->mCount;
    gSelectRaceRuleWait->mStateFrames++;
    offsetY = InterpolateS16(1, 0xc0, 0, gSelectRaceRuleWait->mStateFrames, 10);
    gSelectRaceRuleWait->mTable[0x2a].mOffsetY = offsetY;
    gSelectRaceRuleWait->mTable[cellEntryCount + 0xe].mOffsetY = offsetY;
    if (gSelectRaceRuleWait->mStateFrames >= SELECT_RACE_RULE_WAIT_SLIDE_STEPS) {
        RequestSelectRaceRuleWaitRest();
    }
}

void AdvanceSelectRaceRuleWaitSlideOut(void) {
    u16 cellEntryCount;
    s16 offsetY;

    cellEntryCount = gSelectRaceRuleWait->mBncl->mCount;
    gSelectRaceRuleWait->mStateFrames++;
    offsetY = InterpolateS16(1, 0, 0xc0, gSelectRaceRuleWait->mStateFrames, 10);
    gSelectRaceRuleWait->mTable[0x2a].mOffsetY = offsetY;
    gSelectRaceRuleWait->mTable[cellEntryCount + 0xe].mOffsetY = offsetY;
    if (gSelectRaceRuleWait->mStateFrames >= SELECT_RACE_RULE_WAIT_SLIDE_STEPS) {
        RequestSelectRaceRuleWaitRest();
    }
}

void AdvanceSelectRaceRuleWait(void) {
    gSelectRaceRuleWait->mState = gSelectRaceRuleWait->mNextState;
    switch (gSelectRaceRuleWait->mState) {
        case SELECT_RACE_RULE_WAIT_SLIDE_IN:
            AdvanceSelectRaceRuleWaitSlideIn();
            break;
        case SELECT_RACE_RULE_WAIT_REST:
            break;
        case SELECT_RACE_RULE_WAIT_SLIDE_OUT:
            AdvanceSelectRaceRuleWaitSlideOut();
            break;
    }
    AdvanceWait();
    DrawLayoutTable(gSelectRaceRuleWait->mBncl, gSelectRaceRuleWait->mNcer, gSelectRaceRuleWait->mBnll,
                    gSelectRaceRuleWait->mOamList, gSelectRaceRuleWait->mTable);
}

void SlideInSelectRaceRuleWait(void) {
    RequestSelectRaceRuleWaitSlideIn();
}

#pragma thumb off

#pragma thumb on

void PlaceSelectRaceRuleWait(void) {
    RequestSelectRaceRuleWaitSlideOut();
    RequestSelectRaceRuleWaitRest();
}

#pragma thumb off

#pragma thumb on
void SlideOutSelectRaceRuleWait(void) {
    u32 unused;
    RequestSelectRaceRuleWaitSlideOut();
}
#pragma thumb off
