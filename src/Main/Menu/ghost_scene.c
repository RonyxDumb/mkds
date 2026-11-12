#include "Main/Menu/ghost_scene.h"
#include "Main/MapObjects/data_02154000.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/kart_icon.h"
#include "Main/Menu/data_02163000.h"
#include "Main/Menu/data_02174000.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Graphics/message_index.h"
#include "code_0214cfe4.h"
#include "Main/Race/ghost_list.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Net/led_pattern.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Save/slot_ghost_records.h"
#include "Main/Save/course_ghost_records.h"
#include "Main/Race/race.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Menu/menu.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/message_screen.h"
#include "Main/Menu/data_02162c74.h"
#include "Main/Menu/time_attack_ghost_get_scan.h"
#include "Main/Menu/ghost_send.h"
#include "code_0214d018.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Graphics/minute_second_millisecond_text.h"
#include "registers.h"

GhostSceneCallbacks *gGhostSceneCallbacks[3] = {&gTimeAttackGhostSendCallbacks, &gTimeAttackGhostGetScanCallbacks, &data_usa_02164460};
GhostScene *gGhostScene;

#pragma thumb on

u32 GhostSceneGetCupCourseIdAtIndex(s32 cupCourseIndex) {
    return gCupCourseIdTable[cupCourseIndex / 4][cupCourseIndex % 4];
}

#pragma thumb off

#pragma thumb on

// Unpacks the Chars, Cells, Palette and ScreenMap files of the ghost scene in place; nothing is kept.
void LoadGhostSceneFiles(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    Unk02021dc8 *cells;
    Nscr *screenMaps[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMaps[0] = NULL;
    file = FindSceneFile("TimeAttack_ghost_get_m_b.NCGR");
    LoadNcgrData(&chars, file);
    file = FindSceneFile("TimeAttack_ghost_get_s_b.NCGR");
    LoadNcgrData(&chars, file);
    file = FindSceneFile("TimeAttack_ghost_send_m_b.NCGR");
    LoadNcgrData(&chars, file);
    file = FindSceneFile("TimeAttack_ghost_send_s_b.NCGR");
    LoadNcgrData(&chars, file);
    file = FindSceneFile("TimeAttack_ghost_get_m.nce.ncgr");
    LoadNcgrData2(&chars, file);
    file = FindSceneFile("TimeAttack_ghost_get_s.nce.ncgr");
    LoadNcgrData2(&chars, file);
    file = FindSceneFile("TimeAttack_ghost_send_m.nce.ncgr");
    LoadNcgrData2(&chars, file);
    file = FindSceneFile("TimeAttack_ghost_send_s.nce.ncgr");
    LoadNcgrData2(&chars, file);
    file = FindSceneFile("TimeAttack_ghost_get_m.nce.ncer");
    LoadNcerData(&cells, file);
    file = FindSceneFile("TimeAttack_ghost_get_s.nce.ncer");
    LoadNcerData(&cells, file);
    file = FindSceneFile("TimeAttack_ghost_send_m.nce.ncer");
    LoadNcerData(&cells, file);
    file = FindSceneFile("TimeAttack_ghost_send_s.nce.ncer");
    LoadNcerData(&cells, file);
    file = FindSceneFile("TimeAttack_ghost_get_m_b.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("TimeAttack_ghost_get_m_o.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("TimeAttack_ghost_get_s_b.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("TimeAttack_ghost_get_s_o.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("TimeAttack_ghost_send_m_b.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("TimeAttack_ghost_send_s_b.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("TimeAttack_ghost_send_m_o.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("TimeAttack_ghost_send_s_o.NCLR");
    LoadNclrData(&palette, file);
    file = FindSceneFile("TimeAttack_ghost_get_m.NSCR");
    LoadNscrData(screenMaps, file);
    file = FindSceneFile("TimeAttack_ghost_get_s.NSCR");
    LoadNscrData(screenMaps, file);
    file = FindSceneFile("TimeAttack_ghost_send_m.NSCR");
    LoadNscrData(screenMaps, file);
    file = FindSceneFile("TimeAttack_ghost_send_s.NSCR");
    LoadNscrData(screenMaps, file);
    LoadKartIconData();
}

#pragma thumb off

#pragma thumb on

void InitGhostScene(void *heap) {
    SceneTextInitParams arg;
    DisplaySettings *displaySettings;
    s32 index;
    u32 courseId;
    GhostRecordHead *courseRecords;
    s32 cupCourseIndex;
    gGhostScene = HeapAlloc(heap, 0x8dc);
    MemFillWordsByBlock_inline(gGhostScene, 0x8dc);
    gGhostScene->mCourseGhostBuffer = HeapAllocAligned(heap, 0xe00, 0x20);
    gGhostScene->mSlotGhostBuffer = HeapAllocAligned(heap, 0x1000, 0x20);
    displaySettings = CreateDisplaySettings(heap, gGhostSceneDisplaySettingsDesc);
    SetBg0Record(&displaySettings->mMainBgRecords, 1, 0, 0, 0, 0, 1, 0);
    SetBg3RecordParams(&displaySettings->mSubBgRecords, 2, 0, 0, 0, 0xf, 0);
    InitDisplayFromSettings(displaySettings);
    LoadGhostSceneFiles();
    arg.mUseTxtSystem = 1;
    arg.mTxtSystemFont = GetFontByIndex(1);
    arg.mUseCanvas1 = 1;
    arg.mUseCanvas2 = 1;
    arg.mUseCanvas3 = 0;
    arg.mUseSelectChoises = 0;
    arg.mSelectChoisesFont = NULL;
    arg.mUseSelectReturn = 1;
    arg.mUseBackScreen = 1;
    arg.mBackScreenKind = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(heap, &arg);
    SetTxtSystemMode(1);
    InitLinkLevelIcons(heap, gGhostScene);
    CreateKartIcon(heap);
    for (index = 0; index < 0x20; index++) {
        gGhostScene->mCupCourseIndices[index] = -1;
    }
    for (index = 0; index < 10; index++) {
        gGhostScene->mSlotIndices[index] = -1;
    }
    gGhostScene->mCourseGhostRecords = CreateCourseGhostRecords(heap);
    StartReadCourseGhostRecords(gGhostScene->mCourseGhostRecords);
    WaitThreadFunctionsDone();
    for (index = 0; index < 0x20; index++) {
        courseId = GhostSceneGetCupCourseIdAtIndex(index);
        courseRecords = gGhostScene->mCourseGhostRecords;
        cupCourseIndex = FindCupCourseIndex(courseId);
        if (IsGhostRecordFilled(&courseRecords[cupCourseIndex]) != FALSE) {
            gGhostScene->mCupCourseIndices[gGhostScene->mCourseGhostCount] = index;
            gGhostScene->mGhostCount++;
            gGhostScene->mCourseGhostCount++;
        }
    }
    gGhostScene->mSlotGhostRecords = CreateSlotGhostRecords(heap);
    StartReadSlotGhostRecords(gGhostScene->mSlotGhostRecords);
    WaitThreadFunctionsDone();
    for (index = 0; index < 10; index++) {
        if (IsGhostRecordFilled(GetSlotGhostRecordHead(index)) != FALSE) {
            gGhostScene->mSlotIndices[gGhostScene->mSlotGhostCount] = index;
            gGhostScene->mGhostCount++;
            gGhostScene->mSlotGhostCount++;
        }
    }
    ResetOamLists(gGhostScene, gGhostScene->mSubOam);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    switch (gMenuShared->mGhostSceneInitialCallbacksIndex) {
        case 0:
            gGhostScene->mRequestedCallbacksIndex = 0;
            break;
        case 1:
            gGhostScene->mRequestedCallbacksIndex = 1;
            break;
    }
    gGhostScene->mCurrentCallbacksIndex = gGhostScene->mRequestedCallbacksIndex;
    gGhostScene->mCurrentCallbacks = gGhostSceneCallbacks[gGhostScene->mRequestedCallbacksIndex];
    gGhostScene->mHeap = CreateExpHeapFromMaxFree(heap);
    gGhostScene->mCurrentCallbacks->mInit(gGhostScene->mHeap, gGhostScene, gGhostScene->mSubOam);
}

void AdvanceGhostScene(s32 sceneNumbers) {
    s32 requestedIndex;
    s32 currentIndex;
    s32 nextIndex;
    GhostSceneCallbacks *oldCallbacks;
    requestedIndex = gGhostScene->mRequestedCallbacksIndex;
    currentIndex = gGhostScene->mCurrentCallbacksIndex;
    if (currentIndex != requestedIndex) {
        oldCallbacks = gGhostScene->mCurrentCallbacks;
        gGhostScene->mCurrentCallbacks = gGhostSceneCallbacks[requestedIndex];
        gGhostScene->mCurrentCallbacksIndex = gGhostScene->mRequestedCallbacksIndex;
        oldCallbacks->mRelease();
        gGhostScene->mCurrentCallbacks->mInit(gGhostScene->mHeap, gGhostScene, gGhostScene->mSubOam);
    } else {
        ClearOamListCounts(gGhostScene, gGhostScene->mSubOam);
        nextIndex = gGhostScene->mCurrentCallbacks->mAdvance(sceneNumbers);
        if (nextIndex != -1) {
            gGhostScene->mRequestedCallbacksIndex = nextIndex;
        }
        HideUnusedOams(gGhostScene, gGhostScene->mSubOam);
    }
    AdvanceSceneText();
    AdvanceLinkLevelIcons();
}

void ReleaseGhostScene(void) {
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    ReleaseSceneText();
    ClearLinkLevelIconsPointer();
    ClearKartIconPointer();
    SendLedPatternNone();
}

void WriteGhostSceneRegisters(void) {
    WriteSceneTextRegisters();
    gGhostScene->mCurrentCallbacks->mWriteRegisters();
    UploadOamLists(gGhostScene, gGhostScene->mSubOam);
}

#pragma thumb off

#pragma thumb on

void PrintGhostRecordInfo(GhostInfoFileSets *fileSets, const s16 (*labelRows)[4], void *name, s32 characterIndex,
                          s32 kartIndex, s32 courseId, MinuteSecondMillisecondTime *time) {
    u16 timeText[10];
    u16 terminatedName[11];
    CellFileSet *cellFileSet;
    cellFileSet = &fileSets->mCellFileSets[2];
    PrintLabelLayoutTextNoFixedAdvance(0, labelRows[0][0], fileSets->mCellFileSets[0].mLabelLayout,
                                       GetBmgEntry(fileSets->mCommonMessages, GetCourseMessageIndex(courseId)),
                                       fileSets->mCellFileSets[0].mCellLayout, fileSets->mCellFileSets[0].mCellTable);
    WriteMinuteSecondMillisecondText((s16 *) timeText, time->mMinute, time->mSecond, time->mMillisecond);
    PrintLabelLayoutTextFixedDigits(0, labelRows[1][0], fileSets->mCellFileSets[0].mLabelLayout, timeText,
                                    fileSets->mCellFileSets[0].mCellLayout, fileSets->mCellFileSets[0].mCellTable, 7);
    MIi_CpuCopy16(name, terminatedName, 0x14);
    terminatedName[10] = 0;
    PrintLabelLayoutTextNoFixedAdvance(0, labelRows[2][0], fileSets->mCellFileSets[0].mLabelLayout, terminatedName,
                                       fileSets->mCellFileSets[0].mCellLayout, fileSets->mCellFileSets[0].mCellTable);
    QueueCellCharsAndFirstPalette(characterIndex, cellFileSet->mCells, fileSets->mCellFileSets[2].mChars,
                                  cellFileSet->mPalette, cellFileSet->mCellLayout, 0, labelRows[0][3],
                                  fileSets->mCellFileSets[0].mCells, fileSets->mCellFileSets[0].mCellLayout);
    QueueKartIcon(
        kartIndex, fileSets->mCellFileSets[0].mCells, fileSets->mCellFileSets[0].mCellLayout, labelRows[1][3],
        GetCellPaletteIndex(labelRows[1][3], fileSets->mCellFileSets[0].mCells, fileSets->mCellFileSets[0].mCellLayout),
        0);
}

#pragma thumb off

#pragma thumb on

GhostRecord *GetCourseGhostBuffer(void) {
    return gGhostScene->mCourseGhostBuffer;
}

SlotGhostRecord *GetSlotGhostBuffer(void) {
    return gGhostScene->mSlotGhostBuffer;
}

u32 GetGhostCount(void) {
    return (gGhostScene->mGhostCount);
}

u32 GetCourseGhostCount(void) {
    return (gGhostScene->mCourseGhostCount);
}

u32 GetSlotGhostCount(void) {
    return (gGhostScene->mSlotGhostCount);
}

#pragma thumb off
