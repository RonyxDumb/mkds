/* Decompiled C draft; module arm7; ROM address 0600e47c. No matching claim. */
#include "types.h"
#include "deps/0600e47c_FUN_0600e47c.h"

void FUN_0600e47c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_060145f8();
  uVar1 = DAT_0600e4c0;
  uVar3 = (*(uint *)(DAT_0600e4c0 & 0xfffffffc) >> (DAT_0600e4c0 & 3) * 8 |
          *(uint *)(DAT_0600e4c0 & 0xfffffffc) << (DAT_0600e4c0 & 3) * -8 + 0x20) + 0x31c;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(undefined2 *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + param_1 * 0x1c) = 0;
  uVar3 = uVar1 & 3;
  uVar2 = *(uint *)(uVar1 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  *(short *)(uVar3 + 0x52c) = *(short *)(uVar3 + 0x52c) + -1;
  return;
}

