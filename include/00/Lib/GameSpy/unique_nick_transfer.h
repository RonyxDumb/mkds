#pragma once

#include "types.h"

#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/GameSpy/presence_api.h"

typedef struct GPITransferID GPITransferID;

s32 gpiSendTransferReply(GPConnection *connection, GPITransferID *transferID, GPIPeer *peer, s32 result,
                         const char *msg);
s32 gpiProcessRegisterUniqueNick(GPConnection *connection, GPIOperation *operation, const char *input);
