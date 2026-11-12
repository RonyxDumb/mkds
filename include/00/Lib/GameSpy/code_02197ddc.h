#pragma once

#include "types.h"

typedef struct Gt2Buffer Gt2Buffer;

void RemoveBufferBytes(Gt2Buffer *buffer, int start, int shortenBy);
void AppendBufferBytes(Gt2Buffer *buffer, const u8 *data, int len);
void AppendBufferU16(Gt2Buffer *buffer, s32 b);
void AppendBufferByte(Gt2Buffer *buffer, u8 b);
int GetBufferUnusedSize(Gt2Buffer *a);
u32 InitBuffer(Gt2Buffer *a, int b);
