/* Decompiled C draft; module arm9; ROM address 020beb40. No matching claim. */
#include "types.h"
#include "deps/020beb40_func_020beb40.h"

void func_020beb40(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  puVar1 = puRam020beb98;
  iVar5 = 0;
  uVar4 = *(uint *)((uint)puRam020beb98 & 0xfffffffc) >> ((uint)puRam020beb98 & 3) * 8 |
          *(uint *)((uint)puRam020beb98 & 0xfffffffc) << ((uint)puRam020beb98 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0xc & 3;
  uVar2 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  if (0 < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
    do {
      uVar3 = uVar4 + iVar5 * 4 + 0x10;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      (*(code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20))();
      uVar3 = (uint)puVar1 & 3;
      uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc);
      uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      iVar5 = iVar5 + 1;
      uVar3 = uVar4 + 0xc & 3;
      uVar2 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
    } while (iVar5 < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20));
  }
  *puRam020beb98 = 0;
  return;
}

