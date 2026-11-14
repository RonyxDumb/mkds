#include "Main/Unknown/code_021258f0.h"
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
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_021274e0.h"
#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/code_0212802c.h"
#include "Main/Unknown/code_02128058.h"
#include "Main/Unknown/code_021287c0.h"
#include "Main/Unknown/code_021287cc.h"
#include "01/code_02198854.h"

#pragma thumb on

void func_02125de0(void *heap, Unk02125de0Arg *config) {
    TxtSystemArgs txtConfig;

    data_0217d3ec = HeapAlloc(heap, 0x814);
    data_0217d3ec->mSubCharOffset = 0x5800;
    data_0217d3ec->mUseTxtSystem = FALSE;
    data_0217d3ec->mUseSelectChoises = FALSE;
    data_0217d3ec->mUnk_08 = FALSE;
    if (config->mUnk_00 != FALSE) {
        txtConfig.mFont = (u32) config->mUnk_04;
        txtConfig.mUseCanvas1 = config->mUnk_08;
        txtConfig.mUseCanvas2 = config->mUnk_0c;
        txtConfig.mUseCanvas3 = config->mUnk_10;
        txtConfig.mSubCharOffset = data_0217d3ec->mSubCharOffset;
        data_0217d3ec->mUseTxtSystem = TRUE;
        data_0217d3ec->mSubCharOffset = InitTxtSystem(heap, &txtConfig);
    }
    if (config->mUnk_14 != FALSE) {
        data_0217d3ec->mUseSelectChoises = TRUE;
        data_0217d3ec->mSubCharOffset = InitSelectChoises(heap, config->mUnk_18, data_0217d3ec->mSubCharOffset);
    }
    if (config->mUnk_1c != FALSE) {
        data_0217d3ec->mUnk_08 = TRUE;
        data_0217d3ec->mSubCharOffset = InitSelectReturn(heap, data_0217d3ec->mSubCharOffset);
    }
    if (config->mUnk_20 != FALSE) {
        data_0217d3ec->mBackScreenKind = config->mUnk_24;
        func_02125ba4();
        data_0217d3ec->mSubCharOffset = LoadBackScreen(data_0217d3ec->mSubCharOffset);
    }
}

#pragma thumb off

#pragma thumb on

void func_02125da0(void) {
    if (data_0217d3ec->mUseTxtSystem != FALSE) {
        ClearTxtSystemPointer();
    }
    if (data_0217d3ec->mUseSelectChoises != FALSE) {
        ClearSelectChoisesPointer();
    }
    if (data_0217d3ec->mUnk_08 != FALSE) {
        ClearSelectReturnPointer();
    }
    *&data_0217d3ec = NULL;
}

#pragma thumb off

#pragma thumb off
// placeholder: the file names as file-scope arrays; this declaration order gives the original's order of the
// names and tables in .data.
static char sBackScreenMBg00Nscr[] = "back_screen_m_bg_00.nscr";
static char sBackScreenSB00Nclr[] = "back_screen_s_b_00.nclr";
static char sBackScreenSB00Ncgr[] = "back_screen_s_b_00.ncgr";
static char sBackScreenMB00Ncgr[] = "back_screen_m_b_00.ncgr";
static char sBackScreenSBg00Nscr[] = "back_screen_s_bg_00.nscr";
const char *gBackScreenSNclrNames[1] = {sBackScreenSB00Nclr};
static char sBackScreenMB01Ncgr[] = "back_screen_m_b_01.ncgr";
static char sBackScreenMB01Nclr[] = "back_screen_m_b_01.nclr";
const char *gBackScreenMNcgrNames[2] = {sBackScreenMB00Ncgr, sBackScreenMB01Ncgr};
static char sBackScreenMB00Nclr[] = "back_screen_m_b_00.nclr";
const char *gBackScreenMNclrNames[2] = {sBackScreenMB00Nclr, sBackScreenMB01Nclr};
const char *gBackScreenSNcgrNames[1] = {sBackScreenSB00Ncgr};
static char sBackScreenMBg01Nscr[] = "back_screen_m_bg_01.nscr";
const char *gBackScreenMNscrNames[2] = {sBackScreenMBg00Nscr, sBackScreenMBg01Nscr};
const char *gBackScreenSNscrNames[1] = {sBackScreenSBg00Nscr};

#pragma thumb on

void LoadTxtSystemAndSelectChoisesAndSelectReturnData(void) {
    LoadedPartPointer loadedPartPointer;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        LoadNcgrData(&loadedPartPointer.mNcgr, FindSceneFile("txt_system_b_00.ncgr"));
        LoadNscrData(&loadedPartPointer.mNscr, FindSceneFile("txt_system_bg_00.nscr"));
        LoadNclrData(&loadedPartPointer.mNclr, FindSceneFile("txt_system_b_00.nclr"));
    } else {
        LoadNcgrData(&loadedPartPointer.mNcgr, FindFileInLoadedArchives("txt_system_b_00.ncgr"));
        LoadNcgrData(&loadedPartPointer.mNcgr, FindFileInLoadedArchives("txt_system_b_01.ncgr"));
        LoadNscrData(&loadedPartPointer.mNscr, FindFileInLoadedArchives("txt_system_bg_00.nscr"));
        LoadNscrData(&loadedPartPointer.mNscr, FindFileInLoadedArchives("txt_system_bg_00_2.nscr"));
        LoadNscrData(&loadedPartPointer.mNscr, FindFileInLoadedArchives("txt_system_bg_01.nscr"));
        LoadNscrData(&loadedPartPointer.mNscr, FindFileInLoadedArchives("txt_system_bg_01_2.nscr"));
        LoadNscrData(&loadedPartPointer.mNscr, FindFileInLoadedArchives("txt_system_bg_02.nscr"));
        LoadNscrData(&loadedPartPointer.mNscr, FindFileInLoadedArchives("txt_system_bg_02_2.nscr"));
        LoadNscrData(&loadedPartPointer.mNscr, FindFileInLoadedArchives("txt_system_bg_02_3.nscr"));
        LoadNclrData(&loadedPartPointer.mNclr, FindFileInLoadedArchives("txt_system_b_00.nclr"));
        LoadNcgrData(&loadedPartPointer.mNcgr, FindFileInLoadedArchives("select_choises_s_b.ncgr"));
        LoadNscrData(&loadedPartPointer.mNscr, FindFileInLoadedArchives("select_choises_s_bg.nscr"));
        LoadNclrData(&loadedPartPointer.mNclr, FindFileInLoadedArchives("select_choises_s_b.nclr"));
        LoadNcgrData(&loadedPartPointer.mNcgr, FindFileInLoadedArchives("select_return_s_b_00.ncgr"));
        LoadNscrData(&loadedPartPointer.mNscr, FindFileInLoadedArchives("select_return_s_bg_00.nscr"));
        LoadNclrData(&loadedPartPointer.mNclr, FindFileInLoadedArchives("select_return_s_b_00.nclr"));
    }
}

void func_02125ba4(void) {
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

s32 LoadBackScreen(s32 subCharOffset) {
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

    kind = data_0217d3ec->mBackScreenKind;
    indexM = gBackScreenKindMIndices[kind * 2];
    indexS = gBackScreenKindSIndices[kind * 2];
    nclrMOffset = gBackScreenMNclrStarts[indexM] << 5;
    nclrMSize = (0xe - gBackScreenMNclrStarts[indexM]) << 5;
    nclrSOffset = gBackScreenSNclrStarts[indexS] << 5;
    nclrSSize = (0xc - gBackScreenSNclrStarts[indexS]) << 5;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        LocateNcgr(&ncgrM, FindSceneFile("common/select_race_rule_s_b.NCGR"));
        LoadNscrData(&nscrM, FindSceneFile("common/select_race_rule_download_bg_m.NSCR"));
        LocateNclr(&nclrM, FindSceneFile("common/select_race_rule_s_b.NCLR"));
        ncgrS = ncgrM;
        LoadNscrData(&nscrS, FindSceneFile("common/select_race_rule_download_bg_s.NSCR"));
        nclrS = nclrM;
    } else {
        if (data_0215d038[indexM] != 0) {
            LoadNcgrData(&ncgrM, FindFileInLoadedArchives(gBackScreenMNcgrNames[indexM]));
            LoadNscrData(&nscrM, FindFileInLoadedArchives(gBackScreenMNscrNames[indexM]));
            LoadNclrData(&nclrM, FindFileInLoadedArchives(gBackScreenMNclrNames[indexM]));
        } else {
            LoadNcgrData(&ncgrM, FindSceneFile(gBackScreenMNcgrNames[indexM]));
            LoadNscrData(&nscrM, FindSceneFile(gBackScreenMNscrNames[indexM]));
            LoadNclrData(&nclrM, FindSceneFile(gBackScreenMNclrNames[indexM]));
        }
        if (data_0215d038[indexS] != 0) {
            LoadNcgrData(&ncgrS, FindFileInLoadedArchives(gBackScreenSNcgrNames[indexS]));
            LoadNscrData(&nscrS, FindFileInLoadedArchives(gBackScreenSNscrNames[indexS]));
            LoadNclrData(&nclrS, FindFileInLoadedArchives(gBackScreenSNclrNames[indexS]));
        } else {
            LoadNcgrData(&ncgrS, FindSceneFile(gBackScreenSNcgrNames[indexS]));
            LoadNscrData(&nscrS, FindSceneFile(gBackScreenSNscrNames[indexS]));
            LoadNclrData(&nclrS, FindSceneFile(gBackScreenSNclrNames[indexS]));
        }
    }
    CallQueueAppend(7, 0, ncgrM->mData, ncgrM->mDataSize);
    CallQueueAppend(0xb, 0, nscrM->mData, nscrM->mDataSize);
    CallQueueAppend(0xf, nclrMOffset, OFFSET_PTR(void, nclrM->mData, nclrMOffset), nclrMSize);
    subCharOffset -= ncgrS->mDataSize;
    CallQueueAppend(0x15, subCharOffset, ncgrS->mData, ncgrS->mDataSize);
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 0x20; j++) {
            *(data_0217d3ec->mBackScreenSNscrCopy + i * 0x20 + j) =
                (subCharOffset >> 5) + *((u16 *) nscrS->mData + i * 0x20 + j);
        }
    }
    CallQueueAppend(0x19, 0, data_0217d3ec->mBackScreenSNscrCopy, nscrS->mDataSize);
    CallQueueAppend(0x1f, nclrSOffset, OFFSET_PTR(void, nclrS->mData, nclrSOffset), nclrSSize);
    return subCharOffset;
}

#pragma thumb off

#pragma thumb on

void func_02125928(void) {
    if (data_0217d3ec->mUseTxtSystem != FALSE) {
        AdvanceTxtSystem();
    }
    if (data_0217d3ec->mUseSelectChoises != FALSE) {
        AdvanceSelectChoises();
    }
    if (data_0217d3ec->mUnk_08 != FALSE) {
        AdvanceSelectReturn();
    }
}

void func_021258f0(void) {
    if (data_0217d3ec->mUseTxtSystem != FALSE) {
        WriteTxtSystemRegisters();
    }
    if (data_0217d3ec->mUseSelectChoises != FALSE) {
        WriteSelectChoisesRegisters();
    }
    if (data_0217d3ec->mUnk_08 != FALSE) {
        WriteSelectReturnRegisters();
    }
}

#pragma thumb off
