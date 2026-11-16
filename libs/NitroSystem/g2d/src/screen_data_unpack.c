#include "screen_data_unpack.h"

NNSG2dBinaryBlockHeader *Common_FindBlockByMagic(NNSG2dBinaryFileHeader *file, u32 tag) {
    u16 blockIndex;
    u16 count;
    NNSG2dBinaryBlockHeader *part;

    part = OFFSET_PTR(NNSG2dBinaryBlockHeader, file, file->mHeaderSize);
    count = file->mDataBlocks;
    for (blockIndex = 0; blockIndex < count; blockIndex++) {
        if (part->mKind == tag) {
            return part;
        }
        part = OFFSET_PTR(NNSG2dBinaryBlockHeader, part, part->mSize);
    }
    return 0;
}

u32 Screen_ReadBlock(NNSG2dBinaryFileHeader *pNscrFile, NNSG2dBinaryBlockHeader **ppScrData) {
    NNSG2dBinaryBlockHeader *part;

    part = Common_FindBlockByMagic(pNscrFile, 0x5343524e);
    if (part != 0) {
        *ppScrData = part + 1;
        return 1;
    }
    *ppScrData = 0;
    return 0;
}
