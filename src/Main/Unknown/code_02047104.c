#include "Main/Unknown/code_02047104.h"

#include "Main/System/Heap.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020487a0.h"
#include "Main/Unknown/code_020cade8.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_0210f130.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020176c0.h"
#include "code_020182c0.h"
#include "tp.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/System/ArchiveFiles.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0205e000.h"
#include "code_020176b0.h"
#include "frameheap.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/unk_02165000.h"
#include "os_printf.h"
#include "code_02003be0.h"
#include "code_0200eddc.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200e000.h"
#include "fs_file.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "code_0214d464.h"
#include "code_0214d564.h"
#include "00/code_02181f98.h"

#pragma thumb on

void arc_getResultSceneArcPath(char *path) {
    const char *suffix;

    if (gStruct217B488->mUnk_78 == 1) {
        suffix = aDl;
    } else {
        suffix = data_0216510c;
    }
    OS_SNPrintf(path, 0x80, aDataSceneSSS, sSceneDefs[10].mName, suffix, a_carc_3);
}

void arc_getLocalizedResultSceneArcPath(char *path) {
    const char *suffix;
    u32 languageCode;

    if (gStruct217B488->mUnk_78 == 1) {
        suffix = aDl_0;
    } else {
        suffix = data_021650e4;
    }
    languageCode = arc_getLocalizationPostfix();
    OS_SNPrintf(path, 0x80, aDataSceneSS_SS, sSceneDefs[10].mName, suffix, languageCode,
                a_carc_2);
}

#pragma thumb off

#pragma thumb on

void arc_getLocalizedStaffrollSceneArcPath(char *path) {
    u32 languageCode;
    languageCode = arc_getLocalizationPostfix();
    OS_SNPrintf(path, 0x80, aDataSceneSta_0, languageCode, a_carc_1);
}

void arc_getRaceSceneArcPath(char *path, const char *sceneName, int mode) {
    if (*sceneName != 0) {
        OS_SNPrintf(path, 0x80, aDataSceneS_SS, sceneName, sRaceModeNames[mode], a_carc_0);
    }
}

void arc_getLocalizedRaceSceneArcPath(char *path, const char *sceneName, int mode) {
    u32 languageCode;
    if (*sceneName != 0) {
        languageCode = arc_getLocalizationPostfix();
        OS_SNPrintf(path, 0x80, aDataSceneS_S_S, sceneName, sRaceModeNames[mode], languageCode,
                    a_carc);
    }
}

void arc_getLocalizedArcPath(const char *prefix, char *path) {
    u32 languageCode;
    languageCode = arc_getLocalizationPostfix();
    OS_SNPrintf(path, 0x80, aS_S_carc, prefix, languageCode);
}

#pragma thumb off

#pragma thumb on

void arc_loadArchiveForScene(int slotIndex, int sceneNumber) {
    char path[0x80] = {0};
    u32 *bufferData;
    s32 f;
    s32 uncompressSource;
    s32 g;
    s32 h;

    bufferData = NULL;
    if (gArcData->mUnk_00[slotIndex].mLoaded != 0) {
        return;
    }
    uncompressSource = sArcDefs[slotIndex].mUncompressSource;
    f = sArcDefs[slotIndex].mUnk_10;
    g = sArcDefs[slotIndex].mUnk_14;
    h = sArcDefs[slotIndex].mBufferIndex;
    if (h != -1) {
        bufferData = gArcData->mBuffers[h].mData;
    }
    switch (slotIndex) {
        case 3:
        case 13:
            arc_getCourseArcPath(path, gRaceMultiConfig->mCourseId, slotIndex != 3);
            break;
        case 5:
            switch (sceneNumber) {
                case 2:
                    bufferData = gArcData->mBuffers[2].mData;
                    break;
                case 1:
                    bufferData = gArcData->mBuffers[0].mData;
                    break;
                case 10:
                    bufferData = gArcData->mBuffers[14].mData;
                    break;
            }
            switch (sceneNumber) {
                case 10:
                    arc_getResultSceneArcPath(path);
                    break;
                case 2:
                    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        OS_SNPrintf(path, 0x80, aDataSceneStaff);
                    } else {
                        arc_getSceneArcPath(path, sSceneDefs[sceneNumber].mName);
                    }
                    break;
                default:
                    arc_getSceneArcPath(path, sSceneDefs[sceneNumber].mName);
                    break;
            }
            g = sSceneDefs[sceneNumber].mUnk_04;
            break;
        case 9:
            switch (sceneNumber) {
                case 2:
                    bufferData = gArcData->mBuffers[3].mData;
                    break;
                case 1:
                    bufferData = gArcData->mBuffers[1].mData;
                    break;
                case 10:
                    bufferData = gArcData->mBuffers[15].mData;
                    break;
            }
            switch (sceneNumber) {
                case 10:
                    arc_getLocalizedResultSceneArcPath(path);
                    break;
                case 2:
                    if (gRaceMultiConfig->mRaceKind == RACE_KIND_STAFF_ROLL) {
                        arc_getLocalizedStaffrollSceneArcPath(path);
                    } else {
                        arc_getLocalizedSceneArcPath(path, sSceneDefs[sceneNumber].mName);
                    }
                    break;
                default:
                    arc_getLocalizedSceneArcPath(path, sSceneDefs[sceneNumber].mName);
                    break;
            }
            break;
        case 11:
            arc_getRaceSceneArcPath(path, sSceneDefs[sceneNumber].mName, gRaceMultiConfig->mMode);
            break;
        case 12:
            arc_getLocalizedRaceSceneArcPath(path, sSceneDefs[sceneNumber].mName, gRaceMultiConfig->mMode);
            break;
        case 2:
        case 15:
        case 17:
            arc_getLocalizedArcPath(sArcDefs[slotIndex].mPath, path);
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
            strncpy(path, sArcDefs[(s32) slotIndex].mPath, 0x80);
            break;
    }
    if (path[0] != 0) {
        arc_loadArchive(slotIndex, path, bufferData, NULL, f, uncompressSource, g);
    }
    h = *(s32 *) ((s32) &sArcDefs[0].mNextSlot + slotIndex * 0x18);
    if (h != -1) {
        arc_loadArchiveForScene(h, sceneNumber);
    }
}

void arc_loadArchive(s32 slotIndex, const char *path, u32 *sourceData, void *data, s32 e, s32 uncompressSource, s32 g) {
    ArchiveLoadRequest *request;
    s32 bufferIndex;

    request = &gArcData->mUnk_8c8;
    strncpy((char *) request->mPath, path, 0x80);
    request->mSlotIndex = slotIndex;
    request->mSourceData = sourceData;
    request->mData = data;
    request->mUnk_90 = e;
    request->mUncompressSource = uncompressSource;
    request->mUnk_9c = g;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        if (request->mSourceData != NULL) {
            if (request->mUncompressSource != 0) {
                bufferIndex = sArcDefs[slotIndex].mBufferIndex;
                if (bufferIndex != -1) {
                    gArcData->mBuffers[bufferIndex].mUnk_08_31 = 1;
                }
                arc_loadArchiveFromMem();
            } else {
                request->mData = request->mSourceData;
            }
            arc_mountArchive();
        }
    } else {
        if (slotIndex == 0x13) {
            arc_loadArchiveFromMem();
        } else {
            arc_loadArchiveFromFile();
        }
        arc_mountArchive();
    }
}

void arc_loadArchiveFromFile(void) {
    ArchiveLoadRequest *request;
    FSFile file;
    MIUncompContextLZ uncompContext;
    u32 uncompressedSize;
    s32 bytesRead;

    request = &gArcData->mUnk_8c8;
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
    if (request->mUnk_90 != 0) {
        request->mData = heap_allocEx(proc_getHeap(proc_getCurrent()), uncompressedSize, -0x20);
    } else {
        request->mData = heap_allocEx(proc_getHeap(proc_getCurrent()), uncompressedSize, 0x20);
    }
    MI_InitUncompContextLZ(&uncompContext, request->mData, (const MICompressionHeader *) request->mReadBuffer);
    do {
        bytesRead = FS_ReadFile(&file, request->mReadBuffer, 0x400);
        if (bytesRead <= 0) {
            return;
        }
    } while (MI_ReadUncompLZ8(&uncompContext, (const u8 *) request->mReadBuffer, bytesRead) != 0);
    DC_StoreRange(request->mData, uncompressedSize);
    NNS_FndGetTotalFreeSizeForExpHeap(proc_getHeap(proc_getCurrent()));
}

void arc_loadArchiveFromMem(void) {
    ArchiveLoadRequest *request;
    u32 uncompressedSize;

    request = &gArcData->mUnk_8c8;
    uncompressedSize = *request->mSourceData >> 8;
    if (request->mUnk_90 != 0) {
        request->mData = heap_allocEx(proc_getHeap(proc_getCurrent()), uncompressedSize, -0x20);
    } else {
        request->mData = heap_allocEx(proc_getHeap(proc_getCurrent()), uncompressedSize, 0x20);
    }
    MI_UncompressLZ8(request->mSourceData, request->mData);
    DC_StoreRange(request->mData, uncompressedSize);
    NNS_FndGetTotalFreeSizeForExpHeap(proc_getHeap(proc_getCurrent()));
}

void arc_mountArchive(void) {
    ArchiveLoadRequest *request;
    ArchiveSlot *slot;

    request = &gArcData->mUnk_8c8;
    slot = &gArcData->mUnk_00[request->mSlotIndex];
    if (request->mData != NULL) {
        if (NNS_FndMountArchive(&slot->mArchive, (const u8 *) sArcNames[request->mSlotIndex], request->mData) !=
            0) {
            slot->mLoaded = 1;
            slot->mData = request->mData;
        }
    }
}

void arc_unloadArchive(int slotIndex) {
    BOOL shouldFree;
    s32 bufferIndex;

    shouldFree = TRUE;
    if (gArcData->mUnk_00[slotIndex].mLoaded != 0 && slotIndex != 0x13) {
        NNS_FndUnmountArchive(&gArcData->mUnk_00[slotIndex].mArchive.mUnk_00);
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            bufferIndex = sArcDefs[slotIndex].mBufferIndex;
            if (bufferIndex != -1 && gArcData->mBuffers[bufferIndex].mUncompress != 0) {
                shouldFree = FALSE;
            } else {
                gArcData->mBuffers[bufferIndex].mUnk_08_31 = 1;
            }
        }
        if (shouldFree != FALSE) {
            heap_free(proc_getHeap(proc_getCurrent()), gArcData->mUnk_00[slotIndex].mData);
        }
        gArcData->mUnk_00[slotIndex].mLoaded = 0;
        gArcData->mUnk_00[slotIndex].mData = 0;
        NNS_FndGetTotalFreeSizeForExpHeap(proc_getHeap(proc_getCurrent()));
    }
}

void arc_loadArchivesForScene(s32 sceneNumber) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 && sceneNumber == 6 && gStruct217B488->mUnk_74 == 0) {
    } else {
        arc_loadArchiveForScene(1, sceneNumber);
    }
    switch (sceneNumber) {
        case 1:
        case 12:
            arc_loadArchiveForScene(5, sceneNumber);
            arc_loadArchiveForScene(14, sceneNumber);
            arc_loadArchiveForScene(16, sceneNumber);
            break;
        case 10:
            arc_loadArchiveForScene(0, sceneNumber);
            arc_loadArchiveForScene(5, sceneNumber);
            arc_loadArchiveForScene(16, sceneNumber);
            arc_loadArchiveForScene(18, sceneNumber);
            break;
        case 2:
            arc_loadArchiveForScene(18, sceneNumber);
            arc_loadArchiveForScene(6, sceneNumber);
            arc_loadArchiveForScene(8, sceneNumber);
            break;
        case 3:
            arc_loadArchiveForScene(0, sceneNumber);
            arc_loadArchiveForScene(5, sceneNumber);
            arc_loadArchiveForScene(16, sceneNumber);
            break;
        case 5:
            arc_loadArchiveForScene(5, sceneNumber);
            arc_loadArchiveForScene(14, sceneNumber);
            arc_loadArchiveForScene(16, sceneNumber);
            break;
        case 0:
        case 7:
        case 8:
        case 9:
        case 11:
        case 13:
        case 14:
        case 15:
            arc_loadArchiveForScene(5, sceneNumber);
            arc_loadArchiveForScene(16, sceneNumber);
            break;
        case 4:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                arc_loadArchiveForScene(5, sceneNumber);
                arc_loadArchiveForScene(16, sceneNumber);
            }
            break;
        case 6:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                arc_loadArchiveForScene(5, sceneNumber);
                arc_loadArchiveForScene(16, sceneNumber);
            }
            break;
    }
}

void arc_unloadAllArchives(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        arc_unloadArchive(i);
    }
}

#pragma thumb off

#pragma thumb on
void arc_setHeapGroupId(u32 groupId) {
    NNS_FndSetGroupIDForExpHeap(proc_getHeap(proc_getCurrent()), groupId);
}
#pragma thumb off

#pragma thumb on

void *arc_getArchiveFile(u32 archiveName, const char *path) {
    char fullPath[0x80];

    if (path[0] == '/') {
        OS_SNPrintf(fullPath, 0x80, aSS_8, archiveName, path);
    } else {
        OS_SNPrintf(fullPath, 0x80, aSS_9, archiveName, path);
    }
    return NNS_FndGetArchiveFileByName((const u8 *) fullPath);
}

#pragma thumb off

#pragma thumb on

void *arc_getMainRaceMainEffectArcFile(const char *path) {
    void *file;
    file = arc_getArchiveFile(sArcNames[0], path);
    if (file == NULL) {
        file = arc_getArchiveFile(sArcNames[18], path);
    }
    return file;
}

#pragma thumb off

#pragma thumb on

// Searches the archives that are loaded, in a fixed order, and returns the first match.
void *arc_get2dArcFile(const char *path) {
    void *file;

    file = NULL;
    if (gArcData->mUnk_7d8 != 0) {
        file = arc_getArchiveFile(sArcNames[17], path);
    }
    if (file == NULL && gArcData->mUnk_768 != 0) {
        file = arc_getArchiveFile(sArcNames[16], path);
    }
    if (file == NULL && gArcData->mUnk_6f8 != 0) {
        file = arc_getArchiveFile(sArcNames[15], path);
    }
    if (file == NULL && gArcData->mUnk_688 != 0) {
        file = arc_getArchiveFile(sArcNames[14], path);
    }
    if (file == NULL && gArcData->mUnk_8b8 != 0) {
        file = arc_getArchiveFile(sArcNames[19], path);
    }
    if (file == NULL && gArcData->mUnk_148 != 0) {
        file = arc_getArchiveFile(sArcNames[2], path);
    }
    if (file == NULL && gArcData->mUnk_d8 != 0) {
        file = arc_getArchiveFile(sArcNames[1], path);
    }
    return file;
}

void *arc_getSceneArcFile(const char *path) {
    void *file;

    file = arc_getArchiveFile(sArcNames[5], path);
    if (file == NULL && gArcData->mUnk_458 != 0) {
        file = arc_getArchiveFile(sArcNames[9], path);
    }
    if (scproc_getCurrentScene() == 2) {
        if (file == NULL && gArcData->mUnk_538 != 0) {
            file = arc_getArchiveFile(sArcNames[11], path);
        }
        if (file == NULL && gArcData->mUnk_5a8 != 0) {
            file = arc_getArchiveFile(sArcNames[12], path);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void *arc_getCourseArcFile(const char *path) {
    void *file;
    file = arc_getArchiveFile(sArcNames[3], path);
    if (file == NULL) {
        file = arc_getArchiveFile(sArcNames[13], path);
    }
    return file;
}

void *arc_getKartModelArcFileSafe(const char *path) {
    int currentSceneNumber;
    currentSceneNumber = scproc_getCurrentScene();
    if (currentSceneNumber == 3) {
        return arc_getKartModelArcFile(path);
    }
    return arc_getKartModelArcFileCopy(path);
}

void *arc_getKartModelArcFile(const char *path) {
    int currentSceneNumber;
    void *file;
    file = NULL;
    currentSceneNumber = scproc_getCurrentScene();
    if (((currentSceneNumber == 1) || (currentSceneNumber == 3)) || (currentSceneNumber == 0xc)) {
        file = arc_getArchiveFile(sArcNames[10], path);
    } else {
        if (gArcData->mUnk_308 != 0) {
            file = arc_getArchiveFile(sArcNames[6], path);
        }
        if ((file == NULL) && (gArcData->mUnk_378 != 0)) {
            file = arc_getArchiveFile(sArcNames[7], path);
        }
        if ((file == NULL) && (gArcData->mUnk_3e8 != 0)) {
            file = arc_getArchiveFile(sArcNames[8], path);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void *arc_getKartModelArcFileCopy(const char *path) {
    void *file;
    s32 currentSceneNumber;
    char fullPath[0x80];
    u32 archiveName;

    file = NULL;
    currentSceneNumber = scproc_getCurrentScene();
    if (currentSceneNumber == 1 || currentSceneNumber == 3 || currentSceneNumber == 0xc) {
        archiveName = sArcNames[10];
        if (path[0] == '/') {
            OS_SNPrintf(fullPath, 0x80, aSS_0, archiveName, path);
        } else {
            OS_SNPrintf(fullPath, 0x80, aSS_1, archiveName, path);
        }
        file = arc_loadFileToHeap(fullPath, 8);
    } else {
        if (gArcData->mUnk_00[6].mLoaded != 0) {
            archiveName = sArcNames[6];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, aSS_2, archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, aSS_3, archiveName, path);
            }
            file = arc_loadFileToHeap(fullPath, 8);
        }
        if (file == NULL && gArcData->mUnk_00[7].mLoaded != 0) {
            archiveName = sArcNames[7];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, aSS_4, archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, aSS_5, archiveName, path);
            }
            file = arc_loadFileToHeap(fullPath, 8);
        }
        if (file == NULL && gArcData->mUnk_00[8].mLoaded != 0) {
            archiveName = sArcNames[8];
            if (path[0] == '/') {
                OS_SNPrintf(fullPath, 0x80, aSS_6, archiveName, path);
            } else {
                OS_SNPrintf(fullPath, 0x80, aSS_7, archiveName, path);
            }
            file = arc_loadFileToHeap(fullPath, 8);
        }
    }
    return file;
}

#pragma thumb off

#pragma thumb on

void arc_switchKartModelMainAtoB(void) {
    arc_unloadArchive(6);
    arc_setHeapGroupId((u16) 0);
    arc_loadArchiveForScene(7, 2);
    arc_setHeapGroupId((u16) 9);
}

void arc_switchKartModelBSubToCourse(void) {
    int currentSceneNumber;
    arc_unloadArchive(7);
    arc_unloadArchive(8);
    arc_setHeapGroupId((u16) 0);
    currentSceneNumber = scproc_getCurrentScene();
    if (currentSceneNumber == 2) {
        arc_loadArchiveForScene(3, 2);
    }
    arc_setHeapGroupId((u16) 9);
}

void arc_switchCourseTexToSceneRace(void) {
    int currentSceneNumber;
    arc_unloadArchive(0xd);
    arc_setHeapGroupId((u16) 0);
    currentSceneNumber = scproc_getCurrentScene();
    if (currentSceneNumber == 2) {
        arc_loadArchiveForScene(5, 2);
        arc_loadArchiveForScene(0xb, 2);
        arc_loadArchiveForScene(0, 2);
    }
    arc_setHeapGroupId((u16) 9);
}

void func_020476ac(void) {
    u32 currentSceneNumber;
    currentSceneNumber = scproc_getCurrentScene();
    arc_unloadArchive(10);
    arc_setHeapGroupId((u16) 0);
    arc_loadArchiveForScene(1, currentSceneNumber);
    arc_loadArchiveForScene(5, currentSceneNumber);
    arc_loadArchiveForScene(0xe, currentSceneNumber);
    arc_loadArchiveForScene(0x10, currentSceneNumber);
    arc_setHeapGroupId((u16) 9);
}

#pragma thumb off

#pragma thumb on

void InitArchiveBuffer(NNSiFndHeapHead *heap, s32 bufferIndex, s32 c, u32 uncompress, u32 e) {
    ArchiveBuffer *buffer = &gArcData->mBuffers[bufferIndex];
    buffer->mHeap = heap;
    buffer->mData = NULL;
    buffer->mUnk_08_0 = c << 10;
    buffer->mUncompress = uncompress;
    buffer->mUnk_08_30 = e;
    buffer->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

// Sets up 12 archive buffers on three heaps.
void InitArchiveBuffers(NNSiFndHeapHead *a, NNSiFndHeapHead *courseBufferHeap, NNSiFndHeapHead *c) {
    InitArchiveBuffer(c, 2, 0x3c, 0, 1);
    InitArchiveBuffer(c, 3, 0x32, 0, 1);
    InitArchiveBuffer(c, 4, 5, 0, 1);
    InitArchiveBuffer(c, 5, 5, 0, 1);
    InitArchiveBuffer(c, 0, 0x14, 0, 1);
    InitArchiveBuffer(c, 1, 0x14, 0, 1);
    InitArchiveBuffer(c, 0xe, 0x46, 0, 1);
    InitArchiveBuffer(c, 0xf, 0x46, 0, 1);
    InitArchiveBuffer(courseBufferHeap, 6, 200, 1, 1);
    InitArchiveBuffer(courseBufferHeap, 7, 200, 0, 1);
    InitArchiveBuffer(a, 8, 0x46, 1, 0);
    InitArchiveBuffer(a, 0xd, 0x1e, 0, 0);
    gArcData->mUnk_a78 = a;
    gArcData->mCourseBufferHeap = courseBufferHeap;
    gArcData->mUnk_a80 = c;
}

void func_020474e4(void) {
    InitArchiveBuffer(gOverlayData->mFrmHeap, 0xb, 0xaa, 0, 0);
    InitArchiveBuffer(gOverlayData->mFrmHeap, 0xc, 0x6e, 0, 0);
    InitArchiveBuffer(gOverlayData->mFrmHeap, 9, 0x1e, 0, 0);
    InitArchiveBuffer(gOverlayData->mFrmHeap, 10, 0x1e, 0, 0);
}

#pragma thumb off

#pragma thumb on

void RequestArchiveLoad(const void *path, s32 bufferIndex) {
    ArchiveBuffer *buffer = &gArcData->mBuffers[bufferIndex];
    AddPendingFile(path, buffer->mHeap, &buffer->mData, buffer->mUnk_08_0, buffer->mUncompress);
    buffer->mUnk_08_31 = 1;
}

#pragma thumb off

#pragma thumb on

void RequestArchiveLoadWithLanguage(const void *prefix, u32 bufferIndex) {
    u32 languageCode;
    char path[128];
    languageCode = GetMPLanguageCode();
    OS_SNPrintf(path, 0x80, aSS_carc, prefix, languageCode);
    RequestArchiveLoad(path, bufferIndex);
}

void func_020473e4(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArcData->mUnk_a80, 3);
    RequestArchiveLoad(aDataKartmode_4, 0xb);
    RequestArchiveLoad(aDataKartmode_5, 0xc);
    RequestArchiveLoad(aDataSceneMen_1, 0);
    RequestArchiveLoadWithLanguage(aDataSceneMen_2, 1);
    RequestArchiveLoad(aDataMainrace_0, 8);
    RequestArchiveLoad(aDataMain2d_c_0, 9);
    RequestArchiveLoadWithLanguage(aDataMain2d_, 10);
    RequestArchiveLoad(aDataMaineffe_0, 0xd);
}

void RequestMenuDLArchives(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArcData->mUnk_a80, 3);
    RequestArchiveLoad(aDataSceneMenud, 0);
    RequestArchiveLoadWithLanguage(aDataSceneMen_0, 1);
}

#pragma thumb off

#pragma thumb on

void RequestRaceArchives(void *courseId, void *b) {
    char path[128];
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArcData->mUnk_a80, 3);
    RequestArchiveLoad(aDataSceneRace_, 2);
    RequestArchiveLoadWithLanguage(aDataSceneRac_0, 3);
    if (b == (void *) 3) {
        RequestArchiveLoad(aDataSceneRac_1, 4);
        RequestArchiveLoadWithLanguage(aDataSceneRac_2, 5);
    } else {
        RequestArchiveLoad(aDataSceneRac_3, 4);
        RequestArchiveLoadWithLanguage(aDataSceneRac_4, 5);
    }
    gArcData->mUnk_a74 = b;
    NNS_FndFreeToFrmHeap(gArcData->mCourseBufferHeap, 3);
    arc_getCourseArcPath(path, (s32) courseId, 0);
    RequestArchiveLoad(path, 6);
    arc_getCourseArcPath(path, (s32) courseId, 1);
    RequestArchiveLoad(path, 7);
    gArcData->mUnk_a70 = courseId;
}

#pragma thumb off

#pragma thumb on

void RequestResultDLArchives(void) {
    ResetPendingFiles();
    NNS_FndFreeToFrmHeap(gArcData->mUnk_a80, 3);
    RequestArchiveLoad(aDataSceneResul, 0xe);
    RequestArchiveLoadWithLanguage(aDataSceneRes_0, 0xf);
}

#pragma thumb off

#pragma thumb on

void arc_2047274(void) {
    s32 i;

    for (i = 0; i < 16; i++) {
        *OFFSET_PTR(u32, &gArcData->mBuffers[0].mUnk_08, i * 12) &= 0x7fffffff;
    }
}

s32 arc_isCourseTexAvailable(void) {
    if (*(vu16 *) 0x027ffc40 == 2) {
        return gArcData->mBuffers[7].mUnk_08 >> 31;
    }
    return 1;
}

// Resizes the block that holds the MainEffect archive so it ends where the caller says.
void arc_resizeMainEffectArc(u8 *a, u32 b) {
    u8 *block;

    block = gArcData->mUnk_84c;
    NNS_FndResizeForMBlockExpHeap(proc_getHeap(proc_getCurrent()), block, b + (a - block));
}

void arc_loadStatic2D(void *heap) {
    u32 uncompressedSize;
    void *data;

    uncompressedSize = *s2d_getArcData() >> 8;
    gArcData->mUnk_8b8 = 0;
    data = heap_allocEx(heap, uncompressedSize, 0x20);
    arc_decompressLZ(s2d_getArcData(), data, uncompressedSize);
    NNS_FndMountArchive(&gArcData->mUnk_850, (const u8 *) sArcNames[19], data);
    gArcData->mUnk_8bc = data;
    gArcData->mUnk_8b8 = 1;
    s2d_init(heap);
}

#pragma thumb off

void spi_initTouch(void) {
    TPCalibrateParam calibrateParam;

    TP_Init();
    if (TP_GetUserInfo(&calibrateParam) == 0) {
        return;
    }
    TP_SetCalibrateParam(&calibrateParam);
}

void spi_init(void *heap) {
    gSpiData = heap_alloc(heap, 0x40);
    gSpiData->mTouchAutoSampling = 0;
    gSpiData->mMicAutoSampling = 0;
    gSpiData->mUnk_30_2 = 0;
    gSpiData->mMicOverThreshold = 0;
    gSpiData->mMicBuffer = NULL;
    mic_init();
}
