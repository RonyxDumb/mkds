#include "00/code_0218da04.h"

void func_ov000_0218da5c(Unk0218dc94 *param_1, s32 param_2) {
    if ((param_2 < 0) || (param_2 >= param_1->mUnk_00)) {
        func_0213442c(data_ov000_021b22e8, data_ov000_021b22dc, 0, 0xca);
    }
    func_ov000_0218dd74(param_1, param_2);
    func_ov000_0218da9c((int *) (param_1), (int) (param_2));
    return;
}

void func_ov000_0218da1c(Unk0218dc94 *param_1, const void *param_2, s32 param_3) {
    if ((param_3 < 0) || (param_3 >= param_1->mUnk_00)) {
        func_0213442c(data_ov000_021b22e8, data_ov000_021b22dc, 0, 0xd3);
    }
    func_ov000_0218dd74(param_1, param_3);
    func_ov000_0218dd18(param_1, param_2, param_3);
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
