#include "03/code_021b7c94.h"

u16 func_ov003_021b7c94(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}
