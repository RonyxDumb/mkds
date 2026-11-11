#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;
typedef struct GpiProfile GpiProfile;
typedef struct GpiBuffer GpiBuffer;

u32 gpiSendAuthBuddyRequest(GpConnection *connection, GpiProfile *profile);
u32 gpiClipBufferToPosition(GpConnection *connection, GpiBuffer *buffer);
u32 gpiReadMessageFromBuffer(GpConnection *connection, GpiBuffer *inputBuffer, s32 *message, s32 *type, s32 *plen);
