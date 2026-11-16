#include "Main/Menu/kart_icon.h"
#include "Main/System/heap.h"

#include "Main/Menu/kart_icon_row.h"
#include "Main/Graphics/font_and_player_character.h"
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
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "vram_transfer_queue.h"
#include "Main/Menu/select_cup_name_files.h"
#include "Main/System/result_archive_path.h"

#pragma thumb on

const char *gKartIconNcgrName = "Kart_icon_o_all.nce.ncgr";
const char *gKartIconNcerName = "Kart_icon_o_all.nce.ncer";
const char *gKartIconNclrNames[3] = {"Kart_icon_o_A.nclr", "Kart_icon_o_B.nclr", "Kart_icon_o_C.nclr"};
const char *gKartIconBnclName = "Kart_icon_all.bncl";
const char *gCommonKartIconNcgrName = "common/Kart_icon_o_all.nce.ncgr";
const char *gCommonKartIconNcerName = "common/Kart_icon_o_all.nce.ncer";
const char *gCommonKartIconNclrNames[3] = {"common/Kart_icon_o_A.nclr", "common/Kart_icon_o_B.nclr",
                                           "common/Kart_icon_o_C.nclr"};
const char *gCommonKartIconBnclName = "common/Kart_icon_all.bncl";
const KartIconRow gKartIconRows[37] = {
    {0, 0, 0, 0, 0},      {1, 0, 1, 0, 0},      {2, 0, 2, 0, 0},      {3, 0, 0, 1, 0},      {4, 0, 1, 1, 0},
    {5, 0, 2, 1, 0},      {6, 0, 0, 2, 0},      {7, 0, 1, 2, 0},      {8, 0, 2, 2, 0},      {9, 0, 0, 3, 0},
    {0xa, 0, 1, 3, 0},    {0xb, 0, 2, 3, 0},    {0xc, 0, 0, 4, 0},    {0xd, 0, 1, 4, 0},    {0xe, 0, 2, 4, 0},
    {0xf, 0, 0, 5, 0},    {0x10, 0, 1, 5, 0},   {0x11, 0, 2, 5, 0},   {0x12, 0, 0, 6, 0},   {0x13, 0, 1, 6, 0},
    {0x14, 0, 2, 6, 0},   {0x15, 0, 0, 7, 0},   {0x16, 0, 1, 7, 0},   {0x17, 0, 2, 7, 0},   {0x18, 0, 0, 8, 0},
    {0x19, 0, 1, 8, 0},   {0x1a, 0, 2, 8, 0},   {0x1b, 0, 0, 9, 0},   {0x1c, 0, 1, 9, 0},   {0x1d, 0, 2, 9, 0},
    {0x1e, 0, 0, 0xa, 0}, {0x1f, 0, 1, 0xa, 0}, {0x20, 0, 2, 0xa, 0}, {0x21, 0, 0, 0xb, 0}, {0x22, 0, 1, 0xb, 0},
    {0x23, 0, 2, 0xb, 0}, {0, 0, 0, 0, 0}};
KartIcon *gKartIcon;

void LoadKartIconData(void) {
    void *sceneFile;
    int paletteCount;
    const char **nclrNameCursor;
    Ncgr *chars;
    NNSG2dCellDataBank *cells;
    Nclr *palette[2];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gKartIconNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gKartIconNcerName);
    LoadNcerData(&cells, sceneFile);
    paletteCount = 0;
    nclrNameCursor = gKartIconNclrNames;
    do {
        sceneFile = FindSceneFile(*nclrNameCursor);
        LoadNclrData(palette, sceneFile);
        nclrNameCursor = nclrNameCursor + 1;
        paletteCount = paletteCount + 1;
    } while (paletteCount < 3);
}

void LoadCommonKartIconData(void) {
    void *sceneFile;
    int paletteCount;
    const char **nclrNameCursor;
    Ncgr *chars;
    NNSG2dCellDataBank *cells;
    Nclr *palette[2];
    chars = NULL;
    cells = NULL;
    palette[0] = NULL;
    sceneFile = FindSceneFile(gCommonKartIconNcgrName);
    LoadNcgrData(&chars, sceneFile);
    sceneFile = FindSceneFile(gCommonKartIconNcerName);
    LoadNcerData(&cells, sceneFile);
    paletteCount = 0;
    nclrNameCursor = gCommonKartIconNclrNames;
    do {
        sceneFile = FindSceneFile(*nclrNameCursor);
        LoadNclrData(palette, sceneFile);
        nclrNameCursor = nclrNameCursor + 1;
        paletteCount = paletteCount + 1;
    } while (paletteCount < 3);
}

#pragma thumb off

#pragma thumb on

void CreateKartIcon(void *heap) {
    int nclrIndex;

    gKartIcon = HeapAlloc(heap, sizeof(*gKartIcon));
    LocateNcgr2(&gKartIcon->mNcgr, FindSceneFile(gKartIconNcgrName));
    LocateNcer(&gKartIcon->mNcer, FindSceneFile(gKartIconNcerName));
    for (nclrIndex = 0; nclrIndex < 3; nclrIndex++) {
        LocateNclr(&gKartIcon->mNclrs[nclrIndex], FindSceneFile(gKartIconNclrNames[nclrIndex]));
    }
    gKartIcon->mBncl = FindSceneFile(gKartIconBnclName);
}

#pragma thumb off

#pragma thumb on

void CreateCommonKartIcon(void *heap) {
    s32 nclrIndex;

    gKartIcon = HeapAlloc(heap, sizeof(*gKartIcon));
    LocateNcgr2(&gKartIcon->mNcgr, FindSceneFile(gCommonKartIconNcgrName));
    LocateNcer(&gKartIcon->mNcer, FindSceneFile(gCommonKartIconNcerName));
    for (nclrIndex = 0; nclrIndex < 3; nclrIndex++) {
        LocateNclr(&gKartIcon->mNclrs[nclrIndex], FindSceneFile(gCommonKartIconNclrNames[nclrIndex]));
    }
    gKartIcon->mBncl = FindSceneFile(gCommonKartIconBnclName);
}

#pragma thumb off

#pragma thumb on
void ClearKartIconPointer(void) {
    gKartIcon = NULL;
}
#pragma thumb off

#pragma thumb on

void QueueKartIcon(s32 iconIndex, NNSG2dCellDataBank *destinationNcer, LayoutEntryTable *destinationBncl,
                   u32 destinationBnclIndex, u16 paletteIndex, s32 queueSelector) {
    int queueKind;

    queueKind = 0x12;
    switch (queueSelector) {
        case 0:
            queueKind = 0xe;
            break;
        case 1:
            queueKind = 0x1e;
            break;
    }
    QueueCellChars(gKartIconRows[iconIndex].mBnclIndex, gKartIcon->mNcer, gKartIcon->mNcgr, gKartIcon->mBncl,
                   queueSelector, destinationBnclIndex, destinationNcer, destinationBncl);
    NNS_GfdRegisterNewVramTransferTask(
        queueKind, paletteIndex * 32,
        gKartIcon->mNclrs[gKartIconRows[iconIndex].mNclrIndex]->mData + gKartIconRows[iconIndex].mNclrStart * 16, 0x20);
}

#pragma thumb off
