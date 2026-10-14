/* Decompiled C draft; module arm9; ROM address 020815dc. No matching claim. */
#include "types.h"
#include "deps/020815dc_func_020815dc.h"

void func_020815dc(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = param_1 * 0x58 +
          (*(uint *)(uRam02081614 & 0xfffffffc) >> (uRam02081614 & 3) * 8 |
          *(uint *)(uRam02081614 & 0xfffffffc) << (uRam02081614 & 3) * -8 + 0x20);
  uVar3 = iVar4 + 0x2c;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (uVar3 == 0) {
    return;
  }
  uVar1 = uVar3 + 0x24 & 3;
  uVar2 = *(uint *)(uVar3 + 0x24 & 0xfffffffc);
  *(uint *)(uVar3 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffe | 1;
  *(undefined4 *)(iVar4 + 0x2c) = 0;
  return;
}

