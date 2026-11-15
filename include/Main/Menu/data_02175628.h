#pragma once
#include "types.h"
#include "tp.h" // TPData

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

// Bits of the pad key word (the slots' mPressedBits, mBits, mRepeatBits ... and the keyboard's key word): one bit per
// key.
#define PAD_KEY_A 0x1

#define PAD_KEY_SELECT 0x4

// A, B, X, Y, Select and Start: every key except the directions and the shoulder keys.
#define PAD_KEYS_NO_DIRECTION_OR_SHOULDER \
    (PAD_KEY_A | PAD_KEY_B | PAD_KEY_SELECT | PAD_KEY_START | PAD_KEY_X | PAD_KEY_Y)

// A, B, X, Y and both shoulder keys.
#define PAD_KEYS_FACE_AND_SHOULDER (PAD_KEY_A | PAD_KEY_B | PAD_KEY_X | PAD_KEY_Y | PAD_KEY_L | PAD_KEY_R)

// Both shoulder keys, Select and Start.
#define PAD_KEYS_SHOULDER_AND_MENU (PAD_KEY_L | PAD_KEY_R | PAD_KEY_SELECT | PAD_KEY_START)

// All twelve keys.
#define PAD_KEYS_ALL 0xfff

// Every key except Start.
#define PAD_KEYS_NO_START (PAD_KEYS_ALL & ~PAD_KEY_START)

// Every key except Select and Start.
#define PAD_KEYS_NO_SELECT_OR_START (PAD_KEYS_ALL & ~(PAD_KEY_SELECT | PAD_KEY_START))

// InputSlot.mBitMask after a reset: all twelve keys and bit 13 of the key word.
#define INPUT_SLOT_BIT_MASK_DEFAULT (PAD_KEYS_ALL | 0x2000)

// The four direction keys together.
#define PAD_KEY_DIRECTIONS 0xf0

// Slots of gInputSlots that the code addresses through a constant, named after the source kind each one gets.
typedef enum InputSlotIndex { INPUT_SLOT_PAD_OR_PARTICIPANT = 8, INPUT_SLOT_PAD_AND_TOUCH = 9 } InputSlotIndex;

typedef struct KeyRecordingBuffer {
    /* 000 */ u32 mPairByteCount;
    /* 004 */ u8 mPairs[0xdc8];
} KeyRecordingBuffer;

// KeyRecording.mStatus: idle, recording, playing back, recording stopped because the buffer is full.
#define KEY_RECORDING_IDLE 0
#define KEY_RECORDING_RECORDING 1
#define KEY_RECORDING_PLAYING 2
#define KEY_RECORDING_FULL 3

// Pad key bits recorded as (bits, repeat count) byte pairs, and played back from them.
typedef struct KeyRecording {
    /* 00 */ KeyRecordingBuffer *mBuffer;
    /* 04 */ u16 mPairIndex;
    /* 06 */ u16 mRepeatCount;
    /* 08 */ s32 mStatus;
    /* 0c */ BOOL mBufferCleared;
} KeyRecording;

// The 0x14 bytes at 0x48 of an element of gInputSlots (the same bytes as its mUnk_48 to mUnk_5b).
typedef struct InputSlotPair {
    union {
        TPData mPoint;
        struct {
            /* 00 */ u16 mPairX;
            /* 02 */ u16 mPairY;
            /* 04 */ u16 mHasPair;
            /* 06 */ u16 mValidity;
        };
    };
    union {
        TPData mPrevPoint;
        struct {
            /* 08 */ u16 mPrevPairX;
            /* 0a */ u16 mPrevPairY;
            /* 0c */ u16 mPrevHasPair;
            /* 0e */ u16 mPrevValidity;
        };
    };
    /* 10 */ u16 mNoPairCount;
    /* 12 */ u8 mMicOverThreshold[0x2];
} InputSlotPair;

// InputSlotHead.mRepeatState: no masked bit held, held until the first repeat, repeating at the interval.
#define INPUT_REPEAT_IDLE 0
#define INPUT_REPEAT_WAIT_DELAY 1
#define INPUT_REPEAT_WAIT_INTERVAL 2

// The first 0x28 bytes of an InputSlot; gKeysInputSlot is only this part.
typedef struct InputSlotHead {
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
    /* 14 */ u16 mLongHoldEnabled;
    /* 16 */ u8 mUnk_16[0x2];
    /* 18 */ u64 mHoldStartTick;
    /* 20 */ s32 mWritesKeyBits;
    /* 24 */ s32 mReadsKeyBits;
} InputSlotHead;

// Values of InputSlot.mSourceKind: where the slot gets its keys from each frame.
#define INPUT_SOURCE_NONE 0
#define INPUT_SOURCE_KEY_RECORDING_PLAYBACK 1
#define INPUT_SOURCE_PAD_RECORDED 2
#define INPUT_SOURCE_REQUESTED_BITS 3
#define INPUT_SOURCE_PARTICIPANT 4
#define INPUT_SOURCE_PAD_OR_PARTICIPANT 5
#define INPUT_SOURCE_PAD_AND_TOUCH 6
#define INPUT_SOURCE_WIFI_REQUESTED_BITS 7

// One 0x5c-byte element of the array at gInputSlots.
typedef struct InputSlot {
    // The members of InputSlotHead, spelled out.
    union {
        InputSlotHead mHead;
        struct {
            /* 00 */ u16 mPressedBits;
            /* 02 */ u16 mBits;
            /* 04 */ u16 mClearedBits;
            /* 06 */ u16 mRepeatBits;
            /* 08 */ u16 mRepeatState;
            /* 0a */ u16 mRepeatCallCount;
            /* 0c */ u16 mRepeatMask;
            /* 0e */ u16 mRepeatDelayLimit;
            /* 10 */ u16 mRepeatIntervalLimit;
            /* 12 */ u16 mHoldLong;
            /* 14 */ u16 mLongHoldEnabled;
            /* 16 */ u8 mUnk_16[0x2];
            /* 18 */ u64 mHoldStartTick;
            /* 20 */ s32 mWritesKeyBits;
            /* 24 */ s32 mReadsKeyBits;
        };
    };
    /* 28 */ KeyRecording mKeyRecording;
    /* 38 */ u8 mUnk_38[0x4];
    /* 3c */ s32 mSourceKind;
    /* 40 */ u16 mRequestedBits;
    /* 42 */ u16 mBitMask;
    /* 44 */ s32 mIsBlocked;
    /* 48 */ InputSlotPair mPair;
} InputSlot;

extern InputSlot gInputSlots[10];

// Views of gInputSlots. The pair, cleared-bits and halfword views
// are arrays of slots (the element stride is still 0x5c) that start at one member of slot 0, so each view type has that
// member first; the other two are the bytes of slots 7 and 8 from one member on.
typedef struct InputSlotAtClearedBits {
    /* 00 */ u16 mClearedBits;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtClearedBits;

typedef struct InputSlotAtPairX {
    /* 00 */ u16 mPairX;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtPairX;

typedef struct InputSlotAtPairY {
    /* 00 */ u16 mPairY;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtPairY;

typedef struct InputSlotAtHasPair {
    /* 00 */ u16 mHasPair;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtHasPair;

typedef struct InputSlotAtPrevHasPair {
    /* 00 */ u16 mPrevHasPair;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtPrevHasPair;

typedef struct InputSlotAtNoPairCount {
    /* 00 */ u16 mNoPairCount;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtNoPairCount;

// Slot 7 from mSourceKind on: mNextBits is the mBits of slot 8.
typedef struct InputSlot7FromSourceKind {
    /* 00 */ u8 mUnk_00[0x22];
    /* 22 */ volatile u16 mNextBits;
} InputSlot7FromSourceKind;

// Slot 8 from mWritesKeyBits on.
typedef struct InputSlot8PairView {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ volatile InputSlotPair mPair;
} InputSlot8PairView;

#define gInputClearedBitsSlots ((InputSlotAtClearedBits *) &gInputSlots[0].mClearedBits)
#define gInputPairXs ((InputSlotAtPairX *) &gInputSlots[0].mPair.mPairX)
#define gInputPairYs ((InputSlotAtPairY *) &gInputSlots[0].mPair.mPairY)
#define gInputHasPairs ((InputSlotAtHasPair *) &gInputSlots[0].mPair.mHasPair)
#define gInputPrevHasPairs ((InputSlotAtPrevHasPair *) &gInputSlots[0].mPair.mPrevHasPair)
#define gInputNoPairCounts ((InputSlotAtNoPairCount *) &gInputSlots[0].mPair.mNoPairCount)
#define gEmblemInputSlotView ((InputSlot7FromSourceKind *) &gInputSlots[7].mSourceKind)
#define gInputSlot8PairView ((InputSlot8PairView *) &gInputSlots[8].mWritesKeyBits)

static inline InputSlot *GetInputSlot(u32 inputSlotIndex) {
    return &gInputSlots[inputSlotIndex];
}
