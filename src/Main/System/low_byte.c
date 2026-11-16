#include "Main/System/low_byte.h"

u32 GetLowByte(u32 value) {
    return ((value) & (0xffu));
}
