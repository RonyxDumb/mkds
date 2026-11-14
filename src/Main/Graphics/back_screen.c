#include "Main/Graphics/back_screen.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/data_0215d000.h"
#include "Main/Menu/data_0217d000.h"
#include "player.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "code_0212d214.h"
#include "Main/Sound/sound_seq.h"
#include "gfd_VramTransferManager.h"
#include "registers.h"
#include "Main/Graphics/scene_text_init.h"

#pragma thumb on

const u8 gBackScreenKindIndices[4] = {0, 0, 1, 0};
const u8 gBackScreenMNclrStarts[4] = {0xc, 0xc, 0, 0};
const u8 gBackScreenInLoadedArchives[4] = {1, 0, 0, 0};
const u8 gBackScreenSNclrStarts[4] = {0xa, 0, 0, 0};
const char *gBackScreenSNclrNames[1] = {gBackScreenSNclr00Name};
const char *gBackScreenSNcgrNames[1] = {gBackScreenSNcgr00Name};
const char *gBackScreenSNscrNames[1] = {gBackScreenSNscrBg00Name};
const char *gBackScreenMNscrNames[2] = {gBackScreenMNscrBg00Name, gBackScreenMNscrBg01Name};
const char *gBackScreenMNcgrNames[2] = {gBackScreenMNcgr00Name, gBackScreenMNcgr01Name};
const char *gBackScreenMNclrNames[2] = {gBackScreenMNclr00Name, gBackScreenMNclr01Name};
char gBackScreenMNscrBg00Name[] = "back_screen_m_bg_00.nscr";
char gBackScreenSNcgr00Name[] = "back_screen_s_b_00.ncgr";
char gBackScreenSNclr00Name[] = "back_screen_s_b_00.nclr";
char gBackScreenMNcgr00Name[] = "back_screen_m_b_00.ncgr";
char gBackScreenMNcgr01Name[] = "back_screen_m_b_01.ncgr";
char gBackScreenMNscrBg01Name[] = "back_screen_m_bg_01.nscr";
char gBackScreenMNclr00Name[] = "back_screen_m_b_00.nclr";
char gBackScreenSNscrBg00Name[] = "back_screen_s_bg_00.nscr";
char gBackScreenMNclr01Name[] = "back_screen_m_b_01.nclr";

void LoadTxtSystemAndSelectChoisesAndSelectReturnData(void) {
    LoadedPartPointer loadedPartPointer;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
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

void InitBackScreenDisplay(void) {
    u32 mainDisplayBits;
    u32 subDisplayBits;

    mainDisplayBits = (reg_GX_DISPCNT & REG_GX_DISPCNT_DISPLAY_MASK) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~REG_GX_DISPCNT_DISPLAY_MASK) | ((mainDisplayBits | 8) << 8);
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~REG_G2_BG3CNT_PRIORITY_MASK) | 3;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & (REG_G2_BG3CNT_PRIORITY_MASK | REG_G2_BG3CNT_MOSAIC_MASK)) | 0x1d18;
    subDisplayBits = (reg_GXS_DB_DISPCNT & REG_GXS_DB_DISPCNT_DISPLAY_MASK) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~REG_GXS_DB_DISPCNT_DISPLAY_MASK) | ((subDisplayBits | 2) << 8);
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~REG_G2S_DB_BG1CNT_PRIORITY_MASK) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & (REG_G2S_DB_BG1CNT_PRIORITY_MASK | REG_G2S_DB_BG1CNT_MOSAIC_MASK)) | 0xd00;
}

s32 LoadBackScreen(s32 subCharOffset) {
    s32 rowIndex;
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
    s32 columnIndex;
    s32 nclrMOffset;
    s32 nclrMSize;

    kind = gSceneText->mBackScreenKind;
    indexM = gBackScreenKindIndices[kind * 2];
    indexS = (gBackScreenKindIndices + 1)[kind * 2];
    nclrMOffset = gBackScreenMNclrStarts[indexM] << 5;
    nclrMSize = (0xe - gBackScreenMNclrStarts[indexM]) << 5;
    nclrSOffset = gBackScreenSNclrStarts[indexS] << 5;
    nclrSSize = (0xc - gBackScreenSNclrStarts[indexS]) << 5;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        LocateNcgr(&ncgrM, FindSceneFile("common/select_race_rule_s_b.NCGR"));
        LoadNscrData(&nscrM, FindSceneFile("common/select_race_rule_download_bg_m.NSCR"));
        LocateNclr(&nclrM, FindSceneFile("common/select_race_rule_s_b.NCLR"));
        ncgrS = ncgrM;
        LoadNscrData(&nscrS, FindSceneFile("common/select_race_rule_download_bg_s.NSCR"));
        nclrS = nclrM;
    } else {
        if (gBackScreenInLoadedArchives[indexM] != 0) {
            LoadNcgrData(&ncgrM, FindFileInLoadedArchives(gBackScreenMNcgrNames[indexM]));
            LoadNscrData(&nscrM, FindFileInLoadedArchives(gBackScreenMNscrNames[indexM]));
            LoadNclrData(&nclrM, FindFileInLoadedArchives(gBackScreenMNclrNames[indexM]));
        } else {
            LoadNcgrData(&ncgrM, FindSceneFile(gBackScreenMNcgrNames[indexM]));
            LoadNscrData(&nscrM, FindSceneFile(gBackScreenMNscrNames[indexM]));
            LoadNclrData(&nclrM, FindSceneFile(gBackScreenMNclrNames[indexM]));
        }
        if (gBackScreenInLoadedArchives[indexS] != 0) {
            LoadNcgrData(&ncgrS, FindFileInLoadedArchives(gBackScreenSNcgrNames[indexS]));
            LoadNscrData(&nscrS, FindFileInLoadedArchives(gBackScreenSNscrNames[indexS]));
            LoadNclrData(&nclrS, FindFileInLoadedArchives(gBackScreenSNclrNames[indexS]));
        } else {
            LoadNcgrData(&ncgrS, FindSceneFile(gBackScreenSNcgrNames[indexS]));
            LoadNscrData(&nscrS, FindSceneFile(gBackScreenSNscrNames[indexS]));
            LoadNclrData(&nclrS, FindSceneFile(gBackScreenSNclrNames[indexS]));
        }
    }
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG3_TILES, 0, ncgrM->mData, ncgrM->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG3_MAP, 0, nscrM->mData, nscrM->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_A_BG_PALETTE, nclrMOffset,
                                       OFFSET_PTR(void, nclrM->mData, nclrMOffset), nclrMSize);
    subCharOffset -= ncgrS->mDataSize;
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG1_TILES, subCharOffset, ncgrS->mData, ncgrS->mDataSize);
    for (rowIndex = 0; rowIndex < 0x20; rowIndex++) {
        for (columnIndex = 0; columnIndex < 0x20; columnIndex++) {
            *(gSceneText->mBackScreenSNscrCopy + rowIndex * 0x20 + columnIndex) =
                (subCharOffset >> 5) + *((u16 *) nscrS->mData + rowIndex * 0x20 + columnIndex);
        }
    }
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG1_MAP, 0, gSceneText->mBackScreenSNscrCopy,
                                       nscrS->mDataSize);
    NNS_GfdRegisterNewVramTransferTask(VRAM_TARGET_ENGINE_B_BG_PALETTE, nclrSOffset,
                                       OFFSET_PTR(void, nclrS->mData, nclrSOffset), nclrSSize);
    return subCharOffset;
}

#pragma thumb off
