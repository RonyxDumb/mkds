#include "00/Menu/wi_fi_select_character.h"

#include "00/Menu/wi_fi_state_machine.h"
#include "00/Lib/wifi_library_globals.h"
#include "Main/Menu/select_character.h"
#include "Main/System/heap.h"
#include "Main/Net/wifi_connection_lost.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "Main/Race/race_setup.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/packed_index.h"
#include "Main/Menu/message_screen.h"
#include "Main/Menu/menu_shared_clear.h"

WiFiStateCallbacks gWiFiSelectCharacterCallbacks = {InitWiFiSelectCharacterState, ReleaseWiFiSelectCharacterState,
                                                AdvanceWiFiSelectCharacterState, WriteSelectCharacterRegistersWrapper};
WiFiSelectHeapHolder *gWiFiSelectCharacterState;

void InitWiFiSelectCharacterState(void *heap) {
    void *firstOamList;
    void *secondOamList;
    s32 index;

    gWiFiSelectCharacterState = HeapAlloc(heap, 4);
    gWiFiSelectCharacterState->mHeap = heap;
    InitWiFiSelectCharacterNop();
    if (GetWiFiPrevState() != 5) {
        PackWiFiSessionIndicesWrapper();
        SetRaceSetupCopyEntryIndex((u8) GetPackedIndex(DWC_GetMyAID()));
        SetSessionKartCount(gWiFiSession->mKartCount);
    }
    firstOamList = GetWiFiMenuMainOamList();
    secondOamList = GetWiFiMenuSubOamList();
    InitSelectCharacter(heap, 2, firstOamList, secondOamList);
    SetLinkLevelIconEnabled(1, 1);
    gMenuShared->mOtherKartCountAdded = FALSE;
    for (index = 0; index < 4; index++) {
        gMenuShared->mUnk_5c[index] = 0;
    }
}

void ReleaseWiFiSelectCharacterState(void) {
    ReleaseSelectCharacter();
    gWiFiSelectCharacterState = NULL;
}

void InitWiFiSelectCharacterNop(void) {}

void AdvanceWiFiSelectCharacterState(void) {
    s32 selectResult;

    selectResult = AdvanceSelectCharacter();
    if (selectResult == 1 || selectResult == 3) {
        if (IsWiFiConnectionLost() != 0) {
            RequestWiFiState(WIFI_STATE_CONNECTION_LOST);
            return;
        }
        if (selectResult == 1) {
            RequestWiFiState(WIFI_STATE_SELECT_KART);
        }
        if (selectResult == 3) {
            RequestWiFiState(WIFI_STATE_VS_COURSE_SELECT);
        }
    }
}

void WriteSelectCharacterRegistersWrapper(void) {
    u32 unusedValue;
    WriteSelectCharacterRegisters();
}

void RegisterSelectCharacterCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiSelectCharacterCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
