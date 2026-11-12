#include "00/Menu/wi_fi_select_character.h"

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "Main/Menu/select_character.h"
#include "Main/System/heap.h"
#include "Main/Net/wifi_connection_lost.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "Main/Race/race_setup.h"
#include "Main/Net/wifi_session.h"
#include "Main/Net/packed_index.h"
#include "Main/Menu/message_screen.h"
#include "Main/Menu/menu_shared_clear.h"

WiFiStateCallbacks gSelectCharacterCallbacks = {InitWiFiSelectCharacterState, ReleaseWiFiSelectCharacterState, AdvanceWiFiSelectCharacterState, WriteSelectCharacterRegistersWrapper};
WiFiSelectHeapHolder *gWiFiSelectCharacterState;

void InitWiFiSelectCharacterState(void *heap) {
    void *firstOamList;
    void *secondOamList;
    s32 i;

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
    for (i = 0; i < 4; i++) {
        gMenuShared->mUnk_5c[i] = 0;
    }
}

void ReleaseWiFiSelectCharacterState(void) {
    ReleaseSelectCharacter();
    *(u32 *) &gWiFiSelectCharacterState = 0;
}

void InitWiFiSelectCharacterNop(void) {}

void AdvanceWiFiSelectCharacterState(void) {
    s32 selectResult;

    selectResult = AdvanceSelectCharacter();
    if (selectResult == 1 || selectResult == 3) {
        if (IsWiFiConnectionLost() != 0) {
            RequestWiFiState(7);
            return;
        }
        if (selectResult == 1) {
            RequestWiFiState(5);
        }
        if (selectResult == 3) {
            RequestWiFiState(6);
        }
    }
}

void WriteSelectCharacterRegistersWrapper(void) {
    u32 value3;
    WriteSelectCharacterRegisters();
}

void RegisterSelectCharacterCallbacks(void) {
    WiFiStateCallbacks callbacks = gSelectCharacterCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
