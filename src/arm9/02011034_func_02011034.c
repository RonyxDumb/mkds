/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGeBufferOP_N func_01ff9048
#define NNS_G3dGlb SDK_data_0217029c
#define NNS_G3dGlbFlushP func_02011034
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
extern NNSG3dGlb NNS_G3dGlb;
#pragma thumb off
void NNS_G3dGlbFlushP (void)
{
    static const u32 sz = (sizeof(NNS_G3dGlb.cmd0) +
                           sizeof(NNS_G3dGlb.mtxmode_proj) +
                           sizeof(NNS_G3dGlb.projMtx) +
                           sizeof(NNS_G3dGlb.mtxmode_posvec) +
                           sizeof(NNS_G3dGlb.cameraMtx) +
                           sizeof(NNS_G3dGlb.cmd1) +
                           sizeof(NNS_G3dGlb.lightVec[0]) * 4 +
                           sizeof(NNS_G3dGlb.cmd2) +
                           sizeof(NNS_G3dGlb.prmMatColor0) +
                           sizeof(NNS_G3dGlb.prmMatColor1) +
                           sizeof(NNS_G3dGlb.prmPolygonAttr) +
                           sizeof(NNS_G3dGlb.prmViewPort) +
                           sizeof(NNS_G3dGlb.cmd4) +
                           sizeof(NNS_G3dGlb.prmBaseTrans) +
                           sizeof(NNS_G3dGlb.prmBaseRot) +
                           sizeof(NNS_G3dGlb.prmBaseScale) +
                           sizeof(NNS_G3dGlb.prmTexImageParam) +
                           sizeof(NNS_G3dGlb.cmd3) +
                           sizeof(NNS_G3dGlb.lightColor[0]) * 4) / 4;

    NNS_G3D_ASSERT(NNS_G3dGlb.cmd0 == ((G3OP_MTX_MODE << 0) |
                                       (G3OP_MTX_LOAD_4x4 << 8) |
                                       (G3OP_MTX_MODE << 16) |
                                       (G3OP_MTX_LOAD_4x3 << 24)));
    NNS_G3D_ASSERT(NNS_G3dGlb.mtxmode_proj == GX_MTXMODE_PROJECTION);
    NNS_G3D_ASSERT(NNS_G3dGlb.mtxmode_posvec == GX_MTXMODE_POSITION_VECTOR);
    NNS_G3D_ASSERT(NNS_G3dGlb.cmd1 == ((G3OP_LIGHT_VECTOR << 0) |
                                       (G3OP_LIGHT_VECTOR << 8) |
                                       (G3OP_LIGHT_VECTOR << 16) |
                                       (G3OP_LIGHT_VECTOR << 24)));
    NNS_G3D_ASSERT(NNS_G3dGlb.cmd2 == ((G3OP_DIF_AMB << 0) |
                                       (G3OP_SPE_EMI << 8) |
                                       (G3OP_POLYGON_ATTR << 16) |
                                       (G3OP_VIEWPORT << 24)));
    NNS_G3D_ASSERT(NNS_G3dGlb.cmd3 == ((G3OP_LIGHT_COLOR << 0) |
                                       (G3OP_LIGHT_COLOR << 8) |
                                       (G3OP_LIGHT_COLOR << 16) |
                                       (G3OP_LIGHT_COLOR << 24)));
    NNS_G3D_ASSERT(NNS_G3dGlb.cmd4 == ((G3OP_MTX_MULT_4x3 << 0) |
                                       (G3OP_MTX_SCALE << 8) |
                                       (G3OP_TEXIMAGE_PARAM << 16)));

    NNS_G3dGeBufferData_N((u32 *)&NNS_G3dGlb.cmd0, sz);

    NNS_G3dGlb.flag &= ~NNS_G3D_GLB_FLAG_FLUSH_WVP;
    NNS_G3dGlb.flag &= ~NNS_G3D_GLB_FLAG_FLUSH_VP;

}
