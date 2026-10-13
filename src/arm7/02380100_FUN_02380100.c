/* Decompiled C draft; module arm7; ROM address 02380100. No matching claim. */
#include "types.h"
#include "deps/02380100_FUN_02380100.h"

void FUN_02380100(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar6;
  
  uVar2 = *(uint *)(DAT_02380154 & 0xfffffffc) >> (DAT_02380154 & 3) * 8 |
          *(uint *)(DAT_02380154 & 0xfffffffc) << (DAT_02380154 & 3) * -8 + 0x20;
  uVar1 = DAT_02380154 + 4 & 3;
  uVar4 = *(uint *)(DAT_02380154 + 4 & 0xfffffffc);
  uVar6 = DAT_02380154 + 8 & 3;
  uVar5 = *(uint *)(DAT_02380154 + 8 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  do {
    if (uVar2 == (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) {
      return;
    }
    puVar7 = (uint *)(*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20);
    uVar3 = uVar2 + 8;
    uVar5 = uVar2 + 4 & 3;
    uVar8 = *(uint *)(uVar2 + 4 & 0xfffffffc);
    iVar9 = (int)puVar7 + (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
    for (; (int)puVar7 - iVar9 < 0; puVar7 = puVar7 + 1) {
      *puVar7 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
      uVar6 = uVar6 + 4;
    }
    uVar2 = uVar2 + 0xc;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    puVar10 = (uint *)((int)puVar7 + (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20));
    for (; puVar7 < puVar10; puVar7 = puVar7 + 1) {
      *puVar7 = 0;
    }
  } while (puVar7 == puVar10);
  return;
}

