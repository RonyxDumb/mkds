#pragma once

#include "types.h"
#include "00/Lib/NitroWiFi/code_021a6fb4.h"

s32 SOCLi_ListenAcceptCallBack(SOCLiCommandPacket *packet);
s32 SOCL_ListenAccept(SOCLSocket *socket, u16 *remotePortOut, u32 *remoteIpOut);
s32 SOCL_Accept(SOCLSocket *socket, u16 *remotePortOut, u32 *remoteIpOut);
s32 SOCL_Listen(s32 socketHandle);
s32 SOCLi_BindCallBack(SOCLiCommandPacket *packet);
s32 SOCLi_ExecBindCommand(SOCLSocket *socket);
s32 SOCL_Connect(SOCLSocket *socket, u16 remotePort, u32 peerAddr);
s32 SOCL_Bind(SOCLSocket *socket, u16 ownPort);
