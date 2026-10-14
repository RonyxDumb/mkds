/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GX_ResetBankForBGExtPltt func_0214903c
#define sBGExtPltt SDK_data_021802e0
#define sBGExtPlttLCDCBlk SDK_data_021802dc
#define sBGExtPlttLCDCOffset SDK_data_021802d8
#define GX_BeginLoadBGExtPltt func_0214b720
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern s32 sBGExtPltt;
extern u32 sBGExtPlttLCDCBlk;
extern u32 sBGExtPlttLCDCOffset;
#pragma thumb off
void GX_BeginLoadBGExtPltt(){
    sBGExtPltt = (s32)GX_ResetBankForBGExtPltt();
    switch (sBGExtPltt)
    {
    case 0: //needed to match
        break;
    case 0x10:
        sBGExtPlttLCDCBlk = 0x06880000;
        sBGExtPlttLCDCOffset = 0x0;
        break;
    case 0x40:
        sBGExtPlttLCDCBlk = 0x06894000;
        sBGExtPlttLCDCOffset = 0x4000;
        break;
    case 0x20:
    case 0x60:
        sBGExtPlttLCDCBlk = 0x06890000;
        sBGExtPlttLCDCOffset = 0x0;
        break;
    }
}
