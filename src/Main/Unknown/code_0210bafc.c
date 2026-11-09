#include "Main/Unknown/code_0210bafc.h"

#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210bbec.h"
#include "code_0212d214.h"
#include "code_020172d0.h"

u32 TryAppendListObject(void *list, void *object) {
    BOOL willAppend;
    Unk0210bc54 *link;

    link = OFFSET_PTR(Unk0210bc54, object, ((NNSFndList *) list)->mLinkOffset);
    if (link->mUnk_08 != 0) {
        willAppend = FALSE;
    } else {
        willAppend = TRUE;
        link->mUnk_08 = list;
    }
    if (willAppend != FALSE) {
        NNS_FndAppendListObject(list, object);
    } else {
        return 0;
    }
    return 1;
}

void RemoveListObject(NNSFndList *list, void *object) {
    Unk0210bc54 *link;

    NNS_FndRemoveListObject(list, object);
    link = OFFSET_PTR(Unk0210bc54, object, list->mLinkOffset);
    if (link->mUnk_08 != 0) {
        link->mUnk_08 = 0;
    }
}

void ClearSurfaceSoundIds(void) {
    __clear(gSurfaceSoundIds, 0x17 * sizeof(SurfaceSoundIdRow));
}

void SetSurfaceSoundIds(u32 rowIndex, u32 columnIndex, void *entries) {
    gSurfaceSoundIds[rowIndex].mIdArrays[columnIndex] = entries;
}

void CourseEntrySetSurfaceSoundIds(u32 rowIndex, u32 columnIndex, Unk0216c860 *entries) {
    gSurfaceSoundIds[rowIndex].mIdArrays[columnIndex] = entries;
}

u32 GetSurfaceSoundId(s32 entryIndex, s32 surfaceKind, s32 surfaceVariant) {
    void *idArray;
    s32 v;

    idArray = gSurfaceSoundIds[surfaceKind].mIdArrays[surfaceVariant];
    v = idArray != 0 ? ((u32 *) idArray)[entryIndex] : 0xffff;
    if (v != 0xffff) {
        return (u16) v;
    }
    v = data_0215a6fc[surfaceKind][surfaceVariant];
    if (v == 0x14) {
        v = 0xffff;
    }
    if (v == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (data_0216ca84 + entryIndex * 0x26 + v * 2);
}

u32 func_0210bafc(s32 entryIndex, s32 rowIndex, s32 columnIndex) {
    void *idArray;
    s32 v;

    idArray = gSurfaceSoundIds[rowIndex].mIdArrays[columnIndex];
    v = idArray != 0 ? ((u32 *) idArray)[entryIndex] : 0xffff;
    if (v != 0xffff) {
        return (u16) v;
    }
    v = data_0215a6fc[rowIndex][columnIndex];
    if (v == 0xe) {
        v = 0xffff;
    }
    if (v == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (data_0216ca68 + entryIndex * 0x1a + v * 2);
}
