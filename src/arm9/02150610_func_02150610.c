/* Decompiled C draft; module arm9; ROM address 02150610. No matching claim. */
#include "types.h"
#include "deps/02150610_func_02150610.h"

void func_02150610(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_2 + 0x14U & 3;
  uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  uVar3 = param_2 + 0x10U & 3;
  uVar4 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  func_021506d4(param_2,uRam021506d0,1);
  uVar3 = param_2 + 0x10U & 3;
  uVar4 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  uVar4 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x3f;
  uVar3 = 0x40 - uVar4;
  if (uVar3 < 8) {
    Mem_CpuFill8(param_2 + 0x18 + uVar4,0);
    func_02150228((int *)(uintptr_t)(param_2));
    uVar4 = 0;
    uVar3 = 0x40;
  }
  if (8 < uVar3) {
    Mem_CpuFill8((uint *)(uintptr_t)(param_2 + 0x18 + uVar4),0,uVar3 - 8);
  }
  *(uint *)(param_2 + 0x50) = uVar5 << 3;
  *(uint *)(param_2 + 0x54) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 3 | uVar5 >> 0x1d
  ;
  func_02150228((int *)(uintptr_t)(param_2));
  Mem_CpuCopy8((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(param_1),0x10);
  Mem_CpuFill8((uint *)(uintptr_t)(param_2),0,0x58);
  return;
}

