#include "00/code_021b02bc.h"
#include "code_0200fc8c.h"

s32 func_ov000_021b02bc(void) {
    u32 a;
    s32 b;

    a = func_0200fca0();
    b = func_0200e070(&data_ov000_021b655c);
    if (b == 0 && data_ov000_021b63b0 == 0) {
        data_ov000_021b63b0 = 1;
        func_0200df68(&data_ov000_021b655c);
    }
    func_0200fcb4(a);
    return b;
}
