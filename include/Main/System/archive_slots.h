#pragma once

#include "types.h"

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

// 8-byte entries of two words: a string and a number.
typedef struct CourseNameEntry {
    /* 00 */ const char *mName;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05[0x3];
} CourseNameEntry;

// Slot numbers of gArchiveSlotInfos and gArchiveSlots->mSlots: one per archive the game keeps mounted. Each slot has a
// mount name in gArchiveNames. The "language" slots load the same archive with the language code in the file name.
typedef enum ArchiveSlotIndex {
    ARCHIVE_SLOT_NONE = -1,
    ARCHIVE_SLOT_MAIN_RACE = 0,
    ARCHIVE_SLOT_MAIN_2D = 1,
    ARCHIVE_SLOT_MAIN_2D_LANGUAGE = 2,
    ARCHIVE_SLOT_COURSE = 3,
    // Has no path and is never loaded through LoadArchiveSlotForScene.
    ARCHIVE_SLOT_SND = 4,
    ARCHIVE_SLOT_SCENE = 5,
    ARCHIVE_SLOT_KART_MODEL_MAIN_A = 6,
    ARCHIVE_SLOT_KART_MODEL_MAIN_B = 7,
    ARCHIVE_SLOT_KART_MODEL_SUB = 8,
    ARCHIVE_SLOT_SCENE_LANGUAGE = 9,
    ARCHIVE_SLOT_KART_MODEL_MENU = 10,
    ARCHIVE_SLOT_SCENE_MODE = 11,
    ARCHIVE_SLOT_SCENE_MODE_LANGUAGE = 12,
    ARCHIVE_SLOT_COURSE_TEXTURE = 13,
    ARCHIVE_SLOT_CHARACTER_KART_SELECT = 14,
    ARCHIVE_SLOT_CHARACTER_KART_SELECT_LANGUAGE = 15,
    ARCHIVE_SLOT_GENERAL_MENU = 16,
    ARCHIVE_SLOT_GENERAL_MENU_LANGUAGE = 17,
    ARCHIVE_SLOT_MAIN_EFFECT = 18,
    // Mounted from the archive kept in memory, not read from a file.
    ARCHIVE_SLOT_IN_MEMORY = 19,
    ARCHIVE_SLOT_COUNT = 20,
} ArchiveSlotIndex;

// Buffer numbers of gArchiveSlots->mBuffers, named after the archive each one is requested for.
typedef enum ArchiveBufferIndex {
    ARCHIVE_BUFFER_NONE = -1,
    ARCHIVE_BUFFER_MENU_DL = 0,
    ARCHIVE_BUFFER_MENU_DL_LANGUAGE = 1,
    ARCHIVE_BUFFER_RACE = 2,
    ARCHIVE_BUFFER_RACE_LANGUAGE = 3,
    ARCHIVE_BUFFER_RACE_MODE = 4,
    ARCHIVE_BUFFER_RACE_MODE_LANGUAGE = 5,
    ARCHIVE_BUFFER_COURSE = 6,
    ARCHIVE_BUFFER_COURSE_TEXTURE = 7,
    ARCHIVE_BUFFER_MAIN_RACE = 8,
    ARCHIVE_BUFFER_MAIN_2D = 9,
    ARCHIVE_BUFFER_MAIN_2D_LANGUAGE = 10,
    ARCHIVE_BUFFER_KART_MODEL_MAIN_A = 11,
    ARCHIVE_BUFFER_KART_MODEL_MAIN_B = 12,
    ARCHIVE_BUFFER_MAIN_EFFECT = 13,
    ARCHIVE_BUFFER_RESULT_DL = 14,
    ARCHIVE_BUFFER_RESULT_DL_LANGUAGE = 15,
    ARCHIVE_BUFFER_COUNT = 16,
} ArchiveBufferIndex;

// Longest archive path, in bytes with the terminator.
#define ARCHIVE_PATH_SIZE 0x80

void BuildSceneArchivePath(char *path, const char *sceneName);
void BuildSceneArchivePathWithLanguage(char *path, const char *sceneName);
u32 GetMPLanguageCode(void);
u32 GetLanguageCode(void);
void BuildCourseArchivePath(char *path, s32 courseId, s32 useTexture);
void *LoadFileAligned(const char *path, s32 alignment);
u32 LoadFileIntoHeap(char *path, NNSiFndHeapHead *heap, void **outData);
u32 ReadFileBytes(void *path, void *buffer, u32 size);
int ReadWholeFile(const char *path, void *buffer, u32 maxSize);
void InitArchiveSlots(void *heap);


