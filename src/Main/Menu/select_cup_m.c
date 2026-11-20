#include "Main/Menu/select_cup_m.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Menu/cup_picture.h"
#include "Main/System/thread_function_queue_run.h"
#include "registers.h"

#include "Main/Menu/select_race_rule_wait_slide_out.h"
#include "Main/Menu/kart_icon_row.h"
#include "Main/Menu/select_cup_name_files.h"
#include "Main/System/stdio_files.h"
#include "print_memory_multibyte_write.h"
#include "capture_output_effect.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Race/race_setup.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/menu_screen_switch.h"
#include "Main/Menu/cup_mark.h"
#include "Main/Menu/select_race_rule_state.h"
#include "vram_bank_display_setup.h"
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
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "vram_transfer_queue.h"

const u32 gSelectCupMCourseIds[8][4] = {{0x14, 0x16, 0x1f, 0x12}, {0x1b, 0x1c, 0x21, 0x18}, {0x1e, 0x11, 0x19, 0x13},
                                        {0x22, 0x1a, 0x20, 0x1d}, {0xa, 0xb, 0xd, 0xe},     {0x23, 0x10, 0xc, 9},
                                        {0xf, 0x24, 0x25, 0x26},  {0x27, 0x17, 0x28, 1}};
char *gSelectCupMBNclrName3 = "common/select_cup_m_b.nclr";
const u16 gSelectCupMLabelWidths[4] = {0xa3, 0xa3, 0xa3, 0xa3};
char *gSelectCupMNcgrName3 = "common/select_cup_m.nce.ncgr";
const u16 gSelectCupMTrophyCells[4] = {3, 4, 5, 6};
const u16 gSelectCupMCourseCells[4] = {0x12, 0x11, 0x10, 0xf};
const u16 gSelectCupMCourseLabels[4] = {3, 2, 1, 0};
const u32 gSelectCupMCupIndices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const u16 gSelectCupMCupMessageIndices[8][4] = {
    {0x2d, 0x2e, 0x2f, 0x30}, {0x31, 0x32, 0x33, 0x34}, {0x35, 0x36, 0x37, 0x38}, {0x39, 0x3a, 0x3b, 0x3c},
    {0x3d, 0x3e, 0x3f, 0x40}, {0x41, 0x42, 0x43, 0x44}, {0x45, 0x46, 0x47, 0x48}, {0x49, 0x4a, 0x4b, 0x4c}};
char *gSelectCupMBNcgrName3 = "common/select_cup_m_b.ncgr";
char *gSelectCupMBnclName3 = "common/select_cup_m.bncl";
char *gSelectCupMNcerName3 = "common/select_cup_m.nce.ncer";
char *gSelectCupMNscrName3 = "common/select_cup_m.nscr";
const u16 gSelectCupMCellSlots[8] = {7, 8, 9, 0xa, 0xb, 0xc, 0xd, 0xe};
const u16 gSelectCupMLabelHeights[4] = {0xd, 0xd, 0xd, 0xd};
char *gSelectCupMBnllName3 = "common/select_cup_m.bnll";
char *gSelectCupMONclrName3 = "common/select_cup_m_o.nclr";
SelectCupM *gSelectCupM;

#pragma thumb on

void LocateAndQueueSelectCupM(void) {
    Ncgr *mainCellChars;
    Nclr *mainCellPalette;
    Ncgr *subCellChars;
    Nclr *subCellPalette;
    Ncgr *firstBgChars;
    Nscr *firstBgScreenMap;
    Nclr *firstBgPalette;
    Ncgr *secondBgChars;
    Nscr *secondBgScreenMap;
    Nclr *secondBgPalette;
    u16 *mainCellPaletteData;

    mainCellChars = NULL;
    mainCellPalette = NULL;
    subCellChars = NULL;
    subCellPalette = NULL;
    firstBgChars = NULL;
    firstBgScreenMap = NULL;
    firstBgPalette = NULL;
    secondBgChars = NULL;
    secondBgScreenMap = NULL;
    secondBgPalette = NULL;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return;
    }
    LocateNcgr(&firstBgChars, FindSceneFile(gSelectCupMBNcgrName3));
    LocateNclr(&firstBgPalette, FindSceneFile(gSelectCupMBNclrName3));
    LocateNscr(&firstBgScreenMap, FindSceneFile(gSelectCupMNscrName3));
    LocateNcgr(&secondBgChars, FindSceneFile(gSelectCupMBNcgrName3));
    LocateNclr(&secondBgPalette, FindSceneFile(gSelectCupMBNclrName3));
    LocateNscr(&secondBgScreenMap, FindSceneFile(gSelectCupMNscrName3));
    gSelectCupM->mSecondScreenMapBuffer = HeapAlloc(gSelectCupM->mHeap, SECOND_SCREEN_MAP_BYTES);
    gSelectCupM->mMainBncl = FindSceneFile(gSelectCupMBnclName3);
    gSelectCupM->mMainBnll = FindSceneFile(gSelectCupMBnllName3);
    LocateNcgr2(&mainCellChars, FindSceneFile(gSelectCupMNcgrName3));
    LocateNcer(&gSelectCupM->mMainNcer, FindSceneFile(gSelectCupMNcerName3));
    LocateNclr(&mainCellPalette, FindSceneFile(gSelectCupMONclrName3));
    gSelectCupM->mSubBncl = FindSceneFile(gSelectCupMBnclName3);
    gSelectCupM->mSubBnll = FindSceneFile(gSelectCupMBnllName3);
    LocateNcgr2(&subCellChars, FindSceneFile(gSelectCupMNcgrName3));
    LocateNcer(&gSelectCupM->mSubNcer, FindSceneFile(gSelectCupMNcerName3));
    LocateNclr(&subCellPalette, FindSceneFile(gSelectCupMONclrName3));
    mainCellPaletteData = mainCellPalette->mData;
    if (!(GetPreviousMenuScreenNumber() == 0x17 || GetPreviousMenuScreenNumber() == 0xb)) {
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG0_TILES, 0, firstBgChars->mData,
                                           firstBgChars->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG_PALETTE, 0, firstBgPalette->mData, 0x140);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG0_MAP, 0, firstBgScreenMap->mData,
                                           firstBgScreenMap->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG0_MAP, 0x800, gSelectCupM->mSecondScreenMapBuffer,
                                           SECOND_SCREEN_MAP_BYTES);
    }
    if (!(GetPreviousMenuScreenNumber() == 0x19 || GetPreviousMenuScreenNumber() == 0xd)) {
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG3_TILES, 0, secondBgChars->mData,
                                           secondBgChars->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG_PALETTE, 0, secondBgPalette->mData, 0x140);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG3_MAP, 0, secondBgScreenMap->mData,
                                           secondBgScreenMap->mDataSize);
        NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG3_MAP, 0x800, gSelectCupM->mSecondScreenMapBuffer,
                                           SECOND_SCREEN_MAP_BYTES);
    }
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_TILES, 0, mainCellChars->mData,
                                       mainCellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, 0, mainCellPalette->mData, 0x1a0);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_SPRITE_PALETTE, 0x1c0, mainCellPaletteData + 0xe0, 0x40);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_TILES, 0, subCellChars->mData,
                                       subCellChars->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_SPRITE_PALETTE, 0, subCellPalette->mData,
                                       subCellPalette->mDataSize);
}

void InitSelectCupMCellsAndRequestCupPicture(void) {
    s32 cellIndex;
    u16 mainCellCount;
    u16 subCellCount;
    s32 courseIndex;
    BOOL screenId;
    BOOL visible;
    s32 nextCourseIndex;
    s32 firstCellIndex;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return;
    }
    mainCellCount = gSelectCupM->mMainBncl->mCount;
    subCellCount = gSelectCupM->mSubBncl->mCount;
    visible = FALSE;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCellSlots[cellIndex]].mVisible = visible;
        gSelectCupM->mSubTable[gSelectCupMCellSlots[cellIndex]].mVisible = visible;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMTrophyCells[cellIndex]].mVisible = 0;
        gSelectCupM->mSubTable[gSelectCupMTrophyCells[cellIndex]].mVisible = 0;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[cellIndex]].mVisible = 0;
        gSelectCupM->mMainTable[mainCellCount + gSelectCupMCourseLabels[cellIndex]].mVisible = 1;
        gSelectCupM->mSubTable[gSelectCupMCourseCells[cellIndex]].mVisible = 0;
        gSelectCupM->mSubTable[subCellCount + gSelectCupMCourseLabels[cellIndex]].mVisible = 1;
    }
    gSelectCupM->mMainTable[20].mVisible = 0;
    gSelectCupM->mMainTable[19].mVisible = 1;
    gSelectCupM->mSubTable[20].mVisible = 0;
    gSelectCupM->mSubTable[19].mVisible = 1;
    QueueSelectCupNameM(gSelectCupMCupIndices[GetCupIndex()], gSelectCupM->mMainNcer, gSelectCupM->mMainBncl, 0x13, 0);
    QueueSelectCupNameM(gSelectCupMCupIndices[GetCupIndex()], gSelectCupM->mSubNcer, gSelectCupM->mSubBncl, 0x13, 1);
    screenId = FALSE;
    for (courseIndex = 0; courseIndex < 4; courseIndex++) {
        PrintLabelLayoutTextNoFixedAdvance(
            screenId, gSelectCupMCourseLabels[courseIndex], gSelectCupM->mMainBnll,
            GetBmgEntry(gSelectCupM->mCommonMessages,
                        gSelectCupMCupMessageIndices[gSelectCupMCupIndices[GetCupIndex()]][courseIndex]),
            gSelectCupM->mMainBncl, gSelectCupM->mMainTable);
        PrintLabelLayoutTextNoFixedAdvance(
            1, gSelectCupMCourseLabels[courseIndex], gSelectCupM->mSubBnll,
            GetBmgEntry(gSelectCupM->mCommonMessages,
                        gSelectCupMCupMessageIndices[gSelectCupMCupIndices[GetCupIndex()]][courseIndex]),
            gSelectCupM->mSubBncl, gSelectCupM->mSubTable);
    }
    firstCellIndex = gSelectCupMCourseCells[0];
    gSelectCupM->mMainTable[firstCellIndex].mVisible = 1;
    courseIndex = gSelectCupMCourseLabels[0];
    SetLabelPaletteIndex(courseIndex, 0xe, gSelectCupM->mMainBnll, gSelectCupM->mMainTable, gSelectCupM->mMainBncl);
    gSelectCupM->mSubTable[firstCellIndex].mVisible = 1;
    SetLabelPaletteIndex(courseIndex, 0xe, gSelectCupM->mSubBnll, gSelectCupM->mSubTable, gSelectCupM->mSubBncl);
    for (nextCourseIndex = 1; nextCourseIndex < 4; nextCourseIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[nextCourseIndex]].mVisible = 0;
        SetLabelPaletteIndex(gSelectCupMCourseLabels[nextCourseIndex], 0xf, gSelectCupM->mMainBnll,
                             gSelectCupM->mMainTable, gSelectCupM->mMainBncl);
        gSelectCupM->mSubTable[gSelectCupMCourseCells[nextCourseIndex]].mVisible = 0;
        SetLabelPaletteIndex(gSelectCupMCourseLabels[nextCourseIndex], 0xf, gSelectCupM->mSubBnll,
                             gSelectCupM->mSubTable, gSelectCupM->mSubBncl);
    }
    TrySetCupPictureIndexAndQueueLoads(gSelectCupMCourseIds[gSelectCupMCupIndices[GetCupIndex()]][0]);
    gSelectCupM->mCupPicturePending = TRUE;
}

void StartSelectCupMScrollDown(void) {
    s32 cellIndex;
    u16 mainCellCount;
    u16 subCellCount;

    gSelectCupM->mNextState = SELECT_CUP_M_STATE_SCROLL_DOWN;
    gSelectCupM->mStateFrames = 0;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return;
    }
    mainCellCount = gSelectCupM->mMainBncl->mCount;
    subCellCount = gSelectCupM->mSubBncl->mCount;
    gSelectCupM->mBg0Offset = 0;
    gSelectCupM->mMainTable[20].mOffsetY = 0;
    gSelectCupM->mMainTable[19].mOffsetY = 0;
    gSelectCupM->mMainTable[2].mOffsetY = 0;
    gSelectCupM->mMainTable[1].mOffsetY = 0;
    gSelectCupM->mMainTable[0].mOffsetY = 0;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCellSlots[cellIndex]].mOffsetY = 0;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = 0;
        gSelectCupM->mMainTable[mainCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = 0;
    }
    gSelectCupM->mBg3Offset = -SELECT_CUP_M_OFFSCREEN_Y;
    gSelectCupM->mSubTable[20].mOffsetY = -SELECT_CUP_M_OFFSCREEN_Y;
    gSelectCupM->mSubTable[19].mOffsetY = -SELECT_CUP_M_OFFSCREEN_Y;
    gSelectCupM->mSubTable[2].mOffsetY = -SELECT_CUP_M_OFFSCREEN_Y;
    gSelectCupM->mSubTable[1].mOffsetY = -SELECT_CUP_M_OFFSCREEN_Y;
    gSelectCupM->mSubTable[0].mOffsetY = -SELECT_CUP_M_OFFSCREEN_Y;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCellSlots[cellIndex]].mOffsetY = -SELECT_CUP_M_OFFSCREEN_Y;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = -SELECT_CUP_M_OFFSCREEN_Y;
        gSelectCupM->mSubTable[subCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = -SELECT_CUP_M_OFFSCREEN_Y;
    }
}

void StartSelectCupMScrollUp(void) {
    s32 cellIndex;
    u16 mainCellCount;
    u16 subCellCount;

    gSelectCupM->mNextState = SELECT_CUP_M_STATE_SCROLL_UP;
    gSelectCupM->mStateFrames = 0;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return;
    }
    mainCellCount = gSelectCupM->mMainBncl->mCount;
    subCellCount = gSelectCupM->mSubBncl->mCount;
    gSelectCupM->mBg0Offset = SELECT_CUP_M_OFFSCREEN_Y;
    gSelectCupM->mMainTable[20].mOffsetY = SELECT_CUP_M_OFFSCREEN_Y;
    gSelectCupM->mMainTable[19].mOffsetY = SELECT_CUP_M_OFFSCREEN_Y;
    gSelectCupM->mMainTable[2].mOffsetY = SELECT_CUP_M_OFFSCREEN_Y;
    gSelectCupM->mMainTable[1].mOffsetY = SELECT_CUP_M_OFFSCREEN_Y;
    gSelectCupM->mMainTable[0].mOffsetY = SELECT_CUP_M_OFFSCREEN_Y;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCellSlots[cellIndex]].mOffsetY = SELECT_CUP_M_OFFSCREEN_Y;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = SELECT_CUP_M_OFFSCREEN_Y;
        gSelectCupM->mMainTable[mainCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = SELECT_CUP_M_OFFSCREEN_Y;
    }
    gSelectCupM->mBg3Offset = SELECT_CUP_M_SUB_END_OFFSET_Y;
    gSelectCupM->mSubTable[20].mOffsetY = SELECT_CUP_M_SUB_END_OFFSET_Y;
    gSelectCupM->mSubTable[19].mOffsetY = SELECT_CUP_M_SUB_END_OFFSET_Y;
    gSelectCupM->mSubTable[2].mOffsetY = SELECT_CUP_M_SUB_END_OFFSET_Y;
    gSelectCupM->mSubTable[1].mOffsetY = SELECT_CUP_M_SUB_END_OFFSET_Y;
    gSelectCupM->mSubTable[0].mOffsetY = SELECT_CUP_M_SUB_END_OFFSET_Y;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCellSlots[cellIndex]].mOffsetY = SELECT_CUP_M_SUB_END_OFFSET_Y;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = SELECT_CUP_M_SUB_END_OFFSET_Y;
        gSelectCupM->mSubTable[subCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY =
            SELECT_CUP_M_SUB_END_OFFSET_Y;
    }
}

void InitSelectCupM(void *parentHeap, void *mainOamList, void *subOamList) {
    void *heap;
    s32 index;
    s32 remainingSize;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~REG_G2_BG0CNT_PRIORITY_MASK) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~REG_G2S_DB_BG3CNT_PRIORITY_MASK) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & (REG_G2_BG0CNT_PRIORITY_MASK | REG_G2_BG0CNT_MOSAIC_MASK)) | 0x9004;
    reg_G2S_DB_BG3CNT =
        (reg_G2S_DB_BG3CNT & (REG_G2S_DB_BG3CNT_PRIORITY_MASK | REG_G2S_DB_BG3CNT_MOSAIC_MASK)) | 0x8300;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectCupM = HeapAlloc(heap, sizeof(*gSelectCupM));
    gSelectCupM->mHeap = heap;
    gSelectCupM->mCupPicturePending = FALSE;
    gSelectCupM->mMainOam = mainOamList;
    gSelectCupM->mSubOam = subOamList;
    gSelectCupM->mUnk_50 = 0;
    if (GetPreviousMenuScreenNumber() == 0x19 || GetPreviousMenuScreenNumber() == 0xd) {
        gSelectCupM->mState = SELECT_CUP_M_STATE_SCROLL_UP;
    } else {
        gSelectCupM->mState = SELECT_CUP_M_STATE_SCROLL_DOWN;
    }
    LocateAndQueueSelectCupM();
    gSelectCupM->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        InitLayoutTable(gSelectCupM->mHeap, gSelectCupM->mMainBncl, gSelectCupM->mMainBnll, &gSelectCupM->mMainTable);
        InitLayoutTable(gSelectCupM->mHeap, gSelectCupM->mSubBncl, gSelectCupM->mSubBnll, &gSelectCupM->mSubTable);
        remainingSize = 0x8000;
        for (index = 0; index < 4; index++) {
            remainingSize -= InitLabelCanvas(gSelectCupM->mHeap, gSelectCupMCourseLabels[index], gSelectCupM->mMainBnll,
                                             gSelectCupMLabelWidths[index], gSelectCupMLabelHeights[index],
                                             gSelectCupMCourseCells[index], gSelectCupM->mMainNcer,
                                             gSelectCupM->mMainBncl, gSelectCupM->mMainTable, remainingSize);
        }
        index = GX_GetSizeOfSubOBJ();
        for (remainingSize = 0; remainingSize < 4; remainingSize++) {
            index -= InitLabelCanvas(gSelectCupM->mHeap, gSelectCupMCourseLabels[remainingSize], gSelectCupM->mSubBnll,
                                     gSelectCupMLabelWidths[remainingSize], gSelectCupMLabelHeights[remainingSize],
                                     gSelectCupMCourseCells[remainingSize], gSelectCupM->mSubNcer,
                                     gSelectCupM->mSubBncl, gSelectCupM->mSubTable, index);
        }
        CreateSelectCupNameM(gSelectCupM->mHeap);
    } else {
        InitSelectRaceRuleWait(gSelectCupM->mHeap, gSelectCupM->mSubOam);
        PlaceSelectRaceRuleWait();
    }
    InitSelectCupMCellsAndRequestCupPicture();
    if (GetPreviousMenuScreenNumber() == 0x19 || GetPreviousMenuScreenNumber() == 0xd) {
        StartSelectCupMScrollUp();
    } else {
        StartSelectCupMScrollDown();
    }
    FrmHeapShrinkInParent(gSelectCupM->mHeap);
}

void ReleaseSelectCupM(void) {
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        ClearSelectCupNameMPointer();
    } else {
        ClearSelectRaceRuleWaitPointer();
    }
    HeapDestroy(gSelectCupM->mHeap);
    gSelectCupM = NULL;
}

void AdvanceSelectCupMScrollDown(void) {
    s32 cellIndex;
    s16 mainOffset;
    s16 subOffset;
    u16 mainCellCount;
    u16 subCellCount;

    gSelectCupM->mStateFrames++;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return;
    }
    mainOffset = InterpolateS16(1, 0, SELECT_CUP_M_OFFSCREEN_Y, gSelectCupM->mStateFrames, SELECT_CUP_M_SCROLL_STEPS);
    subOffset = InterpolateS16(1, -SELECT_CUP_M_OFFSCREEN_Y, SELECT_CUP_M_SUB_END_OFFSET_Y, gSelectCupM->mStateFrames,
                               SELECT_CUP_M_SCROLL_STEPS);
    mainCellCount = gSelectCupM->mMainBncl->mCount;
    gSelectCupM->mBg0Offset = mainOffset;
    gSelectCupM->mMainTable[20].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[19].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[2].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[1].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[0].mOffsetY = mainOffset;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCellSlots[cellIndex]].mOffsetY = mainOffset;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = mainOffset;
        gSelectCupM->mMainTable[mainCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = mainOffset;
    }
    subCellCount = gSelectCupM->mSubBncl->mCount;
    gSelectCupM->mBg3Offset = subOffset;
    gSelectCupM->mSubTable[20].mOffsetY = subOffset;
    gSelectCupM->mSubTable[19].mOffsetY = subOffset;
    gSelectCupM->mSubTable[2].mOffsetY = subOffset;
    gSelectCupM->mSubTable[1].mOffsetY = subOffset;
    gSelectCupM->mSubTable[0].mOffsetY = subOffset;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCellSlots[cellIndex]].mOffsetY = subOffset;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = subOffset;
        gSelectCupM->mSubTable[subCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = subOffset;
    }
}

void AdvanceSelectCupMScrollUp(void) {
    s32 cellIndex;
    s16 mainOffset;
    s16 subOffset;
    u16 mainCellCount;
    u16 subCellCount;

    gSelectCupM->mStateFrames++;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return;
    }
    mainOffset = InterpolateS16(1, SELECT_CUP_M_OFFSCREEN_Y, 0, gSelectCupM->mStateFrames, SELECT_CUP_M_SCROLL_STEPS);
    subOffset = InterpolateS16(1, SELECT_CUP_M_SUB_END_OFFSET_Y, -SELECT_CUP_M_OFFSCREEN_Y, gSelectCupM->mStateFrames,
                               SELECT_CUP_M_SCROLL_STEPS);
    mainCellCount = gSelectCupM->mMainBncl->mCount;
    gSelectCupM->mBg0Offset = mainOffset;
    gSelectCupM->mMainTable[20].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[19].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[2].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[1].mOffsetY = mainOffset;
    gSelectCupM->mMainTable[0].mOffsetY = mainOffset;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCellSlots[cellIndex]].mOffsetY = mainOffset;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mMainTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = mainOffset;
        gSelectCupM->mMainTable[mainCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = mainOffset;
    }
    subCellCount = gSelectCupM->mSubBncl->mCount;
    gSelectCupM->mBg3Offset = subOffset;
    gSelectCupM->mSubTable[20].mOffsetY = subOffset;
    gSelectCupM->mSubTable[19].mOffsetY = subOffset;
    gSelectCupM->mSubTable[2].mOffsetY = subOffset;
    gSelectCupM->mSubTable[1].mOffsetY = subOffset;
    gSelectCupM->mSubTable[0].mOffsetY = subOffset;
    for (cellIndex = 0; cellIndex < 8; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCellSlots[cellIndex]].mOffsetY = subOffset;
    }
    for (cellIndex = 0; cellIndex < 4; cellIndex++) {
        gSelectCupM->mSubTable[gSelectCupMCourseCells[cellIndex]].mOffsetY = subOffset;
        gSelectCupM->mSubTable[subCellCount + gSelectCupMCourseLabels[cellIndex]].mOffsetY = subOffset;
    }
}

s32 AdvanceSelectCupM(void) {
    s32 index;
    u16 *cupPictureScreenMap;
    s32 screenMapIndex;
    s32 transferKind;
    s32 transferSize;

    gSelectCupM->mState = gSelectCupM->mNextState;
    switch (gSelectCupM->mState) {
        case SELECT_CUP_M_STATE_SCROLL_DOWN:
            AdvanceSelectCupMScrollDown();
            break;
        case SELECT_CUP_M_STATE_SCROLL_UP:
            AdvanceSelectCupMScrollUp();
            break;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        if (gSelectCupM->mCupPicturePending != FALSE && IsCupPictureReady() != FALSE) {
            cupPictureScreenMap = GetCupPictureNscrData();
            NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG_PALETTE, 0, GetCupPictureNclrData(), 0xe0);
            NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG0_TILES, 0x20, GetCupPictureNcgrData(), 0xdc0);
            transferKind = 8;
            transferSize = 0x14;
            for (index = 0; index < 0xb; index++) {
                screenMapIndex = ((index + 8) << 5) + 0x16;
                NNS_GfdRegisterNewVramTransferTask(transferKind, screenMapIndex << 1,
                                                   cupPictureScreenMap + screenMapIndex, transferSize);
            }
            NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG_PALETTE, 0, GetCupPictureNclrData(), 0xe0);
            NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG3_TILES, 0x20, GetCupPictureNcgrData(), 0xdc0);
            transferKind = 0x1b;
            for (index = 0; index < 0xb; index++) {
                screenMapIndex = ((index + 8) << 5) + 0x16;
                NNS_GfdRegisterNewVramTransferTask(transferKind, screenMapIndex << 1,
                                                   cupPictureScreenMap + screenMapIndex, transferSize);
            }
            gSelectCupM->mCupPicturePending = FALSE;
        }
        DrawLayoutTable(gSelectCupM->mMainBncl, gSelectCupM->mMainNcer, gSelectCupM->mMainBnll, gSelectCupM->mMainOam,
                        gSelectCupM->mMainTable);
        DrawLayoutTable(gSelectCupM->mSubBncl, gSelectCupM->mSubNcer, gSelectCupM->mSubBnll, gSelectCupM->mSubOam,
                        gSelectCupM->mSubTable);
    } else {
        AdvanceSelectRaceRuleWait();
    }
    if (gSelectCupM->mState == SELECT_CUP_M_STATE_SCROLL_DOWN &&
        gSelectCupM->mStateFrames > SELECT_CUP_M_SCROLL_STEPS) {
        return 1;
    }
    if (gSelectCupM->mState == SELECT_CUP_M_STATE_SCROLL_UP && gSelectCupM->mStateFrames > SELECT_CUP_M_SCROLL_STEPS) {
        return 2;
    }
    return 0;
}

void WriteSelectCupMBgOffsets(void) {
    reg_G2_BG0OFS = (-gSelectCupM->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gSelectCupM->mBg3Offset << 16) & 0x1ff0000;
}

#pragma thumb off
