#include "03/code_021d1790.h"
#include "03/code_021d1770.h"

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
