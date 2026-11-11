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
            wepKey->mMode = userInfo->mWepMode;
            MI_CpuCopy8(userInfo->mWepKeys, wepKey->mKey, 0x50);
            break;
        case 5:
            userInfo++;
        case 4:
            userInfo++;
        case 3:
            wepKey->mMode = 1;
            MI_CpuCopy8(userInfo->mWep2, wepKey->mKey, 0x14);
            wepKey->mKey[0x14] = 0;
            break;
        case 6:
            wepKey->mMode = 2;
            DWCi_AC_GetNintendoUSBWepKey(work->mBssDesc[work->mConnectNo].mUnk_0c, wepKey->mKey);
            break;
        case 7:
            wepKey->mMode = 2;
            DWCi_AC_GetNintendoShopWepKey(work->mBssDesc[work->mConnectNo].mUnk_0c, wepKey->mKey);
            break;
        case 8:
        case 9:
            break;
    }
    if (wepKey->mMode != 0) {
        return 1;
    }
    return 0;
}
