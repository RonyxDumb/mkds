#pragma once

#include "types.h"

#define PAD_KEY_B 0x2
#define PAD_KEY_DOWN 0x80
#define PAD_KEY_L 0x200
#define PAD_KEY_LEFT 0x20
#define PAD_KEY_R 0x100
#define PAD_KEY_RIGHT 0x10
#define PAD_KEY_START 0x8
#define PAD_KEY_UP 0x40
#define PAD_KEY_X 0x400
#define PAD_KEY_Y 0x800
// Bits of the pad key word (the slots' field0, mBits, mRepeatBits ... and the keyboard's key word): one bit per key.
#define PAD_KEY_A 0x1
// The four direction keys together.
#define PAD_KEY_DIRECTIONS 0xf0
// Slot of gInputUnits that the code addresses through a constant.
typedef enum InputSlotIndex { UNK_02175628_INDEX_8 = 8 } InputSlotIndex;

typedef struct KeyRecordingBuffer {
    /* 000 */ u32 field0;
    /* 004 */ u8 mPairs[0xdc8];
} KeyRecordingBuffer;

// Pad key bits recorded as (bits, repeat count) byte pairs, and played back from them.
typedef struct KeyRecording {
    /* 00 */ KeyRecordingBuffer *mBuffer;
    /* 04 */ u16 mPairIndex;
    /* 06 */ u16 mRepeatCount;
// 0 idle, 1 recording, 2 playing, 3 buffer full.
    /* 08 */ s32 mStatus;
    /* 0c */ BOOL fieldC;
    /* 10 */ u8 field10[0x4c];
} KeyRecording;

// One 0x5c-byte element of the array at gInputUnits.
typedef struct InputSlot {
    /* 00 */ u16 mPressedBits;
    /* 02 */ u16 mBits;
    /* 04 */ u16 mClearedBits;
    // The masked bits on the calls where the repeat fires: the first call of a hold (state 0 -> 1), then after
    // mRepeatDelayLimit calls, then every mRepeatIntervalLimit calls; 0 on other calls.
    /* 06 */ u16 mRepeatBits;
    /* 08 */ u16 mRepeatState;
    // Calls with a masked bit held since the last fire; compared with mRepeatDelayLimit in state 1 and
    // mRepeatIntervalLimit in state 2.
    /* 0a */ u16 mRepeatCallCount;
    /* 0c */ u16 mRepeatMask;
    /* 0e */ u16 mRepeatDelayLimit;
    /* 10 */ u16 mRepeatIntervalLimit;
    /* 12 */ u16 mHoldLong;
    /* 14 */ u16 field14;
    /* 16 */ u8 field16[0x2];
    /* 18 */ u64 mHoldStartTick;
    /* 20 */ s32 field20;
    /* 24 */ s32 field24;
    /* 28 */ void *field28;
    /* 2c */ u16 field2C;
    /* 2e */ u16 field2E;
    /* 30 */ s32 field30;
    /* 34 */ u8 field34[0x8];
    /* 3c */ s32 mSourceKind;
    /* 40 */ u16 mRequestedBits;
    /* 42 */ u16 mBitMask;
    /* 44 */ s32 field44;
    /* 48 */ u16 mPairX;
    /* 4a */ u16 mPairY;
    /* 4c */ u16 mHasPair;
    /* 4e */ u16 mValidity;
    /* 50 */ u16 mPrevPairX;
    /* 52 */ u16 mPrevPairY;
    /* 54 */ u16 mPrevHasPair;
    /* 56 */ u16 mPrevValidity;
    /* 58 */ u16 mNoPairCount;
    /* 5a */ u8 field5A;
    /* 5b */ u8 field5B;
} InputSlot;

// The 0x14 bytes at 0x48 of an element of gInputUnits (the same bytes as its field48 to field5B).
typedef struct InputSlotPair {
    /* 00 */ u16 mPairX;
    /* 02 */ u16 mPairY;
    /* 04 */ u16 mHasPair;
    /* 06 */ u16 mValidity;
    /* 08 */ u16 mPrevPairX;
    /* 0a */ u16 mPrevPairY;
    /* 0c */ u16 mPrevHasPair;
    /* 0e */ u16 mPrevValidity;
    /* 10 */ u16 mNoPairCount;
    /* 12 */ u8 field12[0x2];
} InputSlotPair;

extern InputSlot data_0217562c[];

extern InputSlot data_02175680[];

extern InputSlot data_0217567c[];

extern InputSlot data_02175674[];

extern InputSlot data_02175672[];

extern InputSlot data_02175670[];

extern InputSlot gInputUnits[];
