#include "Main/System/input_keys.h"
#include "reset_interrupts_halt.h"
#include "Main/System/input_slot_repeat.h"
#include "Main/Race/race_keys.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "model_texture_bind.h"
#include "registers.h"

KeyStream g_GlobalIG;
InputSlotHead g_GlobalG;

void InitializeGlobalG_M1(void) {
    g_GlobalG.mPressedBits = 0;
    g_GlobalG.mBits = 0;
    g_GlobalG.mClearedBits = 0;
    g_GlobalG.mRepeatBits = 0;
    g_GlobalG.mRepeatState = 0;
    g_GlobalG.mRepeatCallCount = 0;
    g_GlobalG.mRepeatMask = 0;
    g_GlobalG.mRepeatDelayLimit = KEYS_REPEAT_DELAY_FRAMES;
    g_GlobalG.mRepeatIntervalLimit = KEYS_REPEAT_INTERVAL_FRAMES;
    g_GlobalG.mHoldLong = 0;
    g_GlobalG.mLongHoldEnabled = 0;
    g_GlobalG.mHoldStartTick = 0;
    g_GlobalG.mWritesKeyBits = 0;
    g_GlobalG.mReadsKeyBits = 0;
}

void InitializeGlobalG_2(void) {
    g_GlobalG.mPressedBits = 0;
    g_GlobalG.mBits = 0;
    g_GlobalG.mClearedBits = 0;
    g_GlobalG.mRepeatBits = 0;
    g_GlobalG.mRepeatState = 0;
    g_GlobalG.mRepeatCallCount = 0;
    g_GlobalG.mRepeatMask = 0;
    g_GlobalG.mRepeatDelayLimit = KEYS_REPEAT_DELAY_FRAMES;
    g_GlobalG.mRepeatIntervalLimit = KEYS_REPEAT_INTERVAL_FRAMES;
    g_GlobalG.mHoldLong = 0;
    g_GlobalG.mLongHoldEnabled = 0;
    g_GlobalG.mHoldStartTick = 0;
    g_GlobalG.mWritesKeyBits = 0;
    g_GlobalG.mReadsKeyBits = 0;
}

void UpdateInput(void) {
    u32 keys;
    if (g_GlobalG.mReadsKeyBits != 0) {
        keys = GetSomeInput();
    } else {
        keys = (u16) (((reg_PAD_KEYINPUT | SYSTEM_WORK->mButtonXY) ^ 0x2fff) & 0x2fff);
    }
    StructG_UpdateInput(keys, &g_GlobalG);
}

void SeekKeyStream(u32 count, u32 origin) {
    u32 elementSize = g_GlobalIG.mElementSize;
    u8 *newPosition;
    u8 *start;
    switch (origin) {
        case KEY_STREAM_SEEK_END:
            newPosition = g_GlobalIG.mHighestWritten - count * elementSize;
            break;
        case KEY_STREAM_SEEK_START:
            newPosition = g_GlobalIG.mStart + count * elementSize;
            break;
        case KEY_STREAM_SEEK_CURRENT:
            newPosition = g_GlobalIG.mPosition + count * elementSize;
            break;
    }
    start = g_GlobalIG.mStart;
    if (newPosition < start) {
        newPosition = start;
    }
    if (g_GlobalIG.mEnd < newPosition + elementSize) {
        newPosition = start + elementSize * ((u32) (g_GlobalIG.mEnd - start) / elementSize);
    }
    g_GlobalIG.mPosition = newPosition;
}

void WriteKeyBitsToStream(u32 keys) {
    u32 elementSize = g_GlobalIG.mElementSize;
    u32 keyBit;
    u32 packedBit;
    u8 *position = g_GlobalIG.mPosition;
    u16 keyMask;
    u16 keyBitCopy;
    u32 packed;
    if (position + elementSize > g_GlobalIG.mEnd) {
        return;
    }
    if (elementSize == 1) {
        keyMask = g_GlobalIG.mKeyMask;
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
    if (g_GlobalIG.mPosition > g_GlobalIG.mHighestWritten) {
        g_GlobalIG.mHighestWritten = g_GlobalIG.mPosition;
    }
}

u32 GetSomeInput(void) {
    u32 keys;
    u32 keyBit;
    u32 packedBit;
    s32 packed;
    u16 keyBitCopy;
    u16 keyMask;
    if (g_GlobalIG.mPosition + g_GlobalIG.mElementSize > g_GlobalIG.mEnd) {
        return 0;
    }
    if (g_GlobalIG.mElementSize == 1) {
        packed = *g_GlobalIG.mPosition;
        keyBit = 1;
        keyMask = g_GlobalIG.mKeyMask;
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
        keys = *(u16 *) g_GlobalIG.mPosition;
    }
    SeekKeyStream(1, 1);
    return keys;
}
