#include "00/code_02199a00.h"
#include "00/code_0219a014.h"

s32 gti2IncomingBufferMessageCompare(const void *elem1, const void *elem2) {
    const u8 *leftMessage = elem1;
    const u8 *rightMessage = elem2;
    s32 value0;
    s32 value1;
    u32 value3;
    value0 = *(const u16 *) (leftMessage + 12);
    value1 = *(const u16 *) (rightMessage + 12);
    value3 = (u32) &func_ov000_0219a014;
    value0 = func_ov000_0219a014(value0, value1);
    return value0;
}
