#include "Main/System/archive_slots.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/MapObjects/data_0217a000.h"

#include "os_printf.h"
#include "code_02003be0.h"
#include "code_02004dc0.h"
#include "fs_file.h"
#include "code_0200eddc.h"
#include "Main/System/heap_call.h"
#include "Main/System/archive_buffer.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/Race/data_02164000.h"
#include "Main/System/result_archive_path.h"


#pragma thumb on

void InitArchiveSlots(void *heap) {
    s32 index;

    gArchiveSlots = HeapAlloc(heap, sizeof(ArchiveSlots));
    gArchiveSlots->mLoadRequest.mReadBuffer = HeapAllocAligned(heap, 0x400, HEAP_ALIGN_CACHE_LINE);
    for (index = 0; index < 20; index++) {
        gArchiveSlots->mSlots[index].mLoaded = 0;
    }
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        gArchiveSlots->mFileTableSize = FS_TryLoadTable(0, 0);
        gArchiveSlots->mFileTable = HeapAlloc(heap, gArchiveSlots->mFileTableSize);
        FS_TryLoadTable((u32) gArchiveSlots->mFileTable, gArchiveSlots->mFileTableSize);
    }
    for (index = 0; index < 16; index++) {
        ResetArchiveBuffer(index);
    }
    gArchiveSlots->mCourseId = NULL;
    gArchiveSlots->mFirstHeap = NULL;
    gArchiveSlots->mCourseBufferHeap = NULL;
    FS_InitFile(&gArchiveSlots->mFile);
}

int ReadWholeFile(const char *path, void *buffer, u32 maxSize) {
    FSFile file;
    u32 opened;
    u32 size;

    FS_InitFile(&file);
    opened = FS_OpenFile(&file, (const u8 *) path);
    if (opened != 0) {
        size = file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04;
        if (maxSize != 0 && size > maxSize) {
            opened = 0;
        } else {
            if (FS_ReadFile(&file, buffer, size) < 0) {
                opened = 0;
            }
            FS_CloseFile(&file);
        }
    }
    return opened;
}

u32 ReadFileBytes(void *path, void *buffer, u32 size) {
    FSFile file;
    u32 opened;

    FS_InitFile(&file);
    opened = FS_OpenFile(&file, path);
    if (opened != 0) {
        if (size <= (file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04)) {
            if (FS_ReadFile(&file, buffer, size) < 0) {
                opened = 0;
            }
            FS_CloseFile(&file);
        }
    }
    return opened;
}

u32 LoadFileIntoHeap(char *path, NNSiFndHeapHead *heap, void **outData) {
    u32 opened;
    FSFile *file;
    u32 size;
    void *data;

    file = &gArchiveSlots->mFile;
    if (((file->mStat & 1) ? 1 : 0) != 0) {
        return 0;
    }
    if (((file->mStat & 0x10) ? 1 : 0) != 0) {
        FS_CloseFile(file);
    }
    opened = FS_OpenFile(file, (const u8 *) path);
    if (opened != 0) {
        size = file->mProp.p.mUnk_08 - file->mProp.p.mUnk_04;
        data = HeapAlloc(heap, size);
        *outData = data;
        if (data == NULL) {
            opened = 0;
        }
        if (opened != 0) {
            if (FS_ReadFile(file, data, size) < 0) {
                opened = 0;
                HeapFree(heap, data);
            }
        }
        FS_CloseFile(file);
    }
    if (opened == 0) {
        size = -1;
        *outData = NULL;
    }
    return size;
}

void *LoadFileAligned(const char *path, s32 alignment) {
    FSFile file;
    u32 opened;
    void *data;
    u32 size;

    data = NULL;
    if (FS_IsAvailable() == 0) {
        return NULL;
    }
    FS_InitFile(&file);
    opened = FS_OpenFile(&file, (const u8 *) path);
    if (opened != 0) {
        size = file.mProp.p.mUnk_08 - file.mProp.p.mUnk_04;
        data = HeapAllocAligned(GetHeap(GetCurrentHeapCall()), size, alignment);
        DC_StoreRange(data, size);
        if (data == NULL) {
            opened = 0;
        } else {
            if (FS_ReadFile(&file, data, size) < 0) {
                HeapFree(GetHeap(GetCurrentHeapCall()), data);
                opened = 0;
            }
            FS_CloseFile(&file);
        }
    }
    if (opened == 0) {
        data = NULL;
    }
    return data;
}

void BuildCourseArchivePath(char *path, s32 courseId, s32 useTexture) {
    BOOL useDSuffix;
    const char *textureSuffix;
    const char *dSuffix;

    useDSuffix = FALSE;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT && gCourseArchiveNames[courseId].mMultibootVariant == 1) {
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
    OS_SNPrintf(path, 0x80, "/data/Course/%s%s%s.carc", gCourseArchiveNames[courseId].mName, dSuffix, textureSuffix);
}

u32 GetLanguageCode(void) {
    s32 languageIndex;

    languageIndex = gStartupWork->mLanguageIndex;
    if (gStartupWork->mRegion == 2 && languageIndex == LANGUAGE_ENGLISH) {
        languageIndex += 5;
    }
    return (u32) gLanguageCodes[languageIndex];
}

#pragma thumb off

#pragma thumb on

u32 GetMPLanguageCode(void) {
    u32 languageIndex;
    languageIndex = gConnectionWork->mLanguageIndex;
    if ((gStartupWork->mRegion == 2) && (gStartupWork->mLanguageIndex == LANGUAGE_ENGLISH)) {
        languageIndex = languageIndex + 5;
    }
    return (u32) gLanguageCodes[languageIndex];
}

void BuildSceneArchivePathWithLanguage(char *path, const char *sceneName) {
    u32 languageCode;
    if (*sceneName != 0) {
        languageCode = GetLanguageCode();
        OS_SNPrintf(path, 0x80, "/data/Scene/%s_%s%s", sceneName, languageCode, ".carc");
    }
}

void BuildSceneArchivePath(char *path, const char *sceneName) {
    if (*sceneName != 0) {
        OS_SNPrintf(path, 0x80, "/data/Scene/%s%s", sceneName, ".carc");
    }
}

#pragma thumb off
