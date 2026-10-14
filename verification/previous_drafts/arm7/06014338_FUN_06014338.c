/* Decompiled C draft; module arm7; ROM address 06014338. No matching claim. */
#include "types.h"
#include "deps/06014338_FUN_06014338.h"

void FUN_06014338(int param_1)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  
  uVar2 = FUN_0600ef30((ushort *)(uintptr_t)(param_1 + 0x18));
  *(undefined2 *)(param_1 + 2) = uVar2;
  if (*(short *)(param_1 + 2) == 0xff) {
    *(undefined2 *)(param_1 + 2) = 0;
  }
  uVar3 = (*(uint *)(DAT_060143a8 & 0xfffffffc) >> (DAT_060143a8 & 3) * 8 |
          *(uint *)(DAT_060143a8 & 0xfffffffc) << (DAT_060143a8 & 3) * -8 + 0x20) + 0x3ec;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(ushort *)(param_1 + 4) = (ushort)(uVar3 >> uVar1 * 8) | (ushort)(uVar3 << uVar1 * -8 + 0x20);
  if ((*(ushort *)(param_1 + 0x14) & 0x4000) != 0) {
    *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + 8;
  }
  FUN_0600ecf4(param_1);
  uVar3 = *(uint *)(DAT_060143a8 & 0xfffffffc) >> (DAT_060143a8 & 3) * 8 |
          *(uint *)(DAT_060143a8 & 0xfffffffc) << (DAT_060143a8 & 3) * -8 + 0x20;
  FUN_06009040(uVar3 + 0x188,uVar3 + 0x1a0,param_1 + -0x10);
  return;
}

