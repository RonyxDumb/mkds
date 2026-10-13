/* Decompiled C draft; module arm9; ROM address 0208bea4. No matching claim. */
#include "types.h"
#include "deps/0208bea4_func_0208bea4.h"

void func_0208bea4(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar3;
  
  uVar2 = param_3 + 0x28U & 3;
  uVar5 = *(uint *)(param_3 + 0x28U & 0xfffffffc);
  uVar2 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0x20;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  puVar3 = (undefined4 *)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
  uVar1 = puVar3[1];
  uVar4 = puVar3[2];
  *param_1 = *puVar3;
  param_1[1] = uVar1;
  param_1[2] = uVar4;
  uVar1 = *(undefined4 *)(param_3 + 0x34);
  uVar4 = *(undefined4 *)(param_3 + 0x38);
  *param_2 = *(undefined4 *)(param_3 + 0x30);
  param_2[1] = uVar1;
  param_2[2] = uVar4;
  return;
}

