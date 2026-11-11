#include "Main/Unknown/code_0205dc84.h"
#include "Main/Unknown/code_020365ac.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02036588.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02108ed8.h"
#include "Main/Unknown/code_02108ec4.h"
#include "03/code_021c2000.h"
#include "03/code_021c209c.h"
#include "00/code_021a3000.h"
#include "00/code_021a3760.h"
#include "01/code_021956dc.h"
#include "code_02004dc0.h"
#include "code_0200c914.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "code_02148950.h"
#include "gx.h"
#include "code_021458c4.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "registers.h"

#pragma opt_loop_invariants off

static inline void LoadOverlayAndRunDWCUtility(void *utilityWork, void *overlayId) {
    u8 languageIndex;
    u32 languageValue;
    if (FS_LoadOverlay(0, (u32) overlayId) != 0) {
        OS_SetIrqFunction(1, NULL);
        OS_DisableIrqMask(1);
        reg_OS_IME;
        reg_OS_IME = 0;
        OS_DisableInterrupts();
        GX_VBlankIntr(0);
        func_ov000_021a397c(2);
        languageValue = 1;
        languageIndex = gStartupWork->mLanguageIndex;
        if (languageIndex < 6) {
            languageValue = gDWCUtilityLanguageTable[languageIndex];
        }
        RunMainLoop(utilityWork, languageValue, 0x20);
        EnableVBlankIrq();
        FS_UnloadOverlay(0, (u32) overlayId);
    }
}

// Runs the DWC utility from overlay 3, then rebuilds the sound heaps.
void RunDWCUtility(void) {
    void *expHeapFromMaxFree;
    void *utilityWork;
    void *heap;
    heap = GetHeap(GetCurrentHeapCall());
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (gBootInfo->mUnk_00 != 2 && gRunScenesState->mSndHeapsBuffer != NULL) {
        ReleaseSndHeaps();
        HeapFree(heap, gRunScenesState->mSndHeapsBuffer);
        gRunScenesState->mSndHeapsBuffer = NULL;
    }
    RunScenesSoundNop();
    expHeapFromMaxFree = CreateExpHeapFromMaxFree(heap);
    utilityWork = HeapAllocAligned(expHeapFromMaxFree, 0x40000, 0x20);
    LoadOverlayAndRunDWCUtility(utilityWork, SDK_OVERLAY_OV003_ID);
    HeapDestroy(expHeapFromMaxFree);
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0x10);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0x10);
    WaitIrqAndTurnOnDisplays();
    SetCurrentSndArc();
    heap = HeapAlloc(heap, GetSndHeapsBufferSize(1));
    CreateSndHeaps(1, (u32) heap);
    gRunScenesState->mSndHeapsBuffer = heap;
}

static inline BOOL IsRunScenesNextKindSameOrKindThree(void) {
    if (gRunScenesState->mNextKind == 3 || gRunScenesState->mNextKind == gRunScenesState->mKind) {
        return TRUE;
    }
    return FALSE;
}

s32 RunScenes(s16 *sceneNumber) {
    HeapCall heapCall;
    void *heap;
    InitRunScenesKind();
    while (IsRunScenesNextKindSameOrKindThree()) {
        gRunScenesState->mNextKind = 3;
        gSceneNumbers[0] = gSceneNumbers[1];
        gSceneNumbers[1] = *sceneNumber;
        gSceneNumbers[2] = -1;
        InitHeapCall(&heapCall, gSceneFuncs[*sceneNumber]);
        RunHeapCall(&heapCall, (u32) gSceneNumbers);
        if (gSceneNumbers[2] != -1) {
            *sceneNumber = gSceneNumbers[2];
        } else {
            *sceneNumber = 9;
        }
        switch (gStartupWork->mConnectionKind) {
            case 0:
            case 1:
            case 2:
                gRunScenesState->mNextKind = 0;
                break;
            case 3:
                gRunScenesState->mNextKind = 1;
                break;
            case 4:
                RunDWCUtility();
                gStartupWork->mConnectionKind = 3;
                break;
        }
    }
    heap = GetHeap(GetCurrentHeapCall());
    if (gBootInfo->mUnk_00 != 2 && gRunScenesState->mSndHeapsBuffer != NULL) {
        ReleaseSndHeaps();
        HeapFree(heap, gRunScenesState->mSndHeapsBuffer);
        gRunScenesState->mSndHeapsBuffer = NULL;
    }
    switch (gRunScenesState->mKind) {
        case 0:
            FinishConnectionEnd();
            break;
        case 1:
            DeleteWiFiSessionHeap();
            break;
    }
    return 0;
}

void RunScenesForever(void) {
    HeapCall heapCall;
    gRunScenesState->mSceneNumber = 9;
    gRunScenesState->mKind = 0;
    if (gBootInfo->mUnk_00 == 2) {
        gStartupWork->mConnectionKind = 2;
        gMenuShared->mWLMenuKind = 0;
        gRunScenesState->mSceneNumber = 6;
    }
    do {
        gRunScenesState->mNextKind = 3;
        InitHeapCall(&heapCall, (u32) RunScenes);
        RunHeapCall(&heapCall, (u32) &gRunScenesState->mSceneNumber);
        gRunScenesState->mKind = gRunScenesState->mNextKind;
    } while (1);
}
