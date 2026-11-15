#include "archive_memory_load.h"
#include "file_handle_setup.h"
#include "file_open_read.h"
#include "narrow_string_functions.h"

u32 ArchiveHeaderMatches(NNSiFndArchiveHeader *header) {
    if (header->mSignature != ARCHIVE_SIGNATURE) {
        return 0;
    }
    if (header->mByteOrder != ARCHIVE_BYTE_ORDER) {
        return 0;
    }
    return header->mVersion == ARCHIVE_VERSION ? 1 : 0;
}

u32 ArchiveLoadFromMemory(NNSFndArchive *archive, const u8 *name, NNSiFndArchiveHeader *header) {
    u8 *fatBlock;
    u8 *fntBlock;
    u8 *imageBlock;
    s32 blockIndex;
    u8 *block;
    s32 blockCount;

    fatBlock = 0;
    fntBlock = 0;
    imageBlock = 0;
    if (ArchiveHeaderMatches(header) == 0) {
        return 0;
    }
    block = (u8 *) header + header->mHeaderSize;
    blockCount = header->mDataBlocks;
    for (blockIndex = 0; blockIndex < blockCount; blockIndex++) {
        switch (*(u32 *) block) {
            case ARCHIVE_BLOCK_FAT:
                fatBlock = block;
                break;
            case ARCHIVE_BLOCK_FNT:
                fntBlock = block;
                break;
            case ARCHIVE_BLOCK_IMAGE:
                imageBlock = block;
                break;
        }
        block += *OFFSET_PTR(u32, block, 4);
    }
    FS_InitArchive(&archive->mFsArchive);
    archive->mArcBinary = header;
    archive->mFatData = fatBlock;
    imageBlock = (u8 *) imageBlock + ARCHIVE_BLOCK_HEADER_SIZE;
    archive->mFileImage = imageBlock;
    if (FS_RegisterArchiveName(&archive->mFsArchive, name, strlen((const char *) name)) == 0) {
        return 0;
    }
    if (FS_LoadArchive(&archive->mFsArchive, imageBlock, fatBlock + 0xc - imageBlock, *(u32 *) (fatBlock + 4) - 0xc,
                       fntBlock + ARCHIVE_BLOCK_HEADER_SIZE - imageBlock,
                       *(u32 *) (fntBlock + 4) - ARCHIVE_BLOCK_HEADER_SIZE, 0, 0) != 0) {
        return 1;
    }
    FS_ReleaseArchiveName(&archive->mFsArchive);
    return 0;
}

u32 ArchiveUnload(FSArchive *archive) {
    if (FS_UnloadArchive(archive) == 0) {
        return 0;
    }
    FS_ReleaseArchiveName(archive);
    return 1;
}

void *ArchiveFileGetAddress(const u8 *path) {
    FSFile file;
    void *address;

    address = NULL;
    FS_InitFile(&file);
    if (FS_OpenFile(&file, path) != 0) {
        address = ((NNSFndArchive *) file.mArc)->mFileImage + file.mProp.w.mUnk_04;
        FS_CloseFile(&file);
    }
    return address;
}
