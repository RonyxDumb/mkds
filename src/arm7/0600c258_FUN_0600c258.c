/* Decompiled C draft; module arm7; ROM address 0600c258. No matching claim. */
#include "types.h"
#include "deps/0600c258_FUN_0600c258.h"

void FUN_0600c258(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  
  iVar4 = DAT_0600c3f8;
  iVar2 = DAT_0600c3f4;
  uVar8 = 0;
  for (uVar7 = 0; uVar5 = DAT_0600c3fc, iVar3 = DAT_0600c3f4, uVar7 < 3; uVar7 = uVar7 + 1) {
    for (uVar5 = 0; uVar5 < 0x1b; uVar5 = uVar5 + 1) {
      uVar1 = *(ushort *)(iVar4 + uVar7 * 2) & *(ushort *)(iVar2 + uVar5 * 4 + 2);
      puVar10 = (ushort *)(*(ushort *)(iVar2 + uVar5 * 4) + 0x4808000);
      *puVar10 = uVar1;
      uVar9 = uVar8;
      if ((*puVar10 != uVar1) && (uVar9 = uVar8 + 1, 0x20 < uVar8)) goto LAB_0600c3c8;
      uVar8 = uVar9;
    }
  }
  uVar9 = 0;
  uVar7 = DAT_0600c3fc;
  do {
    *(ushort *)(*(ushort *)(iVar3 + uVar9 * 4) + 0x4808000) =
         (ushort)uVar7 & *(ushort *)(iVar3 + uVar9 * 4 + 2);
    iVar2 = DAT_0600c3f4;
    uVar7 = uVar7 + uVar5 & 0xffff;
    uVar9 = uVar9 + 1;
  } while (uVar9 < 0x1b);
  uVar7 = DAT_0600c3fc;
  for (uVar5 = 0; uVar5 < 0x1b; uVar5 = uVar5 + 1) {
    uVar9 = uVar8;
    if (((uint)*(ushort *)(*(ushort *)(DAT_0600c3f4 + uVar5 * 4) + 0x4808000) !=
         (uVar7 & *(ushort *)(DAT_0600c3f4 + uVar5 * 4 + 2))) && (uVar9 = uVar8 + 1, 0x20 < uVar8))
    goto LAB_0600c3c8;
    uVar7 = uVar7 + DAT_0600c3fc & 0xffff;
    uVar8 = uVar9;
  }
  uVar7 = 0;
  while ((uVar9 = uVar8, uVar7 < 0x1b &&
         ((psVar6 = (short *)(*(ushort *)(iVar2 + uVar7 * 4) + 0x4808000), *psVar6 = 0, *psVar6 == 0
          || (uVar9 = uVar8 + 1, uVar8 < 0x21))))) {
    uVar7 = uVar7 + 1;
    uVar8 = uVar9;
  }
LAB_0600c3c8:
  if (uVar9 != 0) {
    uVar8 = *(uint *)(DAT_0600c400 & 0xfffffffc) >> (DAT_0600c400 & 3) * 8 |
            *(uint *)(DAT_0600c400 & 0xfffffffc) << (DAT_0600c400 & 3) * -8 + 0x20;
    *(ushort *)(uVar8 + 0x33e) = *(ushort *)(uVar8 + 0x33e) | 1;
  }
  return;
}

