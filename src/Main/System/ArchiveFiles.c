#include "Main/System/ArchiveFiles.h"
#include "Main/System/Heap.h"
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

void arc_init(void *heap) {
    s32 index;

    gArcData = heap_alloc(heap, 0xa84);
    gArcData->field8C8.mReadBuffer = heap_allocEx(heap, 0x400, 0x20);
    for (index = 0; index < 20; index++) {
        gArcData->field0[index].mLoaded = 0;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->field0 != 2) {
        gArcData->mFileTableSize = FS_TryLoadTable(0, 0);
        gArcData->mFileTable = heap_alloc(heap, gArcData->mFileTableSize);
        FS_TryLoadTable((u32) gArcData->mFileTable, gArcData->mFileTableSize);
    }
    for (index = 0; index < 16; index++) {
        arc_initSomething(index);
    }
    gArcData->fieldA70 = NULL;
    gArcData->fieldA78 = NULL;
    gArcData->mCourseBufferHeap = NULL;
    FS_InitFile(&gArcData->mFile);
}

int arc_readFileToEnd(const char *path, void *buffer, u32 maxSize) {
    FSFile file;
    u32 opened;
    u32 size;

    FS_InitFile(&file);
    opened = FS_OpenFile(&file, (const u8 *) path);
    if (opened != 0) {
        size = file.mProp.p.field8 - file.mProp.p.field4;
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

u32 arc_readFile(void *path, void *buffer, u32 size) {
    FSFile file;
    u32 opened;

    FS_InitFile(&file);
    opened = FS_OpenFile(&file, path);
    if (opened != 0) {
        if (size <= (file.mProp.p.field8 - file.mProp.p.field4)) {
            if (FS_ReadFile(&file, buffer, size) < 0) {
                opened = 0;
            }
            FS_CloseFile(&file);
        }
    }
    return opened;
}

u32 arc_loadFile(char *path, NNSiFndHeapHead *heap, void **outData) {
    u32 opened;
    FSFile *file;
    u32 size;
    void *data;

    file = &gArcData->mFile;
    if (((file->mStat & 1) ? 1 : 0) != 0) {
        return 0;
    }
    if (((file->mStat & 0x10) ? 1 : 0) != 0) {
        FS_CloseFile(file);
    }
    opened = FS_OpenFile(file, (const u8 *) path);
    if (opened != 0) {
        size = file->mProp.p.field8 - file->mProp.p.field4;
        data = heap_alloc(heap, size);
        *outData = data;
        if (data == NULL) {
            opened = 0;
        }
        if (opened != 0) {
            if (FS_ReadFile(file, data, size) < 0) {
                opened = 0;
                heap_free(heap, data);
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

void *arc_loadFileToHeap(const char *path, s32 alignment) {
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
        size = file.mProp.p.field8 - file.mProp.p.field4;
        data = heap_allocEx(proc_getHeap(proc_getCurrent()), size, alignment);
        DC_StoreRange(data, size);
        if (data == NULL) {
            opened = 0;
        } else {
            if (FS_ReadFile(&file, data, size) < 0) {
                heap_free(proc_getHeap(proc_getCurrent()), data);
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

void arc_getCourseArcPath(char *path, s32 courseId, s32 useTexture) {
    BOOL d;
    const char *textureSuffix;
    const char *dSuffix;

    d = FALSE;
    if (((Unk027ffc40 *) 0x027ffc40)->field0 == 2 && sCourseDefs[courseId].field4 == 1) {
        d = TRUE;
    }
    if (useTexture != 0) {
        textureSuffix = aTex;
    } else {
        textureSuffix = data_02165168;
    }
    if (d != FALSE) {
        dSuffix = aD_0;
    } else {
        dSuffix = data_02165170;
    }
    OS_SNPrintf(path, 0x80, aDataCourseSSS_, sCourseDefs[courseId].field0, dSuffix, textureSuffix);
}

u32 arc_getLocalizationPostfix(void) {
    s32 languageIndex;

    languageIndex = gSystemData->mLanguageIndex;
    if (gSystemData->field0 == 2 && languageIndex == 1) {
        languageIndex += 5;
    }
    return ((u32 *) sLocalizationNames)[languageIndex];
}

#pragma thumb off

#pragma thumb on

u32 GetMPLanguageCode(void) {
    u32 languageIndex;
    languageIndex = gStruct217AA00->field43C;
    if ((gSystemData->field0 == 2) && (((s32 *) gSystemData)[1] == 1)) {
        languageIndex = languageIndex + 5;
    }
    return ((u32 *) &sLocalizationNames)[languageIndex];
}

void arc_getLocalizedSceneArcPath(char *path, const char *sceneName) {
    u32 languageCode;
    if (*sceneName != 0) {
        languageCode = arc_getLocalizationPostfix();
        OS_SNPrintf(path, 0x80, aDataSceneS_S_0, sceneName, languageCode, a_carc_5);
    }
}

void arc_getSceneArcPath(char *path, const char *sceneName) {
    if (*sceneName != 0) {
        OS_SNPrintf(path, 0x80, aDataSceneSS, sceneName, a_carc_4);
    }
}

#pragma thumb off
