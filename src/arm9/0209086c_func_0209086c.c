/* Decompiled C draft; module arm9; ROM address 0209086c. No matching claim. */
#include "types.h"
#include "deps/0209086c_func_0209086c.h"

void func_0209086c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = GetDriverEntry(param_2);
  uVar2 = uRam020908cc;
  *(short *)(param_1 + 0x24) = (short)param_2;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = param_2 * 0x210 + (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x1f0;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  func_0207ffa4((uint *)(uintptr_t)(param_1),param_2,uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  *(undefined2 *)(param_1 + 0x26) = 0;
  *(undefined2 *)(param_1 + 0x28) = 0;
  *(undefined2 *)(iVar1 + 0x388) = 0;
  DriverContext_ApplyDriftBoost(iVar1);
  return;
}

