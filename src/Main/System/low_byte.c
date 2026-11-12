#include "Main/System/low_byte.h"

u32 GetLowByte(u32 p0) {
    return ((p0) & (0xffu));
}
