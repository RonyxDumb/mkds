/* Decompiled C draft; module arm9; ROM address 020d7b88. No matching claim. */
#include "types.h"
#include "deps/020d7b88_func_020d7b88.h"

void func_020d7b88(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = param_1 + 4 & 3;
  uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
  iVar3 = FX_Sqrt(((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x1000) * 2);
  uVar1 = param_1 + 8 & 3;
  uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc);
  FX_DivAsync(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,iVar3);
  param_2[1] = 0;
  uVar4 = FX_GetDivResult();
  *param_2 = uVar4;
  FX_DivAsync(-(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20),iVar3);
  param_2[3] = iVar3 >> 1;
  uVar4 = FX_GetDivResult();
  param_2[2] = uVar4;
  return;
}

