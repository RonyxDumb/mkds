/* Decompiled C draft; module arm7; ROM address 02380000. No matching claim. */
#include "types.h"
#include "deps/02380000_Arm7Entry.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Arm7Entry(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  
  iVar2 = iRam023800d0;
  _DAT_04000208 = 0x4000000;
  puVar4 = puRam023800cc;
  if (-1 < 0x3800000 - (int)puRam023800cc) {
    puVar4 = &DAT_03800000;
  }
  for (; (int)puVar4 < iVar2; puVar4 = puVar4 + 1) {
    *puVar4 = 0;
  }
  puVar8 = puRam023800e4 + 0x58;
  uVar3 = uRam023800e0;
  puVar6 = puRam023800e4;
  do {
    puVar5 = puVar6;
    puVar6 = puVar5 + 1;
    *puVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    uVar3 = uVar3 + 4;
  } while ((int)puVar6 - (int)puVar8 < 0);
  uVar3 = uRam023800e8;
  do {
    puVar8 = puVar6 + 1;
    *puVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    uVar3 = uVar3 + 4;
    puVar6 = puVar8;
  } while ((int)puVar8 - (int)(puVar5 + 9) < 0);
  FUN_02380100();
  uVar3 = iRam023800ec + 0xcU & 3;
  uVar7 = *(uint *)(iRam023800ec + 0xcU & 0xfffffffc);
  uVar1 = iRam023800ec + 0x10U & 3;
  uVar9 = *(uint *)(iRam023800ec + 0x10U & 0xfffffffc);
  for (puVar4 = (undefined4 *)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
      puVar4 < (undefined4 *)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20); puVar4 = puVar4 + 1)
  {
    *puVar4 = 0;
  }
  FUN_0238015c();
  *puRam023800f0 = uRam023800f4;
                    /* WARNING: Could not recover jumptable at 0x023800c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam023800f8)();
  return;
}

