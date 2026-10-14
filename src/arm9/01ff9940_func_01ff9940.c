/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dRS SDK_data_02170500
#define NNS_G3dRSOnGlb SDK_data_02170504
#define NNSi_G3dGetJointScaleMaya func_01ff9940
#include <nnsys/g3d/cgtool/maya.h>
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/util.h>

#include <nitro/code32.h>
#include <nitro/codereset.h>

#pragma thumb off
void NNSi_G3dGetJointScaleMaya (NNSG3dJntAnmResult * pResult, const fx32 * p, const u8 * cmd, u32 srtflag)
{
    u8 opFlag;

    NNS_G3D_NULL_ASSERT(pResult);
    NNS_G3D_NULL_ASSERT(cmd);
    NNS_G3D_NULL_ASSERT(p);
    NNS_G3D_NULL_ASSERT(NNS_G3dRS);
    opFlag = *(cmd + 3);

    if (srtflag & NNS_G3D_SRTFLAG_SCALE_ONE) {
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALE_ONE;
        if (opFlag & NNS_G3D_SBC_NODEDESC_FLAG_MAYASSC_PARENT) {
            u32 nodeID = *(cmd + 1);
            NNSi_G3dBitVecSet(&NNS_G3dRS->isScaleCacheOne[0], nodeID);
        }
    } else {
        pResult->scale.x = *(p + 0);
        pResult->scale.y = *(p + 1);
        pResult->scale.z = *(p + 2);

        if (opFlag & NNS_G3D_SBC_NODEDESC_FLAG_MAYASSC_PARENT) {
            u32 nodeID = *(cmd + 1);

            NNSi_G3dBitVecReset(&NNS_G3dRS->isScaleCacheOne[0], nodeID);

            NNS_G3dRSOnGlb.scaleCache[nodeID].inv.x = *(p + 3);
            NNS_G3dRSOnGlb.scaleCache[nodeID].inv.y = *(p + 4);
            NNS_G3dRSOnGlb.scaleCache[nodeID].inv.z = *(p + 5);
        }
    }

    if (opFlag & NNS_G3D_SBC_NODEDESC_FLAG_MAYASSC_APPLY) {
        u32 parentID = *(cmd + 2);
        pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_MAYA_SSC;

        if (NNSi_G3dBitVecCheck(&NNS_G3dRS->isScaleCacheOne[0], parentID)) {
            pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALEEX0_ONE;
        } else {
            pResult->scaleEx0 = NNS_G3dRSOnGlb.scaleCache[parentID].inv;
        }
    }

    pResult->flag |= NNS_G3D_JNTANM_RESULTFLAG_SCALEEX1_ONE;
}
