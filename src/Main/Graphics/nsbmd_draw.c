#include "Main/Graphics/nsbmd_draw.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "model_draw_state.h"
#include "ITCM/model_draw_and_irq_handler.h"

void (*const gNsbmdDrawFunctions[2])(void *object) = {(void (*)(void *)) DrawRenderObjWrapper,
                                                              (void (*)(void *)) DrawNsbmd1Mat1Shp};

void DrawNsbmd1Mat1Shp(Nsbmd *nsbmd) {
    NNS_G3dDraw1Mat1Shp(nsbmd->mResMdl, 0, 0, 1);
}

void DrawRenderObjWrapper(NNSG3dRenderObj *object) {
    NNS_G3dDraw(object);
}
