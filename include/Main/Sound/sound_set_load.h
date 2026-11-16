#pragma once

#include "types.h"
#include "Main/Menu/menu_label_cell_rows.h" // SoundRow
#include "font_glyph_layout.h"
#include "Main/Graphics/cell_file_set.h"
#include "sound_archive_load.h"

// Id that leaves a SoundSet slot empty: the set loads nothing for it.
#define SOUND_ID_NONE 0xff

// Sequence ids and a first bank id for which LoadSoundSetIfChanged loads a second wave archive (the source) and moves
// its file to the place of the first one (the destination); the pairs of archive ids are listed with each.
#define SOUND_SET_FIRST_SEQ_SWAP 0x4a
#define SOUND_SET_SECOND_SEQ_SWAP 0x2b
#define SOUND_SET_THIRD_SEQ_SWAP 0xf
#define SOUND_SET_FOURTH_BANK_SWAP 0x10
#define WAVE_ARC_FIRST_SWAP_SOURCE 0x63
#define WAVE_ARC_FIRST_SWAP_DEST 0x31
#define WAVE_ARC_SECOND_SWAP_SOURCE 0x64
#define WAVE_ARC_SECOND_SWAP_DEST 0x58
#define WAVE_ARC_THIRD_SWAP_SOURCE 0x34
#define WAVE_ARC_THIRD_SWAP_DEST 0x33
#define WAVE_ARC_FOURTH_SWAP_SOURCE 0x13
#define WAVE_ARC_FOURTH_SWAP_DEST 0x12

// Three words, at 0, 4 and 8: LoadSoundSet, IsSoundSetLoaded and ReleaseSoundSet take one by value.
typedef struct SoundSet {
    /* 00 */ u32 mSeqId;
    /* 04 */ u32 mFirstBankId;
    /* 08 */ u32 mSecondBankId;
} SoundSet;

// LoadedSoundSet.mHeapState of a set with no saved heap state.
#define LOADED_SOUND_SET_NO_HEAP_STATE 0xff00

// Object gLoadedSoundSet, which GetLoadedSoundSet returns: a SoundSet at 0 and a word at 0xc that
// SaveSndHeapState and ReleaseSoundSet write.
typedef struct LoadedSoundSet {
    /* 00 */ SoundSet mSoundSet;
    /* 0c */ u32 mHeapState;
} LoadedSoundSet;

// The ids of the sound data files loaded so far (mFileIds, mCount); loads add an id, clearing walks and resets it.
typedef struct SndFileIdList {
    /* 00 */ u32 mFileIds[16];
    /* 40 */ s32 mCount;
} SndFileIdList;

extern const SoundSet gEmptySoundSet;
extern const SoundSet gReleaseEmptySoundSet;
extern const SoundSet gResetEmptySoundSet;
extern LoadedSoundSet gLoadedSoundSet;

void ReleaseLoadedSoundSet(void);
u32 LoadSndGroupWithWaveArcs(u32 groupId, u32 moveWaveArcs);
u32 LoadSoundSetIfChanged(SoundSet soundSet, u32 loadExtras);
void LoadInitialSndArcs(void);
void LoadInitialSndGroup(u32 moveWaveArcs);
void LoadSceneSoundSet(SoundRow soundRow, u32 loadExtras);
u32 LoadSndDataFromFile(void);
u32 LoadCourseSoundSet(u32 raceMode, u32 courseId);
u32 LoadResultSceneSoundSet(void);
u32 LoadSndGroup(s32 groupId);
void ResetLoadedSoundSet(LoadedSoundSet *loadedSet);
void SaveSndHeapState(LoadedSoundSet *loadedSet);
void ReleaseSoundSet(LoadedSoundSet *loadedSet);
u32 IsSoundSetLoaded(LoadedSoundSet *loadedSet, SoundSet soundSet);
u32 LoadSoundSet(LoadedSoundSet *loadedSet, SoundSet soundSet);

extern struct NNSSndHeap *gCurrentSndHeap;
extern SndFileIdList gSndDataFileIdList;
// Same layout as the list above and goes through the same functions.
extern SndFileIdList gSoundSetFileIdList;
