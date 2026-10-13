/* Decompiled C draft; module arm9; ROM address 020d84c0. No matching claim. */
#include "types.h"
#include "deps/020d84c0_func_020d84c0.h"

void func_020d84c0(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  bool bVar3;
  uint uVar2;
  
  uVar2 = param_1 + 0x34U & 3;
  uVar1 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  bVar3 = uVar2 != 0;
  if (bVar3) {
    param_4 = (uint)((longlong)param_2 * (longlong)(int)uVar2);
    uVar2 = (uint)((ulonglong)((longlong)param_2 * (longlong)(int)uVar2) >> 0x20);
  }
  *(int *)(param_1 + 0x54) = param_2;
  if (bVar3) {
    uVar2 = param_4 >> 0xc | uVar2 << 0x14;
  }
  else {
    uVar2 = 0x1000000;
  }
  *(uint *)(param_1 + 0x58) = uVar2;
  return;
}

