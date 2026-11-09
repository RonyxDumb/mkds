#include "Main/Unknown/code_0207adf8.h"

void DrawShadowModel(ShadowModel *shadowModel, u32 b, u32 c) {
    SetNsbmdFirstDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
    SetNsbmdSecondDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha, shadowModel->mPolygonId);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
}
