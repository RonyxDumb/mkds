#include "Main/Unknown/code_02039cbc.h"
#include "Main/Unknown/code_02039e08.h"
#include "Main/Unknown/code_02039e00.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_02146af4.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02057524.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108e94.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02057ed8.h"
#include "Main/Unknown/code_02057ed4.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_020cefa0.h"
#include "Main/Unknown/code_020cef1c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0212b0b8.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "code_0200e77c.h"
#include "code_0214d93c.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_0204ad44.h"
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
    if (gBootInfo->mUnk_00 != 2) {
        InitWiFiSession(backHeap);
    }
    CreateRaceSetupObjects(backHeap);
    InitBackupBuffers(backHeap);
    InitSound(soundBuffer, soundBufferSize, gBootInfo->mUnk_00 != 2);
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
    if (gBootInfo->mUnk_00 == 2) {
        InitArchiveBuffers(firstFrontHeap, secondFrontHeap, thirdFrontHeap);
    }
    ResetRaceSetup();
    InitBackupAccess();
    ResetCurrentOverlay();
    ClearMenuShared();
}
