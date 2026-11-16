#include "Main/Unknown/code_0210bafc.h"

#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210bbec.h"
#include "code_0212d214.h"
#include "code_020172d0.h"

u32 list_append(void *list, void *object) {
    BOOL willAppend;
    Unk0210bc54 *link;

    link = OFFSET_PTR(Unk0210bc54, object, ((NNSFndList *) list)->mLinkOffset);
    if (link->field8 != 0) {
        willAppend = FALSE;
    } else {
        willAppend = TRUE;
        link->field8 = list;
    }
    if (willAppend != FALSE) {
        NNS_FndAppendListObject(list, object);
    } else {
        return 0;
    }
    return 1;
}

void list_remove(NNSFndList *list, void *object) {
    Unk0210bc54 *link;

    NNS_FndRemoveListObject(list, object);
    link = OFFSET_PTR(Unk0210bc54, object, list->mLinkOffset);
    if (link->field8 != 0) {
        link->field8 = 0;
    }
}

void csfx_init(void) {
    __clear(csfx_sSfxOverrides, 0x17 * sizeof(Unk0217cd30));
}

u32 csfx_setFloorOverride(u32 rowIndex, u32 columnIndex, void *entries) {
    u32 value0 = rowIndex;
    u32 columnCopy = columnIndex;
    u32 entriesCopy = (u32) entries;
    u32 table;
    table = (u32) &csfx_sSfxOverrides;
    value0 = (table) + ((value0 << 5));
    *(u32 *) ((value0) + ((columnCopy << 2))) = entriesCopy;
    return value0;
}

u32 csfx_setWallOverride(u32 rowIndex, u32 columnIndex, Unk0216c860 *entries) {
    u32 value0 = rowIndex;
    u32 columnCopy = columnIndex;
    u32 entriesCopy = (u32) entries;
    u32 table;
    table = (u32) &csfx_sSfxOverrides;
    value0 = (table) + ((value0 << 5));
    *(u32 *) ((value0) + ((columnCopy << 2))) = entriesCopy;
    return value0;
}

u32 csfx_getFloorSfx(s32 entryIndex, s32 surfaceKind, s32 surfaceVariant) {
    s32 idArray;
    s32 v;

    idArray = ((Unk0217cd30 *) csfx_sSfxOverrides)[surfaceKind].field0[surfaceVariant];
    v = idArray != 0 ? ((u32 *) idArray)[entryIndex] : 0xffff;
    if (v != 0xffff) {
        return (u16) v;
    }
    v = csfx_sMaterialTable[surfaceKind][surfaceVariant];
    if (v == 0x14) {
        v = 0xffff;
    }
    if (v == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (csfx_sFloorSfxIds + entryIndex * 0x26 + v * 2);
}

u32 csfx_getWallSfx(s32 entryIndex, s32 rowIndex, s32 columnIndex) {
    s32 idArray;
    s32 v;

    idArray = ((Unk0217cd30 *) csfx_sSfxOverrides)[rowIndex].field0[columnIndex];
    v = idArray != 0 ? ((u32 *) idArray)[entryIndex] : 0xffff;
    if (v != 0xffff) {
        return (u16) v;
    }
    v = csfx_sMaterialTable[rowIndex][columnIndex];
    if (v == 0xe) {
        v = 0xffff;
    }
    if (v == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (csfx_sWallSfxIds + entryIndex * 0x1a + v * 2);
}
