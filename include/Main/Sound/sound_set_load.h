#pragma once

#include "types.h"
#include "Main/Menu/data_02153000.h" // SoundRow
#include "code_02022aa8.h"
#include "Main/Graphics/cell_file_set.h"
#include "code_0212d214.h"

// Id that leaves a SoundSet slot empty: the set loads nothing for it.
#define SOUND_ID_NONE 0xff

// Three words, at 0, 4 and 8: LoadSoundSet, IsSoundSetLoaded and ReleaseSoundSet take one by value.
typedef struct SoundSet {
    /* 00 */ u32 mSeqId;
    /* 04 */ u32 mFirstBankId;
    /* 08 */ u32 mSecondBankId;
} SoundSet;

// Object gLoadedSoundSet, which GetLoadedSoundSet returns: a SoundSet at 0 and a word at 0xc that
// SaveSndHeapState and ReleaseSoundSet write.
typedef struct LoadedSoundSet {
    /* 00 */ SoundSet mSoundSet;
    /* 0c */ u32 mHeapState;
} LoadedSoundSet;

// Object gSndDataFileIdList: 16 words from 0x00 and a signed number at 0x40; LoadSndDataFromFile and
// LoadSndGroupWithWaveArcs add a word to it, ClearSndFileAddresses walks it and ClearSndFileIdList resets it.
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
