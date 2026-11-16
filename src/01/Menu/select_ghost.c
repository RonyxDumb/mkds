#include "01/Menu/select_ghost.h"

#include "01/MapObjects/mission_run_map_object_flags.h"
#include "Main/System/heap.h"
#include "Main/Kart/shadow_model_draw.h"
#include "01/Menu/menu_screen_states_and_file_names.h"
#include "animation_lookup.h"
#include "Main/System/heap_call.h"
#include "print_memory_multibyte_write.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Graphics/time_format.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/cup_mark.h"
#include "Main/Race/ghost_record_set.h"
#include "Main/Menu/select_return.h"
#include "Main/Graphics/oam.h"
#include "Main/Graphics/palette_blend.h"
#include "Main/System/input_slots.h"
#include "Main/Graphics/layout_rect_table.h"
#include "registers.h"
#include "vram_bank_display_setup.h"
#include "sound_player_control.h"
#include "sound_archive_load_result.h"
#include "01/Menu/record_gpx_grade_text.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Sound/sound_system.h"
#include "Main/System/init_after_startup.h"

const u16 gSelectGhostSTableIndices[6] = {0, 1, 2, 4, 3, 5};
char *gSelectGhostSONcerName = "ta/select_ghost_s_o.nce.ncer";
char *gSelectGhostSBnllName = "ta/select_ghost_s.bnll";
const u16 gSelectGhostTimerZeroSTableIndices[2] = {6, 8};
const u16 gSelectGhostCharacterCells[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xa, 0xb, 0xc};
const u16 gSelectGhostRunningSTableIndices[2] = {7, 9};
const u32 gSelectGhostCupIndices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char *gSelectGhostSBNclrName = "ta/select_ghost_s_b.nclr";
char *gSelectGhostSONcgrName = "ta/select_ghost_s_o.nce.ncgr";
char *gSelectGhostSONclrName = "ta/select_ghost_s_o.nclr";
const u16 gSelectGhostSBnllIndices[5] = {0, 1, 2, 3, 4};
char *gSelectGhostSBnblName = "ta/select_ghost_s.bnbl";
const u16 gSelectGhostSLabelHeights[5] = {0xd, 0xd, 0xd, 0xd, 0xf};
char *gSelectGhostSBNcgrName = "ta/select_ghost_s_b.ncgr";
const u32 gSelectGhostRecordKinds[SELECT_GHOST_KIND_COUNT] = {4, 0, 1, 2};
const u16 gSelectGhostSLabelWidths[5] = {0x3c, 0x50, 0x82, 0xba, 0xba};
const u16 gSelectGhostMenuMessageIndices[SELECT_GHOST_KIND_COUNT] = {0xa, 0xb, 0xc, 0xd};
char *gSelectGhostSelectCupCourseTaMBnclName = "common/select_cup_course_ta_m.bncl";
char *gSelectGhostSelectCupCourseTaMBnllName = "common/select_cup_course_ta_m.bnll";
char *gSelectGhostSelectCupCourseMNcerName = "common/select_cup_course_m.nce.ncer";
char *gSelectGhostSBnclName = "ta/select_ghost_s.bncl";
char *gSelectGhostSNscrName = "ta/select_ghost_s.nscr";
SelectGhost *gSelectGhost;

void LoadSelectGhostAndKartIconData(void) {
    Ncgr *selectGhostSONcgr = NULL;
    NNSG2dCellDataBank *selectGhostSONcer = NULL;
    Nclr *selectGhostSONclr = NULL;
    Ncgr *selectGhostSBNcgr = NULL;
    Nclr *selectGhostSBNclr = NULL;
    Nscr *selectGhostSNscr = NULL;

    LoadNcgrData(&selectGhostSBNcgr, FindSceneFile(gSelectGhostSBNcgrName));
    LoadNscrData(&selectGhostSNscr, FindSceneFile(gSelectGhostSNscrName));
    LoadNclrData(&selectGhostSBNclr, FindSceneFile(gSelectGhostSBNclrName));
    LoadNcgrData2(&selectGhostSONcgr, FindSceneFile(gSelectGhostSONcgrName));
    LoadNcerData(&selectGhostSONcer, FindSceneFile(gSelectGhostSONcerName));
    LoadNclrData(&selectGhostSONclr, FindSceneFile(gSelectGhostSONclrName));
    LoadCommonKartIconData();
}

void LocateAndQueueSelectGhost(void) {
    Ncgr *selectGhostSONcgr;
    Ncgr *selectGhostSBNcgr;
    Nclr *selectGhostSBNclr;
    Nscr *selectGhostSNscr;

    selectGhostSONcgr = NULL;
    selectGhostSBNcgr = NULL;
    selectGhostSBNclr = NULL;
    selectGhostSNscr = NULL;
    LocateNcgr(&selectGhostSBNcgr, FindSceneFile(gSelectGhostSBNcgrName));
    LocateNscr(&selectGhostSNscr, FindSceneFile(gSelectGhostSNscrName));
    LocateNclr(&selectGhostSBNclr, FindSceneFile(gSelectGhostSBNclrName));
    gSelectGhost->mSecondScreenMapBuffer = HeapAlloc(gSelectGhost->mHeap, SECOND_SCREEN_MAP_BYTES);
    gSelectGhost->mSelectCupCourseTaMCellLayout = FindSceneFile(gSelectGhostSelectCupCourseTaMBnclName);
    gSelectGhost->mSelectCupCourseTaMLabelLayout = FindSceneFile(gSelectGhostSelectCupCourseTaMBnllName);
    LocateNcer(&gSelectGhost->mSelectCupCourseMNcer, FindSceneFile(gSelectGhostSelectCupCourseMNcerName));
    gSelectGhost->mSelectGhostSCellLayout = FindSceneFile(gSelectGhostSBnclName);
    gSelectGhost->mSelectGhostSRects = FindSceneFile(gSelectGhostSBnblName);
    gSelectGhost->mSelectGhostSLabelLayout = FindSceneFile(gSelectGhostSBnllName);
    LocateNcgr2(&selectGhostSONcgr, FindSceneFile(gSelectGhostSONcgrName));
    LocateNcer(&gSelectGhost->mSelectGhostSOCells, FindSceneFile(gSelectGhostSONcerName));
    LocateNclr(&gSelectGhost->mSelectGhostSOPalette, FindSceneFile(gSelectGhostSONclrName));
    gSelectGhost->mPlayerCharacterMNcgr = GetPlayerCharacterNcgr(0);
    gSelectGhost->mPlayerCharacterMNcer = GetPlayerCharacterNcer(0);
    gSelectGhost->mPlayerCharacterMONclr = GetPlayerCharacterNclr(0);
    gSelectGhost->mPlayerCharacterMBncl = GetPlayerCharacterBncl(0);
    NNS_GfdRegisterNewVramTransferTask(0x17, 0, selectGhostSBNcgr->mData, selectGhostSBNcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1f, 0, selectGhostSBNclr->mData, 0x20);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0, selectGhostSNscr->mData, selectGhostSNscr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1b, 0x800, gSelectGhost->mSecondScreenMapBuffer, SECOND_SCREEN_MAP_BYTES);
    NNS_GfdRegisterNewVramTransferTask(0x23, 0, selectGhostSONcgr->mData, selectGhostSONcgr->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0, gSelectGhost->mSelectGhostSOPalette->mData,
                                       gSelectGhost->mSelectGhostSOPalette->mDataSize);
}

void ResetSelectGhost(void) {
    u16 layoutCount;
    s32 index;

    gSelectGhost->mNextState = SELECT_GHOST_STATE_SLIDE_IN;
    gSelectGhost->mStateFrames = 0;
    gSelectGhost->mBg0Offset = 0;
    gSelectGhost->mBg3Offset = -0xc0;
    for (index = 0; index < 6; index++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[index]].mOffsetY = -0xc0;
    }
    gSelectGhost->mSelectGhostSTable[10].mOffsetY = -0xc0;
    gSelectGhost->mSelectGhostSTable[11].mOffsetY = -0xc0;
    layoutCount = gSelectGhost->mSelectGhostSCellLayout->mCount;
    for (index = 0; index < 5; index++) {
        gSelectGhost->mSelectGhostSTable[layoutCount + gSelectGhostSBnllIndices[index]].mOffsetY = -0xc0;
    }
    gSelectGhost->mSelectGhostSTable[layoutCount + 5].mOffsetY = -0xc0;
    for (index = 0; index < 2; index++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[index]].mOffsetY = -0xc0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[index]].mOffsetY = -0xc0;
    }
}

// Requests state 1.
void RequestSelectGhostReturnSlideIn(void) {
    gSelectGhost->mNextState = SELECT_GHOST_STATE_RETURN_SLIDE_IN;
    gSelectGhost->mStateFrames = 0;
}

// Requests state 2.
void RequestSelectGhostInput(void) {
    gSelectGhost->mNextState = SELECT_GHOST_STATE_INPUT;
    gSelectGhost->mStateFrames = 0;
}

void RequestSelectGhostPress(void) {
    gSelectGhost->mNextState = SELECT_GHOST_STATE_PRESS;
    gSelectGhost->mStateFrames = 0;
    StopPaletteBlend();
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 5);
}

void RequestSelectGhostChoisesOpen(void) {
    gSelectGhost->mNextState = SELECT_GHOST_STATE_CHOISES_OPEN;
    gSelectGhost->mStateFrames = 0;
    StartSelectChoises(GetBmgEntry(gSelectGhost->mCommonMessages, 4), GetBmgEntry(gSelectGhost->mCommonMessages, 2), 0);
}

// Requests state 5.
void RequestSelectGhostChoisesInput(void) {
    gSelectGhost->mNextState = SELECT_GHOST_STATE_CHOISES_INPUT;
    gSelectGhost->mStateFrames = 0;
}

void RequestSelectGhostChoisesClose(void) {
    gSelectGhost->mNextState = SELECT_GHOST_STATE_CHOISES_CLOSE;
    gSelectGhost->mStateFrames = 0;
    RequestSelectChoisesHidden();
}

// Requests state 7.
void RequestSelectGhostSlideOut(void) {
    gSelectGhost->mNextState = SELECT_GHOST_STATE_SLIDE_OUT;
    gSelectGhost->mStateFrames = 0;
}

void UpdateSelectGhostCellVisibility(void) {
    gSelectGhost->mSelectGhostSTable[10].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[11].mVisible = 0;
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[0]].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[1]].mVisible = 0;
    gSelectGhost->mSelectGhostSTable[10].mVisible = 0;
    gSelectGhost->mSelectGhostSTable[11].mVisible = 1;
}

// Stores both offsets and steps both timers; each timer switches its rows on or off.
void AdvanceSelectGhostOffsetTimers(void) {
    s32 timerIndex;
    gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[0]].mOffsetX =
        -LookupFrameOffset(SELECT_GHOST_OFFSET_TIMER_FRAMES - gSelectGhost->mOffsetTimers[0]);
    gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[1]].mOffsetX =
        LookupFrameOffset(SELECT_GHOST_OFFSET_TIMER_FRAMES - gSelectGhost->mOffsetTimers[1]);
    for (timerIndex = 0; timerIndex < 2; timerIndex++) {
        if (gSelectGhost->mOffsetTimers[timerIndex] > 0) {
            gSelectGhost->mOffsetTimers[timerIndex]--;
            gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[timerIndex]].mVisible = 0;
            gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[timerIndex]].mVisible = 1;
        } else {
            gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[timerIndex]].mVisible = 1;
            gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[timerIndex]].mVisible = 0;
        }
    }
}

void RefreshSelectGhostForIndex(void) {
    SelectGhost *selectGhost = gSelectGhost;
    LayoutEntryTable *subLayout;
    u16 subLayoutCount;
    u16 characterCellIndex;
    u16 kartCellIndex;
    u16 nameLabelIndex;
    u16 timeLabelIndex;
    u16 *paletteData;
    s32 characterCell;
    s32 ghostRecordSetKartIndex;
    u8 recordTime[4];
    u16 labelText[16];

    subLayout = selectGhost->mSelectGhostSCellLayout;
    subLayoutCount = subLayout->mCount;
    PrintLabelLayoutTextNoFixedAdvance(
        1, gSelectGhostSBnllIndices[4], gSelectGhost->mSelectGhostSLabelLayout,
        GetBmgEntry(selectGhost->mMenuMessages, gSelectGhostMenuMessageIndices[selectGhost->mIndex]), subLayout,
        selectGhost->mSelectGhostSTable);
    if (gSelectGhost->mIndex == 0) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[2]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[3]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[4]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[5]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[subLayoutCount + gSelectGhostSBnllIndices[0]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[subLayoutCount + gSelectGhostSBnllIndices[1]].mVisible = 0;
        gSelectGhost->mSelectGhostSTable[subLayoutCount + gSelectGhostSBnllIndices[2]].mVisible = 0;
        return;
    }
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[2]].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[3]].mVisible = 1;
    characterCellIndex = gSelectGhostSTableIndices[4];
    gSelectGhost->mSelectGhostSTable[characterCellIndex].mVisible = 1;
    kartCellIndex = gSelectGhostSTableIndices[5];
    gSelectGhost->mSelectGhostSTable[kartCellIndex].mVisible = 1;
    gSelectGhost->mSelectGhostSTable[subLayoutCount + gSelectGhostSBnllIndices[0]].mVisible = 1;
    timeLabelIndex = gSelectGhostSBnllIndices[1];
    gSelectGhost->mSelectGhostSTable[subLayoutCount + timeLabelIndex].mVisible = 1;
    nameLabelIndex = gSelectGhostSBnllIndices[2];
    gSelectGhost->mSelectGhostSTable[subLayoutCount + nameLabelIndex].mVisible = 1;
    characterCell =
        gSelectGhostCharacterCells[GetGhostRecordSetCharacterIndex(gSelectGhostRecordKinds[gSelectGhost->mIndex])];
    QueueCellChars(characterCell, gSelectGhost->mPlayerCharacterMNcer, gSelectGhost->mPlayerCharacterMNcgr,
                   gSelectGhost->mPlayerCharacterMBncl, 1, characterCellIndex, gSelectGhost->mSelectGhostSOCells,
                   gSelectGhost->mSelectGhostSCellLayout);
    paletteData = gSelectGhost->mPlayerCharacterMONclr->mData;
    NNS_GfdRegisterNewVramTransferTask(0x1e, 0x100,
                                       (u8 *) paletteData +
                                           (GetCellPaletteIndex(characterCell, gSelectGhost->mPlayerCharacterMNcer,
                                                                gSelectGhost->mPlayerCharacterMBncl)
                                            << 5),
                                       0x20);
    ghostRecordSetKartIndex = GetGhostRecordSetKartIndex(gSelectGhostRecordKinds[gSelectGhost->mIndex]);
    QueueKartIcon(ghostRecordSetKartIndex, gSelectGhost->mSelectGhostSOCells, gSelectGhost->mSelectGhostSCellLayout,
                  kartCellIndex, 9, 1);
    GetGhostRecordSetTime(gSelectGhostRecordKinds[gSelectGhost->mIndex], recordTime);
    FormatTimeFullWidth(recordTime, labelText);
    PrintLabelLayoutTextFixedDigits(1, timeLabelIndex, gSelectGhost->mSelectGhostSLabelLayout, labelText,
                                    gSelectGhost->mSelectGhostSCellLayout, gSelectGhost->mSelectGhostSTable, 9);
    GetGhostRecordSetName(gSelectGhostRecordKinds[gSelectGhost->mIndex], labelText);
    PrintLabelLayoutTextNoFixedAdvance(1, nameLabelIndex, gSelectGhost->mSelectGhostSLabelLayout, labelText,
                                       gSelectGhost->mSelectGhostSCellLayout, gSelectGhost->mSelectGhostSTable);
}

void IncrementSelectGhostIndex(void) {
    BOOL selectable = TRUE;
    gSelectGhost->mIndex++;
    if (gSelectGhost->mIndex >= SELECT_GHOST_KIND_COUNT) {
        gSelectGhost->mIndex = 0;
    }
    if (IsGhostRecordSetKindSelectable(gSelectGhostRecordKinds[gSelectGhost->mIndex]) == 0) {
        selectable = FALSE;
        IncrementSelectGhostIndex();
    }
    gSelectGhost->mOffsetTimers[1] = SELECT_GHOST_OFFSET_TIMER_FRAMES;
    if (selectable != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 1);
        RefreshSelectGhostForIndex();
    }
}

void DecrementSelectGhostIndex(void) {
    BOOL selectable = TRUE;
    gSelectGhost->mIndex--;
    if (gSelectGhost->mIndex < 0) {
        gSelectGhost->mIndex = SELECT_GHOST_KIND_COUNT - 1;
    }
    if (IsGhostRecordSetKindSelectable(gSelectGhostRecordKinds[gSelectGhost->mIndex]) == 0) {
        selectable = FALSE;
        DecrementSelectGhostIndex();
    }
    gSelectGhost->mOffsetTimers[0] = SELECT_GHOST_OFFSET_TIMER_FRAMES;
    if (selectable != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 1);
        RefreshSelectGhostForIndex();
    }
}

void ReadSelectGhostRecords(void) {
    SetRaceSetupCopyGhostRecordIndex(gSelectGhostRecordKinds[gSelectGhost->mIndex]);
    ReadGhostRecordsForKind(gSelectGhostRecordKinds[gSelectGhost->mIndex]);
}

void SetupSelectGhostCupCells(void) {
    u16 layoutCount = gSelectGhost->mSelectCupCourseTaMCellLayout->mCount;

    gSelectGhost->mSelectCupCourseTaMTable[0].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[2].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[1].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[4].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[3].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[5].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[layoutCount].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[layoutCount + 1].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[layoutCount + 2].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[layoutCount + 3].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[layoutCount + 4].mVisible = 1;
    gSelectGhost->mSelectCupCourseTaMTable[layoutCount + 5].mVisible = 1;
    QueueSelectCupNameM(gSelectGhostCupIndices[GetCupIndex()], gSelectGhost->mSelectCupCourseMNcer,
                        gSelectGhost->mSelectCupCourseTaMCellLayout, 0, 0);
    QueueCupMark(gSelectGhostCupIndices[GetCupIndex()], gSelectGhost->mSelectCupCourseMNcer,
                 gSelectGhost->mSelectCupCourseTaMCellLayout, 5,
                 GetCellPaletteIndex(5, gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMCellLayout), 0);
    PrintLabelLayoutTextNoFixedAdvance(0, 2, gSelectGhost->mSelectCupCourseTaMLabelLayout,
                                       GetBmgEntry(gSelectGhost->mCommonMessages, 0x73),
                                       gSelectGhost->mSelectCupCourseTaMCellLayout, gSelectGhost->mSelectCupCourseTaMTable);
    PrintLabelLayoutTextNoFixedAdvance(0, 4, gSelectGhost->mSelectCupCourseTaMLabelLayout,
                                       GetBmgEntry(gSelectGhost->mCommonMessages, 0x74),
                                       gSelectGhost->mSelectCupCourseTaMCellLayout, gSelectGhost->mSelectCupCourseTaMTable);
    SetLabelOamModeXlu(0, 0, gSelectGhost->mSelectCupCourseTaMLabelLayout, gSelectGhost->mSelectCupCourseTaMTable,
                       gSelectGhost->mSelectCupCourseTaMCellLayout);
    SetLabelOamModeXlu(1, 0, gSelectGhost->mSelectCupCourseTaMLabelLayout, gSelectGhost->mSelectCupCourseTaMTable,
                       gSelectGhost->mSelectCupCourseTaMCellLayout);
    SetLabelOamModeXlu(2, 0, gSelectGhost->mSelectCupCourseTaMLabelLayout, gSelectGhost->mSelectCupCourseTaMTable,
                       gSelectGhost->mSelectCupCourseTaMCellLayout);
    SetLabelOamModeXlu(4, 0, gSelectGhost->mSelectCupCourseTaMLabelLayout, gSelectGhost->mSelectCupCourseTaMTable,
                       gSelectGhost->mSelectCupCourseTaMCellLayout);
}

void InitSelectGhost(void *parentHeap, void *mainOam, void *subOam) {
    void *heap;
    s32 remainingSize;
    s32 index;

    reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~REG_G2S_DB_BG0CNT_PRIORITY_MASK;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 1;
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x8300;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectGhost = HeapAlloc(heap, sizeof(SelectGhost));
    gSelectGhost->mHeap = heap;
    gSelectGhost->mState = SELECT_GHOST_STATE_SLIDE_IN;
    gSelectGhost->mIndex = 0;
    gSelectGhost->mMainOamList = mainOam;
    gSelectGhost->mSubOamList = subOam;
    gSelectGhost->mResult = SELECT_GHOST_RESULT_NONE;
    LocateAndQueueSelectGhost();
    CreateCommonKartIcon(gSelectGhost->mHeap);
    InitLayoutTable(gSelectGhost->mHeap, gSelectGhost->mSelectCupCourseTaMCellLayout, gSelectGhost->mSelectCupCourseTaMLabelLayout,
                    &gSelectGhost->mSelectCupCourseTaMTable);
    InitLayoutTable(gSelectGhost->mHeap, gSelectGhost->mSelectGhostSCellLayout, gSelectGhost->mSelectGhostSLabelLayout,
                    &gSelectGhost->mSelectGhostSTable);
    gSelectGhost->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    gSelectGhost->mMenuMessages = FindSceneFile("menu.bmg");
    remainingSize = 0x8000;
    remainingSize -= InitLabelCanvas(gSelectGhost->mHeap, 0, gSelectGhost->mSelectCupCourseTaMLabelLayout, 0xb4, 0xd, 0,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMCellLayout,
                           gSelectGhost->mSelectCupCourseTaMTable, remainingSize);
    remainingSize -= InitLabelCanvas(gSelectGhost->mHeap, 1, gSelectGhost->mSelectCupCourseTaMLabelLayout, 0xb4, 0xd, 1,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMCellLayout,
                           gSelectGhost->mSelectCupCourseTaMTable, remainingSize);
    remainingSize -= InitLabelCanvas(gSelectGhost->mHeap, 2, gSelectGhost->mSelectCupCourseTaMLabelLayout, 0x96, 0xd, 2,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMCellLayout,
                           gSelectGhost->mSelectCupCourseTaMTable, remainingSize);
    remainingSize -= InitLabelCanvas(gSelectGhost->mHeap, 3, gSelectGhost->mSelectCupCourseTaMLabelLayout, 0x50, 0xd, 3,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMCellLayout,
                           gSelectGhost->mSelectCupCourseTaMTable, remainingSize);
    remainingSize -= InitLabelCanvas(gSelectGhost->mHeap, 4, gSelectGhost->mSelectCupCourseTaMLabelLayout, 0x96, 0xd, 4,
                           gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMCellLayout,
                           gSelectGhost->mSelectCupCourseTaMTable, remainingSize);
    InitLabelCanvas(gSelectGhost->mHeap, 5, gSelectGhost->mSelectCupCourseTaMLabelLayout, 0x50, 0xd, 5,
                    gSelectGhost->mSelectCupCourseMNcer, gSelectGhost->mSelectCupCourseTaMCellLayout,
                    gSelectGhost->mSelectCupCourseTaMTable, remainingSize);
    remainingSize = GX_GetSizeOfSubOBJ();
    for (index = 0; index < 5; index++) {
        remainingSize -= InitLabelCanvas(gSelectGhost->mHeap, gSelectGhostSBnllIndices[index], gSelectGhost->mSelectGhostSLabelLayout,
                               gSelectGhostSLabelWidths[index], gSelectGhostSLabelHeights[index], index,
                               gSelectGhost->mSelectGhostSOCells, gSelectGhost->mSelectGhostSCellLayout,
                               gSelectGhost->mSelectGhostSTable, remainingSize);
    }
    InitLabelCanvas(gSelectGhost->mHeap, 5, gSelectGhost->mSelectGhostSLabelLayout, 0x32, 0xd, 0xb,
                    gSelectGhost->mSelectGhostSOCells, gSelectGhost->mSelectGhostSCellLayout, gSelectGhost->mSelectGhostSTable,
                    remainingSize);
    PrintLabelLayoutTextNoFixedAdvance(1, gSelectGhostSBnllIndices[0], gSelectGhost->mSelectGhostSLabelLayout,
                                       GetBmgEntry(gSelectGhost->mMenuMessages, 8), gSelectGhost->mSelectGhostSCellLayout,
                                       gSelectGhost->mSelectGhostSTable);
    PrintLabelLayoutTextNoFixedAdvance(1, gSelectGhostSBnllIndices[3], gSelectGhost->mSelectGhostSLabelLayout,
                                       GetBmgEntry(gSelectGhost->mMenuMessages, 9), gSelectGhost->mSelectGhostSCellLayout,
                                       gSelectGhost->mSelectGhostSTable);
    PrintLabelLayoutTextNoFixedAdvance(1, gSelectGhostSBnllIndices[4], gSelectGhost->mSelectGhostSLabelLayout,
                                       GetBmgEntry(gSelectGhost->mMenuMessages, gSelectGhostMenuMessageIndices[0]),
                                       gSelectGhost->mSelectGhostSCellLayout, gSelectGhost->mSelectGhostSTable);
    PrintLabelLayoutTextNoFixedAdvance(1, 5, gSelectGhost->mSelectGhostSLabelLayout,
                                       GetBmgEntry(gSelectGhost->mCommonMessages, 4), gSelectGhost->mSelectGhostSCellLayout,
                                       gSelectGhost->mSelectGhostSTable);
    CreateSelectCupNameM(gSelectGhost->mHeap);
    CreateCommonCupMark(gSelectGhost->mHeap);
    InitPaletteBlend(gSelectGhost->mHeap, gSelectGhost->mSelectGhostSOPalette, 4);
    ResetPaletteBlendCycle();
    SetupSelectGhostCupCells();
    ResetSelectGhost();
    for (index = SELECT_GHOST_KIND_COUNT - 1; index >= 0; index--) {
        if (IsGhostRecordSetKindSelectable(gSelectGhostRecordKinds[index]) != 0) {
            gSelectGhost->mIndex = index;
            break;
        }
    }
    RefreshSelectGhostForIndex();
    FrmHeapShrinkInParent(gSelectGhost->mHeap);
}

void ReleaseSelectGhost(void) {
    if (gSelectGhost->mResult == SELECT_GHOST_RESULT_CHOSEN) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | 0x1800;
    }
    ClearPaletteBlendPointer();
    ClearSelectCupNameMPointer();
    ClearCupMarkPointer();
    ClearKartIconPointer();
    HeapDestroy(gSelectGhost->mHeap);
    gSelectGhost = NULL;
}

void AdvanceSelectGhostSlideIn(void) {
    u16 subLayoutCount;
    s16 offsetY;
    s32 index;

    AdvanceSelectGhostOffsetTimers();
    subLayoutCount = gSelectGhost->mSelectGhostSCellLayout->mCount;
    gSelectGhost->mStateFrames++;
    offsetY = InterpolateS16(1, ~0xbf, 0, gSelectGhost->mStateFrames, SELECT_GHOST_SLIDE_FRAMES);
    gSelectGhost->mBg3Offset = offsetY;
    for (index = 0; index < 6; index++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[index]].mOffsetY = offsetY;
    }
    for (index = 0; index < 5; index++) {
        gSelectGhost->mSelectGhostSTable[subLayoutCount + gSelectGhostSBnllIndices[index]].mOffsetY = offsetY;
    }
    for (index = 0; index < 2; index++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[index]].mOffsetY = offsetY;
        gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[index]].mOffsetY = offsetY;
    }
    if (gSelectGhost->mStateFrames >= SELECT_GHOST_SLIDE_FRAMES) {
        RequestSelectGhostReturnSlideIn();
    }
}

void AdvanceSelectGhostReturnSlideIn(void) {
    u16 subLayoutCount;
    s16 returnOffsetY;

    AdvanceSelectGhostOffsetTimers();
    subLayoutCount = gSelectGhost->mSelectGhostSCellLayout->mCount;
    gSelectGhost->mStateFrames++;
    returnOffsetY = -LookupSelectReturnSlideInBg2Offset(gSelectGhost->mStateFrames);
    gSelectGhost->mSelectGhostSTable[10].mOffsetY = returnOffsetY;
    gSelectGhost->mSelectGhostSTable[11].mOffsetY = returnOffsetY;
    gSelectGhost->mSelectGhostSTable[subLayoutCount + 5].mOffsetY = returnOffsetY;
    if (gSelectGhost->mStateFrames >= SELECT_RETURN_SLIDE_STEPS) {
        RequestSelectGhostInput();
    }
}

void AdvanceSelectGhostInput(void) {
    s32 touchBeganRect;
    BOOL touchBegan;
    BOOL recentlyLost;
    BOOL touchBeganAgain;
    BOOL recentlyLostAgain;
    InputSlotIndex slotIndex;

    touchBeganRect = -1;
    AdvanceSelectGhostOffsetTimers();
    slotIndex = INPUT_SLOT_PAD_OR_PARTICIPANT;
    touchBegan = FALSE;
    recentlyLost = FALSE;
    if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
        recentlyLost = TRUE;
    }
    if (recentlyLost == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
        gInputSlots[slotIndex].mPair.mHasPair != 0) {
        touchBegan = TRUE;
    }
    if (touchBegan != FALSE) {
        touchBeganRect = RectTableFindContaining(gSelectGhost->mSelectGhostSRects, gInputSlots[slotIndex].mPair.mPairX,
                                                 gInputSlots[slotIndex].mPair.mPairY);
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_B) == 0) {
        touchBeganAgain = FALSE;
        recentlyLostAgain = FALSE;
        if (gInputSlots[slotIndex].mPair.mHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
            recentlyLostAgain = TRUE;
        }
        if (recentlyLostAgain == FALSE && gInputSlots[slotIndex].mPair.mPrevHasPair == 0 &&
            gInputSlots[slotIndex].mPair.mHasPair != 0) {
            touchBeganAgain = TRUE;
        }
        if (touchBeganAgain == FALSE ||
            IsSelectReturnShownNoRequestAndInRect(gInputSlots[slotIndex].mPair.mPairX,
                                                  gInputSlots[slotIndex].mPair.mPairY) == FALSE) {
            goto next;
        }
    }
    SetSelectReturnSoundId(SELECT_RETURN_SOUND_ID);
    RequestSelectGhostSlideOut();
    gSelectGhost->mResult = SELECT_GHOST_RESULT_RETURN;
    RequestSelectReturnPressWithSound(0);
    return;
next:
    if (touchBeganRect == 0) {
        DecrementSelectGhostIndex();
        return;
    }
    if (touchBeganRect == 1) {
        IncrementSelectGhostIndex();
        return;
    }
    if (touchBeganRect == 3) {
        RequestSelectGhostPress();
        return;
    }
    if (touchBeganRect == 2) {
        IncrementSelectGhostIndex();
        return;
    }
    if ((u16) (gInputSlots[slotIndex].mPressedBits & PAD_KEY_A) != 0) {
        RequestSelectGhostPress();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_LEFT) != 0) {
        DecrementSelectGhostIndex();
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DIRECTION_RIGHT) != 0) {
        IncrementSelectGhostIndex();
    }
}

void AdvanceSelectGhostPress(void) {
    AdvanceSelectGhostOffsetTimers();
    gSelectGhost->mStateFrames++;
    if (gSelectGhost->mStateFrames >= SELECT_GHOST_PRESS_FRAMES) {
        RequestSelectGhostChoisesOpen();
    }
}

void AdvanceSelectGhostChoisesOpen(void) {
    if (IsSelectChoisesChooseNoRequest() != 0) {
        RequestSelectGhostChoisesInput();
    }
}

void AdvanceSelectGhostChoisesInput(void) {
    int selectChoisesDone;
    selectChoisesDone = GetSelectChoisesDone();
    if (selectChoisesDone != 0) {
        RequestSelectGhostChoisesClose();
    }
}

void AdvanceSelectGhostChoisesClose(void) {
    s32 selectChoisesIndex;

    if (IsSelectChoisesHiddenNoRequest() == 0) {
        return;
    }
    selectChoisesIndex = GetSelectChoisesIndex();
    switch (selectChoisesIndex) {
        case 0:
            ReadSelectGhostRecords();
            gSelectGhost->mResult = SELECT_GHOST_RESULT_CHOSEN;
            RequestSelectGhostSlideOut();
            RequestSelectReturnSlideOut();
            break;
        case -1:
        case 1:
            StartPaletteBlend();
            RequestSelectGhostInput();
            break;
    }
}

void AdvanceSelectGhostSlideOut(void) {
    BOOL isChosen;
    s16 offsetY;
    s16 returnOffsetY;
    u16 layoutCount;
    s32 index;

    isChosen = gSelectGhost->mResult == SELECT_GHOST_RESULT_CHOSEN;
    gSelectGhost->mStateFrames++;
    offsetY = InterpolateS16(1, 0, ~0xbf, gSelectGhost->mStateFrames, SELECT_GHOST_SLIDE_FRAMES);
    if (isChosen) {
        layoutCount = gSelectGhost->mSelectCupCourseTaMCellLayout->mCount;
        gSelectGhost->mBg0Offset = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[0].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[2].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[1].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[4].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[3].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[5].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[layoutCount].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[layoutCount + 1].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[layoutCount + 2].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[layoutCount + 3].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[layoutCount + 4].mOffsetY = offsetY;
        gSelectGhost->mSelectCupCourseTaMTable[layoutCount + 5].mOffsetY = offsetY;
    }
    layoutCount = gSelectGhost->mSelectGhostSCellLayout->mCount;
    returnOffsetY = -LookupSelectReturnSlideOutBg2Offset(gSelectGhost->mStateFrames);
    gSelectGhost->mBg3Offset = offsetY;
    for (index = 0; index < 6; index++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostSTableIndices[index]].mOffsetY = offsetY;
    }
    gSelectGhost->mSelectGhostSTable[10].mOffsetY = returnOffsetY;
    gSelectGhost->mSelectGhostSTable[11].mOffsetY = returnOffsetY;
    for (index = 0; index < 5; index++) {
        gSelectGhost->mSelectGhostSTable[layoutCount + gSelectGhostSBnllIndices[index]].mOffsetY = offsetY;
    }
    for (index = 0; index < 2; index++) {
        gSelectGhost->mSelectGhostSTable[gSelectGhostTimerZeroSTableIndices[index]].mOffsetY = offsetY;
        gSelectGhost->mSelectGhostSTable[gSelectGhostRunningSTableIndices[index]].mOffsetY = offsetY;
    }
    gSelectGhost->mSelectGhostSTable[layoutCount + 5].mOffsetY = returnOffsetY;
}

int AdvanceSelectGhost(void) {
    gSelectGhost->mState = gSelectGhost->mNextState;
    switch (gSelectGhost->mState) {
        case SELECT_GHOST_STATE_SLIDE_IN:
            AdvanceSelectGhostSlideIn();
            break;
        case SELECT_GHOST_STATE_RETURN_SLIDE_IN:
            AdvanceSelectGhostReturnSlideIn();
            break;
        case SELECT_GHOST_STATE_INPUT:
            AdvanceSelectGhostInput();
            break;
        case SELECT_GHOST_STATE_PRESS:
            AdvanceSelectGhostPress();
            break;
        case SELECT_GHOST_STATE_CHOISES_OPEN:
            AdvanceSelectGhostChoisesOpen();
            break;
        case SELECT_GHOST_STATE_CHOISES_INPUT:
            AdvanceSelectGhostChoisesInput();
            break;
        case SELECT_GHOST_STATE_CHOISES_CLOSE:
            AdvanceSelectGhostChoisesClose();
            break;
        case SELECT_GHOST_STATE_SLIDE_OUT:
            AdvanceSelectGhostSlideOut();
            break;
    }
    AdvancePaletteBlend();
    UpdateSelectGhostCellVisibility();
    DrawLayoutTable(gSelectGhost->mSelectCupCourseTaMCellLayout, gSelectGhost->mSelectCupCourseMNcer,
                    gSelectGhost->mSelectCupCourseTaMLabelLayout, gSelectGhost->mMainOamList,
                    gSelectGhost->mSelectCupCourseTaMTable);
    DrawLayoutTable(gSelectGhost->mSelectGhostSCellLayout, gSelectGhost->mSelectGhostSOCells, gSelectGhost->mSelectGhostSLabelLayout,
                    gSelectGhost->mSubOamList, gSelectGhost->mSelectGhostSTable);
    if (gSelectGhost->mState == SELECT_GHOST_STATE_SLIDE_OUT) {
        switch (gSelectGhost->mResult) {
            case SELECT_GHOST_RESULT_CHOSEN:
                if (gSelectGhost->mStateFrames >= SELECT_GHOST_SLIDE_FRAMES) {
                    if (IsSelectReturnHiddenNoSlideInRequest() != 0) {
                        return 1;
                    }
                }
                break;
            case SELECT_GHOST_RESULT_RETURN:
                if (gSelectGhost->mStateFrames >= SELECT_GHOST_SLIDE_FRAMES) {
                    return 2;
                }
                break;
        }
    }
    return 0;
}

void WriteSelectGhostRegisters(void) {
    reg_G2_BG0OFS = (-gSelectGhost->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gSelectGhost->mBg3Offset << 16) & 0x1ff0000;
}
