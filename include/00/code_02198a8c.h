#pragma once

#include "types.h"
#include "00/code_02197e58.h"
#include "00/code_0219903c.h"

void gt2Think(Gt2Socket *socket);
void gt2CloseSocket(Gt2Socket *socket);
u32 gt2CreateSocket(Gt2Socket **socket, const char *localAddress, u32 outgoingBufferSize, u32 incomingBufferSize,
                    u32 callback);
int gti2Send(Gt2Connection *connection, u8 *message, int len, int reliable);
BOOL gti2ResendMessage(Gt2Connection *connection, GTI2OutgoingBufferMessage *message);
BOOL gti2SendClosedOnSocket(Gt2Socket *socket, u32 address, int port);
int gti2SendClosed(Gt2Connection *connection);
u32 gti2SendPong(u32 connection, u32 message, u32 len);
BOOL gti2SendNack(Gt2Connection *connection, u16 firstNumber, u16 lastNumber);
BOOL gti2SendAck(Gt2Connection *connection);
BOOL gti2SendAppUnreliable(Gt2Connection *connection, u8 *message, int len);
