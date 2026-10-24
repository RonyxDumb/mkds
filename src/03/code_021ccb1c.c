#include "03/code_021ccb1c.h"

int func_ov003_021ccb50(void) {
    int iVar1;
    int iVar2;
    u8 auStack_18[8];
    func_ov003_021cca9c(1, (short *) (void *) (auStack_18));
    iVar1 = func_ov003_021d29e8((u16 *) (void *) (auStack_18));
    if (iVar1 != 0) {
        return 1;
    }
    iVar1 = 2;
    do {
        func_ov003_021cca9c(iVar1, (short *) (void *) (auStack_18));
        iVar2 = func_ov003_021d29e8((u16 *) (void *) (auStack_18));
        if (iVar2 != 0) {
            return iVar1;
        }
        iVar1 = iVar1 + 1;
    } while (iVar1 <= 3);
    func_ov003_021cca9c(4, (short *) (void *) (auStack_18));
    iVar1 = func_ov003_021d2a34((u16 *) ((u16 *) (void *) (auStack_18)));
    if (iVar1 != 0) {
        return 4;
    }
    return 0;
}

int func_ov003_021ccb1c(void) {
    int iVar1;
    int iVar2;
    u8 auStack_18[8];
    iVar2 = 2;
    do {
        func_ov003_021cca9c(iVar2, (short *) (void *) (auStack_18));
        iVar1 = func_ov003_021d2a80((u16 *) (void *) (auStack_18));
        if (iVar1 != 0) {
            return iVar2;
        }
        iVar2 = iVar2 + 1;
    } while (iVar2 <= 3);
    return 0;
}
