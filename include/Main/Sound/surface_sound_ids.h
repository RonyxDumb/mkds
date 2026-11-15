#pragma once

#include "types.h"
#include "Main/Sound/sound_seq.h"

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

typedef struct CourseSurfaceSoundEntry CourseSurfaceSoundEntry;

void CourseEntrySetSurfaceSoundIds(u32 rowIndex, u32 columnIndex, CourseSurfaceSoundEntry *entries);
void SetSurfaceSoundIds(u32 rowIndex, u32 columnIndex, void *entries);

extern u8 gSurfaceSoundIdShortRowTable[28];
extern u8 gSurfaceSoundIdRowTable[152];
extern SurfaceSoundIdRow gSurfaceSoundIds[23];

extern const u16 gSurfaceSoundColumnIndices[24][8];
extern const LoadedSoundBanks gLoadedSoundBanksAfterRelease;
extern const u8 gOnMemorySdat[6909];
extern const LoadedSoundBanks gLoadedSoundBanksAfterHeapCreate;
extern const LoadedSoundBanks gLoadedSoundBanksAfterOnMemoryInit;
