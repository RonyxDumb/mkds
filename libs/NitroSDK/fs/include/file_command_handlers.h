#pragma once

#include "types.h"
#include "thread_mutex_types.h"

typedef struct FSFile FSFile;
typedef struct FSArchive FSArchive;

typedef s32 (*FS_ARCHIVE_READ_FUNC)(FSArchive *archive, void *dst, u32 src, u32 len);
typedef s32 (*FS_ARCHIVE_WRITE_FUNC)(FSArchive *archive, const void *src, u32 dst, u32 len);
typedef s32 (*FS_ARCHIVE_PROC_FUNC)(FSFile *file, u32 command);

struct FSDirEntry;

// An archive and a file number in it, as stored by Fs_GetOverlayFileId and Fs_File_DefaultOperation_FindPath and read by
// Fs_File_OpenById.
typedef struct FSFileID {
    /* 00 */ FSArchive *mArc;
    /* 04 */ u32 mFileId;
} FSFileID;

// 12 bytes at 0x20 and at 0x30 of FSFile (assigned as a whole by Fs_File_DefaultOperation_SeekDirectory, Fs_File_FindPath and
// Fs_Chdir; g_CurrentDirectoryPosition). Different functions use the region with different types: an FSArchive pointer
// (Fs_File_DoSeekDirectory, Fs_File_DefaultOperation_ReadDirectory, Fs_File_FindPath), an FSDirEntry pointer (Fs_File_DefaultOperation_FindPath,
// Fs_File_DefaultOperation_GetPath), three words (Fs_File_DefaultOperation_OpenFileById, Fs_File_OpenRaw), an FSFileID (Fs_File_DefaultOperation_FindPath,
// Fs_File_OpenById), a u8 pointer with two lengths (Fs_File_DefaultOperation_GetPath) and a pointer with two signed words
// (Fs_File_Seek, Fs_File_DoRead, Fs_File_DefaultOperation_ReadFile).
typedef union FileLocation {
    struct {
        /* 00 */ u32 mUnk_00;
        /* 04 */ u32 mUnk_04;
        /* 08 */ u32 mUnk_08;
    } w;
    struct {
        /* 00 */ FSFileID mId;
        /* 08 */ u32 mUnk_08;
    } d;
    struct {
        /* 00 */ FSArchive *mArc;
        /* 04 */ u16 mOwnId;
        /* 06 */ u16 mIndex;
        /* 08 */ u32 mPos;
    } h;
    struct {
        /* 00 */ struct FSDirEntry *mEntry;
        /* 04 */ u32 mSkipString;
        /* 08 */ u32 mUnk_08;
    } e;
    struct {
        /* 00 */ u8 *mBuf;
        /* 04 */ u32 mBufLen;
        /* 08 */ u16 mTotalLen;
        /* 0a */ u16 mDirId;
    } b;
    struct {
        /* 00 */ void *mUnk_00;
        /* 04 */ s32 mUnk_04;
        /* 08 */ s32 mUnk_08;
    } p;
} FileLocation;

typedef struct FSFileLink {
    /* 00 */ FSFile *mPrev;
    /* 04 */ FSFile *mNext;
} FSFileLink;

// Command indexes: FSFile.mCommand and the second argument of Fs_File_DoExecuteOperation, which picks the archive handler.
typedef enum ArchiveCommand {
    ARCHIVE_COMMAND_MOVE_DIR_CURSOR = 2,
    ARCHIVE_COMMAND_LIST_DIR_ENTRY = 3,
    ARCHIVE_COMMAND_OPEN_BY_NUMBER = 7,
    // Sent to FSArchive.mProc, not to a file: the archive starts running its queue, and has run it empty.
    ARCHIVE_COMMAND_START_RUN = 9,
    ARCHIVE_COMMAND_STOP_RUN = 10,
    ARCHIVE_COMMAND_UNSET = 14
} ArchiveCommand;

// Bits of FSArchive.mProcFlag: the commands the archive handles itself (bit n is command n).
enum {
    ARCHIVE_PROC_START_RUN = 1 << ARCHIVE_COMMAND_START_RUN,
    ARCHIVE_PROC_STOP_RUN = 1 << ARCHIVE_COMMAND_STOP_RUN,
};

// Commands 2 to 8 are always waited for by the caller (Fs_File_SendOperation sets FILE_STAT_SYNC for them).
#define ARCHIVE_SYNC_COMMANDS_MASK 0x1fc

// Results of the archive handlers and of the commands. FSFile.mError holds the final ones.
enum {
    ARCHIVE_RESULT_SUCCESS = 0,
    ARCHIVE_RESULT_FAILED = 1,
    ARCHIVE_RESULT_PENDING = 2,
    ARCHIVE_RESULT_CANCELED = 3,
    ARCHIVE_RESULT_UNSUPPORTED = 4,
    ARCHIVE_RESULT_RUNNING_IN_BACKGROUND = 6,
    ARCHIVE_RESULT_USE_DEFAULT = 7,
    ARCHIVE_RESULT_NOT_HANDLED = 8,
};

// Bits of FSFile.mStat.
enum {
    FILE_STAT_BUSY = 0x1,
    FILE_STAT_CANCEL = 0x2,
    FILE_STAT_SYNC = 0x4,
    FILE_STAT_ASYNC = 0x8,
    FILE_STAT_IS_FILE = 0x10,
    FILE_STAT_IS_DIRECTORY = 0x20,
    FILE_STAT_STARTED = 0x40,
    FILE_STAT_COMMAND_MASK = FILE_STAT_BUSY | FILE_STAT_CANCEL | FILE_STAT_SYNC | FILE_STAT_ASYNC | FILE_STAT_STARTED,
};

// Bits of FSArchive.mFlag.
enum {
    ARCHIVE_FLAG_LOADED = 0x2,
    ARCHIVE_FLAG_TABLES_IN_MEMORY = 0x4,
    ARCHIVE_FLAG_SUSPENDED = 0x8,
    ARCHIVE_FLAG_RUNNING = 0x10,
    ARCHIVE_FLAG_CANCEL_PENDING = 0x20,
    ARCHIVE_FLAG_SUSPEND_REQUESTED = 0x40,
    ARCHIVE_FLAG_UNLOADING = 0x80,
    ARCHIVE_FLAG_ASYNC_COMMAND = 0x100,
    ARCHIVE_FLAG_SYNC_COMMAND = 0x200,
};

// Archive names hold up to three characters in FSArchive.mName; these are the largest values of one and of two.
#define ARCHIVE_NAME_SINGLE_CHAR_MAX 0xff
#define ARCHIVE_NAME_DOUBLE_CHAR_MAX 0xff00

// Mask of the directory number in the parent field of a directory table entry.
#define FILE_DIR_NUMBER_MASK 0xfff

// FSFile.mStat bits: a command on the file is running, the record holds an open file.
#define FILE_RECORD_BUSY 0x1
#define FILE_RECORD_OPEN 0x10

// A file system file: its link, archive, status, command, error, thread queue and file location.
typedef struct FSFile {
    // Fs_File_ReleaseOperation links mLink.mPrev and mLink.mNext to each other, then clears both.
    /* 00 */ FSFileLink mLink;
    /* 08 */ FSArchive *mArc;
    /* 0c */ volatile u32 mStat; // bit 2 selects the path in Fs_File_DoExecuteOperation; Fs_File_ReleaseOperation clears 0x4f
    /* 10 */ u32 mCommand; // index passed to Fs_File_DoExecuteOperation by Fs_File_ExecuteSyncOperation and Fs_File_ExecuteAsyncOperation
    /* 14 */ s32 mError; // set from a return value in Fs_File_DoExecuteOperation and Fs_File_ReleaseOperation
    /* 18 */ OSThreadQueue mQueue;
    /* 20 */ FileLocation mProp;
    union {
        /* 2c */ u32 mPosition;
        /* 2c */ u32 mParentId;
    };
    /* 30 */ FileLocation mArg;
    /* 3c */ const u8 *mPath;
    /* 40 */ u32 mFindDirectory;
    /* 44 */ FileLocation *mResult;
} FSFile;

// A file system archive: its name, links to other archives, flags, file list, thread queues and its access functions.
typedef struct FSArchive {
    /* 00 */ u32 mName;
    /* 04 */ FSArchive *mNext;
    /* 08 */ FSArchive *mPrev;
    /* 0c */ OSThreadQueue mSyncQ;
    /* 14 */ OSThreadQueue mStatQ;
    /* 1c */ volatile u32 mFlag;
    /* 20 */ FSFileLink mList;
    /* 28 */ u8 *mBase;
    /* 2c */ u32 mFat;
    /* 30 */ u32 mFatSize;
    /* 34 */ u32 mFnt;
    /* 38 */ u32 mFntSize;
    /* 3c */ u32 mFatBak;
    /* 40 */ u32 mFntBak;
    /* 44 */ u32 mLoadMem;
    /* 48 */ FS_ARCHIVE_READ_FUNC mRead;
    /* 4c */ FS_ARCHIVE_WRITE_FUNC mWrite;
    /* 50 */ FS_ARCHIVE_READ_FUNC mTable;
    /* 54 */ FS_ARCHIVE_PROC_FUNC mProc;
    /* 58 */ u32 mProcFlag;
} FSArchive;

// Called by Fs_File_DoExecuteOperation with its second argument as the index.
extern s32 (*fsi_default_command[])(FSFile *file);

s32 Fs_File_DoExecuteOperation(FSFile *file, u32 command);
void Fs_File_ReleaseOperation(FSFile *file, s32 result);
s32 Fs_File_DefaultOperation_OpenFileRaw(FSFile *file);
s32 Fs_File_DefaultOperation_CloseFile(FSFile *file);

// Two words Fs_File_DefaultOperation_OpenFileById reads into FSFile.mArg.
typedef struct FSArchiveFAT {
    /* 00 */ u32 mTop;
    /* 04 */ u32 mBottom;
} FSArchiveFAT;

// Fs_SyncReader_Read passes mPos to FSArchive.mTable of mArc and adds the count to it.
typedef struct FSiSyncReadParam {
    /* 00 */ FSArchive *mArc;
    /* 04 */ u32 mPos;
} FSiSyncReadParam;

// Eight bytes read by Fs_File_DefaultOperation_SeekDirectory.
typedef struct FSArchiveFNT {
    /* 00 */ u32 mStart;
    /* 04 */ u16 mIndex;
    /* 06 */ u16 mParent;
} FSArchiveFNT;

// Entry read by Fs_File_DefaultOperation_FindPath, Fs_File_DefaultOperation_ReadDirectory and Fs_File_DefaultOperation_GetPath: a FileLocation, then a flag, a length
// and the bytes.
typedef struct FSDirEntry {
    /* 00 */ FileLocation mId;
    /* 0c */ u32 mIsDirectory;
    /* 10 */ u32 mNameLength;
    /* 14 */ u8 mName[0x80];
} FSDirEntry;

s32 Fs_File_DefaultOperation_OpenFileById(FSFile *file);
s32 Fs_File_DefaultOperation_GetPath(FSFile *file);
s32 Fs_File_DefaultOperation_FindPath(FSFile *dir);
s32 Fs_File_DefaultOperation_ReadDirectory(FSFile *dir);
s32 Fs_File_DefaultOperation_SeekDirectory(FSFile *dir);
s32 Fs_File_DefaultOperation_WriteFile(FSFile *file);
s32 Fs_File_DefaultOperation_ReadFile(FSFile *file);
s32 Fs_File_DoSeekDirectory(FSFile *dir, u32 id);
void Fs_SyncReader_Read(FSiSyncReadParam *param, void *dst, u32 len);
s32 Fs_Strcasecmp(const u8 *str1, const u8 *str2, u32 len);
