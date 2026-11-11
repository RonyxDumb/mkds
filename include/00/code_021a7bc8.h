#pragma once

#include "types.h"

typedef struct SOCLSocket SOCLSocket;

s32 SOCLi_ExecReadCommand(SOCLSocket *socket, unsigned int buffer, unsigned int length, unsigned int remotePort,
                          unsigned int peerAddr);
