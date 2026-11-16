#include "01/Menu/mission_run_boss_icon.h"

#include "types.h"
#include "01/Menu/emblem_state_and_lld.h"
#include "01/Menu/emblem_grid.h"
#include "01/Graphics/clear_chars_and_screen_map.h"
#include "01/Menu/menu_screen_work_structs.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "sound_player_control.h"
#include "01/Menu/emblem_and_boss_icon_tables.h"
#include "sound_archive_load_result.h"

const char *gMissionRunBossIconSNcgrName = "mr/Mission_run_BOSS_icon_s.nce.ncgr";
const char *gMissionRunBossIconSNcerName = "mr/Mission_run_BOSS_icon_s.nce.ncer";
const char *gMissionRunBossIconSONclrName = "mr/Mission_run_BOSS_icon_s_o.nclr";
const char *gMissionRunBossIconSBnclName = "mr/Mission_run_BOSS_icon_s.bncl";
const u16 gMissionRunBossIconCellIndices[7] = {0, 1, 2, 3, 4, 5, 6};
const u16 gMissionRunBossIconPaletteIndices[7] = {0, 1, 2, 3, 4, 5, 6};
MissionRunBossIcon *gMissionRunBossIcon;

void LoadMissionRunBossIconData(void) {
    void *sceneFile;
    Ncgr *ncgr;
    NNSG2dCellDataBank *ncer;
    Nclr *nclr[1];
    ncgr = NULL;
    ncer = NULL;
    nclr[0] = NULL;
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gMissionRunBossIconSNcgrName);
    Gfx_ReadCharGraphicsV2(&ncgr, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gMissionRunBossIconSNcerName);
    LoadCellBankFrom(&ncer, sceneFile);
    sceneFile = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gMissionRunBossIconSONclrName);
    Gfx_ReadPalette(nclr, sceneFile);
}

void CreateMissionRunBossIcon(void *heap) {
    gMissionRunBossIcon = Mem_AllocateHeap(heap, sizeof(MissionRunBossIcon));
    Gfx_ReadCharGraphicsRelative(&gMissionRunBossIcon->mNcgr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gMissionRunBossIconSNcgrName));
    LocateNcer(&gMissionRunBossIcon->mNcer, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gMissionRunBossIconSNcerName));
    Gfx_ReadPaletteRelative(&gMissionRunBossIcon->mNclr, FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gMissionRunBossIconSONclrName));
    gMissionRunBossIcon->mBncl = FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(gMissionRunBossIconSBnclName);
}

void ClearMissionRunBossIconPointer(void) {
    gMissionRunBossIcon = NULL;
}

void QueueMissionRunBossIcon(s16 rowIndex, s32 usePaletteIndex, void *destCells, void *destCellLayout, u32 destIndex,
                             u16 paletteSlot, s32 queueSelector) {
    s32 transferKind = 14;
    MissionRunBossIcon *missionRunBossIcon;
    u8 *paletteData;
    s32 paletteIndex;

    if (queueSelector != 0) {
        if (queueSelector == 1) {
            transferKind = 30;
        }
    }
    missionRunBossIcon = gMissionRunBossIcon;
    QueueCellChars(gMissionRunBossIconCellIndices[rowIndex], missionRunBossIcon->mNcer, missionRunBossIcon->mNcgr,
                   missionRunBossIcon->mBncl, queueSelector, destIndex, (destCells), (destCellLayout));
    paletteData = (u8 *) gMissionRunBossIcon->mNclr->mData;
    if (usePaletteIndex != 0) {
        paletteIndex = gMissionRunBossIconPaletteIndices[rowIndex];
    } else {
        paletteIndex = 7;
    }
    AllocateReserveTEQSub(transferKind, paletteSlot << 5, paletteData + (paletteIndex << 5), 32);
}
