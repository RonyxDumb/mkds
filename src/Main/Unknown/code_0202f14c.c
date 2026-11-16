#include "Main/Unknown/code_0202f14c.h"

#include "Main/Unknown/code_0202f000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Ui/BackScreen.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0202f498.h"
#include "Main/Unknown/code_0202f4ac.h"
#include "Main/Unknown/code_0202f554.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02163000.h"
#include "registers.h"

void SetSomeDispcntTopMask(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | bits;
}

void SetSomeDispcntSubMask(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | bits;
}

#pragma thumb on

void InitWLMenuScene(void *heap) {
    Unk02180774 *displaySettings;
    Unk02125de0Arg v1;

    gWLMenuScene = heap_allocEx(heap, 0x874, 0x20);
    sub_202F51C(gWLMenuScene, 0x874);
    displaySettings = dc_createDisplayConfig(heap, data_02154818);
    DisplayConfig_SetTopEngineBg1Config_0(displaySettings, 0, 0, 0, 0, 0xc, 0, 0);
    DisplayConfig_SetBottomEngineBg3Config_0(displaySettings, 2, 0, 0, 0, 0xf, 6);
    dc_setDisplayConfig(displaySettings);
    if (j_IsDwc_2() == 0) {
        v1.field0 = 1;
        v1.field4 = m2d_getFont(1);
        v1.field8 = 0;
        v1.fieldC = 1;
        v1.field10 = 0;
        v1.field14 = 0;
        v1.field18 = NULL;
        v1.field1C = 1;
        v1.field20 = GetB488SomeMode() == 0;
        v1.field24 = 0;
        gmenu_unpackData();
        gmenu_init(heap, &v1);
    }
    InitLinkLevelIcons(heap, gWLMenuScene);
    switch (GetB488SomeMode()) {
        case 0:
            gWLMenuScene->mRequestedCallbacksIndex = j_IsDwc_2() != 0 ? 4 : 0;
            sub_203B0F8(heap);
            sub_2053D00();
            break;
        case 1:
            gWLMenuScene->mRequestedCallbacksIndex = 5;
            sub_203B1FC(heap);
            break;
        case 2:
            gWLMenuScene->mRequestedCallbacksIndex = 6;
            sub_203B1C8(heap);
            break;
        case 3:
            gWLMenuScene->mRequestedCallbacksIndex = 7;
            sub_203B194(heap);
            break;
    }
    gWLMenuScene->mCurrentCallbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
    gWLMenuScene->mCurrentCallbacks = gWLMenuCallbacks[gWLMenuScene->mRequestedCallbacksIndex];
    gWLMenuScene->mHeap = heap_createSubExpHeap(heap);
    if (j_IsDwc_2() == 0) {
        LoadMultiSelectFiles();
    }
    oam_clearResetBuffers(gWLMenuScene, gWLMenuScene->mSubOam);
    SetSomeDispcntTopMask(0x10);
    SetSomeDispcntSubMask(0x10);
    gWLMenuScene->mCurrentCallbacks->field0(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
}

void AdvanceWLMenuScene(void *a) {
    s32 callbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
    WLMenuCallbacks *previousCallbacks;

    if (gWLMenuScene->mCurrentCallbacksIndex != callbacksIndex) {
        previousCallbacks = gWLMenuScene->mCurrentCallbacks;
        gWLMenuScene->mCurrentCallbacks = gWLMenuCallbacks[callbacksIndex];
        gWLMenuScene->mCurrentCallbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
        previousCallbacks->field8();
        gWLMenuScene->mCurrentCallbacks->field0(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
    } else {
        oam_resetBuffers(gWLMenuScene, gWLMenuScene->mSubOam);
        callbacksIndex = gWLMenuScene->mCurrentCallbacks->field4(a);
        if (callbacksIndex != -1) {
            gWLMenuScene->mRequestedCallbacksIndex = callbacksIndex;
        }
        AdvanceLinkLevelIcons();
        oam_prepareBuffers(gWLMenuScene, gWLMenuScene->mSubOam);
    }
    if (j_IsDwc_2() == 0) {
        gmenu_render();
    }
}

#pragma thumb off

#pragma thumb on

void EndMultiplayerMenu(void) {
    int v1;
    gWLMenuScene->mCurrentCallbacks->field8();
    v1 = j_IsDwc_2();
    if (v1 == 0) {
        gmenu_finish();
    }
    ClearLinkLevelIconsPointer();
}

#pragma thumb off

u16 *GetBiosBootIndicatorRef(void) {
    return (u16 *) 0x027ffc40;
}

u32 IsDwc_2(void) {
    return *GetBiosBootIndicatorRef() == 2;
}

u32 j_IsDwc_2(void) {
    return IsDwc_2();
}

#pragma thumb on

void func_0202f160(void) {
    int v1;
    v1 = j_IsDwc_2();
    if (v1 == 0) {
        gmenu_vblank();
    }
    gWLMenuScene->mCurrentCallbacks->fieldC();
    oam_applyBuffers(gWLMenuScene, gWLMenuScene->mSubOam);
}

Unk02174e4c_818 *func_0202f14c(void) {
    return &gWLMenuScene->field818;
}

#pragma thumb off
