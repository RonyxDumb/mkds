#pragma once

#include "types.h"

#include "file_command_handlers.h"

void Fs_Archive_NotifyAsyncEnded(FSArchive *archive, u32 result);
void Fs_Archive_SetExtraFileOperationHandler(FSArchive *archive, FS_ARCHIVE_PROC_FUNC proc, u32 flags);
u32 Fs_Archive_Resume(FSArchive *archive);
u32 Fs_Archive_Suspend(FSArchive *archive);
u32 FS_UnloadArchiveTables(FSArchive *archive);
u32 Fs_Archive_LoadFatFnt(FSArchive *archive, u32 mem, u32 maxSize);
u32 Fs_Archive_UnloadFatFnt(FSArchive *archive);
u32 Fs_Archive_LoadFromFatFnt(FSArchive *archive, u8 *base, u32 fat, u32 fatSize, u32 fnt, u32 fntSize,
                   FS_ARCHIVE_READ_FUNC readFunc, FS_ARCHIVE_WRITE_FUNC writeFunc);
void Fs_UnregisterArchive(FSArchive *archive);
u32 Fs_RegisterArchive(FSArchive *archive, const u8 *name, s32 nameLen);
FSArchive *Fs_FindArchiveByMountName(const u8 *name, s32 nameLen);

void Fs_Archive_Initialize(FSArchive *archive);

u32 Fs_File_SendOperation(FSFile *file, u32 command);
u32 Fs_File_ExecuteSyncOperation(FSFile *file);
void Fs_File_ExecuteAsyncOperation(FSFile *file);
FSFile *Fs_Archive_HandleNextOperation(FSArchive *archive);
s32 Fs_Archive_DefaultFatFntRead(FSArchive *archive, void *dst, u32 pos, u32 size);
s32 Fs_Archive_WriteFn_Default(FSArchive *archive, const void *src, u32 pos, u32 size);
s32 Fs_Archive_ReadFn_Default(FSArchive *archive, void *dst, u32 pos, u32 size);
u32 Fs_PackArchiveMountName(const u8 *name, s32 nameLen);
u32 Fs_Chdir(const u8 *path);
// Values of the origin of Fs_File_Seek.
enum {
    FILE_SEEK_START = 0,
    FILE_SEEK_CURRENT = 1,
    FS_SEEK_END = 2,
};
u32 Fs_File_Seek(FSFile *file, s32 offset, u32 origin);
s32 Fs_File_Read(FSFile *file, void *dst, s32 len);
s32 Fs_File_ReadAsync(FSFile *file, void *dst, s32 len);
void File_If1Set2AndUnk20(FSFile *file);
u32 Fs_File_WaitAsync(FSFile *file);
u32 Fs_File_Close(FSFile *file);
u32 Fs_File_Open(FSFile *file, const u8 *path);
u32 Fs_File_OpenById(FSFile *file, FSFileID fileID);
u32 Fs_File_OpenRaw(FSFile *file, FSArchive *archive, u32 imageTop, u32 imageBottom, u32 fileIndex);
u32 Fs_FileId_LoadFromPath(FSFileID *fileID, const u8 *path);
s32 Fs_File_DoRead(FSFile *file, void *dst, s32 len, u32 async);
u32 Fs_File_FindPath(FSFile *dir, const u8 *path, void *fileID, void *dirPos);

// First FSArchive of the list Fs_RegisterArchive builds through mNext/mPrev (Fs_FindArchiveByMountName searches it).
extern FSArchive *g_ArchiveList;
// Set by Fs_RegisterArchive, Fs_UnregisterArchive and Fs_Chdir; read by Fs_File_FindPath.
extern FileLocation g_CurrentDirectoryPosition;
