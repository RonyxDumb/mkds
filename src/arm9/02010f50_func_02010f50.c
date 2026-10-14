/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGlb SDK_data_0217029c
#define NNS_G3dGlbMaterialColorSpecEmi func_02010f50
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
extern NNSG3dGlb NNS_G3dGlb;
#pragma thumb off
void NNS_G3dGlbMaterialColorSpecEmi (GXRgb specular, GXRgb emission, BOOL IsShininess)
{
    GXRGB_ASSERT(specular);
    GXRGB_ASSERT(emission);

    NNS_G3dGlb.prmMatColor1 = GX_PACK_SPECEMI_PARAM(specular, emission, IsShininess);
}
