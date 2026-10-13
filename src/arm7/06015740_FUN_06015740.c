/* Decompiled C draft; module arm7; ROM address 06015740. No matching claim. */
#include "types.h"
#include "deps/06015740_FUN_06015740.h"

void FUN_06015740(void)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  uVar4 = DAT_060157b0;
  iVar9 = (*(uint *)(DAT_060157b0 & 0xfffffffc) >> (DAT_060157b0 & 3) * 8 |
          *(uint *)(DAT_060157b0 & 0xfffffffc) << (DAT_060157b0 & 3) * -8 + 0x20) + DAT_060157b4;
  uVar8 = 0;
  do {
    psVar6 = (short *)(iVar9 + uVar8 * 0x18);
    sVar2 = *(short *)(iVar9 + uVar8 * 0x18);
    if ((sVar2 != 0) && (*psVar6 = sVar2 + -1, *psVar6 == 0)) {
      uVar3 = uVar4 & 3;
      uVar5 = *(uint *)(uVar4 & 0xfffffffc);
      uVar1 = (uint)(psVar6 + 10) & 3;
      uVar7 = *(uint *)((uint)(psVar6 + 10) & 0xfffffffc);
      FUN_060090b4((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x188,
                   uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 3);
  return;
}

