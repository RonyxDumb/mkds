#include "03/code_021c6a18.h"

void func_ov003_021c6a18(void) {
    s32 local_10;
    int local_c[1];
    func_ov003_021bf410();
    func_ov003_021d2f00((u32 *) (u32) ((u32) data_ov003_021da1f8->mUnk_04));
    func_ov003_021d2168((int) 0);
    func_ov003_021bf620((u32) &data_ov003_021d728c, (u32) &func_0214c090);
    func_ov003_021d272c((int) 1, (u32) 1);
    func_ov003_021d272c((int) 0, (u32) 0x15);
    func_ov003_021c20dc(&local_10, local_c);
    if (local_c[0] == 0) {
        func_ov003_021c2120((u32) 2, (u32) 1);
        func_ov003_021c20f8((u32) 0, (u32) local_10);
        func_ov003_021c212c(func_ov003_021c965c);
    } else if (*(u8 *) ((*(int *) &data_ov003_021da1f8) + 0x2a) == 0) {
        func_ov003_021c2120((u32) 0, (u32) 1);
        func_ov003_021c20f8((u32) 1, (u32) 0);
        func_ov003_021c212c(func_ov003_021c6668);
    } else {
        func_ov003_021c2120((u32) 0, (u32) 0);
        func_ov003_021c20f8((u32) 0, (u32) 1);
        func_ov003_021c212c(func_ov003_021cbf60);
    }
    func_ov003_021d2808((int *) &data_ov003_021da1f8);
}
