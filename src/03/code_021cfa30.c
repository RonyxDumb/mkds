#include "03/code_021cfa30.h"
#include "03/code_021d07b0.h"

void func_ov003_021cfa30(u8 *param_1) {
    *(u8 **) &data_ov003_021da288 = param_1;
    func_ov003_021d0810((Unk021da2a8 *) (param_1 + 0x1b160));
    *(u32 *) (*(u8 **) &data_ov003_021da288 + 0x1b140) = 0;
    *(u32 *) (*(u8 **) &data_ov003_021da288 + 0x1b144) = 0;
}
