/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define updateHintVec_ func_01ff8dec
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/anm.h>
#include <nnsys/g3d/binres/res_struct.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#pragma thumb off
void updateHintVec_ (u32 * pVec, const NNSG3dAnmObj * pAnmObj)
{
    const NNSG3dAnmObj * p = pAnmObj;
    while (p) {
        int i;
        for (i = 0; i < p->numMapData; ++i) {
            if (p->mapData[i] & NNS_G3D_ANMOBJ_MAPDATA_EXIST) {
                pVec[i >> 5] |= 1 << (i & 31);
            }
        }
        p = p->next;
    }
}
