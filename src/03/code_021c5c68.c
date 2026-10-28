#include "03/code_021c5c68.h"
#include "code_02147cd8.h"

void func_ov003_021c5c68(void) {
    int iVar1;
    int iVar2;
    int iVar3;
    int uVar4;
    iVar1 = func_02147d30((u32) ((*(u16 *) &data_ov003_021da1f0)), (u32) (0x1c));
    uVar4 = (u32) * (u8 *) ((*(int *) &data_ov003_021da1f4) + 0x51);
    func_ov003_021d2060(*(u32 *) ((*(int *) &data_ov003_021da1f4) + 0xc), 0);
    if (5 < uVar4) {
        uVar4 = 5;
    }
    iVar2 = 0;
    iVar3 = iVar1;
    if (uVar4 > 0) {
        do {
            func_ov003_021c5b90((int) (iVar3), (int) (iVar2));
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + 1;
        } while (iVar2 < (int) uVar4);
    }
    iVar3 = 0;
    if (uVar4 > 0) {
        do {
            func_ov003_021c5b34((int) (iVar1), (int) (iVar3));
            iVar3 = iVar3 + 1;
            iVar1 = iVar1 + 1;
        } while (iVar3 < (int) uVar4);
    }
    func_ov003_021d1fd0((int) (*(u32 *) ((*(int *) &data_ov003_021da1f4) + 0xc)));
    func_ov003_021c5aa4();
    return;
}
