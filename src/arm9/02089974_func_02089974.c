/* Decompiled C draft; module arm9; ROM address 02089974. No matching claim. */
#include "types.h"
#include "deps/02089974_func_02089974.h"

void func_02089974(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  puVar2 = puRam02089a14;
  uVar1 = uRam02089a10;
  uVar6 = *(uint *)(uRam02089a08 & 0xfffffffc) >> (uRam02089a08 & 3) * 8 |
          *(uint *)(uRam02089a08 & 0xfffffffc) << (uRam02089a08 & 3) * -8 + 0x20;
  *puRam02089a0c = 0;
  *puVar2 = uVar1;
  puVar3 = puRam02089a20;
  uVar5 = uVar6 + 0x18 & 3;
  uVar4 = *(uint *)(uVar6 + 0x18 & 0xfffffffc);
  if (uVar4 >> uVar5 * 8 != 0 || uVar4 << uVar5 * -8 + 0x20 != 0) {
    *puRam02089a20 = 0x190000;
    if ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
        *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) == 0x2b) {
      *puVar3 = 0x28000;
    }
    return;
  }
  uVar5 = uVar6 + 0x14 & 3;
  uVar4 = *(uint *)(uVar6 + 0x14 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (uVar5 == 2) {
    *puVar2 = uRam02089a1c;
    return;
  }
  if (uVar5 == 3) {
    *puVar2 = uRam02089a18;
  }
  return;
}

