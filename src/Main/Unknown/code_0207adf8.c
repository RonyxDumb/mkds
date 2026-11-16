#include "Main/Unknown/code_0207adf8.h"

void DrawShadowModel(ShadowModel *shadowModel, u32 b, u32 c) {
    model_configShadowPass1(shadowModel, shadowModel->mAlpha);
    gModelRenderFuncs[shadowModel->mNsbmd.mDrawKind](shadowModel);
    model_configShadowPass2(shadowModel, shadowModel->mAlpha, shadowModel->mPolygonId);
    gModelRenderFuncs[shadowModel->mNsbmd.mDrawKind](shadowModel);
}
