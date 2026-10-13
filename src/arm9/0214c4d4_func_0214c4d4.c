/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GX_SetBankForTex func_021495e4
#define GXi_DmaId SDK_data_0216f074
#define sTex SDK_data_021802fc
#define sSzTexBlk1 SDK_data_02180304
#define sTexLCDCBlk2 SDK_data_02180300
#define sTexLCDCBlk1 SDK_data_021802ec
#define GX_EndLoadTex func_0214c4d4
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 GXi_DmaId;
extern s32 sTex;
extern u32 sSzTexBlk1;
extern u32 sTexLCDCBlk2;
extern u32 sTexLCDCBlk1;
#pragma thumb off
void GX_EndLoadTex(){
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForTex(sTex);
    sSzTexBlk1 = 0x0;
    sTexLCDCBlk2 = 0x0;
    sTexLCDCBlk1 = 0x0;
    sTex = 0x0;
}
