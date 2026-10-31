#include "03/code_021c36ec.h"
#include "03/code_021c36c8.h"
#include "03/code_021d254c.h"

void func_ov003_021c371c(void) {
    func_ov003_021d1ee0((int) (2), (int) (1), (u32) (1), (u16) (8));
    func_ov003_021d1ee0((int) (2), (int) (0), (u32) (0x15), (u16) (8));
    func_ov003_021d2784((int) (1), (u32) (1));
    func_ov003_021d2784((int) (0), (u32) (0x15));
    func_ov003_021c212c(func_ov003_021c36ec);
    return;
}

void func_ov003_021c36ec(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70((int) (1));
    if ((iVar1 == 0) && (iVar1 = func_ov003_021d1f70((int) (0)), iVar1 == 0)) {
        func_ov003_021bf5c8((u32) (2));
        func_ov003_021c212c(func_ov003_021c36c8);
    }
    return;
}
