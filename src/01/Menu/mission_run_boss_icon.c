#include "01/Menu/mission_run_boss_icon.h"

#include "types.h"
#include "01/code_021a5140.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/Menu/emblem_grid.h"
#include "01/Graphics/clear_chars_and_screen_map.h"
#include "01/unk_021ca000.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "player.h"
#include "01/unk_021a7000.h"
#include "code_0212df7c.h"

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
    Unk02021dc8 *ncer;
    Nclr *nclr[1];
    ncgr = NULL;
    ncer = NULL;
    nclr[0] = NULL;
    sceneFile = FindSceneFile(gMissionRunBossIconSNcgrName);
    LoadNcgrData(&ncgr, sceneFile);
    sceneFile = FindSceneFile(gMissionRunBossIconSNcerName);
    LoadNcerData(&ncer, sceneFile);
    sceneFile = FindSceneFile(gMissionRunBossIconSONclrName);
    LoadNclrData(nclr, sceneFile);
}

void CreateMissionRunBossIcon(void *heap) {
    gMissionRunBossIcon = HeapAlloc(heap, 0x10);
    LocateNcgr2(&gMissionRunBossIcon->mNcgr, FindSceneFile(gMissionRunBossIconSNcgrName));
    LocateNcer(&gMissionRunBossIcon->mNcer, FindSceneFile(gMissionRunBossIconSNcerName));
    LocateNclr(&gMissionRunBossIcon->mNclr, FindSceneFile(gMissionRunBossIconSONclrName));
    gMissionRunBossIcon->mBncl = FindSceneFile(gMissionRunBossIconSBnclName);
}

void ClearMissionRunBossIconPointer(void) {
    *(u32 *) &gMissionRunBossIcon = 0;
}

void QueueMissionRunBossIcon(s32 rowIndex, s32 usePaletteIndex, void *destCells, void *destCellLayout, u32 destIndex,
                             u16 paletteSlot, s32 queueSelector) {
    s32 v0 = 14;
    MissionRunBossIcon *missionRunBossIcon;
    u8 *paletteData;
    s32 paletteIndex;

    if (queueSelector != 0) {
        if (queueSelector == 1) {
            v0 = 30;
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
    NNS_GfdRegisterNewVramTransferTask(v0, paletteSlot << 5, paletteData + (paletteIndex << 5), 32);
}
