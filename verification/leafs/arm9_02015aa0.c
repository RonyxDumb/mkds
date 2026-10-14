/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GetTexSRTAnmVectorVal_ func_02015aa0
#include <nnsys/g3d/anm/nsbta.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#pragma thumb off
fx32 GetTexSRTAnmVectorVal_ (const NNSG3dResTexSRTAnm * pTexAnm, u32 info, u32 data, u32 frame)
{
    u32 idx, idx_sub;
    u32 last_interp;
    const void * pDataHead;

    if (info & NNS_G3D_TEXSRTANM_ELEM_CONST) {
        return (fx32)data;
    }

    pDataHead = (const void *)((u8 *)pTexAnm + data);

    if (!(info & NNS_G3D_TEXSRTANM_ELEM_STEP_MASK)) {
        idx = frame;
        goto TEXSRT_VAL_NONINTERP;
    }

    last_interp = (NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_MASK & info) >>
                  NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_TEXSRTANM_ELEM_STEP_2) {
        if (frame & 1) {
            if (frame > last_interp) {
                idx = (last_interp >> 1) + 1;
                goto TEXSRT_VAL_NONINTERP;
            } else {
                idx = frame >> 1;
                goto TEXSRT_VAL_INTERP_2;
            }
        } else {
            idx = frame >> 1;
            goto TEXSRT_VAL_NONINTERP;
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                idx = (last_interp >> 2) + (frame & 3);
                goto TEXSRT_VAL_NONINTERP;
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

                if (info & NNS_G3D_TEXSRTANM_ELEM_FX16) {
                    v = *((const fx16 *)pDataHead + idx);
                    v_sub = *((const fx16 *)pDataHead + idx_sub);
                } else {
                    v = *((const fx32 *)pDataHead + idx);
                    v_sub = *((const fx32 *)pDataHead + idx_sub);
                }
                return (v + v + v + v_sub) >> 2;
            } else {
                idx = frame >> 2;
                goto TEXSRT_VAL_INTERP_2;
            }
        } else {
            idx = frame >> 2;
            goto TEXSRT_VAL_NONINTERP;
        }
    }
    NNS_G3D_ASSERT(0);
TEXSRT_VAL_NONINTERP:
    if (info & NNS_G3D_TEXSRTANM_ELEM_FX16) {
        return *((const fx16 *)pDataHead + idx);
    } else {
        return *((const fx32 *)pDataHead + idx);
    }
TEXSRT_VAL_INTERP_2:
    {
        fx32 v0, v1;
        if (info & NNS_G3D_TEXSRTANM_ELEM_FX16) {
            v0 = *((const fx16 *)pDataHead + idx);
            v1 = *((const fx16 *)pDataHead + idx + 1);
        } else {
            v0 = *((const fx32 *)pDataHead + idx);
            v1 = *((const fx32 *)pDataHead + idx + 1);
        }
        return ((v0 + v1) >> 1);
    }
}
