#pragma once

#include "types.h"
#include "00/Lib/GameSpy/code_0218f960.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/code_021965a0.h"

u32 GpiSendBuffer(GpConnection *connection, s32 sock, GpiBuffer *outputBuffer, u32 *bytesSentOut, s32 discardSent,
                  const s8 *label);
u32 GpiReceiveBuffer(GpConnection *connection, s32 sock, GpiBuffer *inputBuffer, s32 *bytesRead, u32 *connClosed,
                     const s8 *label);
u32 GpiPeerSendString(GpConnection *connection, GpiPeer *gpiPeer, const char *string);
u32 GpiPeerSendBytes(GpConnection *connection, GpiPeer *gpiPeer, const char *data, s32 byteCount);
u32 GpiPeerSendByte(GpConnection *connection, GpiPeer *gpiPeer, s8 byte);
u32 GpiSendBytes(GpConnection *connection, s32 sock, const void *data, s32 dataLen, s32 *wasClosed, s32 *bytesSent,
                 const s8 *label);
u32 GpiAppendBufferNumber(void *connection, void *outputBuffer, u32 number);
u32 GpiAppendBufferString(void *connection, void *outputBuffer, const void *string);
u32 GpiAppendBufferBytes(void *connection, GpiBuffer *outputBuffer, const void *string, s32 stringLen);
u32 GpiAppendBufferByte(void *connection, GpiBuffer *outputBuffer, s32 byte);
