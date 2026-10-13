/* Decompiled C draft; module arm9; ROM address 020f99b8. No matching claim. */
#include "types.h"
#include "deps/020f99b8_func_020f99b8.h"

void func_020f99b8(int param_1,undefined4 param_2,undefined2 param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar4 = param_4[1];
  uVar5 = param_4[2];
  *(undefined4 *)(param_1 + 0x50) = *param_4;
  *(undefined4 *)(param_1 + 0x54) = uVar4;
  *(undefined4 *)(param_1 + 0x58) = uVar5;
  *(undefined2 *)(param_1 + 0x78) = param_3;
  func_020f9a14(param_1,param_2);
  uVar1 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x8000000) != 0) {
    uVar2 = func_020ff178(param_1);
    *(undefined2 *)(param_1 + 0x4e) = uVar2;
    return;
  }
  return;
}

