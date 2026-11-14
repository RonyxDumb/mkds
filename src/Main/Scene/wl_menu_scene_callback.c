#include "Main/Scene/wl_menu_scene_callback.h"

#include "Main/System/heap.h"
#include "Main/Scene/run_scene_connection.h"
#include "gecom.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0200eddc.h"
#include "os_tick.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "Main/Sound/scene_sound_set.h"
#include "Main/Save/backup_access.h"

SceneCallbacks gWLMenuSceneCallbacks = {InitWLMenuSceneCallback,
                                        UpdateWLMenuSceneCallback,
                                        ReleaseWLMenuSceneCallback,
                                        WriteWLMenuSceneRegistersCallback,
                                        NULL,
                                        NULL,
                                        0xa,
                                        0xa,
                                        0};

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
    OwnerInfo ownerInfo;
    u64 firstTick;
    u64 secondTick;
    StartupWork *startupWork;
    RandomState64 *random;

    OS_GetOwnerInfo(&ownerInfo);
    MI_CpuFill8(gStartupWork->mOwnerText, 0, 0x14);
    gStartupWork->mOwnerCharCount = ownerInfo.mNickNameLength;
    MI_CpuCopy8(ownerInfo.mNickName, gStartupWork->mOwnerText, gStartupWork->mOwnerCharCount << 1);
    gStartupWork->mFavoriteColor = ownerInfo.mFavoriteColor;
    gStartupWork->mRegion = 1;
    switch (ownerInfo.mLanguage) {
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
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
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
