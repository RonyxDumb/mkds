/* Decompiled C draft; module arm9; ROM address 020ee6e8. No matching claim. */
#include "types.h"
#include "deps/020ee6e8_func_020ee6e8.h"

void func_020ee6e8(int param_1,int param_2,undefined4 param_3)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = param_1 + 0x20U & 3;
  uVar2 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  iVar4 = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) - 1;
  if (param_2 != iVar4) {
    iVar3 = param_1 + iVar4 * 2;
    iVar6 = param_1 + iVar4 * 4;
    uVar1 = *(undefined2 *)(iVar3 + 0x18c);
    uVar5 = iVar6 + 0x14;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    iVar4 = param_1 + param_2 * 2;
    *(undefined4 *)(iVar6 + 0x14) = param_3;
    *(undefined2 *)(iVar3 + 0x18c) = *(undefined2 *)(iVar4 + 0x18c);
    *(uint *)(param_1 + param_2 * 4 + 0x14) = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    *(undefined2 *)(iVar4 + 0x18c) = uVar1;
  }
  func_020efa48(param_1,param_3);
  return;
}

