#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

u64 FriendCode_GetSomePackedValue_from_thumb(const DWCAccFriendData *userdata);
BOOL FriendCode_SetFlagsImpl_from_thumb(u32 *ptr, u32 data, u32 shift, u32 mask);
u32 MaybeInitializeDwc_from_thumb(u8 *work);
