#include "code_020182c0.h"
#include "fs_file.h"
#include "code_02003be0.h"
#include "code_02139f70.h"

u32 ArchiveHeaderMatches(Unk02018344 *header) {
    if (header->mUnk_00 != 0x4352414e) {
        return 0;
    }
    if (header->mUnk_04 != 0xfffe) {
        return 0;
    }
    return header->mUnk_06 == 0x100 ? 1 : 0;
}

u32 ArchiveLoadFromMemory(Unk020182c0 *archive, const u8 *name, Unk02018344 *header) {
    u8 *fntBlock;
    u8 *fatBlock;
    u8 *imageBlock;
    s32 blockIndex;
    u8 *block;
    s32 blockCount;

    fntBlock = 0;
    fatBlock = 0;
    imageBlock = 0;
    if (ArchiveHeaderMatches(header) == 0) {
        return 0;
    }
    block = (u8 *) header + header->mUnk_0c;
    blockCount = header->mUnk_0e;
    for (blockIndex = 0; blockIndex < blockCount; blockIndex++) {
        switch (*(u32 *) block) {
            case 0x46415442:
                fntBlock = block;
                break;
            case 0x464e5442:
                fatBlock = block;
                break;
            case 0x46494d47:
                imageBlock = block;
                break;
        }
        block += *OFFSET_PTR(u32, block, 4);
    }
    FS_InitArchive(&archive->mUnk_00);
    archive->mUnk_5c = header;
    archive->mUnk_60 = fntBlock;
    imageBlock = (u8 *) imageBlock + 8;
    archive->mUnk_64 = imageBlock;
    if (FS_RegisterArchiveName(&archive->mUnk_00, name, strlen((const char *) name)) == 0) {
        return 0;
    }
    if (FS_LoadArchive(&archive->mUnk_00, imageBlock, fntBlock + 0xc - imageBlock, *(u32 *) (fntBlock + 4) - 0xc,
                       fatBlock + 8 - imageBlock, *(u32 *) (fatBlock + 4) - 8, 0, 0) != 0) {
        return 1;
    }
    FS_ReleaseArchiveName(&archive->mUnk_00);
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
        address = ((Unk020182c0 *) file.mArc)->mUnk_64 + file.mProp.w.mUnk_04;
        FS_CloseFile(&file);
    }
    return address;
}
