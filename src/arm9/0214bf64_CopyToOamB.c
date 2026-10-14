/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MIi_CpuCopy32 Mem_CpuCopy32
#define GXi_DmaId SDK_data_0216f074
#define GXS_LoadOAM CopyToOamB
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 GXi_DmaId;
#pragma thumb off
void GXS_LoadOAM(void *src, u32 offset, u32 size){
    GXi_DmaCopy32(GXi_DmaId, src, (void *)(0x7000400 + offset), size);
}
