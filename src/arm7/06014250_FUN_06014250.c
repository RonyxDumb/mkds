/* Decompiled C draft; module arm7; ROM address 06014250. No matching claim. */
#include "types.h"
#include "deps/06014250_FUN_06014250.h"

void FUN_06014250(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(DAT_0601428c & 0xfffffffc) >> (DAT_0601428c & 3) * 8 |
          *(uint *)(DAT_0601428c & 0xfffffffc) << (DAT_0601428c & 3) * -8 + 0x20;
  iVar3 = uVar2 + DAT_06014290;
  *(undefined2 *)(uVar2 + 0x4a4) = 1;
  uVar2 = iVar3 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *DAT_06014298 =
       (ushort)(((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & DAT_06014294) >> 1) | 0x8000;
  return;
}

