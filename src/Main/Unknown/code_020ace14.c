#include "Main/Unknown/code_020ace14.h"
#include "Main/Unknown/code_020acebc.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

u32 title_spi_isPenReleaseTimeout(InputSlotPair *inputSlotPair) {
    if (title_spi_getTpValid(inputSlotPair) == 0) {
        if (inputSlotPair->mNoPairCount < 5) {
            return 1;
        }
    }
    return 0;
}

u32 title_spi_isPenDownEvent(InputSlotPair *inputSlotPair) {
    if (inputSlotPair->mPrevHasPair == 0 && inputSlotPair->mHasPair != 0) {
        return 1;
    }
    return 0;
}

u32 title_spi_isValidPenDownEvent(InputSlotPair *inputSlotPair) {
    u32 r;

    if (title_spi_isPenReleaseTimeout(inputSlotPair) == 0 && title_spi_isPenDownEvent(inputSlotPair) != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

u32 title_input_isValidPenDownEventById(u32 slotIndex) {
    return title_spi_isValidPenDownEvent((InputSlotPair *) &gInputUnits[slotIndex].mPairX);
}
