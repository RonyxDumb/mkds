#pragma once

#include "types.h"

typedef struct DWCAccFriendData DWCAccFriendData;

u32 FriendCode_GetCrcChecksum_from_thumb(const DWCAccFriendData *friendData);

extern u8 g_SomeDigest[20];
extern u8 OverlaySignatures[4][0x14];
