#include "Main/Unknown/code_0208ec64.h"
#include "code_020172d0.h"

// non-matching: 0x98 bytes, original 0x74; 42 lines differ; first: original `push {r4, r5, lr}`, ours `push {r4, r5,
// r6, lr}`
int func_0208ec64(u32 param_1) {
    u32 uVar1;
    int iVar2;
    u32 uVar3;
    iVar2 = func_020172d8((Unk02017328 *) ((*(u32 *) &data_0217b08c) + 0xc), (int) (0));
    if (iVar2 != 0) {
        *(u32 *) (iVar2 + 0x14) = param_1;
        *(u32 *) (iVar2 + 0x18) = 0;
        uVar3 = ((u32) (&data_0217b08c));
        *(u32 *) (iVar2 + 0x1c) = 0x400;
        uVar1 = uVar3 & 3;
        uVar3 = *(u32 *) (uVar3 & 0xfffffffc);
        func_02017354((Unk02017328 *) ((u32 *) (u32) ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xc)),
                      (void *) (iVar2));
        func_020174a4(
            (Unk02017328 *) (*(u32 *) (((u32) (&data_0217b08c)) & 0xfffffffc) >> (((u32) (&data_0217b08c)) & 3) * 8 |
                             *(u32 *) (((u32) (&data_0217b08c)) & 0xfffffffc)
                                 << (((u32) (&data_0217b08c)) & 3) * -8 + 0x20),
            (void *) (iVar2));
    }
    return iVar2;
}
