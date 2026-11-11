#include "00/code_021849e0.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_02027e78.h"

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02122ae4.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02028130.h"
#include "Main/Unknown/code_02028864.h"

void InitWiFiSelectKartState(void *heap) {
    void *firstOamList;
    void *secondOamList;

    gWiFiSelectKartState = HeapAlloc(heap, 4);
    gWiFiSelectKartState->mHeap = heap;
    InitWiFiSelectKartNop();
    firstOamList = func_ov000_021804f4();
    secondOamList = func_ov000_021804e0();
    InitSelectKart(heap, 2, firstOamList, secondOamList);
}

void ReleaseWiFiSelectKartState(void) {
    ReleaseSelectKart();
    *(u32 *) &gWiFiSelectKartState = 0;
}

void InitWiFiSelectKartNop(void) {}

void AdvanceWiFiSelectKartState(void) {
    s32 selectResult;

    selectResult = AdvanceSelectKart();
    if (selectResult == 1 || selectResult == 2) {
        if (IsWiFiConnectionLost() != 0) {
            RequestWiFiState(7);
            return;
        }
        if (selectResult == 1) {
            RequestWiFiState(6);
            return;
        }
        if (selectResult == 2) {
            RequestWiFiState(4);
        }
    }
}

void WriteSelectKartRegistersWrapper(void) {
    u32 value3;
    WriteSelectKartRegisters();
}

void RegisterSelectKartCallbacks(void) {
    WiFiStateCallbacks callbacks = gSelectKartCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
