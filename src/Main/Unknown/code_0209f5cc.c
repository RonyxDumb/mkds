#include "Main/Unknown/code_0209f5cc.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff8000.h"

void DrawChandelier(void *mapObjectList, Unk0209f338 *chandelier) {
    MtxFx43 *viewMatrix;
    u32 commandArg;
    commandArg = 0x1e;
    NNS_G3dGeBufferOP_N(0x14, &commandArg, 1);
    viewMatrix = SetViewRotatedMatrixPos(&chandelier->mMapObject.mPos);
    NNS_G3dGeBufferOP_N(0x19, viewMatrix, 0xc);
    NNS_G3dGeBufferOP_N(0x1b, &chandelier->mMapObject.mScale, 3);
    SetMapObjectModelNsbcaFrameIndex(gChandelier, chandelier->mFrameIndex);
    DrawMapObjectModel(mapObjectList, gChandelier, chandelier);
}
