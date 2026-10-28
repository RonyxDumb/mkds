#include "00/code_0219eac8.h"

u8 func_ov000_0219eac8(void) {
    u8 i = 0;
    do {
        if (data_ov000_021b5698[i][0] == 0) {
            return i + 100;
        }
        i++;
    } while (i < 154);
    return 0;
}
