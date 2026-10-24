#include "03/code_021c722c.h"

// non-matching: 9 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4, lr}`
void func_ov003_021c722c(void) {
    int local_8[1];
    func_ov003_021bf410();
    func_ov003_021d2f00((u32 *) (u32) (*(u32 *) (*((int *) ((u32) (&data_ov003_021da1fc))) + 4)));
    func_ov003_021d2168((int) (0));
    func_ov003_021bf620((unsigned int) (((u32) ((u32) (&data_ov003_021d7338)))),
                        (unsigned int) (((u32) ((u32) (&func_0214c090)))));
    func_ov003_021d272c((int) (1), (u32) (1));
    func_ov003_021d272c((int) (0), (u32) (0x15));
    func_ov003_021c20dc(local_8, 0);
    if (3 <= local_8[0]) {
        local_8[0] = local_8[0] + 1;
    }
    func_ov003_021c2120((u32) (2), (u32) (1));
    func_ov003_021c20f8((u32) (0), (u32) (local_8[0] + 3));
    func_ov003_021c212c((u32) (((u32) ((u32) (&func_ov003_021c965c)))));
    func_ov003_021d2808(((int *) ((u32) (&data_ov003_021da1fc))));
    return;
}
