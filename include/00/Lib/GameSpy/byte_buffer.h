#pragma once

#include "types.h"

typedef struct Gt2Buffer Gt2Buffer;

void gti2BufferShorten(Gt2Buffer *buffer, int start, int shortenBy);
void gti2BufferWriteData(Gt2Buffer *buffer, const u8 *data, int len);
void gti2BufferWriteUShort(Gt2Buffer *buffer, s32 value);
void gti2BufferWriteByte(Gt2Buffer *buffer, u8 byteValue);
int gti2GetBufferFreeSpace(Gt2Buffer *gt2Buffer);
u32 gti2AllocateBuffer(Gt2Buffer *gt2Buffer, int size);
