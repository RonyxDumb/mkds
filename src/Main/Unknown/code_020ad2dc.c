#include "Main/Unknown/code_020ad2dc.h"
#include "registers.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02090354.h"

#include "Main/Unknown/code_020ad32c.h"
#include "Main/Unknown/code_020ad344.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_02090000.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_02125de0.h"
#include "code_02148950.h"
#include "Main/Unknown/code_020acaa4.h"
#include "Main/Unknown/code_020ad268.h"
#include "Main/Unknown/code_020ad820.h"
#include "Main/Unknown/code_020ad870.h"
#include "Main/Unknown/code_020ad8a4.h"
#include "Main/Unknown/code_020ad8e0.h"
#include "Main/Unknown/code_020ad9fc.h"
#include "Main/Unknown/code_020ada10.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0214a390.h"
#include "code_0214b338.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_02044618.h"

void *title_proc_getCurrentHeap(void) {
    return proc_getHeap(proc_getCurrent());
}

u32 title_struct217B488_getTitleMenuSkipIntro(void) {
    return (gStruct217B488->mTitleBlendDone);
}

void title_dc_setMainBg1Config(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7, u32 cntVal8,
                   u32 cntVal2, u32 cntVal13) {
    dc_setBg1Config(displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void title_dc_setMainBg2Config(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8,
                   u32 cntVal2) {
    dc_setBg2Config(displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, e, cntVal8, cntVal2);
}

void title_dc_setMainBg3Config(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8,
                   u32 cntVal2) {
    dc_setBg3Config(displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, e, cntVal8, cntVal2);
}

void title_dc_setSubBg3Config(Unk02180774 *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e, u32 cntVal8,
                   u32 cntVal2) {
    dc_setBg3Config(displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, e, cntVal8, cntVal2);
}

void title_GX_SetOBJVRamModeChar(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | bits;
}

void title_GXS_SetOBJVRamModeChar(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | bits;
}

void title_G2S_SetBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, plane1, plane2, ev1, ev2);
}

u32 title_GX_SetVisibleWnd(u32 bits) {
    u32 dispcntValue = (reg_GX_DISPCNT & ~0xe000u) | (bits << 13);
    reg_GX_DISPCNT = dispcntValue;
    return dispcntValue;
}

u32 title_GXS_SetVisibleWnd(u32 bits) {
    u32 dispcntValue = (reg_GXS_DB_DISPCNT & ~0xe000u) | (bits << 13);
    reg_GXS_DB_DISPCNT = dispcntValue;
    return dispcntValue;
}

void title_struct217B488_setField4(u32 value) {
    gStruct217B488->field4 = value;
}

void title_struct217B488_setSinglePlayerMenuTarget(u32 value) {
    gStruct217B488->field8 = value;
}

void title_struct217B488_setField10(u32 value) {
    gStruct217B488->field10 = value;
}

void title_struct217B488_setField14(u32 value) {
    gStruct217B488->field14 = value;
}

#pragma thumb on

void title_init(void) {
    s32 useTrueFiles;
    s32 objSizeLeft;
    void *displaySettings;
    Unk02125de0Arg config;

    useTrueFiles = unlock_hasUnlockedTrueTitleScreen();
    sTitleSceneState = heap_alloc(title_proc_getCurrentHeap(), 0x8bc);
    sTitleSceneState->mStateFrames = 0;
    sTitleSceneState->mStateChanged = TRUE;
    sTitleSceneState->mPrevState = 0;
    sTitleSceneState->mState = 0;
    sTitleSceneState->mNextState = 8;
    sTitleSceneState->mNoInputFrames = 0;
    sTitleSceneState->mBlendDone = title_struct217B488_getTitleMenuSkipIntro() != 0;
    sTitleSceneState->mSelectedIndex = 0;
    sTitleSceneState->mSelectedPressed = FALSE;
    sTitleSceneState->mPreferEntry4 = TRUE;
    sTitleSceneState->mSelectedOffset = 0;
    sTitleSceneState->mBlendFrames = title_struct217B488_getTitleMenuSkipIntro() != 0 ? 0x6b : 0;
    title_updateIntro();
    title_setupStates();
    oam_clearResetBuffers(&sTitleSceneState->mMainOam, &sTitleSceneState->mSubOam);
    g2du_unpackPaletteData(&sTitleSceneState->mTitleTrueMBOrMBNclr,
                 m2d_getSceneArcFile(useTrueFiles != 0 ? aTitle_true_m_b : aTitle_m_b_nclr));
    g2du_unpackPaletteData(&sTitleSceneState->mTitleSBNclr, m2d_getSceneArcFile(aTitle_s_b_nclr));
    g2du_unpackCharacterDataBG(&sTitleSceneState->mTitleTrueMBOrMBNcgr,
                 m2d_getSceneArcFile(useTrueFiles != 0 ? aTitle_true_m_0 : aTitle_m_b_ncgr));
    g2du_unpackCharacterDataBG(&sTitleSceneState->mTitleSBNcgr, m2d_getSceneArcFile(aTitle_s_b_ncgr));
    g2du_unpackScreenData(&sTitleSceneState->mTitleTrueM1OrM1Nscr,
                 m2d_getSceneArcFile(useTrueFiles != 0 ? aTitle_true_m1_ : aTitle_m1_eu_ns));
    g2du_unpackScreenData(&sTitleSceneState->mTitleTrueM2OrM2Nscr,
                 m2d_getSceneArcFile(useTrueFiles != 0 ? aTitle_true_m2_ : aTitle_m2_nscr));
    g2du_unpackScreenData(&sTitleSceneState->mTitleSBgNscr, m2d_getSceneArcFile(aTitle_s_bg_nsc));
    g2du_unpackPaletteData(&sTitleSceneState->mTitleSONclr, m2d_getSceneArcFile(aTitle_s_o_nclr));
    g2du_unpackCharacterData(&sTitleSceneState->mTitleSNceNcgr, m2d_getSceneArcFile(aTitle_s_nce_nc));
    g2du_unpackCellBankData(&sTitleSceneState->mTitleSNceNcer, m2d_getSceneArcFile(aTitle_s_nce__1));
    sTitleSceneState->mTitleSBncl = m2d_getSceneArcFile(aTitle_s_bncl);
    sTitleSceneState->mTitleSBnbl = m2d_getSceneArcFile(aTitle_s_bnbl);
    sTitleSceneState->mTitleSBnll = m2d_getSceneArcFile(aTitle_s_bnll);
    displaySettings = dc_createDisplayConfig(title_proc_getCurrentHeap(), sTitleSceneDisplayConfigBase);
    title_dc_setMainBg1Config(displaySettings, 0, 0, 0, 0, 2, 0, 0);
    title_dc_setMainBg2Config(displaySettings, 2, 0, 0, 1, 14, 4);
    title_dc_setMainBg3Config(displaySettings, 3, 0, 0, 1, 15, 4);
    title_dc_setSubBg3Config(displaySettings, 3, 0, 0, 0, 1, 6);
    dc_setDisplayConfig(displaySettings);
    jn_ui_initLayout(title_proc_getCurrentHeap(), sTitleSceneState->mTitleSBncl, sTitleSceneState->mTitleSBnll, &sTitleSceneState->mTitleTable);
    jn_ui_setCellIsTranslucent(0, 1, sTitleSceneState->mTitleSNceNcer, sTitleSceneState->mTitleSBncl);
    jn_ui_setCellIsTranslucent(1, 1, sTitleSceneState->mTitleSNceNcer, sTitleSceneState->mTitleSBncl);
    jn_ui_setCellIsTranslucent(2, 1, sTitleSceneState->mTitleSNceNcer, sTitleSceneState->mTitleSBncl);
    jn_ui_setCellIsTranslucent(3, 1, sTitleSceneState->mTitleSNceNcer, sTitleSceneState->mTitleSBncl);
    jn_ui_setCellIsTranslucent(4, 1, sTitleSceneState->mTitleSNceNcer, sTitleSceneState->mTitleSBncl);
    objSizeLeft = GX_GetSizeOfSubOBJ();
    objSizeLeft -=
        jn_ui_initLabel(title_proc_getCurrentHeap(), 0, sTitleSceneState->mTitleSBnll, 0x55, 0xd, 0xd, sTitleSceneState->mTitleSNceNcer,
                        sTitleSceneState->mTitleSBncl, sTitleSceneState->mTitleTable, objSizeLeft);
    jn_ui_initLabel(title_proc_getCurrentHeap(), 1, sTitleSceneState->mTitleSBnll, 0x55, 0xd, 0xe, sTitleSceneState->mTitleSNceNcer,
                    sTitleSceneState->mTitleSBncl, sTitleSceneState->mTitleTable, objSizeLeft);
    jn_ui_212426C(1, 0, sTitleSceneState->mTitleSBnll, jn_msg_getMessage(m2d_getSceneArcFile(aTitle_bmg), 1),
                  sTitleSceneState->mTitleSBncl, sTitleSceneState->mTitleTable);
    jn_ui_212426C(1, 1, sTitleSceneState->mTitleSBnll, jn_msg_getMessage(m2d_getSceneArcFile(aTitle_bmg_1), 0),
                  sTitleSceneState->mTitleSBncl, sTitleSceneState->mTitleTable);
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(sTitleSceneState->mTitleTrueMBOrMBNclr->mData, 0x4000, sTitleSceneState->mTitleTrueMBOrMBNclr->mDataSize);
    GX_LoadBGExtPltt(sTitleSceneState->mTitleTrueMBOrMBNclr->mData, 0x6000, sTitleSceneState->mTitleTrueMBOrMBNclr->mDataSize);
    GX_EndLoadBGExtPltt();
    GX_LoadBG2Char(sTitleSceneState->mTitleTrueMBOrMBNcgr->mData, 0, sTitleSceneState->mTitleTrueMBOrMBNcgr->mDataSize);
    GX_LoadBG2Scr(sTitleSceneState->mTitleTrueM1OrM1Nscr->mData, 0, 0x800);
    GX_LoadBG3Scr(sTitleSceneState->mTitleTrueM2OrM2Nscr->mData, 0, 0x800);
    GXS_LoadBGPltt(sTitleSceneState->mTitleSBNclr->mData, 0, sTitleSceneState->mTitleSBNclr->mDataSize);
    GXS_LoadBG3Char(sTitleSceneState->mTitleSBNcgr->mData, 0, sTitleSceneState->mTitleSBNcgr->mDataSize);
    GXS_LoadBG3Scr(sTitleSceneState->mTitleSBgNscr->mData, 0, 0x800);
    GXS_LoadOBJPltt(sTitleSceneState->mTitleSONclr->mData, 0, sTitleSceneState->mTitleSONclr->mDataSize);
    GXS_LoadOBJ(sTitleSceneState->mTitleSNceNcgr->mData, 0, sTitleSceneState->mTitleSNceNcgr->mDataSize);
    title_GX_SetOBJVRamModeChar(0x10);
    title_GXS_SetOBJVRamModeChar(0x10);
    title_G2_SetBlendAlpha(4, 8, 0, 0x10);
    title_G2S_SetBlendAlpha(0, 0x3f, 6, 10);
    title_GX_SetVisibleWnd(0);
    title_GXS_SetVisibleWnd(0);
    config.field0 = 0;
    config.field4 = NULL;
    config.field8 = 0;
    config.fieldC = 0;
    config.field10 = 0;
    config.field14 = 0;
    config.field18 = m2d_getFont(0);
    config.field1C = 0;
    config.field20 = 0;
    config.field24 = 0;
    gmenu_unpackData();
    gmenu_init(title_proc_getCurrentHeap(), &config);
    sTitleSceneState->mCharacterKartPicks = func_0203bedc(title_proc_getCurrentHeap());
    title_sysdat_setOverlayRelatedNum(0);
    sysdat_setIsMBChild(0);
    ClearShuffledIndices();
    title_struct217B488_setField4(1);
    title_struct217B488_setSinglePlayerMenuTarget(0);
    title_struct217B488_setField10(0);
    title_struct217B488_setField14(0);
    rconf_reset();
}

#pragma thumb off

#pragma thumb on

void title_finalize(void) {
    gmenu_finish();
    sTitleSceneState = NULL;
}

#pragma thumb off

void title_G2_SetBlendAlpha(u32 plane1, u32 plane2, u32 ev1, u32 ev2) {
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, plane1, plane2, ev1, ev2);
}

// Set when the title blend has run to its end; title_init then starts its blend already finished.
void title_struct217B488_setTitleMenuSkipIntro(u32 blendDone) {
    gStruct217B488->mTitleBlendDone = blendDone;
}
