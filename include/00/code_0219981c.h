#pragma once

#include "types.h"

typedef struct Gt2Connection Gt2Connection;

typedef struct GTI2IncomingBufferMessage {
    /* 00 */ s32 mStart;
    /* 04 */ s32 mLen;
    /* 08 */ s32 mType;
    /* 0c */ u16 mSerialNumber;
} GTI2IncomingBufferMessage;

u32 gti2DeliverHoldMessages(Gt2Connection *connection);
void gti2RemoveHoldMessage(Gt2Connection *connection, GTI2IncomingBufferMessage *message, s32 index);
u32 gti2BufferIncomingMessage(Gt2Connection *connection, s32 type, u32 serialNumber, const u8 *message, s32 len,
                              s32 *overflow);
