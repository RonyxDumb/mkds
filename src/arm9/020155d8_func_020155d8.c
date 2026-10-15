/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GetMatColAnmValue_ func_020155d8
#include <nnsys/g3d/anm/nsbma.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#pragma thumb off
u16 GetMatColAnmValue_ (const NNSG3dResMatCAnm * pAnm, u32 info, u32 frame)
{
    const u16 * pDataHead;
    u32 last_interp;
    u32 idx;

    if (info & NNS_G3D_MATCANM_ELEM_CONST) {
        return (u16)(info & NNS_G3D_MATCANM_ELEM_OFFSET_CONSTANT_MASK);
    }

    pDataHead = (const u16 *)((const u8 *)pAnm + (info & NNS_G3D_MATCANM_ELEM_OFFSET_CONSTANT_MASK));

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
                idx = frame >> 1;
                goto MATC_INTERP_50_50;
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
                u32 idx_sub;
                u32 v, v_sub;
                u32 c, c_sub;
                u32 rval;
                const u32 cmask0 = GX_RGB_R_MASK | GX_RGB_B_MASK;
                const u32 cmask1 = GX_RGB_G_MASK;

                if (frame & 2) {
                    idx_sub = (frame >> 2);
                    idx = idx_sub + 1;
                } else {
                    idx = (frame >> 2);
                    idx_sub = idx + 1;
                }

                v = *(pDataHead + idx);
                v_sub = *(pDataHead + idx_sub);

                c = v & cmask0;
                c_sub = v_sub & cmask0;
                rval = ((c + c + c + c_sub) >> 2) & cmask0;

                c = v & cmask1;
                c_sub = v_sub & cmask1;
                rval |= ((c + c + c + c_sub) >> 2) & cmask1;

                return (u16)rval;
            } else {
                idx = frame >> 2;
                goto MATC_INTERP_50_50;
            }
        } else {
            return *(pDataHead + (frame >> 2));
        }
    }
    NNS_G3D_ASSERT(0);
MATC_INTERP_50_50:
    {
        u32 rval;
        u32 v0 = *(pDataHead + idx);
        u32 v1 = *(pDataHead + idx + 1);
        const u32 cmask0 = GX_RGB_R_MASK | GX_RGB_B_MASK;
        const u32 cmask1 = GX_RGB_G_MASK;

        rval = (((v0 & cmask0) + (v1 & cmask0)) >> 1) & cmask0;
        rval |= (((v0 & cmask1) + (v1 & cmask1)) >> 1) & cmask1;

        return (u16) rval;
    }
}
