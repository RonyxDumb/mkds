#include "03/code_021d1790.h"
#include "03/code_021d1770.h"

static inline void func_ov003_021d17d4_inline(OamEntry *p, u32 *x, u32 *y) {
    *x = (p->field0 & 0x1ff0000) >> 16;
    *y = p->field0 & 0xff;
}

void SetOamRangeEffect(OamRange *range, s32 index, u32 effect, u32 affineIndex) {
    OamEntry *entries = range->mEntries;
    s32 i;

    if (index >= 0) {
        if (effect != 0x100 && effect != 0x300) {
            u32 word = entries[index].field0;

            entries[index].field0 = (word & 0xc1fffcff) | effect;
        } else {
            u32 word = entries[index].field0;

            entries[index].field0 = (affineIndex << 25) | ((word & 0xc1fffcff) | effect);
        }
    } else {
        for (i = 0; i < range->mEntryCount; i++) {
            if (effect != 0x100 && effect != 0x300) {
                entries->field0 = (entries->field0 & 0xc1fffcff) | effect;
            } else {
                entries->field0 = (affineIndex << 25) | ((entries->field0 & 0xc1fffcff) | effect);
            }
            entries++;
        }
    }
}

void func_ov003_021d1890(OamRange *range, s32 index, u32 param_3, u32 param_4) {
    s32 i;
    OamEntry *entries = range->mEntries;

    if (index >= 0) {
        u32 t = entries[index].field0;
        u32 u;

        entries[index].field0 = (t & 0xfffff3ff) | (param_3 << 10);
        u = entries[index].field4;
        entries[index].field4 = (u & 0xffff0fff) | (param_4 << 12);
    } else {
        for (i = 0; i < range->mEntryCount; i++) {
            entries->field0 = (entries->field0 & 0xfffff3ff) | (param_3 << 10);
            entries->field4 = (entries->field4 & 0xffff0fff) | (param_4 << 12);
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
        u32 word = entries[index].field0;

        entries[index].field0 = ((xPos & 0x1ff) << 16) | ((word & 0xfe00ff00) | (yPos & 0xff));
    } else {
        func_ov003_021d17d4_inline(entries, (u32 *) &firstX, (u32 *) &firstY);
        entries->field0 = ((xPos & 0x1ff) << 16) | ((entries->field0 & 0xfe00ff00) | (yPos & 0xff));
        deltaX = xPos - firstX;
        deltaY = yPos - firstY;
        for (i = 1; i < range->mEntryCount; i++) {
            func_ov003_021d17d4_inline(&entries[i], (u32 *) &entryX, (u32 *) &entryY);
            entries[i].field0 =
                (((entryX + deltaX) & 0x1ff) << 16) | ((entries[i].field0 & 0xfe00ff00) | ((entryY + deltaY) & 0xff));
        }
    }
}

void func_ov003_021d1790(OamRange *range, s32 index, u32 param_3) {
    OamEntry *entries = range->mEntries;
    s32 i;

    if (index >= 0) {
        u32 word = entries[index].field4;

        entries[index].field4 = (word & 0xfffff3ff) | (param_3 << 10);
    } else {
        for (i = 0; i < range->mEntryCount; i++) {
            entries->field4 = (entries->field4 & 0xfffff3ff) | (param_3 << 10);
            entries++;
        }
    }
}
