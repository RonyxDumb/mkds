#include "Main/System/result_archive_path.h"

#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/System/archive_buffer.h"
#include "Main/System/compressed_archive.h"
#include "Main/Net/search_icon_mb_child_and.h"
#include "Main/Sound/mic_init.h"
#include "Main/Race/race_scene_callbacks.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "code_020176c0.h"
#include "Main/System/archive_slots.h"
#include "Main/System/backup_net_camera_work.h"
#include "expheap.h"
#include "Main/Net/pending_files.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Kart/kart_name_tags.h"
#include "os_printf.h"
#include "code_02003be0.h"
#include "code_0200eddc.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "fs_file.h"
#include "Main/Menu/select_race_rule_state.h"
#include "mi_uncomp_stream.h"
#include "code_0214d564.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"


#pragma explicit_zero_data on
char gArchiveSlotInfosEmptyPath19[] = "";
char gArchiveSlotInfosEmptyPath4[] = "";
char gArchiveSlotInfosEmptyPath5[] = "";
char gArchiveSlotInfosEmptyPath20[] = "";
char gArchiveSlotInfosEmptyPath11[] = "";
char gArchiveSlotInfosEmptyPath9[] = "";
char gCourseArchiveNamesEmptyName0[] = "";
char gArchiveSlotInfosEmptyPath13[] = "";
char gArchiveSlotInfosEmptyPath3[] = "";
char gArchiveSlotInfosEmptyPath12[] = "";
#pragma explicit_zero_data off
char gModeArchiveNameNt[] = "nt";
char gModeArchiveNameGp[] = "gp";
char gLanguageCodeFr[] = "fr";
char gLanguageCodeGe[] = "ge";
char gModeArchiveNameVs[] = "vs";
char gLanguageCodeIt[] = "it";
char gLanguageCodeUs6[] = "us";
char gModeArchiveNameTa[] = "ta";
char gModeArchiveNameMg[] = "mg";
char gLanguageCodeEs[] = "es";
char gModeArchiveNameMr[] = "mr";
char gLanguageCodeUs1[] = "us";
char gLanguageCodeJa[] = "ja";
char gArchiveNameCKL[] = "CKL";
char gArchiveNameCRS[] = "CRS";
char gArchiveNameEFT[] = "EFT";
char gArchiveNameKME[] = "KME";
char gArchiveNameM2L[] = "M2L";
char gArchiveNameCKS[] = "CKS";
char gArchiveNameG2L[] = "G2L";
char gArchiveNameKM2[] = "KM2";
char gArchiveNameLOC[] = "LOC";
char gArchiveNameK2D[] = "K2D";
char gArchiveNameR2L[] = "R2L";
char gArchiveNameR2D[] = "R2D";
char gArchiveNameS2D[] = "S2D";
char gArchiveNameGE2[] = "GE2";
char gArchiveNameKSB[] = "KSB";
char gArchiveNameSND[] = "SND";
char gArchiveNameMAR[] = "MAR";
char gArchiveNameKM1[] = "KM1";
char gArchiveNameMA2[] = "MA2";
char gArchiveNameCST[] = "CST";
char gSceneNameRace[] = "Race";
char gSceneNameMenu1[] = "Menu";
char gSceneNameMenu4[] = "Menu";
char gSceneNameLogo[] = "Logo";
char gSceneNameTest[] = "Test";
char gCourseArchiveNameAward[] = "Award";
char gSceneNameTitle[] = "Title";
char gSceneNameGhost[] = "Ghost";
char gSceneNameWLMenu[] = "WLMenu";
char gSceneNameEmblem[] = "Emblem";
char gSceneNameOption[] = "Option";
char gSceneNameRecord[] = "Record";
char gSceneNameResult[] = "Result";
char gSceneNameEnding[] = "Ending";
char gSceneNameNickname[] = "Nickname";
char gSceneNameWiFiMenu[] = "WiFiMenu";
char gSceneNameKeyboard[] = "Keyboard";
char gCourseArchiveNameMrStage1[] = "mr_stage1";
char gCourseArchiveNameMrStage3[] = "mr_stage3";
char gCourseArchiveNameMrStage4[] = "mr_stage4";
char gCourseArchiveNameStaffRoll[] = "StaffRoll";
char gCourseArchiveNameMrStage2[] = "mr_stage2";
char gCourseArchiveNameOldBabyGc[] = "old_baby_gc";
char gCourseArchiveNameTestCircle[] = "test_circle";
char gCourseArchiveNameBankCourse[] = "bank_course";
char gCourseArchiveNameTownCourse[] = "town_course";
char gCourseArchiveNameSnowCourse[] = "snow_course";
char gCourseArchiveNameOldSkyAgb[] = "old_sky_agb";
char gCourseArchiveNameMiniStage1[] = "mini_stage1";
char gCourseArchiveNameMiniStage2[] = "mini_stage2";
char gCourseArchiveNameMiniStage3[] = "mini_stage3";
char gCourseArchiveNameMiniStage4[] = "mini_stage4";
char gCourseArchiveNameOldMomo64[] = "old_momo_64";
char gCourseArchiveNameMarioCourse[] = "mario_course";
char gCourseArchiveNameBeachCourse[] = "beach_course";
char gCourseArchiveNameKoopaCourse[] = "koopa_course";
char gCourseArchiveNameOldChoco64[] = "old_choco_64";
char gCourseArchiveNameOldYoshiGc[] = "old_yoshi_gc";
char gArchiveSlotPathDataMain2D[] = "/data/Main2D";
char gCourseArchiveNameOldMarioGc[] = "old_mario_gc";
char gCourseArchiveNameLuigiCourse[] = "luigi_course";
char gCourseArchiveNameDokanCourse[] = "dokan_course";
char gCourseArchiveNameTest1Course[] = "test1_course";
char gCourseArchiveNameWarioCourse[] = "wario_course";
char gCourseArchiveNameOldLuigiGc[] = "old_luigi_gc";
char gCourseArchiveNameOldNokoSfc[] = "old_noko_sfc";
char gCourseArchiveNameClockCourse[] = "clock_course";
char gCourseArchiveNameCrossCourse[] = "cross_course";
char gCourseArchiveNameRidgeCourse[] = "ridge_course";
char gCourseArchiveNameMiniBlock64[] = "mini_block_64";
char gCourseArchiveNameMiniDokanGc[] = "mini_dokan_gc";
char gCourseArchiveNameStaffRollTrue[] = "StaffRollTrue";
char gCourseArchiveNameDonkeyCourse[] = "donkey_course";
char gCourseArchiveNameOldMarioSfc[] = "old_mario_sfc";
char gCourseArchiveNameOldKoopaAgb[] = "old_koopa_agb";
char gCourseArchiveNameOldPeachAgb[] = "old_peach_agb";
char gCourseArchiveNameOldFrappe64[] = "old_frappe_64";
char gCourseArchiveNameGardenCourse[] = "garden_course";
char gCourseArchiveNameDesertCourse[] = "desert_course";
char gCourseArchiveNameOldDonutSfc[] = "old_donut_sfc";
char gCourseArchiveNameOldLuigiAgb[] = "old_luigi_agb";
char gCourseArchiveNameOldKinokoGc[] = "old_kinoko_gc";
char gCourseArchiveNameOldChocoSfc[] = "old_choco_sfc";
char gCourseArchiveNameRainbowCourse[] = "rainbow_course";
char gCourseArchiveNamePinballCourse[] = "pinball_course";
char gCourseArchiveNameStadiumCourse[] = "stadium_course";
char gCourseArchiveNameMansionCourse[] = "mansion_course";
char gCourseArchiveNameAirshipCourse[] = "airship_course";
char gCourseArchiveNameOldHyudoro64[] = "old_hyudoro_64";
char gCourseArchiveNameNokonokoCourse[] = "nokonoko_course";
char gCourseArchiveNameMiniBlockCourse[] = "mini_block_course";
char gArchiveSlotPathDataGeneralMenu[] = "/data/GeneralMenu";
char gArchiveSlotPathDataMain2DCarc[] = "/data/Main2D.carc";
char gArchiveSlotPathDataMainRaceCarc[] = "/data/MainRace.carc";
char gArchiveSlotPathDataMainEffectCarc[] = "/data/MainEffect.carc";
char gArchiveSlotPathDataGeneralMenuCarc[] = "/data/GeneralMenu.carc";
const char *gModeArchiveNames[6] = {gModeArchiveNameGp, gModeArchiveNameTa, gModeArchiveNameMg,
                                    gModeArchiveNameVs, gModeArchiveNameMr, gModeArchiveNameNt};
char gArchiveSlotPathDataKartModelMenuCarc[] = "/data/KartModelMenu.carc";
char gArchiveSlotPathDataCharacterKartSelect[] = "/data/CharacterKartSelect";
char gArchiveSlotPathDataKartModelMainACarc[] = "/data/KartModelMainA.carc";
char gArchiveSlotPathDataKartModelMainBCarc[] = "/data/KartModelMainB.carc";
char gArchiveSlotPathDataCharacterKartSelectCarc[] = "/data/CharacterKartSelect.carc";

const SceneName gSceneNames[16] = {
    {gSceneNameTitle, -1},
    {gSceneNameMenu1, 184320},
    {gSceneNameRace, -1},
    {gSceneNameEmblem, -1},
    {gSceneNameMenu4, -1},
    {gSceneNameTest, -1},
    {gSceneNameWLMenu, -1},
    {gSceneNameOption, -1},
    {gSceneNameRecord, -1},
    {gSceneNameLogo, -1},
    {gSceneNameResult, 665600},
    {gSceneNameNickname, -1},
    {gSceneNameWiFiMenu, -1},
    {gSceneNameGhost, -1},
    {gSceneNameKeyboard, -1},
    {gSceneNameEnding, -1},
};

const CourseNameEntry gCourseArchiveNames[55] = {
    {gCourseArchiveNamesEmptyName0, 2},
    {gCourseArchiveNameOldYoshiGc, 0},
    {gCourseArchiveNameOldMarioGc, 0},
    {gCourseArchiveNameLuigiCourse, 0},
    {gCourseArchiveNameDokanCourse, 0},
    {gCourseArchiveNameTest1Course, 0},
    {gCourseArchiveNameDonkeyCourse, 0},
    {gCourseArchiveNameWarioCourse, 0},
    {gCourseArchiveNameNokonokoCourse, 0},
    {gCourseArchiveNameOldBabyGc, 0},
    {gCourseArchiveNameOldMarioSfc, 0},
    {gCourseArchiveNameOldMomo64, 1},
    {gCourseArchiveNameOldKoopaAgb, 0},
    {gCourseArchiveNameOldPeachAgb, 0},
    {gCourseArchiveNameOldLuigiGc, 1},
    {gCourseArchiveNameOldNokoSfc, 0},
    {gCourseArchiveNameOldFrappe64, 0},
    {gCourseArchiveNameClockCourse, 0},
    {gCourseArchiveNameMansionCourse, 1},
    {gCourseArchiveNameAirshipCourse, 0},
    {gCourseArchiveNameCrossCourse, 1},
    {gCourseArchiveNameTestCircle, 0},
    {gCourseArchiveNameBankCourse, 0},
    {gCourseArchiveNameOldHyudoro64, 0},
    {gCourseArchiveNameRidgeCourse, 0},
    {gCourseArchiveNameMarioCourse, 0},
    {gCourseArchiveNameGardenCourse, 0},
    {gCourseArchiveNameDesertCourse, 0},
    {gCourseArchiveNameTownCourse, 0},
    {gCourseArchiveNameRainbowCourse, 0},
    {gCourseArchiveNameSnowCourse, 0},
    {gCourseArchiveNameBeachCourse, 1},
    {gCourseArchiveNameKoopaCourse, 0},
    {gCourseArchiveNamePinballCourse, 0},
    {gCourseArchiveNameStadiumCourse, 0},
    {gCourseArchiveNameOldDonutSfc, 0},
    {gCourseArchiveNameOldChoco64, 0},
    {gCourseArchiveNameOldLuigiAgb, 0},
    {gCourseArchiveNameOldKinokoGc, 0},
    {gCourseArchiveNameOldChocoSfc, 0},
    {gCourseArchiveNameOldSkyAgb, 0},
    {gCourseArchiveNameMiniBlockCourse, 0},
    {gCourseArchiveNameMiniBlock64, 0},
    {gCourseArchiveNameMiniDokanGc, 0},
    {gCourseArchiveNameMiniStage1, 0},
    {gCourseArchiveNameMiniStage2, 0},
    {gCourseArchiveNameMiniStage3, 0},
    {gCourseArchiveNameMiniStage4, 0},
    {gCourseArchiveNameMrStage1, 0},
    {gCourseArchiveNameMrStage2, 0},
    {gCourseArchiveNameMrStage3, 0},
    {gCourseArchiveNameMrStage4, 0},
    {gCourseArchiveNameAward, 0},
    {gCourseArchiveNameStaffRoll, 0},
    {gCourseArchiveNameStaffRollTrue, 0},
};

const ArchiveSlotInfo gArchiveSlotInfos[21] = {
    {gArchiveSlotPathDataMainRaceCarc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_MAIN_RACE, {0, 0, 0}, 0, 0, -1},
    {gArchiveSlotPathDataMain2DCarc, ARCHIVE_SLOT_MAIN_2D_LANGUAGE, ARCHIVE_BUFFER_MAIN_2D, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataMain2D, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_MAIN_2D_LANGUAGE, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath3, ARCHIVE_SLOT_COURSE_TEXTURE, ARCHIVE_BUFFER_COURSE, {0, 0, 0}, 0, 0, -1},
    {gArchiveSlotInfosEmptyPath4, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 0, 0, -1},
    {gArchiveSlotInfosEmptyPath5, ARCHIVE_SLOT_SCENE_LANGUAGE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataKartModelMainACarc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_KART_MODEL_MAIN_A, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotPathDataKartModelMainBCarc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_KART_MODEL_MAIN_B, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotPathDataKartModelSubCarc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotInfosEmptyPath9, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, 286720},
    {gArchiveSlotPathDataKartModelMenuCarc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotInfosEmptyPath11, ARCHIVE_SLOT_SCENE_MODE_LANGUAGE, ARCHIVE_BUFFER_RACE_MODE, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath12, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_RACE_MODE_LANGUAGE, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath13, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_COURSE_TEXTURE, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotPathDataCharacterKartSelectCarc,
     ARCHIVE_SLOT_CHARACTER_KART_SELECT_LANGUAGE,
     ARCHIVE_BUFFER_NONE,
     {0, 0, 0},
     1,
     0,
     -1},
    {gArchiveSlotPathDataCharacterKartSelect, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataGeneralMenuCarc, ARCHIVE_SLOT_GENERAL_MENU_LANGUAGE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataGeneralMenu, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataMainEffectCarc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_MAIN_EFFECT, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath19, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath20, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 0, 0, -1},
};

char gArchiveSlotPathDataKartModelSubCarc[] = "/data/KartModelSub.carc";
const char *gLanguageCodes[7] = {gLanguageCodeJa, gLanguageCodeUs1, gLanguageCodeFr, gLanguageCodeGe,
                                 gLanguageCodeIt, gLanguageCodeEs,  gLanguageCodeUs6};
const char *gArchiveNames[20] = {gArchiveNameMAR, gArchiveNameMA2, gArchiveNameM2L, gArchiveNameCRS, gArchiveNameSND,
                                 gArchiveNameK2D, gArchiveNameKM1, gArchiveNameKM2, gArchiveNameKSB, gArchiveNameLOC,
                                 gArchiveNameKME, gArchiveNameR2D, gArchiveNameR2L, gArchiveNameCST, gArchiveNameCKS,
                                 gArchiveNameCKL, gArchiveNameGE2, gArchiveNameG2L, gArchiveNameEFT, gArchiveNameS2D};

#pragma thumb on

void BuildResultArchivePath(char *path) {
    const char *suffix;

    if (gMenuShared->mResultArchiveDl == TRUE) {
        suffix = "DL";
    } else {
        suffix = "";
    }
    OS_SNPrintf(path, ARCHIVE_PATH_SIZE, "/data/Scene/%s%s%s", gSceneNames[SCENE_RESULT].mName, suffix, ".carc");
}

void BuildResultArchivePathWithLanguage(char *path) {
    const char *suffix;
    u32 languageCode;

    if (gMenuShared->mResultArchiveDl == TRUE) {
        suffix = "DL";
    } else {
        suffix = "";
    }
    languageCode = GetLanguageCode();
    OS_SNPrintf(path, ARCHIVE_PATH_SIZE, "/data/Scene/%s%s_%s%s", gSceneNames[SCENE_RESULT].mName, suffix, languageCode,
                ".carc");
}

#pragma thumb off

#pragma thumb on

void BuildStaffRollArchivePath(char *path) {
    u32 languageCode;
    languageCode = GetLanguageCode();
    OS_SNPrintf(path, ARCHIVE_PATH_SIZE, "/data/Scene/StaffRoll_%s%s", languageCode, ".carc");
}

void BuildSceneModeArchivePath(char *path, const char *sceneName, int mode) {
    if (*sceneName != 0) {
        OS_SNPrintf(path, ARCHIVE_PATH_SIZE, "/data/Scene/%s_%s%s", sceneName, gModeArchiveNames[mode], ".carc");
    }
}

void BuildSceneModeLanguageArchivePath(char *path, const char *sceneName, int mode) {
    u32 languageCode;
    if (*sceneName != 0) {
        languageCode = GetLanguageCode();
        OS_SNPrintf(path, ARCHIVE_PATH_SIZE, "/data/Scene/%s_%s_%s%s", sceneName, gModeArchiveNames[mode], languageCode,
                    ".carc");
    }
}

void BuildArchivePathWithLanguage(const char *prefix, char *path) {
    u32 languageCode;
    languageCode = GetLanguageCode();
    OS_SNPrintf(path, ARCHIVE_PATH_SIZE, "%s_%s.carc", prefix, languageCode);
}

#pragma thumb off

#pragma thumb on

void LoadArchiveSlotForScene(int slotIndex, int sceneNumber) {
    char path[ARCHIVE_PATH_SIZE] = {0};
    u32 *bufferData;
    s32 allocFromHeapEnd;
    s32 uncompressSource;
    s32 archiveBufferSize;
    s32 bufferIndex;

    bufferData = NULL;
    if (gArchiveSlots->mSlots[slotIndex].mLoaded != 0) {
        return;
    }
    uncompressSource = gArchiveSlotInfos[slotIndex].mUncompressSource;
    allocFromHeapEnd = gArchiveSlotInfos[slotIndex].mAllocFromHeapEnd;
    archiveBufferSize = gArchiveSlotInfos[slotIndex].mArchiveBufferSize;
    bufferIndex = gArchiveSlotInfos[slotIndex].mBufferIndex;
    if (bufferIndex != ARCHIVE_BUFFER_NONE) {
        bufferData = gArchiveSlots->mBuffers[bufferIndex].mData;
    }
    switch (slotIndex) {
        case ARCHIVE_SLOT_COURSE:
        case ARCHIVE_SLOT_COURSE_TEXTURE:
            BuildCourseArchivePath(path, gRaceSetup->mCourseId, slotIndex != ARCHIVE_SLOT_COURSE);
            break;
        case ARCHIVE_SLOT_SCENE:
            switch (sceneNumber) {
                case SCENE_RACE:
                    bufferData = gArchiveSlots->mBuffers[ARCHIVE_BUFFER_RACE].mData;
                    break;
                case SCENE_MENU_1:
                    bufferData = gArchiveSlots->mBuffers[ARCHIVE_BUFFER_MENU_DL].mData;
                    break;
                case SCENE_RESULT:
                    bufferData = gArchiveSlots->mBuffers[ARCHIVE_BUFFER_RESULT_DL].mData;
                    break;
            }
            switch (sceneNumber) {
                case SCENE_RESULT:
                    BuildResultArchivePath(path);
                    break;
                case SCENE_RACE:
                    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        OS_SNPrintf(path, ARCHIVE_PATH_SIZE, "/data/Scene/StaffRoll.carc");
                    } else {
                        BuildSceneArchivePath(path, gSceneNames[sceneNumber].mName);
                    }
                    break;
                default:
                    BuildSceneArchivePath(path, gSceneNames[sceneNumber].mName);
                    break;
            }
            archiveBufferSize = gSceneNames[sceneNumber].mArchiveBufferSize;
            break;
        case ARCHIVE_SLOT_SCENE_LANGUAGE:
            switch (sceneNumber) {
                case SCENE_RACE:
                    bufferData = gArchiveSlots->mBuffers[ARCHIVE_BUFFER_RACE_LANGUAGE].mData;
                    break;
                case SCENE_MENU_1:
                    bufferData = gArchiveSlots->mBuffers[ARCHIVE_BUFFER_MENU_DL_LANGUAGE].mData;
                    break;
                case SCENE_RESULT:
                    bufferData = gArchiveSlots->mBuffers[ARCHIVE_BUFFER_RESULT_DL_LANGUAGE].mData;
                    break;
            }
            switch (sceneNumber) {
                case SCENE_RESULT:
                    BuildResultArchivePathWithLanguage(path);
                    break;
                case SCENE_RACE:
                    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        BuildStaffRollArchivePath(path);
                    } else {
                        BuildSceneArchivePathWithLanguage(path, gSceneNames[sceneNumber].mName);
                    }
                    break;
                default:
                    BuildSceneArchivePathWithLanguage(path, gSceneNames[sceneNumber].mName);
                    break;
            }
            break;
        case ARCHIVE_SLOT_SCENE_MODE:
            BuildSceneModeArchivePath(path, gSceneNames[sceneNumber].mName, gRaceSetup->mMode);
            break;
        case ARCHIVE_SLOT_SCENE_MODE_LANGUAGE:
            BuildSceneModeLanguageArchivePath(path, gSceneNames[sceneNumber].mName, gRaceSetup->mMode);
            break;
        case ARCHIVE_SLOT_MAIN_2D_LANGUAGE:
        case ARCHIVE_SLOT_CHARACTER_KART_SELECT_LANGUAGE:
        case ARCHIVE_SLOT_GENERAL_MENU_LANGUAGE:
            BuildArchivePathWithLanguage(gArchiveSlotInfos[slotIndex].mPath, path);
            break;
        case ARCHIVE_SLOT_MAIN_RACE:
        case ARCHIVE_SLOT_MAIN_2D:
        case ARCHIVE_SLOT_KART_MODEL_MAIN_A:
        case ARCHIVE_SLOT_KART_MODEL_MAIN_B:
        case ARCHIVE_SLOT_KART_MODEL_SUB:
        case ARCHIVE_SLOT_KART_MODEL_MENU:
        case ARCHIVE_SLOT_CHARACTER_KART_SELECT:
        case ARCHIVE_SLOT_GENERAL_MENU:
        case ARCHIVE_SLOT_MAIN_EFFECT:
            strncpy(path, gArchiveSlotInfos[(s32) slotIndex].mPath, ARCHIVE_PATH_SIZE);
            break;
    }
    if (path[0] != 0) {
        LoadArchiveSlot(slotIndex, path, bufferData, NULL, allocFromHeapEnd, uncompressSource, archiveBufferSize);
    }
    bufferIndex = *(s32 *) ((s32) &gArchiveSlotInfos[0].mNextSlot + slotIndex * 0x18);
    if (bufferIndex != ARCHIVE_SLOT_NONE) {
        LoadArchiveSlotForScene(bufferIndex, sceneNumber);
    }
}

void LoadArchiveSlot(s32 slotIndex, const char *path, u32 *sourceData, void *data, s32 allocFromHeapEnd,
                     s32 uncompressSource, s32 archiveBufferSize) {
    ArchiveLoadRequest *request;
    s32 bufferIndex;

    request = &gArchiveSlots->mLoadRequest;
    strncpy((char *) request->mPath, path, ARCHIVE_PATH_SIZE);
    request->mSlotIndex = slotIndex;
    request->mSourceData = sourceData;
    request->mData = data;
    request->mAllocFromHeapEnd = allocFromHeapEnd;
    request->mUncompressSource = uncompressSource;
    request->mArchiveBufferSize = archiveBufferSize;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        if (request->mSourceData != NULL) {
            if (request->mUncompressSource != 0) {
                bufferIndex = gArchiveSlotInfos[slotIndex].mBufferIndex;
                if (bufferIndex != ARCHIVE_BUFFER_NONE) {
                    gArchiveSlots->mBuffers[bufferIndex].mUnk_08_31 = 1;
                }
                UncompressArchiveMemory();
            } else {
                request->mData = request->mSourceData;
            }
            LoadArchiveSlotData();
        }
    } else {
        if (slotIndex == ARCHIVE_SLOT_IN_MEMORY) {
            UncompressArchiveMemory();
        } else {
            UncompressArchiveFile();
        }
        LoadArchiveSlotData();
    }
}

void UncompressArchiveFile(void) {
    ArchiveLoadRequest *request;
    FSFile file;
    MIUncompContextLZ uncompContext;
    u32 uncompressedSize;
    s32 bytesRead;

    request = &gArchiveSlots->mLoadRequest;
    FS_InitFile(&file);
    if (FS_OpenFile(&file, request->mPath) == 0) {
        return;
    }
    if (FS_ReadFile(&file, request->mReadBuffer, 4) < 0) {
        return;
    }
    uncompressedSize = *request->mReadBuffer >> 8;
    if (uncompressedSize > 0x200000) {
        return;
    }
    if (request->mAllocFromHeapEnd != 0) {
        request->mData = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), uncompressedSize, -0x20);
    } else {
        request->mData = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), uncompressedSize, HEAP_ALIGN_CACHE_LINE);
    }
    MI_InitUncompContextLZ(&uncompContext, request->mData, (const MICompressionHeader *) request->mReadBuffer);
    do {
        bytesRead = FS_ReadFile(&file, request->mReadBuffer, 0x400);
        if (bytesRead <= 0) {
            return;
        }
    } while (MI_ReadUncompLZ8(&uncompContext, (const u8 *) request->mReadBuffer, bytesRead) != 0);
    DC_StoreRange(request->mData, uncompressedSize);
    NNS_FndGetTotalFreeSizeForExpHeap(GetHeap(GetCurrentHeapCall()));
}

void UncompressArchiveMemory(void) {
    ArchiveLoadRequest *request;
    u32 uncompressedSize;

    request = &gArchiveSlots->mLoadRequest;
    uncompressedSize = *request->mSourceData >> 8;
    if (request->mAllocFromHeapEnd != 0) {
        request->mData = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), uncompressedSize, -0x20);
    } else {
        request->mData = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), uncompressedSize, HEAP_ALIGN_CACHE_LINE);
    }
    MI_UncompressLZ8(request->mSourceData, request->mData);
    DC_StoreRange(request->mData, uncompressedSize);
    NNS_FndGetTotalFreeSizeForExpHeap(GetHeap(GetCurrentHeapCall()));
}

void LoadArchiveSlotData(void) {
    ArchiveLoadRequest *request;
    ArchiveSlot *slot;

    request = &gArchiveSlots->mLoadRequest;
    slot = &gArchiveSlots->mSlots[request->mSlotIndex];
    if (request->mData != NULL) {
        if (ArchiveLoadFromMemory(&slot->mArchive, (const u8 *) gArchiveNames[request->mSlotIndex], request->mData) !=
            0) {
            slot->mLoaded = 1;
            slot->mData = request->mData;
        }
    }
}

void ReleaseArchiveSlot(int slotIndex) {
    BOOL shouldFree;
    s32 bufferIndex;

    shouldFree = TRUE;
    if (gArchiveSlots->mSlots[slotIndex].mLoaded != 0 && slotIndex != ARCHIVE_SLOT_IN_MEMORY) {
        ArchiveUnload(&gArchiveSlots->mSlots[slotIndex].mArchive.mFsArchive);
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            bufferIndex = gArchiveSlotInfos[slotIndex].mBufferIndex;
            if (bufferIndex != ARCHIVE_BUFFER_NONE && gArchiveSlots->mBuffers[bufferIndex].mUncompress != 0) {
                shouldFree = FALSE;
            } else {
                gArchiveSlots->mBuffers[bufferIndex].mUnk_08_31 = 1;
            }
        }
        if (shouldFree != FALSE) {
            HeapFree(GetHeap(GetCurrentHeapCall()), gArchiveSlots->mSlots[slotIndex].mData);
        }
        gArchiveSlots->mSlots[slotIndex].mLoaded = 0;
        gArchiveSlots->mSlots[slotIndex].mData = 0;
        NNS_FndGetTotalFreeSizeForExpHeap(GetHeap(GetCurrentHeapCall()));
    }
}

void LoadArchiveSlotsForScene(s32 sceneNumber) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT && sceneNumber == SCENE_WL_MENU && gMenuShared->mWLMenuKind == 0) {
    } else {
        LoadArchiveSlotForScene(ARCHIVE_SLOT_MAIN_2D, sceneNumber);
    }
    switch (sceneNumber) {
        case SCENE_MENU_1:
        case SCENE_WIFI_MENU:
            LoadArchiveSlotForScene(ARCHIVE_SLOT_SCENE, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_CHARACTER_KART_SELECT, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            break;
        case SCENE_RESULT:
            LoadArchiveSlotForScene(ARCHIVE_SLOT_MAIN_RACE, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_SCENE, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_MAIN_EFFECT, sceneNumber);
            break;
        case SCENE_RACE:
            LoadArchiveSlotForScene(ARCHIVE_SLOT_MAIN_EFFECT, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_KART_MODEL_MAIN_A, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_KART_MODEL_SUB, sceneNumber);
            break;
        case SCENE_EMBLEM:
            LoadArchiveSlotForScene(ARCHIVE_SLOT_MAIN_RACE, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_SCENE, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            break;
        case SCENE_TEST:
            LoadArchiveSlotForScene(ARCHIVE_SLOT_SCENE, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_CHARACTER_KART_SELECT, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            break;
        case SCENE_TITLE:
        case SCENE_OPTION:
        case SCENE_RECORD:
        case SCENE_LOGO:
        case SCENE_NICKNAME:
        case SCENE_GHOST:
        case SCENE_KEYBOARD:
        case SCENE_ENDING:
            LoadArchiveSlotForScene(ARCHIVE_SLOT_SCENE, sceneNumber);
            LoadArchiveSlotForScene(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            break;
        case SCENE_MENU_4:
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                LoadArchiveSlotForScene(ARCHIVE_SLOT_SCENE, sceneNumber);
                LoadArchiveSlotForScene(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            }
            break;
        case SCENE_WL_MENU:
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                LoadArchiveSlotForScene(ARCHIVE_SLOT_SCENE, sceneNumber);
                LoadArchiveSlotForScene(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            }
            break;
    }
}

void ReleaseArchiveSlots(void) {
    s32 slotIndex;

    for (slotIndex = 0; slotIndex < ARCHIVE_SLOT_COUNT; slotIndex++) {
        ReleaseArchiveSlot(slotIndex);
    }
}

#pragma thumb off

#pragma thumb on
void SetHeapGroupId(u32 groupId) {
    NNS_FndSetGroupIDForExpHeap(GetHeap(GetCurrentHeapCall()), groupId);
}
#pragma thumb off

#pragma thumb on

void *FindArchiveFile(const char *archiveName, const char *path) {
    char fullPath[ARCHIVE_PATH_SIZE];

    if (path[0] == '/') {
        OS_SNPrintf(fullPath, ARCHIVE_PATH_SIZE, "%s:%s", archiveName, path);
    } else {
        OS_SNPrintf(fullPath, ARCHIVE_PATH_SIZE, "%s:/%s", archiveName, path);
    }
    return ArchiveFileGetAddress((const u8 *) fullPath);
}

#pragma thumb off

#pragma thumb on

void *FindMainRaceOrMainEffectFile(const char *path) {
    void *file;
    file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_MAIN_RACE], path);
    if (file == NULL) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_MAIN_EFFECT], path);
    }
    return file;
}

#pragma thumb off

#pragma thumb on

// Searches the archives that are loaded, in a fixed order, and returns the first match.
void *FindFileInLoadedArchives(const char *path) {
    void *file;

    file = NULL;
    if (gArchiveSlots->mSlots[ARCHIVE_SLOT_GENERAL_MENU_LANGUAGE].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_GENERAL_MENU_LANGUAGE], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_GENERAL_MENU].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_GENERAL_MENU], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_CHARACTER_KART_SELECT_LANGUAGE].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_CHARACTER_KART_SELECT_LANGUAGE], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_CHARACTER_KART_SELECT].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_CHARACTER_KART_SELECT], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_IN_MEMORY].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_IN_MEMORY], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_MAIN_2D_LANGUAGE].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_MAIN_2D_LANGUAGE], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_MAIN_2D].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_MAIN_2D], path);
    }
    return file;
}

void *FindSceneFile(const char *path) {
    void *file;

    file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_SCENE], path);
    if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_SCENE_LANGUAGE].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_SCENE_LANGUAGE], path);
    }
    if (GetCurrentSceneNumber() == SCENE_RACE) {
        if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_SCENE_MODE].mLoaded != 0) {
            file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_SCENE_MODE], path);
        }
        if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_SCENE_MODE_LANGUAGE].mLoaded != 0) {
            file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_SCENE_MODE_LANGUAGE], path);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void *FindCourseFile(const char *path) {
    void *file;
    file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_COURSE], path);
    if (file == NULL) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_COURSE_TEXTURE], path);
    }
    return file;
}

void *GetKartModelFile(const char *path) {
    int currentSceneNumber;
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == SCENE_EMBLEM) {
        return FindKartModelFile(path);
    }
    return LoadKartModelFile(path);
}

void *FindKartModelFile(const char *path) {
    int currentSceneNumber;
    void *file;
    file = NULL;
    currentSceneNumber = GetCurrentSceneNumber();
    if (((currentSceneNumber == SCENE_MENU_1) || (currentSceneNumber == SCENE_EMBLEM)) ||
        (currentSceneNumber == SCENE_WIFI_MENU)) {
        file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MENU], path);
    } else {
        if (gArchiveSlots->mSlots[ARCHIVE_SLOT_KART_MODEL_MAIN_A].mLoaded != 0) {
            file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MAIN_A], path);
        }
        if ((file == NULL) && (gArchiveSlots->mSlots[ARCHIVE_SLOT_KART_MODEL_MAIN_B].mLoaded != 0)) {
            file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MAIN_B], path);
        }
        if ((file == NULL) && (gArchiveSlots->mSlots[ARCHIVE_SLOT_KART_MODEL_SUB].mLoaded != 0)) {
            file = FindArchiveFile(gArchiveNames[ARCHIVE_SLOT_KART_MODEL_SUB], path);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void *LoadKartModelFile(const char *path) {
    void *file;
    s32 currentSceneNumber;
    char fullPath[ARCHIVE_PATH_SIZE];
    const char *archiveName;

    file = NULL;
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == SCENE_MENU_1 || currentSceneNumber == SCENE_EMBLEM ||
        currentSceneNumber == SCENE_WIFI_MENU) {
        archiveName = gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MENU];
        if (path[0] == '/') {
            OS_SNPrintf(fullPath, ARCHIVE_PATH_SIZE, "%s:%s", archiveName, path);
        } else {
            OS_SNPrintf(fullPath, ARCHIVE_PATH_SIZE, "%s:/%s", archiveName, path);
        }
        file = LoadFileAligned(fullPath, 8);
    } else {
        if (gArchiveSlots->mSlots[ARCHIVE_SLOT_KART_MODEL_MAIN_A].mLoaded != 0) {
            archiveName = gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MAIN_A];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, ARCHIVE_PATH_SIZE, "%s:%s", archiveName, path);
            } else {
                OS_SNPrintf(fullPath, ARCHIVE_PATH_SIZE, "%s:/%s", archiveName, path);
            }
            file = LoadFileAligned(fullPath, 8);
        }
        if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_KART_MODEL_MAIN_B].mLoaded != 0) {
            archiveName = gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MAIN_B];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, ARCHIVE_PATH_SIZE, "%s:%s", archiveName, path);
            } else {
                OS_SNPrintf(fullPath, ARCHIVE_PATH_SIZE, "%s:/%s", archiveName, path);
            }
            file = LoadFileAligned(fullPath, 8);
        }
        if (file == NULL && gArchiveSlots->mSlots[ARCHIVE_SLOT_KART_MODEL_SUB].mLoaded != 0) {
            archiveName = gArchiveNames[ARCHIVE_SLOT_KART_MODEL_SUB];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, ARCHIVE_PATH_SIZE, "%s:%s", archiveName, path);
            } else {
                OS_SNPrintf(fullPath, ARCHIVE_PATH_SIZE, "%s:/%s", archiveName, path);
            }
            file = LoadFileAligned(fullPath, 8);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void ReplaceKm1ArchiveWithKm2(void) {
    ReleaseArchiveSlot(ARCHIVE_SLOT_KART_MODEL_MAIN_A);
    SetHeapGroupId((u16) HEAP_GROUP_DEFAULT);
    LoadArchiveSlotForScene(ARCHIVE_SLOT_KART_MODEL_MAIN_B, SCENE_RACE);
    SetHeapGroupId((u16) HEAP_GROUP_SCENE);
}

void ReleaseKartModelSlotsLoadCourse(void) {
    int currentSceneNumber;
    ReleaseArchiveSlot(ARCHIVE_SLOT_KART_MODEL_MAIN_B);
    ReleaseArchiveSlot(ARCHIVE_SLOT_KART_MODEL_SUB);
    SetHeapGroupId((u16) HEAP_GROUP_DEFAULT);
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == SCENE_RACE) {
        LoadArchiveSlotForScene(ARCHIVE_SLOT_COURSE, SCENE_RACE);
    }
    SetHeapGroupId((u16) HEAP_GROUP_SCENE);
}

void ReleaseCourseLoadSlotsInRace(void) {
    int currentSceneNumber;
    ReleaseArchiveSlot(ARCHIVE_SLOT_COURSE_TEXTURE);
    SetHeapGroupId((u16) HEAP_GROUP_DEFAULT);
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == SCENE_RACE) {
        LoadArchiveSlotForScene(ARCHIVE_SLOT_SCENE, SCENE_RACE);
        LoadArchiveSlotForScene(ARCHIVE_SLOT_SCENE_MODE, SCENE_RACE);
        LoadArchiveSlotForScene(ARCHIVE_SLOT_MAIN_RACE, SCENE_RACE);
    }
    SetHeapGroupId((u16) HEAP_GROUP_SCENE);
}

void ReleaseKartModelLoadSlotsForScene(void) {
    u32 currentSceneNumber;
    currentSceneNumber = GetCurrentSceneNumber();
    ReleaseArchiveSlot(ARCHIVE_SLOT_KART_MODEL_MENU);
    SetHeapGroupId((u16) HEAP_GROUP_DEFAULT);
    LoadArchiveSlotForScene(ARCHIVE_SLOT_MAIN_2D, currentSceneNumber);
    LoadArchiveSlotForScene(ARCHIVE_SLOT_SCENE, currentSceneNumber);
    LoadArchiveSlotForScene(ARCHIVE_SLOT_CHARACTER_KART_SELECT, currentSceneNumber);
    LoadArchiveSlotForScene(ARCHIVE_SLOT_GENERAL_MENU, currentSceneNumber);
    SetHeapGroupId((u16) HEAP_GROUP_SCENE);
}

#pragma thumb off

#pragma thumb on

void InitArchiveBuffer(NNSiFndHeapHead *heap, s32 bufferIndex, s32 sizeInKb, u32 uncompress, u32 flag) {
    ArchiveBuffer *buffer = &gArchiveSlots->mBuffers[bufferIndex];
    buffer->mHeap = heap;
    buffer->mData = NULL;
    buffer->mByteSize = sizeInKb << 10;
    buffer->mUncompress = uncompress;
    buffer->mUnk_08_30 = flag;
    buffer->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

// Sets up 12 archive buffers on three heaps.
void InitArchiveBuffers(NNSiFndHeapHead *firstHeap, NNSiFndHeapHead *courseBufferHeap, NNSiFndHeapHead *lastHeap) {
    InitArchiveBuffer(lastHeap, ARCHIVE_BUFFER_RACE, 0x3c, 0, 1);
    InitArchiveBuffer(lastHeap, ARCHIVE_BUFFER_RACE_LANGUAGE, 0x32, 0, 1);
    InitArchiveBuffer(lastHeap, ARCHIVE_BUFFER_RACE_MODE, 5, 0, 1);
    InitArchiveBuffer(lastHeap, ARCHIVE_BUFFER_RACE_MODE_LANGUAGE, 5, 0, 1);
    InitArchiveBuffer(lastHeap, ARCHIVE_BUFFER_MENU_DL, 0x14, 0, 1);
    InitArchiveBuffer(lastHeap, ARCHIVE_BUFFER_MENU_DL_LANGUAGE, 0x14, 0, 1);
    InitArchiveBuffer(lastHeap, ARCHIVE_BUFFER_RESULT_DL, 0x46, 0, 1);
    InitArchiveBuffer(lastHeap, ARCHIVE_BUFFER_RESULT_DL_LANGUAGE, 0x46, 0, 1);
    InitArchiveBuffer(courseBufferHeap, ARCHIVE_BUFFER_COURSE, 200, 1, 1);
    InitArchiveBuffer(courseBufferHeap, ARCHIVE_BUFFER_COURSE_TEXTURE, 200, 0, 1);
    InitArchiveBuffer(firstHeap, ARCHIVE_BUFFER_MAIN_RACE, 0x46, 1, 0);
    InitArchiveBuffer(firstHeap, ARCHIVE_BUFFER_MAIN_EFFECT, 0x1e, 0, 0);
    gArchiveSlots->mFirstHeap = firstHeap;
    gArchiveSlots->mCourseBufferHeap = courseBufferHeap;
    gArchiveSlots->mLastHeap = lastHeap;
}

void InitArchiveBuffersOnOverlayHeap(void) {
    InitArchiveBuffer(gOverlayLoader->mFrmHeap, ARCHIVE_BUFFER_KART_MODEL_MAIN_A, 0xaa, 0, 0);
    InitArchiveBuffer(gOverlayLoader->mFrmHeap, ARCHIVE_BUFFER_KART_MODEL_MAIN_B, 0x6e, 0, 0);
    InitArchiveBuffer(gOverlayLoader->mFrmHeap, ARCHIVE_BUFFER_MAIN_2D, 0x1e, 0, 0);
    InitArchiveBuffer(gOverlayLoader->mFrmHeap, ARCHIVE_BUFFER_MAIN_2D_LANGUAGE, 0x1e, 0, 0);
}

#pragma thumb off

#pragma thumb on

void RequestArchiveLoad(const void *path, s32 bufferIndex) {
    ArchiveBuffer *buffer = &gArchiveSlots->mBuffers[bufferIndex];
    AddPendingFile(path, buffer->mHeap, &buffer->mData, buffer->mByteSize, buffer->mUncompress);
    buffer->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

void RequestArchiveLoadWithLanguage(const void *prefix, u32 bufferIndex) {
    u32 languageCode;
    char path[ARCHIVE_PATH_SIZE];
    languageCode = GetMPLanguageCode();
    OS_SNPrintf(path, ARCHIVE_PATH_SIZE, "%s%s.carc", prefix, languageCode);
    RequestArchiveLoad(path, bufferIndex);
}

void RequestMainAndMenuDLArchives(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArchiveSlots->mLastHeap, 3);
    RequestArchiveLoad("/data/KartModelMainA.carc", ARCHIVE_BUFFER_KART_MODEL_MAIN_A);
    RequestArchiveLoad("/data/KartModelMainB.carc", ARCHIVE_BUFFER_KART_MODEL_MAIN_B);
    RequestArchiveLoad("/data/Scene/MenuDL.carc", ARCHIVE_BUFFER_MENU_DL);
    RequestArchiveLoadWithLanguage("/data/Scene/MenuDL_", ARCHIVE_BUFFER_MENU_DL_LANGUAGE);
    RequestArchiveLoad("/data/MainRace.carc", ARCHIVE_BUFFER_MAIN_RACE);
    RequestArchiveLoad("/data/Main2D.carc", ARCHIVE_BUFFER_MAIN_2D);
    RequestArchiveLoadWithLanguage("/data/Main2D_", ARCHIVE_BUFFER_MAIN_2D_LANGUAGE);
    RequestArchiveLoad("/data/MainEffect.carc", ARCHIVE_BUFFER_MAIN_EFFECT);
}

void RequestMenuDLArchives(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArchiveSlots->mLastHeap, 3);
    RequestArchiveLoad("/data/Scene/MenuDL.carc", ARCHIVE_BUFFER_MENU_DL);
    RequestArchiveLoadWithLanguage("/data/Scene/MenuDL_", ARCHIVE_BUFFER_MENU_DL_LANGUAGE);
}

#pragma thumb off

#pragma thumb on

void RequestRaceArchives(void *courseId, void *kind) {
    char path[ARCHIVE_PATH_SIZE];
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArchiveSlots->mLastHeap, 3);
    RequestArchiveLoad("/data/Scene/Race.carc", ARCHIVE_BUFFER_RACE);
    RequestArchiveLoadWithLanguage("/data/Scene/Race_", ARCHIVE_BUFFER_RACE_LANGUAGE);
    if (kind == (void *) MODE_VS) {
        RequestArchiveLoad("/data/Scene/Race_vs.carc", ARCHIVE_BUFFER_RACE_MODE);
        RequestArchiveLoadWithLanguage("/data/Scene/Race_vs_", ARCHIVE_BUFFER_RACE_MODE_LANGUAGE);
    } else {
        RequestArchiveLoad("/data/Scene/Race_mg.carc", ARCHIVE_BUFFER_RACE_MODE);
        RequestArchiveLoadWithLanguage("/data/Scene/Race_mg_", ARCHIVE_BUFFER_RACE_MODE_LANGUAGE);
    }
    gArchiveSlots->mRaceKind = kind;
    NNS_FndFreeToFrmHeap(gArchiveSlots->mCourseBufferHeap, 3);
    BuildCourseArchivePath(path, (s32) courseId, 0);
    RequestArchiveLoad(path, ARCHIVE_BUFFER_COURSE);
    BuildCourseArchivePath(path, (s32) courseId, 1);
    RequestArchiveLoad(path, ARCHIVE_BUFFER_COURSE_TEXTURE);
    gArchiveSlots->mCourseId = courseId;
}

#pragma thumb off

#pragma thumb on

void RequestResultDLArchives(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArchiveSlots->mLastHeap, 3);
    RequestArchiveLoad("/data/Scene/ResultDL.carc", ARCHIVE_BUFFER_RESULT_DL);
    RequestArchiveLoadWithLanguage("/data/Scene/ResultDL_", ARCHIVE_BUFFER_RESULT_DL_LANGUAGE);
}

#pragma thumb off

#pragma thumb on

void ClearArchiveBuffersMap2DLoadFlag(void) {
    s32 bufferIndex;

    for (bufferIndex = 0; bufferIndex < ARCHIVE_BUFFER_COUNT; bufferIndex++) {
        gArchiveSlots->mBuffers[bufferIndex].mUnk_08_31 = 0;
    }
}

s32 ShouldLoadMap2DData(void) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return gArchiveSlots->mBuffers[ARCHIVE_BUFFER_COURSE_TEXTURE].mUnk_08 >> 31;
    }
    return 1;
}

// Resizes the block that holds the MainEffect archive so it ends where the caller says.
void ResizeMainEffectArchiveBlock(u8 *regionStart, u32 regionSize) {
    u8 *block;

    block = gArchiveSlots->mSlots[ARCHIVE_SLOT_MAIN_EFFECT].mData;
    NNS_FndResizeForMBlockExpHeap(GetHeap(GetCurrentHeapCall()), block, regionSize + (regionStart - block));
}

void InitCompressedArchiveAndMBChild(void *heap) {
    u32 uncompressedSize;
    void *data;

    uncompressedSize = *GetCompressedArchive() >> 8;
    gArchiveSlots->mSlots[ARCHIVE_SLOT_IN_MEMORY].mLoaded = 0;
    data = HeapAllocAligned(heap, uncompressedSize, HEAP_ALIGN_CACHE_LINE);
    UncompressLZ8AndStoreRange(GetCompressedArchive(), data, uncompressedSize);
    ArchiveLoadFromMemory(&gArchiveSlots->mSlots[ARCHIVE_SLOT_IN_MEMORY].mArchive,
                          (const u8 *) gArchiveNames[ARCHIVE_SLOT_IN_MEMORY], data);
    gArchiveSlots->mSlots[ARCHIVE_SLOT_IN_MEMORY].mData = data;
    gArchiveSlots->mSlots[ARCHIVE_SLOT_IN_MEMORY].mLoaded = 1;
    CreateSearchIconMBChildAndMultiDownload(heap);
}

#pragma thumb off

void InitTouchPanelAndSetCalibration(void) {
    TPCalibrateParam calibrateParam;

    TP_Init();
    if (TP_GetUserInfo(&calibrateParam) == 0) {
        return;
    }
    TP_SetCalibrateParam(&calibrateParam);
}

void InitTouchMicInput(void *heap) {
    gTouchMicInput = HeapAlloc(heap, sizeof(TouchMicInput));
    gTouchMicInput->mTouchAutoSampling = 0;
    gTouchMicInput->mMicAutoSampling = 0;
    gTouchMicInput->mMicPreSleepDone = 0;
    gTouchMicInput->mMicOverThreshold = 0;
    gTouchMicInput->mMicBuffer = NULL;
    InitMicAndAmp();
}
