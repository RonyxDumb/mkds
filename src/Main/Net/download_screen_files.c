#include "Main/Net/download_screen_files.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/System/result_archive_path.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "touch_panel_sampling.h"
#include "cell_animation.h"
#include "Main/Graphics/font_and_player_character.h"

struct DownloadScreenFiles *g_Global2D;

void LoadStatic2DContents(void *heap) {
    g_Global2D = Mem_AllocateHeap(heap, sizeof(*g_Global2D));
    g_Global2D->mSearchIconCellLayout = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("search_icon_00.bncl");
    g_Global2D->mSearchIconLayoutCellLayout = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("search_icon_layout_00.bncl");
    Gfx_ReadCharGraphics(&g_Global2D->mSearchIconChars, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("search_icon_00.nce.ncgr"));
    LoadCellBankFrom(&g_Global2D->mSearchIconCells, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("search_icon_00.nce.ncer"));
    Gfx_ReadPalette(&g_Global2D->mSearchIconPalette, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("search_icon_00_o.nclr"));
    switch (g_GlobalP->mLanguageIndex) {
        default:
            NFTR_Load(&g_Global2D->mMBChildFont, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("MBChild_us.NFTR"));
            break;
        case LANGUAGE_FRENCH:
            NFTR_Load(&g_Global2D->mMBChildFont, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("MBChild_fr.NFTR"));
            break;
        case LANGUAGE_GERMAN:
            NFTR_Load(&g_Global2D->mMBChildFont, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("MBChild_ge.NFTR"));
            break;
        case LANGUAGE_ITALIAN:
            NFTR_Load(&g_Global2D->mMBChildFont, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("MBChild_it.NFTR"));
            break;
        case LANGUAGE_SPANISH:
            NFTR_Load(&g_Global2D->mMBChildFont, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("MBChild_es.NFTR"));
            break;
    }
    switch (g_GlobalP->mLanguageIndex) {
        default:
            g_Global2D->mMBChildMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("MBChild_us.bmg");
            break;
        case LANGUAGE_FRENCH:
            g_Global2D->mMBChildMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("MBChild_fr.bmg");
            break;
        case LANGUAGE_GERMAN:
            g_Global2D->mMBChildMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("MBChild_ge.bmg");
            break;
        case LANGUAGE_ITALIAN:
            g_Global2D->mMBChildMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("MBChild_it.bmg");
            break;
        case LANGUAGE_SPANISH:
            g_Global2D->mMBChildMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("MBChild_es.bmg");
            break;
    }
    Gfx_ReadCharGraphicsV2(&g_Global2D->mMultiDownloadChars, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("multi_download_00_b.NCGR"));
    Gfx_ReadPalette(&g_Global2D->mMultiDownloadPalette, FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb("multi_download_00_b.NCLR"));
}
