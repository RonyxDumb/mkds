#include "03/code_021c5944.h"
#include "code_02147cd8.h"

void func_ov003_021c5944(void) {
    int iVar1;
    u32 uVar2;
    if (*(unsigned char *) ((*(int *) &data_ov003_021da1f4) + 0x56) != '\0') {
        iVar1 = func_02147cd8((u32) ((*(u16 *) &data_ov003_021da1f0)), (u32) (0x1c));
        uVar2 = (iVar1 + -0x32) * 0x10000 & ((u32) 0x01ff0000u);
        *((u32 *) 0x04000010u) = uVar2;
        *((u32 *) 0x04000018u) = uVar2;
        *(u8 *) ((*(int *) &data_ov003_021da1f4) + 0x56) = 0;
    }
    return;
}
