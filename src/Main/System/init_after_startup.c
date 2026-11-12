#include "Main/System/init_after_startup.h"
#include "Main/Scene/menu_scene.h"
#include "Main/Scene/return_terminate_for_pulled_out.h"
#include "Main/System/heap_call.h"
#include "code_02146af4.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Net/connection_sharing.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/backup_buffers.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108e94.h"
#include "Main/Race/race_setup_input.h"
#include "Main/System/thread_function_queue_init.h"
#include "Main/System/init_after_startup_nop.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/Menu/menu_shared_create.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/System/result_archive_path.h"
#include "Main/Unknown/code_0212b0b8.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "code_0200e77c.h"
#include "code_0214d93c.h"
#include "Main/Race/race_entries.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/System/archive_slots.h"
#include "Main/Scene/scene_connection.h"
#include "Main/Scene/wl_menu_scene_callback.h"
#include "Main/Unknown/code_0204b714.h"

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
    if (gBootInfo->mBootType != 2) {
        InitWiFiSession(backHeap);
    }
    CreateRaceSetupObjects(backHeap);
    InitBackupBuffers(backHeap);
    InitSound(soundBuffer, soundBufferSize, gBootInfo->mBootType != 2);
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
    if (gBootInfo->mBootType == 2) {
        InitArchiveBuffers(firstFrontHeap, secondFrontHeap, thirdFrontHeap);
    }
    ResetRaceSetup();
    InitBackupAccess();
    ResetCurrentOverlay();
    ClearMenuShared();
}
