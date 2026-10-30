#include "00/code_0218f808.h"

void func_ov000_0218f808(int *param_1) {
    int iVar1;
    iVar1 = *param_1;
    func_ov000_02190ff8((Unk0218f960 *) (param_1), 1);
    func_ov000_021a3668((void *) (*(u32 *) (iVar1 + ((int) 0x00000460u))));
    *(u32 *) (iVar1 + ((int) 0x00000460u)) = 0;
    func_ov000_0218dfb4((int *) ((int *) (u32) (*(u32 *) (iVar1 + ((int) 0x00000428u)))));
    func_ov000_021a3668((void *) (iVar1));
    *param_1 = 0;
    return;
}
