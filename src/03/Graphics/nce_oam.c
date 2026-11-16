#include "03/Graphics/nce_oam.h"
#include "03/Graphics/nce_file.h"
#include "03/Menu/wifi_menu_shared.h"
#include "03/Graphics/oam_buffer_entries.h"
#include "03/System/wifi_utility_archive.h"
#include "cpu_copy_clear_16.h"
#include "cpu_copy_fill.h"
#include "03/Graphics/oam_range.h"
#include "03/Graphics/oam_range_entry.h"
#include "03/System/pointer_stack.h"
#include "03/System/pointer_stack_delete.h"
#include "03/System/pointer_stack_filled.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/oam_buffers.h"
#include "03/Graphics/node_list_link.h"
#include "03/Graphics/node_list_delete.h"
#include "interrupt_control.h"
#include "reset_interrupts_halt.h"
#include "03/Graphics/oam_range_set.h"

OamRanges *gOamRanges;
NceImage *gNceFiles[2];

void LoadNceFile(u32 slot, const u8 *path) {
    u32 size;

    gNceFiles[slot] = LoadFile(path, &size, 4);
}

void FreeNceFile(u32 slot) {
    DeleteLoadedFile(gNceFiles[slot]);
    gNceFiles[slot] = NULL;
}

void CopyNceImageToOamEntries(u32 slot, u32 imageIndex, OamEntry *destination) {
    NceImage *file = gNceFiles[slot];
    u8 *source = (u8 *) file + file[imageIndex].mEntriesOffset;
    u16 entryCount = file[imageIndex].mEntryCount;
    s32 entryIndex;
    u8 buffer[8];
    volatile u32 clearValue = 0;

    MIi_CpuClear32(clearValue, buffer, 8);
    for (entryIndex = 0; entryIndex < entryCount; entryIndex++, source += 6, destination++) {
        MIi_CpuCopy16(source, buffer, 6);
        MIi_CpuCopy32(buffer, destination, 8);
    }
}

void *CreateOamEntryFromNceImage(u32 screen, u32 imageIndex) {
    OamEntry *entry;
    u8 source[8];
    entry = CreateOamEntry(screen, source);
    CopyNceImageToOamEntries(screen, imageIndex, entry);
    return entry;
}

OamRange *CreateOamRangeFromNceImage(u32 screen, u32 imageIndex, s32 fromFront) {
    OamRange *range = CreateOamRange(screen, gNceFiles[screen][imageIndex].mEntryCount, fromFront);

    CopyNceImageToOamEntries(screen, imageIndex, GetOamRangeEntry(range, 0));
    return range;
}

void InitOamRanges(void) {
    s32 bufferIndex;

    gOamRanges = AllocZeroedExpHeapBlock(0x450, 4);
    for (bufferIndex = 0; bufferIndex < 2; bufferIndex++) {
        gOamRanges[bufferIndex].mFreeRanges = CreateFilledPointerStack(0x20, &gOamRanges[bufferIndex], 0x10);
        gOamRanges[bufferIndex].mNodeList = CreateNodeList();
        gOamRanges[bufferIndex].mListStart.mEntries = GetOamBufferEntry(bufferIndex, 0x40);
        gOamRanges[bufferIndex].mListEnd.mEntries = GetOamBufferEntry(bufferIndex, 0x7f) + 1;
        AddNodeToListFront(gOamRanges[bufferIndex].mNodeList, &gOamRanges[bufferIndex].mListStart);
        AddNodeToListBack(gOamRanges[bufferIndex].mNodeList, &gOamRanges[bufferIndex].mListEnd);
    }
}

void ReleaseOamRanges(void) {
    s32 bufferIndex;

    for (bufferIndex = 0; bufferIndex < 2; bufferIndex++) {
        DeleteNodeList(gOamRanges[bufferIndex].mNodeList);
        DeletePointerStack(gOamRanges[bufferIndex].mFreeRanges);
    }
    FreeExpHeapBlockAndClearPointer(&gOamRanges);
}

OamRange *CreateOamRange(u32 screen, s32 entryCount, s32 fromFront) {
    OamRange *range;
    u32 interrupts;
    OamRange *node;
    OamRange *neighbor;
    OamEntry *start;

    range = PopPointerStack(gOamRanges[screen].mFreeRanges);
    interrupts = OS_DisableIrqMask(1);
    if (fromFront != 0) {
        node = &gOamRanges[screen].mListStart;
        if (node != &gOamRanges[screen].mListEnd) {
            do {
                neighbor = node->mNext;
                start = node->mEntries + node->mEntryCount;
                if (start + entryCount <= neighbor->mEntries) {
                    range->mEntries = start;
                    AddNodeBefore(neighbor, range);
                    break;
                }
                node = neighbor;
            } while (node != &gOamRanges[screen].mListEnd);
        }
        if (node == &gOamRanges[screen].mListEnd) {
            OS_Terminate();
        }
    } else {
        node = &gOamRanges[screen].mListEnd;
        if (node != &gOamRanges[screen].mListStart) {
            do {
                neighbor = node->mPrev;
                start = node->mEntries - entryCount;
                if (start >= neighbor->mEntries + neighbor->mEntryCount) {
                    range->mEntries = start;
                    AddNodeBefore(node, range);
                    break;
                }
                node = neighbor;
            } while (node != &gOamRanges[screen].mListStart);
        }
        if (node == &gOamRanges[screen].mListStart) {
            OS_Terminate();
        }
    }
    OS_EnableIrqMask(interrupts);
    range->mEntryCount = entryCount;
    return range;
}

void DeleteOamRange(OamRange *range) {
    OamEntry *entries = range->mEntries;
    u32 screen = 0;
    s32 entryIndex;

    for (entryIndex = 0; entryIndex < range->mEntryCount; entryIndex++, entries++) {
        entries->mAttr01 = (entries->mAttr01 & OAM_ENTRY_NOT_EFFECT_AND_AFFINE_INDEX_MASK) | OAM_ENTRY_EFFECT_HIDDEN;
    }
    RemoveNodeFromList(range);
    if (range >= &gOamRanges[1].mRanges[0]) {
        screen = 1;
    }
    PushPointerStack(gOamRanges[screen].mFreeRanges, range);
}

OamEntry *GetOamRangeEntry(OamRange *range, int index) {
    return &range->mEntries[index];
}

u8 GetOamRangeEntryCount(OamRange *range) {
    return range->mEntryCount;
}

static inline void G2_GetOBJPosition(OamEntry *oam, u32 *x, u32 *y) {
    *x = (oam->mAttr01 & OAM_ENTRY_X_POSITION_MASK) >> 16;
    *y = oam->mAttr01 & OAM_ENTRY_Y_POSITION_MASK;
}

void SetOamRangeEffect(OamRange *range, s32 index, u32 effect, u32 affineIndex) {
    OamEntry *entries = range->mEntries;
    s32 entryIndex;

    if (index >= 0) {
        if (effect != OAM_ENTRY_EFFECT_TAKES_AFFINE_INDEX && effect != OAM_ENTRY_EFFECT_TAKES_AFFINE_INDEX_BOTH_BITS) {
            u32 word = entries[index].mAttr01;

            entries[index].mAttr01 = (word & OAM_ENTRY_NOT_EFFECT_AND_AFFINE_INDEX_MASK) | effect;
        } else {
            u32 word = entries[index].mAttr01;

            entries[index].mAttr01 =
                (affineIndex << 25) | ((word & OAM_ENTRY_NOT_EFFECT_AND_AFFINE_INDEX_MASK) | effect);
        }
    } else {
        for (entryIndex = 0; entryIndex < range->mEntryCount; entryIndex++) {
            if (effect != OAM_ENTRY_EFFECT_TAKES_AFFINE_INDEX && effect != OAM_ENTRY_EFFECT_TAKES_AFFINE_INDEX_BOTH_BITS) {
                entries->mAttr01 = (entries->mAttr01 & OAM_ENTRY_NOT_EFFECT_AND_AFFINE_INDEX_MASK) | effect;
            } else {
                entries->mAttr01 = (affineIndex << 25)
                    | ((entries->mAttr01 & OAM_ENTRY_NOT_EFFECT_AND_AFFINE_INDEX_MASK) | effect);
            }
            entries++;
        }
    }
}

void SetOamRangeMode(OamRange *range, s32 index, u32 mode, u32 colorParam) {
    s32 entryIndex;
    OamEntry *entries = range->mEntries;

    if (index >= 0) {
        u32 attr01 = entries[index].mAttr01;
        u32 attr2;

        entries[index].mAttr01 = (attr01 & 0xfffff3ff) | (mode << 10);
        attr2 = entries[index].mAttr2;
        entries[index].mAttr2 = (attr2 & 0xffff0fff) | (colorParam << 12);
    } else {
        for (entryIndex = 0; entryIndex < range->mEntryCount; entryIndex++) {
            entries->mAttr01 = (entries->mAttr01 & OAM_ENTRY_NOT_MODE_MASK) | (mode << 10);
            entries->mAttr2 = (entries->mAttr2 & OAM_ENTRY_NOT_PALETTE_MASK) | (colorParam << 12);
            entries++;
        }
    }
}

void SetOamRangePosition(OamRange *range, s32 index, u32 xPos, u32 yPos) {
    OamEntry *entries = range->mEntries;
    s32 entryIndex;
    s32 firstX;
    s32 firstY;
    s32 deltaX;
    s32 deltaY;
    s32 entryX;
    s32 entryY;

    if (index >= 0) {
        u32 word = entries[index].mAttr01;

        entries[index].mAttr01 = ((xPos & 0x1ff) << 16) | ((word & 0xfe00ff00) | (yPos & 0xff));
    } else {
        G2_GetOBJPosition(entries, (u32 *) &firstX, (u32 *) &firstY);
        entries->mAttr01 = ((xPos & 0x1ff) << 16) | ((entries->mAttr01 & OAM_ENTRY_NOT_POSITION_MASK) | (yPos & 0xff));
        deltaX = xPos - firstX;
        deltaY = yPos - firstY;
        for (entryIndex = 1; entryIndex < range->mEntryCount; entryIndex++) {
            G2_GetOBJPosition(&entries[entryIndex], (u32 *) &entryX, (u32 *) &entryY);
            entries[entryIndex].mAttr01 =
                (((entryX + deltaX) & 0x1ff) << 16) |
                ((entries[entryIndex].mAttr01 & OAM_ENTRY_NOT_POSITION_MASK) | ((entryY + deltaY) & 0xff));
        }
    }
}

void SetOamRangePriority(OamRange *range, s32 index, u32 priority) {
    OamEntry *entries = range->mEntries;
    s32 entryIndex;

    if (index >= 0) {
        u32 word = entries[index].mAttr2;

        entries[index].mAttr2 = (word & 0xfffff3ff) | (priority << 10);
    } else {
        for (entryIndex = 0; entryIndex < range->mEntryCount; entryIndex++) {
            entries->mAttr2 = (entries->mAttr2 & OAM_ENTRY_NOT_PRIORITY_MASK) | (priority << 10);
            entries++;
        }
    }
}

void GetOamRangeEntryPosition(OamRange *range, int index, s32 *xPos, s32 *yPos) {
    OamEntry *entries;

    entries = range->mEntries;
    *xPos = (entries[index].mAttr01 & OAM_ENTRY_X_POSITION_MASK) >> 0x10;
    *yPos = entries[index].mAttr01 & OAM_ENTRY_Y_POSITION_MASK;
}
