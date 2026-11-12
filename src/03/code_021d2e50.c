#include "03/code_021d2e50.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d1cd4.h"
#include "Main/Unknown/code_0214d000.h"
#include "03/code_021d2fa0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"
#include "03/code_021d3488.h"
#include "code_0214d018.h"
#include "03/code_021d2eb8.h"
#include "03/code_021d2e68.h"
#include "code_0200c914.h"

void ReleaseOamBuffers(void) {
    RemoveTaskEntryWrapper(1, gOamBuffers->mUploadTask);
    FreeExpHeapBlockAndClearPointer(&gOamBuffers);
}

OamEntry *CreateOamEntry(int screen, u8 *source) {
    OamEntry *entry;
    entry = PopPointerStack(gOamBuffers->mFreeEntries[screen]);
    MIi_CpuCopy32(source, entry, 8);
    return entry;
}

void DeleteOamEntry(u32 *entry) {
    OamBuffers *buffers;
    s32 screen = 0;

    *entry = (*entry & 0xc1fffcff) | 0x200;
    buffers = gOamBuffers;
    if ((u32) entry >= (u32) buffers + 0x400) {
        screen = 1;
    }
    PushPointerStack(buffers->mFreeEntries[screen], entry);
}

OamEntry *GetOamBufferEntry(int screen, int index) {
    return (OamEntry *) (&gOamBuffers->mBuffers[screen][index * 8]);
}

void *CreateNodeList(void) {
    u32 header = ((u32) AllocExpHeapBlock(0x10u, 0x4u));
    u32 firstEndNode;
    u32 lastEndNode;
    *(u32 *) ((header) + (0)) = 0x0u;
    firstEndNode = ((header) + (0x0u));
    lastEndNode = ((firstEndNode) + (0x8u));
    *(u32 *) ((header) + (4)) = lastEndNode;
    *(u32 *) ((header) + (8)) = header;
    *(u32 *) ((header) + (12)) = 0x0u;
    return (void *) header;
}

void DeleteNodeList(void *block, ...) {
    FreeExpHeapBlockAndClearPointer(&block);
}

void RemoveNodeFromList(u32 node) {
    u32 nodeAddress = ((node) + (0x0u));
    u32 savedIrqMask = OS_DisableIrqMask(0x1u);
    u32 next = (*(u32 *) ((nodeAddress) + (4)));
    u32 previous = (*(u32 *) ((nodeAddress) + (0)));
    u32 reloadedPrevious;
    u32 reloadedNext;
    u32 nullLink;
    u32 v14;
    *(u32 *) ((previous) + (4)) = next;
    reloadedPrevious = (*(u32 *) ((nodeAddress) + (0)));
    reloadedNext = (*(u32 *) ((nodeAddress) + (4)));
    *(u32 *) ((reloadedNext) + (0)) = reloadedPrevious;
    *(u32 *) ((nodeAddress) + (4)) = 0x0u;
    nullLink = (*(u32 *) ((nodeAddress) + (4)));
    *(u32 *) ((nodeAddress) + (0)) = nullLink;
    v14 = OS_EnableIrqMask(savedIrqMask);
}

void AddNodeBefore(u32 node, u32 newNode) {
    u32 nodeAddress = ((node) + (0x0u));
    u32 newNodeAddress = ((newNode) + (0x0u));
    u32 savedIrqMask = OS_DisableIrqMask(0x1u);
    u32 previous = (*(u32 *) ((nodeAddress) + (0)));
    u32 reloadedPrevious;
    u32 v12;
    *(u32 *) ((previous) + (4)) = newNodeAddress;
    reloadedPrevious = (*(u32 *) ((nodeAddress) + (0)));
    *(u32 *) ((newNodeAddress) + (0)) = reloadedPrevious;
    *(u32 *) ((newNodeAddress) + (4)) = nodeAddress;
    *(u32 *) ((nodeAddress) + (0)) = newNodeAddress;
    v12 = OS_EnableIrqMask(savedIrqMask);
}

void AddNodeToListBack(void *list, void *node) {
    u32 value0 = (u32) list;
    u32 nodeAddress = (u32) node;
    u32 unused;
    value0 = (value0) + 8u;
    AddNodeBefore(value0, nodeAddress);
}

void AddNodeToListFront(void *list, void *node) {
    u32 value0 = (u32) list;
    u32 nodeAddress = (u32) node;
    u32 unused;
    value0 = *(const u32 *) ((value0) + 4u);
    AddNodeBefore(value0, nodeAddress);
}
