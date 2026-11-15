#include "code_02003024.h"

#include "fs_file.h"
#include "os_thread.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

// Compares two names for len characters, ignoring case; returns the difference of the first pair that differs.
s32 FSi_StrNICmp(const u8 *str1, const u8 *str2, u32 len) {
    u32 charIndex;
    u32 firstChar;
    u32 secondChar;

    for (charIndex = 0; charIndex < len; charIndex++) {
        firstChar = str1[charIndex] - 0x41;
        secondChar = str2[charIndex] - 0x41;
        if (firstChar <= 0x19) {
            firstChar += 0x20;
        }
        if (secondChar <= 0x19) {
            secondChar += 0x20;
        }
        if (firstChar != secondChar) {
            return firstChar - secondChar;
        }
    }
    return 0;
}

// Reads len bytes of the archive tables through FSArchive.mTable, waiting if it runs in the background; advances
// the position.
void FSi_ReadTable(FSiSyncReadParam *param, void *dst, u32 len) {
    FSArchive *archive;
    s32 result;
    u32 enabled;

    archive = param->mArc;
    archive->mFlag |= 0x200;
    result = archive->mTable(archive, dst, param->mPos, len);
    switch (result) {
        case 0:
        case 1:
            archive->mFlag &= ~0x200;
            break;
        case 6:
            enabled = OS_DisableInterrupts();
            if (archive->mFlag & 0x200) {
                do {
                    OS_SleepThread(&archive->mSyncQ);
                } while (archive->mFlag & 0x200);
            }
            OS_RestoreInterrupts(enabled);
            break;
    }
    param->mPos += len;
}

// Moves a directory file to the directory with the given number.
s32 FSi_SeekDirDirect(FSFile *dir, u32 id) {
    dir->mStat |= 4;
    dir->mArg.h.mArc = dir->mArc;
    dir->mArg.w.mUnk_08 = 0;
    dir->mArg.h.mIndex = 0;
    dir->mArg.h.mOwnId = id;
    return FSi_TranslateCommand(dir, ARCHIVE_COMMAND_MOVE_DIR_CURSOR);
}

// File read command: advances FSFile position and calls FSArchive.mRead.
s32 FSi_ReadFileCommand(FSFile *file) {
    FSArchive *archive;
    void *dst;
    u32 pos;
    u32 len;

    pos = file->mPosition;
    len = file->mArg.p.mUnk_08;
    archive = file->mArc;
    dst = file->mArg.p.mUnk_00;
    file->mPosition = pos + len;
    return archive->mRead(archive, dst, pos, len);
}

// File write command: advances FSFile position and calls FSArchive.mWrite.
s32 FSi_WriteFileCommand(FSFile *file) {
    FSArchive *archive;
    void *src;
    u32 pos;
    u32 len;

    pos = file->mPosition;
    len = file->mArg.p.mUnk_08;
    archive = file->mArc;
    src = file->mArg.p.mUnk_00;
    file->mPosition = pos + len;
    return archive->mWrite(archive, src, pos, len);
}

// Directory seek command: reads the directory table entry for the directory in FSFile.mArg.
s32 FSi_SeekDirCommand(FSFile *dir) {
    FSArchive *archive;
    FileLocation *arg;
    FSArchiveFNT tableEntry;
    FSiSyncReadParam readParam;

    archive = dir->mArc;
    arg = &dir->mArg;
    readParam.mArc = archive;
    readParam.mPos = archive->mFnt + arg->h.mOwnId * 8;
    FSi_ReadTable(&readParam, &tableEntry, 8);
    dir->mProp = *arg;
    if (arg->h.mIndex == 0 && arg->h.mPos == 0) {
        dir->mProp.h.mIndex = tableEntry.mIndex;
        dir->mProp.h.mPos = archive->mFnt + tableEntry.mStart;
    }
    dir->mParentId = tableEntry.mParent & 0xfff;
    return 0;
}

// Directory read command: reads the next entry of the directory into the FSDirEntry in FSFile.mArg.
s32 FSi_ReadDirCommand(FSFile *dir) {
    FSDirEntry *entry;
    u8 header;
    u16 parent;
    FSiSyncReadParam readParam;

    entry = dir->mArg.e.mEntry;
    readParam.mArc = dir->mArc;
    readParam.mPos = dir->mProp.w.mUnk_08;
    FSi_ReadTable(&readParam, &header, 1);
    entry->mNameLength = header & 0x7f;
    entry->mIsDirectory = (header >> 7) & 1;
    if (entry->mNameLength == 0) {
        return 1;
    }
    if (dir->mArg.e.mSkipString != 0) {
        readParam.mPos += entry->mNameLength;
    } else {
        FSi_ReadTable(&readParam, entry->mName, entry->mNameLength);
        entry->mName[entry->mNameLength] = 0;
    }
    if (entry->mIsDirectory != 0) {
        FSi_ReadTable(&readParam, &parent, 2);
        entry->mId.h.mArc = dir->mArc;
        entry->mId.h.mOwnId = parent & 0xfff;
        entry->mId.h.mIndex = 0;
        entry->mId.w.mUnk_08 = 0;
    } else {
        entry->mId.h.mArc = dir->mArc;
        entry->mId.w.mUnk_04 = dir->mProp.h.mIndex;
        dir->mProp.h.mIndex++;
    }
    dir->mProp.w.mUnk_08 = readParam.mPos;
    return 0;
}

static inline int IsPathNameChar(u32 character) {
    int result;

    result = 0;
    if (character != 0 && character != 0x2f && character != 0x5c) {
        result = 1;
    }
    return result;
}

// Path search command: walks the path through the directory entries and stores the file or directory found.
s32 FSi_FindPathCommand(FSFile *dir) {
    u32 wantsDir;
    FSDirEntry entry;
    const u8 *path;
    u32 isDirName;
    s32 nameLen;
    u32 ch;
    FileLocation *result;

    wantsDir = dir->mFindDirectory;
    path = dir->mPath;
    FSi_TranslateCommand(dir, ARCHIVE_COMMAND_MOVE_DIR_CURSOR);
    ch = *path;
    if (ch != 0) {
        do {
            for (nameLen = 0; isDirName = path[nameLen], IsPathNameChar(isDirName); nameLen++) {
            }
            if (isDirName != 0 || wantsDir != 0) {
                isDirName = 1;
            }
            if (nameLen == 0) {
                return 1;
            }
            if (ch == 0x2e) {
                if (nameLen == 1) {
                    path += 1;
                    goto next;
                }
                if ((nameLen == 2) & (path[1] == 0x2e)) {
                    if (dir->mProp.h.mOwnId != 0) {
                        FSi_SeekDirDirect(dir, dir->mParentId);
                    }
                    path += 2;
                    goto next;
                }
            }
            if (nameLen > 0x7f) {
                return 1;
            }
            dir->mArg.e.mEntry = &entry;
            dir->mArg.e.mSkipString = 0;
            do {
                if (FSi_TranslateCommand(dir, ARCHIVE_COMMAND_LIST_DIR_ENTRY) != 0) {
                    return 1;
                }
            } while (isDirName != entry.mIsDirectory || nameLen != entry.mNameLength ||
                     FSi_StrNICmp(path, entry.mName, nameLen) != 0);
            if (isDirName != 0) {
                dir->mArg = entry.mId;
                path += nameLen;
                FSi_TranslateCommand(dir, ARCHIVE_COMMAND_MOVE_DIR_CURSOR);
            } else {
                if (wantsDir != 0) {
                    return 1;
                }
                result = dir->mResult;
                result->d.mId = entry.mId.d.mId;
                return 0;
            }
        next:
            path += (*path != 0) ? 1 : 0;
            ch = *path;
        } while (ch != 0);
    }
    if (wantsDir == 0) {
        return 1;
    }
    *dir->mResult = dir->mProp;
    return 0;
}

// Path query command: sizes and writes the full path of a file or directory, starting with the archive name.
s32 FSi_GetPathCommand(FSFile *file) {
    FSArchive *archive;
    FSDirEntry entry;
    FSFile searchFile;
    FileLocation *arg;
    u32 dirId;
    u32 fileId;
    u32 dirIndex;
    u32 dirCount;
    u32 parent;
    u32 totalLen;
    u8 *buf;
    u32 len;
    u32 off;
    u32 byteCount;

    archive = file->mArc;
    arg = &file->mArg;
    FS_InitFile(&searchFile);
    searchFile.mArc = file->mArc;
    if (((file->mStat & 0x20) ? 1 : 0) != 0) {
        dirId = file->mProp.h.mOwnId;
        fileId = 0x10000;
    } else {
        fileId = file->mProp.w.mUnk_00;
        if (arg->b.mTotalLen != 0) {
            dirId = arg->b.mDirId;
        } else {
            dirIndex = 0;
            dirCount = 0;
            dirId = 0x10000;
            do {
                FSi_SeekDirDirect(&searchFile, dirIndex);
                if (dirIndex == 0) {
                    dirCount = searchFile.mParentId;
                }
                searchFile.mArg.e.mEntry = &entry;
                searchFile.mArg.e.mSkipString = 1;
                if (FSi_TranslateCommand(&searchFile, ARCHIVE_COMMAND_LIST_DIR_ENTRY) == 0) {
                    do {
                        if (entry.mIsDirectory == 0 && entry.mId.w.mUnk_04 == fileId) {
                            dirId = searchFile.mProp.h.mOwnId;
                            break;
                        }
                    } while (FSi_TranslateCommand(&searchFile, ARCHIVE_COMMAND_LIST_DIR_ENTRY) == 0);
                }
                if (dirId != 0x10000) {
                    break;
                }
                dirIndex++;
            } while (dirIndex < dirCount);
        }
    }
    if (dirId == 0x10000) {
        arg->b.mTotalLen = 0;
        return 1;
    }
    if (arg->b.mTotalLen == 0) {
        totalLen = 0;
        if (archive->mName <= 0xff) {
            totalLen += 1;
        } else if (archive->mName <= 0xff00) {
            totalLen += 2;
        } else {
            totalLen += 3;
        }
        totalLen += 2;
        if (fileId != 0x10000) {
            totalLen += entry.mNameLength;
        }
        parent = dirId;
        if (parent != 0) {
            FSi_SeekDirDirect(&searchFile, parent);
            do {
                FSi_SeekDirDirect(&searchFile, searchFile.mParentId);
                searchFile.mArg.e.mEntry = &entry;
                searchFile.mArg.e.mSkipString = 1;
                if (FSi_TranslateCommand(&searchFile, ARCHIVE_COMMAND_LIST_DIR_ENTRY) == 0) {
                    do {
                        if (entry.mIsDirectory != 0 && entry.mId.h.mOwnId == parent) {
                            totalLen += entry.mNameLength + 1;
                            break;
                        }
                    } while (FSi_TranslateCommand(&searchFile, ARCHIVE_COMMAND_LIST_DIR_ENTRY) == 0);
                }
                parent = searchFile.mProp.h.mOwnId;
            } while (parent != 0);
        }
        arg->b.mTotalLen = totalLen + 1;
        arg->b.mDirId = dirId;
    }
    buf = arg->b.mBuf;
    if (buf == 0) {
        return 0;
    }
    len = arg->b.mTotalLen;
    if (arg->b.mBufLen < len) {
        return 1;
    }
    off = 0;
    if (archive->mName <= 0xff) {
        byteCount = 1;
    } else if (archive->mName <= 0xff00) {
        byteCount = 2;
    } else {
        byteCount = 3;
    }
    MI_CpuCopy8(archive, buf, byteCount);
    off += byteCount;
    MI_CpuCopy8(":/", buf + off, 2);
    FSi_SeekDirDirect(&searchFile, dirId);
    if (fileId != 0x10000) {
        searchFile.mArg.e.mEntry = &entry;
        searchFile.mArg.e.mSkipString = 0;
        if (FSi_TranslateCommand(&searchFile, ARCHIVE_COMMAND_LIST_DIR_ENTRY) == 0) {
            do {
                if (entry.mIsDirectory == 0 && entry.mId.w.mUnk_04 == fileId) {
                    break;
                }
            } while (FSi_TranslateCommand(&searchFile, ARCHIVE_COMMAND_LIST_DIR_ENTRY) == 0);
        }
        byteCount = entry.mNameLength + 1;
        MI_CpuCopy8(entry.mName, buf + len - byteCount, byteCount);
        len -= byteCount;
    } else {
        *(buf + len - 1) = 0;
        len--;
    }
    if (dirId != 0) {
        do {
            FSi_SeekDirDirect(&searchFile, searchFile.mParentId);
            searchFile.mArg.e.mEntry = &entry;
            searchFile.mArg.e.mSkipString = 0;
            *(buf + len - 1) = 0x2f;
            len--;
            if (FSi_TranslateCommand(&searchFile, ARCHIVE_COMMAND_LIST_DIR_ENTRY) == 0) {
                do {
                    if (entry.mIsDirectory != 0 && entry.mId.h.mOwnId == dirId) {
                        byteCount = entry.mNameLength;
                        MI_CpuCopy8(entry.mName, buf + len - byteCount, byteCount);
                        len -= byteCount;
                        break;
                    }
                } while (FSi_TranslateCommand(&searchFile, ARCHIVE_COMMAND_LIST_DIR_ENTRY) == 0);
            }
            dirId = searchFile.mProp.h.mOwnId;
        } while (dirId != 0);
    }
    return 0;
}

// Open command by file number: reads the file range from the file table and opens it.
s32 FSi_OpenFileFastCommand(FSFile *file) {
    FSArchive *archive;
    u32 index;
    u32 offset;
    FSArchiveFAT range;
    FSiSyncReadParam readParam;

    archive = file->mArc;
    index = file->mArg.w.mUnk_04;
    offset = index << 3;
    if (offset >= archive->mFatSize) {
        return 1;
    }
    readParam.mArc = archive;
    readParam.mPos = archive->mFat + offset;
    FSi_ReadTable(&readParam, &range, 8);
    file->mArg.w.mUnk_00 = range.mTop;
    file->mArg.w.mUnk_04 = range.mBottom;
    file->mArg.w.mUnk_08 = index;
    return FSi_TranslateCommand(file, ARCHIVE_COMMAND_OPEN_BY_NUMBER);
}

// Open command by byte range: sets the file range and position.
s32 FSi_OpenFileDirectCommand(FSFile *file) {
    file->mProp.w.mUnk_04 = file->mArg.w.mUnk_00;
    file->mPosition = file->mArg.w.mUnk_00;
    file->mProp.w.mUnk_08 = file->mArg.w.mUnk_04;
    file->mProp.w.mUnk_00 = file->mArg.w.mUnk_08;
    return 0;
}

// Close command: nothing to do.
s32 FSi_CloseFileCommand(FSFile *file) {
    return 0;
}

// Unlinks a finished command from its archive list, stores the result and wakes the waiting threads.
void FSi_ReleaseCommand(FSFile *file, s32 result) {
    u32 enabled;
    FSFile *prev;
    FSFile *next;

    enabled = OS_DisableInterrupts();
    prev = file->mLink.mPrev;
    next = file->mLink.mNext;
    if (prev != 0) {
        prev->mLink.mNext = next;
    }
    if (next != 0) {
        next->mLink.mPrev = prev;
    }
    file->mLink.mPrev = 0;
    file->mLink.mNext = file->mLink.mPrev;
    file->mStat &= ~0x4f;
    file->mError = result;
    OS_WakeupThread(&file->mQueue);
    OS_RestoreInterrupts(enabled);
}

// Runs a command through FSArchive.mProc when it handles it, else through the default command table.
s32 FSi_TranslateCommand(FSFile *file, u32 command) {
    s32 result;
    FSArchive *archive;
    u32 mask;
    u32 enabled;

    archive = file->mArc;
    mask = 1 << command;
    if (((file->mStat & 4) ? 1 : 0) != 0) {
        archive->mFlag |= 0x200;
    } else {
        archive->mFlag |= 0x100;
    }
    if (archive->mProcFlag & mask) {
        result = archive->mProc(file, command);
        switch (result) {
            case 0:
            case 1:
            case 4:
                file->mError = result;
                break;
            case 8:
                archive->mProcFlag = archive->mProcFlag & ~mask;
                result = 7;
                break;
        }
    } else {
        result = 7;
    }
    if (result == 7) {
        result = fsi_default_command[command](file);
    }
    if (result == 6) {
        if (((file->mStat & 4) ? 1 : 0) != 0) {
            enabled = OS_DisableInterrupts();
            if (archive->mFlag & 0x200) {
                do {
                    OS_SleepThread(&archive->mSyncQ);
                } while (archive->mFlag & 0x200);
            }
            result = file->mError;
            OS_RestoreInterrupts(enabled);
        }
    } else if (((file->mStat & 4) ? 1 : 0) != 0) {
        archive->mFlag &= ~0x200;
        file->mError = result;
    } else {
        archive->mFlag &= ~0x100;
        FSi_ReleaseCommand(file, result);
    }
    return result;
}
