/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GX_BeginLoadTexPltt func_0214c48c
#define GX_LoadTexPltt SomeDmaCopy_0
#define GX_EndLoadTexPltt func_0214c3c0
#define NNS_G3dPlttLoad Tex0Block_MaybeCopyPaletteToMem
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/anm.h>
#include <nnsys/g3d/binres/res_struct.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#pragma thumb off
void NNS_G3dPlttLoad (NNSG3dResTex * pTex, BOOL exec_begin_end)
{
    NNS_G3D_NULL_ASSERT(pTex);
    NNS_G3D_WARNING(!(pTex->plttInfo.flag & NNS_G3D_RESPLTT_LOADED),
                    "NNS_G3dPlttLoad: texture already loaded");

    if (exec_begin_end) {
        GX_BeginLoadTexPltt();
    }

    {
        u32 sz;
        const void * pData;
        u32 from;

        sz = (u32)pTex->plttInfo.sizePltt << 3;
        pData = NNS_G3dGetPlttData(pTex);
        from = NNS_GfdGetTexKeyAddr(pTex->plttInfo.vramKey);

        GX_LoadTexPltt(pData, from, sz);

        pTex->plttInfo.flag |= NNS_G3D_RESPLTT_LOADED;
    }

    if (exec_begin_end) {
        GX_EndLoadTexPltt();
    }
}
