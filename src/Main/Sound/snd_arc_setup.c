#include "Main/Sound/snd_arc_setup.h"

#include "code_02003024.h"
#include "code_02003be0.h"
#include "code_0212d214.h"
#include "fs_file.h"
#include "Main/Sound/sound_set_load.h"

u32 SetupSndArcFromFile(NNSSndArc *arc, const u8 *filePath, NNSSndHeap *heap, u32 symbolLoadFlag) {
    arc->mInfo = NULL;
    arc->mFat = NULL;
    arc->mSymbol = NULL;
    if (FS_ConvertPathToFileID(&arc->mFileId, filePath) == 0) {
        return 0;
    }
    FS_InitFile(&arc->mFile);
    if (FS_OpenFileFast(&arc->mFile, arc->mFileId) == 0) {
        return 0;
    }
    arc->mFileOpen = 1;
    if (NNS_SndArcSetup(arc, heap, symbolLoadFlag) == 0) {
        return 0;
    }
    NNS_SndArcSetCurrent(arc);
    return 1;
}

void ClearSndFileIdList(SndFileIdList *fileIdList) {
    s32 fileIndex;

    for (fileIndex = 0; fileIndex < 16; fileIndex++) {
        fileIdList->mFileIds[fileIndex] = 0;
    }
    fileIdList->mCount = 0;
}

void ClearSndFileAddresses(SndFileIdList *fileIdList) {
    s32 fileIndex;

    for (fileIndex = 0; fileIndex < fileIdList->mCount; fileIndex++) {
        NNS_SndArcSetFileAddress(fileIdList->mFileIds[fileIndex], NULL);
    }
}
