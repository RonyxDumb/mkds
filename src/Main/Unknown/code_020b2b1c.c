#include "Main/Unknown/code_020b2b1c.h"

#include "Main/Unknown/code_020b2b24.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020b2b54.h"
#include "00/code_02181f98.h"

u32 ChoisesSGetUnfilledNotEliminated(void) {
    return (data_0217b488->mUnfilledNotEliminated);
}

u32 GetChoisesSInputSlot(void) {
    return 0x8u;
}

u16 ChoisesSGetInputSlotNewBits(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 ChoisesSGetNewBits(s32 slotIndex, u32 mask) {
    return ChoisesSGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}

u32 ChoisesSGetPairHasPair(const void *inputSlotPair) {
    return (*OFFSET_PTR(const u16, inputSlotPair, 4));
}
