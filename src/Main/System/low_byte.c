#include "Main/System/low_byte.h"

u32 Int32ToInt8(u32 value) {
    return ((value) & (0xffu));
}
