#include "03/Graphics/obj_char_ranges.h"
#include "03/System/pointer_stack.h"
#include "03/code_021d1d60.h"
#include "03/code_021d1000.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/oam_buffers.h"
#include "03/code_021d2e68.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d3000.h"
#include "03/System/tasks.h"
#include "03/unk_021da000.h"
#include "code_0200c914.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "gx_load2d.h"
#include "code_0214d018.h"

struct ObjCharRanges *gObjCharRanges;

void InitObjCharRanges(void) {
    s32 rangeIndex;

    gObjCharRanges = AllocZeroedExpHeapBlock(0x340, 4);
    for (rangeIndex = 0; rangeIndex < 2; rangeIndex++) {
        gObjCharRanges[rangeIndex].mFreeRanges = CreateFilledPointerStack(0x20, &gObjCharRanges[rangeIndex], 0xc);
        gObjCharRanges[rangeIndex].mList = CreateNodeList();
        gObjCharRanges[rangeIndex].mListStart.mStart = 0x300;
        gObjCharRanges[rangeIndex].mListEnd.mStart = 0x400;
        AddNodeToListFront(gObjCharRanges[rangeIndex].mList, &gObjCharRanges[rangeIndex].mListStart);
        AddNodeToListBack(gObjCharRanges[rangeIndex].mList, &gObjCharRanges[rangeIndex].mListEnd);
    }
}

ObjCharRange *CreateObjCharRange(u32 screen, s32 charCount, s32 fromFront, u32 *outStart) {
    ObjCharRange *range;
    ObjCharRange *node;
    ObjCharRange *neighbor;
    ObjCharRanges *ranges;
    s32 start;
    s32 unitCount;
    u32 savedIrqMask;

    range = PopPointerStack(gObjCharRanges[screen].mFreeRanges);
    unitCount = (charCount + 3 & ~3) >> 2;
    range->mLength = unitCount;
    savedIrqMask = OS_DisableIrqMask(1);
    if (fromFront != 0) {
        ranges = gObjCharRanges;
        node = &ranges[screen].mListStart;
        if (node != &ranges[screen].mListEnd) {
            do {
                neighbor = node->mNext;
                start = node->mStart + node->mLength;
                if (start + unitCount <= neighbor->mStart) {
                    range->mStart = start;
                    AddNodeBefore((u32) neighbor, (u32) range);
                    break;
                }
                node = neighbor;
            } while (node != &ranges[screen].mListEnd);
        }
        if (node == &gObjCharRanges[screen].mListEnd) {
            OS_Terminate();
        }
    } else {
        ranges = gObjCharRanges;
        node = &ranges[screen].mListEnd;
        if (node != &ranges[screen].mListStart) {
            do {
                neighbor = node->mPrev;
                start = node->mStart - unitCount;
                if (start >= neighbor->mStart + neighbor->mLength) {
                    range->mStart = start;
                    AddNodeBefore((u32) node, (u32) range);
                    break;
                }
                node = neighbor;
            } while (node != &ranges[screen].mListStart);
        }
        if (node == &gObjCharRanges[screen].mListStart) {
            OS_Terminate();
        }
    }
    *outStart = range->mStart;
    OS_EnableIrqMask(savedIrqMask);
    return range;
}

void DeleteObjCharRange(u32 range) {
    ObjCharRanges *ranges;
    s32 screen = 0;

    RemoveNodeFromList(range);
    ranges = gObjCharRanges;
    if (range >= (u32) ranges + 0x1a0) {
        screen = 1;
    }
    PushPointerStack(ranges[screen].mFreeRanges, (void *) range);
}

void InitOamBuffers(void) {
    OamBuffers *buffers = AllocExpHeapBlock(0x80c, 4);
    vu32 fillValue;
    s32 bufferIndex;

    gOamBuffers = buffers;
    fillValue = 0x200;
    MIi_CpuClearFast(fillValue, buffers, 0x800);
    for (bufferIndex = 0; bufferIndex < 2; bufferIndex++) {
        gOamBuffers->mFreeEntries[bufferIndex] = CreateFilledPointerStack(0x40, gOamBuffers->mBuffers[bufferIndex], 8);
    }
    gOamBuffers->mUploadTask = AddTask(1, UploadOamBuffers, NULL, 200);
}

void UploadOamBuffers(void) {
    DC_FlushRange((u8 *) gOamBuffers, 0x800);
    GX_LoadOAM(gOamBuffers->mBuffers[0], 0, 0x400);
    GXS_LoadOAM(gOamBuffers->mBuffers[1], 0, 0x400);
}
