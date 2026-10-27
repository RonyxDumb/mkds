#include "03/code_021b7c44.h"

u16 func_ov003_021b7c44(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}
