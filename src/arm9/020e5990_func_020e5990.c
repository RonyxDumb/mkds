/* Decompiled C draft; module arm9; ROM address 020e5990. No matching claim. */
#include "types.h"
#include "deps/020e5990_func_020e5990.h"

void func_020e5990(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = uRam020e59e0;
  uVar1 = param_2 + 4U & 3;
  uVar3 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(param_2 + 0x4c) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8U & 3;
  uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(param_2 + 0x50) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xcU & 3;
  uVar3 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(param_2 + 0x54) = (int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  func_020ea8a8(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_2 + 0x28,param_2 + 0x1c);
  return;
}

