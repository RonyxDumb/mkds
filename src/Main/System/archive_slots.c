#include "Main/System/archive_slots.h"
#include "Main/System/heap.h"
#include "Main/Kart/kart_effect_param_tables.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/System/backup_net_camera_work.h"

#include "formatted_text_to_buffer.h"
#include "file_archive_access.h"
#include "overlay_rom_loader.h"
#include "file_handle_setup.h"
#include "arena_cache_init.h"
#include "Main/System/heap_call.h"
#include "Main/System/archive_buffer.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Race/race_scene_callbacks.h"
#include "Main/System/result_archive_path.h"


#pragma thumb on

void CreateMountManager_from_thumb(void *heap) {
    s32 index;

    g_MountManager = Mem_AllocateHeap(heap, sizeof(ArchiveSlots));
    g_MountManager->mLoadRequest.mReadBuffer = Mem_AllocateHeapAligned(heap, 0x400, HEAP_ALIGN_CACHE_LINE);
    for (index = 0; index < 20; index++) {
        g_MountManager->mSlots[index].mLoaded = 0;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        g_MountManager->mFileTableSize = Fs_LoadRomArchiveFatFnt(0, 0);
        g_MountManager->mFileTable = Mem_AllocateHeap(heap, g_MountManager->mFileTableSize);
        Fs_LoadRomArchiveFatFnt((u32) g_MountManager->mFileTable, g_MountManager->mFileTableSize);
    }
    for (index = 0; index < 16; index++) {
        InitializeMountDatas_from_thumb(index);
    }
    g_MountManager->mCourseId = NULL;
    g_MountManager->mFirstHeap = NULL;
    g_MountManager->mCourseBufferHeap = NULL;
    Fs_File_Initialize(&g_MountManager->mFile);
}

int OpenReadEntireFileBuffer_from_thumb(const char *path, void *buffer, u32 maxSize) {
    FSFile file;
    u32 opened;
    u32 size;

    Fs_File_Initialize(&file);
    opened = Fs_File_Open(&file, (const u8 *) path);
    if (opened != 0) {
        size = file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04;
        if (maxSize != 0 && size > maxSize) {
            opened = 0;
        } else {
            if (Fs_File_Read(&file, buffer, size) < 0) {
                opened = 0;
            }
            Fs_File_Close(&file);
        }
    }
    return opened;
}

u32 OpenReadFileBufferSize_from_thumb(void *path, void *buffer, u32 size) {
    FSFile file;
    u32 opened;

    Fs_File_Initialize(&file);
    opened = Fs_File_Open(&file, path);
    if (opened != 0) {
        if (size <= (file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04)) {
            if (Fs_File_Read(&file, buffer, size) < 0) {
                opened = 0;
            }
            Fs_File_Close(&file);
        }
    }
    return opened;
}

u32 ReadFileFromMountManagerHandle_from_thumb(char *path, NNSiFndHeapHead *heap, void **outData) {
    u32 opened;
    FSFile *file;
    u32 size;
    void *data;

    file = &g_MountManager->mFile;
    if (((file->mStat & FILE_RECORD_BUSY) ? 1 : 0) != 0) {
        return 0;
    }
    if (((file->mStat & FILE_RECORD_OPEN) ? 1 : 0) != 0) {
        Fs_File_Close(file);
    }
    opened = Fs_File_Open(file, (const u8 *) path);
    if (opened != 0) {
        size = file->mProp.p.mUnk_08 - file->mProp.p.mUnk_04;
        data = Mem_AllocateHeap(heap, size);
        *outData = data;
        if (data == NULL) {
            opened = 0;
        }
        if (opened != 0) {
            if (Fs_File_Read(file, data, size) < 0) {
                opened = 0;
                Mem_FreeHeap(heap, data);
            }
        }
        Fs_File_Close(file);
    }
    if (opened == 0) {
        size = -1;
        *outData = NULL;
    }
    return size;
}

void *AllocateReadFileBuffer_from_thumb(const char *path, s32 alignment) {
    FSFile file;
    u32 opened;
    void *data;
    u32 size;

    data = NULL;
    if (Fs_IsInitialized() == 0) {
        return NULL;
    }
    Fs_File_Initialize(&file);
    opened = Fs_File_Open(&file, (const u8 *) path);
    if (opened != 0) {
        size = file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04;
        data = Mem_AllocateHeapAligned(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), size, alignment);
        DC_SomeClean(data, size);
        if (data == NULL) {
            opened = 0;
        } else {
            if (Fs_File_Read(&file, data, size) < 0) {
                Mem_FreeHeap(ExecutionContext_GetHeapHandle(GetActiveExecutionContext()), data);
                opened = 0;
            }
            Fs_File_Close(&file);
        }
    }
    if (opened == 0) {
        data = NULL;
    }
    return data;
}

void FormatCourseCarc_from_thumb(char *path, s32 courseId, s32 useTexture) {
    BOOL useDSuffix;
    const char *textureSuffix;
    const char *dSuffix;

    useDSuffix = FALSE;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT && g_CourseNameTable[courseId].mMultibootVariant == 1) {
        useDSuffix = TRUE;
    }
    if (useTexture != 0) {
        textureSuffix = "Tex";
    } else {
        textureSuffix = "";
    }
    if (useDSuffix != FALSE) {
        dSuffix = "D";
    } else {
        dSuffix = "";
    }
    Util_SNPrintF(path, 0x80, "/data/Course/%s%s%s.carc", g_CourseNameTable[courseId].mName, dSuffix, textureSuffix);
}

u32 GetLanguageIdentifierString_from_thumb(void) {
    s32 languageIndex;

    languageIndex = g_GlobalP->mLanguageIndex;
    if (g_GlobalP->mRegion == REGION_EUROPE && languageIndex == LANGUAGE_ENGLISH) {
        languageIndex += 5;
    }
    return (u32) g_LanguageIdentifierTable[languageIndex];
}

#pragma thumb off

#pragma thumb on

u32 GetSomeLanguage_from_thumb(void) {
    u32 languageIndex;
    languageIndex = g_GlobalZE->mLanguageIndex;
    if ((g_GlobalP->mRegion == REGION_EUROPE) && (g_GlobalP->mLanguageIndex == LANGUAGE_ENGLISH)) {
        languageIndex = languageIndex + 5;
    }
    return (u32) g_LanguageIdentifierTable[languageIndex];
}

void FormatCarcWithLanguage2_from_thumb(char *path, const char *sceneName) {
    u32 languageCode;
    if (*sceneName != 0) {
        languageCode = GetLanguageIdentifierString_from_thumb();
        Util_SNPrintF(path, 0x80, "/data/Scene/%s_%s%s", sceneName, languageCode, ".carc");
    }
}

void FormatSceneArchive_from_thumb(char *path, const char *sceneName) {
    if (*sceneName != 0) {
        Util_SNPrintF(path, 0x80, "/data/Scene/%s%s", sceneName, ".carc");
    }
}

#pragma thumb off
