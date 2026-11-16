#include "Main/Menu/multi_select_files.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Menu/label_palette_indices.h"


#pragma thumb on

void MaybeVerifyMultiSelectFiles_from_thumb(void) {
    void *file;
    Ncgr *chars;
    Nclr *palette;
    NNSG2dCellDataBank *cells;
    Nscr *screenMaps[1];
    chars = NULL;
    palette = NULL;
    cells = NULL;
    screenMaps[0] = NULL;
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_s_b.NCGR");
    Gfx_ReadCharGraphicsV2(&chars, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_m.nce.ncgr");
    Gfx_ReadCharGraphics(&chars, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_group_s.nce.ncgr");
    Gfx_ReadCharGraphics(&chars, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_register_s.nce.ncgr");
    Gfx_ReadCharGraphics(&chars, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_NS_s.nce.ncgr");
    Gfx_ReadCharGraphics(&chars, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_m.nce.ncer");
    LoadCellBankFrom(&cells, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_group_s.nce.ncer");
    LoadCellBankFrom(&cells, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_register_s.nce.ncer");
    LoadCellBankFrom(&cells, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_NS_s.nce.ncer");
    LoadCellBankFrom(&cells, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_m_o.NCLR");
    Gfx_ReadPalette(&palette, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_s_b.NCLR");
    Gfx_ReadPalette(&palette, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_group_s_o.NCLR");
    Gfx_ReadPalette(&palette, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_register_s_o.NCLR");
    Gfx_ReadPalette(&palette, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_NS_s_o.NCLR");
    Gfx_ReadPalette(&palette, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_s_register.NSCR");
    MaybeReadScreenBlock_0(screenMaps, file);
    file = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb("multi_select_member_s_group.NSCR");
    MaybeReadScreenBlock_0(screenMaps, file);
}

#pragma thumb off
