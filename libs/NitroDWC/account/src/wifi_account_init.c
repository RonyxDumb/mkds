#include "wifi_account_init.h"
#include "wifi_id_and_backup_check.h"
#include "friend_data_account_fields.h"
#include "startup_entry.h"
#include "build_info_layout.h"
#include "Main/Save/nvram_new_wifi_info.h"

#pragma thumb on

u32 DWC_Init(u8 *work) {
    u32 created;
    s32 result;

    created = 0;
    OSi_ReferSymbol(BuildInfo.mDwc);
    result = DWC_BM_Init(work);
    if (DWC_Auth_CheckWiFiIDNeedCreate() != 0) {
        WriteNewWiFiInfoToNvram((u32) work);
        created = 1;
    }
    if (result < 0) {
        if (created != 0) {
            return 2;
        }
        return 3;
    }
    if (created != 0) {
        return 1;
    }
    return 0;
}

BOOL DWCi_Acc_SetMaskBits(u32 *ptr, u32 data, u32 shift, u32 mask) {
    if ((data & ~mask) != 0) {
        return 0;
    }
    *ptr = *ptr & ~(mask << shift) | data << shift;
    return 1;
}

u64 DWCi_Acc_GetUserId(const DWCAccFriendData *loginid) {
    return (u64) (loginid->mIdData & ACCOUNT_USER_ID_HIGH_MASK) << 32 | loginid->mUserIdLo32;
}

#pragma thumb off
