#include "03/Menu/selection_objects.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021d5000.h"

#include "03/code_021d1000.h"
#include "03/System/exp_heap.h"
#include "03/unk_021da000.h"

const u8 gSelectionPairImages[8] = {0xa, 0xb, 4, 5, 2, 3, 0xc, 0xd};
OamRange **gSelectionObjects;

void InitSelectionObjects(void) {
    gSelectionObjects = AllocZeroedExpHeapBlock(0x10, 4);
}

void ReleaseSelectionObjects(void) {
    ReleaseSelectionObjectSlots();
    FreeExpHeapBlockAndClearPointer(&gSelectionObjects);
}

void PlaceSelectionPair(u32 pairIndex, u32 leftX, u32 rightX, u32 yPos) {
    s32 i;
    const u8 *objectIds;

    ReleaseSelectionObjectSlots();
    i = 0;
    objectIds = gSelectionPairImages + pairIndex * 2;
    for (; i < 2; i++) {
        gSelectionObjects[i] = CreateOamRangeFromNceImage(0, *objectIds, 1);
        SetOamRangePriority(gSelectionObjects[i], -1, 1);
        objectIds++;
    }
    SetOamRangePosition(gSelectionObjects[0], -1, leftX, yPos);
    SetOamRangePosition(gSelectionObjects[1], -1, rightX, yPos);
}

void PlaceSelectionCorners(u32 left, u32 right, u32 top, u32 bottom) {
    int objectId;
    int count;
    int slot;
    OamRange *object;
    objectId = 6;
    ReleaseSelectionObjectSlots();
    count = 0;
    slot = 0;
    do {
        object = CreateOamRangeFromNceImage(0, objectId, 1);
        gSelectionObjects[slot] = object;
        SetOamRangePriority(gSelectionObjects[slot], 0xffffffff, 1);
        slot = slot + 1;
        count = count + 1;
        objectId = objectId + 1;
    } while (count < 4);
    SetOamRangePosition(gSelectionObjects[0], 0xffffffff, left, top);
    SetOamRangePosition(gSelectionObjects[1], 0xffffffff, right, top);
    SetOamRangePosition(gSelectionObjects[2], 0xffffffff, left, bottom);
    SetOamRangePosition(gSelectionObjects[3], 0xffffffff, right, bottom);
}

void ReleaseSelectionObjectSlots(void) {
    int count;
    int slot;
    OamRange *object;
    count = 0;
    slot = 0;
    do {
        object = gSelectionObjects[slot];
        if (NULL != object) {
            DeleteOamRange(object);
            gSelectionObjects[slot] = NULL;
        }
        slot = slot + 1;
        count = count + 1;
    } while (count < 4);
}
