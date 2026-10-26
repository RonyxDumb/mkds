#include "00/code_0218da04.h"

void func_ov000_0218da5c(int *param_1, int param_2) {
    if ((param_2 < 0) || (param_2 >= *param_1)) {
        func_0213442c((u32) (((u32) ((u32) (&data_ov000_021b22e8)))), (u32) (((u32) ((u32) (&data_ov000_021b22dc)))),
                      (u32) (0), (u32) (0xca));
    }
    func_ov000_0218dd74(param_1, param_2);
    func_ov000_0218da9c((int *) (param_1), (int) (param_2));
    return;
}

void func_ov000_0218da1c(int *param_1, u32 param_2, int param_3) {
    if ((param_3 < 0) || (param_3 >= *param_1)) {
        func_0213442c((u32) (((u32) ((u32) (&data_ov000_021b22e8)))), (u32) (((u32) ((u32) (&data_ov000_021b22dc)))),
                      (u32) (0), (u32) (0xd3));
    }
    func_ov000_0218dd74(param_1, param_3);
    func_ov000_0218dd18((int) ((int) (u32) (param_1)), (u32) (param_2), (u32) (param_3));
    return;
}

void func_ov000_0218da04(unsigned int p0, unsigned int p1) {
    unsigned int v2 = ((p0) + (0x0u));
    unsigned int v3 = ((p1) + (0x0u));
    unsigned int v4 = ((unsigned int) *(unsigned int *) ((v2) + (20)));
    unsigned int v5 = ((unsigned int) *(unsigned int *) ((v2) + (0)));
    unsigned int v6 = ((unsigned int) *(unsigned int *) ((v2) + (8)));
    func_021382a8((u8 *) (v4), (unsigned int) (v5), (unsigned int) (v6), (int (*)(void *, void *))(v3));
}
