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

void SetEntryKartFinishResult(u32 finishResult) {
    u32 copy = finishResult;
    u32 unused;
    gSeqRowState.mFinishResult = copy;
}

u32 GetResultSceneSeqId(void) {
    u32 selector;
    u32 result;
    result = 0xffffffff;
    selector = GetResultSceneSeqKind();
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
    gSeqRowState.mSeqHeap = NNS_SndHeapCreate(heapMemory, heapSize);
    gSeqRowState.mSeqRow = NULL;
}

// Loads the sequences of the row for index a unless that row is already loaded; returns 0 if a load fails.
u32 LoadSeqRowIfChanged(s32 index) {
    SeqRowState *state;
    u32 *row;
    NNSSndHeap *savedHeap;
    s32 i;
    savedHeap = gCurrentSndHeap;
    state = &gSeqRowState;
    if (index == 4 && (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1) == 9) {
        row = gMissionRunBossSeqRow;
    } else {
        row = gSeqRowTable[index];
    }
    if (state->mSeqRow == row) {
        return 1;
    }
    gCurrentSndHeap = gSeqRowState.mSeqHeap;
    NNS_SndHeapClear(state->mSeqHeap);
    for (i = 0; i < 6; i++) {
        if (row[i] != 0xff) {
            if (NNS_SndArcLoadSeq(row[i], gCurrentSndHeap) == 0) {
                gCurrentSndHeap = savedHeap;
                return 0;
            }
        }
    }
    state->mLoadedIndex = index;
    state->mSeqRow = row;
    gCurrentSndHeap = savedHeap;
    return 1;
}

u32 GetSeqRowSceneSeq(void) {
    return gSeqRowState.mSeqRow[5];
}

s32 *ResetRaceEndSeqState(void) {
    gRaceEndNextSeqPending = 0;
    gRaceEndSeqStarted = 0;
    gRaceEndSeqCallCount = 0;
    return &gRaceEndSeqCallCount;
}
