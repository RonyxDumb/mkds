#include "Main/System/result_archive_path.h"

#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/System/archive_buffer.h"
#include "Main/System/compressed_archive.h"
#include "Main/Net/download_screen_files.h"
#include "Main/Sound/mic_init.h"
#include "Main/Race/race_scene_callbacks.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "expanded_heap_head.h"
#include "Main/System/archive_slots.h"
#include "Main/System/backup_net_camera_work.h"
#include "heap_expanded_allocator.h"
#include "Main/Net/pending_files.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Kart/kart_name_tags.h"
#include "formatted_text_to_buffer.h"
#include "file_archive_access.h"
#include "arena_cache_init.h"
#include "narrow_string_functions.h"
#include "cpu_copy_fill.h"
#include "file_handle_setup.h"
#include "Main/Menu/select_race_rule_state.h"
#include "lz_stream_decompress.h"
#include "uncompress_contexts.h"
#include "00/Menu/wi_fi_vs_setting.h"
#include "Main/Menu/menu_shared_clear.h"
#include "Main/Save/ghost_record_file.h"


#pragma explicit_zero_data on
char gArchiveSlotInfosEmptyPath19[] = "";
char g_SomeEmptyString5[] = "";
char g_SomeEmptyString2[] = "";
char gArchiveSlotInfosEmptyPath20[] = "";
char gArchiveSlotInfosEmptyPath11[] = "";
char gArchiveSlotInfosEmptyPath9[] = "";
char g_SomeEmptyString0[] = "";
char g_SomeEmptyString4[] = "";
char g_SomeEmptyString1[] = "";
char g_SomeEmptyString3[] = "";
#pragma explicit_zero_data off
char g_mount_nt[] = "nt";
char g_mount_gp[] = "gp";
char g_mount_fr[] = "fr";
char g_mount_ge[] = "ge";
char g_mount_vs[] = "vs";
char g_mount_it[] = "it";
char g_mount_us_0[] = "us";
char g_mount_ta[] = "ta";
char g_mount_mg[] = "mg";
char g_mount_es[] = "es";
char g_mount_mr[] = "mr";
char g_mount_us[] = "us";
char g_mount_ja[] = "ja";
char g_mount_CKL[] = "CKL";
char g_mount_CRS[] = "CRS";
char g_mount_EFT[] = "EFT";
char g_mount_KME[] = "KME";
char g_mount_M2L[] = "M2L";
char g_mount_CKS[] = "CKS";
char g_mount_G2L[] = "G2L";
char g_mount_KM2[] = "KM2";
char g_mount_LOC[] = "LOC";
char g_mount_K2D[] = "K2D";
char g_mount_R2L[] = "R2L";
char g_mount_R2D[] = "R2D";
char g_mount_S2D[] = "S2D";
char g_mount_GE2[] = "GE2";
char g_mount_KSB[] = "KSB";
char g_mount_SND[] = "SND";
char g_mount_MAR[] = "MAR";
char g_mount_KM1[] = "KM1";
char g_mount_MA2[] = "MA2";
char g_mount_CST[] = "CST";
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
char g_str_data_Main2D[] = "/data/Main2D";
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
char g_str_data_Main2D_carc[] = "/data/Main2D.carc";
char g_SomeTypeCarcNames[] = "/data/MainRace.carc";
char g_str_data_MainEffect_carc[] = "/data/MainEffect.carc";
char g_str_data_GeneralMenu_carc[] = "/data/GeneralMenu.carc";
const char *g_RaceModeNameTable[6] = {g_mount_gp, g_mount_ta, g_mount_mg,
                                    g_mount_vs, g_mount_mr, g_mount_nt};
char g_data_KartModelMenu_carc[] = "/data/KartModelMenu.carc";
char g_data_CharacterKartSelect_carc[] = "/data/CharacterKartSelect";
char g_data_KartModelMainA_carc[] = "/data/KartModelMainA.carc";
char g_data_KartModelMainB_carc[] = "/data/KartModelMainB.carc";
char g_data_CharacterKartSelect_carc_0[] = "/data/CharacterKartSelect.carc";

const SceneName g_SceneArchiveNameTable[16] = {
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

const CourseNameEntry g_CourseNameTable[55] = {
    {g_SomeEmptyString0, 2},
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
    {g_SomeTypeCarcNames, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_MAIN_RACE, {0, 0, 0}, 0, 0, -1},
    {g_str_data_Main2D_carc, ARCHIVE_SLOT_MAIN_2D_LANGUAGE, ARCHIVE_BUFFER_MAIN_2D, {0, 0, 0}, 1, 0, -1},
    {g_str_data_Main2D, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_MAIN_2D_LANGUAGE, {0, 0, 0}, 1, 0, -1},
    {g_SomeEmptyString1, ARCHIVE_SLOT_COURSE_TEXTURE, ARCHIVE_BUFFER_COURSE, {0, 0, 0}, 0, 0, -1},
    {g_SomeEmptyString5, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 0, 0, -1},
    {g_SomeEmptyString2, ARCHIVE_SLOT_SCENE_LANGUAGE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, -1},
    {g_data_KartModelMainA_carc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_KART_MODEL_MAIN_A, {0, 0, 0}, 1, 1, -1},
    {g_data_KartModelMainB_carc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_KART_MODEL_MAIN_B, {0, 0, 0}, 1, 1, -1},
    {g_str_data_KartModelSub_carc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotInfosEmptyPath9, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, 286720},
    {g_data_KartModelMenu_carc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotInfosEmptyPath11, ARCHIVE_SLOT_SCENE_MODE_LANGUAGE, ARCHIVE_BUFFER_RACE_MODE, {0, 0, 0}, 1, 0, -1},
    {g_SomeEmptyString3, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_RACE_MODE_LANGUAGE, {0, 0, 0}, 1, 0, -1},
    {g_SomeEmptyString4, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_COURSE_TEXTURE, {0, 0, 0}, 1, 1, -1},
    {g_data_CharacterKartSelect_carc_0,
     ARCHIVE_SLOT_CHARACTER_KART_SELECT_LANGUAGE,
     ARCHIVE_BUFFER_NONE,
     {0, 0, 0},
     1,
     0,
     -1},
    {g_data_CharacterKartSelect_carc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, -1},
    {g_str_data_GeneralMenu_carc, ARCHIVE_SLOT_GENERAL_MENU_LANGUAGE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataGeneralMenu, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, -1},
    {g_str_data_MainEffect_carc, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_MAIN_EFFECT, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath19, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath20, ARCHIVE_SLOT_NONE, ARCHIVE_BUFFER_NONE, {0, 0, 0}, 0, 0, -1},
};

char g_str_data_KartModelSub_carc[] = "/data/KartModelSub.carc";
const char *g_LanguageIdentifierTable[7] = {g_mount_ja, g_mount_us, g_mount_fr, g_mount_ge,
                                 g_mount_it, g_mount_es,  g_mount_us_0};
const char *gArchiveNames[20] = {g_mount_MAR, g_mount_MA2, g_mount_M2L, g_mount_CRS, g_mount_SND,
                                 g_mount_K2D, g_mount_KM1, g_mount_KM2, g_mount_KSB, g_mount_LOC,
                                 g_mount_KME, g_mount_R2D, g_mount_R2L, g_mount_CST, g_mount_CKS,
                                 g_mount_CKL, g_mount_GE2, g_mount_G2L, g_mount_EFT, g_mount_S2D};

#pragma thumb on

void FormatResultCarc_from_thumb(char *path) {
    const char *suffix;

    if (g_GlobalB488->mResultArchiveDl == TRUE) {
        suffix = "DL";
    } else {
        suffix = "";
    }
    Util_SNPrintF(path, ARCHIVE_PATH_SIZE, "/data/Scene/%s%s%s", g_SceneArchiveNameTable[SCENE_RESULT].mName, suffix, ".carc");
}

void FormatResultCarcWithLanguage_from_thumb(char *path) {
    const char *suffix;
    u32 languageCode;

    if (g_GlobalB488->mResultArchiveDl == TRUE) {
        suffix = "DL";
    } else {
        suffix = "";
    }
    languageCode = GetLanguageIdentifierString_from_thumb();
    Util_SNPrintF(path, ARCHIVE_PATH_SIZE, "/data/Scene/%s%s_%s%s", g_SceneArchiveNameTable[SCENE_RESULT].mName, suffix, languageCode,
                ".carc");
}

#pragma thumb off

#pragma thumb on

void FormatStaffRollCarcWithLanguage_from_thumb(char *path) {
    u32 languageCode;
    languageCode = GetLanguageIdentifierString_from_thumb();
    Util_SNPrintF(path, ARCHIVE_PATH_SIZE, "/data/Scene/StaffRoll_%s%s", languageCode, ".carc");
}

void FormatSceneArchiveWithRaceMode_from_thumb(char *path, const char *sceneName, int mode) {
    if (*sceneName != 0) {
        Util_SNPrintF(path, ARCHIVE_PATH_SIZE, "/data/Scene/%s_%s%s", sceneName, g_RaceModeNameTable[mode], ".carc");
    }
}

void FormatRaceCarcWithLanguage_from_thumb(char *path, const char *sceneName, int mode) {
    u32 languageCode;
    if (*sceneName != 0) {
        languageCode = GetLanguageIdentifierString_from_thumb();
        Util_SNPrintF(path, ARCHIVE_PATH_SIZE, "/data/Scene/%s_%s_%s%s", sceneName, g_RaceModeNameTable[mode], languageCode,
                    ".carc");
    }
}

void FormatArchiveWithLanguage_from_thumb(const char *prefix, char *path) {
    u32 languageCode;
    languageCode = GetLanguageIdentifierString_from_thumb();
    Util_SNPrintF(path, ARCHIVE_PATH_SIZE, "%s_%s.carc", prefix, languageCode);
}

#pragma thumb off

#pragma thumb on

void Arc_MountArchive_from_thumb(int slotIndex, int sceneNumber) {
    char path[ARCHIVE_PATH_SIZE] = {0};
    u32 *bufferData;
    s32 allocFromHeapEnd;
    s32 uncompressSource;
    s32 archiveBufferSize;
    s32 bufferIndex;

    bufferData = NULL;
    if (g_MountManager->mSlots[slotIndex].mLoaded != 0) {
        return;
    }
    uncompressSource = gArchiveSlotInfos[slotIndex].mUncompressSource;
    allocFromHeapEnd = gArchiveSlotInfos[slotIndex].mAllocFromHeapEnd;
    archiveBufferSize = gArchiveSlotInfos[slotIndex].mArchiveBufferSize;
    bufferIndex = gArchiveSlotInfos[slotIndex].mBufferIndex;
    if (bufferIndex != ARCHIVE_BUFFER_NONE) {
        bufferData = g_MountManager->mBuffers[bufferIndex].mData;
    }
    switch (slotIndex) {
        case ARCHIVE_SLOT_COURSE:
        case ARCHIVE_SLOT_COURSE_TEXTURE:
            FormatCourseCarc_from_thumb(path, g_GlobalCO->mCourseId, slotIndex != ARCHIVE_SLOT_COURSE);
            break;
        case ARCHIVE_SLOT_SCENE:
            switch (sceneNumber) {
                case SCENE_RACE:
                    bufferData = g_MountManager->mBuffers[ARCHIVE_BUFFER_RACE].mData;
                    break;
                case SCENE_MENU_1:
                    bufferData = g_MountManager->mBuffers[ARCHIVE_BUFFER_MENU_DL].mData;
                    break;
                case SCENE_RESULT:
                    bufferData = g_MountManager->mBuffers[ARCHIVE_BUFFER_RESULT_DL].mData;
                    break;
            }
            switch (sceneNumber) {
                case SCENE_RESULT:
                    FormatResultCarc_from_thumb(path);
                    break;
                case SCENE_RACE:
                    if (g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        Util_SNPrintF(path, ARCHIVE_PATH_SIZE, "/data/Scene/StaffRoll.carc");
                    } else {
                        FormatSceneArchive_from_thumb(path, g_SceneArchiveNameTable[sceneNumber].mName);
                    }
                    break;
                default:
                    FormatSceneArchive_from_thumb(path, g_SceneArchiveNameTable[sceneNumber].mName);
                    break;
            }
            archiveBufferSize = g_SceneArchiveNameTable[sceneNumber].mArchiveBufferSize;
            break;
        case ARCHIVE_SLOT_SCENE_LANGUAGE:
            switch (sceneNumber) {
                case SCENE_RACE:
                    bufferData = g_MountManager->mBuffers[ARCHIVE_BUFFER_RACE_LANGUAGE].mData;
                    break;
                case SCENE_MENU_1:
                    bufferData = g_MountManager->mBuffers[ARCHIVE_BUFFER_MENU_DL_LANGUAGE].mData;
                    break;
                case SCENE_RESULT:
                    bufferData = g_MountManager->mBuffers[ARCHIVE_BUFFER_RESULT_DL_LANGUAGE].mData;
                    break;
            }
            switch (sceneNumber) {
                case SCENE_RESULT:
                    FormatResultCarcWithLanguage_from_thumb(path);
                    break;
                case SCENE_RACE:
                    if (g_GlobalCO->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        FormatStaffRollCarcWithLanguage_from_thumb(path);
                    } else {
                        FormatCarcWithLanguage2_from_thumb(path, g_SceneArchiveNameTable[sceneNumber].mName);
                    }
                    break;
                default:
                    FormatCarcWithLanguage2_from_thumb(path, g_SceneArchiveNameTable[sceneNumber].mName);
                    break;
            }
            break;
        case ARCHIVE_SLOT_SCENE_MODE:
            FormatSceneArchiveWithRaceMode_from_thumb(path, g_SceneArchiveNameTable[sceneNumber].mName, g_GlobalCO->mMode);
            break;
        case ARCHIVE_SLOT_SCENE_MODE_LANGUAGE:
            FormatRaceCarcWithLanguage_from_thumb(path, g_SceneArchiveNameTable[sceneNumber].mName, g_GlobalCO->mMode);
            break;
        case ARCHIVE_SLOT_MAIN_2D_LANGUAGE:
        case ARCHIVE_SLOT_CHARACTER_KART_SELECT_LANGUAGE:
        case ARCHIVE_SLOT_GENERAL_MENU_LANGUAGE:
            FormatArchiveWithLanguage_from_thumb(gArchiveSlotInfos[slotIndex].mPath, path);
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
            SomeStrncpy_0(path, gArchiveSlotInfos[(s32) slotIndex].mPath, ARCHIVE_PATH_SIZE);
            break;
    }
    if (path[0] != 0) {
        MountArchiveEntryImpl_from_thumb(slotIndex, path, bufferData, NULL, allocFromHeapEnd, uncompressSource, archiveBufferSize);
    }
    bufferIndex = *(s32 *) ((s32) &gArchiveSlotInfos[0].mNextSlot + slotIndex * 0x18);
    if (bufferIndex != ARCHIVE_SLOT_NONE) {
        Arc_MountArchive_from_thumb(bufferIndex, sceneNumber);
    }
}

void MountArchiveEntryImpl_from_thumb(s32 slotIndex, const char *path, u32 *sourceData, void *data, s32 allocFromHeapEnd,
                     s32 uncompressSource, s32 archiveBufferSize) {
    ArchiveLoadRequest *request;
    s32 bufferIndex;

    request = &g_MountManager->mLoadRequest;
    SomeStrncpy_0((char *) request->mPath, path, ARCHIVE_PATH_SIZE);
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
                    g_MountManager->mBuffers[bufferIndex].mUnk_08_31 = 1;
                }
                DecompressCurrentMountEntry_from_thumb();
            } else {
                request->mData = request->mSourceData;
            }
            MountCurrentMountEntry_from_thumb();
        }
    } else {
        if (slotIndex == ARCHIVE_SLOT_IN_MEMORY) {
            DecompressCurrentMountEntry_from_thumb();
        } else {
            ReadDecompressCurrentMountEntry_from_thumb();
        }
        MountCurrentMountEntry_from_thumb();
    }
}

void ReadDecompressCurrentMountEntry_from_thumb(void) {
    ArchiveLoadRequest *request;
    FSFile file;
    MIUncompContextLZ uncompContext;
    u32 uncompressedSize;
    s32 bytesRead;

    request = &g_MountManager->mLoadRequest;
    Fs_File_Initialize(&file);
    if (Fs_File_Open(&file, request->mPath) == 0) {
        return;
    }
    if (Fs_File_Read(&file, request->mReadBuffer, 4) < 0) {
        return;
    }
    uncompressedSize = *request->mReadBuffer >> 8;
    if (uncompressedSize > 0x200000) {
        return;
    }
    if (request->mAllocFromHeapEnd != 0) {
        request->mData = Mem_AllocateHeapAligned(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), uncompressedSize, -0x20);
    } else {
        request->mData = Mem_AllocateHeapAligned(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), uncompressedSize, HEAP_ALIGN_CACHE_LINE);
    }
    LzDecompressContext_Create(&uncompContext, request->mData, (const MICompressionHeader *) request->mReadBuffer);
    do {
        bytesRead = Fs_File_Read(&file, request->mReadBuffer, 0x400);
        if (bytesRead <= 0) {
            return;
        }
    } while (LzDecompressContext_DoCycle(&uncompContext, (const u8 *) request->mReadBuffer, bytesRead) != 0);
    DC_SomeClean(request->mData, uncompressedSize);
    Mem_GetExpHeapTotalFreeSize(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
}

void DecompressCurrentMountEntry_from_thumb(void) {
    ArchiveLoadRequest *request;
    u32 uncompressedSize;

    request = &g_MountManager->mLoadRequest;
    uncompressedSize = *request->mSourceData >> 8;
    if (request->mAllocFromHeapEnd != 0) {
        request->mData = Mem_AllocateHeapAligned(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), uncompressedSize, -0x20);
    } else {
        request->mData = Mem_AllocateHeapAligned(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), uncompressedSize, HEAP_ALIGN_CACHE_LINE);
    }
    DecompressLzss(request->mSourceData, request->mData);
    DC_SomeClean(request->mData, uncompressedSize);
    Mem_GetExpHeapTotalFreeSize(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
}

void MountCurrentMountEntry_from_thumb(void) {
    ArchiveLoadRequest *request;
    ArchiveSlot *slot;

    request = &g_MountManager->mLoadRequest;
    slot = &g_MountManager->mSlots[request->mSlotIndex];
    if (request->mData != NULL) {
        if (MountMountEntryFrom(&slot->mArchive, (const u8 *) gArchiveNames[request->mSlotIndex], request->mData) !=
            0) {
            slot->mLoaded = 1;
            slot->mData = request->mData;
        }
    }
}

void Arc_DisposeArchive_from_thumb(int slotIndex) {
    BOOL shouldFree;
    s32 bufferIndex;

    shouldFree = TRUE;
    if (g_MountManager->mSlots[slotIndex].mLoaded != 0 && slotIndex != ARCHIVE_SLOT_IN_MEMORY) {
        Fs_Archive_Dispose(&g_MountManager->mSlots[slotIndex].mArchive.mFsArchive);
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            bufferIndex = gArchiveSlotInfos[slotIndex].mBufferIndex;
            if (bufferIndex != ARCHIVE_BUFFER_NONE && g_MountManager->mBuffers[bufferIndex].mUncompress != 0) {
                shouldFree = FALSE;
            } else {
                g_MountManager->mBuffers[bufferIndex].mUnk_08_31 = 1;
            }
        }
        if (shouldFree != FALSE) {
            Mem_FreeHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), g_MountManager->mSlots[slotIndex].mData);
        }
        g_MountManager->mSlots[slotIndex].mLoaded = 0;
        g_MountManager->mSlots[slotIndex].mData = 0;
        Mem_GetExpHeapTotalFreeSize(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()));
    }
}

void MountArchivesForScene_from_thumb(s32 sceneNumber) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT && sceneNumber == SCENE_WL_MENU && g_GlobalB488->mWLMenuKind == 0) {
    } else {
        Arc_MountArchive_from_thumb(ARCHIVE_SLOT_MAIN_2D, sceneNumber);
    }
    switch (sceneNumber) {
        case SCENE_MENU_1:
        case SCENE_WIFI_MENU:
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_SCENE, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_CHARACTER_KART_SELECT, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            break;
        case SCENE_RESULT:
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_MAIN_RACE, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_SCENE, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_MAIN_EFFECT, sceneNumber);
            break;
        case SCENE_RACE:
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_MAIN_EFFECT, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_KART_MODEL_MAIN_A, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_KART_MODEL_SUB, sceneNumber);
            break;
        case SCENE_EMBLEM:
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_MAIN_RACE, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_SCENE, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            break;
        case SCENE_TEST:
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_SCENE, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_CHARACTER_KART_SELECT, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            break;
        case SCENE_TITLE:
        case SCENE_OPTION:
        case SCENE_RECORD:
        case SCENE_LOGO:
        case SCENE_NICKNAME:
        case SCENE_GHOST:
        case SCENE_KEYBOARD:
        case SCENE_ENDING:
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_SCENE, sceneNumber);
            Arc_MountArchive_from_thumb(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            break;
        case SCENE_MENU_4:
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                Arc_MountArchive_from_thumb(ARCHIVE_SLOT_SCENE, sceneNumber);
                Arc_MountArchive_from_thumb(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            }
            break;
        case SCENE_WL_MENU:
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                Arc_MountArchive_from_thumb(ARCHIVE_SLOT_SCENE, sceneNumber);
                Arc_MountArchive_from_thumb(ARCHIVE_SLOT_GENERAL_MENU, sceneNumber);
            }
            break;
    }
}

void Arc_DisposeAllArchives_from_thumb(void) {
    s32 slotIndex;

    for (slotIndex = 0; slotIndex < ARCHIVE_SLOT_COUNT; slotIndex++) {
        Arc_DisposeArchive_from_thumb(slotIndex);
    }
}

#pragma thumb off

#pragma thumb on
void SetActiveExecutionContextHeapGroupId_from_thumb(u32 groupId) {
    Mem_SetExpHeapGroupId(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), groupId);
}
#pragma thumb off

#pragma thumb on

void *FormatGetPathMountBuffer_from_thumb(const char *archiveName, const char *path) {
    char fullPath[ARCHIVE_PATH_SIZE];

    if (path[0] == '/') {
        Util_SNPrintF(fullPath, ARCHIVE_PATH_SIZE, "%s:%s", archiveName, path);
    } else {
        Util_SNPrintF(fullPath, ARCHIVE_PATH_SIZE, "%s:/%s", archiveName, path);
    }
    return GetFileBuffer((const u8 *) fullPath);
}

#pragma thumb off

#pragma thumb on

void *FindFileBuffer_MAR_EFT_from_thumb(const char *path) {
    void *file;
    file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_MAIN_RACE], path);
    if (file == NULL) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_MAIN_EFFECT], path);
    }
    return file;
}

#pragma thumb off

#pragma thumb on

// Searches the archives that are loaded, in a fixed order, and returns the first match.
void *FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(const char *path) {
    void *file;

    file = NULL;
    if (g_MountManager->mSlots[ARCHIVE_SLOT_GENERAL_MENU_LANGUAGE].mLoaded != 0) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_GENERAL_MENU_LANGUAGE], path);
    }
    if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_GENERAL_MENU].mLoaded != 0) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_GENERAL_MENU], path);
    }
    if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_CHARACTER_KART_SELECT_LANGUAGE].mLoaded != 0) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_CHARACTER_KART_SELECT_LANGUAGE], path);
    }
    if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_CHARACTER_KART_SELECT].mLoaded != 0) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_CHARACTER_KART_SELECT], path);
    }
    if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_IN_MEMORY].mLoaded != 0) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_IN_MEMORY], path);
    }
    if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_MAIN_2D_LANGUAGE].mLoaded != 0) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_MAIN_2D_LANGUAGE], path);
    }
    if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_MAIN_2D].mLoaded != 0) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_MAIN_2D], path);
    }
    return file;
}

void *FindFileBuffer_K2D_LOC_R2D_R2L_from_thumb(const char *path) {
    void *file;

    file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_SCENE], path);
    if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_SCENE_LANGUAGE].mLoaded != 0) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_SCENE_LANGUAGE], path);
    }
    if (GetCurrentSceneId() == SCENE_RACE) {
        if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_SCENE_MODE].mLoaded != 0) {
            file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_SCENE_MODE], path);
        }
        if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_SCENE_MODE_LANGUAGE].mLoaded != 0) {
            file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_SCENE_MODE_LANGUAGE], path);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void *FindFileBuffer_CRS_CST_from_thumb(const char *path) {
    void *file;
    file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_COURSE], path);
    if (file == NULL) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_COURSE_TEXTURE], path);
    }
    return file;
}

void *FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(const char *path) {
    int currentSceneNumber;
    currentSceneNumber = GetCurrentSceneId();
    if (currentSceneNumber == SCENE_EMBLEM) {
        return FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(path);
    }
    return AllocateFindFileBuffer_KME_KM1_KM2_KSB_from_thumb(path);
}

void *FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(const char *path) {
    int currentSceneNumber;
    void *file;
    file = NULL;
    currentSceneNumber = GetCurrentSceneId();
    if (((currentSceneNumber == SCENE_MENU_1) || (currentSceneNumber == SCENE_EMBLEM)) ||
        (currentSceneNumber == SCENE_WIFI_MENU)) {
        file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MENU], path);
    } else {
        if (g_MountManager->mSlots[ARCHIVE_SLOT_KART_MODEL_MAIN_A].mLoaded != 0) {
            file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MAIN_A], path);
        }
        if ((file == NULL) && (g_MountManager->mSlots[ARCHIVE_SLOT_KART_MODEL_MAIN_B].mLoaded != 0)) {
            file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MAIN_B], path);
        }
        if ((file == NULL) && (g_MountManager->mSlots[ARCHIVE_SLOT_KART_MODEL_SUB].mLoaded != 0)) {
            file = FormatGetPathMountBuffer_from_thumb(gArchiveNames[ARCHIVE_SLOT_KART_MODEL_SUB], path);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void *AllocateFindFileBuffer_KME_KM1_KM2_KSB_from_thumb(const char *path) {
    void *file;
    s32 currentSceneNumber;
    char fullPath[ARCHIVE_PATH_SIZE];
    const char *archiveName;

    file = NULL;
    currentSceneNumber = GetCurrentSceneId();
    if (currentSceneNumber == SCENE_MENU_1 || currentSceneNumber == SCENE_EMBLEM ||
        currentSceneNumber == SCENE_WIFI_MENU) {
        archiveName = gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MENU];
        if (path[0] == '/') {
            Util_SNPrintF(fullPath, ARCHIVE_PATH_SIZE, "%s:%s", archiveName, path);
        } else {
            Util_SNPrintF(fullPath, ARCHIVE_PATH_SIZE, "%s:/%s", archiveName, path);
        }
        file = AllocateReadFileBuffer_from_thumb(fullPath, 8);
    } else {
        if (g_MountManager->mSlots[ARCHIVE_SLOT_KART_MODEL_MAIN_A].mLoaded != 0) {
            archiveName = gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MAIN_A];
            if (path[0] == '/') {
                Util_SNPrintF(fullPath, ARCHIVE_PATH_SIZE, "%s:%s", archiveName, path);
            } else {
                Util_SNPrintF(fullPath, ARCHIVE_PATH_SIZE, "%s:/%s", archiveName, path);
            }
            file = AllocateReadFileBuffer_from_thumb(fullPath, 8);
        }
        if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_KART_MODEL_MAIN_B].mLoaded != 0) {
            archiveName = gArchiveNames[ARCHIVE_SLOT_KART_MODEL_MAIN_B];
            if (path[0] == '/') {
                Util_SNPrintF(fullPath, ARCHIVE_PATH_SIZE, "%s:%s", archiveName, path);
            } else {
                Util_SNPrintF(fullPath, ARCHIVE_PATH_SIZE, "%s:/%s", archiveName, path);
            }
            file = AllocateReadFileBuffer_from_thumb(fullPath, 8);
        }
        if (file == NULL && g_MountManager->mSlots[ARCHIVE_SLOT_KART_MODEL_SUB].mLoaded != 0) {
            archiveName = gArchiveNames[ARCHIVE_SLOT_KART_MODEL_SUB];
            if (path[0] == '/') {
                Util_SNPrintF(fullPath, ARCHIVE_PATH_SIZE, "%s:%s", archiveName, path);
            } else {
                Util_SNPrintF(fullPath, ARCHIVE_PATH_SIZE, "%s:/%s", archiveName, path);
            }
            file = AllocateReadFileBuffer_from_thumb(fullPath, 8);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void Dispose_KM1_Mount_KM2_from_thumb(void) {
    Arc_DisposeArchive_from_thumb(ARCHIVE_SLOT_KART_MODEL_MAIN_A);
    SetActiveExecutionContextHeapGroupId_from_thumb((u16) HEAP_GROUP_DEFAULT);
    Arc_MountArchive_from_thumb(ARCHIVE_SLOT_KART_MODEL_MAIN_B, SCENE_RACE);
    SetActiveExecutionContextHeapGroupId_from_thumb((u16) HEAP_GROUP_SCENE);
}

void Dispose_KM2_KSB_Mount_CRS_from_thumb(void) {
    int currentSceneNumber;
    Arc_DisposeArchive_from_thumb(ARCHIVE_SLOT_KART_MODEL_MAIN_B);
    Arc_DisposeArchive_from_thumb(ARCHIVE_SLOT_KART_MODEL_SUB);
    SetActiveExecutionContextHeapGroupId_from_thumb((u16) HEAP_GROUP_DEFAULT);
    currentSceneNumber = GetCurrentSceneId();
    if (currentSceneNumber == SCENE_RACE) {
        Arc_MountArchive_from_thumb(ARCHIVE_SLOT_COURSE, SCENE_RACE);
    }
    SetActiveExecutionContextHeapGroupId_from_thumb((u16) HEAP_GROUP_SCENE);
}

void Dispose_CST_Mount_K2D_R2D_MAR_from_thumb(void) {
    int currentSceneNumber;
    Arc_DisposeArchive_from_thumb(ARCHIVE_SLOT_COURSE_TEXTURE);
    SetActiveExecutionContextHeapGroupId_from_thumb((u16) HEAP_GROUP_DEFAULT);
    currentSceneNumber = GetCurrentSceneId();
    if (currentSceneNumber == SCENE_RACE) {
        Arc_MountArchive_from_thumb(ARCHIVE_SLOT_SCENE, SCENE_RACE);
        Arc_MountArchive_from_thumb(ARCHIVE_SLOT_SCENE_MODE, SCENE_RACE);
        Arc_MountArchive_from_thumb(ARCHIVE_SLOT_MAIN_RACE, SCENE_RACE);
    }
    SetActiveExecutionContextHeapGroupId_from_thumb((u16) HEAP_GROUP_SCENE);
}

void ReleaseKartModelLoadSlotsForScene(void) {
    u32 currentSceneNumber;
    currentSceneNumber = GetCurrentSceneId();
    Arc_DisposeArchive_from_thumb(ARCHIVE_SLOT_KART_MODEL_MENU);
    SetActiveExecutionContextHeapGroupId_from_thumb((u16) HEAP_GROUP_DEFAULT);
    Arc_MountArchive_from_thumb(ARCHIVE_SLOT_MAIN_2D, currentSceneNumber);
    Arc_MountArchive_from_thumb(ARCHIVE_SLOT_SCENE, currentSceneNumber);
    Arc_MountArchive_from_thumb(ARCHIVE_SLOT_CHARACTER_KART_SELECT, currentSceneNumber);
    Arc_MountArchive_from_thumb(ARCHIVE_SLOT_GENERAL_MENU, currentSceneNumber);
    SetActiveExecutionContextHeapGroupId_from_thumb((u16) HEAP_GROUP_SCENE);
}

#pragma thumb off

#pragma thumb on

void SetMountData_from_thumb(NNSiFndHeapHead *heap, s32 bufferIndex, s32 sizeInKb, u32 uncompress, u32 flag) {
    ArchiveBuffer *buffer = &g_MountManager->mBuffers[bufferIndex];
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
void SpecialDwcSetMountDatas_from_thumb(NNSiFndHeapHead *firstHeap, NNSiFndHeapHead *courseBufferHeap, NNSiFndHeapHead *lastHeap) {
    SetMountData_from_thumb(lastHeap, ARCHIVE_BUFFER_RACE, 0x3c, 0, 1);
    SetMountData_from_thumb(lastHeap, ARCHIVE_BUFFER_RACE_LANGUAGE, 0x32, 0, 1);
    SetMountData_from_thumb(lastHeap, ARCHIVE_BUFFER_RACE_MODE, 5, 0, 1);
    SetMountData_from_thumb(lastHeap, ARCHIVE_BUFFER_RACE_MODE_LANGUAGE, 5, 0, 1);
    SetMountData_from_thumb(lastHeap, ARCHIVE_BUFFER_MENU_DL, 0x14, 0, 1);
    SetMountData_from_thumb(lastHeap, ARCHIVE_BUFFER_MENU_DL_LANGUAGE, 0x14, 0, 1);
    SetMountData_from_thumb(lastHeap, ARCHIVE_BUFFER_RESULT_DL, 0x46, 0, 1);
    SetMountData_from_thumb(lastHeap, ARCHIVE_BUFFER_RESULT_DL_LANGUAGE, 0x46, 0, 1);
    SetMountData_from_thumb(courseBufferHeap, ARCHIVE_BUFFER_COURSE, 200, 1, 1);
    SetMountData_from_thumb(courseBufferHeap, ARCHIVE_BUFFER_COURSE_TEXTURE, 200, 0, 1);
    SetMountData_from_thumb(firstHeap, ARCHIVE_BUFFER_MAIN_RACE, 0x46, 1, 0);
    SetMountData_from_thumb(firstHeap, ARCHIVE_BUFFER_MAIN_EFFECT, 0x1e, 0, 0);
    g_MountManager->mFirstHeap = firstHeap;
    g_MountManager->mCourseBufferHeap = courseBufferHeap;
    g_MountManager->mLastHeap = lastHeap;
}

void InitArchiveBuffersOnOverlayHeap(void) {
    SetMountData_from_thumb(g_OverlayManager->mFrmHeap, ARCHIVE_BUFFER_KART_MODEL_MAIN_A, 0xaa, 0, 0);
    SetMountData_from_thumb(g_OverlayManager->mFrmHeap, ARCHIVE_BUFFER_KART_MODEL_MAIN_B, 0x6e, 0, 0);
    SetMountData_from_thumb(g_OverlayManager->mFrmHeap, ARCHIVE_BUFFER_MAIN_2D, 0x1e, 0, 0);
    SetMountData_from_thumb(g_OverlayManager->mFrmHeap, ARCHIVE_BUFFER_MAIN_2D_LANGUAGE, 0x1e, 0, 0);
}

#pragma thumb off

#pragma thumb on

void RequestArchiveLoad(const void *path, s32 bufferIndex) {
    ArchiveBuffer *buffer = &g_MountManager->mBuffers[bufferIndex];
    AddPendingFile(path, buffer->mHeap, &buffer->mData, buffer->mByteSize, buffer->mUncompress);
    buffer->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

void RequestArchiveLoadWithLanguage(const void *prefix, u32 bufferIndex) {
    u32 languageCode;
    char path[ARCHIVE_PATH_SIZE];
    languageCode = GetSomeLanguage_from_thumb();
    Util_SNPrintF(path, ARCHIVE_PATH_SIZE, "%s%s.carc", prefix, languageCode);
    RequestArchiveLoad(path, bufferIndex);
}

void RequestMainAndMenuDLArchives(void) {
    ResetPendingFiles();
    Mem_ResetFrameHeap(g_MountManager->mLastHeap, 3);
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
    Mem_ResetFrameHeap(g_MountManager->mLastHeap, 3);
    RequestArchiveLoad("/data/Scene/MenuDL.carc", ARCHIVE_BUFFER_MENU_DL);
    RequestArchiveLoadWithLanguage("/data/Scene/MenuDL_", ARCHIVE_BUFFER_MENU_DL_LANGUAGE);
}

#pragma thumb off

#pragma thumb on

void RequestRaceArchives(void *courseId, void *kind) {
    char path[ARCHIVE_PATH_SIZE];
    ResetPendingFiles();
    Mem_ResetFrameHeap(g_MountManager->mLastHeap, 3);
    RequestArchiveLoad("/data/Scene/Race.carc", ARCHIVE_BUFFER_RACE);
    RequestArchiveLoadWithLanguage("/data/Scene/Race_", ARCHIVE_BUFFER_RACE_LANGUAGE);
    if (kind == (void *) MODE_VS) {
        RequestArchiveLoad("/data/Scene/Race_vs.carc", ARCHIVE_BUFFER_RACE_MODE);
        RequestArchiveLoadWithLanguage("/data/Scene/Race_vs_", ARCHIVE_BUFFER_RACE_MODE_LANGUAGE);
    } else {
        RequestArchiveLoad("/data/Scene/Race_mg.carc", ARCHIVE_BUFFER_RACE_MODE);
        RequestArchiveLoadWithLanguage("/data/Scene/Race_mg_", ARCHIVE_BUFFER_RACE_MODE_LANGUAGE);
    }
    g_MountManager->mRaceKind = kind;
    Mem_ResetFrameHeap(g_MountManager->mCourseBufferHeap, 3);
    FormatCourseCarc_from_thumb(path, (s32) courseId, 0);
    RequestArchiveLoad(path, ARCHIVE_BUFFER_COURSE);
    FormatCourseCarc_from_thumb(path, (s32) courseId, 1);
    RequestArchiveLoad(path, ARCHIVE_BUFFER_COURSE_TEXTURE);
    g_MountManager->mCourseId = courseId;
}

#pragma thumb off

#pragma thumb on

void RequestResultDLArchives(void) {
    ResetPendingFiles();
    Mem_ResetFrameHeap(g_MountManager->mLastHeap, 3);
    RequestArchiveLoad("/data/Scene/ResultDL.carc", ARCHIVE_BUFFER_RESULT_DL);
    RequestArchiveLoadWithLanguage("/data/Scene/ResultDL_", ARCHIVE_BUFFER_RESULT_DL_LANGUAGE);
}

#pragma thumb off

#pragma thumb on

void SomeMaskMountDataFlags_from_thumb(void) {
    s32 bufferIndex;

    for (bufferIndex = 0; bufferIndex < ARCHIVE_BUFFER_COUNT; bufferIndex++) {
        g_MountManager->mBuffers[bufferIndex].mUnk_08_31 = 0;
    }
}

s32 GetMountData7FlagBit31_from_thumb(void) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return g_MountManager->mBuffers[ARCHIVE_BUFFER_COURSE_TEXTURE].mUnk_08 >> 31;
    }
    return 1;
}

// Resizes the block that holds the MainEffect archive so it ends where the caller says.
void ResizeActiveExecutionContextHeapHandle_from_thumb(u8 *regionStart, u32 regionSize) {
    u8 *block;

    block = g_MountManager->mSlots[ARCHIVE_SLOT_MAIN_EFFECT].mData;
    Mem_ResizeExpHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), block, regionSize + (regionStart - block));
}

void LoadEmbeddedStatic2DArchive_from_thumb(void *heap) {
    u32 uncompressedSize;
    void *data;

    uncompressedSize = *GetEmbeddedStatic2DCarcArchiveData() >> 8;
    g_MountManager->mSlots[ARCHIVE_SLOT_IN_MEMORY].mLoaded = 0;
    data = Mem_AllocateHeapAligned(heap, uncompressedSize, HEAP_ALIGN_CACHE_LINE);
    DecompressLzssAndDCClean_from_thumb(GetEmbeddedStatic2DCarcArchiveData(), data, uncompressedSize);
    MountMountEntryFrom(&g_MountManager->mSlots[ARCHIVE_SLOT_IN_MEMORY].mArchive,
                          (const u8 *) gArchiveNames[ARCHIVE_SLOT_IN_MEMORY], data);
    g_MountManager->mSlots[ARCHIVE_SLOT_IN_MEMORY].mData = data;
    g_MountManager->mSlots[ARCHIVE_SLOT_IN_MEMORY].mLoaded = 1;
    LoadStatic2DContents(heap);
}

#pragma thumb off

void Input_MaybeInitializeTouch(void) {
    TPCalibrateParam calibrateParam;

    Os_InitializeTouchPanelFifo();
    if (ComputeSomeScreenCalibrationStuff(&calibrateParam) == 0) {
        return;
    }
    UseSomeCalibrationStuff(&calibrateParam);
}

void CreateGlobal59C4(void *heap) {
    g_Global59C4 = Mem_AllocateHeap(heap, sizeof(TouchMicInput));
    g_Global59C4->mTouchAutoSampling = 0;
    g_Global59C4->mMicAutoSampling = 0;
    g_Global59C4->mMicPreSleepDone = 0;
    g_Global59C4->mMicOverThreshold = 0;
    g_Global59C4->mMicBuffer = NULL;
    InitializeBalloonHardware();
}
