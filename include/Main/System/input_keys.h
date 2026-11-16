#pragma once

#include "types.h"
#include "Main/System/input_slots.h"

// A byte stream of pad key bits (g_GlobalIG): buffer bounds, position, highest position written, element size and mask.
typedef struct KeyStream {
    /* 00 */ u8 *mStart;
    /* 04 */ u8 *mEnd;
    /* 08 */ u8 *mPosition;
    /* 0c */ u8 *mHighestWritten;
    /* 10 */ u32 mFlipX;
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

u32 GetSomeInput(void);
void WriteKeyBitsToStream(u32 keys);
void SeekKeyStream(u32 count, u32 origin);
void UpdateInput(void);
void InitializeGlobalG_2(void);
void InitializeGlobalG_M1(void);

extern KeyStream g_GlobalIG;
extern InputSlotHead g_GlobalG;
