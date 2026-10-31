#include "03/code_021c91fc.h"

u32 func_ov003_021c91fc(void) {
    int iVar1;
    int iVar2;
    func_ov003_021cdb6c();
    iVar1 = func_ov003_021c8400();
    if (iVar1 == 0xe) {
        return 0;
    }
    iVar2 = func_ov003_021c8904(iVar1);
    if (iVar2 == 0) {
        func_ov003_021cdc10((u32) (9));
        return 1;
    }
    func_ov003_021c8100(iVar1);
    switch (iVar1) {
        case 2:
        case 3:
        case 7:
        case 8:
            func_ov003_021c7e20();
    }
    func_ov003_021c90dc(iVar1);
    return 1;
}
