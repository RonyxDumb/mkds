/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GX_ResetBankForOBJExtPltt func_02149018
#define sOBJExtPltt SDK_data_021802d4
#define sOBJExtPlttLCDCBlk SDK_data_021802d0
#define GX_BeginLoadOBJExtPltt func_0214b5cc
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern s32 sOBJExtPltt;
extern u32 sOBJExtPlttLCDCBlk;
#pragma thumb off
void GX_BeginLoadOBJExtPltt(){
    sOBJExtPltt = (s32)GX_ResetBankForOBJExtPltt();
    switch (sOBJExtPltt)
    {
    case 0: //needed to match
        break;
    case 0x40:
        sOBJExtPlttLCDCBlk = 0x06894000;
        break;
    case 0x20:
        sOBJExtPlttLCDCBlk = 0x06890000;
        break;
    }
}
