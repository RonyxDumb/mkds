#include "Main/System/init_after_startup.h"
#include "Main/Scene/menu_scene.h"
#include "Main/Scene/return_terminate_for_pulled_out.h"
#include "Main/System/heap_call.h"
#include "card_pullOut.h"
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

RaceProgress *gRaceProgress;
InputState *gInputState;
CourseMap *gCourseMap;
InputSlot gInputSlots[10];

void InitAfterStartup(void) {
    void *backHeap;
    void *firstFrontHeap;
    void *secondFrontHeap;
    void *thirdFrontHeap;
    void *soundBuffer;
    u32 soundBufferSize;
    soundBufferSize = CreateFrmHeapsAndAllocSoundBuffer(GetHeap(GetCurrentHeapCall()), &backHeap, &soundBuffer,
                                                        &firstFrontHeap, &secondFrontHeap, &thirdFrontHeap);
    CARD_SetPulledOutCallback(ReturnTerminateForPulledOut);
    CreateRunScenesState(backHeap);
    InitSceneRunState(backHeap);
    InitArchiveSlots(backHeap);
    InitStartupWork(backHeap);
    InitConnection(backHeap);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        InitWiFiSession(backHeap);
    }
    CreateRaceSetupObjects(backHeap);
    InitBackupBuffers(backHeap);
    InitSound(soundBuffer, soundBufferSize, gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT);
    SetSoundOutputEffect(1);
    if (OS_IsRunOnEmulator() == 0) {
        RTC_Init();
    }
    InitInputSlotsAndTouchMic(backHeap);
    CreateBackupAccess(backHeap);
    InitThreadFunctionQueue(backHeap);
    InitOverlayTable(backHeap);
    CreateMenuShared(backHeap);
    InitCompressedArchiveAndMBChild(backHeap);
    InitMessageScreen(backHeap);
    InitAfterStartupNop();
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        InitArchiveBuffers(firstFrontHeap, secondFrontHeap, thirdFrontHeap);
    }
    ResetRaceSetup();
    InitBackupAccess();
    ResetCurrentOverlay();
    ClearMenuShared();
}
