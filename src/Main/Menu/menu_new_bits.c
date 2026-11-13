#include "Main/Menu/menu_new_bits.h"
#include "Main/Menu/data_02175628.h"
#include "Main/System/init_after_startup.h"

#pragma optimize_for_size on
u16 MenuGetInputSlotNewBits(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 MenuGetNewBits(u32 slotIndex, u32 mask) {
    return MenuGetInputSlotNewBits(&gInputSlots[slotIndex], mask);
}
