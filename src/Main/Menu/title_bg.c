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
#include "Main/Menu/title_select_press.h"
#include "Main/Menu/title_blend.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
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
TitleScene *g_SceneTitleContext;

void *GetActiveExecutionContextHeapHandle_4(void) {
    return ExecutionContext_GetHeapHandle(GetActiveExecutionContext());
}

u32 GetB488TitleMenuSkipIntro(void) {
    return (g_GlobalB488->mTitleBlendDone);
}

void DisplayConfig_SetTopEngineBg1Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14, u32 cntVal7,
                           u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    DisplayEngineConfig_SetBg1Config(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void DisplayConfig_SetTopEngineBg2Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    DisplayEngineConfig_SetBg2Config2(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void DisplayConfig_SetTopEngineBg3Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    DisplayEngineConfig_SetBg3Config(&displaySettings->mMainBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void DisplayConfig_SetBottomEngineBg3Config(DisplaySettings *displaySettings, u32 cntLow2, u32 cntMosaic, u32 cntVal14,
                                u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    DisplayEngineConfig_SetBg3Config(&displaySettings->mSubBgRecords, cntLow2, cntMosaic, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void SetDispcntTopDisplayFrameSelect(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

void SetDispcntSubDisplayFrameSelect(u32 bits) {
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_EXOBJ_CH_MASK | REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK)) | bits;
}

void EnableAlphaSetSubBldcntBldalpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2);
}

u32 SetTopDispcntWindow0Window1ObjDisplayFlag(u32 bits) {
    u32 dispcntValue =
        (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK)) | (bits << 13);
    reg_GX_DISPCNT = dispcntValue;
    return dispcntValue;
}

u32 SetSubDispcntWindow0Window1ObjDisplayFlag(u32 bits) {
    u32 dispcntValue =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK)) |
        (bits << 13);
    reg_GXS_DB_DISPCNT = dispcntValue;
    return dispcntValue;
}

void SetB488_b2(u32 value) {
    g_GlobalB488->mRaceSetupRequested = value;
}

void SetB488SinglePlayerMenuTarget(u32 value) {
    g_GlobalB488->mMenuEntryKind = value;
}

void SetB488_b5(u32 value) {
    g_GlobalB488->mUnfilledNotEliminated = value;
}

void SetB488_b6(u32 value) {
    g_GlobalB488->mLVselIndex6Requested = value;
}

#pragma thumb on

void LoadTitleFiles_from_thumb(void) {
    s32 useTrueFiles;
    s32 objSizeLeft;
    DisplaySettings *displaySettings;
    SceneTextInitParams config;

    useTrueFiles = IsTitleTrue();
    g_SceneTitleContext = Mem_AllocateHeap(GetActiveExecutionContextHeapHandle_4(), sizeof(TitleScene));
    g_SceneTitleContext->mStateFrames = 0;
    g_SceneTitleContext->mStateChanged = TRUE;
    g_SceneTitleContext->mPrevState = TITLE_STATE_BLEND_IN;
    g_SceneTitleContext->mState = TITLE_STATE_BLEND_IN;
    // Past the end of the 7-entry state table.
    g_SceneTitleContext->mNextState = TITLE_NEXT_STATE_NONE;
    g_SceneTitleContext->mNoInputFrames = 0;
    g_SceneTitleContext->mBlendDone = GetB488TitleMenuSkipIntro() != 0;
    g_SceneTitleContext->mSelectedIndex = TITLE_ENTRY_FIRST;
    g_SceneTitleContext->mStartedOnSelected = FALSE;
    g_SceneTitleContext->mPreferRecordEntry = TRUE;
    g_SceneTitleContext->mSelectedOffset = 0;
    g_SceneTitleContext->mBlendFrames = GetB488TitleMenuSkipIntro() != 0 ? 0x6b : 0;
    Title_SomeBldalphaConfig_from_thumb();
    Title_CopyFunctionList_from_thumb();
    OamBuffer_SomeFn_from_thumb(&g_SceneTitleContext->mMainOam, &g_SceneTitleContext->mSubOam);
    Gfx_ReadPalette(&g_SceneTitleContext->mTitleTrueMBOrMBNclr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L(useTrueFiles != 0 ? "title_true_m_b.NCLR" : "title_m_b.NCLR"));
    Gfx_ReadPalette(&g_SceneTitleContext->mTitleSBNclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("title_s_b.NCLR"));
    Gfx_ReadCharGraphicsV2(&g_SceneTitleContext->mTitleTrueMBOrMBNcgr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L(useTrueFiles != 0 ? "title_true_m_b.NCGR" : "title_m_b.NCGR"));
    Gfx_ReadCharGraphicsV2(&g_SceneTitleContext->mTitleSBNcgr, j_FindFileBuffer_K2D_LOC_R2D_R2L("title_s_b.NCGR"));
#ifdef version_EUR
    MaybeReadScreenBlock_0(&g_SceneTitleContext->mTitleTrueM1OrM1Nscr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L(useTrueFiles != 0 ? "title_true_m1_EU.NSCR" : "title_m1_EU.NSCR"));
#else
    MaybeReadScreenBlock_0(&g_SceneTitleContext->mTitleTrueM1OrM1Nscr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L(useTrueFiles != 0 ? "title_true_m1.NSCR" : "title_m1.NSCR"));
#endif
    MaybeReadScreenBlock_0(&g_SceneTitleContext->mTitleTrueM2OrM2Nscr,
                 j_FindFileBuffer_K2D_LOC_R2D_R2L(useTrueFiles != 0 ? "title_true_m2.NSCR" : "title_m2.NSCR"));
    MaybeReadScreenBlock_0(&g_SceneTitleContext->mTitleSBgNscr, j_FindFileBuffer_K2D_LOC_R2D_R2L("title_s_bg.NSCR"));
    Gfx_ReadPalette(&g_SceneTitleContext->mTitleSONclr, j_FindFileBuffer_K2D_LOC_R2D_R2L("title_s_o.NCLR"));
    Gfx_ReadCharGraphics(&g_SceneTitleContext->mTitleSNceNcgr, j_FindFileBuffer_K2D_LOC_R2D_R2L("title_s.nce.ncgr"));
    LoadCellBankFrom(&g_SceneTitleContext->mTitleSNceNcer, j_FindFileBuffer_K2D_LOC_R2D_R2L("title_s.nce.ncer"));
    g_SceneTitleContext->mTitleSBncl = j_FindFileBuffer_K2D_LOC_R2D_R2L("title_s.bncl");
    g_SceneTitleContext->mTitleSBnbl = j_FindFileBuffer_K2D_LOC_R2D_R2L("title_s.bnbl");
    g_SceneTitleContext->mTitleSBnll = j_FindFileBuffer_K2D_LOC_R2D_R2L("title_s.bnll");
    displaySettings = CreateDisplayConfig(GetActiveExecutionContextHeapHandle_4(), gTitleDisplaySettingsDesc);
    DisplayConfig_SetTopEngineBg1Config(displaySettings, 0, 0, 0, 0, 2, 0, 0);
    DisplayConfig_SetTopEngineBg2Config(displaySettings, 2, 0, 0, 1, 14, 4);
    DisplayConfig_SetTopEngineBg3Config(displaySettings, 3, 0, 0, 1, 15, 4);
    DisplayConfig_SetBottomEngineBg3Config(displaySettings, 3, 0, 0, 0, 1, 6);
    SetGlobalDisplayConfig(displaySettings);
    InitLayoutTable(GetActiveExecutionContextHeapHandle_4(), g_SceneTitleContext->mTitleSBncl, g_SceneTitleContext->mTitleSBnll,
                    &g_SceneTitleContext->mTitleTable);
    CellBank_ResetSomeMetatileObjectsMode_from_thumb(0, 1, g_SceneTitleContext->mTitleSNceNcer, g_SceneTitleContext->mTitleSBncl);
    CellBank_ResetSomeMetatileObjectsMode_from_thumb(1, 1, g_SceneTitleContext->mTitleSNceNcer, g_SceneTitleContext->mTitleSBncl);
    CellBank_ResetSomeMetatileObjectsMode_from_thumb(2, 1, g_SceneTitleContext->mTitleSNceNcer, g_SceneTitleContext->mTitleSBncl);
    CellBank_ResetSomeMetatileObjectsMode_from_thumb(3, 1, g_SceneTitleContext->mTitleSNceNcer, g_SceneTitleContext->mTitleSBncl);
    CellBank_ResetSomeMetatileObjectsMode_from_thumb(4, 1, g_SceneTitleContext->mTitleSNceNcer, g_SceneTitleContext->mTitleSBncl);
    objSizeLeft = GX_GetSizeOfSubOBJ();
    objSizeLeft -=
        InitLabelCanvas(GetActiveExecutionContextHeapHandle_4(), 0, g_SceneTitleContext->mTitleSBnll, 0x55, 0xd, 0xd, g_SceneTitleContext->mTitleSNceNcer,
                        g_SceneTitleContext->mTitleSBncl, g_SceneTitleContext->mTitleTable, objSizeLeft);
    InitLabelCanvas(GetActiveExecutionContextHeapHandle_4(), 1, g_SceneTitleContext->mTitleSBnll, 0x55, 0xd, 0xe, g_SceneTitleContext->mTitleSNceNcer,
                    g_SceneTitleContext->mTitleSBncl, g_SceneTitleContext->mTitleTable, objSizeLeft);
    PrintLabelLayoutTextNoFixedAdvance(1, 0, g_SceneTitleContext->mTitleSBnll,
                                       Bmg_GetRawStringPointer_from_thumb(j_FindFileBuffer_K2D_LOC_R2D_R2L("title.bmg"), 1), g_SceneTitleContext->mTitleSBncl,
                                       g_SceneTitleContext->mTitleTable);
    PrintLabelLayoutTextNoFixedAdvance(1, 1, g_SceneTitleContext->mTitleSBnll,
                                       Bmg_GetRawStringPointer_from_thumb(j_FindFileBuffer_K2D_LOC_R2D_R2L("title.bmg"), 0), g_SceneTitleContext->mTitleSBncl,
                                       g_SceneTitleContext->mTitleTable);
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(g_SceneTitleContext->mTitleTrueMBOrMBNclr->mData, 0x4000, g_SceneTitleContext->mTitleTrueMBOrMBNclr->mDataSize);
    GX_LoadBGExtPltt(g_SceneTitleContext->mTitleTrueMBOrMBNclr->mData, 0x6000, g_SceneTitleContext->mTitleTrueMBOrMBNclr->mDataSize);
    GX_EndLoadBGExtPltt();
    CopyBgData_Bg2_Top(g_SceneTitleContext->mTitleTrueMBOrMBNcgr->mData, 0, g_SceneTitleContext->mTitleTrueMBOrMBNcgr->mDataSize);
    TEQSub_Fn10Impl_Fn12Impl(g_SceneTitleContext->mTitleTrueM1OrM1Nscr->mData, 0, 0x800);
    TEQSub_Fn11Impl_Fn13Impl(g_SceneTitleContext->mTitleTrueM2OrM2Nscr->mData, 0, 0x800);
    CopyPaletteBottom(g_SceneTitleContext->mTitleSBNclr->mData, 0, g_SceneTitleContext->mTitleSBNclr->mDataSize);
    CopyBgData_Bg3_Bottom(g_SceneTitleContext->mTitleSBNcgr->mData, 0, g_SceneTitleContext->mTitleSBNcgr->mDataSize);
    TEQSub_Fn27Impl_Fn29Impl(g_SceneTitleContext->mTitleSBgNscr->mData, 0, 0x800);
    TEQSub_Fn30Impl(g_SceneTitleContext->mTitleSONclr->mData, 0, g_SceneTitleContext->mTitleSONclr->mDataSize);
    TEQSub_Fn35Impl(g_SceneTitleContext->mTitleSNceNcgr->mData, 0, g_SceneTitleContext->mTitleSNceNcgr->mDataSize);
    SetDispcntTopDisplayFrameSelect(0x10);
    SetDispcntSubDisplayFrameSelect(0x10);
    EnableAlphaSetTopBldcntBldalpha(4, 8, 0, 0x10);
    EnableAlphaSetSubBldcntBldalpha(0, 0x3f, 6, 10);
    SetTopDispcntWindow0Window1ObjDisplayFlag(0);
    SetSubDispcntWindow0Window1ObjDisplayFlag(0);
    config.mUseTxtSystem = 0;
    config.mTxtSystemFont = NULL;
    config.mUseCanvas1 = 0;
    config.mUseCanvas2 = 0;
    config.mUseCanvas3 = 0;
    config.mUseSelectChoises = 0;
    config.mSelectChoisesFont = GetLoadedFont_from_thumb(0);
    config.mUseSelectReturn = 0;
    config.mUseBackScreen = 0;
    config.mBackScreenKind = 0;
    PrepareNavigationContextFiles_from_thumb();
    InitializeNavigationContext_from_thumb(GetActiveExecutionContextHeapHandle_4(), &config);
    g_SceneTitleContext->mCharacterKartPicks = AllocateKartAppearTableData_from_thumb(GetActiveExecutionContextHeapHandle_4());
    SetGlobalPMaybeState(0);
    StructP_SetAFlag4_SkipBattleIntro(0);
    ResetB488HeyhoPaletteRows_from_thumb();
    SetB488_b2(1);
    SetB488SinglePlayerMenuTarget(0);
    SetB488_b5(0);
    SetB488_b6(0);
    PopulateGlobalCO();
}

#pragma thumb off

#pragma thumb on

void Scene_Title_FinalizeImpl_from_thumb(void) {
    DisposeNavigationContext_from_thumb();
    g_SceneTitleContext = NULL;
}

#pragma thumb off

void EnableAlphaSetTopBldcntBldalpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, plane1, plane2, ev1, ev2);
}

// Set when the title blend has run to its end; LoadTitleFiles_from_thumb then starts its blend already finished.
void SetB488TitleMenuSkipIntro(u32 blendDone) {
    g_GlobalB488->mTitleBlendDone = blendDone;
}
