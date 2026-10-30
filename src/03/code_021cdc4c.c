#include "03/code_021cdc4c.h"
#include "03/code_021bf620.h"
#include "03/code_021cdbc8.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3544.h"
#include "code_0212ba68.h"
#include "code_0212d5e0.h"
#include "code_0212df7c.h"

void func_ov003_021cdc4c(void) {
    u32 a;
    *(Unk021cdc4c **) &data_ov003_021da274 = func_ov003_021d285c(0x9c, 4);
    (*(Unk021cdc4c **) &data_ov003_021da274)->mUnk_94 = func_ov003_021d14b8(data_ov003_021d77d4, &a, 0x20);
    func_0212baa8();
    func_0212d5f8(&(*(Unk021cdc4c **) &data_ov003_021da274)->mUnk_00, (*(Unk021cdc4c **) &data_ov003_021da274)->mUnk_94);
    func_0212edac(0);
    func_0212c6a0(&(*(Unk021cdc4c **) &data_ov003_021da274)->mUnk_90);
    (*(Unk021cdc4c **) &data_ov003_021da274)->mUnk_98 = func_ov003_021d3544(0, (u32) func_ov003_021cdbc8, 0, 0xc8);
}
