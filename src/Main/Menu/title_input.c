#include "Main/Menu/title_input.h"

#include "Main/Menu/title_state0.h"
#include "Main/Menu/data_02175628.h"

#pragma thumb on
u32 TitleState2ReturnArgumentWrapper(u32 value) {
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
    return (*OFFSET_PTR(const u16, pair, 4));
}
