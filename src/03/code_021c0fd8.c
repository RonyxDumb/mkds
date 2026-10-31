#include "03/code_021c0fd8.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2f00.h"

void func_ov003_021c0fd8(u32 param_1) {
    int iVar4;
    int iVar3;
    func_ov003_021d34c8(0, param_1);
    iVar4 = 0;
    iVar3 = 0;
    do {
        func_ov003_021d197c(*(Unk021d1770 **) ((u8 *) data_ov003_021da160 + iVar3 + 0x48));
        func_ov003_021d2388((int) (*(u32 *) ((u8 *) data_ov003_021da160 + iVar3)));
        iVar3 = iVar3 + 4;
        iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    iVar3 = 0;
    iVar4 = 0;
    do {
        func_ov003_021d197c(*(Unk021d1770 **) ((u8 *) data_ov003_021da160 + iVar4 + 0x40));
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    iVar3 = 0;
    iVar4 = 0;
    do {
        func_ov003_021d2f00((u32 *) (u32) (*(u32 *) ((u8 *) data_ov003_021da160 + iVar4 + 0x38)));
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    iVar3 = 0;
    iVar4 = 0;
    do {
        func_ov003_021d2f00((u32 *) (u32) (*(u32 *) ((u8 *) data_ov003_021da160 + iVar4 + 0x10)));
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 10);
    func_ov003_021d2808((int *) &data_ov003_021da160);
    return;
}
