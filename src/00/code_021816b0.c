#include "00/code_021816b0.h"
#include "00/code_02180c3c.h"
#include "00/code_021816a0.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_0212a910.h"

void func_ov000_021816b0(void *a) {
    data_ov000_021b4c68 = func_02036bec(a, 0x40);
    data_ov000_021b4c68->mUnk_1c = a;
    data_ov000_021b4c68->mUnk_00 = 0;
    data_ov000_021b4c68->mUnk_04 = 0;
    data_ov000_021b4c68->mUnk_0c = -1;
    data_ov000_021b4c68->mUnk_08 = 0;
    data_ov000_021b4c68->mUnk_38 = func_0204799c("wifi.bmg");
    data_ov000_021b4c68->mUnk_3c = func_02047a28("common.bmg");
    func_ov000_021816a0();
    func_0212a910(1, 1);
    func_021281c8(0xe);
    func_0204f804();
}
