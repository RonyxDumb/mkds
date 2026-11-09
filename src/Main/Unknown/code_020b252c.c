#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020364e0.h"

#include "Main/Unknown/code_020b2540.h"
#include "Main/Unknown/code_020b255c.h"
#include "Main/Unknown/code_020b2c68.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on

void UpdateChoisesSScreenMap(void) {
    int isOpen;
    isOpen = IsChoisesSOpen();
    if (isOpen != 0) {
        WriteChoisesSListScreenMap();
    }
}

#pragma thumb off

void *ChoisesSGetCurrentHeap(void) {
    return GetHeap(GetCurrentHeapCall());
}

u32 ChoisesSGetCurrentMode(void) {
    return (gRaceSetup->mMode);
}
