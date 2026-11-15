#pragma once

#include "types.h"

#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"

typedef struct GpiTransferId GpiTransferId;

s32 gpiSendTransferReply(GpConnection *connection, GpiTransferId *transferID, GpiPeer *peer, s32 result,
                         const char *msg);
s32 gpiProcessRegisterUniqueNick(GpConnection *connection, GpiOperation *operation, const char *input);
