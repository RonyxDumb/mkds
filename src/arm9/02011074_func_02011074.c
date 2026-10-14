/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MTX_Identity43_ Matrix4x3_Identity
#define MTX_Identity44_ func_02147954
#define NNS_G3dGlb SDK_data_0217029c
#define NNS_G3dGlbInit func_02011074
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
extern NNSG3dGlb NNS_G3dGlb;
#pragma thumb off
void NNS_G3dGlbInit (void)
{
    NNS_G3dGlb.cmd0 = GX_PACK_OP(G3OP_MTX_MODE, G3OP_MTX_LOAD_4x4, G3OP_MTX_MODE, G3OP_MTX_LOAD_4x3);
    NNS_G3dGlb.mtxmode_proj = GX_MTXMODE_PROJECTION;
    NNS_G3dGlb.mtxmode_posvec = GX_MTXMODE_POSITION_VECTOR;

    NNS_G3dGlb.cmd1 = GX_PACK_OP(G3OP_LIGHT_VECTOR, G3OP_LIGHT_VECTOR, G3OP_LIGHT_VECTOR, G3OP_LIGHT_VECTOR);
    NNS_G3dGlb.cmd2 = GX_PACK_OP(G3OP_DIF_AMB, G3OP_SPE_EMI, G3OP_POLYGON_ATTR, G3OP_VIEWPORT);
    NNS_G3dGlb.cmd3 = GX_PACK_OP(G3OP_LIGHT_COLOR, G3OP_LIGHT_COLOR, G3OP_LIGHT_COLOR, G3OP_LIGHT_COLOR);
    NNS_G3dGlb.cmd4 = GX_PACK_OP(G3OP_MTX_MULT_4x3, G3OP_MTX_SCALE, G3OP_TEXIMAGE_PARAM, G3OP_NOP);

    MTX_Identity43(&NNS_G3dGlb.cameraMtx);
    MTX_Identity44(&NNS_G3dGlb.projMtx);

    NNS_G3dGlb.lightVec[0] = GX_PACK_LIGHTVECTOR_PARAM(0, -FX16_SQRT1_3, -FX16_SQRT1_3, -FX16_SQRT1_3);
    NNS_G3dGlb.lightVec[1] = GX_PACK_LIGHTVECTOR_PARAM(1, -FX16_ONE, 0, 0);
    NNS_G3dGlb.lightVec[2] = GX_PACK_LIGHTVECTOR_PARAM(2, FX16_ONE - 1, 0, 0);
    NNS_G3dGlb.lightVec[3] = GX_PACK_LIGHTVECTOR_PARAM(3, 0, -FX16_ONE, 0);

    NNS_G3dGlb.prmMatColor0 = GX_PACK_DIFFAMB_PARAM(GX_RGB(16, 16, 16),
                                                    GX_RGB(16, 16, 16),
                                                    TRUE);
    NNS_G3dGlb.prmMatColor1 = GX_PACK_SPECEMI_PARAM(GX_RGB(16, 16, 16),
                                                    GX_RGB(16, 16, 16),
                                                    TRUE);

    NNS_G3dGlb.prmPolygonAttr = GX_PACK_POLYGONATTR_PARAM(0xf,
                                                          GX_POLYGONMODE_MODULATE,
                                                          GX_CULL_BACK,
                                                          0,
                                                          31,
                                                          GX_POLYGON_ATTR_MISC_NONE);

    NNS_G3dGlb.prmViewPort = GX_PACK_VIEWPORT_PARAM(0, 0, 255, 191);

    NNS_G3dGlb.lightColor[0] = GX_PACK_LIGHTCOLOR_PARAM(0, GX_RGB(31, 31, 31));
    NNS_G3dGlb.lightColor[1] = GX_PACK_LIGHTCOLOR_PARAM(1, GX_RGB(31, 0, 0));
    NNS_G3dGlb.lightColor[2] = GX_PACK_LIGHTCOLOR_PARAM(2, GX_RGB(0, 31, 0));
    NNS_G3dGlb.lightColor[3] = GX_PACK_LIGHTCOLOR_PARAM(3, GX_RGB(0, 0, 31));

    NNS_G3dGlb.prmBaseTrans.x = 0;
    NNS_G3dGlb.prmBaseTrans.y = 0;
    NNS_G3dGlb.prmBaseTrans.z = 0;

    MTX_Identity33(&NNS_G3dGlb.prmBaseRot);

    NNS_G3dGlb.prmBaseScale.x = FX32_ONE;
    NNS_G3dGlb.prmBaseScale.y = FX32_ONE;
    NNS_G3dGlb.prmBaseScale.z = FX32_ONE;
    NNS_G3dGlb.prmTexImageParam = 0;

    NNS_G3dGlb.flag = (NNSG3dGlbFlag) 0;

    NNS_G3dGlb.camPos.x = NNS_G3dGlb.camPos.y = NNS_G3dGlb.camPos.z = 0;
    NNS_G3dGlb.camUp.x = NNS_G3dGlb.camUp.z = 0;
    NNS_G3dGlb.camUp.y = FX32_ONE;
    NNS_G3dGlb.camTarget.x = NNS_G3dGlb.camTarget.y = 0;
    NNS_G3dGlb.camTarget.z = -FX32_ONE;
}
