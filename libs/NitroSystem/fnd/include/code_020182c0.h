#pragma once

#include "types.h"
#include "code_02003024.h" // FSArchive

// Record whose first fields ArchiveHeaderMatches checks; mUnk_0c is the offset of the first of mUnk_0e blocks that
// ArchiveLoadFromMemory walks, each starting with a word and its own size.
typedef struct NNSiFndArchiveHeader {
    /* 00 */ u32 mSignature;
    /* 04 */ u16 mByteOrder;
    /* 06 */ u16 mVersion;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u16 mHeaderSize;
    /* 0e */ u16 mDataBlocks;
} NNSiFndArchiveHeader;

// FSArchive followed by the three words ArchiveLoadFromMemory sets.
typedef struct NNSFndArchive {
    /* 00 */ FSArchive mFsArchive;
    /* 5c */ NNSiFndArchiveHeader *mArcBinary;
    /* 60 */ u8 *mFatData;
    /* 64 */ u8 *mFileImage;
} NNSFndArchive;

void *ArchiveFileGetAddress(const u8 *path);
u32 ArchiveUnload(FSArchive *archive);
u32 ArchiveLoadFromMemory(NNSFndArchive *archive, const u8 *name, NNSiFndArchiveHeader *header);
u32 ArchiveHeaderMatches(NNSiFndArchiveHeader *header);
