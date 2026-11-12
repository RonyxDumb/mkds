#include "03/Graphics/nce_oam.h"
#include "03/code_021d1c18.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0214d000.h"
#include "03/code_021d2ecc.h"
#include "03/System/dwc_archive.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "03/code_021d197c.h"
#include "03/code_021d1970.h"
#include "03/System/pointer_stack.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d1d60.h"
#include "03/System/exp_heap.h"
#include "03/Graphics/oam_buffers.h"
#include "03/code_021d2e68.h"
#include "03/code_021d2eb8.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "03/code_021d1790.h"

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
    s32 i;
    u8 buffer[8];
    volatile u32 d = 0;

    MIi_CpuClear32(d, buffer, 8);
    for (i = 0; i < entryCount; i++, source += 6, destination++) {
        MIi_CpuCopy16(source, buffer, 6);
        MIi_CpuCopy32(buffer, destination, 8);
    }
}

void *CreateOamEntryFromNceImage(u32 screen, u32 imageIndex) {
    OamEntry *entry;
    u8 v2[8];
    entry = CreateOamEntry(screen, v2);
    CopyNceImageToOamEntries(screen, imageIndex, entry);
    return entry;
}

OamRange *CreateOamRangeFromNceImage(u32 screen, u32 imageIndex, s32 fromFront) {
    OamRange *range = CreateOamRange(screen, gNceFiles[screen][imageIndex].mEntryCount, fromFront);

    CopyNceImageToOamEntries(screen, imageIndex, GetOamRangeEntry(range, 0));
    return range;
}

void InitOamRanges(void) {
    s32 i;

    gOamRanges = AllocZeroedExpHeapBlock(0x450, 4);
    for (i = 0; i < 2; i++) {
        gOamRanges[i].mFreeRanges = CreateFilledPointerStack(0x20, &gOamRanges[i], 0x10);
        gOamRanges[i].mNodeList = CreateNodeList();
        gOamRanges[i].mListStart.mEntries = GetOamBufferEntry(i, 0x40);
        gOamRanges[i].mListEnd.mEntries = GetOamBufferEntry(i, 0x7f) + 1;
        AddNodeToListFront(gOamRanges[i].mNodeList, &gOamRanges[i].mListStart);
        AddNodeToListBack(gOamRanges[i].mNodeList, &gOamRanges[i].mListEnd);
    }
}

void ReleaseOamRanges(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        DeleteNodeList(gOamRanges[i].mNodeList);
        DeletePointerStack(gOamRanges[i].mFreeRanges);
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
                    AddNodeBefore((u32) neighbor, (u32) range);
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
                    AddNodeBefore((u32) node, (u32) range);
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
    s32 i;

    for (i = 0; i < range->mEntryCount; i++, entries++) {
        entries->mAttr01 = (entries->mAttr01 & 0xc1fffcff) | 0x200;
    }
    RemoveNodeFromList((u32) range);
    if (range >= (OamRange *) &gOamRanges[1]) {
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
    *x = (oam->mAttr01 & 0x1ff0000) >> 16;
    *y = oam->mAttr01 & 0xff;
}

void SetOamRangeEffect(OamRange *range, s32 index, u32 effect, u32 affineIndex) {
    OamEntry *entries = range->mEntries;
    s32 i;

    if (index >= 0) {
        if (effect != 0x100 && effect != 0x300) {
            u32 word = entries[index].mAttr01;

            entries[index].mAttr01 = (word & 0xc1fffcff) | effect;
        } else {
            u32 word = entries[index].mAttr01;

            entries[index].mAttr01 = (affineIndex << 25) | ((word & 0xc1fffcff) | effect);
        }
    } else {
        for (i = 0; i < range->mEntryCount; i++) {
            if (effect != 0x100 && effect != 0x300) {
                entries->mAttr01 = (entries->mAttr01 & 0xc1fffcff) | effect;
            } else {
                entries->mAttr01 = (affineIndex << 25) | ((entries->mAttr01 & 0xc1fffcff) | effect);
            }
            entries++;
        }
    }
}

void SetOamRangeMode(OamRange *range, s32 index, u32 mode, u32 colorParam) {
    s32 i;
    OamEntry *entries = range->mEntries;

    if (index >= 0) {
        u32 attr01 = entries[index].mAttr01;
        u32 attr2;

        entries[index].mAttr01 = (attr01 & 0xfffff3ff) | (mode << 10);
        attr2 = entries[index].mAttr2;
        entries[index].mAttr2 = (attr2 & 0xffff0fff) | (colorParam << 12);
    } else {
        for (i = 0; i < range->mEntryCount; i++) {
            entries->mAttr01 = (entries->mAttr01 & 0xfffff3ff) | (mode << 10);
            entries->mAttr2 = (entries->mAttr2 & 0xffff0fff) | (colorParam << 12);
            entries++;
        }
    }
}

void SetOamRangePosition(OamRange *range, s32 index, u32 xPos, u32 yPos) {
    OamEntry *entries = range->mEntries;
    s32 i;
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
        entries->mAttr01 = ((xPos & 0x1ff) << 16) | ((entries->mAttr01 & 0xfe00ff00) | (yPos & 0xff));
        deltaX = xPos - firstX;
        deltaY = yPos - firstY;
        for (i = 1; i < range->mEntryCount; i++) {
            G2_GetOBJPosition(&entries[i], (u32 *) &entryX, (u32 *) &entryY);
            entries[i].mAttr01 =
                (((entryX + deltaX) & 0x1ff) << 16) | ((entries[i].mAttr01 & 0xfe00ff00) | ((entryY + deltaY) & 0xff));
        }
    }
}

void SetOamRangePriority(OamRange *range, s32 index, u32 priority) {
    OamEntry *entries = range->mEntries;
    s32 i;

    if (index >= 0) {
        u32 word = entries[index].mAttr2;

        entries[index].mAttr2 = (word & 0xfffff3ff) | (priority << 10);
    } else {
        for (i = 0; i < range->mEntryCount; i++) {
            entries->mAttr2 = (entries->mAttr2 & 0xfffff3ff) | (priority << 10);
            entries++;
        }
    }
}

void GetOamRangeEntryPosition(OamRange *range, int index, u32 *xPos, s32 *yPos) {
    OamEntry *entries;

    entries = range->mEntries;
    *xPos = (entries[index].mAttr01 & 0x01ff0000) >> 0x10;
    *yPos = entries[index].mAttr01 & 0xff;
}
