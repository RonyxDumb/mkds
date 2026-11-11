#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

#include "os_printf.h"
#include "code_02003be0.h"
#include "code_02004dc0.h"
#include "Main/Unknown/code_0200e000.h"
#include "fs_file.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020487a0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

void InitArchiveSlots(void *heap) {
    s32 index;

    gArchiveSlots = HeapAlloc(heap, 0xa84);
    gArchiveSlots->mLoadRequest.mReadBuffer = HeapAllocAligned(heap, 0x400, 0x20);
    for (index = 0; index < 20; index++) {
        gArchiveSlots->mSlots[index].mLoaded = 0;
    }
    if (gBootInfo->mUnk_00 != 2) {
        gArchiveSlots->mFileTableSize = FS_TryLoadTable(0, 0);
        gArchiveSlots->mFileTable = HeapAlloc(heap, gArchiveSlots->mFileTableSize);
        FS_TryLoadTable((u32) gArchiveSlots->mFileTable, gArchiveSlots->mFileTableSize);
    }
    for (index = 0; index < 16; index++) {
        ResetArchiveBuffer(index);
    }
    gArchiveSlots->mCourseId = NULL;
    gArchiveSlots->mUnk_a78 = NULL;
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
    if (gBootInfo->mUnk_00 == 2 && data_usa_02154228[courseId].mUnk_04 == 1) {
        useDSuffix = TRUE;
    }
    if (useTexture != 0) {
        textureSuffix = data_usa_02165164;
    } else {
        textureSuffix = data_usa_02165168;
    }
    if (useDSuffix != FALSE) {
        dSuffix = data_usa_0216516c;
    } else {
        dSuffix = data_usa_02165170;
    }
    OS_SNPrintf(path, 0x80, data_usa_02165174, data_usa_02154228[courseId].mUnk_00, dSuffix, textureSuffix);
}

u32 GetLanguageCode(void) {
    s32 languageIndex;

    languageIndex = gStartupWork->mLanguageIndex;
    if (gStartupWork->mRegion == 2 && languageIndex == 1) {
        languageIndex += 5;
    }
    return ((u32 *) data_02164dc8)[languageIndex];
}

#pragma thumb off

#pragma thumb on

u32 GetMPLanguageCode(void) {
    u32 languageIndex;
    languageIndex = gConnectionWork->mLanguageIndex;
    if ((gStartupWork->mRegion == 2) && (((s32 *) gStartupWork)[1] == 1)) {
        languageIndex = languageIndex + 5;
    }
    return ((u32 *) &data_02164dc8)[languageIndex];
}

void BuildSceneArchivePathWithLanguage(char *path, const char *sceneName) {
    u32 languageCode;
    if (*sceneName != 0) {
        languageCode = GetLanguageCode();
        OS_SNPrintf(path, 0x80, data_02165148, sceneName, languageCode, data_0216515c);
    }
}

void BuildSceneArchivePath(char *path, const char *sceneName) {
    if (*sceneName != 0) {
        OS_SNPrintf(path, 0x80, data_0216512c, sceneName, data_02165140);
    }
}

#pragma thumb off
