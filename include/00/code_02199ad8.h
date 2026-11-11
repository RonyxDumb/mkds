#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;

u32 gti2HandleClose(Gt2Connection *connection);
u32 gti2HandleReject(Gt2Connection *connection, void *message, u32 length);
u32 gti2HandleAccept(Gt2Connection *connection);
u32 gti2HandleClientResponse(Gt2Connection *connection, const u8 *message, int length);
u32 gti2HandleServerChallenge(Gt2Connection *connection, const u8 *message, int length);
u32 gti2HandleClientChallenge(Gt2Connection *connection, const u8 *message, int length);
u32 gti2HandleAppReliable(Gt2Connection *connection, const u8 *message, u32 length);
u32 gti2HandleAppUnreliable(Gt2Connection *connection, const u8 *message, s32 length);
u32 gti2HandleESN(Gt2Connection *connection, u32 esn);
