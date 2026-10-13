/* Decompiled C draft; module arm9; ROM address 02150994. No matching claim. */
#include "types.h"
#include "deps/02150994_func_02150994.h"

void func_02150994(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = (int)(param_3 + ((uint)(param_3 >> 5) >> 0x1a)) >> 6;
  iVar4 = 0;
  if (iVar1 < 1) {
    return;
  }
  do {
    uVar2 = param_2 + 0x18U & 3;
    uVar6 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
    uVar3 = param_2 + 0x38U & 3;
    uVar5 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x38) = 0;
    func_02150e1c((uint *)(uintptr_t)(param_1),param_2,0x40);
    *(uint *)(param_2 + 0x18) = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
    iVar4 = iVar4 + 1;
    *(uint *)(param_2 + 0x38) = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    param_2 = param_2 + 0x40;
  } while (iVar4 < iVar1);
  return;
}

