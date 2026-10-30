#include "03/code_021b7bb4.h"
#include "code_0214d964.h"
#include "03/code_021b7d84.h"

u16 func_ov003_021b7bb4(void) {
    s32 a;
    u32 b[3];
    u32 *c;
    if (data_ov003_021d7c48 == 0) {
        a = 0;
        func_ov003_021b7d84(b, 0, 12);
        if (func_0214df78(b) == 0) {
            a += b[0] << 10;
            a += b[1] << 3;
            a += b[2];
        }
        data_ov003_021d7c60[0] = a;
        data_ov003_021d7c60[1] = 0x5d588b65;
        data_ov003_021d7c60[2] = 0x269ec3;
        data_ov003_021d7c48 = 1;
    }
    data_ov003_021d7c60[0] = data_ov003_021d7c60[2] + data_ov003_021d7c60[1] * data_ov003_021d7c60[0];
    return ((data_ov003_021d7c60[0] >> 16) * 0x7fff) >> 16;
}
