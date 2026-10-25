#include "03/code_021bf4dc.h"

u32 func_ov003_021bf4dc(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) func_ov003_021c20d0();
    value1 = (value0 << 2);
    value0 = (u32) &data_ov003_021d5f1c;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return (u32) value0;
}
