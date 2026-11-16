#include "Main/Sound/sound_archive_setup.h"

#include "file_command_handlers.h"
#include "file_archive_access.h"
#include "sound_archive_load.h"
#include "file_handle_setup.h"
#include "Main/Sound/sound_set_load.h"

u32 Sound_ReadSdatFromPathImplV2(NNSSndArc *arc, const u8 *filePath, NNSSndHeap *heap, u32 symbolLoadFlag) {
    arc->mInfo = NULL;
    arc->mFat = NULL;
    arc->mSymbol = NULL;
    if (Fs_FileId_LoadFromPath(&arc->mFileId, filePath) == 0) {
        return 0;
    }
    Fs_File_Initialize(&arc->mFile);
    if (Fs_File_OpenById(&arc->mFile, arc->mFileId) == 0) {
        return 0;
    }
    arc->mFileOpen = 1;
    if (Sound_ReadSdatFromOpenedFile(arc, heap, symbolLoadFlag) == 0) {
        return 0;
    }
    Sound_MaybeSetActiveSdat(arc);
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
        Sound_SetFileFatDynamicOffsetField(fileIdList->mFileIds[fileIndex], NULL);
    }
}
