#pragma once

#include "types.h"

#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/GameSpy/code_0218e8d4.h"

typedef struct GpiTransferId GpiTransferId;

s32 gpiSendTransferReply(GpConnection *connection, GpiTransferId *transferID, GpiPeer *peer, s32 result,
                         const char *msg);
s32 gpiProcessRegisterUniqueNick(GpConnection *connection, GpiOperation *operation, const char *input);
