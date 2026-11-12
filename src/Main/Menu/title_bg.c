#include "Main/Menu/title_bg.h"
#include "registers.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/Scene/display_settings.h"
#include "Main/Unknown/unk_02175000.h"
#include "00/code_02181f98.h"
#include "Main/Menu/title_scene.h"
#include "Main/Race/gp_records_killer.h"

#include "Main/Unknown/code_020ad32c.h"
#include "Main/Unknown/code_020ad344.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/System/key_recording_buffer.h"
#include "Main/Unknown/code_02090000.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Graphics/back_screen.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Unknown/code_02125de0.h"
#include "code_02148950.h"
#include "Main/Menu/title_state4.h"
#include "Main/Menu/title_blend.h"
#include "Main/Unknown/code_020ad820.h"
#include "Main/Unknown/code_020ad870.h"
#include "Main/Unknown/code_020ad8a4.h"
#include "Main/Unknown/code_020ad8e0.h"
#include "Main/Unknown/code_020ad9fc.h"
#include "Main/Unknown/code_020ada10.h"
#include "Main/Graphics/font_glyph_text.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/file_in_loaded.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Menu/menu.h"
#include "Main/Menu/shuffled_indices.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "g2.h"
#include "gx_load2d.h"
#include "Main/Race/race_entries.h"

void *TitleGetCurrentHeap(void) {
    return GetHeap(GetCurrentHeapCall());
}

u32 GetTitleBlendDone(void) {
    return (gMenuShared->mTitleBlendDone);
}

void TitleSetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7,
                           u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg1Record(&displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void TitleSetMainBg2RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    SetBg2RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void TitleSetMainBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14,
                                 u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void TitleSetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14,
                                u32 cntVal7Or13, u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, cntVal7Or13, cntVal8, cntVal2);
}

void TitleGX_SetOBJVRamModeChar(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | bits;
}

void TitleGXS_SetOBJVRamModeChar(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | bits;
}

void TitleWriteSubBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2);
}

u32 WriteMainWinEnableBits(u32 bits) {
    u32 dispcntValue = (reg_GX_DISPCNT & ~0xe000u) | (bits << 13);
    reg_GX_DISPCNT = dispcntValue;
    return dispcntValue;
}

u32 TitleWriteSubWinEnableBits(u32 bits) {
    u32 dispcntValue = (reg_GXS_DB_DISPCNT & ~0xe000u) | (bits << 13);
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
    gTitleScene = HeapAlloc(TitleGetCurrentHeap(), 0x8bc);
    gTitleScene->mStateFrames = 0;
    gTitleScene->mStateChanged = TRUE;
    gTitleScene->mPrevState = 0;
    gTitleScene->mState = 0;
    gTitleScene->mNextState = 8;
    gTitleScene->mNoInputFrames = 0;
    gTitleScene->mBlendDone = GetTitleBlendDone() != 0;
    gTitleScene->mSelectedIndex = 0;
    gTitleScene->mStartedOnSelected = FALSE;
    gTitleScene->mPreferEntry4 = TRUE;
    gTitleScene->mSelectedOffset = 0;
    gTitleScene->mBlendFrames = GetTitleBlendDone() != 0 ? 0x6b : 0;
    AdvanceTitleBlend();
    InitTitleStateHandlers();
    ResetOamLists(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
    LoadNclrData(&gTitleScene->mTitleTrueMBOrMBNclr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? gTitleTrueMBNclrName : gTitleMBNclrName));
    LoadNclrData(&gTitleScene->mTitleSBNclr, FindSceneFileWrapper(gTitleSBNclrName));
    LoadNcgrData(&gTitleScene->mTitleTrueMBOrMBNcgr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? gTitleTrueMBNcgrName : gTitleMBNcgrName));
    LoadNcgrData(&gTitleScene->mTitleSBNcgr, FindSceneFileWrapper(gTitleSBNcgrName));
    LoadNscrData(&gTitleScene->mTitleTrueM1OrM1Nscr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? gTitleTrueM1NscrName : gTitleM1NscrName));
    LoadNscrData(&gTitleScene->mTitleTrueM2OrM2Nscr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? gTitleTrueM2NscrName : gTitleM2NscrName));
    LoadNscrData(&gTitleScene->mTitleSBgNscr, FindSceneFileWrapper(gTitleSBgNscrName));
    LoadNclrData(&gTitleScene->mTitleSONclr, FindSceneFileWrapper(gTitleSONclrName));
    LoadNcgrData2(&gTitleScene->mTitleSNceNcgr, FindSceneFileWrapper(gTitleSNceNcgrName));
    LoadNcerData(&gTitleScene->mTitleSNceNcer, FindSceneFileWrapper(gTitleSNceNcerName));
    gTitleScene->mTitleSBncl = FindSceneFileWrapper(gTitleSBnclName);
    gTitleScene->mTitleSBnbl = FindSceneFileWrapper(gTitleSBnblName);
    gTitleScene->mTitleSBnll = FindSceneFileWrapper(gTitleSBnllName);
    displaySettings = CreateDisplaySettings(TitleGetCurrentHeap(), data_02156840);
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
                                       GetBmgEntry(FindSceneFileWrapper(gTitleBmgName), 1), gTitleScene->mTitleSBncl,
                                       gTitleScene->mTitleTable);
    PrintLabelLayoutTextNoFixedAdvance(1, 1, gTitleScene->mTitleSBnll,
                                       GetBmgEntry(FindSceneFileWrapper(gTitleBmgName2), 0), gTitleScene->mTitleSBncl,
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
