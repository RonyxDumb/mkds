#include "Main/System/input_keys.h"
#include "code_0200fc8c.h"
#include "Main/System/input_slot_repeat.h"
#include "Main/Race/race_keys.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "code_0200fe74.h"
#include "registers.h"

KeyStream gKeyStream;
InputSlotHead gKeysInputSlot;

void StartupResetKeysInputSlot(void) {
    gKeysInputSlot.mPressedBits = 0;
    gKeysInputSlot.mBits = 0;
    gKeysInputSlot.mClearedBits = 0;
    gKeysInputSlot.mRepeatBits = 0;
    gKeysInputSlot.mRepeatState = 0;
    gKeysInputSlot.mRepeatCallCount = 0;
    gKeysInputSlot.mRepeatMask = 0;
    gKeysInputSlot.mRepeatDelayLimit = 0x14;
    gKeysInputSlot.mRepeatIntervalLimit = 8;
    gKeysInputSlot.mHoldLong = 0;
    gKeysInputSlot.mUnk_14 = 0;
    gKeysInputSlot.mHoldStartTick = 0;
    gKeysInputSlot.mUnk_20 = 0;
    gKeysInputSlot.mUnk_24 = 0;
}

void ResetKeysInputSlot(void) {
    gKeysInputSlot.mPressedBits = 0;
    gKeysInputSlot.mBits = 0;
    gKeysInputSlot.mClearedBits = 0;
    gKeysInputSlot.mRepeatBits = 0;
    gKeysInputSlot.mRepeatState = 0;
    gKeysInputSlot.mRepeatCallCount = 0;
    gKeysInputSlot.mRepeatMask = 0;
    gKeysInputSlot.mRepeatDelayLimit = 0x14;
    gKeysInputSlot.mRepeatIntervalLimit = 8;
    gKeysInputSlot.mHoldLong = 0;
    gKeysInputSlot.mUnk_14 = 0;
    gKeysInputSlot.mHoldStartTick = 0;
    gKeysInputSlot.mUnk_20 = 0;
    gKeysInputSlot.mUnk_24 = 0;
}

void ReadKeysIntoInputSlot(void) {
    u32 keys;
    if (gKeysInputSlot.mUnk_24 != 0) {
        keys = ReadKeyBitsFromStream();
    } else {
        keys = (u16) (((reg_PAD_KEYINPUT | SYSTEM_WORK->mButtonXY) ^ 0x2fff) & 0x2fff);
    }
    UpdateInputSlot(keys, &gKeysInputSlot);
}

void SeekKeyStream(u32 count, u32 origin) {
    u32 elementSize = gKeyStream.mElementSize;
    u8 *newPosition;
    u8 *start;
    switch (origin) {
        case 2:
            newPosition = gKeyStream.mHighestWritten - count * elementSize;
            break;
        case 0:
            newPosition = gKeyStream.mStart + count * elementSize;
            break;
        case 1:
            newPosition = gKeyStream.mPosition + count * elementSize;
            break;
    }
    start = gKeyStream.mStart;
    if (newPosition < start) {
        newPosition = start;
    }
    if (gKeyStream.mEnd < newPosition + elementSize) {
        newPosition = start + elementSize * ((u32) (gKeyStream.mEnd - start) / elementSize);
    }
    gKeyStream.mPosition = newPosition;
}

void WriteKeyBitsToStream(u32 keys) {
    u32 elementSize = gKeyStream.mElementSize;
    u32 keyBit;
    u32 packedBit;
    u8 *position = gKeyStream.mPosition;
    u16 keyMask;
    u16 keyBitCopy;
    u32 packed;
    if (position + elementSize > gKeyStream.mEnd) {
        return;
    }
    if (elementSize == 1) {
        keyMask = gKeyStream.mKeyMask;
        keyBit = 1;
        packedBit = 1;
        packed = 0;
        for (; keyBit < 0x10000; keyBit <<= 1) {
            keyBitCopy = keyBit;
            if (keyBitCopy & keyMask) {
                if (keyBitCopy & keys) {
                    packed |= packedBit;
                }
                packedBit = (packedBit << 1) & 0xff;
                if (packedBit == 0) {
                    break;
                }
            }
        }
        *position = packed;
    } else {
        *(u16 *) position = keys;
    }
    SeekKeyStream(1, 1);
    if (gKeyStream.mPosition > gKeyStream.mHighestWritten) {
        gKeyStream.mHighestWritten = gKeyStream.mPosition;
    }
}

u32 ReadKeyBitsFromStream(void) {
    u32 keys;
    u32 keyBit;
    u32 packedBit;
    s32 packed;
    u16 keyBitCopy;
    u16 keyMask;
    if (gKeyStream.mPosition + gKeyStream.mElementSize > gKeyStream.mEnd) {
        return 0;
    }
    if (gKeyStream.mElementSize == 1) {
        packed = *gKeyStream.mPosition;
        keyBit = 1;
        keyMask = gKeyStream.mKeyMask;
        packedBit = 1;
        keys = 0;
        for (; keyBit < 0x10000; keyBit <<= 1) {
            keyBitCopy = keyBit;
            if (keyBitCopy & keyMask) {
                if (packedBit & packed) {
                    keys |= keyBitCopy;
                }
                packedBit = (packedBit << 1) & 0xff;
                if (packedBit == 0) {
                    break;
                }
            }
        }
    } else {
        keys = *(u16 *) gKeyStream.mPosition;
    }
    SeekKeyStream(1, 1);
    return keys;
}
