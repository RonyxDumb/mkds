/* Decompiled C draft; module arm9; ROM address 02021db0. No matching claim. */
#include "types.h"
#include "deps/02021db0_func_02021db0.h"

int func_02021db0(ushort *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 < *param_1) {
    uVar1 = (uint)(param_1 + 2) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_2 * 0x10;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}

