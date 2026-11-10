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

void func_0202f478(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | bits;
}

void func_0202f454(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | bits;
}

#pragma thumb on

void InitWLMenuScene(void *heap) {
    DisplaySettings *displaySettings;
    SceneTextInitParams v1;

    gWLMenuScene = HeapAllocAligned(heap, 0x874, 0x20);
    func_0202f51c(gWLMenuScene, 0x874);
    displaySettings = CreateDisplaySettings(heap, data_02154818);
    WLMenuSetMainBg1Record(displaySettings, 0, 0, 0, 0, 0xc, 0, 0);
    WLMenuSetSubBg3RecordParams(displaySettings, 2, 0, 0, 0, 0xf, 6);
    InitDisplayFromSettings(displaySettings);
    if (func_0202f19c() == 0) {
        v1.mUseTxtSystem = 1;
        v1.mTxtSystemFont = GetFontByIndex(1);
        v1.mUseCanvas1 = 0;
        v1.mUseCanvas2 = 1;
        v1.mUseCanvas3 = 0;
        v1.mUseSelectChoises = 0;
        v1.mSelectChoisesFont = NULL;
        v1.mUseSelectReturn = 1;
        v1.mUseBackScreen = GetWLMenuKind() == 0;
        v1.mBackScreenKind = 0;
        LoadTxtSystemAndSelectChoisesAndSelectReturnData();
        InitSceneText(heap, &v1);
    }
    InitLinkLevelIcons(heap, gWLMenuScene);
    switch (GetWLMenuKind()) {
        case 0:
            gWLMenuScene->mRequestedCallbacksIndex = func_0202f19c() != 0 ? 4 : 0;
            func_0203b0f8(heap);
            func_02053d00();
            break;
        case 1:
            gWLMenuScene->mRequestedCallbacksIndex = 5;
            func_0203b1fc(heap);
            break;
        case 2:
            gWLMenuScene->mRequestedCallbacksIndex = 6;
            func_0203b1c8(heap);
            break;
        case 3:
            gWLMenuScene->mRequestedCallbacksIndex = 7;
            func_0203b194(heap);
            break;
    }
    gWLMenuScene->mCurrentCallbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
    gWLMenuScene->mCurrentCallbacks = gWLMenuCallbacks[gWLMenuScene->mRequestedCallbacksIndex];
    gWLMenuScene->mHeap = CreateExpHeapFromMaxFree(heap);
    if (func_0202f19c() == 0) {
        LoadMultiSelectFiles();
    }
    ResetOamLists(gWLMenuScene, gWLMenuScene->mSubOam);
    func_0202f478(0x10);
    func_0202f454(0x10);
    gWLMenuScene->mCurrentCallbacks->mInit(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
}

void AdvanceWLMenuScene(void *a) {
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
        callbacksIndex = gWLMenuScene->mCurrentCallbacks->mAdvance(a);
        if (callbacksIndex != -1) {
            gWLMenuScene->mRequestedCallbacksIndex = callbacksIndex;
        }
        AdvanceLinkLevelIcons();
        HideUnusedOams(gWLMenuScene, gWLMenuScene->mSubOam);
    }
    if (func_0202f19c() == 0) {
        AdvanceSceneText();
    }
}

#pragma thumb off

#pragma thumb on

void ReleaseWLMenuScene(void) {
    int v1;
    gWLMenuScene->mCurrentCallbacks->mRelease();
    v1 = func_0202f19c();
    if (v1 == 0) {
        ReleaseSceneText();
    }
    ClearLinkLevelIconsPointer();
}

#pragma thumb off

u16 *func_0202f1d0(void) {
    return &gBootInfo->mUnk_00;
}

u32 func_0202f1a8(void) {
    return *func_0202f1d0() == 2;
}

u32 func_0202f19c(void) {
    return func_0202f1a8();
}

#pragma thumb on

void WriteWLMenuSceneRegisters(void) {
    int v1;
    v1 = func_0202f19c();
    if (v1 == 0) {
        WriteSceneTextRegisters();
    }
    gWLMenuScene->mCurrentCallbacks->mWriteRegisters();
    UploadOamLists(gWLMenuScene, gWLMenuScene->mSubOam);
}

WLMenuScanSlotPick *GetWLMenuSceneScanSlotPick(void) {
    return &gWLMenuScene->mScanSlotPick;
}

#pragma thumb off
