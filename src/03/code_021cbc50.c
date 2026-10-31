#include "03/code_021cbc50.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021cbd0c(void) {
    func_ov003_021cbc00();
    func_ov003_021cbd08();
    return;
}

void func_ov003_021cbd08(void) {
    return;
}

void func_ov003_021cbcc8(void) {
    int local_8[1];
    func_ov003_021c20dc(0, local_8);
    if (local_8[0] != 0) {
        func_ov003_021ce0c4();
    }
    func_ov003_021d1ee0((int) (3), (int) (1), (u32) (1), (u16) (8));
    func_ov003_021d1ee0((int) (3), (int) (0), (u32) (0x15), (u16) (8));
    func_ov003_021c212c(func_ov003_021cbc50);
    return;
}

void func_ov003_021cbc50(void) {
    int iVar1;
    int local_8[1];
    iVar1 = func_ov003_021d1f70((int) (1));
    if (((iVar1 == 0) && (iVar1 = func_ov003_021d1f70((int) (0)), iVar1 == 0)) &&
        (iVar1 = func_ov003_021cdd28(), iVar1 != 0)) {
        func_ov003_021d2168((int) (0));
        func_ov003_021bf410();
        func_ov003_021d272c((int) (1), (u32) (1));
        func_ov003_021d272c((int) (0), (u32) (0x15));
        func_ov003_021c2120((u32) (2), (u32) (1));
        func_ov003_021c20dc(0, local_8);
        if (local_8[0] == 0) {
            func_ov003_021c20f8((u32) (0), (u32) (0));
            func_ov003_021c212c(func_ov003_021c965c);
            return;
        }
        func_ov003_021c212c(func_ov003_021c3078);
    }
    return;
}
