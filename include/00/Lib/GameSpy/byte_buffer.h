#pragma once

#include "types.h"

typedef struct GTI2Buffer GTI2Buffer;

void gti2BufferShorten(GTI2Buffer *buffer, int start, int shortenBy);
void gti2BufferWriteData(GTI2Buffer *buffer, const u8 *data, int len);
void gti2BufferWriteUShort(GTI2Buffer *buffer, s32 value);
void gti2BufferWriteByte(GTI2Buffer *buffer, u8 byteValue);
int gti2GetBufferFreeSpace(GTI2Buffer *gt2Buffer);
u32 gti2AllocateBuffer(GTI2Buffer *gt2Buffer, int size);
