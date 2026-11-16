#pragma once

#include "types.h"
#include "Main/Sound/sound_seq.h"

// Results of GetSurfaceSoundId and GetSurfaceSoundIdShortRows: no sound; GetSurfaceSoundId can also return the two lap
// progress sounds (bit 0 picks the kind).
#define SURFACE_SOUND_NONE 0xffff
#define SURFACE_SOUND_LAP_PROGRESS_A 0xffd0
#define SURFACE_SOUND_LAP_PROGRESS_B 0xffd1

// One row of gSurfaceSoundIds (indexed by surface kind): per surface variant a pointer to an array of sound ids, or 0
// when none was set.
typedef struct SurfaceSoundIdRow {
    /* 0 */ void *mIdArrays[8];
} SurfaceSoundIdRow;

#include "sound_archive_load.h"

// The link of a list object: it follows the NNSFndLink words at the list's mLinkOffset and holds the list the object is
// on, set by TryAppendListObject and cleared by RemoveListObject.
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
