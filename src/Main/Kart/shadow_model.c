#include "Main/Kart/shadow_model.h"
#include "Main/MapObjects/data_02155000.h"

void DrawShadowModel(ShadowModel *shadowModel, u32 unusedParam1, u32 unusedParam2) {
    SetNsbmdFirstDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
    SetNsbmdSecondDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha, shadowModel->mPolygonId);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
}
