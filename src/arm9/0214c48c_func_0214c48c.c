/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GX_ResetBankForTexPltt func_02148ff0
#define sTexPltt SDK_data_021802f4
#define sTexPlttStartAddrTable SDK_data_021616bc
#define sTexPlttLCDCBlk SDK_data_021802f0
#define GX_BeginLoadTexPltt func_0214c48c
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern s32 sTexPltt;
extern const u16 sTexPlttStartAddrTable[8];
extern u32 sTexPlttLCDCBlk;
#pragma thumb off
void GX_BeginLoadTexPltt(){
    s32 temp = (s32)GX_ResetBankForTexPltt();
    sTexPltt = temp;
    sTexPlttLCDCBlk = (u32)(sTexPlttStartAddrTable[temp >> 4] << 0xC);
}
