#include "00/code_021a10b0.h"

void func_ov000_021a10b0(u8 param_1, u8 param_2, u32 param_3, u32 param_4) {
    int *piVar1;
    func_ov000_021a1140((int) (0));
    piVar1 = (int *) &data_ov000_021b566c;
    *(u8 *) ((*(int *) &data_ov000_021b566c) + 0x15) = param_1;
    *(u8 *) (*piVar1 + 0x16) = param_2;
    *(u32 *) (*piVar1 + ((int) 0x0000044cu)) = param_3;
    *(u32 *) (*piVar1 + ((int) 0x00000450u)) = param_4;
    *(u8 *) (*piVar1 + ((int) 0x00000175u)) = 0;
    *(u8 *) (*piVar1 + ((int) 0x000002b8u)) = 0;
    func_ov000_021a4b84((int) (0x32), data_ov000_021b40c4);
    func_ov000_021a4b84((int) (0x33), data_ov000_021b40f0);
    func_ov000_021a4b84((int) (0x34), data_ov000_021b40fc);
    func_ov000_021a4b84((int) (0x35), data_ov000_021b4108);
    func_ov000_021a4b84((int) (0x36), data_ov000_021b40cc);
    return;
}
