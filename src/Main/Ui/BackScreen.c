#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_02126700.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02016468.h"
#include "registers.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_021274e0.h"
#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/code_0212802c.h"
#include "Main/Unknown/code_02128058.h"
#include "Main/Unknown/code_021287c0.h"
#include "Main/Unknown/code_021287cc.h"
#include "01/OptionSelectMenu.h"

#pragma thumb on

void gmenu_init(void *heap, Unk02125de0Arg *config) {
    TxtSystemArgs txtConfig;

    gmenu_sGlobalMenuContext = heap_alloc(heap, 0x814);
    gmenu_sGlobalMenuContext->mSubCharOffset = 0x5800;
    gmenu_sGlobalMenuContext->mUseTxtSystem = FALSE;
    gmenu_sGlobalMenuContext->mUseSelectChoises = FALSE;
    gmenu_sGlobalMenuContext->field8 = FALSE;
    if (config->field0 != FALSE) {
        txtConfig.mFont = (u32) config->field4;
        txtConfig.mUseCanvas1 = config->field8;
        txtConfig.mUseCanvas2 = config->fieldC;
        txtConfig.mUseCanvas3 = config->field10;
        txtConfig.mSubCharOffset = gmenu_sGlobalMenuContext->mSubCharOffset;
        gmenu_sGlobalMenuContext->mUseTxtSystem = TRUE;
        gmenu_sGlobalMenuContext->mSubCharOffset = gmenu_initUnknown(heap, &txtConfig);
    }
    if (config->field14 != FALSE) {
        gmenu_sGlobalMenuContext->mUseSelectChoises = TRUE;
        gmenu_sGlobalMenuContext->mSubCharOffset = gmenu_initSelectChoises(heap, config->field18, gmenu_sGlobalMenuContext->mSubCharOffset);
    }
    if (config->field1C != FALSE) {
        gmenu_sGlobalMenuContext->field8 = TRUE;
        gmenu_sGlobalMenuContext->mSubCharOffset = gmenu_initSelectReturn(heap, gmenu_sGlobalMenuContext->mSubCharOffset);
    }
    if (config->field20 != FALSE) {
        gmenu_sGlobalMenuContext->mBackScreenKind = config->field24;
        gmenu_setupHWForBackground();
        gmenu_sGlobalMenuContext->mSubCharOffset = gmenu_loadBackground(gmenu_sGlobalMenuContext->mSubCharOffset);
    }
}

#pragma thumb off

#pragma thumb on

void gmenu_finish(void) {
    if (gmenu_sGlobalMenuContext->mUseTxtSystem != FALSE) {
        gmenu_finishUnknown();
    }
    if (gmenu_sGlobalMenuContext->mUseSelectChoises != FALSE) {
        gmenu_finishSelectChoises();
    }
    if (gmenu_sGlobalMenuContext->field8 != FALSE) {
        gmenu_finishSelectReturn();
    }
    *&gmenu_sGlobalMenuContext = NULL;
}

#pragma thumb off

#pragma thumb off
// placeholder: the file names as file-scope arrays; this declaration order gives the original's order of the
// names and tables in .data.
static char aBack_screen_m_bg_00_nscr[] = "back_screen_m_bg_00.nscr";
static char aBack_screen_s_b_00_nclr[] = "back_screen_s_b_00.nclr";
static char aBack_screen_s_b_00_ncgr[] = "back_screen_s_b_00.ncgr";
static char aBack_screen_m_b_00_ncgr[] = "back_screen_m_b_00.ncgr";
static char aBack_screen_s_bg_00_nscr[] = "back_screen_s_bg_00.nscr";
const char *gBackScreenSNclrNames[1] = {aBack_screen_s_b_00_nclr};
static char aBack_screen_m_b_01_ncgr[] = "back_screen_m_b_01.ncgr";
static char aBack_screen_m_b_01_nclr[] = "back_screen_m_b_01.nclr";
const char *gBackScreenMNcgrNames[2] = {aBack_screen_m_b_00_ncgr, aBack_screen_m_b_01_ncgr};
static char aBack_screen_m_b_00_nclr[] = "back_screen_m_b_00.nclr";
const char *gBackScreenMNclrNames[2] = {aBack_screen_m_b_00_nclr, aBack_screen_m_b_01_nclr};
const char *gBackScreenSNcgrNames[1] = {aBack_screen_s_b_00_ncgr};
static char aBack_screen_m_bg_01_nscr[] = "back_screen_m_bg_01.nscr";
const char *gBackScreenMNscrNames[2] = {aBack_screen_m_bg_00_nscr, aBack_screen_m_bg_01_nscr};
const char *gBackScreenSNscrNames[1] = {aBack_screen_s_bg_00_nscr};

#pragma thumb on

void gmenu_unpackData(void) {
    LoadedPartPointer loadedPartPointer;

    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
        g2du_unpackCharacterDataBG(&loadedPartPointer.mNcgr, arc_getSceneArcFile("txt_system_b_00.ncgr"));
        g2du_unpackScreenData(&loadedPartPointer.mNscr, arc_getSceneArcFile("txt_system_bg_00.nscr"));
        g2du_unpackPaletteData(&loadedPartPointer.mNclr, arc_getSceneArcFile("txt_system_b_00.nclr"));
    } else {
        g2du_unpackCharacterDataBG(&loadedPartPointer.mNcgr, arc_get2dArcFile("txt_system_b_00.ncgr"));
        g2du_unpackCharacterDataBG(&loadedPartPointer.mNcgr, arc_get2dArcFile("txt_system_b_01.ncgr"));
        g2du_unpackScreenData(&loadedPartPointer.mNscr, arc_get2dArcFile("txt_system_bg_00.nscr"));
        g2du_unpackScreenData(&loadedPartPointer.mNscr, arc_get2dArcFile("txt_system_bg_00_2.nscr"));
        g2du_unpackScreenData(&loadedPartPointer.mNscr, arc_get2dArcFile("txt_system_bg_01.nscr"));
        g2du_unpackScreenData(&loadedPartPointer.mNscr, arc_get2dArcFile("txt_system_bg_01_2.nscr"));
        g2du_unpackScreenData(&loadedPartPointer.mNscr, arc_get2dArcFile("txt_system_bg_02.nscr"));
        g2du_unpackScreenData(&loadedPartPointer.mNscr, arc_get2dArcFile("txt_system_bg_02_2.nscr"));
        g2du_unpackScreenData(&loadedPartPointer.mNscr, arc_get2dArcFile("txt_system_bg_02_3.nscr"));
        g2du_unpackPaletteData(&loadedPartPointer.mNclr, arc_get2dArcFile("txt_system_b_00.nclr"));
        g2du_unpackCharacterDataBG(&loadedPartPointer.mNcgr, arc_get2dArcFile("select_choises_s_b.ncgr"));
        g2du_unpackScreenData(&loadedPartPointer.mNscr, arc_get2dArcFile("select_choises_s_bg.nscr"));
        g2du_unpackPaletteData(&loadedPartPointer.mNclr, arc_get2dArcFile("select_choises_s_b.nclr"));
        g2du_unpackCharacterDataBG(&loadedPartPointer.mNcgr, arc_get2dArcFile("select_return_s_b_00.ncgr"));
        g2du_unpackScreenData(&loadedPartPointer.mNscr, arc_get2dArcFile("select_return_s_bg_00.nscr"));
        g2du_unpackPaletteData(&loadedPartPointer.mNclr, arc_get2dArcFile("select_return_s_b_00.nclr"));
    }
}

void gmenu_setupHWForBackground(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    mainDisplayBits = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((mainDisplayBits | 8) << 8);
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 3;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & 0x43) | 0x1d18;
    subDisplayBits = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((subDisplayBits | 2) << 8);
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xd00;
}

s32 gmenu_loadBackground(s32 subCharOffset) {
    s32 i;
    s32 nclrSOffset;
    s32 nclrSSize;
    Ncgr *ncgrM;
    Nscr *nscrM;
    Nclr *nclrM;
    Ncgr *ncgrS;
    Nscr *nscrS;
    Nclr *nclrS;
    s32 kind;
    u8 indexM;
    u8 indexS;
    s32 j;
    s32 nclrMOffset;
    s32 nclrMSize;

    kind = gmenu_sGlobalMenuContext->mBackScreenKind;
    indexM = gBackScreenKindMIndices[kind * 2];
    indexS = gBackScreenKindSIndices[kind * 2];
    nclrMOffset = gBackScreenMNclrStarts[indexM] << 5;
    nclrMSize = (0xe - gBackScreenMNclrStarts[indexM]) << 5;
    nclrSOffset = gBackScreenSNclrStarts[indexS] << 5;
    nclrSSize = (0xc - gBackScreenSNclrStarts[indexS]) << 5;
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2) {
        g2du_getCharacterDataBG(&ncgrM, arc_getSceneArcFile("common/select_race_rule_s_b.NCGR"));
        g2du_unpackScreenData(&nscrM, arc_getSceneArcFile("common/select_race_rule_download_bg_m.NSCR"));
        g2du_getPaletteData(&nclrM, arc_getSceneArcFile("common/select_race_rule_s_b.NCLR"));
        ncgrS = ncgrM;
        g2du_unpackScreenData(&nscrS, arc_getSceneArcFile("common/select_race_rule_download_bg_s.NSCR"));
        nclrS = nclrM;
    } else {
        if (data_0215d038[indexM] != 0) {
            g2du_unpackCharacterDataBG(&ncgrM, arc_get2dArcFile(gBackScreenMNcgrNames[indexM]));
            g2du_unpackScreenData(&nscrM, arc_get2dArcFile(gBackScreenMNscrNames[indexM]));
            g2du_unpackPaletteData(&nclrM, arc_get2dArcFile(gBackScreenMNclrNames[indexM]));
        } else {
            g2du_unpackCharacterDataBG(&ncgrM, arc_getSceneArcFile(gBackScreenMNcgrNames[indexM]));
            g2du_unpackScreenData(&nscrM, arc_getSceneArcFile(gBackScreenMNscrNames[indexM]));
            g2du_unpackPaletteData(&nclrM, arc_getSceneArcFile(gBackScreenMNclrNames[indexM]));
        }
        if (data_0215d038[indexS] != 0) {
            g2du_unpackCharacterDataBG(&ncgrS, arc_get2dArcFile(gBackScreenSNcgrNames[indexS]));
            g2du_unpackScreenData(&nscrS, arc_get2dArcFile(gBackScreenSNscrNames[indexS]));
            g2du_unpackPaletteData(&nclrS, arc_get2dArcFile(gBackScreenSNclrNames[indexS]));
        } else {
            g2du_unpackCharacterDataBG(&ncgrS, arc_getSceneArcFile(gBackScreenSNcgrNames[indexS]));
            g2du_unpackScreenData(&nscrS, arc_getSceneArcFile(gBackScreenSNscrNames[indexS]));
            g2du_unpackPaletteData(&nclrS, arc_getSceneArcFile(gBackScreenSNclrNames[indexS]));
        }
    }
    NNS_GfdRegisterNewVramTransferTask(7, 0, ncgrM->mData, ncgrM->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xb, 0, nscrM->mData, nscrM->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0xf, nclrMOffset, OFFSET_PTR(void, nclrM->mData, nclrMOffset), nclrMSize);
    subCharOffset -= ncgrS->mDataSize;
    NNS_GfdRegisterNewVramTransferTask(0x15, subCharOffset, ncgrS->mData, ncgrS->mDataSize);
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 0x20; j++) {
            *(gmenu_sGlobalMenuContext->mBackScreenSNscrCopy + i * 0x20 + j) =
                (subCharOffset >> 5) + *((u16 *) nscrS->mData + i * 0x20 + j);
        }
    }
    NNS_GfdRegisterNewVramTransferTask(0x19, 0, gmenu_sGlobalMenuContext->mBackScreenSNscrCopy, nscrS->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(0x1f, nclrSOffset, OFFSET_PTR(void, nclrS->mData, nclrSOffset), nclrSSize);
    return subCharOffset;
}

#pragma thumb off

#pragma thumb on

void gmenu_render(void) {
    if (gmenu_sGlobalMenuContext->mUseTxtSystem != FALSE) {
        gmenu_2126834();
    }
    if (gmenu_sGlobalMenuContext->mUseSelectChoises != FALSE) {
        gmenu_21279A0();
    }
    if (gmenu_sGlobalMenuContext->field8 != FALSE) {
        gmenu_2128458();
    }
}

void gmenu_vblank(void) {
    if (gmenu_sGlobalMenuContext->mUseTxtSystem != FALSE) {
        WriteTxtSystemRegisters();
    }
    if (gmenu_sGlobalMenuContext->mUseSelectChoises != FALSE) {
        WriteSelectChoisesRegisters();
    }
    if (gmenu_sGlobalMenuContext->field8 != FALSE) {
        gmenu_updateSelectReturn();
    }
}

#pragma thumb off
