#include "00/Menu/wi_fi_vs_course_select.h"
#include "Main/System/heap.h"

#include "00/Menu/wi_fi_state_machine.h"
#include "Main/Menu/wifi_vs_course_select_files.h"
#include "Main/System/interpolation_value.h"
#include "Main/System/heap_call.h"
#include "font_glyph_layout.h"
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
#include "00/Lib/wifi_library_globals.h"
#include "Main/Save/ghost_file_records.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/wifi_connection_lost.h"
#include "Main/Race/race_setup.h"
#include "Main/Race/race_setup_input.h"
#include "Main/Menu/menu_shared_clear.h"

WiFiStateCallbacks gWiFiVSCourseSelectCallbacks = {InitWiFiVSCourseSelectState,
                                                   ReleaseWiFiVSCourseSelectState, AdvanceWiFiVSCourseSelectState,
                                                   WriteWiFiVSCourseSelectRegistersWrapper};
WiFiVSCourseSelectHeapHolder *gWiFiVSCourseSelectState;

void InitWiFiVSCourseSelectState(void *heap) {
    void *firstOamList;
    void *secondOamList;
    gWiFiVSCourseSelectState = HeapAlloc(heap, 8);
    gWiFiVSCourseSelectState->mHeap = heap;
    InitWiFiVSCourseSelectNop();
    firstOamList = GetWiFiMenuMainOamList();
    secondOamList = GetWiFiMenuSubOamList();
    InitWiFiVSCourseSelect(heap, firstOamList, secondOamList);
    SetLinkLevelIconEnabled(1, 1);
}

void ReleaseWiFiVSCourseSelectState(void) {
    ReleaseWiFiVSCourseSelect();
    gWiFiVSCourseSelectState = NULL;
}

void InitWiFiVSCourseSelectNop(void) {}

void AdvanceWiFiVSCourseSelectState(void) {
    s32 selectResult;
    u8 kartCount;

    selectResult = AdvanceWiFiVSCourseSelect();
    if (GetWiFiNextScene() == -1 && (selectResult == 1 || selectResult == 2)) {
        if (IsWiFiConnectionLost() != 0) {
            RequestWiFiState(WIFI_STATE_CONNECTION_LOST);
            return;
        }
        kartCount = gWiFiSession->mKartCount;
        GetRaceSetupCopy()->mKartCount = kartCount;
        SetNextRaceSetupFromKartMask();
        if ((u32) gMenuShared->mWiFiMenuStartKind <= WIFI_MENU_START_SELECT_CHARACTER) {
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
