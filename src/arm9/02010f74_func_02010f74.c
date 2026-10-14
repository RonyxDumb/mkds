/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGlb SDK_data_0217029c
#define NNS_G3dGlbMaterialColorDiffAmb func_02010f74
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
extern NNSG3dGlb NNS_G3dGlb;
#pragma thumb off
void NNS_G3dGlbMaterialColorDiffAmb (GXRgb diffuse, GXRgb ambient, BOOL IsSetVtxColor)
{
    GXRGB_ASSERT(diffuse);
    GXRGB_ASSERT(ambient);

    NNS_G3dGlb.prmMatColor0 = GX_PACK_DIFFAMB_PARAM(diffuse, ambient, IsSetVtxColor);
}
