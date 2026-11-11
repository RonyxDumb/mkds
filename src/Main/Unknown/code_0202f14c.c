#include "Main/Unknown/code_0202f14c.h"

#include "Main/Unknown/code_0202f000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0202f498.h"
#include "Main/Unknown/code_0202f4ac.h"
#include "Main/Unknown/code_0202f554.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
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
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02163000.h"
#include "registers.h"
#include "Main/Unknown/code_0211d4a8.h"

void WLMenuGX_SetOBJVRamModeChar(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | bits;
}

void WLMenuGXS_SetOBJVRamModeChar(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | bits;
}

#pragma thumb on

void InitWLMenuScene(void *heap) {
    DisplaySettings *displaySettings;
    SceneTextInitParams sceneTextInitParams;

    gWLMenuScene = HeapAllocAligned(heap, 0x874, 0x20);
    WLMenuMI_CpuClearFast(gWLMenuScene, 0x874);
    displaySettings = CreateDisplaySettings(heap, data_02154818);
    WLMenuSetMainBg1Record(displaySettings, 0, 0, 0, 0, 0xc, 0, 0);
    WLMenuSetSubBg3RecordParams(displaySettings, 2, 0, 0, 0, 0xf, 6);
    InitDisplayFromSettings(displaySettings);
    if (WLMenuMB_IsMultiBootChildWrapper() == 0) {
        sceneTextInitParams.mUseTxtSystem = 1;
        sceneTextInitParams.mTxtSystemFont = GetFontByIndex(1);
        sceneTextInitParams.mUseCanvas1 = 0;
        sceneTextInitParams.mUseCanvas2 = 1;
        sceneTextInitParams.mUseCanvas3 = 0;
        sceneTextInitParams.mUseSelectChoises = 0;
        sceneTextInitParams.mSelectChoisesFont = NULL;
        sceneTextInitParams.mUseSelectReturn = 1;
        sceneTextInitParams.mUseBackScreen = GetWLMenuKind() == 0;
        sceneTextInitParams.mBackScreenKind = 0;
        LoadTxtSystemAndSelectChoisesAndSelectReturnData();
        InitSceneText(heap, &sceneTextInitParams);
    }
    InitLinkLevelIcons(heap, gWLMenuScene);
    switch (GetWLMenuKind()) {
        case 0:
            gWLMenuScene->mRequestedCallbacksIndex = WLMenuMB_IsMultiBootChildWrapper() != 0 ? 4 : 0;
            InitWLMenuResetRaceSetup(heap);
            ResetConnection();
            break;
        case 1:
            gWLMenuScene->mRequestedCallbacksIndex = 5;
            InitWLMenuRequestMPState16(heap);
            break;
        case 2:
            gWLMenuScene->mRequestedCallbacksIndex = 6;
            InitWLMenuRequestMPState18(heap);
            break;
        case 3:
            gWLMenuScene->mRequestedCallbacksIndex = 7;
            InitWLMenuRequestMPState21(heap);
            break;
    }
    gWLMenuScene->mCurrentCallbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
    gWLMenuScene->mCurrentCallbacks = gWLMenuCallbacks[gWLMenuScene->mRequestedCallbacksIndex];
    gWLMenuScene->mHeap = CreateExpHeapFromMaxFree(heap);
    if (WLMenuMB_IsMultiBootChildWrapper() == 0) {
        LoadMultiSelectFiles();
    }
    ResetOamLists(gWLMenuScene, gWLMenuScene->mSubOam);
    WLMenuGX_SetOBJVRamModeChar(0x10);
    WLMenuGXS_SetOBJVRamModeChar(0x10);
    gWLMenuScene->mCurrentCallbacks->mInit(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
}

void AdvanceWLMenuScene(void *sceneNumbers) {
    s32 callbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
    WLMenuCallbacks *previousCallbacks;

    if (gWLMenuScene->mCurrentCallbacksIndex != callbacksIndex) {
        previousCallbacks = gWLMenuScene->mCurrentCallbacks;
        gWLMenuScene->mCurrentCallbacks = gWLMenuCallbacks[callbacksIndex];
        gWLMenuScene->mCurrentCallbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
        previousCallbacks->mRelease();
        gWLMenuScene->mCurrentCallbacks->mInit(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
    } else {
        ClearOamListCounts(gWLMenuScene, gWLMenuScene->mSubOam);
        callbacksIndex = gWLMenuScene->mCurrentCallbacks->mAdvance(sceneNumbers);
        if (callbacksIndex != -1) {
            gWLMenuScene->mRequestedCallbacksIndex = callbacksIndex;
        }
        AdvanceLinkLevelIcons();
        HideUnusedOams(gWLMenuScene, gWLMenuScene->mSubOam);
    }
    if (WLMenuMB_IsMultiBootChildWrapper() == 0) {
        AdvanceSceneText();
    }
}

#pragma thumb off

#pragma thumb on

void ReleaseWLMenuScene(void) {
    int isMultiBootChild;
    gWLMenuScene->mCurrentCallbacks->mRelease();
    isMultiBootChild = WLMenuMB_IsMultiBootChildWrapper();
    if (isMultiBootChild == 0) {
        ReleaseSceneText();
    }
    ClearLinkLevelIconsPointer();
}

#pragma thumb off

u16 *WLMenuMB_GetMultiBootParam(void) {
    return &gBootInfo->mUnk_00;
}

u32 WLMenuMB_IsMultiBootChild(void) {
    return *WLMenuMB_GetMultiBootParam() == 2;
}

u32 WLMenuMB_IsMultiBootChildWrapper(void) {
    return WLMenuMB_IsMultiBootChild();
}

#pragma thumb on

void WriteWLMenuSceneRegisters(void) {
    int isMultiBootChild;
    isMultiBootChild = WLMenuMB_IsMultiBootChildWrapper();
    if (isMultiBootChild == 0) {
        WriteSceneTextRegisters();
    }
    gWLMenuScene->mCurrentCallbacks->mWriteRegisters();
    UploadOamLists(gWLMenuScene, gWLMenuScene->mSubOam);
}

WLMenuScanSlotPick *GetWLMenuSceneScanSlotPick(void) {
    return &gWLMenuScene->mScanSlotPick;
}

#pragma thumb off
