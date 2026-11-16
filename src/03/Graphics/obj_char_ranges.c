#include "03/Graphics/obj_char_ranges.h"
#include "03/System/pointer_stack.h"
#include "03/System/pointer_stack_filled.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/oam_buffers.h"
#include "03/Graphics/node_list_link.h"
#include "03/Graphics/oam_buffer_entries.h"
#include "03/System/tasks.h"
#include "03/Menu/wifi_menu_shared.h"
#include "interrupt_control.h"
#include "arena_cache_init.h"
#include "reset_interrupts_halt.h"
#include "vram_load_2d_graphics.h"
#include "cpu_copy_fill.h"

struct ObjCharRanges *gObjCharRanges;

void InitObjCharRanges(void) {
    s32 rangeIndex;

    gObjCharRanges = AllocZeroedExpHeapBlock(0x340, 4);
    for (rangeIndex = 0; rangeIndex < 2; rangeIndex++) {
        gObjCharRanges[rangeIndex].mFreeRanges = CreateFilledPointerStack(0x20, &gObjCharRanges[rangeIndex], 0xc);
        gObjCharRanges[rangeIndex].mList = CreateNodeList();
        gObjCharRanges[rangeIndex].mListStart.mStart = OBJ_CHAR_RANGE_FIRST_UNIT;
        gObjCharRanges[rangeIndex].mListEnd.mStart = OBJ_CHAR_RANGE_END_UNIT;
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
    savedIrqMask = Os_DisableIrqHandler(1);
    if (fromFront != 0) {
        ranges = gObjCharRanges;
        node = &ranges[screen].mListStart;
        if (node != &ranges[screen].mListEnd) {
            do {
                neighbor = node->mNext;
                start = node->mStart + node->mLength;
                if (start + unitCount <= neighbor->mStart) {
                    range->mStart = start;
                    AddNodeBefore(neighbor, range);
                    break;
                }
                node = neighbor;
            } while (node != &ranges[screen].mListEnd);
        }
        if (node == &gObjCharRanges[screen].mListEnd) {
            Os_Terminate();
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
                    AddNodeBefore(node, range);
                    break;
                }
                node = neighbor;
            } while (node != &ranges[screen].mListStart);
        }
        if (node == &gObjCharRanges[screen].mListStart) {
            Os_Terminate();
        }
    }
    *outStart = range->mStart;
    Os_EnableIrqHandler(savedIrqMask);
    return range;
}

void DeleteObjCharRange(ObjCharRange *range) {
    ObjCharRanges *ranges;
    s32 screen = 0;

    RemoveNodeFromList(range);
    ranges = gObjCharRanges;
    if ((u32) range >= (u32) ranges + 0x1a0) {
        screen = 1;
    }
    PushPointerStack(ranges[screen].mFreeRanges, range);
}

void InitOamBuffers(void) {
    OamBuffers *buffers = AllocExpHeapBlock(0x80c, 4);
    vu32 fillValue;
    s32 bufferIndex;

    gOamBuffers = buffers;
    fillValue = 0x200;
    Mem_CpuFastMemorySet(fillValue, buffers, 0x800);
    for (bufferIndex = 0; bufferIndex < 2; bufferIndex++) {
        gOamBuffers->mFreeEntries[bufferIndex] = CreateFilledPointerStack(0x40, gOamBuffers->mBuffers[bufferIndex], 8);
    }
    gOamBuffers->mUploadTask = AddTask(1, UploadOamBuffers, NULL, 200);
}

void UploadOamBuffers(TaskEntry *task, void *arg) {
    Arm_FlushRange((u8 *) gOamBuffers, 0x800);
    CopyToOamA(gOamBuffers->mBuffers[0], 0, 0x400);
    CopyToOamB(gOamBuffers->mBuffers[1], 0, 0x400);
}
