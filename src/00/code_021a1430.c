#include "00/code_021a1430.h"
#include "00/code_0219e000.h"
#include "00/code_021a369c.h"

void func_ov000_021a1430(void) {
    data_ov000_021b566c = 0;
    if (data_ov000_021b5674 != 0) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5674, 0);
        data_ov000_021b5674 = 0;
    }
    func_ov000_0219ea88();
    if (data_ov000_021b5670 != 0) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5670, 0);
        data_ov000_021b5670 = 0;
    }
    data_ov000_021b5668.mUnk_00 = 0;
    data_ov000_021b5668.mUnk_01 = 0;
}
