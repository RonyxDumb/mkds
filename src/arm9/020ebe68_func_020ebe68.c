/* Decompiled C draft; module arm9; ROM address 020ebe68. No matching claim. */
#include "types.h"
#include "deps/020ebe68_func_020ebe68.h"

void func_020ebe68(int param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  
  uVar1 = param_1 + 0x84U & 3;
  uVar4 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < 900) {
    return;
  }
  uVar1 = param_1 + 0x9cU & 3;
  uVar4 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  if (*(short *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x2c) == 0) {
    bVar2 = *(uint *)((uint)piRam020ebea8 & 0xfffffffc) >> ((uint)piRam020ebea8 & 3) * 8 == 0;
    bVar3 = *(uint *)((uint)piRam020ebea8 & 0xfffffffc) << ((uint)piRam020ebea8 & 3) * -8 + 0x20 ==
            0;
    piVar5 = piRam020ebea8;
    if (bVar2 && bVar3) {
      *piRam020ebea8 = param_1;
      piVar5 = (int *)0x2;
    }
    if (bVar2 && bVar3) {
      *(short *)(param_1 + 0x90) = (short)piVar5;
      *(undefined2 *)(param_1 + 0x92) = 1;
    }
    return;
  }
  return;
}

