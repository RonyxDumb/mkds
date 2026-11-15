#include "model_set_resource_lookup.h"

u32 gSbcBillboardPackedOps[1] = {0x1b171012};
u32 gSbcBillboardOpArgs[2] = {1, 2};
u32 gSbcBillboardMatrix[9] = {0x1000, 0, 0, 0, 0x1000, 0, 0, 0, 0x1000};

NNSG3dResMdlSet *NNS_G3dGetMdlSet(const NNSG3dResFileHeader *header) {
    u32 *blockOffsets;

    blockOffsets = OFFSET_PTR(u32, header, header->mHeaderSize);
    return OFFSET_PTR(NNSG3dResMdlSet, header, blockOffsets[0]);
}
