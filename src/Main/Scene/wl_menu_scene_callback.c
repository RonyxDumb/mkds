#include "Main/Scene/wl_menu_scene_callback.h"

#include "Main/System/heap.h"
#include "Main/Scene/run_scene_connection.h"
#include "geometry_function_tables_and_fast_dma.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Menu/wl_menu_scene.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/backup_net_camera_work.h"
#include "arena_cache_init.h"
#include "tick_counter.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"
#include "Main/Sound/scene_sound_set.h"
#include "Main/Save/backup_access.h"

SceneCallbacks g_Scene_WLMenu = {Scene_WLMenu_Initialize,
                                        Scene_WLMenu_Update,
                                        Scene_WLMenu_Finalize,
                                        Scene_WLMenu_Vblank,
                                        NULL,
                                        NULL,
                                        0xa,
                                        0xa,
                                        0};

void Scene_WLMenu_Finalize(void) {
    u32 unused;
    Scene_WLMenu_FinalizeImpl_from_thumb();
}

void Scene_WLMenu_Vblank(void) {
    u32 unused;
    Scene_WLMenu_VblankImpl_from_thumb();
}

void Scene_WLMenu_Update(void *sceneNumbers) {
    Scene_WLMenu_UpdateImpl_from_thumb(sceneNumbers);
}

s32 SceneFn_WLMenu(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = g_Scene_WLMenu;

    OnSceneLoop(sceneNumbers, &callbacks);
    return 0;
}

void InitializeGlobalP(void *heap) {
    u8 *arenaLo;
    u8 *arenaHi;

    arenaLo = Os_GetMemoryRegionStartAddress(4);
    arenaHi = Os_GetMemoryRegionEndAddress(4);
    g_GlobalP = Mem_AllocateHeap(heap, sizeof(StartupWork));
    g_GlobalP->mHeap = Mem_Frame_Create(arenaLo, arenaHi - arenaLo, 1);
    InitializeGlobalPImpl();
}

void InitializeGlobalPImpl(void) {
    OwnerInfo ownerInfo;
    u64 firstTick;
    u64 secondTick;
    StartupWork *startupWork;
    RandomState64 *random;

    Os_GetPersonalData(&ownerInfo);
    Mem_CpuFill8(g_GlobalP->mOwnerText, 0, sizeof(g_GlobalP->mOwnerText));
    g_GlobalP->mOwnerCharCount = ownerInfo.mNickNameLength;
    Mem_CpuCopy8(ownerInfo.mNickName, g_GlobalP->mOwnerText, g_GlobalP->mOwnerCharCount << 1);
    g_GlobalP->mFavoriteColor = ownerInfo.mFavoriteColor;
#ifdef version_EUR
    g_GlobalP->mRegion = 2;
#else
    g_GlobalP->mRegion = 1;
#endif
    switch (ownerInfo.mLanguage) {
        case LANGUAGE_ENGLISH:
            g_GlobalP->mLanguageIndex = LANGUAGE_ENGLISH;
            break;
        case LANGUAGE_FRENCH:
            g_GlobalP->mLanguageIndex = LANGUAGE_FRENCH;
            break;
        case LANGUAGE_GERMAN:
            g_GlobalP->mLanguageIndex = LANGUAGE_GERMAN;
            break;
        case LANGUAGE_ITALIAN:
            g_GlobalP->mLanguageIndex = LANGUAGE_ITALIAN;
            break;
        case LANGUAGE_SPANISH:
            g_GlobalP->mLanguageIndex = LANGUAGE_SPANISH;
            break;
        default:
            g_GlobalP->mLanguageIndex = LANGUAGE_ENGLISH;
            break;
    }
    g_GlobalP->mConnectionKind = CONNECTION_KIND_NONE;
    g_GlobalP->mUnk_28 = -1;
    g_GlobalP->mPickedValue = -1;
    g_GlobalP->mSoundSetSeqPlaying = 0;
    g_GlobalP->mSoundSetPlayerInitialized = 0;
    g_GlobalP->mUnk_58 = 0;
    g_GlobalP->mUnk_5c = 0;
    NNS_G3dGeUseFastDma(0);
    g_GlobalP->mUnk_1c_3 = 0;
    g_GlobalP->mUnk_54 = FALSE;
    g_GlobalP->mDemoEndedByInput = 0;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        g_GlobalP->mMultiSimple = 1;
    } else {
        g_GlobalP->mMultiSimple = 0;
    }
    firstTick = Os_GetTick();
    secondTick = Os_GetTick();
    startupWork = g_GlobalP;
    random = &startupWork->mRandom;
    random->mValue = (u32) ((firstTick << 16) + secondTick);
    random->mMultiplier = RANDOM_STATE64_MULTIPLIER;
    random->mIncrement = RANDOM_STATE64_INCREMENT;
    if (PM_GetBackLight(&startupWork->mFirstBackLightOn, &startupWork->mSecondBackLightOn) == 0) {
        return;
    }
    TrySetBackLights(1, 1);
}
