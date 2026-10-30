#include "00/code_02189478.h"

u8 func_ov000_021894c0(void) {
    int iVar1;
    iVar1 = func_ov000_02188584((u32) (1));
    iVar1 = func_ov000_021892f4((u8 *) ((u8 *) (u32) (iVar1 + 10)));
    if (iVar1 == 1) {
        return 0x12;
    }
    return 0x11;
}

u32 func_ov000_02189478(void) {
    u32 uVar1;
    int iVar2;
    uVar1 = func_ov000_02188584((u32) (1));
    iVar2 = func_ov000_021884fc();
    if (iVar2 < 4) {
        return func_ov000_02189440();
    }
    if (iVar2 < 5) {
        return func_ov000_02189438();
    }
    if (iVar2 == 5) {
        return func_ov000_02189420((int) (uVar1));
    }
    return func_ov000_02189350((int) (uVar1));
}
