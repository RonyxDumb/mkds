#include "00/code_02198714.h"
#include "00/code_0218e8c4.h"

u32 func_ov000_02198714(u32 *param_1, u32 param_2, u32 param_3) {
    int iVar1;
    u32 uVar2;
    iVar1 = func_ov000_0219a110((u32 *) ((u32 *) (u32) (param_1[2])), (u32) (*param_1), (int) (*(u16 *) (param_1 + 1)),
                                (u32) (param_2), (u32) (param_3));
    if (iVar1 == 0) {
        return 0;
    }
    uVar2 = func_ov000_0218e8c4();
    param_1[0x22] = uVar2;
    return 1;
}
