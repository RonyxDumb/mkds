/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGlb SDK_data_0217029c
#define NNS_G3dGlbLightVector func_02010fac
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
extern NNSG3dGlb NNS_G3dGlb;
#pragma thumb off
void NNS_G3dGlbLightVector (GXLightId lightID, fx16 x, fx16 y, fx16 z)
{
    GX_LIGHTID_ASSERT(lightID);

    NNS_G3D_ASSERT(x >= -FX16_ONE && x < FX16_ONE);
    NNS_G3D_ASSERT(y >= -FX16_ONE && y < FX16_ONE);
    NNS_G3D_ASSERT(z >= -FX16_ONE && z < FX16_ONE);

    NNS_G3dGlb.lightVec[lightID] = GX_PACK_LIGHTVECTOR_PARAM(lightID, x, y, z);
}
