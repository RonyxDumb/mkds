#include "Main/System/init_after_startup.h"
#include "Main/Scene/menu_scene.h"
#include "Main/Scene/return_terminate_for_pulled_out.h"
#include "Main/System/heap_call.h"
#include "card_removal_handling.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/backup_buffers.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Race/race_setup_input.h"
#include "Main/System/thread_function_queue_init.h"
#include "Main/System/init_after_startup_nop.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/Menu/menu_shared_create.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/message_screen.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Menu/select_race_rule_state.h"
#include "thread_mutex_types.h"
#include "clock_chip_access.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/archive_slots.h"
#include "Main/Scene/scene_connection.h"
#include "Main/Scene/wl_menu_scene_callback.h"
#include "Main/Save/backup_read_copies.h"

RaceProgress *g_GlobalMV;
InputState *g_Global5624;
CourseMap *g_GlobalPE;
InputSlot g_GlobalCYT[10];

void InitializeGeneralObjects(void) {
    void *backHeap;
    void *firstFrontHeap;
    void *secondFrontHeap;
    void *thirdFrontHeap;
    void *soundBuffer;
    u32 soundBufferSize;
    soundBufferSize = AllocateHeapsAndBuffers(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), &backHeap, &soundBuffer,
                                                        &firstFrontHeap, &secondFrontHeap, &thirdFrontHeap);
    Card_SetUserCardPulledOutCallback(InitGlobal_UserCardPulledOutCallback);
    InitializeSceneOverlayConfig(backHeap);
    InitializeGlobalZM(backHeap);
    CreateMountManager_from_thumb(backHeap);
    InitializeGlobalP(backHeap);
    InitializeGlobalZE(backHeap);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        InitializeGlobalB_from_thumb(backHeap);
    }
    InitializeGlobalCO(backHeap);
    InitializeSaveDataHolder_from_thumb(backHeap);
    InitializeAudio(soundBuffer, soundBufferSize, gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT);
    SetSoundOutputEffect(1);
    if (Os_IsEmulator() == 0) {
        Rtc_Initialize();
    }
    Input_Initialize(backHeap);
    InitializeSaveDataIoManager_from_thumb(backHeap);
    InitializeWorker(backHeap);
    InitializeOverlayManager(backHeap);
    InitializeGlobalB488_from_thumb(backHeap);
    LoadEmbeddedStatic2DArchive_from_thumb(backHeap);
    InitializeGlobal1A44_from_thumb(backHeap);
    nullsub_5();
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        SpecialDwcSetMountDatas_from_thumb(firstFrontHeap, secondFrontHeap, thirdFrontHeap);
    }
    PopulateGlobalCO();
    InitializePrepareBackup_from_thumb();
    ResetOverlayManager();
    CreateGlobalB488_from_thumb();
}
