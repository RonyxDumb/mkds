#include "Main/Menu/title_input.h"

#include "Main/Menu/title_state0.h"
#include "Main/System/input_slots.h"
#include "Main/System/init_after_startup.h"

#pragma thumb on
u32 TitleMenuInputReturnArgumentWrapper(u32 value) {
    return TitleReturnArgument(value);
}
#pragma thumb off

u32 GetTitleInputSlot(void) {
    return 0x8u;
}

u16 TitleGetInputSlotNewBits(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 TitleGetNewBits(u32 slotIndex, u32 mask) {
    return TitleGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

u32 TitleGetPairHasPair(InputSlotPair *pair) {
    return pair->mHasPair;
}
