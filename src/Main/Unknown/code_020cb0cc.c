#include "Main/Unknown/code_020cb0cc.h"

#include "Main/Unknown/code_020cb0ec.h"
#include "Main/Unknown/code_020cb0f4.h"
#include "Main/Unknown/code_020cb114.h"
#include "Main/Unknown/unk_02175628.h"

u32 MenuGetPairX(InputSlotPair *pairAddress) {
    return pairAddress->mPairX;
}

u32 MenuGetSlotPairX(u32 slotIndex) {
    return MenuGetPairX(&gInputSlots[slotIndex].mPair);
}

u32 MenuGetPairY(InputSlotPair *pairAddress) {
    return pairAddress->mPairY;
}

u32 MenuGetSlotPairY(u32 slotIndex) {
    return MenuGetPairY(&gInputSlots[slotIndex].mPair);
}
