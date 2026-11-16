#pragma once

#include "types.h"

void *LoadKartModelFile(const char *path);
void *FindKartModelFile(const char *path);
void *FindCourseFile(const char *path);
void *FindSceneFile(const char *name);
void *FindMainRaceOrMainEffectFile(const char *path);
void *FindArchiveFile(const char *archiveName, const char *path);

// The load info of one archive slot: its path, next slot, buffer index and the uncompress and allocation settings.
typedef struct ArchiveSlotInfo {
    /* 00 */ const char *mPath;
    /* 04 */ s32 mNextSlot;
    /* 08 */ s8 mBufferIndex;
    /* 09 */ u8 mUnk_09[0x3];
    /* 0c */ s32 mUncompressSource;
    /* 10 */ s32 mAllocFromHeapEnd;
    /* 14 */ s32 mUnk_14;
} ArchiveSlotInfo;

// A scene's name string (mName) and the archive buffer size (mArchiveBufferSize) it loads with, -1 for most scenes.
typedef struct SceneName {
    /* 00 */ const char *mName;
    /* 04 */ s32 mArchiveBufferSize;
} SceneName;

#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/archive_slots.h"
#include "Main/System/scene_numbers.h"

// Heap group ids passed to SetHeapGroupId: 0 is the id every expanded heap starts with and the one archive slots are
// loaded under; 9 is the id the scene setup works under, and the one set again after a part of it used another id.
#define HEAP_GROUP_DEFAULT 0
#define HEAP_GROUP_SCENE 9

void InitTouchMicInput(void *heap);
void InitTouchPanelAndSetCalibration(void);
void InitCompressedArchiveAndMBChild(void *heap);
void ResizeMainEffectArchiveBlock(u8 *regionStart, u32 regionSize);
s32 ShouldLoadMap2DData(void);
void ClearArchiveBuffersMap2DLoadFlag(void);
void RequestResultDLArchives(void);
void RequestRaceArchives(void *courseId, void *kind);
void RequestMenuDLArchives(void);
void RequestMainAndMenuDLArchives(void);
void RequestArchiveLoadWithLanguage(const void *prefix, u32 bufferIndex);
void RequestArchiveLoad(const void *path, s32 bufferIndex);
void InitArchiveBuffersOnOverlayHeap(void);
void InitArchiveBuffers(NNSiFndHeapHead *firstHeap, NNSiFndHeapHead *courseBufferHeap, NNSiFndHeapHead *lastHeap);
void InitArchiveBuffer(NNSiFndHeapHead *heap, s32 bufferIndex, s32 sizeInKb, u32 uncompress, u32 flag);
void ReleaseKartModelLoadSlotsForScene(void);
void ReleaseCourseLoadSlotsInRace(void);
void ReleaseKartModelSlotsLoadCourse(void);
void ReplaceKm1ArchiveWithKm2(void);
void *GetKartModelFile(const char *path);
void *FindFileInLoadedArchives(const char *name);
void SetHeapGroupId(u32 groupId);
void ReleaseArchiveSlots(void);
void LoadArchiveSlotsForScene(s32 sceneNumber);
void ReleaseArchiveSlot(int slotIndex);
void LoadArchiveSlotData(void);
void UncompressArchiveMemory(void);
void UncompressArchiveFile(void);
void LoadArchiveSlot(s32 slotIndex, const char *path, u32 *sourceData, void *data, s32 allocFromHeapEnd,
                     s32 uncompressSource, s32 archiveBufferSize);
void LoadArchiveSlotForScene(int slotIndex, int sceneNumber);
void BuildArchivePathWithLanguage(const char *prefix, char *path);
void BuildSceneModeLanguageArchivePath(char *path, const char *sceneName, int mode);
void BuildSceneModeArchivePath(char *path, const char *sceneName, int mode);
void BuildStaffRollArchivePath(char *path);
void BuildResultArchivePathWithLanguage(char *path);
void BuildResultArchivePath(char *path);

extern const SceneName gSceneNames[16];
extern const CourseNameEntry gCourseArchiveNames[55];
extern const ArchiveSlotInfo gArchiveSlotInfos[21];
extern const char *gModeArchiveNames[6];
extern const char *gLanguageCodes[7];
extern const char *gArchiveNames[20];
extern char gArchiveSlotInfosEmptyPathCourse[];
extern char gArchiveSlotInfosEmptyPathScene[];
extern char gArchiveSlotInfosEmptyPathSceneModeLanguage[];
extern char gArchiveSlotInfosEmptyPathCourseTexture[];
extern char gArchiveSlotInfosEmptyPathSnd[];
extern char gCourseArchiveNamesEmptyNameFirst[];
extern char gArchiveSlotInfosEmptyPathAtCount[];
extern char gArchiveSlotInfosEmptyPathSceneLanguage[];
extern char gArchiveSlotInfosEmptyPathSceneMode[];
extern char gArchiveSlotInfosEmptyPathInMemory[];
extern char gModeArchiveNameMr[];
extern char gModeArchiveNameGp[];
extern char gLanguageCodeIt[];
extern char gModeArchiveNameVs[];
extern char gModeArchiveNameTa[];
extern char gModeArchiveNameMg[];
extern char gLanguageCodeEnglish[];
extern char gLanguageCodeFr[];
extern char gLanguageCodeEuropeEnglish[];
extern char gModeArchiveNameNt[];
extern char gLanguageCodeJa[];
extern char gLanguageCodeGe[];
extern char gLanguageCodeEs[];
extern char gArchiveNameR2D[];
extern char gArchiveNameGE2[];
extern char gArchiveNameKME[];
extern char gArchiveNameCKL[];
extern char gArchiveNameEFT[];
extern char gArchiveNameM2L[];
extern char gArchiveNameSND[];
extern char gArchiveNameR2L[];
extern char gArchiveNameS2D[];
extern char gArchiveNameK2D[];
extern char gArchiveNameCST[];
extern char gArchiveNameMA2[];
extern char gArchiveNameKM1[];
extern char gArchiveNameKSB[];
extern char gArchiveNameLOC[];
extern char gArchiveNameG2L[];
extern char gArchiveNameCRS[];
extern char gArchiveNameKM2[];
extern char gArchiveNameCKS[];
extern char gArchiveNameMAR[];
extern char gSceneNameMenu[];
extern char gSceneNameRace[];
extern char gSceneNameSecondMenu[];
extern char gSceneNameLogo[];
extern char gSceneNameTest[];
extern char gCourseArchiveNameAward[];
extern char gSceneNameTitle[];
extern char gSceneNameGhost[];
extern char gSceneNameEnding[];
extern char gSceneNameEmblem[];
extern char gSceneNameWLMenu[];
extern char gSceneNameOption[];
extern char gSceneNameRecord[];
extern char gSceneNameResult[];
extern char gSceneNameNickname[];
extern char gSceneNameWiFiMenu[];
extern char gSceneNameKeyboard[];
extern char gCourseArchiveNameMrStage1[];
extern char gCourseArchiveNameMrStage3[];
extern char gCourseArchiveNameMrStage4[];
extern char gCourseArchiveNameStaffRoll[];
extern char gCourseArchiveNameMrStage2[];
extern char gCourseArchiveNameTownCourse[];
extern char gCourseArchiveNameSnowCourse[];
extern char gCourseArchiveNameOldSkyAgb[];
extern char gCourseArchiveNameMiniStage1[];
extern char gCourseArchiveNameMiniStage2[];
extern char gCourseArchiveNameMiniStage3[];
extern char gCourseArchiveNameMiniStage4[];
extern char gCourseArchiveNameOldMomo64[];
extern char gCourseArchiveNameOldBabyGc[];
extern char gCourseArchiveNameTestCircle[];
extern char gCourseArchiveNameBankCourse[];
extern char gCourseArchiveNameMarioCourse[];
extern char gCourseArchiveNameBeachCourse[];
extern char gCourseArchiveNameKoopaCourse[];
extern char gCourseArchiveNameOldChoco64[];
extern char gCourseArchiveNameOldYoshiGc[];
extern char gArchiveSlotPathDataMain2D[];
extern char gCourseArchiveNameOldMarioGc[];
extern char gCourseArchiveNameLuigiCourse[];
extern char gCourseArchiveNameDokanCourse[];
extern char gCourseArchiveNameTest1Course[];
extern char gCourseArchiveNameWarioCourse[];
extern char gCourseArchiveNameOldLuigiGc[];
extern char gCourseArchiveNameOldNokoSfc[];
extern char gCourseArchiveNameClockCourse[];
extern char gCourseArchiveNameCrossCourse[];
extern char gCourseArchiveNameRidgeCourse[];
extern char gCourseArchiveNameGardenCourse[];
extern char gCourseArchiveNameDesertCourse[];
extern char gCourseArchiveNameOldDonutSfc[];
extern char gCourseArchiveNameOldLuigiAgb[];
extern char gCourseArchiveNameOldKinokoGc[];
extern char gCourseArchiveNameOldChocoSfc[];
extern char gCourseArchiveNameMiniBlock64[];
extern char gCourseArchiveNameMiniDokanGc[];
extern char gCourseArchiveNameStaffRollTrue[];
extern char gCourseArchiveNameDonkeyCourse[];
extern char gCourseArchiveNameOldMarioSfc[];
extern char gCourseArchiveNameOldKoopaAgb[];
extern char gCourseArchiveNameOldPeachAgb[];
extern char gCourseArchiveNameOldFrappe64[];
extern char gCourseArchiveNameRainbowCourse[];
extern char gCourseArchiveNamePinballCourse[];
extern char gCourseArchiveNameStadiumCourse[];
extern char gCourseArchiveNameMansionCourse[];
extern char gCourseArchiveNameAirshipCourse[];
extern char gCourseArchiveNameOldHyudoro64[];
extern char gCourseArchiveNameNokonokoCourse[];
extern char gCourseArchiveNameMiniBlockCourse[];
extern char gArchiveSlotPathDataGeneralMenu[];
extern char gArchiveSlotPathDataMain2DCarc[];
extern char gArchiveSlotPathDataMainRaceCarc[];
extern char gArchiveSlotPathDataMainEffectCarc[];
extern char gArchiveSlotPathDataGeneralMenuCarc[];
extern char gArchiveSlotPathDataKartModelSubCarc[];
extern char gArchiveSlotPathDataKartModelMenuCarc[];
extern char gArchiveSlotPathDataCharacterKartSelect[];
extern char gArchiveSlotPathDataKartModelMainACarc[];
extern char gArchiveSlotPathDataKartModelMainBCarc[];
extern char gArchiveSlotPathDataCharacterKartSelectCarc[];
