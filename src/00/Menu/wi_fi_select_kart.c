#include "00/Menu/wi_fi_select_kart.h"
#include "Main/Menu/select_kart_data.h"

#include "00/Menu/wi_fi_state_machine.h"
#include "00/Lib/wifi_library_globals.h"
#include "Main/System/heap.h"
#include "Main/Net/wifi_connection_lost.h"
#include "00/Menu/wi_fi_vs_setting.h"

WiFiStateCallbacks gSelectKartCallbacks = {InitWiFiSelectKartState, ReleaseWiFiSelectKartState,
                                           AdvanceWiFiSelectKartState, WriteSelectKartRegistersWrapper};
WiFiSelectHeapHolder *gWiFiSelectKartState;

void InitWiFiSelectKartState(void *heap) {
    void *firstOamList;
    void *secondOamList;

    gWiFiSelectKartState = Mem_AllocateHeap(heap, 4);
    gWiFiSelectKartState->mHeap = heap;
    InitWiFiSelectKartNop();
    firstOamList = GetWiFiMenuMainOamList();
    secondOamList = GetWiFiMenuSubOamList();
    InitSelectKart(heap, 2, firstOamList, secondOamList);
}

void ReleaseWiFiSelectKartState(void) {
    ReleaseSelectKart();
    gWiFiSelectKartState = NULL;
}

void InitWiFiSelectKartNop(void) {}

void AdvanceWiFiSelectKartState(void) {
    s32 selectResult;

    selectResult = AdvanceSelectKart();
    if (selectResult == 1 || selectResult == 2) {
        if (IsWiFiConnectionLost() != 0) {
            RequestWiFiState(WIFI_STATE_CONNECTION_LOST);
            return;
        }
        if (selectResult == 1) {
            RequestWiFiState(WIFI_STATE_VS_COURSE_SELECT);
            return;
        }
        if (selectResult == 2) {
            RequestWiFiState(WIFI_STATE_SELECT_CHARACTER);
        }
    }
}

void WriteSelectKartRegistersWrapper(void) {
    u32 unusedValue;
    WriteSelectKartRegisters();
}

void RegisterSelectKartCallbacks(void) {
    WiFiStateCallbacks callbacks = gSelectKartCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
