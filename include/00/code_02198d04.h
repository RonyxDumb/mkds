#pragma once

#include "types.h"
#include "00/code_02197e58.h"

u32 gti2SendKeepAlive(Gt2Connection *connection);
u32 gti2SendClose(Gt2Connection *connection);
u32 gti2SendReject(Gt2Connection *connection, const void *message, int len);
u32 gti2SendAccept(Gt2Connection *connection);
u32 gti2SendClientResponse(Gt2Connection *connection, const u8 *response, const u8 *message, int len);
u32 gti2SendServerChallenge(Gt2Connection *connection, const u8 *response, const u8 *challenge);
u32 gti2SendClientChallenge(Gt2Connection *connection, const void *challenge);
u32 gti2SendAppReliable(Gt2Connection *connection, const u8 *message, int len);
u32 gti2EndReliableMessage(Gt2Connection *connection);
