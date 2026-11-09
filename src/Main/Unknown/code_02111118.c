#include "Main/Unknown/code_02111118.h"
#include "Main/Unknown/code_0202a360.h"

#include "Main/Unknown/code_02111158.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0211127c.h"
#include "Main/Unknown/code_021112fc.h"

void func_021112fc(u32 arg0) {
    u32 copy = arg0;
    u32 unused;
    data_0217d32c.mUnk_0c = copy;
}

u32 func_0211127c(void) {
    u32 selector;
    u32 result;
    result = 0xffffffff;
    selector = func_0202a360();
    switch (selector) {
        case 0:
            result = 0x43;
            break;
        case 1:
            result = 0x44;
            break;
        case 2:
            result = 0x3f;
            break;
        case 3:
            result = 0x41;
            break;
        case 4:
            result = 0x40;
            break;
        case 5:
            result = 0x3f;
            break;
        case 6:
            result = 0x41;
            break;
        case 7:
            result = 0x40;
    }
    return result;
}

void CreateSeqRowHeap(void *heapMemory, u32 heapSize) {
    data_0217d32c.mSeqHeap = NNS_SndHeapCreate(heapMemory, heapSize);
    data_0217d32c.mSeqRow = NULL;
}

// Loads the sequences of the row for index a unless that row is already loaded; returns 0 if a load fails.
u32 LoadSeqRowIfChanged(s32 index) {
    Unk0217d32c *state;
    u32 *row;
    NNSSndHeap *savedHeap;
    s32 i;
    savedHeap = data_0217d130;
    state = &data_0217d32c;
    if (index == 4 && (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1) == 9) {
        row = data_0216cbc0;
    } else {
        row = data_0216cbd8[index];
    }
    if (state->mSeqRow == row) {
        return 1;
    }
    data_0217d130 = data_0217d32c.mSeqHeap;
    NNS_SndHeapClear(state->mSeqHeap);
    for (i = 0; i < 6; i++) {
        if (row[i] != 0xff) {
            if (NNS_SndArcLoadSeq(row[i], data_0217d130) == 0) {
                data_0217d130 = savedHeap;
                return 0;
            }
        }
    }
    state->mLoadedIndex = index;
    state->mSeqRow = row;
    data_0217d130 = savedHeap;
    return 1;
}

u32 GetSeqRowSceneSeq(void) {
    return data_0217d32c.mSeqRow[5];
}

u32 ResetRaceEndSeqState(void) {
    data_0217d328 = 0;
    data_0217d324 = 0;
    gRaceEndSeqCallCount = 0;
    return (u32) &gRaceEndSeqCallCount;
}
