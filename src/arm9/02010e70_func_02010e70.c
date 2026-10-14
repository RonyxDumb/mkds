/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MTX_ScaleApply43 func_02147914
#define MTX_Inverse43 func_0214755c
#define NNS_G3dGlb SDK_data_0217029c
#define calcSrtCameraMtx_ func_02010e70
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
extern NNSG3dGlb NNS_G3dGlb;
#pragma thumb off
void calcSrtCameraMtx_ (void)
{
    s32 result;

    MTX_Concat43((MtxFx43 *)&NNS_G3dGlb.prmBaseRot,
                 &NNS_G3dGlb.cameraMtx,
                 &NNS_G3dGlb.srtCameraMtx);
    MTX_ScaleApply43(&NNS_G3dGlb.srtCameraMtx,
                     &NNS_G3dGlb.srtCameraMtx,
                     NNS_G3dGlb.prmBaseScale.x,
                     NNS_G3dGlb.prmBaseScale.y,
                     NNS_G3dGlb.prmBaseScale.z);
    result = MTX_Inverse43(&NNS_G3dGlb.srtCameraMtx,
                           &NNS_G3dGlb.invSrtCameraMtx);
    NNS_G3D_ASSERT(!result);
}
