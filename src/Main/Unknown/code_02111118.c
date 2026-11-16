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

void sub_21112FC(u32 arg0) {
    u32 copy = arg0;
    u32 unused;
    g_GlobalCX.fieldC = copy;
}

u32 snd_getResultSceneSeqId(void) {
    u32 selector;
    u32 result;
    result = 0xffffffff;
    selector = result_getResultType();
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
    g_GlobalCX.mSeqHeap = NNS_SndHeapCreate(heapMemory, heapSize);
    g_GlobalCX.mSeqRow = NULL;
}

// Loads the sequences of the row for index a unless that row is already loaded; returns 0 if a load fails.
u32 LoadSeqRowIfChanged(s32 index) {
    Unk0217d32c *state;
    u32 *row;
    NNSSndHeap *savedHeap;
    s32 i;
    savedHeap = gSndHeapHandle;
    state = &g_GlobalCX;
    if (index == 4 && (gRaceMultiConfig->mMode == MODE_MISSION_RUN ? gRaceMultiConfig->mMissionTableColumn : -1) == 9) {
        row = g_MissionRunBossResultSseqIdTable;
    } else {
        row = g_PerRaceModeResultSseqIdTable[index];
    }
    if (state->mSeqRow == row) {
        return 1;
    }
    gSndHeapHandle = g_GlobalCX.mSeqHeap;
    NNS_SndHeapClear(state->mSeqHeap);
    for (i = 0; i < 6; i++) {
        if (row[i] != 0xff) {
            if (NNS_SndArcLoadSeq(row[i], gSndHeapHandle) == 0) {
                gSndHeapHandle = savedHeap;
                return 0;
            }
        }
    }
    state->mLoadedIndex = index;
    state->mSeqRow = row;
    gSndHeapHandle = savedHeap;
    return 1;
}

u32 snd_getRaceStartSeqId(void) {
    u32 value;
    value = (u32) &g_GlobalCX;
    value = *(const u32 *) ((value) + (8));
    value = *(const u32 *) ((value) + (20));
    return value;
}

u32 sub_2111118(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    value2 = (u32) &data_0217d328;
    value3 = 0u;
    value1 = (u32) &data_0217d324;
    value0 = (u32) &data_0217d320;
    *(u32 *) ((value2) + (0)) = value3;
    *(u32 *) ((value1) + (0)) = value3;
    *(u32 *) ((value0) + (0)) = value3;
    return value0;
}
