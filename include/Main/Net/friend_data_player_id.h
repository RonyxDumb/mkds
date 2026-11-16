#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

u32 GetFriendDataPlayerId(const DWCAccFriendData *friendData);

extern u8 SDK_OVERLAYTABLE_DIGEST[20];
extern u8 OverlaySignatures[4][0x14];
