#include "Main/Kart/shadow_model.h"
#include "Main/Kart/kart_palette_stem_tables.h"
#include "Main/Graphics/nsbmd_draw.h"

const Vec3 gKartModelMenuReferenceAxis = {0x1000, 0, 0};
const Vec4 gQuaternionIdentity = {0, 0, 0, 0x1000};

void DrawShadowModel(ShadowModel *shadowModel, u32 unusedParam1, u32 unusedParam2) {
    SetNsbmdFirstDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
    SetNsbmdSecondDrawMaterial(&shadowModel->mNsbmd, shadowModel->mAlpha, shadowModel->mPolygonId);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
}
