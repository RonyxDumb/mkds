#include "00/code_02186a84.h"

u32 func_ov000_02186a84(u32 value) {
    if (value & 0x8000) {
        value &= 0xffff7fff;
    }
    return value;
}
