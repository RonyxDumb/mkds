#include "03/Graphics/oam_buffers.h"
#include "03/Graphics/oam_buffer_entries.h"
#include "03/System/pointer_stack.h"
#include "03/Graphics/obj_char_ranges.h"
#include "03/System/exp_heap.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/System/tasks.h"
#include "code_0214d018.h"
#include "03/Graphics/node_list_delete.h"
#include "03/Graphics/node_list_link.h"
#include "code_0200c914.h"

struct OamBuffers *gOamBuffers;

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

void DeleteOamEntry(OamEntry *entry) {
    OamBuffers *buffers;
    s32 screen = 0;

    entry->mAttr01 = (entry->mAttr01 & OAM_ATTR01_NOT_EFFECT_MASK) | OAM_ATTR01_EFFECT_HIDDEN;
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

void RemoveNodeFromList(void *node) {
    u32 nodeAddress = (((u32) node) + (0x0u));
    u32 savedIrqMask = OS_DisableIrqMask(0x1u);
    u32 next = (*(u32 *) ((nodeAddress) + (4)));
    u32 previous = (*(u32 *) ((nodeAddress) + (0)));
    u32 reloadedPrevious;
    u32 reloadedNext;
    u32 nullLink;
    u32 restoredIrqMask;
    *(u32 *) ((previous) + (4)) = next;
    reloadedPrevious = (*(u32 *) ((nodeAddress) + (0)));
    reloadedNext = (*(u32 *) ((nodeAddress) + (4)));
    *(u32 *) ((reloadedNext) + (0)) = reloadedPrevious;
    *(u32 *) ((nodeAddress) + (4)) = 0x0u;
    nullLink = (*(u32 *) ((nodeAddress) + (4)));
    *(u32 *) ((nodeAddress) + (0)) = nullLink;
    restoredIrqMask = OS_EnableIrqMask(savedIrqMask);
}

void AddNodeBefore(void *node, void *newNode) {
    u32 nodeAddress = (((u32) node) + (0x0u));
    u32 newNodeAddress = (((u32) newNode) + (0x0u));
    u32 savedIrqMask = OS_DisableIrqMask(0x1u);
    u32 previous = (*(u32 *) ((nodeAddress) + (0)));
    u32 reloadedPrevious;
    u32 restoredIrqMask;
    *(u32 *) ((previous) + (4)) = newNodeAddress;
    reloadedPrevious = (*(u32 *) ((nodeAddress) + (0)));
    *(u32 *) ((newNodeAddress) + (0)) = reloadedPrevious;
    *(u32 *) ((newNodeAddress) + (4)) = nodeAddress;
    *(u32 *) ((nodeAddress) + (0)) = newNodeAddress;
    restoredIrqMask = OS_EnableIrqMask(savedIrqMask);
}

void AddNodeToListBack(void *list, void *node) {
    u32 sentinelAddress = (u32) list;
    u32 nodeAddress = (u32) node;
    u32 unused;
    sentinelAddress = (sentinelAddress) + 8u;
    AddNodeBefore((void *) sentinelAddress, node);
}

void AddNodeToListFront(void *list, void *node) {
    u32 firstNode = (u32) list;
    u32 nodeAddress = (u32) node;
    u32 unused;
    firstNode = *(const u32 *) ((firstNode) + 4u);
    AddNodeBefore((void *) firstNode, node);
}
