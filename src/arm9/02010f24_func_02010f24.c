/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGlb SDK_data_0217029c
#define NNS_G3dGlbPolygonAttr func_02010f24
#include <nnsys/g3d/glbstate.h>
#include <nnsys/g3d/gecom.h>
extern NNSG3dGlb NNS_G3dGlb;
#pragma thumb off
void NNS_G3dGlbPolygonAttr (int light, GXPolygonMode polyMode, GXCull cullMode, int polygonID, int alpha, int misc)
{
    GX_LIGHTMASK_ASSERT(light);
    GX_POLYGONMODE_ASSERT(polyMode);
    GX_CULL_ASSERT(cullMode);
    GX_POLYGON_ATTR_POLYGONID_ASSERT(polygonID);
    GX_POLYGON_ATTR_ALPHA_ASSERT(alpha);

    NNS_G3dGlb.prmPolygonAttr = GX_PACK_POLYGONATTR_PARAM(light,
                                                          polyMode,
                                                          cullMode,
                                                          polygonID,
                                                          alpha,
                                                          misc);
}
