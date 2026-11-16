#pragma once

#include "types.h"

// Byte stream at gKeyStream: field0 to field4 bound the buffer, field8 is the position, fieldC the highest
// position written, field14 the element size, field18 the mask of bits ReadKeyBitsFromStream and WriteKeyBitsToStream
// move.
typedef struct KeyStream {
    /* 00 */ u8 *mStart;
    /* 04 */ u8 *mEnd;
    /* 08 */ u8 *mPosition;
    /* 0c */ u8 *mHighestWritten;
    /* 10 */ u32 field10;
    /* 14 */ u32 mElementSize;
    /* 18 */ u16 mKeyMask;
} KeyStream;

extern KeyStream gKeyStream;

u32 ReadKeyBitsFromStream(void);
void WriteKeyBitsToStream(u32 keys);
void SeekKeyStream(u32 count, u32 origin);
void ReadKeysIntoInputSlot(void);
void InitializeGlobalG_2(void);
void InitializeGlobalG_M1(void);
