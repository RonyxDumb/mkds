/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MI_DmaCopy32Async func_0214c990
#define MIi_CpuCopy32 Mem_CpuCopy32
#define sTexPlttLCDCBlk SDK_data_021802d0
#define GXi_DmaId SDK_data_0216f074
#define GX_LoadTexPltt func_0214b558
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 sTexPlttLCDCBlk;
extern u32 GXi_DmaId;
#pragma thumb off
void GX_LoadTexPltt(void *src, u32 offset, u32 size){
    GXi_DmaCopy32Async(GXi_DmaId, src, (void *)(sTexPlttLCDCBlk + offset), size, NULL, NULL);
}
