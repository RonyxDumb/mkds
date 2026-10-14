/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define getScaleDataEx_ func_0201456c
#include <nnsys/g3d/anm/nsbca.h>
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
void getScaleDataEx_ (fx32 * s_invs, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm)
{
    const void * pArray = (const void *)((const u8 *)pJntAnm + *(pData + 1));
    NNSG3dJntAnmSInfo info = (NNSG3dJntAnmSInfo) * pData;
    u32 last_interp;
    u32 idx0, idx1;
    fx32 remainder;
    int step;
    u32 step_shift;
    u32 frame;

    frame = (u32)FX_Whole(Frame);

    if (frame == pJntAnm->numFrame - 1) {
        if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK)) {
            idx0 = frame;
        } else if (info & NNS_G3D_JNTANM_SINFO_STEP_2)   {
            idx0 = (frame >> 1) + (frame & 1);
        } else {
            idx0 = (frame >> 2) + (frame & 3);
        }

        if (pJntAnm->flag & NNS_G3D_JNTANM_OPTION_END_TO_START_INTERPOLATION) {
            idx1 = 0;
            goto SCALE_EX_0_1;
        } else {
            if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
                const fx16 * p_fx16 = (const fx16 *)pArray;

                s_invs[0] = *(p_fx16 + 2 * idx0);
                s_invs[1] = *(p_fx16 + 2 * idx0 + 1);
            } else {
                const fx32 * p_fx32 = (const fx32 *)pArray;

                s_invs[0] = *(p_fx32 + 2 * idx0);
                s_invs[1] = *(p_fx32 + 2 * idx0 + 1);
            }
            return;
        }
    }

    if (!(info & NNS_G3D_JNTANM_SINFO_STEP_MASK)) {
        goto SCALE_EX_0;
    }

    last_interp = ((u32)info & NNS_G3D_JNTANM_SINFO_LAST_INTERP_MASK) >>
                  NNS_G3D_JNTANM_SINFO_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_SINFO_STEP_2) {

        if (frame >= last_interp) {
            idx0 = (last_interp >> 1);
            idx1 = idx0 + 1;
            goto SCALE_EX_0_1;
        } else {
            idx0 = frame >> 1;
            idx1 = idx0 + 1;
            remainder = Frame & (FX32_ONE * 2 - 1);
            step = 2;
            step_shift = 1;
            goto SCALE_EX;
        }
    } else {
        if (frame >= last_interp) {
            idx0 = (frame >> 2) + (frame & 3);
            idx1 = idx0 + 1;
            goto SCALE_EX_0_1;
        } else {
            idx0 = frame >> 2;
            idx1 = idx0 + 1;
            remainder = Frame & (FX32_ONE * 4 - 1);
            step = 4;
            step_shift = 2;
            goto SCALE_EX;
        }
    }
    NNS_G3D_ASSERT(0);
SCALE_EX_0:
    idx0 = (u32)frame;
    idx1 = idx0 + 1;
SCALE_EX_0_1:
    remainder = Frame & (FX32_ONE - 1);
    step = 1;
    step_shift = 0;
SCALE_EX:
    {
        fx32 s0, s1;
        fx32 inv0, inv1;

        if (info & NNS_G3D_JNTANM_SINFO_FX16ARRAY) {
            const fx16 * p_fx16 = (const fx16 *)pArray;

            s0 = *(p_fx16 + 2 * idx0);
            inv0 = *(p_fx16 + 2 * idx0 + 1);

            s1 = *(p_fx16 + 2 * idx1);
            inv1 = *(p_fx16 + 2 * idx1 + 1);
        } else {
            const fx32 * p_fx32 = (const fx32 *)pArray;

            s0 = *(p_fx32 + 2 * idx0);
            inv0 = *(p_fx32 + 2 * idx0 + 1);

            s1 = *(p_fx32 + 2 * idx1);
            inv1 = *(p_fx32 + 2 * idx1 + 1);
        }

        s_invs[0] = ((s0 * step) + (((s1 - s0) * remainder) >> FX32_SHIFT)) >> step_shift;
        s_invs[1] = ((inv0 * step) + (((inv1 - inv0) * remainder) >> FX32_SHIFT)) >> step_shift;
    }

    return;
}
