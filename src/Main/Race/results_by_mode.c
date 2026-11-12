#include "Main/Race/results_by_mode.h"
#include "Main/Graphics/scene_text_wrapper.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02032000.h"
#include "Main/Race/results_battle_registers.h"
#include "Main/System/heap.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Scene/scene_connection.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Graphics/oam_upload.h"
#include "Main/Unknown/code_0212a000.h"

#include "Main/Race/results_gp.h"
#include "Main/Unknown/code_02032ab0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Graphics/oam_lists.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Menu/message_screen.h"
#include "Main/Unknown/unk_021759c0.h"
#include "g2.h"
#include "code_0214d018.h"
#include "registers.h"

#pragma thumb on

void InitResultsByMode(void *heap) {
    gResultScene = HeapAlloc(heap, 0x80c);
    MemFillWordsByBlock_inline(gResultScene, 0x80c);
    ResetOamLists(gResultScene, gResultScene->mSubOam);
    gResultScene->mMode = gRaceSetup->mMode;
    if (gResultScene->mMode == 0) {
        InitResultsGp(heap, gResultScene, gResultScene->mSubOam);
    } else {
        InitResultsBattle(heap, gResultScene, gResultScene->mSubOam);
    }
    InitLinkLevelIcons(heap, gResultScene);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 1, 0x3f, 8, 8);
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x2f, 8, 8);
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
}

#pragma thumb off

#pragma thumb on

void AdvanceResultsByMode(SceneNumbers *sceneNumbers) {
    int result;
    result = IsDataSharingIncomplete();
    if (result == 0) {
        ClearOamListCounts(gResultScene, gResultScene->mSubOam);
        if (gResultScene->mMode == 0) {
            AdvanceResultsGp(sceneNumbers);
        } else {
            AdvanceResultsBattle(sceneNumbers);
        }
        HideUnusedOams(gResultScene, gResultScene->mSubOam);
        AdvanceLinkLevelIcons();
    }
}

void ReleaseResultsByMode(void) {
    if (gResultScene->mMode == 0) {
        ReleaseSceneTextWrapper();
    } else {
        ReleaseResultsBattle();
    }
    ClearLinkLevelIconsPointer();
}

void WriteResultsByMode(void) {
    if (gResultScene->mMode == 0) {
        WriteSceneTextRegistersWrapper();
    } else {
        ResultsBattleWriteSceneTextRegistersWrapper();
    }
    UploadOamLists(gResultScene, gResultScene->mSubOam);
}

#pragma thumb off
