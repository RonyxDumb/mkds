#include "graphic_resource_unpack.h"

void Gfx_MakePaletteOffsetsAbsolute(NNSG2dPaletteData *pPlttData) {
    pPlttData->mRawData = OFFSET_PTR(void, pPlttData->mRawData, (u32) pPlttData);
}

void Gfx_MakeCharGraphicsOffsetsAbsolute(NNSG2dCharacterData *pCharData) {
    pCharData->mRawData = OFFSET_PTR(void, pCharData->mRawData, (u32) pCharData);
}

void Gfx_MakeCharGraphicsOffsetsAbsoluteV2(NNSG2dCharacterData *pCharData) {
    pCharData->mRawData = OFFSET_PTR(void, pCharData->mRawData, (u32) pCharData);
}
