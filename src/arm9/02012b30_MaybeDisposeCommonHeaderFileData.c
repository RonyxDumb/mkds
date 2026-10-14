/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G3dGetMdlSet Nsbmd_GetMDL0Block
#define NNS_G3dGetTex Nsbtx_GetTEX0Block
#define NNS_G3dReleaseMdlSet func_020100fc
#define NNS_G3dPlttReleasePlttKey func_020107e4
#define NNS_G3dTexReleaseTexKey Tex0_CleanGetKeys
#define NNS_GfdDefaultFuncFreePlttVram SDK_data_021619f8
#define NNS_GfdDefaultFuncFreeTexVram SDK_data_021619f0
#define NNS_G3dResDefaultRelease MaybeDisposeCommonHeaderFileData
#include <nnsys/g3d/util.h>
#include <nnsys/g3d/gecom.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>
#include <nnsys/g3d/anm.h>
#include <nnsys/g3d/glbstate.h>

#pragma thumb off
void NNS_G3dResDefaultRelease (void * pResData)
{
    u8 * binFile = (u8 *)pResData;
    BOOL failed = FALSE;

    NNS_G3D_NULL_ASSERT(pResData);

    switch (*(u32 *)&binFile[0]) {
    case NNS_G3D_SIGNATURE_NSBMD:
    {
        NNSG3dResTex * tex;
        NNSG3dResMdlSet * mdlSet = NNS_G3dGetMdlSet(pResData);
        NNS_G3D_NULL_ASSERT(mdlSet);
        tex = NNS_G3dGetTex((NNSG3dResFileHeader *) pResData);

        if (tex) {

            NNS_G3dReleaseMdlSet(mdlSet);
        }
    }

    case NNS_G3D_SIGNATURE_NSBTX:
    {
        NNSG3dResTex * tex;
        NNSG3dPlttKey plttKey;
        NNSG3dTexKey texKey, tex4x4Key;
        int status;
        tex = NNS_G3dGetTex((NNSG3dResFileHeader *) pResData);

        if (tex) {
            plttKey = NNS_G3dPlttReleasePlttKey(tex);
            NNS_G3dTexReleaseTexKey(tex, &texKey, &tex4x4Key);

            if (plttKey > 0) {
                status = NNS_GfdFreePlttVram(plttKey);
                NNS_G3D_ASSERTMSG(!status, "NNS_GfdFreePlttVram failed");
            }

            if (tex4x4Key > 0) {
                status = NNS_GfdFreeTexVram(tex4x4Key);
                NNS_G3D_ASSERTMSG(!status, "NNS_GfdFreeTexVram failed");
            }

            if (texKey > 0) {
                status = NNS_GfdFreeTexVram(texKey);
                NNS_G3D_ASSERTMSG(!status, "NNS_GfdFreeTexVram failed");
            }
        }
    }
    break;
    case NNS_G3D_SIGNATURE_NSBCA:
    case NNS_G3D_SIGNATURE_NSBVA:
    case NNS_G3D_SIGNATURE_NSBMA:
    case NNS_G3D_SIGNATURE_NSBTP:
    case NNS_G3D_SIGNATURE_NSBTA:
        break;
    default:
        NNS_G3D_ASSERTMSG(1==0, "unknown file signature: '%c%c%c%c' found.\n",
                          binFile[0], binFile[1], binFile[2], binFile[3]);
        break;
    };
}
