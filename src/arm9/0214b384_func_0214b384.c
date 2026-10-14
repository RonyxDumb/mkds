/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MI_DmaCopy32Async func_0214c990
#define MIi_CpuCopy32 Mem_CpuCopy32
#define GXi_DmaId SDK_data_0216f074
#define GXS_LoadOBJExtPltt func_0214b384
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 GXi_DmaId;
#pragma thumb off
void GXS_LoadOBJExtPltt(void *src, u32 offset, u32 size){
    GXi_DmaCopy32Async(GXi_DmaId, src, (void *)(0x068A0000 + offset), size, NULL, NULL);
}
