#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"
#include "00/Lib/DWC/login_close.h"
#include "00/Lib/wifi_library_work_objects.h"
#include "00/Lib/DWC/buddy_request_callbacks.h"
#include "00/Lib/DWC/buddy_friend_list.h"
#include "00/Lib/GameSpy/connection_accept_reject.h"
#include "00/Lib/DWC/friends_match_session.h"

// Address and byte-swapped port of a peer, built by DWCi_ProcessRecvMatchCommand for DWCi_NNCompletedCallback.
typedef struct PeerAddress {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mPort;
    /* 04 */ u32 mAddress;
} PeerAddress;

s32 DWCi_ProcessRecvMatchCommand(s32 command, u32 profileId, u32 address, u16 port, u32 *values, s32 valueCount);
