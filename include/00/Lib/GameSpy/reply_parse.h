#pragma once

#include "types.h"

typedef struct GPConnection GPConnection;

s32 gpiReadKeyAndValue(GPConnection *connection, s8 *buffer, s32 *index, char *key, char *value);
u32 gpiCheckSocketConnect(GPConnection *connection, u32 sock, u32 *state);

typedef struct GPConnection GPConnection;

BOOL gpiValueForKey(const char *command, const char *key, char *value, s32 len);
BOOL gpiCheckForError(GPConnection *connection, const char *input, s32 callErrorCallback);

void CopyStringWithTerminator(char *dest, const char *src, s32 len);


void gpiDebug(GPConnection *connection, const char *fmt, ...);
