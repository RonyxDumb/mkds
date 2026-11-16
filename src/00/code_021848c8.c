#include "00/code_021848c8.h"
#include "Main/Unknown/code_02026000.h"

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_02122ae4.h"
#include "00/code_021832d8.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_0212a910.h"

void InitWiFiSelectCharacterState(void *a) {
    void *b;
    void *c;
    s32 i;

    gWiFiSelectCharacterState = heap_alloc(a, 4);
    gWiFiSelectCharacterState->mHeap = a;
    func_ov000_02184934();
    if (GetWiFiPrevState() != 5) {
        func_02122728();
        SetRaceSetupCopyEntryIndex((u8) GetPackedIndex(func_ov000_0219bb50()));
        SetSessionKartCount(gStruct217D384->mKartCount);
    }
    b = func_ov000_021804f4();
    c = test_run();
    menucs_init(a, 2, b, c);
    SetLinkLevelIconEnabled(1, 1);
    gStruct217B488->mUnk_6c = FALSE;
    for (i = 0; i < 4; i++) {
        gStruct217B488->mUnk_5c[i] = 0;
    }
}

void ReleaseWiFiSelectCharacterState(void) {
    ReleaseSelectCharacter();
    *(u32 *) &gWiFiSelectCharacterState = 0;
}

void func_ov000_02184934(void) {}

void AdvanceWiFiSelectCharacterState(void) {
    s32 a;

    a = menucs_render();
    if (a == 1 || a == 3) {
        if (func_02122ae4() != 0) {
            RequestWiFiState(7);
            return;
        }
        if (a == 1) {
            RequestWiFiState(5);
        }
        if (a == 3) {
            RequestWiFiState(6);
        }
    }
}

void func_ov000_021848ec(void) {
    u32 value3;
    menucs_2026058();
}

void RegisterSelectCharacterCallbacks(void) {
    WiFiStateCallbacks callbacks = gSelectCharacterCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
