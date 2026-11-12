#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

s32 GpiReadKeyValue(GpConnection *connection, s8 *buffer, s32 *index, s8 *key, s8 *value);
u32 GpiCheckConnectComplete(GpConnection *connection, u32 sock, u32 *state);

typedef struct GpConnection GpConnection;

BOOL GpiGetValue(const char *command, const char *key, char *value, s32 len);
BOOL GpiReadError(GpConnection *connection, const char *input, s32 callErrorCallback);

void GpiCopyString(char *dest, const char *src, s32 len);

extern char gBufferAssertText[];
extern char gKeyAssertText[];
extern char gValueAssertText[];
extern char gParseErrorString[];
extern char gCommandAssertText[];
extern char data_ov000_021b3ae4[];
extern char gErrorKey[];
extern char gErrKey[];
extern char gGpErrmsgKey[];
extern char data_ov000_021b3b08[];

void gpiDebug(GpConnection *connection, const char *fmt, ...);
