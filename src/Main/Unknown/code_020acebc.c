#include "Main/Unknown/code_020acebc.h"

#include "Main/Unknown/code_020acec4.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020acef4.h"
#include "Main/Unknown/code_020acefc.h"

#pragma thumb on
u32 title_mainStateVblank(u32 value) {
    u32 value0 = value;
    u32 functionAddress;
    functionAddress = (u32) &func_020ad230;
    value0 = func_020ad230(value0);
    return value0;
}
#pragma thumb off

u32 title_input_getMasterInputUnitId(void) {
    return 0x8u;
}

u16 title_pad_isSetPadTrig(InputSlot *slot, u32 mask) {
    return slot->mPressedBits & mask;
}

u16 title_input_isSetPadTrigById(u32 slotIndex, u32 mask) {
    return title_pad_isSetPadTrig(&gInputUnits[slotIndex], mask);
}

u32 title_spi_getTpValid(const void *pair) {
    return (*OFFSET_PTR(const u16, pair, 4));
}
