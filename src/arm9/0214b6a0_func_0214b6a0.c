/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MI_DmaCopy32Async func_0214c990
#define MIi_CpuCopy32 Mem_CpuCopy32
#define sBGExtPlttLCDCBlk SDK_data_021802dc
#define sBGExtPlttLCDCOffset SDK_data_021802d8
#define GXi_DmaId SDK_data_0216f074
#define GX_LoadBGExtPltt func_0214b6a0
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 sBGExtPlttLCDCBlk;
extern u32 sBGExtPlttLCDCOffset;
extern u32 GXi_DmaId;
#pragma thumb off
void GX_LoadBGExtPltt(void *src, u32 offset, u32 size){
    GXi_DmaCopy32Async(GXi_DmaId, src, (void *)(sBGExtPlttLCDCBlk + offset - sBGExtPlttLCDCOffset), size, NULL, NULL);
}
