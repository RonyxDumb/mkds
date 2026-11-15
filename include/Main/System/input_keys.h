#pragma once

#include "types.h"
#include "Main/Menu/data_02175628.h"

// Byte stream at gKeyStream: mUnk_00 to mUnk_04 bound the buffer, mUnk_08 is the position, mUnk_0c the highest
// position written, mUnk_14 the element size, mUnk_18 the mask of bits ReadKeyBitsFromStream and WriteKeyBitsToStream
// move.
typedef struct KeyStream {
    /* 00 */ u8 *mStart;
    /* 04 */ u8 *mEnd;
    /* 08 */ u8 *mPosition;
    /* 0c */ u8 *mHighestWritten;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mElementSize;
    /* 18 */ u16 mKeyMask;
} KeyStream;

// Frames a key is held before it repeats, and frames between two repeats (KeysInputSlot defaults).
#define KEYS_REPEAT_DELAY_FRAMES 0x14
#define KEYS_REPEAT_INTERVAL_FRAMES 8

// Origin argument of SeekKeyStream: the start of the stream, the current position, the highest position written.
#define KEY_STREAM_SEEK_START 0
#define KEY_STREAM_SEEK_CURRENT 1
#define KEY_STREAM_SEEK_END 2

u32 ReadKeyBitsFromStream(void);
void WriteKeyBitsToStream(u32 keys);
void SeekKeyStream(u32 count, u32 origin);
void ReadKeysIntoInputSlot(void);
void ResetKeysInputSlot(void);
void StartupResetKeysInputSlot(void);

extern KeyStream gKeyStream;
extern InputSlotHead gKeysInputSlot;
