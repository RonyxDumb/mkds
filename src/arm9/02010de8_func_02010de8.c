/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define calcSrtCameraMtx_ func_02010e70
#define NNS_G3dGlb SDK_data_0217029c
#define NNS_G3dGlbGetInvWV func_02010de8
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
extern void calcSrtCameraMtx_ (void);
extern NNSG3dGlb NNS_G3dGlb;
#pragma thumb off
const MtxFx43 * NNS_G3dGlbGetInvWV (void)
{
    if (!(NNS_G3dGlb.flag & NNS_G3D_GLB_FLAG_SRTCAMERA_UPTODATE)) {
        calcSrtCameraMtx_();
        NNS_G3dGlb.flag |= NNS_G3D_GLB_FLAG_SRTCAMERA_UPTODATE;
    }

    return &NNS_G3dGlb.invSrtCameraMtx;
}
