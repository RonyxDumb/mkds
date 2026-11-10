#pragma once

#include "types.h"

// gSurfaceSoundIds is addressed in rows of eight words.
typedef struct SurfaceSoundIdRow {
    /* 0 */ void *mIdArrays[8];
} SurfaceSoundIdRow;

#include "code_0212d214.h"

// Addressed at the byte offset NNSFndList.mLinkOffset of the pointer passed to RemoveListObject.
typedef struct ListObjectLink {
    /* 0 */ u8 mUnk_00[8];
    /* 8 */ void *mList;
} ListObjectLink;

u32 GetSurfaceSoundIdShortRows(s32 entryIndex, s32 rowIndex, s32 columnIndex);
u32 GetSurfaceSoundId(s32 entryIndex, s32 surfaceKind, s32 surfaceVariant);
void ClearSurfaceSoundIds(void);
void RemoveListObject(NNSFndList *list, void *object);
u32 TryAppendListObject(void *list, void *object);
