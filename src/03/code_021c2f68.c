#include "03/code_021c2f68.h"
#include "03/code_021c2f44.h"

void func_ov003_021c2f98(void) {
    func_ov003_021d1ee0((int) (2), (int) (1), (u32) (1), (u16) (8));
    func_ov003_021d1ee0((int) (2), (int) (0), (u32) (0x14), (u16) (8));
    func_ov003_021d2784((int) (1), (u32) (1));
    func_ov003_021d2784((int) (0), (u32) (0x14));
    func_ov003_021c212c(func_ov003_021c2f68);
    return;
}

void func_ov003_021c2f68(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if ((iVar1 == 0) && (iVar1 = func_ov003_021d1f70((int) (0)), iVar1 == 0)) {
        func_ov003_021bf5c8((u32) (0));
        func_ov003_021c212c(func_ov003_021c2f44);
    }
    return;
}
