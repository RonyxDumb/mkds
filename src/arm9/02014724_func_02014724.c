/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define getScaleData_ func_02014724
#include <nnsys/g3d/anm/nsbca.h>
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
void getScaleData_ (fx32 * s_invs, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm)
{
    u32 frame = (u32)FX_Whole(Frame);
    const void * pArray = (const void *)((u8 *)pJntAnm + *(pData + 1));
    NNSG3dJntAnmSInfo info = (NNSG3dJntAnmSInfo) * pData;
    u32 last_interp;
    u32 idx;
    u32 idx_sub;

    NNS_G3D_NULL_ASSERT(s_invs);
    NNS_G3D_NULL_ASSERT(pArray);

    if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK)) {
        idx = frame;
        goto SCALE_NONINTERP;
    }

    last_interp = ((u32)info & NNS_G3D_JNTANM_SINFO_LAST_INTERP_MASK) >>
                  NNS_G3D_JNTANM_SINFO_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {
        if (frame & 1) {
            if (frame > last_interp) {
                idx = (last_interp >> 1) + 1;
                goto SCALE_NONINTERP;
            } else {
                idx = frame >> 1;
                goto SCALE_INTERP_2;
            }
        } else {
            idx = frame >> 1;
            goto SCALE_NONINTERP;
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                idx = (last_interp >> 2) + (frame & 3);
                goto SCALE_NONINTERP;
            }

            if (frame & 1) {
                fx32 v, v_sub;
                if (frame & 2) {
                    idx_sub = (frame >> 2);
                    idx = idx_sub + 1;
                } else {
                    idx = (frame >> 2);
                    idx_sub = idx + 1;
                }

                if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
                    const fx16 * p_fx16 = (const fx16 *)pArray;

                    v = *(p_fx16 + 2 * idx);
                    v_sub = *(p_fx16 + 2 * idx_sub);
                    s_invs[0] = (v + (v << 1) + v_sub) >> 2;

                    v = *(p_fx16 + 2 * idx + 1);
                    v_sub = *(p_fx16 + 2 * idx_sub + 1);
                    s_invs[1] = (v + (v << 1) + v_sub) >> 2;
                } else {
                    const fx32 * p_fx32 = (const fx32 *)pArray;

                    v = *(p_fx32 + 2 * idx);
                    v_sub = *(p_fx32 + 2 * idx_sub);

                    s_invs[0] = (fx32)(((fx64)v + v + v + v_sub) >> 2);

                    v = *(p_fx32 + 2 * idx + 1);
                    v_sub = *(p_fx32 + 2 * idx_sub + 1);

                    s_invs[1] = (fx32)(((fx64)v + v + v + v_sub) >> 2);
                }
                return;
            } else {
                idx = frame >> 2;
                goto SCALE_INTERP_2;
            }
        } else {
            idx = frame >> 2;
            goto SCALE_NONINTERP;
        }
    }
SCALE_NONINTERP:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
        const fx16 * p_fx16 = (const fx16 *)pArray;

        s_invs[0] = *(p_fx16 + 2 * idx);
        s_invs[1] = *(p_fx16 + 2 * idx + 1);
    } else {
        const fx32 * p_fx32 = (const fx32 *)pArray;

        s_invs[0] = *(p_fx32 + 2 * idx);
        s_invs[1] = *(p_fx32 + 2 * idx + 1);
    }
    return;
SCALE_INTERP_2:
    if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
        const fx16 * p_fx16 = (const fx16 *)pArray;

        s_invs[0] = (*(p_fx16 + 2 * idx) + *(p_fx16 + 2 * idx + 2)) >> 1;
        s_invs[1] = (*(p_fx16 + 2 * idx + 1) + *(p_fx16 + 2 * idx + 3)) >> 1;
    } else {
        const fx32 * p_fx32 = (const fx32 *)pArray;

        s_invs[0] = (*(p_fx32 + 2 * idx) + (*(p_fx32 + 2 * idx + 2))) >> 1;
        s_invs[1] = (*(p_fx32 + 2 * idx + 1) + (*(p_fx32 + 2 * idx + 3))) >> 1;
    }
    return;
}
