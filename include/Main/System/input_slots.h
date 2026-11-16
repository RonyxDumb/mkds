#pragma once
#include "types.h"
#include "touch_panel_sampling.h" // TPData

#define PAD_KEY_B 0x2

#define PAD_KEY_DIRECTION_DOWN 0x80

#define PAD_KEY_L 0x200

#define PAD_KEY_DIRECTION_LEFT 0x20

#define PAD_KEY_R 0x100

#define PAD_KEY_DIRECTION_RIGHT 0x10

#define PAD_KEY_START 0x8

#define PAD_KEY_DIRECTION_UP 0x40

#define PAD_KEY_X 0x400

#define PAD_KEY_Y 0x800

// Bits of the pad key word (the slots' mPressedBits, mBits, mRepeatBits ... and the keyboard's key word): one bit per
// key.
#define PAD_KEY_A 0x1

#define PAD_KEY_SELECT 0x4

// A, B, X, Y, Select and Start: every key except the four direction keys, L and R.
#define PAD_KEYS_A_B_X_Y_SELECT_START \
    (PAD_KEY_A | PAD_KEY_B | PAD_KEY_SELECT | PAD_KEY_START | PAD_KEY_X | PAD_KEY_Y)

// A, B, X, Y, L and R.
#define PAD_KEYS_A_B_X_Y_L_R (PAD_KEY_A | PAD_KEY_B | PAD_KEY_X | PAD_KEY_Y | PAD_KEY_L | PAD_KEY_R)

// L, R, Select and Start.
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

// Slots 8 and 9 of gInputSlots, named after the source kind each one gets.
typedef enum InputSlotIndex { INPUT_SLOT_PAD_OR_PARTICIPANT = 8, INPUT_SLOT_PAD_AND_TOUCH = 9 } InputSlotIndex;

// The recorded key pairs (bits, repeat count) and their byte count.
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

// The pair state of an input slot: the current and previous point, mHasPair, mNoPairCount and the mic threshold flags.
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

// A touch pair lost for fewer frames than this (InputSlotPair.mNoPairCount) still counts as recently lost.
#define INPUT_NO_PAIR_BRIEF_FRAMES 5

// InputSlotHead.mRepeatState: no masked bit held, held until the first repeat, repeating at the interval.
#define INPUT_REPEAT_IDLE 0
#define INPUT_REPEAT_WAIT_DELAY 1
#define INPUT_REPEAT_WAIT_INTERVAL 2

// A touch pair lost for fewer samples than this still counts as recently lost.
#define INPUT_PAIR_LOSS_SAMPLES 5

// The key state of an input slot: pressed, held and cleared bits and repeat state; gKeysInputSlot is only this part.
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

// One input slot: its key state, key recording, source kind, requested bits and touch pair.
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

// A view of an input slot that starts at its cleared bits.
typedef struct InputSlotAtClearedBits {
    /* 00 */ u16 mClearedBits;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtClearedBits;

// A view of gInputSlots that starts at the pair x member.
typedef struct InputSlotAtPairX {
    /* 00 */ u16 mPairX;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtPairX;

// A view of gInputSlots that starts at the pair y member.
typedef struct InputSlotAtPairY {
    /* 00 */ u16 mPairY;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtPairY;

// A view of gInputSlots that starts at the has-pair flag.
typedef struct InputSlotAtHasPair {
    /* 00 */ u16 mHasPair;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtHasPair;

// A view of gInputSlots that starts at the previous has-pair flag.
typedef struct InputSlotAtPrevHasPair {
    /* 00 */ u16 mPrevHasPair;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtPrevHasPair;

// A view of gInputSlots that starts at the no-pair count.
typedef struct InputSlotAtNoPairCount {
    /* 00 */ u16 mNoPairCount;
    /* 02 */ u8 mRest[0x5a];
} InputSlotAtNoPairCount;

// Slot 7 from mSourceKind on: mNextBits is the mBits of slot 8.
typedef struct PadOrParticipantSlotBitsView {
    /* 00 */ u8 mUnk_00[0x22];
    /* 22 */ volatile u16 mNextBits;
} PadOrParticipantSlotBitsView;

// Slot 8 (INPUT_SLOT_PAD_OR_PARTICIPANT) from mWritesKeyBits on: mPair is the mPair of that slot.
typedef struct PadOrParticipantSlotPairView {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ volatile InputSlotPair mPair;
} PadOrParticipantSlotPairView;

#define gInputClearedBitsSlots ((InputSlotAtClearedBits *) &gInputSlots[0].mClearedBits)
#define gInputPairXs ((InputSlotAtPairX *) &gInputSlots[0].mPair.mPairX)
#define gInputPairYs ((InputSlotAtPairY *) &gInputSlots[0].mPair.mPairY)
#define gInputHasPairs ((InputSlotAtHasPair *) &gInputSlots[0].mPair.mHasPair)
#define gInputPrevHasPairs ((InputSlotAtPrevHasPair *) &gInputSlots[0].mPair.mPrevHasPair)
#define gInputNoPairCounts ((InputSlotAtNoPairCount *) &gInputSlots[0].mPair.mNoPairCount)
#define gEmblemInputSlotView ((PadOrParticipantSlotBitsView *) &gInputSlots[7].mSourceKind)
#define gPadOrParticipantSlotPairView                                                                                  \
    ((PadOrParticipantSlotPairView *) &gInputSlots[INPUT_SLOT_PAD_OR_PARTICIPANT].mWritesKeyBits)

static inline InputSlot *GetInputSlot(u32 inputSlotIndex) {
    return &gInputSlots[inputSlotIndex];
}
