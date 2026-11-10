#include "Main/Unknown/code_0204ad44.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020487fc.h"
#include "gecom.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "pm.h"
#include "frameheap.h"
#include "Main/Unknown/code_0204aa60.h"

void ReleaseWLMenuSceneCallback(void) {
    u32 unused;
    ReleaseWLMenuScene();
}

void WriteWLMenuSceneRegistersCallback(void) {
    u32 unused;
    WriteWLMenuSceneRegisters();
}

void UpdateWLMenuSceneCallback(void *sceneNumbers) {
    AdvanceWLMenuScene(sceneNumbers);
}

s32 RunWLMenuScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gWLMenuSceneCallbacks;

    RunScene(sceneNumbers, &callbacks);
    return 0;
}

void InitStartupWork(void *heap) {
    u8 *arenaLo;
    u8 *arenaHi;

    arenaLo = OS_GetArenaLo(4);
    arenaHi = OS_GetArenaHi(4);
    gStartupWork = HeapAlloc(heap, 0x7c);
    gStartupWork->mHeap = NNS_FndCreateFrmHeapEx(arenaLo, arenaHi - arenaLo, 1);
    FillStartupWork();
}

void FillStartupWork(void) {
    Unk0200fddc ownerInfo;
    u64 firstTick;
    u64 secondTick;
    StartupWork *startupWork;
    RandomState64 *random;

    OS_GetOwnerInfo(&ownerInfo);
    MI_CpuFill8(gStartupWork->mOwnerText, 0, 0x14);
    gStartupWork->mOwnerCharCount = ownerInfo.mUnk_18;
    MI_CpuCopy8(ownerInfo.mUnk_04, gStartupWork->mOwnerText, gStartupWork->mOwnerCharCount << 1);
    gStartupWork->mUnk_40 = ownerInfo.mUnk_01;
    gStartupWork->mRegion = 1;
    switch (ownerInfo.mUnk_00) {
        case 1:
            gStartupWork->mLanguageIndex = 1;
            break;
        case 2:
            gStartupWork->mLanguageIndex = 2;
            break;
        case 3:
            gStartupWork->mLanguageIndex = 3;
            break;
        case 4:
            gStartupWork->mLanguageIndex = 4;
            break;
        case 5:
            gStartupWork->mLanguageIndex = 5;
            break;
        default:
            gStartupWork->mLanguageIndex = 1;
            break;
    }
    gStartupWork->mConnectionKind = 0;
    gStartupWork->mUnk_28 = -1;
    gStartupWork->mPickedValue = -1;
    gStartupWork->mSoundSetSeqPlaying = 0;
    gStartupWork->mSoundSetPlayerInitialized = 0;
    gStartupWork->mUnk_58 = 0;
    gStartupWork->mUnk_5c = 0;
    NNS_G3dGeUseFastDma(0);
    gStartupWork->mUnk_1c_3 = 0;
    gStartupWork->mUnk_54 = FALSE;
    gStartupWork->mDemoEndedByInput = 0;
    if (gBootInfo->mUnk_00 == 2) {
        gStartupWork->mMultiSimple = 1;
    } else {
        gStartupWork->mMultiSimple = 0;
    }
    firstTick = OS_GetTick();
    secondTick = OS_GetTick();
    startupWork = gStartupWork;
    random = &startupWork->mRandom;
    random->mValue = (u32) ((firstTick << 16) + secondTick);
    random->mMultiplier = 0x5d588b656c078965;
    random->mIncrement = 0x269ec3;
    if (PM_GetBackLight(&startupWork->mFirstBackLightOn, &startupWork->mSecondBackLightOn) == 0) {
        return;
    }
    TrySetBackLights(1, 1);
}
