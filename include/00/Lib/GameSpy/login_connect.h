#pragma once

#include "types.h"
#include "narrow_string_functions.h"
#include "00/Lib/GameSpy/send_buffer.h"
#include "00/Lib/GameSpy/profile_empty_check.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "00/Lib/wifi_library_globals.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "00/Lib/GameSpy/reply_parse.h"
#include "00/Lib/GameSpy/error_set.h"
#include "00/Lib/DWC/memory_allocator.h"
#include "00/Lib/GameSpy/error_message_set.h"
#include "text_to_number.h"
#include "00/Lib/GameSpy/profile_list.h"
#include "00/Lib/GameSpy/md5_base64_encode.h"
#include "00/Lib/GameSpy/connect_operation.h"
#include "00/Lib/GameSpy/unique_nick_transfer.h"
#include "00/Lib/GameSpy/profile_info.h"
#include "00/Lib/GameSpy/dynamic_array.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/socket_calls.h"
#include "00/Lib/GameSpy/query_reporting.h"
#include "00/Lib/GameSpy/profile_walk.h"

// Object of 0x308 bytes that GpiStartConnect allocates and fills.
typedef struct GPIConnectData {
    /* 000 */ char mServerChallenge[0x80];
    /* 080 */ char mUserChallenge[0x21];
    /* 0a1 */ char mPasswordHash[0x21];
    /* 0c2 */ s8 mAuthtoken[0x100];
    /* 1c2 */ s8 mPartnerChallenge[0x100];
    /* 2c2 */ s8 mCdkey[0x41];
    /* 303 */ u8 mUnk_303;
    /* 304 */ s32 mNewUser;
} GPIConnectData;

void randomString(char *buffer, s32 numChars);
u32 GpiWriteLogin(GpConnection *connection, GPIConnectData *data);
u32 GpiStartConnect(GpConnection *connection, const char *nick, const char *uniquenick, const char *email,
                    const char *password, const s8 *authtoken, const s8 *partnerchallenge, const char *cdkey,
                    s32 firewall, s32 newuser, s32 blocking, GpiCallbackFn callback, s32 param);
u32 GpiOpenSockets(GpConnection *connection, GpiOperation *operation);
