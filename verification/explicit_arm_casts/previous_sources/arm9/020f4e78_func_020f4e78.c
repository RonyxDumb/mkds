/* Decompiled C draft; module arm9; ROM address 020f4e78. No matching claim. */
#include "types.h"
#include "deps/020f4e78_func_020f4e78.h"

void func_020f4e78(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *(undefined4 *)(param_1 + 0x134) = 1;
  func_0208ad74(param_1 + 0x7c);
  if (param_2 != (undefined4 *)0x0) {
    uVar3 = param_2[1];
    uVar4 = param_2[2];
    *(undefined4 *)(param_1 + 0xf0) = *param_2;
    *(undefined4 *)(param_1 + 0xf4) = uVar3;
    *(undefined4 *)(param_1 + 0xf8) = uVar4;
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x80;
  }
  if (param_3 != (undefined4 *)0x0) {
    uVar3 = param_3[1];
    uVar4 = param_3[2];
    *(undefined4 *)(param_1 + 0x50) = *param_3;
    *(undefined4 *)(param_1 + 0x54) = uVar3;
    *(undefined4 *)(param_1 + 0x58) = uVar4;
    VecFx32_Subtract((undefined4 *)(param_1 + 0x50),param_1 + 0xe4,param_1 + 0x5c);
    return;
  }
  return;
}

