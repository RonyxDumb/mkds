#pragma once

#include "types.h"
#include "file_command_handlers.h" // FSArchive

// Record whose first fields ArcEntry_ValidateNarcHeader checks; mUnk_0c is the offset of the first of mUnk_0e blocks that
// MountMountEntryFrom walks, each starting with a word and its own size.
typedef struct NNSiFndArchiveHeader {
    /* 00 */ u32 mSignature;
    /* 04 */ u16 mByteOrder;
    /* 06 */ u16 mVersion;
    /* 08 */ u8 mFileSize[4];
    /* 0c */ u16 mHeaderSize;
    /* 0e */ u16 mDataBlocks;
} NNSiFndArchiveHeader;

// Values of NNSiFndArchiveHeader.mSignature, mByteOrder and mVersion that ArcEntry_ValidateNarcHeader accepts, and the kind
// words of the three blocks (the ASCII tags "NARC", "BTAF", "BTNF" and "GMIF" as words).
#define ARCHIVE_SIGNATURE 0x4352414e
#define ARCHIVE_BYTE_ORDER 0xfffe
#define ARCHIVE_VERSION 0x100
#define ARCHIVE_BLOCK_FAT 0x46415442
#define ARCHIVE_BLOCK_FNT 0x464e5442
#define ARCHIVE_BLOCK_IMAGE 0x46494d47

// Bytes at the start of each block of the archive: its kind word and its size.
#define ARCHIVE_BLOCK_HEADER_SIZE 8

// FSArchive followed by the three words MountMountEntryFrom sets.
typedef struct NNSFndArchive {
    /* 00 */ FSArchive mFsArchive;
    /* 5c */ NNSiFndArchiveHeader *mArcBinary;
    /* 60 */ u8 *mFatData;
    /* 64 */ u8 *mFileImage;
} NNSFndArchive;

void *GetFileBuffer(const u8 *path);
u32 Fs_Archive_Dispose(FSArchive *archive);
u32 MountMountEntryFrom(NNSFndArchive *archive, const u8 *name, NNSiFndArchiveHeader *header);
u32 ArcEntry_ValidateNarcHeader(NNSiFndArchiveHeader *header);
