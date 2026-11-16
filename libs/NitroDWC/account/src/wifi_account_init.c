#include "wifi_account_init.h"
#include "wifi_id_and_backup_check.h"
#include "friend_data_account_fields.h"
#include "startup_entry.h"
#include "build_info_layout.h"
#include "Main/Save/nvram_new_wifi_info.h"

#pragma thumb on

u32 MaybeInitializeDwc_from_thumb(u8 *work) {
    u32 created;
    s32 result;

    created = 0;
    Os_ReferSymbol(g_StartModuleParams.mDwc);
    result = StructDC_SomeFn_2_from_thumb(work);
    if (DWC_Auth_CheckWiFiIDNeedCreate() != 0) {
        StructDC_SomeFn_4_from_thumb((u32) work);
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

BOOL FriendCode_SetFlagsImpl_from_thumb(u32 *ptr, u32 data, u32 shift, u32 mask) {
    if ((data & ~mask) != 0) {
        return 0;
    }
    *ptr = *ptr & ~(mask << shift) | data << shift;
    return 1;
}

u64 FriendCode_GetSomePackedValue_from_thumb(const DWCAccFriendData *userdata) {
    return (u64) (userdata->mIdData & ACCOUNT_USER_ID_HIGH_MASK) << 32 | userdata->mUserIdLo;
}

#pragma thumb off
