#include "Main/System/input_slot_repeat.h"
#include "Main/System/input_slots.h"
#include "Main/System/input_keys.h"
#include "tick_counter.h"

void ResetInputSlot(InputSlot *slot) {
    slot->mPressedBits = 0x0u;
    slot->mBits = 0x0u;
    slot->mClearedBits = 0x0u;
    slot->mRepeatBits = 0x0u;
    slot->mRepeatState = INPUT_REPEAT_IDLE;
    slot->mRepeatCallCount = 0x0u;
    slot->mRepeatMask = 0x0u;
    slot->mRepeatDelayLimit = INPUT_REPEAT_DELAY_FRAMES;
    slot->mRepeatIntervalLimit = INPUT_REPEAT_INTERVAL_FRAMES;
    slot->mHoldLong = 0x0u;
    slot->mLongHoldEnabled = 0x0u;
    slot->mHoldStartTick = 0;
    slot->mWritesKeyBits = 0x0u;
    slot->mReadsKeyBits = 0x0u;
}

void ClearInputSlotBitsAndRepeat(InputSlot *slot) {
    slot->mPressedBits = 0x0u;
    slot->mBits = 0x0u;
    slot->mClearedBits = 0x0u;
    slot->mRepeatBits = 0x0u;
    slot->mRepeatState = INPUT_REPEAT_IDLE;
    slot->mRepeatCallCount = 0x0u;
}

void UpdateInputSlot(u32 keys, InputSlotHead *slot) {
    u16 maskedBits;
    if (slot->mWritesKeyBits != 0) {
        WriteKeyBitsToStream(keys);
    }
    slot->mPressedBits = keys & (keys ^ slot->mBits);
    slot->mClearedBits = (keys ^ 0xffff) & (keys ^ slot->mBits);
    slot->mBits = keys;
    slot->mRepeatBits = 0;
    switch (slot->mRepeatState) {
        case INPUT_REPEAT_IDLE:
            if (keys & slot->mRepeatMask) {
                slot->mRepeatState = INPUT_REPEAT_WAIT_DELAY;
                slot->mRepeatCallCount = 0;
                slot->mRepeatBits = keys & slot->mRepeatMask;
            }
            break;
        case INPUT_REPEAT_WAIT_DELAY:
            if (keys & slot->mRepeatMask) {
                slot->mRepeatCallCount++;
                if (slot->mRepeatCallCount >= slot->mRepeatDelayLimit) {
                    slot->mRepeatState = INPUT_REPEAT_WAIT_INTERVAL;
                    slot->mRepeatCallCount = 0;
                    slot->mRepeatBits = keys & slot->mRepeatMask;
                }
            } else {
                slot->mRepeatState = INPUT_REPEAT_IDLE;
            }
            break;
        case INPUT_REPEAT_WAIT_INTERVAL:
            if (keys & slot->mRepeatMask) {
                slot->mRepeatCallCount++;
                if (slot->mRepeatCallCount >= slot->mRepeatIntervalLimit) {
                    slot->mRepeatCallCount = 0;
                    slot->mRepeatBits = keys & slot->mRepeatMask;
                }
            } else {
                slot->mRepeatState = INPUT_REPEAT_IDLE;
            }
            break;
    }
    maskedBits = slot->mBits & PAD_KEYS_SHOULDER_AND_MENU;
    if (slot->mLongHoldEnabled != 0 && maskedBits == PAD_KEYS_SHOULDER_AND_MENU) {
        if (slot->mPressedBits & PAD_KEYS_SHOULDER_AND_MENU) {
            slot->mHoldStartTick = OS_GetTick();
            slot->mHoldLong = 0;
            return;
        }
        if (slot->mHoldLong != 0) {
            return;
        }
        if ((u32) (OS_GetTick() - slot->mHoldStartTick) > 0x3fec4) {
            slot->mHoldLong = 1;
        }
        return;
    }
    if (maskedBits != 0x30c) {
        slot->mLongHoldEnabled = 1;
    }
    slot->mHoldLong = 0;
}

void SetInputSlotRepeat(InputSlot *slot, u32 mask, u32 delayLimit, u32 intervalLimit) {
    slot->mRepeatMask = mask;
    slot->mRepeatDelayLimit = delayLimit;
    slot->mRepeatIntervalLimit = intervalLimit;
}
