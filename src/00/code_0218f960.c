#include "00/code_0218f960.h"

// non-matching: 0x134 bytes, original 0x138; 19 instructions differ; first at +0x14: original `ldr r1, [pc, #0xe8]
// (->0x100)`, ours `ldr r1, [pc, #0xe4] (->0xfc)`
u32 func_ov000_0218f960(int *param_1, u32 param_2) {
    int iVar1;
    int iVar2;
    int *piVar3;
    int iVar4;
    u32 *local_18[2];
    iVar4 = *param_1;
    iVar1 = func_ov000_02194934(param_1, param_2, (int *) (void *) (local_18));
    if (iVar1 == 0) {
        func_ov000_02196590(param_1, ((u32) ((u32) (&data_ov000_021b273c))));
        return 2;
    }
    func_ov000_02190b80((unsigned int) ((u32) (u32) (param_1)), (unsigned int) (iVar4 + ((int) 0x000001f4u)),
                        (unsigned int) (((u32) ((u32) (&data_ov000_021b2750)))));
    func_ov000_02190b80((unsigned int) ((u32) (u32) (param_1)), (unsigned int) (iVar4 + ((int) 0x000001f4u)),
                        (unsigned int) (((u32) ((u32) (&data_ov000_021b275c)))));
    func_ov000_02190b58(param_1, iVar4 + ((int) 0x000001f4u), *(u32 *) (iVar4 + ((int) 0x00000198u)));
    func_ov000_02190b80((unsigned int) ((u32) (u32) (param_1)), (unsigned int) (iVar4 + ((int) 0x000001f4u)),
                        (unsigned int) (((u32) ((u32) (&data_ov000_021b2768)))));
    func_ov000_02190b58(param_1, iVar4 + ((int) 0x000001f4u), *local_18[0]);
    func_ov000_02190b80((unsigned int) ((u32) (u32) (param_1)), (unsigned int) (iVar4 + ((int) 0x000001f4u)),
                        (unsigned int) (((u32) ((u32) (&data_ov000_021b2778)))));
    if ((int *) local_18[0][2] != (int *) 0x0) {
        iVar1 = *(int *) local_18[0][2];
        if (iVar1 < 0) {
            func_0213442c(data_ov000_021b2780, data_ov000_021b278c, 0, 0x1fd);
        }
        func_ov000_021a3668((u32) (*(u32 *) (local_18[0][2] + 8)));
        *(u32 *) (local_18[0][2] + 8) = 0;
        func_ov000_021a3668((u32) (*(u32 *) (local_18[0][2] + 0xc)));
        *(u32 *) (local_18[0][2] + 0xc) = 0;
        func_ov000_021a3668((u32) (local_18[0][2]));
        local_18[0][2] = 0;
        iVar2 = func_ov000_021947e4((int) ((int) (u32) (local_18[0])));
        if (iVar2 != 0) {
            func_ov000_021948f8(param_1, local_18[0]);
        }
        piVar3 = (int *) (iVar4 + ((int) 0x00000430u));
        *piVar3 = *piVar3 + -1;
        if (*piVar3 < 0) {
            func_0213442c(data_ov000_021b2798, data_ov000_021b278c, 0, 0x204);
        }
        func_ov000_02194840(param_1, ((u32) ((u32) (&func_ov000_0218fa98))), iVar1);
    }
    return 0;
}
