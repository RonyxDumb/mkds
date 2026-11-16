#include "Main/Unknown/code_0204ad44.h"

#include "Main/System/Heap.h"
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

void wlmenu_finalize(void) {
    u32 unused;
    EndMultiplayerMenu();
}

void wlmenu_vblank(void) {
    u32 unused;
    func_0202f160();
}

void wlmenu_update(void *sceneNumbers) {
    AdvanceWLMenuScene(sceneNumbers);
}

s32 wlmenu_run(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = multiplayerMenu_vtable;

    scene_runScene(sceneNumbers, &callbacks);
    return 0;
}

void sysdat_init(void *heap) {
    u8 *arenaLo;
    u8 *arenaHi;

    arenaLo = OS_GetArenaLo(4);
    arenaHi = OS_GetArenaHi(4);
    gSystemData = heap_alloc(heap, 0x7c);
    gSystemData->mHeap = NNS_FndCreateFrmHeapEx(arenaLo, arenaHi - arenaLo, 1);
    sysdat_initSystemData();
}

void sysdat_initSystemData(void) {
    Unk0200fddc ownerInfo;
    u64 firstTick;
    u64 secondTick;
    Unk021759d0 *p;
    RandomState64 *random;

    OS_GetOwnerInfo(&ownerInfo);
    MI_CpuFill8(gSystemData->mOwnerText, 0, 0x14);
    gSystemData->mOwnerCharCount = ownerInfo.mUnk_18;
    MI_CpuCopy8(ownerInfo.mUnk_04, gSystemData->mOwnerText, gSystemData->mOwnerCharCount << 1);
    gSystemData->mUnk_40 = ownerInfo.mUnk_01;
#ifdef version_EUR
    gSystemData->mUnk_00 = 2;
#else
    gSystemData->mUnk_00 = 1;
#endif
    switch (ownerInfo.mUnk_00) {
        case 1:
            gSystemData->mLanguageIndex = 1;
            break;
        case 2:
            gSystemData->mLanguageIndex = 2;
            break;
        case 3:
            gSystemData->mLanguageIndex = 3;
            break;
        case 4:
            gSystemData->mLanguageIndex = 4;
            break;
        case 5:
            gSystemData->mLanguageIndex = 5;
            break;
        default:
            gSystemData->mLanguageIndex = 1;
            break;
    }
    gSystemData->mUnk_20 = 0;
    gSystemData->mUnk_28 = -1;
    gSystemData->mUnk_44 = -1;
    gSystemData->mSoundSetSeqPlaying = 0;
    gSystemData->mSoundSetPlayerInitialized = 0;
    gSystemData->mUnk_58 = 0;
    gSystemData->mUnk_5c = 0;
    NNS_G3dGeUseFastDma(0);
    gSystemData->mUnk_1c_3 = 0;
    gSystemData->mUnk_54 = FALSE;
    gSystemData->mUnk_50 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        gSystemData->mUnk_1c_2 = 1;
    } else {
        gSystemData->mUnk_1c_2 = 0;
    }
    firstTick = OS_GetTick();
    secondTick = OS_GetTick();
    p = gSystemData;
    random = &p->mRandom;
    random->mValue = (u32) ((firstTick << 16) + secondTick);
    random->mMultiplier = 0x5d588b656c078965;
    random->mIncrement = 0x269ec3;
    if (PM_GetBackLight(&p->mFirstBackLightOn, &p->mSecondBackLightOn) == 0) {
        return;
    }
    sysdat_configureBackLight(1, 1);
}
