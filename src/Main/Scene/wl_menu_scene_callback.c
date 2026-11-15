#include "Main/Scene/wl_menu_scene_callback.h"

#include "Main/System/heap.h"
#include "Main/Scene/run_scene_connection.h"
#include "gecom.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/backup_net_camera_work.h"
#include "arena_cache_init.h"
#include "os_tick.h"
#include "reset_interrupt_enable.h"
#include "cpu_copy_fill.h"
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
    gStartupWork = HeapAlloc(heap, sizeof(StartupWork));
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
    MI_CpuFill8(gStartupWork->mOwnerText, 0, sizeof(gStartupWork->mOwnerText));
    gStartupWork->mOwnerCharCount = ownerInfo.mNickNameLength;
    MI_CpuCopy8(ownerInfo.mNickName, gStartupWork->mOwnerText, gStartupWork->mOwnerCharCount << 1);
    gStartupWork->mFavoriteColor = ownerInfo.mFavoriteColor;
    gStartupWork->mRegion = 1;
    switch (ownerInfo.mLanguage) {
        case LANGUAGE_ENGLISH:
            gStartupWork->mLanguageIndex = LANGUAGE_ENGLISH;
            break;
        case LANGUAGE_FRENCH:
            gStartupWork->mLanguageIndex = LANGUAGE_FRENCH;
            break;
        case LANGUAGE_GERMAN:
            gStartupWork->mLanguageIndex = LANGUAGE_GERMAN;
            break;
        case LANGUAGE_ITALIAN:
            gStartupWork->mLanguageIndex = LANGUAGE_ITALIAN;
            break;
        case LANGUAGE_SPANISH:
            gStartupWork->mLanguageIndex = LANGUAGE_SPANISH;
            break;
        default:
            gStartupWork->mLanguageIndex = LANGUAGE_ENGLISH;
            break;
    }
    gStartupWork->mConnectionKind = CONNECTION_KIND_NONE;
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
    random->mMultiplier = RANDOM_STATE64_MULTIPLIER;
    random->mIncrement = RANDOM_STATE64_INCREMENT;
    if (PM_GetBackLight(&startupWork->mFirstBackLightOn, &startupWork->mSecondBackLightOn) == 0) {
        return;
    }
    TrySetBackLights(1, 1);
}
