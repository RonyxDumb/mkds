#include "00/code_021ad36c.h"

u32 func_ov000_021ad36c(void) {
    u32 uVar1;
    int iVar2;
    int iVar3;
    func_ov000_021ae270();
    func_ov000_021ae2d8();
    func_ov000_021ae290((int) (0x44), (u16) (0x43), (int) (0xffffffff));
    iVar3 = 0;
    do {
        uVar1 = func_ov000_021ad6c0();
        iVar2 = func_ov000_021ad3b8((u32) (uVar1), (int) (iVar3));
        if (iVar2 == 1) {
            break;
        }
        iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    func_ov000_021ae258();
    if (iVar2 == 1) {
        return 1;
    }
    return 0;
}
