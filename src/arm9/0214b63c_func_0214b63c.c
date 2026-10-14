/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GX_SetBankForBGExtPltt func_021498a0
#define GXi_DmaId SDK_data_0216f074
#define sBGExtPltt SDK_data_021802e0
#define sBGExtPlttLCDCBlk SDK_data_021802dc
#define sBGExtPlttLCDCOffset SDK_data_021802d8
#define GX_EndLoadBGExtPltt func_0214b63c
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 GXi_DmaId;
extern s32 sBGExtPltt;
extern u32 sBGExtPlttLCDCBlk;
extern u32 sBGExtPlttLCDCOffset;
#pragma thumb off
void GX_EndLoadBGExtPltt(){
    GXi_WaitDma(GXi_DmaId);
    GX_SetBankForBGExtPltt(sBGExtPltt);
    sBGExtPltt = 0x0;
    sBGExtPlttLCDCBlk = 0x0;
    sBGExtPlttLCDCOffset = 0x0;
}
