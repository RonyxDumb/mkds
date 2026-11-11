#include "03/code_021d1790.h"
#include "03/code_021d1770.h"

static inline void G2_GetOBJPosition(OamEntry *oam, u32 *x, u32 *y) {
    *x = (oam->mUnk_00 & 0x1ff0000) >> 16;
    *y = oam->mUnk_00 & 0xff;
}

void SetOamRangeEffect(OamRange *range, s32 index, u32 effect, u32 affineIndex) {
    OamEntry *entries = range->mEntries;
    s32 i;

    if (index >= 0) {
        if (effect != 0x100 && effect != 0x300) {
            u32 word = entries[index].mUnk_00;

            entries[index].mUnk_00 = (word & 0xc1fffcff) | effect;
        } else {
            u32 word = entries[index].mUnk_00;

            entries[index].mUnk_00 = (affineIndex << 25) | ((word & 0xc1fffcff) | effect);
        }
    } else {
        for (i = 0; i < range->mEntryCount; i++) {
            if (effect != 0x100 && effect != 0x300) {
                entries->mUnk_00 = (entries->mUnk_00 & 0xc1fffcff) | effect;
            } else {
                entries->mUnk_00 = (affineIndex << 25) | ((entries->mUnk_00 & 0xc1fffcff) | effect);
            }
            entries++;
        }
    }
}

void SetOamRangeMode(OamRange *range, s32 index, u32 mode, u32 colorParam) {
    s32 i;
    OamEntry *entries = range->mEntries;

    if (index >= 0) {
        u32 attr01 = entries[index].mUnk_00;
        u32 attr2;

        entries[index].mUnk_00 = (attr01 & 0xfffff3ff) | (mode << 10);
        attr2 = entries[index].mUnk_04;
        entries[index].mUnk_04 = (attr2 & 0xffff0fff) | (colorParam << 12);
    } else {
        for (i = 0; i < range->mEntryCount; i++) {
            entries->mUnk_00 = (entries->mUnk_00 & 0xfffff3ff) | (mode << 10);
            entries->mUnk_04 = (entries->mUnk_04 & 0xffff0fff) | (colorParam << 12);
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
        u32 word = entries[index].mUnk_00;

        entries[index].mUnk_00 = ((xPos & 0x1ff) << 16) | ((word & 0xfe00ff00) | (yPos & 0xff));
    } else {
        G2_GetOBJPosition(entries, (u32 *) &firstX, (u32 *) &firstY);
        entries->mUnk_00 = ((xPos & 0x1ff) << 16) | ((entries->mUnk_00 & 0xfe00ff00) | (yPos & 0xff));
        deltaX = xPos - firstX;
        deltaY = yPos - firstY;
        for (i = 1; i < range->mEntryCount; i++) {
            G2_GetOBJPosition(&entries[i], (u32 *) &entryX, (u32 *) &entryY);
            entries[i].mUnk_00 =
                (((entryX + deltaX) & 0x1ff) << 16) | ((entries[i].mUnk_00 & 0xfe00ff00) | ((entryY + deltaY) & 0xff));
        }
    }
}

void SetOamRangePriority(OamRange *range, s32 index, u32 priority) {
    OamEntry *entries = range->mEntries;
    s32 i;

    if (index >= 0) {
        u32 word = entries[index].mUnk_04;

        entries[index].mUnk_04 = (word & 0xfffff3ff) | (priority << 10);
    } else {
        for (i = 0; i < range->mEntryCount; i++) {
            entries->mUnk_04 = (entries->mUnk_04 & 0xfffff3ff) | (priority << 10);
            entries++;
        }
    }
}
