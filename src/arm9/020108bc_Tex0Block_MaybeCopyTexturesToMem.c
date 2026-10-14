/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GX_BeginLoadTex func_0214c6a8
#define GX_LoadTex func_0214c544
#define GX_EndLoadTex func_0214c4d4
#define NNS_G3dTexLoad Tex0Block_MaybeCopyTexturesToMem
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/anm.h>
#include <nnsys/g3d/binres/res_struct.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#pragma thumb off
void NNS_G3dTexLoad (NNSG3dResTex * pTex, BOOL exec_begin_end)
{
    NNS_G3D_NULL_ASSERT(pTex);
    NNS_G3D_WARNING(!(pTex->texInfo.flag & NNS_G3D_RESTEX_LOADED),
                    "NNS_G3dTexLoad: texture already loaded");
    NNS_G3D_WARNING(!(pTex->tex4x4Info.flag & NNS_G3D_RESTEX4x4_LOADED),
                    "NNS_G3dTex4x4Load: texture already loaded");

    if (exec_begin_end) {
        GX_BeginLoadTex();
    }

    {
        u32 sz;
        const void * pData;
        u32 from;

        sz = (u32)pTex->texInfo.sizeTex << 3;
        if (sz > 0) {
            NNS_G3D_ASSERT(pTex->texInfo.vramKey != 0);
            NNS_G3D_ASSERTMSG(sz <= NNS_GfdGetTexKeySize(pTex->texInfo.vramKey),
                              "NNS_G3dTexLoad: texKey size not enough, "
                              "0x%05x bytes required.", sz);

            pData = NNS_G3dGetTexData(pTex);
            from = NNS_GfdGetTexKeyAddr(pTex->texInfo.vramKey);

            GX_LoadTex(pData, from, sz);

            pTex->texInfo.flag |= NNS_G3D_RESTEX_LOADED;
        }
    }

    {

        u32 sz;
        const void * pData;
        const void * pDataPlttIdx;
        u32 from;

        sz = (u32)pTex->tex4x4Info.sizeTex << 3;

        if (sz > 0) {
            NNS_G3D_ASSERT(pTex->tex4x4Info.sizeTex != 0);
            NNS_G3D_ASSERTMSG(NNS_GfdGetTexKey4x4Flag(pTex->tex4x4Info.vramKey),
                              "NNS_G3dTexLoad(4x4): texKey is not for 4x4comp textures");
            NNS_G3D_ASSERTMSG(sz <= NNS_GfdGetTexKeySize(pTex->tex4x4Info.vramKey),
                              "NNS_G3dTexLoad(4x4): texKey size not enough, "
                              "0x%05x bytes required.", sz);

            pData = NNS_G3dGetTex4x4Data(pTex);
            pDataPlttIdx = NNS_G3dGetTex4x4PlttIdxData(pTex);
            from = NNS_GfdGetTexKeyAddr(pTex->tex4x4Info.vramKey);

            GX_LoadTex(pData, from, sz);
            GX_LoadTex(pDataPlttIdx, GX_COMP4x4_PLTT_IDX(from), sz >> 1);

            pTex->tex4x4Info.flag |= NNS_G3D_RESTEX4x4_LOADED;
        }
    }

    if (exec_begin_end) {
        GX_EndLoadTex();
    }
}
