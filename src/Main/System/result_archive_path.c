#include "Main/System/result_archive_path.h"

#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/System/archive_buffer.h"
#include "Main/System/compressed_archive.h"
#include "Main/Net/search_icon_mb_child_and.h"
#include "Main/Sound/mic_init.h"
#include "Main/Race/data_02164000.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "code_020176c0.h"
#include "Main/System/archive_slots.h"
#include "Main/MapObjects/data_0217a000.h"
#include "expheap.h"
#include "Main/Net/pending_files.h"
#include "Main/Scene/run_scenes.h"
#include "Main/MapObjects/data_02165000.h"
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
const char *gModeArchiveNames[6] = {gModeArchiveNameGp, gModeArchiveNameTa, gModeArchiveNameMg, gModeArchiveNameVs, gModeArchiveNameMr, gModeArchiveNameNt};
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
    {gArchiveSlotPathDataMainRaceCarc, -1, 8, {0, 0, 0}, 0, 0, -1},
    {gArchiveSlotPathDataMain2DCarc, 2, 9, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataMain2D, -1, 10, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath3, 13, 6, {0, 0, 0}, 0, 0, -1},
    {gArchiveSlotInfosEmptyPath4, -1, -1, {0, 0, 0}, 0, 0, -1},
    {gArchiveSlotInfosEmptyPath5, 9, -1, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataKartModelMainACarc, -1, 11, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotPathDataKartModelMainBCarc, -1, 12, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotPathDataKartModelSubCarc, -1, -1, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotInfosEmptyPath9, -1, -1, {0, 0, 0}, 1, 0, 286720},
    {gArchiveSlotPathDataKartModelMenuCarc, -1, -1, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotInfosEmptyPath11, 12, 4, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath12, -1, 5, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath13, -1, 7, {0, 0, 0}, 1, 1, -1},
    {gArchiveSlotPathDataCharacterKartSelectCarc, 15, -1, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataCharacterKartSelect, -1, -1, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataGeneralMenuCarc, 17, -1, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataGeneralMenu, -1, -1, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotPathDataMainEffectCarc, -1, 13, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath19, -1, -1, {0, 0, 0}, 1, 0, -1},
    {gArchiveSlotInfosEmptyPath20, -1, -1, {0, 0, 0}, 0, 0, -1},
};

char gArchiveSlotPathDataKartModelSubCarc[] = "/data/KartModelSub.carc";
const char *gLanguageCodes[7] = {gLanguageCodeJa, gLanguageCodeUs1, gLanguageCodeFr, gLanguageCodeGe, gLanguageCodeIt, gLanguageCodeEs, gLanguageCodeUs6};
const char *gArchiveNames[20] = {gArchiveNameMAR, gArchiveNameMA2, gArchiveNameM2L, gArchiveNameCRS, gArchiveNameSND, gArchiveNameK2D, gArchiveNameKM1, gArchiveNameKM2, gArchiveNameKSB, gArchiveNameLOC, gArchiveNameKME, gArchiveNameR2D, gArchiveNameR2L, gArchiveNameCST, gArchiveNameCKS, gArchiveNameCKL, gArchiveNameGE2, gArchiveNameG2L, gArchiveNameEFT, gArchiveNameS2D};

#pragma thumb on

void BuildResultArchivePath(char *path) {
    const char *suffix;

    if (gMenuShared->mResultArchiveDl == 1) {
        suffix = "DL";
    } else {
        suffix = "";
    }
    OS_SNPrintf(path, 0x80, "/data/Scene/%s%s%s", gSceneNames[10].mName, suffix, ".carc");
}

void BuildResultArchivePathWithLanguage(char *path) {
    const char *suffix;
    u32 languageCode;

    if (gMenuShared->mResultArchiveDl == 1) {
        suffix = "DL";
    } else {
        suffix = "";
    }
    languageCode = GetLanguageCode();
    OS_SNPrintf(path, 0x80, "/data/Scene/%s%s_%s%s", gSceneNames[10].mName, suffix, languageCode,
                ".carc");
}

#pragma thumb off

#pragma thumb on

void BuildStaffRollArchivePath(char *path) {
    u32 languageCode;
    languageCode = GetLanguageCode();
    OS_SNPrintf(path, 0x80, "/data/Scene/StaffRoll_%s%s", languageCode, ".carc");
}

void BuildSceneModeArchivePath(char *path, const char *sceneName, int mode) {
    if (*sceneName != 0) {
        OS_SNPrintf(path, 0x80, "/data/Scene/%s_%s%s", sceneName, gModeArchiveNames[mode], ".carc");
    }
}

void BuildSceneModeLanguageArchivePath(char *path, const char *sceneName, int mode) {
    u32 languageCode;
    if (*sceneName != 0) {
        languageCode = GetLanguageCode();
        OS_SNPrintf(path, 0x80, "/data/Scene/%s_%s_%s%s", sceneName, gModeArchiveNames[mode], languageCode,
                    ".carc");
    }
}

void BuildArchivePathWithLanguage(const char *prefix, char *path) {
    u32 languageCode;
    languageCode = GetLanguageCode();
    OS_SNPrintf(path, 0x80, "%s_%s.carc", prefix, languageCode);
}

#pragma thumb off

#pragma thumb on

void LoadArchiveSlotForScene(int slotIndex, int sceneNumber) {
    char path[0x80] = {0};
    u32 *bufferData;
    s32 infoValueA;
    s32 uncompressSource;
    s32 infoValueB;
    s32 bufferIndex;

    bufferData = NULL;
    if (gArchiveSlots->mSlots[slotIndex].mLoaded != 0) {
        return;
    }
    uncompressSource = gArchiveSlotInfos[slotIndex].mUncompressSource;
    infoValueA = gArchiveSlotInfos[slotIndex].mUnk_10;
    infoValueB = gArchiveSlotInfos[slotIndex].mUnk_14;
    bufferIndex = gArchiveSlotInfos[slotIndex].mBufferIndex;
    if (bufferIndex != -1) {
        bufferData = gArchiveSlots->mBuffers[bufferIndex].mData;
    }
    switch (slotIndex) {
        case 3:
        case 13:
            BuildCourseArchivePath(path, gRaceSetup->mCourseId, slotIndex != 3);
            break;
        case 5:
            switch (sceneNumber) {
                case 2:
                    bufferData = gArchiveSlots->mBuffers[2].mData;
                    break;
                case 1:
                    bufferData = gArchiveSlots->mBuffers[0].mData;
                    break;
                case 10:
                    bufferData = gArchiveSlots->mBuffers[14].mData;
                    break;
            }
            switch (sceneNumber) {
                case 10:
                    BuildResultArchivePath(path);
                    break;
                case 2:
                    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        OS_SNPrintf(path, 0x80, "/data/Scene/StaffRoll.carc");
                    } else {
                        BuildSceneArchivePath(path, gSceneNames[sceneNumber].mName);
                    }
                    break;
                default:
                    BuildSceneArchivePath(path, gSceneNames[sceneNumber].mName);
                    break;
            }
            infoValueB = gSceneNames[sceneNumber].mUnk_04;
            break;
        case 9:
            switch (sceneNumber) {
                case 2:
                    bufferData = gArchiveSlots->mBuffers[3].mData;
                    break;
                case 1:
                    bufferData = gArchiveSlots->mBuffers[1].mData;
                    break;
                case 10:
                    bufferData = gArchiveSlots->mBuffers[15].mData;
                    break;
            }
            switch (sceneNumber) {
                case 10:
                    BuildResultArchivePathWithLanguage(path);
                    break;
                case 2:
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
        case 11:
            BuildSceneModeArchivePath(path, gSceneNames[sceneNumber].mName, gRaceSetup->mMode);
            break;
        case 12:
            BuildSceneModeLanguageArchivePath(path, gSceneNames[sceneNumber].mName, gRaceSetup->mMode);
            break;
        case 2:
        case 15:
        case 17:
            BuildArchivePathWithLanguage(gArchiveSlotInfos[slotIndex].mPath, path);
            break;
        case 0:
        case 1:
        case 6:
        case 7:
        case 8:
        case 10:
        case 14:
        case 16:
        case 18:
            strncpy(path, gArchiveSlotInfos[(s32) slotIndex].mPath, 0x80);
            break;
    }
    if (path[0] != 0) {
        LoadArchiveSlot(slotIndex, path, bufferData, NULL, infoValueA, uncompressSource, infoValueB);
    }
    bufferIndex = *(s32 *) ((s32) &gArchiveSlotInfos[0].mNextSlot + slotIndex * 0x18);
    if (bufferIndex != -1) {
        LoadArchiveSlotForScene(bufferIndex, sceneNumber);
    }
}

void LoadArchiveSlot(s32 slotIndex, const char *path, u32 *sourceData, void *data, s32 requestValueA,
                     s32 uncompressSource, s32 requestValueB) {
    ArchiveLoadRequest *request;
    s32 bufferIndex;

    request = &gArchiveSlots->mLoadRequest;
    strncpy((char *) request->mPath, path, 0x80);
    request->mSlotIndex = slotIndex;
    request->mSourceData = sourceData;
    request->mData = data;
    request->mAllocFromHeapEnd = requestValueA;
    request->mUncompressSource = uncompressSource;
    request->mUnk_9c = requestValueB;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        if (request->mSourceData != NULL) {
            if (request->mUncompressSource != 0) {
                bufferIndex = gArchiveSlotInfos[slotIndex].mBufferIndex;
                if (bufferIndex != -1) {
                    gArchiveSlots->mBuffers[bufferIndex].mUnk_08_31 = 1;
                }
                UncompressArchiveMemory();
            } else {
                request->mData = request->mSourceData;
            }
            LoadArchiveSlotData();
        }
    } else {
        if (slotIndex == 0x13) {
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
        request->mData = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), uncompressedSize, 0x20);
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
        request->mData = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), uncompressedSize, 0x20);
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
    if (gArchiveSlots->mSlots[slotIndex].mLoaded != 0 && slotIndex != 0x13) {
        ArchiveUnload(&gArchiveSlots->mSlots[slotIndex].mArchive.mFsArchive);
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            bufferIndex = gArchiveSlotInfos[slotIndex].mBufferIndex;
            if (bufferIndex != -1 && gArchiveSlots->mBuffers[bufferIndex].mUncompress != 0) {
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
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT && sceneNumber == 6 && gMenuShared->mWLMenuKind == 0) {
    } else {
        LoadArchiveSlotForScene(1, sceneNumber);
    }
    switch (sceneNumber) {
        case 1:
        case 12:
            LoadArchiveSlotForScene(5, sceneNumber);
            LoadArchiveSlotForScene(14, sceneNumber);
            LoadArchiveSlotForScene(16, sceneNumber);
            break;
        case 10:
            LoadArchiveSlotForScene(0, sceneNumber);
            LoadArchiveSlotForScene(5, sceneNumber);
            LoadArchiveSlotForScene(16, sceneNumber);
            LoadArchiveSlotForScene(18, sceneNumber);
            break;
        case 2:
            LoadArchiveSlotForScene(18, sceneNumber);
            LoadArchiveSlotForScene(6, sceneNumber);
            LoadArchiveSlotForScene(8, sceneNumber);
            break;
        case 3:
            LoadArchiveSlotForScene(0, sceneNumber);
            LoadArchiveSlotForScene(5, sceneNumber);
            LoadArchiveSlotForScene(16, sceneNumber);
            break;
        case 5:
            LoadArchiveSlotForScene(5, sceneNumber);
            LoadArchiveSlotForScene(14, sceneNumber);
            LoadArchiveSlotForScene(16, sceneNumber);
            break;
        case 0:
        case 7:
        case 8:
        case 9:
        case 11:
        case 13:
        case 14:
        case 15:
            LoadArchiveSlotForScene(5, sceneNumber);
            LoadArchiveSlotForScene(16, sceneNumber);
            break;
        case 4:
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                LoadArchiveSlotForScene(5, sceneNumber);
                LoadArchiveSlotForScene(16, sceneNumber);
            }
            break;
        case 6:
            if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
                LoadArchiveSlotForScene(5, sceneNumber);
                LoadArchiveSlotForScene(16, sceneNumber);
            }
            break;
    }
}

void ReleaseArchiveSlots(void) {
    s32 slotIndex;

    for (slotIndex = 0; slotIndex < 20; slotIndex++) {
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
    char fullPath[0x80];

    if (path[0] == '/') {
        OS_SNPrintf(fullPath, 0x80, "%s:%s", archiveName, path);
    } else {
        OS_SNPrintf(fullPath, 0x80, "%s:/%s", archiveName, path);
    }
    return ArchiveFileGetAddress((const u8 *) fullPath);
}

#pragma thumb off

#pragma thumb on

void *FindMainRaceOrMainEffectFile(const char *path) {
    void *file;
    file = FindArchiveFile(gArchiveNames[0], path);
    if (file == NULL) {
        file = FindArchiveFile(gArchiveNames[18], path);
    }
    return file;
}

#pragma thumb off

#pragma thumb on

// Searches the archives that are loaded, in a fixed order, and returns the first match.
void *FindFileInLoadedArchives(const char *path) {
    void *file;

    file = NULL;
    if (gArchiveSlots->mSlots[17].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[17], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[16].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[16], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[15].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[15], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[14].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[14], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[19].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[19], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[2].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[2], path);
    }
    if (file == NULL && gArchiveSlots->mSlots[1].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[1], path);
    }
    return file;
}

void *FindSceneFile(const char *path) {
    void *file;

    file = FindArchiveFile(gArchiveNames[5], path);
    if (file == NULL && gArchiveSlots->mSlots[9].mLoaded != 0) {
        file = FindArchiveFile(gArchiveNames[9], path);
    }
    if (GetCurrentSceneNumber() == 2) {
        if (file == NULL && gArchiveSlots->mSlots[11].mLoaded != 0) {
            file = FindArchiveFile(gArchiveNames[11], path);
        }
        if (file == NULL && gArchiveSlots->mSlots[12].mLoaded != 0) {
            file = FindArchiveFile(gArchiveNames[12], path);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void *FindCourseFile(const char *path) {
    void *file;
    file = FindArchiveFile(gArchiveNames[3], path);
    if (file == NULL) {
        file = FindArchiveFile(gArchiveNames[13], path);
    }
    return file;
}

void *GetKartModelFile(const char *path) {
    int currentSceneNumber;
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == 3) {
        return FindKartModelFile(path);
    }
    return LoadKartModelFile(path);
}

void *FindKartModelFile(const char *path) {
    int currentSceneNumber;
    void *file;
    file = NULL;
    currentSceneNumber = GetCurrentSceneNumber();
    if (((currentSceneNumber == 1) || (currentSceneNumber == 3)) || (currentSceneNumber == 0xc)) {
        file = FindArchiveFile(gArchiveNames[10], path);
    } else {
        if (gArchiveSlots->mSlots[6].mLoaded != 0) {
            file = FindArchiveFile(gArchiveNames[6], path);
        }
        if ((file == NULL) && (gArchiveSlots->mSlots[7].mLoaded != 0)) {
            file = FindArchiveFile(gArchiveNames[7], path);
        }
        if ((file == NULL) && (gArchiveSlots->mSlots[8].mLoaded != 0)) {
            file = FindArchiveFile(gArchiveNames[8], path);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void *LoadKartModelFile(const char *path) {
    void *file;
    s32 currentSceneNumber;
    char fullPath[0x80];
    const char *archiveName;

    file = NULL;
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == 1 || currentSceneNumber == 3 || currentSceneNumber == 0xc) {
        archiveName = gArchiveNames[10];
        if (path[0] == '/') {
            OS_SNPrintf(fullPath, 0x80, "%s:%s", archiveName, path);
        } else {
            OS_SNPrintf(fullPath, 0x80, "%s:/%s", archiveName, path);
        }
        file = LoadFileAligned(fullPath, 8);
    } else {
        if (gArchiveSlots->mSlots[6].mLoaded != 0) {
            archiveName = gArchiveNames[6];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, "%s:%s", archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, "%s:/%s", archiveName, path);
            }
            file = LoadFileAligned(fullPath, 8);
        }
        if (file == NULL && gArchiveSlots->mSlots[7].mLoaded != 0) {
            archiveName = gArchiveNames[7];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, "%s:%s", archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, "%s:/%s", archiveName, path);
            }
            file = LoadFileAligned(fullPath, 8);
        }
        if (file == NULL && gArchiveSlots->mSlots[8].mLoaded != 0) {
            archiveName = gArchiveNames[8];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, "%s:%s", archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, "%s:/%s", archiveName, path);
            }
            file = LoadFileAligned(fullPath, 8);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void ReplaceKm1ArchiveWithKm2(void) {
    ReleaseArchiveSlot(6);
    SetHeapGroupId((u16) 0);
    LoadArchiveSlotForScene(7, 2);
    SetHeapGroupId((u16) 9);
}

void ReleaseKartModelSlotsLoadCourse(void) {
    int currentSceneNumber;
    ReleaseArchiveSlot(7);
    ReleaseArchiveSlot(8);
    SetHeapGroupId((u16) 0);
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == 2) {
        LoadArchiveSlotForScene(3, 2);
    }
    SetHeapGroupId((u16) 9);
}

void ReleaseCourseLoadSlotsInRace(void) {
    int currentSceneNumber;
    ReleaseArchiveSlot(0xd);
    SetHeapGroupId((u16) 0);
    currentSceneNumber = GetCurrentSceneNumber();
    if (currentSceneNumber == 2) {
        LoadArchiveSlotForScene(5, 2);
        LoadArchiveSlotForScene(0xb, 2);
        LoadArchiveSlotForScene(0, 2);
    }
    SetHeapGroupId((u16) 9);
}

void ReleaseKartModelLoadSlotsForScene(void) {
    u32 currentSceneNumber;
    currentSceneNumber = GetCurrentSceneNumber();
    ReleaseArchiveSlot(10);
    SetHeapGroupId((u16) 0);
    LoadArchiveSlotForScene(1, currentSceneNumber);
    LoadArchiveSlotForScene(5, currentSceneNumber);
    LoadArchiveSlotForScene(0xe, currentSceneNumber);
    LoadArchiveSlotForScene(0x10, currentSceneNumber);
    SetHeapGroupId((u16) 9);
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
    InitArchiveBuffer(lastHeap, 2, 0x3c, 0, 1);
    InitArchiveBuffer(lastHeap, 3, 0x32, 0, 1);
    InitArchiveBuffer(lastHeap, 4, 5, 0, 1);
    InitArchiveBuffer(lastHeap, 5, 5, 0, 1);
    InitArchiveBuffer(lastHeap, 0, 0x14, 0, 1);
    InitArchiveBuffer(lastHeap, 1, 0x14, 0, 1);
    InitArchiveBuffer(lastHeap, 0xe, 0x46, 0, 1);
    InitArchiveBuffer(lastHeap, 0xf, 0x46, 0, 1);
    InitArchiveBuffer(courseBufferHeap, 6, 200, 1, 1);
    InitArchiveBuffer(courseBufferHeap, 7, 200, 0, 1);
    InitArchiveBuffer(firstHeap, 8, 0x46, 1, 0);
    InitArchiveBuffer(firstHeap, 0xd, 0x1e, 0, 0);
    gArchiveSlots->mFirstHeap = firstHeap;
    gArchiveSlots->mCourseBufferHeap = courseBufferHeap;
    gArchiveSlots->mLastHeap = lastHeap;
}

void InitArchiveBuffersOnOverlayHeap(void) {
    InitArchiveBuffer(gOverlayLoader->mFrmHeap, 0xb, 0xaa, 0, 0);
    InitArchiveBuffer(gOverlayLoader->mFrmHeap, 0xc, 0x6e, 0, 0);
    InitArchiveBuffer(gOverlayLoader->mFrmHeap, 9, 0x1e, 0, 0);
    InitArchiveBuffer(gOverlayLoader->mFrmHeap, 10, 0x1e, 0, 0);
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
    char path[128];
    languageCode = GetMPLanguageCode();
    OS_SNPrintf(path, 0x80, "%s%s.carc", prefix, languageCode);
    RequestArchiveLoad(path, bufferIndex);
}

void RequestMainAndMenuDLArchives(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArchiveSlots->mLastHeap, 3);
    RequestArchiveLoad("/data/KartModelMainA.carc", 0xb);
    RequestArchiveLoad("/data/KartModelMainB.carc", 0xc);
    RequestArchiveLoad("/data/Scene/MenuDL.carc", 0);
    RequestArchiveLoadWithLanguage("/data/Scene/MenuDL_", 1);
    RequestArchiveLoad("/data/MainRace.carc", 8);
    RequestArchiveLoad("/data/Main2D.carc", 9);
    RequestArchiveLoadWithLanguage("/data/Main2D_", 10);
    RequestArchiveLoad("/data/MainEffect.carc", 0xd);
}

void RequestMenuDLArchives(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArchiveSlots->mLastHeap, 3);
    RequestArchiveLoad("/data/Scene/MenuDL.carc", 0);
    RequestArchiveLoadWithLanguage("/data/Scene/MenuDL_", 1);
}

#pragma thumb off

#pragma thumb on

void RequestRaceArchives(void *courseId, void *kind) {
    char path[128];
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArchiveSlots->mLastHeap, 3);
    RequestArchiveLoad("/data/Scene/Race.carc", 2);
    RequestArchiveLoadWithLanguage("/data/Scene/Race_", 3);
    if (kind == (void *) 3) {
        RequestArchiveLoad("/data/Scene/Race_vs.carc", 4);
        RequestArchiveLoadWithLanguage("/data/Scene/Race_vs_", 5);
    } else {
        RequestArchiveLoad("/data/Scene/Race_mg.carc", 4);
        RequestArchiveLoadWithLanguage("/data/Scene/Race_mg_", 5);
    }
    gArchiveSlots->mRaceKind = kind;
    NNS_FndFreeToFrmHeap(gArchiveSlots->mCourseBufferHeap, 3);
    BuildCourseArchivePath(path, (s32) courseId, 0);
    RequestArchiveLoad(path, 6);
    BuildCourseArchivePath(path, (s32) courseId, 1);
    RequestArchiveLoad(path, 7);
    gArchiveSlots->mCourseId = courseId;
}

#pragma thumb off

#pragma thumb on

void RequestResultDLArchives(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArchiveSlots->mLastHeap, 3);
    RequestArchiveLoad("/data/Scene/ResultDL.carc", 0xe);
    RequestArchiveLoadWithLanguage("/data/Scene/ResultDL_", 0xf);
}

#pragma thumb off

#pragma thumb on

void ClearArchiveBuffersBit31(void) {
    s32 bufferIndex;

    for (bufferIndex = 0; bufferIndex < 16; bufferIndex++) {
        gArchiveSlots->mBuffers[bufferIndex].mUnk_08_31 = 0;
    }
}

s32 ShouldLoadMap2DData(void) {
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        return gArchiveSlots->mBuffers[7].mUnk_08 >> 31;
    }
    return 1;
}

// Resizes the block that holds the MainEffect archive so it ends where the caller says.
void ResizeMainEffectArchiveBlock(u8 *regionStart, u32 regionSize) {
    u8 *block;

    block = gArchiveSlots->mSlots[18].mData;
    NNS_FndResizeForMBlockExpHeap(GetHeap(GetCurrentHeapCall()), block, regionSize + (regionStart - block));
}

void InitCompressedArchiveAndMBChild(void *heap) {
    u32 uncompressedSize;
    void *data;

    uncompressedSize = *GetCompressedArchive() >> 8;
    gArchiveSlots->mSlots[19].mLoaded = 0;
    data = HeapAllocAligned(heap, uncompressedSize, 0x20);
    UncompressLZ8AndStoreRange(GetCompressedArchive(), data, uncompressedSize);
    ArchiveLoadFromMemory(&gArchiveSlots->mSlots[19].mArchive, (const u8 *) gArchiveNames[19], data);
    gArchiveSlots->mSlots[19].mData = data;
    gArchiveSlots->mSlots[19].mLoaded = 1;
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
    gTouchMicInput = HeapAlloc(heap, 0x40);
    gTouchMicInput->mTouchAutoSampling = 0;
    gTouchMicInput->mMicAutoSampling = 0;
    gTouchMicInput->mMicPreSleepDone = 0;
    gTouchMicInput->mMicOverThreshold = 0;
    gTouchMicInput->mMicBuffer = NULL;
    InitMicAndAmp();
}
