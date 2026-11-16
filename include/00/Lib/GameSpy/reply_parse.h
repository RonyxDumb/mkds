#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

s32 gpiReadKeyAndValue(GpConnection *connection, s8 *buffer, s32 *index, char *key, char *value);
u32 gpiCheckSocketConnect(GpConnection *connection, u32 sock, u32 *state);

typedef struct GpConnection GpConnection;

BOOL gpiValueForKey(const char *command, const char *key, char *value, s32 len);
BOOL gpiCheckForError(GpConnection *connection, const char *input, s32 callErrorCallback);

void CopyStringWithTerminator(char *dest, const char *src, s32 len);


void gpiDebug(GpConnection *connection, const char *fmt, ...);
