#include "03/code_021c2120.h"

void func_ov003_021c2138(void) {
    func_02148a10();
    *((u32 *) 0x04001000u) = *((u32 *) 0x04001000u) & ((u32) 0xfffeffffu);
    func_ov003_021d326c();
    func_ov003_021d2d28();
    func_ov003_021d2dcc();
    func_ov003_021cdc28();
    func_ov003_021d1af0();
    func_ov003_021d2f78();
    func_ov003_021d244c();
    func_ov003_021d1f88();
    func_ov003_021d15f4();
    func_ov003_021d35c0();
    func_ov003_021d2894();
    func_ov003_021d332c();
    return;
}

void func_ov003_021c212c(u32 param_1) {
    *((u32 *) ((u32) (&data_ov003_021da17c))) = param_1;
    return;
}

void func_ov003_021c2120(u32 param_1, u32 param_2) {
    u32 *puVar1;
    puVar1 = ((u32 *) ((u32) (&data_ov003_021da180)));
    *((u32 *) ((u32) (&data_ov003_021da180))) = param_1;
    puVar1[1] = param_2;
    return;
}
