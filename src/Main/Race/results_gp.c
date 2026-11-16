#include "Main/Race/results_gp.h"
#include "Main/Scene/run_scene_connection.h" // SceneNumbers
#include "01/Scene/test_scene.h"
#include "Main/Graphics/player_character_cell_file_set.h"
#include "Main/Graphics/message_index.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Race/course_time_text.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/System/result_archive_path.h"
#include "Main/Race/race.h"
#include "Main/System/thread_function_queue.h"
#include "Main/MapObjects/trophy.h"
#include "Main/Race/results_gp_frame_limit.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Menu/txt_system.h"
#include "Main/Graphics/scene_text.h"
#include "vram_bank_display_setup.h"
#include "Main/System/input_slots.h"
#include "sound_player_control.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "vram_transfer_queue.h"
#include "sound_archive_load_result.h"
#include "display_blend_affine_setup.h"
#include "cpu_copy_clear_16.h"
#include "cpu_copy_fill.h"
#include "card_rom_backup_access.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Race/gp_records_killer.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Scene/display_settings_descs.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const u16 g_CommonBmgCircuitCcTable[4] = {0x6e, 0x6f, 0x70, 0};
const u16 gCupNameLeftCharIndices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
const u16 gCupRankCellIndexTable[8] = {0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13};
const u16 gResultsGpGradeCellIndices[8] = {0xb, 0xa, 9, 8, 7, 6, 5, 4};
const u32 gResultsGpCupCourseIds[8][4] = {{0x14, 0x16, 0x1f, 0x12}, {0x1b, 0x1c, 0x21, 0x18}, {0x1e, 0x11, 0x19, 0x13},
                                          {0x22, 0x1a, 0x20, 0x1d}, {0xa, 0xb, 0xd, 0xe},     {0x23, 0x10, 0xc, 9},
                                          {0xf, 0x24, 0x25, 0x26},  {0x27, 0x17, 0x28, 1}};
const LabelCanvasEntry gResultsGpSubLabelCanvasEntries[16] = {
    {0, 0x2a, 0xd, 1, -1},     {1, 0x2a, 0xd, 2, -1},     {2, 0x37, 0xd, 3, -1},     {3, 0x37, 0xd, 4, -1},
    {4, 0xaf, 0xd, 5, -1},     {5, 0xaf, 0xd, 6, -1},     {6, 0xaf, 0xd, 7, -1},     {7, 0xaf, 0xd, 8, -1},
    {8, 0x40, 0xd, 9, -1},     {9, 0x40, 0xd, 0xa, -1},   {0xa, 0x40, 0xd, 0xb, -1}, {0xb, 0x40, 0xd, 0xc, -1},
    {0xc, 0x40, 0xd, 0xd, -1}, {0xd, 0x40, 0xd, 0xe, -1}, {0xe, 0x40, 0xd, 0xf, -1}, {0xf, 0x40, 0xd, 0x10, -1}};
ResultsGp *g_GlobalM;

#pragma thumb on

// Sets up the Grand Prix results screen: loads its files and lays out the cup, course and time texts.
void InstanceStructM_from_thumb(void *heap, void *firstOamList, void *secondOamList) {
    s16 timeText[10];
    SceneTextInitParams config;
    ScreenMapFileSet mainScreenMapFileSet;
    u16 playerName[11];
    CellFileSet cellFileSet;
    ScreenMapFileSet subScreenMapFileSet;
    CellFileSet cupNameFileSet;
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    DisplaySettings *displaySettings;
    u32 mainObjSize;
    u32 subObjSizeLeft;
    u32 characterIndex;
    u32 labelTableIndex;
    u32 cellFlag;
    s32 index;
    void *message;
    s32 courseIndex;
    s32 loopIndex;
    const LabelCanvasEntry *tableEntry;

    labelTableIndex = 0;
    g_GlobalM = Mem_AllocateHeap(heap, sizeof(ResultsGp));
    MemFillWordsByBlock_inline(g_GlobalM, 0x60);
    g_GlobalM->mOamLists[0] = firstOamList;
    g_GlobalM->mOamLists[1] = secondOamList;
    g_GlobalM->mCommonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("common.bmg");
    g_GlobalM->mSecretMessages = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("secret.bmg");
    g_GlobalM->mCupIndex = g_GlobalB488->mCupIndex;
    g_GlobalM->mCupRankIndex = g_GlobalB488->mCupRankIndex;
    if (g_GlobalM->mCupRankIndex < 0) {
        g_GlobalM->mCupRankIndex = 0;
    }
    g_GlobalM->mGrade = g_GlobalB488->mGrade;
    Init3dEngine();
    displaySettings = CreateDisplayConfig(heap, gResultsDisplaySettingsDesc);
    DisplayEngineConfig_SetBg1Config(&displaySettings->mMainBgRecords, 2, 0, 0, 0, 0x10, 6, 0);
    DisplayEngineConfig_SetBg3Config(&displaySettings->mMainBgRecords, 3, 0, 0, 0, 2, 6);
    DisplayEngineConfig_SetBg3Config(&displaySettings->mSubBgRecords, 3, 0, 0, 0, 1, 6);
    SetGlobalDisplayConfig(displaySettings);
    config.mUseTxtSystem = 1;
    config.mTxtSystemFont = GetLoadedFont_from_thumb(1);
    config.mUseCanvas1 = 0;
    config.mUseCanvas2 = 1;
    config.mUseCanvas3 = 0;
    config.mUseSelectChoises = 0;
    config.mSelectChoisesFont = NULL;
    config.mUseSelectReturn = 0;
    config.mUseBackScreen = 0;
    config.mBackScreenKind = 0;
    PrepareNavigationContextFiles_from_thumb();
    InitializeNavigationContext_from_thumb(heap, &config);
    LoadAndQueueScreenMapFileSet(SCREEN_SIDE_MAIN, &mainScreenMapFileSet, "results_gp_m_b.NCGR", "results_gp_m_b.NCLR",
                                 "results_gp_m1.NSCR", 1, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb);
    MaybeReadScreenBlock_0(&mainScreenMapFileSet.mScreenMaps[3], FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("results_gp_m2.NSCR"));
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_BG3_MAP, 0, &mainScreenMapFileSet.mScreenMaps[3]->mData,
                                       mainScreenMapFileSet.mScreenMaps[3]->mDataSize);
    mainObjSize = GX_GetSizeOfOBJ();
    mainFileSet = &g_GlobalM->mCellFileSets[0];
    PlayerGfxData_Create_from_thumb(mainFileSet, "results_gp_m.nce.ncgr", "results_gp_m.nce.ncer", "results_gp_m_o.NCLR",
                    "results_gp_m.bncl", "results_gp_m.bnll", NULL, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb);
    SetupCellFileSet(SCREEN_SIDE_MAIN, heap, mainFileSet);
    CopyMemory16(&g_SaveDataHolder->mFirstBlock->mPlayerName, playerName, 0x14);
    playerName[10] = 0;
    InitLabelCanvas(heap, 0, mainFileSet->mLabelLayout, 0x82, 0xd, 0x14, mainFileSet->mCells, mainFileSet->mCellLayout,
                    mainFileSet->mCellTable, mainObjSize);
    PrintLabelLayoutTextNoFixedAdvance(0, 0, mainFileSet->mLabelLayout, playerName, mainFileSet->mCellLayout,
                                       mainFileSet->mCellTable);
    SetLabelPriority(0, 1, mainFileSet->mLabelLayout, mainFileSet->mCellTable, mainFileSet->mCellLayout);
    for (index = 0; index < 8; index++) {
        if (index == g_GlobalM->mCupRankIndex) {
            cellFlag = 1;
        } else {
            cellFlag = 0;
        }
        mainFileSet->mCellTable[gCupRankCellIndexTable[index]].mVisible = cellFlag;
    }
    for (index = 0; index < 8; index++) {
        if (index == g_GlobalM->mGrade) {
            cellFlag = 1;
        } else {
            cellFlag = 0;
        }
        mainFileSet->mCellTable[gResultsGpGradeCellIndices[index]].mVisible = cellFlag;
    }
    if (g_GlobalM->mCupRankIndex >= CUP_RANK_TROPHY_COUNT) {
        cellFlag = 1;
    } else {
        cellFlag = 0;
    }
    mainFileSet->mCellTable[3].mVisible = cellFlag;
    mainFileSet->mCellTable[2].mVisible = mainFileSet->mCellTable[3].mVisible;
    mainFileSet->mCellTable[1].mVisible = (mainFileSet->mCellTable[2].mVisible == 0) ? 1 : 0;
    mainFileSet->mCellTable[0].mVisible = mainFileSet->mCellTable[1].mVisible;
    characterIndex = g_GlobalB488->mCharacterIndex;
    mainFileSet = &g_GlobalM->mCellFileSets[0];
    LoadPlayerGfxData_from_thumb(1, &cellFileSet);
    QueueCellCharsAndFirstPalette(characterIndex, cellFileSet.mCells, cellFileSet.mChars, cellFileSet.mPalette,
                                  cellFileSet.mCellLayout, 0, 0x14, mainFileSet->mCells, mainFileSet->mCellLayout);
    LoadAndQueueScreenMapFileSet(SCREEN_SIDE_SUB, &subScreenMapFileSet, "results_gp_s_b.NCGR", "results_gp_s_b.NCLR",
                                 "results_gp_s.NSCR", 3, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb);
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    subFileSet = &g_GlobalM->mCellFileSets[1];
    PlayerGfxData_Create_from_thumb(subFileSet, "results_gp_s.nce.ncgr", "results_gp_s.nce.ncer", "results_gp_s_o.NCLR",
                    "results_gp_s.bncl", "results_gp_s.bnll", NULL, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb);
    SetupCellFileSet(SCREEN_SIDE_SUB, heap, subFileSet);
    loopIndex = 0;
    tableEntry = gResultsGpSubLabelCanvasEntries;
    for (; loopIndex < 16; loopIndex++) {
        subObjSizeLeft -= SetupLabelCanvas(SCREEN_SIDE_SUB, heap, subFileSet, tableEntry, subObjSizeLeft);
        tableEntry++;
    }
    message = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mCommonMessages, g_CommonBmgCircuitCcTable[g_GlobalB488->mEngineIndex]);
    for (loopIndex = 0; loopIndex < 2; loopIndex++) {
        PrintLabelLayoutTextNoFixedAdvance(1, gResultsGpSubLabelCanvasEntries[labelTableIndex].mLabelIndex,
                                           subFileSet->mLabelLayout, message, subFileSet->mCellLayout,
                                           subFileSet->mCellTable);
        labelTableIndex++;
    }
    if (g_GlobalB488->mMirrorMode != 0) {
        message = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mCommonMessages, 0x71);
        for (loopIndex = 0; loopIndex < 2; loopIndex++) {
            PrintLabelLayoutTextNoFixedAdvance(1, gResultsGpSubLabelCanvasEntries[labelTableIndex].mLabelIndex,
                                               subFileSet->mLabelLayout, message, subFileSet->mCellLayout,
                                               subFileSet->mCellTable);
            labelTableIndex++;
        }
    } else {
        labelTableIndex += 2;
    }
    for (courseIndex = 0; courseIndex < 4; courseIndex++) {
        message = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mCommonMessages,
                              GetBmgIndexFromCircuitIndex_from_thumb(gResultsGpCupCourseIds[g_GlobalM->mCupIndex][courseIndex]));
        PrintLabelLayoutTextNoFixedAdvance(1, gResultsGpSubLabelCanvasEntries[labelTableIndex].mLabelIndex,
                                           subFileSet->mLabelLayout, message, subFileSet->mCellLayout,
                                           subFileSet->mCellTable);
        labelTableIndex++;
    }
    for (loopIndex = 0; loopIndex < 4; loopIndex++) {
        WriteCourseTimeText(timeText, loopIndex);
        PrintLabelLayoutTextFixedDigits(1, gResultsGpSubLabelCanvasEntries[labelTableIndex].mLabelIndex,
                                        subFileSet->mLabelLayout, timeText, subFileSet->mCellLayout,
                                        subFileSet->mCellTable, 7);
        PrintLabelLayoutTextFixedDigits(1, gResultsGpSubLabelCanvasEntries[labelTableIndex + 4].mLabelIndex,
                                        subFileSet->mLabelLayout, timeText, subFileSet->mCellLayout,
                                        subFileSet->mCellTable, 7);
        labelTableIndex++;
    }
    subFileSet = &g_GlobalM->mCellFileSets[1];
    PlayerGfxData_Create_from_thumb(&cupNameFileSet, "cup_name_left.nce.ncgr", "cup_name_left.nce.ncer", NULL, "cup_name_left.bncl",
                    NULL, NULL, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb);
    QueueCellChars(gCupNameLeftCharIndices[g_GlobalM->mCupIndex], cupNameFileSet.mCells, cupNameFileSet.mChars,
                   cupNameFileSet.mCellLayout, 1, 0, subFileSet->mCells, subFileSet->mCellLayout);
    InitFrmVramManagers();
    LoadCupTrophyModel(g_GlobalM->mCupIndex, g_GlobalM->mCupRankIndex);
    index = -1;
    switch (g_GlobalM->mGrade) {
        case RESULTS_GP_GRADE_THIRD_BEST:
            index = 0x1e;
            break;
        case RESULTS_GP_GRADE_SECOND_BEST:
            index = 0x1f;
            break;
        case RESULTS_GP_GRADE_BEST:
            index = 0x20;
            break;
    }
    if (index >= 0) {
        PlaySseqFromSarc(&gSharedSeqHandle, 0, (u16) index);
    }
    if (CheckUpdateGrandPrixResult()) {
        WaitForWorkerTask();
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            j_WaitForPendingCardOperation();
        }
        g_GlobalM->mSecretMessageMask = GetCurrentUnlockedSecretFlagsAndSaveIfResultScene();
    }
}

// Draws the Grand Prix results; after a delay and a button press or touch, shows each pending secret message, then
// picks the next scene.
void HandleEarnedSecrets_from_thumb(SceneNumbers *sceneNumbers) {
    u32 inputSlotIndex;
    void *secretMessage;
    s32 screenIndex;
    inputSlotIndex = GetSomeCYId_9();
    secretMessage = NULL;
    for (screenIndex = 0; screenIndex < 2; screenIndex++) {
        DrawLayoutTable(g_GlobalM->mCellFileSets[screenIndex].mCellLayout,
                        g_GlobalM->mCellFileSets[screenIndex].mCells,
                        g_GlobalM->mCellFileSets[screenIndex].mLabelLayout, g_GlobalM->mOamLists[screenIndex],
                        g_GlobalM->mCellFileSets[screenIndex].mCellTable);
    }
    if (g_GlobalM->mCupRankIndex < CUP_RANK_TROPHY_COUNT) {
        AdvanceTrophy();
        DrawTrophy();
    }
    switch (g_GlobalM->mState) {
        case RESULTS_GP_STATE_TIMELINE: {
            s32 frameLimit;
            s32 frames;
            frameLimit = GetResultsGpFrameLimit(g_GlobalM->mCupRankIndex);
            frames = g_GlobalM->mStateFrames;
            g_GlobalM->mStateFrames = frames + 1;
            if (frames >= frameLimit) {
                void *commonMessage;
                u32 messageMask;
                if (!(u16) (g_GlobalCYT[inputSlotIndex].mPressedBits & PAD_KEY_A)) {
                    BOOL newlyPaired;
                    BOOL recentlyUnpaired;
                    u16 hasPair;
                    newlyPaired = FALSE;
                    recentlyUnpaired = FALSE;
                    hasPair = g_GlobalCYT[inputSlotIndex].mPair.mHasPair;
                    if (hasPair == 0) {
                        if (g_GlobalCYT[inputSlotIndex].mPair.mNoPairCount < INPUT_NO_PAIR_BRIEF_FRAMES) {
                            recentlyUnpaired = TRUE;
                        }
                    }
                    if (recentlyUnpaired == FALSE) {
                        if (g_GlobalCYT[inputSlotIndex].mPair.mPrevHasPair == 0) {
                            if (hasPair != 0) {
                                newlyPaired = TRUE;
                            }
                        }
                    }
                    if (newlyPaired == FALSE) {
                        break;
                    }
                }
                commonMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mCommonMessages, 4);
                messageMask = g_GlobalM->mSecretMessageMask;
                if (messageMask != 0) {
                    if (messageMask & 0x1) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 0);
                        g_GlobalM->mSecretMessageMask &= ~0x1;
                    } else if (messageMask & 0x2) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 1);
                        g_GlobalM->mSecretMessageMask &= ~0x2;
                    } else if (messageMask & 0x4) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 2);
                        g_GlobalM->mSecretMessageMask &= ~0x4;
                    } else if (messageMask & 0x8) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 3);
                        g_GlobalM->mSecretMessageMask &= ~0x8;
                    } else if (messageMask & 0x10) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 4);
                        g_GlobalM->mSecretMessageMask &= ~0x10;
                    } else if (messageMask & 0x20) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 5);
                        g_GlobalM->mSecretMessageMask &= ~0x20;
                    } else if (messageMask & 0x40) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 6);
                        g_GlobalM->mSecretMessageMask &= ~0x40;
                    } else if (messageMask & 0x80) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 7);
                        g_GlobalM->mSecretMessageMask &= ~0x80;
                    } else if (messageMask & 0x100) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 8);
                        g_GlobalM->mSecretMessageMask &= ~0x100;
                    } else if (messageMask & 0x200) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 9);
                        g_GlobalM->mSecretMessageMask &= ~0x200;
                    } else if (messageMask & 0x400) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 10);
                        g_GlobalM->mSecretMessageMask &= ~0x400;
                    } else if (messageMask & 0x800) {
                        secretMessage = Bmg_GetRawStringPointer_from_thumb(g_GlobalM->mSecretMessages, 11);
                        g_GlobalM->mSecretMessageMask &= ~0x800;
                    }
                    TextSystem_SetFadeInSseqId_from_thumb(0x53);
                    TextSystem_DisplaySingleButtonDialog_from_thumb(secretMessage, commonMessage, 0, 1, 1, 0);
                    g_GlobalM->mState = RESULTS_GP_STATE_TEXT_OPEN;
                } else {
                    switch (GetStaffRollKindAfterGp()) {
                        case STAFF_ROLL_AFTER_GP_NONE:
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = SCENE_TITLE;
                            }
                            break;
                        case STAFF_ROLL_AFTER_GP_NORMAL:
                            SetupStaffRollRace(0);
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = SCENE_RACE;
                            }
                            break;
                        case STAFF_ROLL_AFTER_GP_TRUE:
                            SetupStaffRollRace(1);
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = SCENE_RACE;
                            }
                            break;
                    }
                    PlaySseqFromSarc(&gSharedSeqHandle, 0, 5);
                    g_GlobalM->mState = RESULTS_GP_STATE_LEFT;
                }
            }
        } break;
        case RESULTS_GP_STATE_TEXT_OPEN:
            if (TextSystem_WasAnyDialogButtonPressed_from_thumb()) {
                TextSystem_CloseDialog_from_thumb();
                g_GlobalM->mState = RESULTS_GP_STATE_TIMELINE;
            }
            break;
    }
    NavigationContext_OnSceneUpdate_from_thumb();
}

#pragma thumb off
