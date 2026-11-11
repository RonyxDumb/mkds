#include "00/code_02184aa4.h"
#include "Main/Unknown/code_0202a000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"

#include "00/code_02180608.h"
#include "Main/Unknown/code_0202a820.h"
#include "00/code_021832d8.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02029758.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122ae4.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020296f4.h"
#include "Main/Unknown/code_02045874.h"

void InitWiFiVSCourseSelectState(u32 heap) {
    int recordAddress;
    void *firstOamList;
    void *secondOamList;
    recordAddress = ((u32) HeapAlloc((void *) heap, 8));
    *(s32 *) &gWiFiVSCourseSelectState = recordAddress;
    *(u32 *) (recordAddress + 4) = heap;
    InitWiFiVSCourseSelectNop();
    firstOamList = GetWiFiMenuMainOamList();
    secondOamList = GetWiFiMenuSubOamList();
    InitWiFiVSCourseSelect((void *) heap, firstOamList, secondOamList);
    SetLinkLevelIconEnabled(1, 1);
}

void ReleaseWiFiVSCourseSelectState(void) {
    ReleaseWiFiVSCourseSelect();
    *(u32 *) &gWiFiVSCourseSelectState = 0;
}

void InitWiFiVSCourseSelectNop(void) {}

void AdvanceWiFiVSCourseSelectState(void) {
    s32 selectResult;
    u8 kartCount;

    selectResult = AdvanceWiFiVSCourseSelect();
    if (GetWiFiNextScene() == -1 && (selectResult == 1 || selectResult == 2)) {
        if (IsWiFiConnectionLost() != 0) {
            RequestWiFiState(7);
            return;
        }
        kartCount = gWiFiSession->mKartCount;
        GetRaceSetupCopy()->mKartCount = kartCount;
        SetNextRaceSetupFromKartMask();
        if ((u32) gMenuShared->mWiFiMenuStartKind <= 2) {
            AssignCpuNumbersAndSetupFirstCourse();
            AddOtherKartCountToSecondTotal();
            gMenuShared->mOtherKartCountAdded = TRUE;
        }
        CopyRaceSetupCopyToEntries();
        SetWiFiNextScene(2);
        PackWiFiSessionIndicesWrapper();
    }
}

void WriteWiFiVSCourseSelectRegistersWrapper(void) {
    WriteWiFiVSCourseSelectRegisters();
}

void RegisterWiFiVSCourseSelectCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiVSCourseSelectCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
