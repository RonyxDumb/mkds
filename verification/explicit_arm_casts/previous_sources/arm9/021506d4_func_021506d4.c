/* Decompiled C draft; module arm9; ROM address 021506d4. No matching claim. */
#include "types.h"
#include "deps/021506d4_func_021506d4.h"

void func_021506d4(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  uint uVar3;
  
  uVar4 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar3 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar1 = uVar3 & 0x3f;
  uVar4 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) = uVar3 + param_3;
  uVar5 = 0x40 - uVar1;
  *(uint *)(param_1 + 0x14) =
       (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + (uint)CARRY4(uVar3,param_3);
  if (param_3 < uVar5) {
    if (param_3 != 0) {
      Mem_CpuCopy8(param_2,param_1 + 0x18 + uVar1);
      return;
    }
    return;
  }
  Mem_CpuCopy8(param_2,param_1 + 0x18 + uVar1,uVar5);
  func_02150228(param_1);
  uVar4 = param_3 - uVar5 >> 6;
  param_2 = param_2 + uVar5;
  if (uVar4 != 0) {
    do {
      Mem_CpuCopy8(param_2,param_1 + 0x18,0x40);
      param_2 = param_2 + 0x40;
      func_02150228(param_1);
      uVar4 = uVar4 - 1;
    } while (0 < (int)uVar4);
  }
  if ((param_3 - uVar5 & 0x3f) != 0) {
    Mem_CpuCopy8(param_2,param_1 + 0x18);
    return;
  }
  return;
}

