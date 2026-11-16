#include "Main/Graphics/back_screen.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/back_screen_keyboard_tables.h"
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
#include "Main/Sound/sound_seq.h"
#include "vram_transfer_queue.h"
#include "registers.h"
#include "Main/Graphics/scene_text_init.h"

#pragma thumb on

const u8 gBackScreenKindIndices[4] = {0, 0, 1, 0};
const u8 gBackScreenMNclrStarts[4] = {0xc, 0xc, 0, 0};
const u8 gBackScreenInLoadedArchives[4] = {1, 0, 0, 0};
const u8 gBackScreenSNclrStarts[4] = {0xa, 0, 0, 0};
const char *g_str_back_screen_s_b_00_nclr[1] = {gBackScreenSNclr00Name};
const char *g_str_back_screen_s_b_00_ncgr[1] = {gBackScreenSNcgr00Name};
const char *g_str_back_screen_s_bg_00_nscr[1] = {gBackScreenSNscrBg00Name};
const char *g_str_back_screen_m_b_00_01_nscr[2] = {gBackScreenMNscrBg00Name, gBackScreenMNscrBg01Name};
const char *g_str_back_screen_m_b_00_01_ncgr[2] = {gBackScreenMNcgr00Name, gBackScreenMNcgr01Name};
const char *g_str_back_screen_m_b_00_01_nclr[2] = {gBackScreenMNclr00Name, gBackScreenMNclr01Name};
char gBackScreenMNscrBg00Name[] = "back_screen_m_bg_00.nscr";
char gBackScreenSNcgr00Name[] = "back_screen_s_b_00.ncgr";
char gBackScreenSNclr00Name[] = "back_screen_s_b_00.nclr";
char gBackScreenMNcgr00Name[] = "back_screen_m_b_00.ncgr";
char gBackScreenMNcgr01Name[] = "back_screen_m_b_01.ncgr";
char gBackScreenMNscrBg01Name[] = "back_screen_m_bg_01.nscr";
char gBackScreenMNclr00Name[] = "back_screen_m_b_00.nclr";
char gBackScreenSNscrBg00Name[] = "back_screen_s_bg_00.nscr";
char gBackScreenMNclr01Name[] = "back_screen_m_b_01.nclr";

void PrepareNavigationContextFiles_from_thumb(void) {
    LoadedPartPointer loadedPartPointer;

    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        Gfx_ReadCharGraphicsV2(&loadedPartPointer.mNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("txt_system_b_00.ncgr"));
        MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("txt_system_bg_00.nscr"));
        Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("txt_system_b_00.nclr"));
    } else {
        Gfx_ReadCharGraphicsV2(&loadedPartPointer.mNcgr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_b_00.ncgr"));
        Gfx_ReadCharGraphicsV2(&loadedPartPointer.mNcgr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_b_01.ncgr"));
        MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_00.nscr"));
        MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_00_2.nscr"));
        MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_01.nscr"));
        MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_01_2.nscr"));
        MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_02.nscr"));
        MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_02_2.nscr"));
        MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_bg_02_3.nscr"));
        Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("txt_system_b_00.nclr"));
        Gfx_ReadCharGraphicsV2(&loadedPartPointer.mNcgr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_choises_s_b.ncgr"));
        MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_choises_s_bg.nscr"));
        Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_choises_s_b.nclr"));
        Gfx_ReadCharGraphicsV2(&loadedPartPointer.mNcgr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_return_s_b_00.ncgr"));
        MaybeReadScreenBlock_0(&loadedPartPointer.mNscr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_return_s_bg_00.nscr"));
        Gfx_ReadPalette(&loadedPartPointer.mNclr, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("select_return_s_b_00.nclr"));
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

s32 InitializeBackScreen_from_thumb(s32 subCharOffset) {
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

    kind = g_NavigationContext->mBackScreenKind;
    indexM = gBackScreenKindIndices[kind * 2];
    indexS = (gBackScreenKindIndices + 1)[kind * 2];
    nclrMOffset = gBackScreenMNclrStarts[indexM] << 5;
    nclrMSize = (0xe - gBackScreenMNclrStarts[indexM]) << 5;
    nclrSOffset = gBackScreenSNclrStarts[indexS] << 5;
    nclrSSize = (0xc - gBackScreenSNclrStarts[indexS]) << 5;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        MaybeReadCharBlock_1(&ncgrM, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("common/select_race_rule_s_b.NCGR"));
        MaybeReadScreenBlock_0(&nscrM, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("common/select_race_rule_download_bg_m.NSCR"));
        Gfx_ReadPaletteRelative(&nclrM, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("common/select_race_rule_s_b.NCLR"));
        ncgrS = ncgrM;
        MaybeReadScreenBlock_0(&nscrS, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("common/select_race_rule_download_bg_s.NSCR"));
        nclrS = nclrM;
    } else {
        if (gBackScreenInLoadedArchives[indexM] != 0) {
            Gfx_ReadCharGraphicsV2(&ncgrM, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(g_str_back_screen_m_b_00_01_ncgr[indexM]));
            MaybeReadScreenBlock_0(&nscrM, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(g_str_back_screen_m_b_00_01_nscr[indexM]));
            Gfx_ReadPalette(&nclrM, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(g_str_back_screen_m_b_00_01_nclr[indexM]));
        } else {
            Gfx_ReadCharGraphicsV2(&ncgrM, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_back_screen_m_b_00_01_ncgr[indexM]));
            MaybeReadScreenBlock_0(&nscrM, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_back_screen_m_b_00_01_nscr[indexM]));
            Gfx_ReadPalette(&nclrM, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_back_screen_m_b_00_01_nclr[indexM]));
        }
        if (gBackScreenInLoadedArchives[indexS] != 0) {
            Gfx_ReadCharGraphicsV2(&ncgrS, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(g_str_back_screen_s_b_00_ncgr[indexS]));
            MaybeReadScreenBlock_0(&nscrS, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(g_str_back_screen_s_bg_00_nscr[indexS]));
            Gfx_ReadPalette(&nclrS, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(g_str_back_screen_s_b_00_nclr[indexS]));
        } else {
            Gfx_ReadCharGraphicsV2(&ncgrS, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_back_screen_s_b_00_ncgr[indexS]));
            MaybeReadScreenBlock_0(&nscrS, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_back_screen_s_bg_00_nscr[indexS]));
            Gfx_ReadPalette(&nclrS, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(g_str_back_screen_s_b_00_nclr[indexS]));
        }
    }
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_BG3_TILES, 0, ncgrM->mData, ncgrM->mDataSize);
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_BG3_MAP, 0, nscrM->mData, nscrM->mDataSize);
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_A_BG_PALETTE, nclrMOffset,
                                       OFFSET_PTR(void, nclrM->mData, nclrMOffset), nclrMSize);
    subCharOffset -= ncgrS->mDataSize;
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG1_TILES, subCharOffset, ncgrS->mData, ncgrS->mDataSize);
    for (rowIndex = 0; rowIndex < 0x20; rowIndex++) {
        for (columnIndex = 0; columnIndex < 0x20; columnIndex++) {
            *(g_NavigationContext->mBackScreenSNscrCopy + rowIndex * 0x20 + columnIndex) =
                (subCharOffset >> 5) + *((u16 *) nscrS->mData + rowIndex * 0x20 + columnIndex);
        }
    }
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG1_MAP, 0, g_NavigationContext->mBackScreenSNscrCopy,
                                       nscrS->mDataSize);
    AllocateReserveTEQSub(VRAM_TARGET_ENGINE_B_BG_PALETTE, nclrSOffset,
                                       OFFSET_PTR(void, nclrS->mData, nclrSOffset), nclrSSize);
    return subCharOffset;
}

#pragma thumb off
