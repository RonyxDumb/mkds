#include "00/code_02188de4.h"
#include "00/code_02188ec0.h"
#include "00/code_0218a64c.h"
#include "code_0214d018.h"
#include "00/code_0218a67c.h"

u32 FillApWepKey(struct ACWORK *work, u32 type, WCMWepDesc *wepKey) {
    DWCMemPage *userInfo;

    userInfo = work->mUserInfo;
    switch (type) {
        case 2:
            userInfo++;
        case 1:
            userInfo++;
        case 0:
            wepKey->mUnk_00 = userInfo->mWepMode;
            MI_CpuCopy8(userInfo->mWepKeys, wepKey->mUnk_02, 0x50);
            break;
        case 5:
            userInfo++;
        case 4:
            userInfo++;
        case 3:
            wepKey->mUnk_00 = 1;
            MI_CpuCopy8(userInfo->mWep2, wepKey->mUnk_02, 0x14);
            wepKey->mUnk_02[0x14] = 0;
            break;
        case 6:
            wepKey->mUnk_00 = 2;
            DWCi_AC_GetNintendoUSBWepKey(work->mBssDesc[work->mConnectNo].mUnk_0c, wepKey->mUnk_02);
            break;
        case 7:
            wepKey->mUnk_00 = 2;
            DWCi_AC_GetNintendoShopWepKey(work->mBssDesc[work->mConnectNo].mUnk_0c, wepKey->mUnk_02);
            break;
        case 8:
        case 9:
            break;
    }
    if (wepKey->mUnk_00 != 0) {
        return 1;
    }
    return 0;
}
