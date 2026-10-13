/* Decompiled C draft; module arm7; ROM address 060149b0. No matching claim. */
#include "types.h"
#include "deps/060149b0_FUN_060149b0.h"

void FUN_060149b0(undefined2 *param_1)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = (uint)(param_1 + 4) & 3;
  uVar3 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
  uVar2 = *(ushort *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 4);
  iVar4 = (*(uint *)(DAT_060149fc & 0xfffffffc) >> (DAT_060149fc & 3) * 8 |
          *(uint *)(DAT_060149fc & 0xfffffffc) << (DAT_060149fc & 3) * -8 + 0x20) + DAT_06014a00;
  if ((uVar2 & 0xff) == 0) {
    uVar1 = iVar4 + 0x6cU & 3;
    uVar3 = *(uint *)(iVar4 + 0x6cU & 0xfffffffc);
    *(uint *)(iVar4 + 0x6c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
  }
  else {
    uVar1 = iVar4 + 0x68U & 3;
    uVar3 = *(uint *)(iVar4 + 0x68U & 0xfffffffc);
    *(uint *)(iVar4 + 0x68) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  }
  param_1[2] = param_1[2] + 1;
  *param_1 = 0;
  return;
}

