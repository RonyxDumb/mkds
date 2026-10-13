/* Decompiled C draft; module arm9; ROM address 020e34f8. No matching claim. */
#include "types.h"
#include "deps/020e34f8_func_020e34f8.h"

void func_020e34f8(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = iRam020e3534;
  uVar1 = param_1 + 8U & 3;
  uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar5 = param_1 + 0x14U & 3;
  uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) +
       (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  uVar1 = param_1 + 0xacU & 3;
  uVar6 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
  uVar5 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  iVar2 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + iVar2;
  iVar3 = iVar2;
  if (iVar2 < (int)uVar5) {
    *(int *)(param_1 + 8) = iVar2;
    iVar3 = 2;
  }
  if (iVar2 < (int)uVar5) {
    *(short *)(param_1 + 0x90) = (short)iVar3;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

