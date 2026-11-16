#include "Main/Unknown/code_02039230.h"
#include "Main/Unknown/code_02039530.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/unk_02175000.h"

void InitializeGlobalG_M1(void) {
    g_GlobalG.mPressedBits = 0;
    g_GlobalG.mBits = 0;
    g_GlobalG.mClearedBits = 0;
    g_GlobalG.mRepeatBits = 0;
    g_GlobalG.mRepeatState = 0;
    g_GlobalG.mRepeatCallCount = 0;
    g_GlobalG.mRepeatMask = 0;
    g_GlobalG.mRepeatDelayLimit = 0x14;
    g_GlobalG.mRepeatIntervalLimit = 8;
    g_GlobalG.mHoldLong = 0;
    g_GlobalG.field14 = 0;
    g_GlobalG.mHoldStartTick = 0;
    g_GlobalG.field20 = 0;
    g_GlobalG.field24 = 0;
}

void InitializeGlobalG_2(void) {
    g_GlobalG.mPressedBits = 0;
    g_GlobalG.mBits = 0;
    g_GlobalG.mClearedBits = 0;
    g_GlobalG.mRepeatBits = 0;
    g_GlobalG.mRepeatState = 0;
    g_GlobalG.mRepeatCallCount = 0;
    g_GlobalG.mRepeatMask = 0;
    g_GlobalG.mRepeatDelayLimit = 0x14;
    g_GlobalG.mRepeatIntervalLimit = 8;
    g_GlobalG.mHoldLong = 0;
    g_GlobalG.field14 = 0;
    g_GlobalG.mHoldStartTick = 0;
    g_GlobalG.field20 = 0;
    g_GlobalG.field24 = 0;
}

void ReadKeysIntoInputSlot(void) {
    u32 keys;
    if (g_GlobalG.field24 != 0) {
        keys = ReadKeyBitsFromStream();
    } else {
        keys = (u16) (((*(vu16 *) 0x4000130 | *(vu16 *) 0x27fffa8) ^ 0x2fff) & 0x2fff);
    }
    pad_update(keys, &g_GlobalG);
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
