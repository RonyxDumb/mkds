#include "g2d_NSC_load.h"

NNSG2dBinaryBlockHeader *FindPartByTag(NNSG2dBinaryFileHeader *file, u32 tag) {
    u16 i;
    u16 count;
    NNSG2dBinaryBlockHeader *part;

    part = OFFSET_PTR(NNSG2dBinaryBlockHeader, file, file->mHeaderSize);
    count = file->mDataBlocks;
    for (i = 0; i < count; i++) {
        if (part->mKind == tag) {
            return part;
        }
        part = OFFSET_PTR(NNSG2dBinaryBlockHeader, part, part->mSize);
    }
    return 0;
}

u32 NNS_G2dGetUnpackedScreenData(NNSG2dBinaryFileHeader *pNscrFile, NNSG2dBinaryBlockHeader **ppScrData) {
    NNSG2dBinaryBlockHeader *part;

    part = FindPartByTag(pNscrFile, 0x5343524e);
    if (part != 0) {
        *ppScrData = part + 1;
        return 1;
    }
    *ppScrData = 0;
    return 0;
}
