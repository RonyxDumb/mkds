/* Decompiled C draft; module arm7; ROM address 027e0000. No matching claim. */
#include "types.h"
#include "deps/027e0000_FUN_027e0000.h"

void FUN_027e0000(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar7;
  
  iVar1 = DAT_027e00cc;
  uVar3 = DAT_027e00c4;
  uVar8 = DAT_027e00c0;
  while( true ) {
    if (uVar3 == DAT_027e00c8) {
      return;
    }
    uVar5 = uVar3 + 4 & 3;
    uVar6 = *(uint *)(uVar3 + 4 & 0xfffffffc);
    uVar7 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    uVar5 = uVar3 + 8 & 3;
    uVar6 = *(uint *)(uVar3 + 8 & 0xfffffffc);
    uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    if ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
        *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) == 0x6000000) break;
    uVar8 = uVar8 + uVar7;
    uVar3 = uVar3 + 0xc;
  }
  *DAT_027e00d0 = DAT_027e00cc;
  iVar2 = uVar7 + uVar5;
  *DAT_027e00d4 = iVar2;
  if (DAT_027e00d8 != iVar1 + iVar2) {
    FUN_037fb000();
  }
  puVar4 = (uint *)(*(uint *)((uint)DAT_027e00d0 & 0xfffffffc) >> ((uint)DAT_027e00d0 & 3) * 8 |
                   *(uint *)((uint)DAT_027e00d0 & 0xfffffffc) <<
                   ((uint)DAT_027e00d0 & 3) * -8 + 0x20);
  for (uVar3 = 0; uVar3 < uVar7 >> 2; uVar3 = uVar3 + 1) {
    *puVar4 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
              *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
    puVar4 = puVar4 + 1;
    uVar8 = uVar8 + 4;
  }
  for (uVar3 = 0; uVar3 < uVar5 >> 2; uVar3 = uVar3 + 1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  return;
}

