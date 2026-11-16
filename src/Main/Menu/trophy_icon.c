#include "Main/Menu/trophy_icon.h"
#include "Main/System/heap.h"
#include "Main/System/result_archive_path.h"
#include "Main/Graphics/font_and_player_character.h"

#include "Main/Menu/back_screen_keyboard_tables.h"
#include "Main/System/stdio_files.h"
#include "print_memory_multibyte_write.h"
#include "capture_output_effect.h"
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

char *gTrophyIconNcerName = "common/trophy_icon.nce.ncer";
char *gTrophyIconBnclName = "common/trophy_icon.bncl";
char *gTrophyIconNclrName = "common/trophy_icon_o.nclr";
const u16 gTrophyIconNclrStarts[4] = {0, 1, 2, 0};
const u16 gTrophyIconBnclIndices[8] = {0, 1, 2, 3, 4, 5, 6, 7};
char *gTrophyIconNcgrName = "common/trophy_icon.nce.ncgr";
TrophyIcon *gTrophyIcon;

#pragma thumb on

void VerifySelectTrophyIconFiles_from_thumb(void) {
    void *sceneFile;
    Ncgr *chars;
    NNSG2dCellDataBank *cells;
    Nclr *palette[1];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gTrophyIconNcgrName);
    Gfx_ReadCharGraphicsV2(&chars, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gTrophyIconNcerName);
    LoadCellBankFrom(&cells, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gTrophyIconNclrName);
    Gfx_ReadPalette(palette, sceneFile);
}

void CreateTrophyIcon(void *heap) {
    void *sceneFile;
    gTrophyIcon = Mem_AllocateHeap(heap, sizeof(*gTrophyIcon));
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gTrophyIconNcgrName);
    Gfx_ReadCharGraphicsRelative(&gTrophyIcon->mNcgr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gTrophyIconNcerName);
    LocateNcer(&gTrophyIcon->mNcer, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gTrophyIconNclrName);
    Gfx_ReadPaletteRelative(&gTrophyIcon->mNclr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gTrophyIconBnclName);
    gTrophyIcon->mBncl = sceneFile;
}

#pragma thumb off

#pragma thumb on

void ClearTrophyIconPointer(void) {
    gTrophyIcon = NULL;
}

#pragma thumb off

#pragma thumb on

void QueueTrophyIcon(int iconIndex, int paletteIndex, void *cells, void *cellLayout, u32 destIndex, u16 paletteSlot,
                     int queueSelector) {
    u32 transferKind;
    TrophyIcon *trophyIcon;
    transferKind = 0xe;
    if ((queueSelector != 0) && (queueSelector == 1)) {
        transferKind = 0x1e;
    }
    trophyIcon = gTrophyIcon;
    QueueCellChars(gTrophyIconBnclIndices[iconIndex], trophyIcon->mNcer, trophyIcon->mNcgr, trophyIcon->mBncl,
                   queueSelector, destIndex, cells, cellLayout);
    AllocateReserveTEQSub(transferKind, paletteSlot << 5,
                                       gTrophyIcon->mNclr->mBytes + gTrophyIconNclrStarts[paletteIndex] * 0x20,
                                       0x20);
}

void nullsub_20_from_thumb(void) {}

#pragma thumb off
