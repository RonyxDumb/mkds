#include "Main/MapObjects/chandelier_draw.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "ITCM/g3d_draw_and_irq_handler.h"
#include "Main/MapObjects/chandelier.h"

void DrawChandelier(void *mapObjectList, Chandelier *chandelier) {
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
