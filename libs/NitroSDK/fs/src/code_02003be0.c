#include "code_02003be0.h"

#include "code_02003024.h"
#include "fs_file.h"
#include "os_thread.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

FSArchive *arc_list;
FileLocation current_dir_pos;

// Resolves a path, with an optional "name:" archive prefix, against the current directory and sends the command.
u32 FSi_FindPath(FSFile *dir, const u8 *path, void *fileID, void *dirPos) {
    FileLocation pos;
    s32 charIndex;
    FSArchive *archive;
    s32 loaded;

    if (path[0] == '/' || path[0] == '\\') {
        pos.h.mArc = current_dir_pos.h.mArc;
        pos.h.mOwnId = 0;
        pos.h.mPos = 0;
        pos.h.mIndex = 0;
        path++;
    } else {
        pos = current_dir_pos;
        for (charIndex = 0; charIndex <= 3; charIndex++) {
            if (path[charIndex] == 0 || path[charIndex] == '/' || path[charIndex] == '\\') {
                break;
            }
            if (path[charIndex] == ':') {
                archive = FS_FindArchive(path, charIndex);
                if (archive == 0) {
                    return 0;
                }
                if (archive->mFlag & ARCHIVE_FLAG_LOADED) {
                    loaded = 1;
                } else {
                    loaded = 0;
                }
                if (loaded == 0) {
                    return 0;
                }
                pos.h.mArc = archive;
                pos.h.mPos = 0;
                pos.h.mIndex = 0;
                pos.h.mOwnId = 0;
                path += charIndex + 1;
                if (*path == '/' || *path == '\\') {
                    path++;
                }
                break;
            }
        }
    }
    dir->mArc = pos.h.mArc;
    dir->mPath = path;
    dir->mArg = pos;
    if (dirPos != 0) {
        dir->mFindDirectory = 1;
        dir->mResult = dirPos;
    } else {
        dir->mFindDirectory = 0;
        dir->mResult = fileID;
    }
    return FSi_SendCommand(dir, 4);
}

// Reads up to len bytes from the file position; waits for the result unless async is set.
s32 FSi_ReadFileCore(FSFile *file, void *dst, s32 len, u32 async) {
    s32 start;
    s32 requested;

    start = file->mPosition;
    requested = len;
    if (len > file->mProp.p.mUnk_08 - start) {
        len = file->mProp.p.mUnk_08 - start;
    }
    if (len < 0) {
        len = 0;
    }
    file->mArg.p.mUnk_00 = dst;
    file->mArg.p.mUnk_04 = requested;
    file->mArg.p.mUnk_08 = len;
    if (async == 0) {
        file->mStat |= FILE_STAT_SYNC;
    }
    FSi_SendCommand(file, 0);
    if (async == 0) {
        if (FS_WaitAsync(file) != 0) {
            len = file->mPosition - start;
        } else {
            len = -1;
        }
    }
    return len;
}

// Looks up a path and stores the archive and file index.
u32 FS_ConvertPathToFileID(FSFileID *fileID, const u8 *path) {
    FSFile file;

    FS_InitFile(&file);
    return FSi_FindPath(&file, path, fileID, 0) != 0;
}

// Opens a file from an archive by byte range and file index.
u32 FS_OpenFileDirect(FSFile *file, FSArchive *archive, u32 imageTop, u32 imageBottom, u32 fileIndex) {
    file->mArc = archive;
    file->mArg.w.mUnk_08 = fileIndex;
    file->mArg.w.mUnk_00 = imageTop;
    file->mArg.w.mUnk_04 = imageBottom;
    if (FSi_SendCommand(file, 7) == 0) {
        return 0;
    }
    file->mStat |= FILE_STAT_IS_FILE;
    file->mStat &= ~FILE_STAT_IS_DIRECTORY;
    return 1;
}

// Opens a file from the archive and index found by FS_ConvertPathToFileID.
u32 FS_OpenFileFast(FSFile *file, FSFileID fileID) {
    if (fileID.mArc == 0) {
        return 0;
    }
    file->mArc = fileID.mArc;
    file->mArg.d.mId = fileID;
    if (FSi_SendCommand(file, 6) == 0) {
        return 0;
    }
    file->mStat |= FILE_STAT_IS_FILE;
    file->mStat &= ~FILE_STAT_IS_DIRECTORY;
    return 1;
}

// Opens a file by path.
u32 FS_OpenFile(FSFile *file, const u8 *path) {
    FSFileID fileID;

    if (FS_ConvertPathToFileID(&fileID, path) != 0) {
        if (FS_OpenFileFast(file, fileID) != 0) {
            return 1;
        }
    }
    return 0;
}

// Closes an open file.
u32 FS_CloseFile(FSFile *file) {
    if (FSi_SendCommand(file, 8) == 0) {
        return 0;
    }
    file->mArc = 0;
    file->mCommand = ARCHIVE_COMMAND_UNSET;
    file->mStat &= ~(FILE_STAT_IS_FILE | FILE_STAT_IS_DIRECTORY);
    return 1;
}

// Waits until the file has no command pending; runs the command itself if it has not started.
u32 FS_WaitAsync(FSFile *file) {
    u32 needsRun;
    u32 enabled;

    needsRun = 0;
    enabled = OS_DisableInterrupts();
    if (((file->mStat & FILE_STAT_BUSY) ? 1 : 0) != 0) {
        needsRun = (file->mStat & (FILE_STAT_SYNC | FILE_STAT_STARTED)) == 0;
        if (needsRun) {
            file->mStat |= FILE_STAT_SYNC;
            do {
                OS_SleepThread(&file->mQueue);
            } while ((file->mStat & FILE_STAT_STARTED) == 0);
        } else {
            do {
                OS_SleepThread(&file->mQueue);
            } while (((file->mStat & FILE_STAT_BUSY) ? 1 : 0) != 0);
        }
    }
    OS_RestoreInterrupts(enabled);
    if (needsRun) {
        return FSi_ExecuteSyncCommand(file);
    }
    return file->mError == 0;
}

// Marks a pending command as cancelled.
void FS_CancelFile(FSFile *file) {
    u32 enabled;

    enabled = OS_DisableInterrupts();
    if (((file->mStat & FILE_STAT_BUSY) ? 1 : 0) != 0) {
        file->mStat |= FILE_STAT_CANCEL;
        file->mArc->mFlag |= ARCHIVE_FLAG_CANCEL_PENDING;
    }
    OS_RestoreInterrupts(enabled);
}

// Starts a read without waiting for it.
s32 FS_ReadFileAsync(FSFile *file, void *dst, s32 len) {
    return FSi_ReadFileCore(file, dst, len, 1);
}

// Reads and waits; returns the byte count or -1.
s32 FS_ReadFile(FSFile *file, void *dst, s32 len) {
    return FSi_ReadFileCore(file, dst, len, 0);
}

// Moves the file position, clamped to the file range; origin 0 is start, 1 current, 2 end.
u32 FS_SeekFile(FSFile *file, s32 offset, u32 origin) {
    switch (origin) {
        case FILE_SEEK_START:
            offset += file->mProp.p.mUnk_04;
            break;
        case FILE_SEEK_CURRENT:
            offset += file->mPosition;
            break;
        case FS_SEEK_END:
            offset += file->mProp.p.mUnk_08;
            break;
        default:
            return 0;
    }
    if (offset < file->mProp.p.mUnk_04) {
        offset = file->mProp.p.mUnk_04;
    }
    if (offset > file->mProp.p.mUnk_08) {
        offset = file->mProp.p.mUnk_08;
    }
    file->mPosition = offset;
    return 1;
}

// Sets the current directory.
u32 FS_ChangeDir(const u8 *path) {
    FileLocation dirPos;
    FSFile searchFile;

    FS_InitFile(&searchFile);
    if (FSi_FindPath(&searchFile, path, 0, &dirPos) == 0) {
        return 0;
    }
    current_dir_pos = dirPos;
    return 1;
}

// Packs up to three characters of an archive name into a word, upper case folded to lower.
u32 FSi_GetPackedName(const u8 *name, s32 nameLen) {
    u32 packed;
    u32 diff;
    int charIndex;

    packed = 0;
    if (nameLen <= 3) {
        for (charIndex = 0; charIndex < nameLen; charIndex++) {
            if (name[charIndex] == 0) {
                break;
            }
            diff = name[charIndex] - 0x41;
            packed |= ((diff <= 0x19) ? diff + 0x61 : diff + 0x41) << (charIndex * 8);
        }
    }
    return packed;
}

// Archive read callback that copies from the archive memory image.
s32 FSi_ReadMemCallback(FSArchive *archive, void *dst, u32 pos, u32 size) {
    MI_CpuCopy8(archive->mBase + pos, dst, size);
    return 0;
}

// Archive write callback that copies into the archive memory image.
s32 FSi_WriteMemCallback(FSArchive *archive, const void *src, u32 pos, u32 size) {
    MI_CpuCopy8(src, archive->mBase + pos, size);
    return 0;
}

// Table read callback that copies from an address.
s32 FSi_ReadMemoryCore(FSArchive *archive, void *dst, u32 pos, u32 size) {
    MI_CpuCopy8((const void *) pos, dst, size);
    return 0;
}

// Cancels flagged commands and returns the next command the archive should run, if it is not suspended.
FSFile *FSi_NextCommand(FSArchive *archive) {
    FSFile procFile;
    FSFile *file;
    FSFile *next;
    u32 enabled;
    u32 first;

    enabled = OS_DisableInterrupts();
    if (archive->mFlag & ARCHIVE_FLAG_CANCEL_PENDING) {
        archive->mFlag &= ~ARCHIVE_FLAG_CANCEL_PENDING;
        file = archive->mList.mNext;
        if (file != 0) {
            do {
                next = file->mLink.mNext;
                if (((file->mStat & FILE_STAT_CANCEL) ? 1 : 0) != 0) {
                    if (archive->mList.mNext == file) {
                        archive->mList.mNext = next;
                    }
                    FSi_ReleaseCommand(file, 3);
                    if (next == 0) {
                        next = archive->mList.mNext;
                    }
                }
                file = next;
            } while (next != 0);
        }
    }
    if (!(archive->mFlag & ARCHIVE_FLAG_SUSPEND_REQUESTED) &&
        ((archive->mFlag & ARCHIVE_FLAG_SUSPENDED) ? 1 : 0) == 0 && (file = archive->mList.mNext) != 0) {
        first = ((archive->mFlag & ARCHIVE_FLAG_RUNNING) ? 1 : 0) == 0;
        if (first != 0) {
            archive->mFlag |= ARCHIVE_FLAG_RUNNING;
        }
        OS_RestoreInterrupts(enabled);
        if (first != 0 && (archive->mProcFlag & ARCHIVE_PROC_START_RUN)) {
            archive->mProc(file, ARCHIVE_COMMAND_START_RUN);
        }
        enabled = OS_DisableInterrupts();
        file->mStat |= FILE_STAT_STARTED;
        if (((file->mStat & FILE_STAT_SYNC) ? 1 : 0) != 0) {
            OS_WakeupThread(&file->mQueue);
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        OS_RestoreInterrupts(enabled);
        return file;
    }
    if (archive->mFlag & ARCHIVE_FLAG_RUNNING) {
        archive->mFlag &= ~ARCHIVE_FLAG_RUNNING;
        if (archive->mProcFlag & ARCHIVE_PROC_STOP_RUN) {
            FS_InitFile(&procFile);
            procFile.mArc = archive;
            archive->mProc(&procFile, ARCHIVE_COMMAND_STOP_RUN);
        }
    }
    if (archive->mFlag & ARCHIVE_FLAG_SUSPEND_REQUESTED) {
        archive->mFlag &= ~ARCHIVE_FLAG_SUSPEND_REQUESTED;
        archive->mFlag |= ARCHIVE_FLAG_SUSPENDED;
        OS_WakeupThread(&archive->mStatQ);
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}

// Runs the given command and then the following queued ones until one is left pending.
void FSi_ExecuteAsyncCommand(FSFile *file) {
    FSArchive *archive;
    u32 enabled;

    archive = file->mArc;
    if (file == 0) {
        return;
    }
    do {
        enabled = OS_DisableInterrupts();
        file->mStat |= FILE_STAT_STARTED;
        if (((file->mStat & FILE_STAT_SYNC) ? 1 : 0) != 0) {
            OS_WakeupThread(&file->mQueue);
            OS_RestoreInterrupts(enabled);
            return;
        }
        file->mStat |= FILE_STAT_ASYNC;
        OS_RestoreInterrupts(enabled);
        if (FSi_TranslateCommand(file, file->mCommand) == 6) {
            return;
        }
        file = FSi_NextCommand(archive);
    } while (file != 0);
}

// Runs one command to completion, then starts the queue.
u32 FSi_ExecuteSyncCommand(FSFile *file) {
    FSFile *next;

    FSi_ReleaseCommand(file, FSi_TranslateCommand(file, file->mCommand));
    next = FSi_NextCommand(file->mArc);
    if (next != 0) {
        FSi_ExecuteAsyncCommand(next);
    }
    return file->mError == 0;
}

// Queues a command on its archive and runs it or waits for it.
u32 FSi_SendCommand(FSFile *file, u32 command) {
    FSArchive *archive;
    FSFile *tail;
    FSFile *prev;
    u32 mask;
    FSFile *next;
    u32 enabled;

    archive = file->mArc;
    file->mCommand = command;
    mask = 1 << command;
    file->mError = ARCHIVE_RESULT_PENDING;
    file->mStat |= FILE_STAT_BUSY;
    enabled = OS_DisableInterrupts();
    if (archive->mFlag & ARCHIVE_FLAG_UNLOADING) {
        FSi_ReleaseCommand(file, 3);
        OS_RestoreInterrupts(enabled);
        return 0;
    }
    if (mask & ARCHIVE_SYNC_COMMANDS_MASK) {
        file->mStat |= FILE_STAT_SYNC;
    }
    prev = file->mLink.mPrev;
    tail = (FSFile *) &archive->mList;
    next = file->mLink.mNext;
    if (prev != 0) {
        prev->mLink.mNext = next;
    }
    if (next != 0) {
        next->mLink.mPrev = prev;
    }
    while (tail->mLink.mNext != 0) {
        tail = tail->mLink.mNext;
    }
    tail->mLink.mNext = file;
    file->mLink.mPrev = tail;
    file->mLink.mNext = 0;
    if (((archive->mFlag & ARCHIVE_FLAG_SUSPENDED) ? 1 : 0) == 0 && (archive->mFlag & ARCHIVE_FLAG_RUNNING) == 0) {
        archive->mFlag |= ARCHIVE_FLAG_RUNNING;
        OS_RestoreInterrupts(enabled);
        if (archive->mProcFlag & ARCHIVE_PROC_START_RUN) {
            archive->mProc(file, ARCHIVE_COMMAND_START_RUN);
        }
        enabled = OS_DisableInterrupts();
        file->mStat |= FILE_STAT_STARTED;
        if (((file->mStat & FILE_STAT_SYNC) ? 1 : 0) == 0) {
            OS_RestoreInterrupts(enabled);
            FSi_ExecuteAsyncCommand(file);
            return 1;
        }
        OS_RestoreInterrupts(enabled);
    } else {
        if (((file->mStat & FILE_STAT_SYNC) ? 1 : 0) == 0) {
            OS_RestoreInterrupts(enabled);
            return 1;
        }
        do {
            OS_SleepThread(&file->mQueue);
        } while ((file->mStat & FILE_STAT_STARTED) == 0);
        OS_RestoreInterrupts(enabled);
    }
    return FSi_ExecuteSyncCommand(file);
}

// Clears an archive and its thread queues.
void FS_InitArchive(FSArchive *archive) {
    MI_CpuFill8(archive, 0, sizeof(FSArchive));
    archive->mSyncQ.mTail = 0;
    archive->mSyncQ.mHead = archive->mSyncQ.mTail;
    archive->mStatQ.mTail = 0;
    archive->mStatQ.mHead = archive->mStatQ.mTail;
}

// Finds a registered archive by name.
FSArchive *FS_FindArchive(const u8 *name, s32 nameLen) {
    u32 packed;
    u32 enabled;
    FSArchive *archive;

    packed = FSi_GetPackedName(name, nameLen);
    enabled = OS_DisableInterrupts();
    archive = arc_list;
    while (archive != 0 && archive->mName != packed) {
        archive = archive->mNext;
    }
    OS_RestoreInterrupts(enabled);
    return archive;
}

// Adds an archive to the list under the given name.
u32 FS_RegisterArchiveName(FSArchive *archive, const u8 *name, s32 nameLen) {
    u32 result;
    u32 enabled;
    FSArchive *tail;

    result = 0;
    enabled = OS_DisableInterrupts();
    if (FS_FindArchive(name, nameLen) == 0) {
        if (arc_list == 0) {
            arc_list = archive;
            current_dir_pos.h.mArc = archive;
            current_dir_pos.h.mPos = 0;
            current_dir_pos.h.mIndex = 0;
            current_dir_pos.h.mOwnId = 0;
        } else {
            tail = arc_list;
            while (tail->mNext != 0) {
                tail = tail->mNext;
            }
            tail->mNext = archive;
            archive->mPrev = tail;
        }
        archive->mName = FSi_GetPackedName(name, nameLen);
        result = 1;
        archive->mFlag |= 1;
    }
    OS_RestoreInterrupts(enabled);
    return result;
}

// Removes an archive from the list.
void FS_ReleaseArchiveName(FSArchive *archive) {
    u32 enabled;

    if (archive->mName == 0) {
        return;
    }
    enabled = OS_DisableInterrupts();
    if (archive->mNext != 0) {
        archive->mNext->mPrev = archive->mPrev;
    }
    if (archive->mPrev != 0) {
        archive->mPrev->mNext = archive->mNext;
    }
    archive->mName = 0;
    archive->mPrev = 0;
    archive->mNext = archive->mPrev;
    archive->mFlag &= ~1;
    if (current_dir_pos.h.mArc == archive) {
        current_dir_pos.h.mPos = 0;
        current_dir_pos.h.mIndex = 0;
        current_dir_pos.h.mArc = arc_list;
        current_dir_pos.h.mOwnId = 0;
    }
    OS_RestoreInterrupts(enabled);
}

// Sets the archive memory image, table offsets and read and write callbacks.
u32 FS_LoadArchive(FSArchive *archive, u8 *base, u32 fat, u32 fatSize, u32 fnt, u32 fntSize,
                   FS_ARCHIVE_READ_FUNC readFunc, FS_ARCHIVE_WRITE_FUNC writeFunc) {
    archive->mBase = base;
    archive->mFatSize = fatSize;
    archive->mFatBak = fat;
    archive->mFat = archive->mFatBak;
    archive->mFntSize = fntSize;
    archive->mFntBak = fnt;
    archive->mFnt = archive->mFntBak;
    archive->mRead = (readFunc == 0) ? FSi_ReadMemCallback : readFunc;
    archive->mWrite = (writeFunc == 0) ? FSi_WriteMemCallback : writeFunc;
    archive->mTable = archive->mRead;
    archive->mLoadMem = 0;
    archive->mFlag |= ARCHIVE_FLAG_LOADED;
    return 1;
}

// Cancels the queued commands and clears the archive.
u32 FS_UnloadArchive(FSArchive *archive) {
    u32 enabled;
    FSFile *file;
    FSFile *next;
    u32 suspended;

    enabled = OS_DisableInterrupts();
    if (((archive->mFlag & ARCHIVE_FLAG_LOADED) ? 1 : 0) != 0) {
        archive->mFlag;
        suspended = FS_SuspendArchive(archive);
        archive->mFlag |= ARCHIVE_FLAG_UNLOADING;
        file = archive->mList.mNext;
        if (file != 0) {
            do {
                next = file->mLink.mNext;
                FSi_ReleaseCommand(file, 3);
                file = next;
            } while (next != 0);
        }
        archive->mList.mNext = 0;
        if (suspended != 0) {
            FS_ResumeArchive(archive);
        }
        archive->mBase = 0;
        archive->mFat = 0;
        archive->mFatSize = 0;
        archive->mFnt = 0;
        archive->mFntSize = 0;
        archive->mFntBak = 0;
        archive->mFatBak = archive->mFntBak;
        archive->mFlag &= ~0xa2;
    }
    OS_RestoreInterrupts(enabled);
    return 1;
}

// Copies the two tables into memory; returns the size needed.
u32 FS_LoadArchiveTables(FSArchive *archive, u32 mem, u32 maxSize) {
    FSFile tableFile;
    u32 totalSize;

    totalSize = ((s32) (archive->mFatSize + archive->mFntSize + 32) + 31) & ~31;
    if (totalSize <= maxSize) {
        u8 *cache;

        cache = (u8 *) ((mem + 31) & ~31);
        FS_InitFile(&tableFile);
        if (FS_OpenFileDirect(&tableFile, archive, archive->mFat, archive->mFat + archive->mFatSize, -1) != 0) {
            if (FS_ReadFile(&tableFile, cache, archive->mFatSize) < 0) {
                MI_CpuFill8(cache, 0, archive->mFatSize);
            }
            FS_CloseFile(&tableFile);
        }
        archive->mFat = (u32) cache;
        cache += archive->mFatSize;
        if (FS_OpenFileDirect(&tableFile, archive, archive->mFnt, archive->mFnt + archive->mFntSize, -1) != 0) {
            if (FS_ReadFile(&tableFile, cache, archive->mFntSize) < 0) {
                MI_CpuFill8(cache, 0, archive->mFntSize);
            }
            FS_CloseFile(&tableFile);
        }
        archive->mFnt = (u32) cache;
        archive->mLoadMem = mem;
        archive->mTable = FSi_ReadMemoryCore;
        archive->mFlag |= ARCHIVE_FLAG_TABLES_IN_MEMORY;
    }
    return totalSize;
}

// Returns the archive to reading its tables from the image; returns the table memory.
u32 FS_UnloadArchiveTables(FSArchive *archive) {
    u32 mem;
    u32 suspended;

    mem = 0;
    if (((archive->mFlag & ARCHIVE_FLAG_LOADED) ? 1 : 0) != 0) {
        suspended = FS_SuspendArchive(archive);
        if (((archive->mFlag & ARCHIVE_FLAG_TABLES_IN_MEMORY) ? 1 : 0) != 0) {
            archive->mFlag &= ~ARCHIVE_FLAG_TABLES_IN_MEMORY;
            mem = archive->mLoadMem;
            archive->mLoadMem = 0;
            archive->mFat = archive->mFatBak;
            archive->mFnt = archive->mFntBak;
            archive->mTable = archive->mRead;
        }
        if (suspended != 0) {
            FS_ResumeArchive(archive);
        }
    }
    return mem;
}

// Stops the archive from starting commands; returns whether it was not already suspended.
u32 FS_SuspendArchive(FSArchive *archive) {
    u32 enabled;
    u32 result;

    enabled = OS_DisableInterrupts();
    result = ((archive->mFlag & ARCHIVE_FLAG_SUSPENDED) ? 1 : 0) == 0;
    if (result) {
        if (archive->mFlag & ARCHIVE_FLAG_RUNNING) {
            archive->mFlag |= ARCHIVE_FLAG_SUSPEND_REQUESTED;
            do {
                OS_SleepThread(&archive->mStatQ);
            } while (archive->mFlag & ARCHIVE_FLAG_SUSPEND_REQUESTED);
        } else {
            archive->mFlag |= ARCHIVE_FLAG_SUSPENDED;
        }
    }
    OS_RestoreInterrupts(enabled);
    return result;
}

// Lets a suspended archive start commands again.
u32 FS_ResumeArchive(FSArchive *archive) {
    FSFile *next;
    u32 enabled;
    u32 result;

    next = 0;
    enabled = OS_DisableInterrupts();
    result = ((archive->mFlag & ARCHIVE_FLAG_SUSPENDED) ? 1 : 0) == 0;
    if (!result) {
        archive->mFlag &= ~ARCHIVE_FLAG_SUSPENDED;
        next = FSi_NextCommand(archive);
    }
    OS_RestoreInterrupts(enabled);
    if (next != 0) {
        FSi_ExecuteAsyncCommand(next);
    }
    return result;
}

// Sets the archive notification callback and the events it receives.
void FS_SetArchiveProc(FSArchive *archive, FS_ARCHIVE_PROC_FUNC proc, u32 flags) {
    if (flags == 0) {
        proc = 0;
    } else if (proc == 0) {
        flags = 0;
    }
    archive->mProc = proc;
    archive->mProcFlag = flags;
}

// Ends an asynchronous command with the given result.
void FS_NotifyArchiveAsyncEnd(FSArchive *archive, u32 result) {
    u32 enabled;
    FSFile *file;

    if (archive->mFlag & ARCHIVE_FLAG_ASYNC_COMMAND) {
        file = archive->mList.mNext;
        archive->mFlag &= ~ARCHIVE_FLAG_ASYNC_COMMAND;
        FSi_ReleaseCommand(file, result);
        file = FSi_NextCommand(archive);
        if (file != 0) {
            FSi_ExecuteAsyncCommand(file);
        }
    } else {
        file = archive->mList.mNext;
        enabled = OS_DisableInterrupts();
        file->mError = result;
        archive->mFlag &= ~ARCHIVE_FLAG_SYNC_COMMAND;
        OS_WakeupThread(&archive->mSyncQ);
        OS_RestoreInterrupts(enabled);
    }
}
