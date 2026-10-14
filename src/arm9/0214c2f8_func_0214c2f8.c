/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GX_ResetBankForClearImage func_02148fdc
#define sClrImg SDK_data_021802e8
#define sClrImgLCDCBlk SDK_data_021802f8
#define GX_BeginLoadClearImage func_0214c2f8
#include "nitro/types.h"
#include "gx.h"
#include "code32.h"
extern s32 sClrImg;
extern u32 sClrImgLCDCBlk;
#pragma thumb off
void GX_BeginLoadClearImage(){
    u32 temp = GX_ResetBankForClearImage();
    sClrImg = (s32)temp;
    switch (temp)
    {
    case 2:
    case 3:
        sClrImgLCDCBlk = 0x6800000;
        return;
    case 8:
    case 12:
        sClrImgLCDCBlk = 0x6840000;
        return;
    case 1:
        sClrImgLCDCBlk = 0x67E0000;
        return;
    case 4:
        sClrImgLCDCBlk = 0x6820000;
    }
}
