#include "Main/Unknown/code_020f1a38.h"
#include "Main/System/Heap.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f1d40.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"

#pragma thumb on

void items_initItemParams(void) {
    ItemKind *p;
    enum { K0 } i;
    enum { K1 } j;
    s32 m;
    u32 v;

    p = heap_alloc(proc_getHeap(proc_getCurrent()), 0x930);
    it_sItemParams = p;
    p[0] = it_sKouraGDef;
    p[1] = it_sKouraRDef;
    p[2] = it_sBananaDef;
    p[3] = it_sKinokoDef;
    p[4] = it_sStarDef;
    p[5] = it_sKouraWDef;
    p[6] = it_sThunderDef;
    p[7] = it_sFBoxDef;
    p[8] = it_sItemBoxDef;
    p[9] = it_sBombDef;
    p[10] = it_sGessoDef;
    p[11] = it_sTeresaDef;
    p[12] = it_sKinokoPDef;
    p[13] = it_sKillerDef;
    for (i = 0; i < 0xe; i++) {
        it_sItemParams[i].mDataSize = GetItemKindCopyDataSize(i);
        v = it_sItemParams[i].mGetFarDistanceSquared;
        if (v != 0) {
            v = ((u32(*)(void)) v)();
        } else {
            v = gSfxParams[1].field20;
        }
        it_sItemParams[i].fieldA4 = v;
    }
    m = gRaceMultiConfig->mMode;
    switch (m) {
        case MODE_BATTLE:
            it_sItemParams[8].mLimit = 8;
            break;
        case MODE_MISSION_RUN:
            for (j = 0; j < 0xe; j++) {
                it_sItemParams[j].mLimit = it_sItemParams[j].field8;
            }
            break;
        case 5:
            it_sItemParams[3].mLimit = 0x20;
            break;
    }
}

void ComputeItemKindObjectCounts(void) {
    s32 a[14];
    enum { K0 } i;
    enum { K1 } j;
    s32 n;

    for (i = 0; i < 0xe; i++) {
        it_sItemParams[i].field10 = it_sItemParams[i].mLimit - 1;
        a[i] = 1;
    }
    for (j = 0; j < 0x12; j++) {
        if (it_sItemConfigs[j].mEnabled != FALSE) {
            i = it_sItemConfigs[j].mObjectKind;
            n = it_sItemConfigs[j].mObjectCount;
            if (a[i] < n) {
                a[i] = n;
            }
        }
    }
    for (i = 0; i < 0xe; i++) {
        it_sItemParams[i].field10 = it_sItemParams[i].field10 + a[i];
        it_sItemParams[i].mObjectCount = it_sItemParams[i].field10;
    }
    if (gRaceMultiConfig->mMode == 5) {
        for (i = 0; i < 0xe; i++) {
            it_sItemParams[i].mObjectCount = it_sItemParams[i].mObjectCount + 3;
        }
    } else {
        it_sItemParams[2].mObjectCount = it_sItemParams[2].mObjectCount + 0x10;
    }
}

#pragma thumb off
