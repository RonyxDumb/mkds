/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MI_DmaCopy32Async func_0214c990
#define MIi_CpuCopy32 Mem_CpuCopy32
#define sClrImgLCDCBlk SDK_data_021802f8
#define GXi_DmaId SDK_data_0216f074
#define GX_LoadClearImageDepth func_0214c214
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 sClrImgLCDCBlk;
extern u32 GXi_DmaId;
#pragma thumb off
void GX_LoadClearImageDepth(void *src, u32 size){
    GXi_DmaCopy32Async(GXi_DmaId, src, (void *)(sClrImgLCDCBlk + 0x20000), size, NULL, NULL);
}
