#pragma once

#include "types.h"

void *AllocateFindFileBuffer_KME_KM1_KM2_KSB_from_thumb(const char *path);
void *FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(const char *path);
void *FindFileBuffer_CRS_CST_from_thumb(const char *path);
void *FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(const char *name);
void *FindFileBuffer_MAR_EFT_from_thumb(const char *path);
void *FormatGetPathMountBuffer_from_thumb(const char *archiveName, const char *path);

// The load info of one archive slot: its path, next slot, buffer index and the uncompress and allocation settings.
typedef struct ArchiveSlotInfo {
    /* 00 */ const char *mPath;
    /* 04 */ s32 mNextSlot;
    /* 08 */ s8 mBufferIndex;
    /* 09 */ u8 mUnk3[0x3];
    /* 0c */ s32 mUncompressSource;
    /* 10 */ s32 mAllocFromHeapEnd;
    /* 14 */ s32 mArchiveBufferSize;
} ArchiveSlotInfo;

// 8-byte entries of a string and a number.
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
#include "Main/Sound/sound_seq.h"
#include "Main/System/archive_slots.h"
#include "Main/System/scene_numbers.h"

// Heap group ids passed to SetActiveExecutionContextHeapGroupId_from_thumb: 0 is the id every expanded heap starts with; 9 is the id restored once the
// special-purpose allocations of a step are done.
#define HEAP_GROUP_DEFAULT 0
#define HEAP_GROUP_SCENE 9

void CreateGlobal59C4(void *heap);
void Input_MaybeInitializeTouch(void);
void LoadEmbeddedStatic2DArchive_from_thumb(void *heap);
void ResizeActiveExecutionContextHeapHandle_from_thumb(u8 *regionStart, u32 regionSize);
s32 GetMountData7FlagBit31_from_thumb(void);
void SomeMaskMountDataFlags_from_thumb(void);
void RequestResultDLArchives(void);
void RequestRaceArchives(void *courseId, void *kind);
void RequestMenuDLArchives(void);
void RequestMainAndMenuDLArchives(void);
void RequestArchiveLoadWithLanguage(const void *prefix, u32 bufferIndex);
void RequestArchiveLoad(const void *path, s32 bufferIndex);
void InitArchiveBuffersOnOverlayHeap(void);
void SpecialDwcSetMountDatas_from_thumb(NNSiFndHeapHead *firstHeap, NNSiFndHeapHead *courseBufferHeap, NNSiFndHeapHead *lastHeap);
void SetMountData_from_thumb(NNSiFndHeapHead *heap, s32 bufferIndex, s32 sizeInKb, u32 uncompress, u32 flag);
void ReleaseKartModelLoadSlotsForScene(void);
void Dispose_CST_Mount_K2D_R2D_MAR_from_thumb(void);
void Dispose_KM2_KSB_Mount_CRS_from_thumb(void);
void Dispose_KM1_Mount_KM2_from_thumb(void);
void *FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(const char *path);
void *FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(const char *name);
void SetActiveExecutionContextHeapGroupId_from_thumb(u32 groupId);
void Arc_DisposeAllArchives_from_thumb(void);
void MountArchivesForScene_from_thumb(s32 sceneNumber);
void Arc_DisposeArchive_from_thumb(int slotIndex);
void MountCurrentMountEntry_from_thumb(void);
void DecompressCurrentMountEntry_from_thumb(void);
void ReadDecompressCurrentMountEntry_from_thumb(void);
void MountArchiveEntryImpl_from_thumb(s32 slotIndex, const char *path, u32 *sourceData, void *data, s32 allocFromHeapEnd,
                     s32 uncompressSource, s32 archiveBufferSize);
void Arc_MountArchive_from_thumb(int slotIndex, int sceneNumber);
void FormatArchiveWithLanguage_from_thumb(const char *prefix, char *path);
void FormatRaceCarcWithLanguage_from_thumb(char *path, const char *sceneName, int mode);
void FormatSceneArchiveWithRaceMode_from_thumb(char *path, const char *sceneName, int mode);
void FormatStaffRollCarcWithLanguage_from_thumb(char *path);
void FormatResultCarcWithLanguage_from_thumb(char *path);
void FormatResultCarc_from_thumb(char *path);

extern const SceneName g_SceneArchiveNameTable[16];
extern const CourseNameEntry g_CourseNameTable[55];
extern const ArchiveSlotInfo gArchiveSlotInfos[21];
extern const char *g_RaceModeNameTable[6];
extern const char *g_LanguageIdentifierTable[7];
extern const char *gArchiveNames[20];
extern char g_SomeEmptyString1[];
extern char g_SomeEmptyString2[];
extern char g_SomeEmptyString3[];
extern char g_SomeEmptyString4[];
extern char g_SomeEmptyString5[];
extern char g_SomeEmptyString0[];
extern char gArchiveSlotInfosEmptyPath20[];
extern char gArchiveSlotInfosEmptyPath9[];
extern char gArchiveSlotInfosEmptyPath11[];
extern char gArchiveSlotInfosEmptyPath19[];
extern char g_mount_mr[];
extern char g_mount_gp[];
extern char g_mount_it[];
extern char g_mount_vs[];
extern char g_mount_ta[];
extern char g_mount_mg[];
extern char g_mount_us[];
extern char g_mount_fr[];
extern char g_mount_us_0[];
extern char g_mount_nt[];
extern char g_mount_ja[];
extern char g_mount_ge[];
extern char g_mount_es[];
extern char g_mount_R2D[];
extern char g_mount_GE2[];
extern char g_mount_KME[];
extern char g_mount_CKL[];
extern char g_mount_EFT[];
extern char g_mount_M2L[];
extern char g_mount_SND[];
extern char g_mount_R2L[];
extern char g_mount_S2D[];
extern char g_mount_K2D[];
extern char g_mount_CST[];
extern char g_mount_MA2[];
extern char g_mount_KM1[];
extern char g_mount_KSB[];
extern char g_mount_LOC[];
extern char g_mount_G2L[];
extern char g_mount_CRS[];
extern char g_mount_KM2[];
extern char g_mount_CKS[];
extern char g_mount_MAR[];
extern char gSceneNameMenu1[];
extern char gSceneNameRace[];
extern char gSceneNameMenu4[];
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
extern char g_str_data_Main2D[];
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
extern char g_str_data_Main2D_carc[];
extern char g_SomeTypeCarcNames[];
extern char g_str_data_MainEffect_carc[];
extern char g_str_data_GeneralMenu_carc[];
extern char g_str_data_KartModelSub_carc[];
extern char g_data_KartModelMenu_carc[];
extern char g_data_CharacterKartSelect_carc[];
extern char g_data_KartModelMainA_carc[];
extern char g_data_KartModelMainB_carc[];
extern char g_data_CharacterKartSelect_carc_0[];
