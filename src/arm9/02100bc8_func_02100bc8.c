/* Decompiled C draft; module arm9; ROM address 02100bc8. No matching claim. */
#include "types.h"
#include "deps/02100bc8_func_02100bc8.h"

void func_02100bc8(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar2 = param_1 + 0x268U & 3;
  uVar4 = *(uint *)(param_1 + 0x268U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x10000000) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 0xf;
  }
  *(uint *)(param_1 + 0x268) = iVar5 - (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x24c) = 0;
  return;
}

