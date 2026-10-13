/* Decompiled C draft; module arm9; ROM address 020e01f0. No matching claim. */
#include "types.h"
#include "deps/020e01f0_func_020e01f0.h"

void func_020e01f0(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (*(short *)(param_2 + 0x16c) == 0) {
    iVar3 = func_020d8cc8(param_2 + 0x144);
    if (iVar3 != 0) {
      if (*(short *)(param_2 + 0x8e) == 2) {
        *(undefined2 *)(param_2 + 0x90) = 0;
        *(undefined2 *)(param_2 + 0x92) = 1;
      }
      uVar1 = param_2 + 0x160U & 3;
      uVar2 = *(uint *)(param_2 + 0x160U & 0xfffffffc);
      *(undefined2 *)(param_2 + 0x16c) =
           *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xe);
    }
    *(undefined4 *)(param_2 + 0xe8) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(param_2 + 0xec) = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)(param_2 + 0xf0) = *(undefined4 *)(param_2 + 0xc);
    func_020d8a5c(param_2 + 0x144,(undefined4 *)(param_2 + 4));
    StateDualHandler_Execute(param_2 + 0x80);
    VecFx32_Subtract(param_2 + 4,param_2 + 0xe8,param_2 + 0x10);
    uVar1 = param_2 + 0x104U & 3;
    uVar2 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
    VecFx32_AddScale1(-(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20),param_2 + 0x34,param_2 + 4,
                      param_2 + 0xf4);
    return;
  }
  *(short *)(param_2 + 0x16c) = *(short *)(param_2 + 0x16c) + -1;
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0;
  if (*(short *)(param_2 + 0x16c) == 0) {
    uVar1 = param_2 + 0x78U & 3;
    uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 4) == 0) {
      uVar1 = param_2 + 0x70U & 3;
      uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
      uVar4 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar1 = iRam020e0338 + 0x68U & 3;
      uVar2 = *(uint *)(iRam020e0338 + 0x68U & 0xfffffffc);
      if (uVar4 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
        uStack_18 = 2;
      }
      else {
        uVar1 = iRam020e0338 + 0x8cU & 3;
        uVar2 = *(uint *)(iRam020e0338 + 0x8cU & 0xfffffffc);
        if (uVar4 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
          uStack_18 = 3;
        }
        else {
          uStack_18 = 4;
        }
      }
      iStack_1c = param_2 + 4;
      uStack_20 = uRam020e033c;
      uStack_14 = func_020d4ef4();
      func_0210b7a8(&uStack_20);
      return;
    }
    return;
  }
  return;
}

