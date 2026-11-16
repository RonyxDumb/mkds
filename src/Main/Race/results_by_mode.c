#include "Main/Race/results_by_mode.h"
#include "Main/Graphics/scene_text_wrapper.h"
#include "Main/Race/results_battle_registers.h"
#include "Main/System/heap.h"
#include "Main/Scene/scene_connection.h"
#include "Main/Graphics/oam_upload.h"

#include "Main/Race/results_gp.h"
#include "Main/Graphics/oam_lists.h"
#include "Main/Menu/message_screen.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "display_blend_affine_setup.h"
#include "cpu_copy_fill.h"
#include "registers.h"
#include "Main/Menu/select_kart_ghost_work.h"

struct ResultScene *g_GlobalN;

#pragma thumb on

void InstanceStructN_from_thumb(void *heap) {
    g_GlobalN = Mem_AllocateHeap(heap, sizeof(*g_GlobalN));
    MemFillWordsByBlock_inline(g_GlobalN, 0x80c);
    OamBuffer_SomeFn_from_thumb(g_GlobalN, g_GlobalN->mSubOam);
    g_GlobalN->mMode = g_GlobalCO->mMode;
    if (g_GlobalN->mMode == 0) {
        InstanceStructM_from_thumb(heap, g_GlobalN, g_GlobalN->mSubOam);
    } else {
        InstanceStructV_from_thumb(heap, g_GlobalN, g_GlobalN->mSubOam);
    }
    CreateGlobalNN_from_thumb(heap, g_GlobalN);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~(REG_GX_DISPCNT_EXOBJ_CH_MASK | REG_GX_DISPCNT_OBJMAP_CH_MASK)) |
                     REG_GX_DISPCNT_OBJMAP_CH_MASK;
    reg_GXS_DB_DISPCNT =
        (reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_EXOBJ_CH_MASK | REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK)) |
        REG_GXS_DB_DISPCNT_OBJMAP_CH_MASK;
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 1, 0x3f, 8, 8);
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x2f, 8, 8);
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~(REG_GX_DISPCNT_OW_MASK | REG_GX_DISPCNT_W1_MASK | REG_GX_DISPCNT_W0_MASK);
    reg_GXS_DB_DISPCNT =
        reg_GXS_DB_DISPCNT & ~(REG_GXS_DB_DISPCNT_OW_MASK | REG_GXS_DB_DISPCNT_W1_MASK | REG_GXS_DB_DISPCNT_W0_MASK);
}

#pragma thumb off

#pragma thumb on

void Scene_Result_UpdateImpl_from_thumb(SceneNumbers *sceneNumbers) {
    int result;
    result = IsDataSharingIncomplete();
    if (result == 0) {
        OamBuffer_ResetValues16_from_thumb(g_GlobalN, g_GlobalN->mSubOam);
        if (g_GlobalN->mMode == 0) {
            HandleEarnedSecrets_from_thumb(sceneNumbers);
        } else {
            AdvanceResultsBattle(sceneNumbers);
        }
        OamBuffer_SomeFn2_from_thumb(g_GlobalN, g_GlobalN->mSubOam);
        AdvanceLinkLevelIcons();
    }
}

void Scene_Result_FinalizeImpl_from_thumb(void) {
    if (g_GlobalN->mMode == 0) {
        j_DisposeNavigationContext_from_thumb();
    } else {
        ReleaseResultsBattle();
    }
    ResetGlobalNN_from_thumb();
}

void Scene_Result_VBlankImpl_from_thumb(void) {
    if (g_GlobalN->mMode == 0) {
        j_NavigationContext_OnSceneVblank_from_thumb();
    } else {
        j_NavigationContext_OnSceneVblank_0_from_thumb();
    }
    CopyOamBuffersToMemory_from_thumb(g_GlobalN, g_GlobalN->mSubOam);
}

#pragma thumb off
