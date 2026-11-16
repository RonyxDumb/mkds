#include "Main/Unknown/code_0202a5a0.h"
#include "Main/Unknown/code_02029a90.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02032000.h"
#include "Main/Unknown/code_02032aa8.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_0212a000.h"

#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_02032ab0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0214a390.h"
#include "code_0214d018.h"
#include "registers.h"

#pragma thumb on

void result_init(void *heap) {
    result_sState = heap_alloc(heap, 0x80c);
    MemFillWordsByBlock_inline(result_sState, 0x80c);
    oam_clearResetBuffers(result_sState, result_sState->mSubOam);
    result_sState->mMode = gRaceMultiConfig->mMode;
    if (result_sState->mMode == 0) {
        gpres_init(heap, result_sState, result_sState->mSubOam);
    } else {
        bres_init(heap, (s32) result_sState, (s32) result_sState->mSubOam);
    }
    InitLinkLevelIcons(heap, result_sState);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 1, 0x3f, 8, 8);
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x2f, 8, 8);
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
}

#pragma thumb off

#pragma thumb on

void result_update(u32 sceneNumbers) {
    int result;
    result = scene_areUpdatesSuspended();
    if (result == 0) {
        oam_resetBuffers(result_sState, result_sState->mSubOam);
        if (result_sState->mMode == 0) {
            gpres_update((SceneNumbersView *) sceneNumbers);
        } else {
            bres_update((SceneNumbersView *) sceneNumbers);
        }
        oam_prepareBuffers(result_sState, result_sState->mSubOam);
        AdvanceLinkLevelIcons();
    }
}

void result_finalize(void) {
    if (result_sState->mMode == 0) {
        gpres_finalize();
    } else {
        bres_finalize();
    }
    ClearLinkLevelIconsPointer();
}

void result_vblank(void) {
    if (result_sState->mMode == 0) {
        gpres_vblank();
    } else {
        bres_vblank();
    }
    oam_applyBuffers(result_sState, result_sState->mSubOam);
}

#pragma thumb off
