#pragma once

#include "types.h"
#include "thread_mutex_types.h"

typedef struct FSFile FSFile;
typedef struct FSArchive FSArchive;

typedef s32 (*FS_ARCHIVE_READ_FUNC)(FSArchive *archive, void *dst, u32 src, u32 len);
typedef s32 (*FS_ARCHIVE_WRITE_FUNC)(FSArchive *archive, const void *src, u32 dst, u32 len);
typedef s32 (*FS_ARCHIVE_PROC_FUNC)(FSFile *file, u32 command);

struct FSDirEntry;

// An archive and a file number in it, as stored by FS_GetOverlayFileID and FSi_FindPathCommand and read by
// FS_OpenFileFast.
typedef struct FSFileID {
    /* 00 */ FSArchive *mArc;
    /* 04 */ u32 mFileId;
} FSFileID;

// A 12-byte area that FSFile.mProp, FSFile.mArg and the lookups through FSFile.mResult read in a different layout for
// each command: h directory position, d file id, e directory entry, b path buffer, w three words, p pointer and two
// sizes or positions.
typedef union FileCommandData {
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
} FileCommandData;

typedef struct FSFileLink {
    /* 00 */ FSFile *mPrev;
    /* 04 */ FSFile *mNext;
} FSFileLink;

// Command indexes: FSFile.mCommand and the second argument of FSi_TranslateCommand, which picks the archive handler.
typedef enum ArchiveCommand {
    ARCHIVE_COMMAND_MOVE_DIR_CURSOR = 2,
    ARCHIVE_COMMAND_LIST_DIR_ENTRY = 3,
    ARCHIVE_COMMAND_OPEN_BY_RANGE = 7,
    // Sent to FSArchive.mProc: START_RUN with the first queued file when the archive was not running, STOP_RUN with an
    // empty file when it was running and its queue is empty or it is suspended or a suspend was requested.
    ARCHIVE_COMMAND_START_RUN = 9,
    ARCHIVE_COMMAND_STOP_RUN = 10,
    ARCHIVE_COMMAND_UNSET = 14
} ArchiveCommand;

// Bits of FSArchive.mProcFlag: the commands the archive handles itself (bit n is command n).
enum {
    ARCHIVE_PROC_START_RUN = 1 << ARCHIVE_COMMAND_START_RUN,
    ARCHIVE_PROC_STOP_RUN = 1 << ARCHIVE_COMMAND_STOP_RUN,
};

// Commands 2 to 8: FSi_SendCommand sets FILE_STAT_SYNC for them, so the caller runs them and waits for the result (not
// when the archive is unloading).
#define ARCHIVE_SYNC_COMMANDS_MASK 0x1fc

// Results of the archive handlers and of the commands. FSFile.mError holds PENDING while a command runs, then its
// result; FSi_TranslateCommand handles USE_DEFAULT, NOT_HANDLED and RUNNING_IN_BACKGROUND itself.
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

// FSArchive.mName packs up to three characters, the first in the low byte; the cutoffs FSi_GetPathCommand uses are the
// largest value it counts as one character and as two.
#define ARCHIVE_NAME_SINGLE_CHAR_MAX 0xff
#define ARCHIVE_NAME_DOUBLE_CHAR_MAX 0xff00

// Mask of the directory id in the parent field of a directory table entry (FSi_SeekDirCommand) and in the id that
// follows a directory name in a directory read (FSi_ReadDirCommand).
#define FILE_DIR_ID_MASK 0xfff

// A file system file or directory: its link, archive, status, command, error, thread queue, the locations mProp and
// mArg, the position or parent id, the path, a directory flag and the result pointer.
typedef struct FSFile {
    // The file's place in the command list of FSFile.mArc (FSArchive.mList): FSi_ReleaseCommand joins the previous and
    // the next file to each other, then clears both.
    /* 00 */ FSFileLink mLink;
    /* 08 */ FSArchive *mArc;
    // FILE_STAT_ bits; FILE_STAT_SYNC picks the path in FSi_TranslateCommand; FSi_ReleaseCommand clears
    // FILE_STAT_COMMAND_MASK.
    /* 0c */ volatile u32 mStat;
    // Command number that FSi_SendCommand stores and FSi_ExecuteSyncCommand and FSi_ExecuteAsyncCommand pass to
    // FSi_TranslateCommand.
    /* 10 */ u32 mCommand;
    // ARCHIVE_RESULT_ code; FSi_SendCommand sets PENDING, FSi_TranslateCommand and FSi_ReleaseCommand store the result.
    /* 14 */ s32 mError;
    /* 18 */ OSThreadQueue mQueue;
    /* 20 */ FileCommandData mProp;
    union {
        /* 2c */ u32 mPosition;
        /* 2c */ u32 mParentId;
    };
    /* 30 */ FileCommandData mArg;
    /* 3c */ const u8 *mPath;
    /* 40 */ u32 mFindDirectory;
    /* 44 */ FileCommandData *mResult;
} FSFile;

// A file system archive: its name, links to other archives, flags, file list, thread queues, base address, FAT and FNT
// offsets and sizes with their backups, load memory, access functions and mProcFlag.
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

// Default handlers that FSi_TranslateCommand calls, indexed by its second argument, when FSArchive.mProc does not
// handle the command.
extern s32 (*fsi_default_command[])(FSFile *file);

s32 FSi_TranslateCommand(FSFile *file, u32 command);
void FSi_ReleaseCommand(FSFile *file, s32 result);
s32 FSi_OpenFileDirectCommand(FSFile *file);
s32 FSi_CloseFileCommand(FSFile *file);

// One file table entry: the top and bottom of a file. FSi_OpenFileFastCommand reads it from FSArchive.mFat and copies
// it into FSFile.mArg.
typedef struct FSArchiveFAT {
    /* 00 */ u32 mTop;
    /* 04 */ u32 mBottom;
} FSArchiveFAT;

// FSi_ReadTable passes mPos to FSArchive.mTable of mArc and adds the count to it.
typedef struct FSiSyncReadParam {
    /* 00 */ FSArchive *mArc;
    /* 04 */ u32 mPos;
} FSiSyncReadParam;

// Eight bytes read by FSi_SeekDirCommand.
typedef struct FSArchiveFNT {
    /* 00 */ u32 mStart;
    /* 04 */ u16 mIndex;
    /* 06 */ u16 mParent;
} FSArchiveFNT;

// A directory entry: its mId, whether it is a directory (mIsDirectory) and its name (mNameLength, mName).
// FSi_ReadDirCommand fills it; FSi_FindPathCommand and FSi_GetPathCommand read it.
typedef struct FSDirEntry {
    /* 00 */ FileCommandData mId;
    /* 0c */ u32 mIsDirectory;
    /* 10 */ u32 mNameLength;
    /* 14 */ u8 mName[0x80];
} FSDirEntry;

s32 FSi_OpenFileFastCommand(FSFile *file);
s32 FSi_GetPathCommand(FSFile *file);
s32 FSi_FindPathCommand(FSFile *dir);
s32 FSi_ReadDirCommand(FSFile *dir);
s32 FSi_SeekDirCommand(FSFile *dir);
s32 FSi_WriteFileCommand(FSFile *file);
s32 FSi_ReadFileCommand(FSFile *file);
s32 FSi_SeekDirDirect(FSFile *dir, u32 id);
void FSi_ReadTable(FSiSyncReadParam *param, void *dst, u32 len);
s32 FSi_StrNICmp(const u8 *str1, const u8 *str2, u32 len);
