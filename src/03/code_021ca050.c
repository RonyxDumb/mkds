#include "03/code_021ca050.h"
#include "03/code_021ca028.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021ca0d4(void) {
    func_ov003_021ca028();
    func_ov003_021ca0d0();
    return;
}

void func_ov003_021ca0d0(void) {
    return;
}

void func_ov003_021ca0a4(void) {
    func_ov003_021d1ee0(3, 1, (u32) (1), (u16) (8));
    func_ov003_021d1ee0(3, 0, (u32) (0x15), (u16) (8));
    func_ov003_021c212c(func_ov003_021ca050);
    return;
}

void func_ov003_021ca050(void) {
    int iVar1;
    iVar1 = func_ov003_021d1f70(1);
    if ((iVar1 == 0) && (iVar1 = func_ov003_021d1f70(0), iVar1 == 0)) {
        func_ov003_021d2168(0);
        func_ov003_021bf410();
        func_ov003_021d272c(1, (u32) (1));
        func_ov003_021d272c(0, (u32) (0x15));
        func_ov003_021c2120((u32) (0), (u32) (0));
        func_ov003_021c20f8((u32) (0), (u32) (1));
        func_ov003_021c212c(func_ov003_021cbf60);
    }
    return;
}
