#pragma once

#include "types.h"

typedef struct SOCLSocket SOCLSocket;

s32 SOCLi_ExecReadCommand(SOCLSocket *socket, u8 *buffer, s32 length, u16 *remotePort, u32 *peerAddr);
