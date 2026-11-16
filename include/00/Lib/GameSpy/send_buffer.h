#pragma once

#include "types.h"
#include "00/Lib/GameSpy/buddy_messages.h"
#include "00/Lib/wifi_library_globals.h"
#include "00/Lib/GameSpy/error_set.h"

u32 gpiSendFromBuffer(GPConnection *connection, s32 sock, GPIBuffer *outputBuffer, u32 *bytesSentOut, s32 discardSent,
                  const s8 *label);
u32 gpiRecvToBuffer(GPConnection *connection, s32 sock, GPIBuffer *inputBuffer, s32 *bytesRead, u32 *connClosed,
                     const s8 *label);
u32 gpiSendOrBufferString(GPConnection *connection, GPIPeer *gpiPeer, const char *string);
u32 gpiSendOrBufferStringLen(GPConnection *connection, GPIPeer *gpiPeer, const char *data, s32 byteCount);
u32 gpiSendOrBufferChar(GPConnection *connection, GPIPeer *gpiPeer, s8 byte);
u32 gpiSendData(GPConnection *connection, s32 sock, const void *data, s32 dataLen, s32 *wasClosed, s32 *bytesSent,
                 const s8 *label);
u32 gpiAppendIntToBuffer(void *connection, void *outputBuffer, u32 number);
u32 gpiAppendStringToBuffer(void *connection, void *outputBuffer, const void *string);
u32 gpiAppendStringToBufferLen(void *connection, GPIBuffer *outputBuffer, const void *string, s32 stringLen);
u32 gpiAppendCharToBuffer(void *connection, GPIBuffer *outputBuffer, s32 byte);
