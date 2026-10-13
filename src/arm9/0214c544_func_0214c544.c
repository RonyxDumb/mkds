/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MIi_CpuCopy32 Mem_CpuCopy32
#define MI_DmaCopy32Async func_0214c990
#define sTexLCDCBlk2 SDK_data_02180300
#define sTexLCDCBlk1 SDK_data_021802ec
#define sSzTexBlk1 SDK_data_02180304
#define GXi_DmaId SDK_data_0216f074
#define GX_LoadTex func_0214c544
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern u32 sTexLCDCBlk2;
extern u32 sTexLCDCBlk1;
extern u32 sSzTexBlk1;
extern u32 GXi_DmaId;
#pragma thumb off
void GX_LoadTex(void *src, u32 offset, u32 size){
    void *temp;
    if (!sTexLCDCBlk2)
    {
        temp = (void *)(sTexLCDCBlk1 + offset);
    }
    else
    {
        if ((offset + size) < sSzTexBlk1)
        {
            temp = (void *)(sTexLCDCBlk1 + offset);
        }
        else if (offset >= sSzTexBlk1)
        {
            temp = (void *)(sTexLCDCBlk2 + offset - sSzTexBlk1);
        }
        else
        {
            void *temp2 = (void *)sTexLCDCBlk2;
            u32 temp1 = sSzTexBlk1 - offset;
            temp = (void *)(sTexLCDCBlk1 + offset);
            GXi_DmaCopy32(GXi_DmaId, src, temp, temp1);
            GXi_DmaCopy32Async(GXi_DmaId, (void *)((u8 *)src + temp1), temp2, (size - temp1), NULL, NULL);
            return;
        }
    }
    GXi_DmaCopy32Async(GXi_DmaId, src, temp, size, NULL, NULL);
}
