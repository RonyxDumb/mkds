/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MIi_CpuCopy16 CopyMemory16
#define GXi_DmaId SDK_data_0216f074
#define GX_LoadOBJPltt CopySomePaletteData
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 GXi_DmaId;
#pragma thumb off
void GX_LoadOBJPltt(void *src, u32 offset, u32 size){
    GXi_DmaCopy16(GXi_DmaId, src, (void *)(0x5000200 + offset), size);
}
