#include "Main/Sound/surface_sound_ids.h"

#include "Main/Item/data_0215a000.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/sound_source_list.h"
#include "code_020172d0.h"

u8 gSurfaceSoundIdShortRowTable[28] = {0x81, 0, 0x82, 0, 0x83, 0, 0x84, 0, 0x85, 0, 0x86, 0, 0x87, 0, 0x88, 0, 0x89, 0, 0x8a, 0, 0x8b, 0, 0x8c, 0, 0x8d, 0, 0, 0};
u8 gSurfaceSoundIdRowTable[152] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x72, 0, 0x75, 0, 0x76, 0, 0xff, 0xff, 0x73, 0, 0x74, 0, 0x79, 0, 0xd0, 0xff, 0x78, 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x77, 0, 0xd1, 0xff, 0xff, 0xff, 0x54, 0, 0x55, 0, 0x56, 0, 0x57, 0, 0x59, 0, 0x5a, 0, 0x5b, 0, 0x5c, 0, 0x5d, 0, 0x65, 0, 0x5e, 0, 0x5f, 0, 0x60, 0, 0x61, 0, 0x62, 0, 0x63, 0, 0x64, 0, 0xff, 0xff, 0xff, 0xff, 0x67, 0, 0x67, 0, 0x67, 0, 0x69, 0, 0x67, 0, 0x68, 0, 0x6a, 0, 0x6b, 0, 0x6f, 0, 0x6c, 0, 0x67, 0, 0x71, 0, 0x6d, 0, 0x67, 0, 0x67, 0, 0x67, 0, 0x6e, 0, 0x67, 0, 0x67, 0, 0x8f, 0, 0x90, 0, 0x91, 0, 0x91, 0, 0x92, 0, 0x91, 0, 0x93, 0, 0x94, 0, 0x95, 0, 0x94, 0, 0x96, 0, 0x97, 0, 0x98, 0, 0x99, 0, 0x9a, 0, 0x9b, 0, 0x9c, 0, 0x8f, 0, 0x8f, 0};
SurfaceSoundIdRow gSurfaceSoundIds[23];

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
    value = gSurfaceSoundColumnIndices[surfaceKind][surfaceVariant];
    if (value == 0x14) {
        value = 0xffff;
    }
    if (value == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (gSurfaceSoundIdRowTable + entryIndex * 0x26 + value * 2);
}

u32 GetSurfaceSoundIdShortRows(s32 entryIndex, s32 rowIndex, s32 columnIndex) {
    void *idArray;
    s32 value;

    idArray = gSurfaceSoundIds[rowIndex].mIdArrays[columnIndex];
    value = idArray != 0 ? ((u32 *) idArray)[entryIndex] : 0xffff;
    if (value != 0xffff) {
        return (u16) value;
    }
    value = gSurfaceSoundColumnIndices[rowIndex][columnIndex];
    if (value == 0xe) {
        value = 0xffff;
    }
    if (value == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (gSurfaceSoundIdShortRowTable + entryIndex * 0x1a + value * 2);
}
