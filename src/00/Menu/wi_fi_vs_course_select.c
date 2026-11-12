#include "00/Menu/wi_fi_vs_course_select.h"
#include "Main/System/heap.h"

#include "00/code_02180608.h"
#include "Main/Menu/wifi_vs_course_select_files.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/multi_select_member_group.h"
#include "tp.h"
#include "Main/Save/buddy_record_time.h"
#include "g2d_CellTransferManager.h"
#include "Main/MapObjects/map_object_park.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/unk_021b4000.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/wifi_connection_lost.h"
#include "Main/Race/race_setup.h"
#include "Main/Race/course_list.h"

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
