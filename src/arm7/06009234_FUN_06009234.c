/* Decompiled C draft; module arm7; ROM address 06009234. No matching claim. */
#include "types.h"
#include "deps/06009234_FUN_06009234.h"

void FUN_06009234(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = DAT_060092d0;
  uVar1 = *(uint *)(DAT_060092d0 & 0xfffffffc) >> (DAT_060092d0 & 3) * 8 |
          *(uint *)(DAT_060092d0 & 0xfffffffc) << (DAT_060092d0 & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x33e) = *(ushort *)(uVar1 + 0x33e) | 0x8000;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (*(short *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x34c) != 0) {
    FUN_06009ecc();
    uVar1 = DAT_060092d0;
    uVar2 = *(uint *)(DAT_060092d0 & 0xfffffffc) >> (DAT_060092d0 & 3) * 8 |
            *(uint *)(DAT_060092d0 & 0xfffffffc) << (DAT_060092d0 & 3) * -8 + 0x20;
    if (*(short *)(uVar2 + 0x404) != 0) {
      *(undefined2 *)(uVar2 + 0x404) = 0;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      uVar1 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x420;
      uVar2 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      *(undefined2 *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 4) = 6;
      FUN_0600fafc();
    }
    FUN_0600ad78();
  }
  do {
    iVar3 = FUN_06008a04(3);
  } while (iVar3 != DAT_060092d4);
  FUN_06008a8c(3,0x17);
  return;
}

