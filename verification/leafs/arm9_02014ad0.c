/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define getTransData_ func_02014ad0
#include <nnsys/g3d/anm/nsbca.h>
#include <nnsys/g3d/sbc.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
void getTransData_ (fx32 * pVal, fx32 Frame, const u32 * pData, const NNSG3dResJntAnm * pJntAnm)
{
    u32 frame = (u32)FX_Whole(Frame);
    const void * pArray = (const void *)((const u8 *)pJntAnm + *(pData + 1));
    NNSG3dJntAnmTInfo info = (NNSG3dJntAnmTInfo) * pData;
    u32 last_interp;
    u32 idx;
    u32 idx_sub;

    NNS_G3D_NULL_ASSERT(pVal);
    NNS_G3D_NULL_ASSERT(pArray);

    if (!(info & NNS_G3D_JNTANM_TINFO_STEP_MASK)) {
        idx = frame;
        goto TRANS_NONINTERP;
    }

    last_interp = ((u32)info & NNS_G3D_JNTANM_TINFO_LAST_INTERP_MASK) >>
                  NNS_G3D_JNTANM_TINFO_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_JNTANM_TINFO_STEP_2) {

        if (frame & 1) {
            if (frame > last_interp) {
                idx = (last_interp >> 1) + 1;
                goto TRANS_NONINTERP;
            } else {
                idx = frame >> 1;
                goto TRANS_INTERP_2;
            }
        } else {
            idx = frame >> 1;
            goto TRANS_NONINTERP;
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                idx = (last_interp >> 2) + (frame & 3);
                goto TRANS_NONINTERP;
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

                if (info & NNS_G3D_JNTANM_TINFO_FX16ARRAY) {
                    const fx16 * p_fx16 = (const fx16 *)pArray;

                    v = *(p_fx16 + idx);
                    v_sub = *(p_fx16 + idx_sub);
                    *pVal = (v + v + v + v_sub) >> 2;
                } else {
                    const fx32 * p_fx32 = (const fx32 *)pArray;

                    v = *(p_fx32 + idx);
                    v_sub = *(p_fx32 + idx_sub);

                    *pVal = (fx32)(((fx64)v + v + v + v_sub) >> 2);
                }
                return;
            } else {
                idx = frame >> 2;
                goto TRANS_INTERP_2;
            }
        } else {
            idx = frame >> 2;
            goto TRANS_NONINTERP;
        }
    }
    NNS_G3D_ASSERT(0);
TRANS_INTERP_2:
    if (info & NNS_G3D_JNTANM_TINFO_FX16ARRAY) {
        const fx16 * p_fx16 = (const fx16 *)pArray;

        *pVal = (*(p_fx16 + idx) + *(p_fx16 + idx + 1)) >> 1;
    } else {
        const fx32 * p_fx32 = (const fx32 *)pArray;

        fx32 v1 = *(p_fx32 + idx) >> 1;
        fx32 v2 = *(p_fx32 + idx + 1) >> 1;
        *pVal = v1 + v2;
    }
    return;
TRANS_NONINTERP:
    if (info & NNS_G3D_JNTANM_TINFO_FX16ARRAY) {
        *pVal = *((const fx16 *)pArray + idx);
    } else {
        *pVal = *((const fx32 *)pArray + idx);
    }
    return;
}
