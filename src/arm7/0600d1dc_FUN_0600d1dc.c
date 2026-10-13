/* Decompiled C draft; module arm7; ROM address 0600d1dc. No matching claim. */
#include "types.h"
#include "deps/0600d1dc_FUN_0600d1dc.h"

void FUN_0600d1dc(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 *puVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = DAT_0600d364;
  uVar4 = *(uint *)(DAT_0600d364 & 0xfffffffc) >> (DAT_0600d364 & 3) * 8 |
          *(uint *)(DAT_0600d364 & 0xfffffffc) << (DAT_0600d364 & 3) * -8 + 0x20;
  iVar6 = uVar4 + DAT_0600d368;
  psVar5 = (short *)(uVar4 + DAT_0600d36c);
  *DAT_0600d370 = 4;
  puVar3 = DAT_0600d380;
  uVar1 = *DAT_0600d374;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if (((*(ushort *)((uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + 0x690) & 8) != 0) &&
     ((uVar1 & 0x400) != 0)) {
    uVar2 = *DAT_0600d378;
    if ((((((uVar2 & 1) == 0) || (*psVar5 == 0)) && (((uVar2 & 4) == 0 || (psVar5[10] == 0)))) &&
        (((uVar2 & 8) == 0 || (psVar5[0x14] == 0)))) && ((*DAT_0600d37c & 1) == 0)) {
      *DAT_0600d380 = 0;
      *puVar3 = 0x8000;
      *(undefined2 *)(iVar6 + 2) = 0;
    }
    else {
      uVar2 = *(ushort *)(iVar6 + 2);
      *(ushort *)(iVar6 + 2) = uVar2 + 1;
      if (0xc < uVar2) {
        *(undefined2 *)(iVar6 + 2) = 0;
        puVar3 = DAT_0600d380;
        *DAT_0600d380 = 0;
        *puVar3 = 0x8000;
        uVar4 = *(uint *)(DAT_0600d364 & 0xfffffffc) >> (DAT_0600d364 & 3) * 8 |
                *(uint *)(DAT_0600d364 & 0xfffffffc) << (DAT_0600d364 & 3) * -8 + 0x20;
        *(short *)(uVar4 + 0x3fe) = *(short *)(uVar4 + 0x3fe) + 1;
      }
    }
  }
  if (((*(ushort *)
         ((*(uint *)(DAT_0600d364 & 0xfffffffc) >> (DAT_0600d364 & 3) * 8 |
          *(uint *)(DAT_0600d364 & 0xfffffffc) << (DAT_0600d364 & 3) * -8 + 0x20) + 0x690) & 1) != 0
      ) && ((uVar1 & 0x60) != 0)) {
    uVar1 = *DAT_0600d384;
    iVar6 = thunk_FUN_03806b2c(*DAT_0600d388 - 0x4000,2);
    if ((iVar6 <= (int)(uint)uVar1) ||
       (iVar6 = thunk_FUN_03806b2c(*DAT_0600d38c - 0x4000,2), (int)(uint)uVar1 < iVar6)) {
      *DAT_0600d394 = *DAT_0600d390;
      *DAT_0600d39c = (short)DAT_0600d398;
    }
    FUN_060093a4();
  }
  return;
}

