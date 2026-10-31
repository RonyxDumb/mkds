#include "03/code_021d11a0.h"
#include "03/code_021cf5ac.h"

u32 func_ov003_021d11a0(void) {
    if (*(u8 *) ((int) data_ov003_021da2ac + ((u32) 0x00000a90u)) == 5) {
        *(s8 *) ((int) data_ov003_021da2ac + 0xa90) = 6;
        func_ov003_021cf69c();
        return 1;
    }
    return 0;
}
