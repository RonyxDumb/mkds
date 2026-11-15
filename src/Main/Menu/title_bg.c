#include "Main/Menu/title_bg.h"
#include "registers.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/title_scene.h"
#include "Main/Race/gp_records_killer.h"

#include "Main/System/key_recording_buffer.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Graphics/scene_text_init.h"
#include "vram_bank_display_setup.h"
#include "Main/Menu/title_state4.h"
#include "Main/Menu/title_blend.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Menu/menu.h"
#include "Main/Menu/shuffled_indices.h"
#include "Main/Menu/keyboard_cursor_targets.h"
#include "Main/Kart/kart_ai_item_use.h"
#include "Main/Menu/keyboard_char_tables.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "display_blend_affine_setup.h"
#include "vram_load_2d_graphics.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Menu/menu_shared_clear.h"

const u16 gTitleDisplaySettingsDesc[20] = {1, 0x1e, 0x1c, 1, 0, 0,     0,    2, 0x60, 0x10,
                                           0, 1,    0,    0, 4, 0x100, 0x80, 0, 8,    0};
TitleScene *gTitleScene;

void *TitleGetCurrentHeap(void) {
    return GetHeap(GetCurrentHeapCall());
}

u32 GetTitleBlendDone(void) {
    return (gMenuShared->mTitleBlendDone);
}

void TitleSetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                           u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg1Record(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void TitleSetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    SetBg2RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void TitleSetMainBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void TitleSetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void TitleGX_SetOBJVRamModeChar(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

void TitleGXS_SetOBJVRamModeChar(u32 bits) {
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_EXOBJ_CH_MASK | REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

void TitleWriteSubBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2);
}

u32 WriteMainWinEnableBits(u32 bits) {
    u32 dispcntValue =
        (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK)) | (bits << 13);
    reg_GX_DISPCNT = dispcntValue;
    return dispcntValue;
}

u32 TitleWriteSubWinEnableBits(u32 bits) {
    u32 dispcntValue =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK)) |
        (bits << 13);
    reg_GXS_DB_DISPCNT = dispcntValue;
    return dispcntValue;
}

void TitleSetRaceSetupRequested(u32 value) {
    gMenuShared->mRaceSetupRequested = value;
}

void TitleSetMenuEntryKind(u32 value) {
    gMenuShared->mMenuEntryKind = value;
}

void TitleSetUnfilledNotEliminated(u32 value) {
    gMenuShared->mUnfilledNotEliminated = value;
}

void TitleSetLVselIndex6Requested(u32 value) {
    gMenuShared->mLVselIndex6Requested = value;
}

#pragma thumb on

void CreateTitleScene(void) {
    s32 useTrueFiles;
    s32 objSizeLeft;
    DisplaySettings *displaySettings;
    SceneTextInitParams config;

    useTrueFiles = IsAllGrandPrixRecordsTopRank();
    gTitleScene = HeapAlloc(TitleGetCurrentHeap(), sizeof(TitleScene));
    gTitleScene->mStateFrames = 0;
    gTitleScene->mStateChanged = TRUE;
    gTitleScene->mPrevState = TITLE_STATE_BLEND_IN;
    gTitleScene->mState = TITLE_STATE_BLEND_IN;
    // Past the end of the 7-entry state table.
    gTitleScene->mNextState = TITLE_NEXT_STATE_NONE;
    gTitleScene->mNoInputFrames = 0;
    gTitleScene->mBlendDone = GetTitleBlendDone() != 0;
    gTitleScene->mSelectedIndex = TITLE_ENTRY_FIRST;
    gTitleScene->mStartedOnSelected = FALSE;
    gTitleScene->mPreferRecordEntry = TRUE;
    gTitleScene->mSelectedOffset = 0;
    gTitleScene->mBlendFrames = GetTitleBlendDone() != 0 ? 0x6b : 0;
    AdvanceTitleBlend();
    InitTitleStateHandlers();
    ResetOamLists(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
    LoadNclrData(&gTitleScene->mTitleTrueMBOrMBNclr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? "title_true_m_b.NCLR" : "title_m_b.NCLR"));
    LoadNclrData(&gTitleScene->mTitleSBNclr, FindSceneFileWrapper("title_s_b.NCLR"));
    LoadNcgrData(&gTitleScene->mTitleTrueMBOrMBNcgr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? "title_true_m_b.NCGR" : "title_m_b.NCGR"));
    LoadNcgrData(&gTitleScene->mTitleSBNcgr, FindSceneFileWrapper("title_s_b.NCGR"));
    LoadNscrData(&gTitleScene->mTitleTrueM1OrM1Nscr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? "title_true_m1.NSCR" : "title_m1.NSCR"));
    LoadNscrData(&gTitleScene->mTitleTrueM2OrM2Nscr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? "title_true_m2.NSCR" : "title_m2.NSCR"));
    LoadNscrData(&gTitleScene->mTitleSBgNscr, FindSceneFileWrapper("title_s_bg.NSCR"));
    LoadNclrData(&gTitleScene->mTitleSONclr, FindSceneFileWrapper("title_s_o.NCLR"));
    LoadNcgrData2(&gTitleScene->mTitleSNceNcgr, FindSceneFileWrapper("title_s.nce.ncgr"));
    LoadNcerData(&gTitleScene->mTitleSNceNcer, FindSceneFileWrapper("title_s.nce.ncer"));
    gTitleScene->mTitleSBncl = FindSceneFileWrapper("title_s.bncl");
    gTitleScene->mTitleSBnbl = FindSceneFileWrapper("title_s.bnbl");
    gTitleScene->mTitleSBnll = FindSceneFileWrapper("title_s.bnll");
    displaySettings = CreateDisplaySettings(TitleGetCurrentHeap(), gTitleDisplaySettingsDesc);
    TitleSetMainBg1Record(displaySettings, 0, 0, 0, 0, 2, 0, 0);
    TitleSetMainBg2RecordParams(displaySettings, 2, 0, 0, 1, 14, 4);
    TitleSetMainBg3RecordParams(displaySettings, 3, 0, 0, 1, 15, 4);
    TitleSetSubBg3RecordParams(displaySettings, 3, 0, 0, 0, 1, 6);
    InitDisplayFromSettings(displaySettings);
    InitLayoutTable(TitleGetCurrentHeap(), gTitleScene->mTitleSBncl, gTitleScene->mTitleSBnll,
                    &gTitleScene->mTitleTable);
    SetCellOamModeXlu(0, 1, gTitleScene->mTitleSNceNcer, gTitleScene->mTitleSBncl);
    SetCellOamModeXlu(1, 1, gTitleScene->mTitleSNceNcer, gTitleScene->mTitleSBncl);
    SetCellOamModeXlu(2, 1, gTitleScene->mTitleSNceNcer, gTitleScene->mTitleSBncl);
    SetCellOamModeXlu(3, 1, gTitleScene->mTitleSNceNcer, gTitleScene->mTitleSBncl);
    SetCellOamModeXlu(4, 1, gTitleScene->mTitleSNceNcer, gTitleScene->mTitleSBncl);
    objSizeLeft = GX_GetSizeOfSubOBJ();
    objSizeLeft -=
        InitLabelCanvas(TitleGetCurrentHeap(), 0, gTitleScene->mTitleSBnll, 0x55, 0xd, 0xd, gTitleScene->mTitleSNceNcer,
                        gTitleScene->mTitleSBncl, gTitleScene->mTitleTable, objSizeLeft);
    InitLabelCanvas(TitleGetCurrentHeap(), 1, gTitleScene->mTitleSBnll, 0x55, 0xd, 0xe, gTitleScene->mTitleSNceNcer,
                    gTitleScene->mTitleSBncl, gTitleScene->mTitleTable, objSizeLeft);
    PrintLabelLayoutTextNoFixedAdvance(1, 0, gTitleScene->mTitleSBnll,
                                       GetBmgEntry(FindSceneFileWrapper("title.bmg"), 1), gTitleScene->mTitleSBncl,
                                       gTitleScene->mTitleTable);
    PrintLabelLayoutTextNoFixedAdvance(1, 1, gTitleScene->mTitleSBnll,
                                       GetBmgEntry(FindSceneFileWrapper("title.bmg"), 0), gTitleScene->mTitleSBncl,
                                       gTitleScene->mTitleTable);
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(gTitleScene->mTitleTrueMBOrMBNclr->mData, 0x4000, gTitleScene->mTitleTrueMBOrMBNclr->mDataSize);
    GX_LoadBGExtPltt(gTitleScene->mTitleTrueMBOrMBNclr->mData, 0x6000, gTitleScene->mTitleTrueMBOrMBNclr->mDataSize);
    GX_EndLoadBGExtPltt();
    GX_LoadBG2Char(gTitleScene->mTitleTrueMBOrMBNcgr->mData, 0, gTitleScene->mTitleTrueMBOrMBNcgr->mDataSize);
    GX_LoadBG2Scr(gTitleScene->mTitleTrueM1OrM1Nscr->mData, 0, 0x800);
    GX_LoadBG3Scr(gTitleScene->mTitleTrueM2OrM2Nscr->mData, 0, 0x800);
    GXS_LoadBGPltt(gTitleScene->mTitleSBNclr->mData, 0, gTitleScene->mTitleSBNclr->mDataSize);
    GXS_LoadBG3Char(gTitleScene->mTitleSBNcgr->mData, 0, gTitleScene->mTitleSBNcgr->mDataSize);
    GXS_LoadBG3Scr(gTitleScene->mTitleSBgNscr->mData, 0, 0x800);
    GXS_LoadOBJPltt(gTitleScene->mTitleSONclr->mData, 0, gTitleScene->mTitleSONclr->mDataSize);
    GXS_LoadOBJ(gTitleScene->mTitleSNceNcgr->mData, 0, gTitleScene->mTitleSNceNcgr->mDataSize);
    TitleGX_SetOBJVRamModeChar(0x10);
    TitleGXS_SetOBJVRamModeChar(0x10);
    TitleWriteMainBlendAlpha(4, 8, 0, 0x10);
    TitleWriteSubBlendAlpha(0, 0x3f, 6, 10);
    WriteMainWinEnableBits(0);
    TitleWriteSubWinEnableBits(0);
    config.mUseTxtSystem = 0;
    config.mTxtSystemFont = NULL;
    config.mUseCanvas1 = 0;
    config.mUseCanvas2 = 0;
    config.mUseCanvas3 = 0;
    config.mUseSelectChoises = 0;
    config.mSelectChoisesFont = GetFontByIndex(0);
    config.mUseSelectReturn = 0;
    config.mUseBackScreen = 0;
    config.mBackScreenKind = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    InitSceneText(TitleGetCurrentHeap(), &config);
    gTitleScene->mCharacterKartPicks = CreateCharacterKartPicks(TitleGetCurrentHeap());
    SetConnectionKind(0);
    SetMultiSimple(0);
    ClearShuffledIndices();
    TitleSetRaceSetupRequested(1);
    TitleSetMenuEntryKind(0);
    TitleSetUnfilledNotEliminated(0);
    TitleSetLVselIndex6Requested(0);
    ResetRaceSetup();
}

#pragma thumb off

#pragma thumb on

void ReleaseTitleSceneObject(void) {
    ReleaseSceneText();
    gTitleScene = NULL;
}

#pragma thumb off

void TitleWriteMainBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, plane1, plane2, ev1, ev2);
}

// Set when the title blend has run to its end; CreateTitleScene then starts its blend already finished.
void SetTitleBlendDone(u32 blendDone) {
    gMenuShared->mTitleBlendDone = blendDone;
}
