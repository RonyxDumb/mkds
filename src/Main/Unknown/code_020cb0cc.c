#include "Main/Unknown/code_020cb0cc.h"

#include "Main/Unknown/code_020cb0ec.h"
#include "Main/Unknown/code_020cb0f4.h"
#include "Main/Unknown/code_020cb114.h"
#include "Main/Unknown/unk_02175628.h"

u32 func_020cb114(InputSlotPair *pairAddress) {
    return pairAddress->mPairX;
}

u32 func_020cb0f4(u32 slotIndex) {
    return func_020cb114(&data_02175628[slotIndex].mUnk_48);
}

u32 func_020cb0ec(InputSlotPair *pairAddress) {
    return pairAddress->mPairY;
}

u32 func_020cb0cc(u32 slotIndex) {
    return func_020cb0ec(&data_02175628[slotIndex].mUnk_48);
}
