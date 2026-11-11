#include "Main/Unknown/code_0210bafc.h"

#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210bbec.h"
#include "code_0212d214.h"
#include "code_020172d0.h"

u32 TryAppendListObject(void *list, void *object) {
    BOOL willAppend;
    ListObjectLink *link;

    link = OFFSET_PTR(ListObjectLink, object, ((NNSFndList *) list)->mLinkOffset);
    if (link->mList != 0) {
        willAppend = FALSE;
    } else {
        willAppend = TRUE;
        link->mList = list;
    }
    if (willAppend != FALSE) {
        NNS_FndAppendListObject(list, object);
    } else {
        return 0;
    }
    return 1;
}

void RemoveListObject(NNSFndList *list, void *object) {
    ListObjectLink *link;

    NNS_FndRemoveListObject(list, object);
    link = OFFSET_PTR(ListObjectLink, object, list->mLinkOffset);
    if (link->mList != 0) {
        link->mList = 0;
    }
}

void ClearSurfaceSoundIds(void) {
    __clear(gSurfaceSoundIds, 0x17 * sizeof(SurfaceSoundIdRow));
}

void SetSurfaceSoundIds(u32 rowIndex, u32 columnIndex, void *entries) {
    gSurfaceSoundIds[rowIndex].mIdArrays[columnIndex] = entries;
}

void CourseEntrySetSurfaceSoundIds(u32 rowIndex, u32 columnIndex, CourseSurfaceSoundEntry *entries) {
    gSurfaceSoundIds[rowIndex].mIdArrays[columnIndex] = entries;
}

u32 GetSurfaceSoundId(s32 entryIndex, s32 surfaceKind, s32 surfaceVariant) {
    void *idArray;
    s32 value;

    idArray = gSurfaceSoundIds[surfaceKind].mIdArrays[surfaceVariant];
    value = idArray != 0 ? ((u32 *) idArray)[entryIndex] : 0xffff;
    if (value != 0xffff) {
        return (u16) value;
    }
    value = data_0215a6fc[surfaceKind][surfaceVariant];
    if (value == 0x14) {
        value = 0xffff;
    }
    if (value == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (data_0216ca84 + entryIndex * 0x26 + value * 2);
}

u32 GetSurfaceSoundIdShortRows(s32 entryIndex, s32 rowIndex, s32 columnIndex) {
    void *idArray;
    s32 value;

    idArray = gSurfaceSoundIds[rowIndex].mIdArrays[columnIndex];
    value = idArray != 0 ? ((u32 *) idArray)[entryIndex] : 0xffff;
    if (value != 0xffff) {
        return (u16) value;
    }
    value = data_0215a6fc[rowIndex][columnIndex];
    if (value == 0xe) {
        value = 0xffff;
    }
    if (value == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (data_0216ca68 + entryIndex * 0x1a + value * 2);
}
