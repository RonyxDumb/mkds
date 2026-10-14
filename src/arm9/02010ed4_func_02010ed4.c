/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MTX_Inverse43 func_0214755c
#define NNS_G3dGlb SDK_data_0217029c
#define NNS_G3dGlbGetInvV func_02010ed4
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
extern NNSG3dGlb NNS_G3dGlb;
#pragma thumb off
const MtxFx43 * NNS_G3dGlbGetInvV (void)
{
    if (!(NNS_G3dGlb.flag & NNS_G3D_GLB_FLAG_INVCAMERA_UPTODATE)) {
        s32 result = MTX_Inverse43(&NNS_G3dGlb.cameraMtx, &NNS_G3dGlb.invCameraMtx);
        NNS_G3D_ASSERT(!result);
        NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_INVCAMERA_UPTODATE;
    }
    return &NNS_G3dGlb.invCameraMtx;
}
