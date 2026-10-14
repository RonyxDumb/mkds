/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GetMatColAnmuAlphaValue_ func_020154e4
#include <nnsys/g3d/anm/nsbma.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#pragma thumb off
u16 GetMatColAnmuAlphaValue_ (const NNSG3dResMatCAnm * pAnm, u32 info, u32 frame)
{
    const u8 * pDataHead;
    u32 last_interp;

    if (info & NNS_G3D_MATCANM_ELEM_CONST) {
        return (u16)(info & NNS_G3D_MATCANM_ELEM_OFFSET_CONSTANT_MASK);
    }

    pDataHead = (const u8 *)pAnm + (info & NNS_G3D_MATCANM_ELEM_OFFSET_CONSTANT_MASK);

    if (!(info & NNS_G3D_MATCANM_ELEM_STEP_MASK)) {
        return *(pDataHead + frame);
    }

    last_interp = (NNS_G3D_MATCANM_ELEM_LAST_INTERP_MASK & info)
                  >> NNS_G3D_MATCANM_ELEM_LAST_INTERP_SHIFT;
    if (info & NNS_G3D_MATCANM_ELEM_STEP_2) {
        if (frame & 1) {
            if (frame > last_interp) {
                return *(pDataHead + (last_interp >> 1) + 1);
            } else {
                return (u16)((*(pDataHead + (frame >> 1)) + *(pDataHead + (frame >> 1) + 1)) >> 1);
            }
        } else {
            return *(pDataHead + (frame >> 1));
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                return *(pDataHead + (last_interp >> 2) + (frame & 3));
            }

            if (frame & 1) {
                u32 idx, idx_sub;
                u32 v, v_sub;

                if (frame & 2) {
                    idx_sub = (frame >> 2);
                    idx = idx_sub + 1;
                } else {
                    idx = (frame >> 2);
                    idx_sub = idx + 1;
                }

                v = *(pDataHead + idx);
                v_sub = *(pDataHead + idx_sub);

                return (u16)((v + v + v + v_sub) >> 2);
            } else {
                return (u16)((*(pDataHead + (frame >> 2)) + *(pDataHead + (frame >> 2) + 1)) >> 1);
            }
        } else {
            return *(pDataHead + (frame >> 2));
        }
    }
    NNS_G3D_ASSERT(0);
}
