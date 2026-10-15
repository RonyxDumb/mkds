/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define NNSG3D_BINRES_RES_STRUCT_ACCESSOR_INLINE_H_
#include <nnsys/g3d/binres/res_struct_accessor.h>
#if 1
#define NNSG3D_BINRES_RES_STRUCT_ACCESSOR_INLINE_H_

#ifdef __cplusplus
extern "C" {
#endif

NNS_G3D_RES_INLINE const NNSG3dResName * NNS_G3dGetResNameByIdx (const NNSG3dResDict * dict, u32 idx)
{
    NNSG3dResDictEntryHeader * hdr;
    NNS_G3D_NULL_ASSERT(dict);


        NNS_G3D_ASSERT(dict->ofsEntry != 0);
        hdr = (NNSG3dResDictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (NNSG3dResName *)((u8 *)hdr +
                                 hdr->ofsName +
                                 sizeof(NNSG3dResName) * idx);

}

NNS_G3D_RES_INLINE void * NNS_G3dGetResDataByIdx (const NNSG3dResDict * dict, u32 idx)
{
    NNSG3dResDictEntryHeader * hdr;
    NNS_G3D_NULL_ASSERT(dict);


        NNS_G3D_ASSERT(dict->ofsEntry != 0);
        hdr = (NNSG3dResDictEntryHeader *)((u8 *)dict + dict->ofsEntry);
        return (void *)(&hdr->data[0] + hdr->sizeUnit * idx);

}

NNS_G3D_RES_INLINE const NNSG3dResName * NNS_G3dGetTexNameByIdx (const NNSG3dResTex * tex, u32 idx)
{
    NNS_G3D_NULL_ASSERT(tex);

    if (tex)
        return NNS_G3dGetResNameByIdx(&tex->dict, idx);
    else
        return NULL;
}

NNS_G3D_RES_INLINE int NNS_G3dGetTexIdxByName (const NNSG3dResTex * tex, const NNSG3dResName * name)
{
    NNS_G3D_NULL_ASSERT(tex);

    if (tex)
        return NNS_G3dGetResDictIdxByName(&tex->dict, name);
    else
        return -1;
}

NNS_G3D_RES_INLINE const NNSG3dResName * NNS_G3dGetPlttNameByIdx (const NNSG3dResTex * tex, u32 idx)
{
    const NNSG3dResDict * dict;
    NNS_G3D_NULL_ASSERT(tex);

    NNS_G3D_ASSERT(tex->plttInfo.ofsDict != 0);

    if (tex && tex->plttInfo.ofsDict != 0) {
        dict = (const NNSG3dResDict *)((u8 *)tex + tex->plttInfo.ofsDict);
        return NNS_G3dGetResNameByIdx(dict, idx);
    } else {
        return NULL;
    }
}

NNS_G3D_RES_INLINE int NNS_G3dGetPlttIdxByName (const NNSG3dResTex * tex, const NNSG3dResName * name)
{
    const NNSG3dResDict * dict;
    NNS_G3D_NULL_ASSERT(tex);

    NNS_G3D_ASSERT(tex->plttInfo.ofsDict != 0);

    if (tex && tex->plttInfo.ofsDict != 0) {
        dict = (const NNSG3dResDict *)((u8 *)tex + tex->plttInfo.ofsDict);
        return NNS_G3dGetResDictIdxByName(dict, name);
    } else {
        return -1;
    }
}

NNS_G3D_RES_INLINE const NNSG3dResName * NNS_G3dGetNodeNameByIdx (const NNSG3dResNodeInfo * nodeinfo, u32 idx)
{
    NNS_G3D_NULL_ASSERT(nodeinfo);

    if (nodeinfo)
        return NNS_G3dGetResNameByIdx(&nodeinfo->dict, idx);
    else
        return NULL;
}

NNS_G3D_RES_INLINE int NNS_G3dGetNodeIdxByName (const NNSG3dResNodeInfo * nodeinfo, const NNSG3dResName * name)
{
    NNS_G3D_NULL_ASSERT(nodeinfo);

    if (nodeinfo)
        return NNS_G3dGetResDictIdxByName(&nodeinfo->dict, name);
    else
        return -1;
}

NNS_G3D_RES_INLINE const NNSG3dResName * NNS_G3dGetMatNameByIdx (const NNSG3dResMat * mat, u32 idx)
{
    NNS_G3D_NULL_ASSERT(mat);

    if (mat)
        return NNS_G3dGetResNameByIdx(&mat->dict, idx);
    else
        return NULL;
}

NNS_G3D_RES_INLINE int NNS_G3dGetMatIdxByName (const NNSG3dResMat * mat, const NNSG3dResName * name)
{
    NNS_G3D_NULL_ASSERT(mat);

    if (mat)
        return NNS_G3dGetResDictIdxByName(&mat->dict, name);
    else
        return -1;
}

NNS_G3D_RES_INLINE const NNSG3dResName * NNS_G3dGetShpNameByIdx (const NNSG3dResShp * shp, u32 idx)
{
    NNS_G3D_NULL_ASSERT(shp);

    if (shp)
        return NNS_G3dGetResNameByIdx(&shp->dict, idx);
    else
        return NULL;
}

NNS_G3D_RES_INLINE int NNS_G3dGetShpIdxByName (const NNSG3dResShp * shp, const NNSG3dResName * name)
{
    NNS_G3D_NULL_ASSERT(shp);

    if (shp)
        return NNS_G3dGetResDictIdxByName(&shp->dict, name);
    else
        return -1;
}

NNS_G3D_RES_INLINE NNSG3dResMdlInfo * NNS_G3dGetMdlInfo (const NNSG3dResMdl * mdl)
{
    NNS_G3D_NULL_ASSERT(mdl);

    if (mdl)
        return (NNSG3dResMdlInfo *)&mdl->info;
    else
        return NULL;
}

NNS_G3D_RES_INLINE NNSG3dResNodeInfo * NNS_G3dGetNodeInfo (const NNSG3dResMdl * mdl)
{
    NNS_G3D_NULL_ASSERT(mdl);

    if (mdl)
        return (NNSG3dResNodeInfo *)&mdl->nodeInfo;
    else
        return NULL;
}

NNS_G3D_RES_INLINE u8 * NNS_G3dGetSbc (const NNSG3dResMdl * mdl)
{
    NNS_G3D_NULL_ASSERT(mdl);

    if (mdl && mdl->ofsSbc != 0)
        return (u8 *)((u8 *)mdl + mdl->ofsSbc);
    else
        return NULL;
}

NNS_G3D_RES_INLINE NNSG3dResMat * NNS_G3dGetMat (const NNSG3dResMdl * mdl)
{
    NNS_G3D_NULL_ASSERT(mdl);
    NNS_G3D_ASSERT(mdl->ofsMat != 0);

    if (mdl && mdl->ofsMat != 0)
        return (NNSG3dResMat *)((u8 *)mdl + mdl->ofsMat);
    else
        return NULL;
}

NNS_G3D_RES_INLINE NNSG3dResShp * NNS_G3dGetShp (const NNSG3dResMdl * mdl)
{
    NNS_G3D_NULL_ASSERT(mdl);
    NNS_G3D_ASSERT(mdl->ofsShp != 0);

    if (mdl && mdl->ofsShp != 0)
        return (NNSG3dResShp *)((u8 *)mdl + mdl->ofsShp);
    else
        return NULL;
}

NNS_G3D_RES_INLINE NNSG3dResMdl * NNS_G3dGetMdlByIdx (const NNSG3dResMdlSet * mdlSet, u32 idx)
{
    NNSG3dResDictMdlSetData * data;
    NNS_G3D_NULL_ASSERT(mdlSet);

    if (mdlSet) {
        data = (NNSG3dResDictMdlSetData *)NNS_G3dGetResDataByIdx(&mdlSet->dict, idx);
        if (data) {
            NNS_G3D_ASSERT(data->offset != 0);
            return (NNSG3dResMdl *)((u8 *)mdlSet + data->offset);
        }
    }
    return NULL;
}

NNS_G3D_RES_INLINE const NNSG3dResName * NNS_G3dGetMdlNameByIdx (const NNSG3dResMdlSet * mdlSet, u32 idx)
{
    NNS_G3D_NULL_ASSERT(mdlSet);

    if (mdlSet)
        return NNS_G3dGetResNameByIdx(&mdlSet->dict, idx);
    else
        return NULL;
}

NNS_G3D_RES_INLINE NNSG3dResMdl * NNS_G3dGetMdlByName (const NNSG3dResMdlSet * mdlSet, const NNSG3dResName * name)
{
    NNSG3dResDictMdlSetData * data;
    NNS_G3D_NULL_ASSERT(mdlSet);

    if (mdlSet) {
        data = (NNSG3dResDictMdlSetData *)NNS_G3dGetResDataByName(&mdlSet->dict, name);
        if (data) {
            NNS_G3D_ASSERT(data->offset != 0);
            return (NNSG3dResMdl *)((u8 *)mdlSet + data->offset);
        }
    }

    return NULL;
}

NNS_G3D_RES_INLINE int NNS_G3dGetMdlIdxByName (const NNSG3dResMdlSet * mdlSet, const NNSG3dResName * name)
{
    NNS_G3D_NULL_ASSERT(mdlSet);

    if (mdlSet)
        return NNS_G3dGetResDictIdxByName(&mdlSet->dict, name);
    else
        return -1;
}

NNS_G3D_RES_INLINE NNSG3dResMdlSet * NNS_G3dCheckMdlSet (const NNSG3dResDataBlockHeader * dataBlkHeader)
{
    NNS_G3D_NULL_ASSERT(dataBlkHeader);

    if (dataBlkHeader->kind == NNS_G3D_DATABLK_MDLSET) {
        return (NNSG3dResMdlSet *)dataBlkHeader;
    } else {
        return NULL;
    }
}

NNS_G3D_RES_INLINE NNSG3dResTex * NNS_G3dCheckTex (const NNSG3dResDataBlockHeader * dataBlkHeader)
{
    NNS_G3D_NULL_ASSERT(dataBlkHeader);

    if (dataBlkHeader->kind == NNS_G3D_DATABLK_TEX) {
        return (NNSG3dResTex *)dataBlkHeader;
    } else {
        return NULL;
    }
}

NNS_G3D_RES_INLINE NNSG3dResNodeData * NNS_G3dGetNodeDataByIdx (const NNSG3dResNodeInfo * info, u32 idx)
{
    NNSG3dResDictNodeData * data;
    NNS_G3D_NULL_ASSERT(info);

    if (info) {
        data = (NNSG3dResDictNodeData *)NNS_G3dGetResDataByIdx(&info->dict, idx);
        if (data) {
            NNS_G3D_ASSERT(data->offset != 0);
            return (NNSG3dResNodeData *)((u8 *)info + data->offset);
        }
    }

    return NULL;
}

NNS_G3D_RES_INLINE NNSG3dResMatData * NNS_G3dGetMatDataByIdx (const NNSG3dResMat * mat, u32 idx)
{
    NNSG3dResDictMatData * data;
    NNS_G3D_NULL_ASSERT(mat);

    if (mat) {
        data = (NNSG3dResDictMatData *)NNS_G3dGetResDataByIdx(&mat->dict, idx);
        if (data) {
            NNS_G3D_ASSERT(data->offset != 0);
            return (NNSG3dResMatData *)((u8 *)mat + data->offset);
        }
    }

    return NULL;
}

NNS_G3D_RES_INLINE NNSG3dResShpData * NNS_G3dGetShpDataByIdx (const NNSG3dResShp * shp, u32 idx)
{
    NNSG3dResDictShpData * data;
    NNS_G3D_NULL_ASSERT(shp);

    if (shp) {
        data = (NNSG3dResDictShpData *)NNS_G3dGetResDataByIdx(&shp->dict, idx);
        if (data) {
            NNS_G3D_ASSERT(data->offset != 0);
            return (NNSG3dResShpData *)((u8 *)shp + data->offset);
        }
    }

    return NULL;
}

NNS_G3D_RES_INLINE NNSG3dResDictTexData * NNS_G3dGetTexDataByName (const NNSG3dResTex * tex, const NNSG3dResName * name)
{
    NNS_G3D_NULL_ASSERT(tex);

    if (tex)
        return (NNSG3dResDictTexData *)NNS_G3dGetResDataByName(&tex->dict, name);
    else
        return NULL;
}

NNS_G3D_RES_INLINE NNSG3dResDictTexData * NNS_G3dGetTexDataByIdx (const NNSG3dResTex * tex, u32 idx)
{
    NNS_G3D_NULL_ASSERT(tex);

    if (tex)
        return (NNSG3dResDictTexData *)NNS_G3dGetResDataByIdx(&tex->dict, idx);
    else
        return NULL;
}

NNS_G3D_RES_INLINE NNSG3dResDictPlttData * NNS_G3dGetPlttDataByName (const NNSG3dResTex * tex, const NNSG3dResName * name)
{
    NNSG3dResDict * dict;
    NNS_G3D_NULL_ASSERT(tex);
    NNS_G3D_ASSERT(tex->plttInfo.ofsDict != 0);

    if (tex && tex->plttInfo.ofsDict != 0) {
        dict = (NNSG3dResDict *)((u8 *)tex + tex->plttInfo.ofsDict);
        return (NNSG3dResDictPlttData *)NNS_G3dGetResDataByName(dict, name);
    } else {
        return NULL;
    }
}

NNS_G3D_RES_INLINE NNSG3dResDictPlttData * NNS_G3dGetPlttDataByIdx (const NNSG3dResTex * tex, u32 idx)
{
    NNSG3dResDict * dict;
    NNS_G3D_NULL_ASSERT(tex);
    NNS_G3D_ASSERT(tex->plttInfo.ofsDict != 0);

    if (tex && tex->plttInfo.ofsDict != 0) {
        dict = (NNSG3dResDict *)((u8 *)tex + tex->plttInfo.ofsDict);
        return (NNSG3dResDictPlttData *)NNS_G3dGetResDataByIdx(dict, idx);
    } else {
        return NULL;
    }
}

NNS_G3D_RES_INLINE const void * NNS_G3dGetTexData (const NNSG3dResTex * tex)
{
    return (u8 *)tex + tex->texInfo.ofsTex;
}

NNS_G3D_RES_INLINE const void * NNS_G3dGetTex4x4Data (const NNSG3dResTex * tex)
{
    return (u8 *)tex + tex->tex4x4Info.ofsTex;
}

NNS_G3D_RES_INLINE const void * NNS_G3dGetTex4x4PlttIdxData (const NNSG3dResTex * tex)
{
    return (u8 *)tex + tex->tex4x4Info.ofsTexPlttIdx;
}

NNS_G3D_RES_INLINE const void * NNS_G3dGetPlttData (const NNSG3dResTex * tex)
{
    return (u8 *)tex + tex->plttInfo.ofsPlttData;
}

NNS_G3D_RES_INLINE const void * NNS_G3dGetShpDLPtr (const NNSG3dResShpData * shp)
{
    return (u8 *)shp + shp->ofsDL;
}

NNS_G3D_RES_INLINE u32 NNS_G3dGetShpDLSize (const NNSG3dResShpData * shp)
{
    return shp->sizeDL;
}

NNS_G3D_RES_INLINE BOOL NNS_G3dIsMatAnm (const void * pAnm)
{
    const NNSG3dResAnmHeader * hdr = (const NNSG3dResAnmHeader *) pAnm;
    return hdr != NULL && hdr->category0 == 'M';
}

NNS_G3D_RES_INLINE BOOL NNS_G3dIsJntAnm (const void * pAnm)
{
    const NNSG3dResAnmHeader * hdr = (const NNSG3dResAnmHeader *) pAnm;
    return hdr != NULL && hdr->category0 == 'J';
}

NNS_G3D_RES_INLINE BOOL NNS_G3dIsVisAnm (const void * pAnm)
{
    const NNSG3dResAnmHeader * hdr = (const NNSG3dResAnmHeader *) pAnm;
    return hdr != NULL && hdr->category0 == 'V';
}

#ifdef __cplusplus
}
#endif

#endif

#include <nnsys/g3d/anm/nsbta.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#ifndef NNS_G3D_NSBTA_DISABLE

static fx32 func_02015aa0 (const NNSG3dResTexSRTAnm * pTexAnm, u32 info, u32 data, u32 frame)
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

static u32 func_02015994 (const NNSG3dResTexSRTAnm * pTexAnm, u32 info, u32 data, u32 frame)
{
    u32 idx, idx_sub;
    u32 last_interp;
    const void * pDataHead;

    NNS_G3D_ASSERT(!(info & NNS_G3D_TEXSRTANM_ELEM_FX16));

    if (info & NNS_G3D_TEXSRTANM_ELEM_CONST) {
        return data;
    }

    pDataHead = (const void *)((u8 *)pTexAnm + data);

    if (!(info & NNS_G3D_TEXSRTANM_ELEM_STEP_MASK)) {
        idx = frame;
        goto TEXSRT_SINCOS_NONINTERP;
    }

    last_interp = (NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_MASK & info) >>
                  NNS_G3D_TEXSRTANM_ELEM_LAST_INTERP_SHIFT;

    if (info & NNS_G3D_TEXSRTANM_ELEM_STEP_2) {
        if (frame & 1) {
            if (frame > last_interp) {
                idx = (last_interp >> 1) + 1;
                goto TEXSRT_SINCOS_NONINTERP;
            } else {
                idx = frame >> 1;
                goto TEXSRT_SINCOS_INTERP_2;
            }
        } else {
            idx = frame >> 1;
            goto TEXSRT_SINCOS_NONINTERP;
        }
    } else {
        if (frame & 3) {
            if (frame > last_interp) {
                idx = (last_interp >> 2) + (frame & 3);
                goto TEXSRT_SINCOS_NONINTERP;
            }

            if (frame & 1) {
                fx32 s, s_sub;
                fx32 c, c_sub;

                if (frame & 2) {
                    idx_sub = (frame >> 2);
                    idx = idx_sub + 1;
                } else {
                    idx = (frame >> 2);
                    idx_sub = idx + 1;
                }

                s = *((const fx16 *)pDataHead + 2 * idx);
                c = *((const fx16 *)pDataHead + 2 * idx + 1);
                s_sub = *((const fx16 *)pDataHead + 2 * idx_sub);
                c_sub = *((const fx16 *)pDataHead + 2 * idx_sub + 1);

                s = (s + s + s + s_sub) >> 2;
                c = (c + c + c + c_sub) >> 2;
                return (u32)((s & 0xffff) | (c << 16));
            } else {
                idx = frame >> 2;
                goto TEXSRT_SINCOS_INTERP_2;
            }
        } else {
            idx = frame >> 2;
            goto TEXSRT_SINCOS_NONINTERP;
        }
    }
    NNS_G3D_ASSERT(0);
TEXSRT_SINCOS_NONINTERP:
    return *((const u32 *)pDataHead + idx);
TEXSRT_SINCOS_INTERP_2:
    {
        fx32 s0, s1;
        fx32 c0, c1;
        s0 = *((const fx16 *)pDataHead + 2 * idx);
        c0 = *((const fx16 *)pDataHead + 2 * idx + 1);

        s1 = *((const fx16 *)pDataHead + 2 * idx + 2);
        c1 = *((const fx16 *)pDataHead + 2 * idx + 3);

        return (u32)((((s0 + s1) >> 1) & 0xffff) | (((c0 + c1) >> 1) << 16));
    }
}

static void func_02015894 (const NNSG3dResTexSRTAnm * pTexAnm, u16 idx, u32 frame, NNSG3dMatAnmResult * pResult)
{
    NNS_G3D_ASSERT(idx < pTexAnm->dict.numEntry);
    NNS_G3D_ASSERT(frame < pTexAnm->numFrame);
    NNS_G3D_ASSERT((pTexAnm->anmHeader.category0 == 'M') && (pTexAnm->anmHeader.category1 == 'TA'));

    {
        const NNSG3dResDictTexSRTAnmData * pAnmData =
            (const NNSG3dResDictTexSRTAnmData *)NNS_G3dGetResDataByIdx(&pTexAnm->dict, idx);
        NNSG3dMatAnmResultFlag flag = pResult->flag;

        {
            fx32 transS, transT;

            transS = func_02015aa0(pTexAnm,
                                            pAnmData->transS,
                                            pAnmData->transSEx,
                                            frame);
            transT = func_02015aa0(pTexAnm,
                                            pAnmData->transT,
                                            pAnmData->transTEx,
                                            frame);

            if (transS == 0 && transT == 0) {
                flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO;
            } else {
                flag &= ~NNS_G3D_MATANM_RESULTFLAG_TEXMTX_TRANSZERO;
                pResult->transS = transS;
                pResult->transT = transT;
            }
        }

        {

            u32 data = func_02015994(pTexAnm,
                                              pAnmData->rot,
                                              pAnmData->rotEx,
                                              frame);

            if (data == ((FX32_ONE << 16) | 0)) {
                flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO;
            } else {
                pResult->sinR = (fx16)(data & 0x0000FFFF);
                pResult->cosR = (fx16)(data >> 16);
                flag &= ~NNS_G3D_MATANM_RESULTFLAG_TEXMTX_ROTZERO;
            }
        }

        {
            fx32 scaleS, scaleT;

            scaleS = func_02015aa0(pTexAnm,
                                            pAnmData->scaleS,
                                            pAnmData->scaleSEx,
                                            frame);
            scaleT = func_02015aa0(pTexAnm,
                                            pAnmData->scaleT,
                                            pAnmData->scaleTEx,
                                            frame);

            if (scaleS == FX32_ONE && scaleT == FX32_ONE) {
                flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE;
            } else {
                flag &= ~NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SCALEONE;
                pResult->scaleS = scaleS;
                pResult->scaleT = scaleT;
            }
        }

        pResult->flag = flag;
    }
}

void NNSi_G3dAnmObjInitNsBta (NNSG3dAnmObj * pAnmObj, void * pResAnm, const NNSG3dResMdl * pResMdl)
{
    u32 i;
    NNSG3dResTexSRTAnm * srtAnm;
    const NNSG3dResMat * mat;

    NNS_G3D_NULL_ASSERT(pAnmObj);
    NNS_G3D_NULL_ASSERT(pResAnm);
    NNS_G3D_NULL_ASSERT(pResMdl);

    srtAnm = (NNSG3dResTexSRTAnm *)pResAnm;
    mat = NNS_G3dGetMat(pResMdl);
    pAnmObj->funcAnm = (void *) NNS_G3dFuncAnmMatNsBtaDefault;
    pAnmObj->numMapData = pResMdl->info.numMat;

    MI_CpuClear16(&pAnmObj->mapData[0], sizeof(u16) * pAnmObj->numMapData);

    for (i = 0; i < srtAnm->dict.numEntry; ++i) {
        const NNSG3dResName * name = NNS_G3dGetResNameByIdx(&srtAnm->dict, i);
        int idx = NNS_G3dGetMatIdxByName(mat, name);
        if (!(idx < 0)) {
            pAnmObj->mapData[idx] = (u16)(i | NNS_G3D_ANMOBJ_MAPDATA_EXIST);
        }
    }
}

void NNSi_G3dAnmCalcNsBta (NNSG3dMatAnmResult * pResult, const NNSG3dAnmObj * pAnmObj, u32 dataIdx)
{
    NNS_G3D_NULL_ASSERT(pResult);
    NNS_G3D_NULL_ASSERT(pAnmObj);

    {
        const NNSG3dResTexSRTAnm * pTexAnm
            = (const NNSG3dResTexSRTAnm *)pAnmObj->resAnm;

        func_02015894(pTexAnm,
                      (u16)dataIdx,
                      (u32)FX_Whole(pAnmObj->frame),
                      pResult);

        pResult->prmTexImage &= ~REG_G3_TEXIMAGE_PARAM_TGEN_MASK;
        pResult->prmTexImage |= GX_TEXGEN_TEXCOORD << REG_G3_TEXIMAGE_PARAM_TGEN_SHIFT;

        pResult->flag |= NNS_G3D_MATANM_RESULTFLAG_TEXMTX_SET;

    }
}
#endif
