#pragma once

#include "types.h"
#include "code_02139f70.h"
#include "00/Lib/GameSpy/code_021906e4.h"
#include "00/Lib/GameSpy/code_021947e4.h"
#include "00/Lib/DWC/connection_error_strings.h"
#include "00/Lib/wifi_library_globals.h"
#include "string.h"
#include "code_02134398.h"
#include "00/Lib/GameSpy/code_02196594.h"
#include "00/Lib/GameSpy/code_021965a0.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/Lib/GameSpy/code_02196590.h"
#include "code_0213a460.h"
#include "00/Lib/GameSpy/code_021948f8.h"
#include "00/Lib/GameSpy/code_0218e0fc.h"
#include "00/Lib/GameSpy/code_02191200.h"
#include "00/Lib/GameSpy/code_02196480.h"
#include "00/Lib/GameSpy/code_02192d64.h"
#include "00/Lib/GameSpy/code_0218d818.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "00/Lib/GameSpy/gpiProfile.h"

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
