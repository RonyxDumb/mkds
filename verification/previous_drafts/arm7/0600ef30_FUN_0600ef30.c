/* Decompiled C draft; module arm7; ROM address 0600ef30. No matching claim. */
#include "types.h"
#include "deps/0600ef30_FUN_0600ef30.h"

uint FUN_0600ef30(ushort *param_1)

{
  short *psVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = DAT_0600efd4;
  if ((*param_1 & 1) == 0) {
    uVar3 = *(uint *)(DAT_0600efd4 & 0xfffffffc) >> (DAT_0600efd4 & 3) * 8 |
            *(uint *)(DAT_0600efd4 & 0xfffffffc) << (DAT_0600efd4 & 3) * -8 + 0x20;
    if (1 < *(ushort *)(uVar3 + 0x52c)) {
      uVar5 = uVar3 + 0x31c & 3;
      uVar6 = *(uint *)(uVar3 + 0x31c & 0xfffffffc);
      uVar7 = 0;
      psVar1 = (short *)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
      for (uVar8 = 1; uVar8 < *(ushort *)(uVar3 + 0x322); uVar8 = uVar8 + 1) {
        if (psVar1[0xe] != 0) {
          iVar4 = FUN_0600a578(psVar1 + 0x10,param_1);
          if (iVar4 != 0) {
            return uVar8;
          }
          uVar7 = uVar7 + 1;
          uVar3 = uVar2 & 3;
          uVar5 = *(uint *)(uVar2 & 0xfffffffc);
          uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
          if (*(ushort *)(uVar3 + 0x52c) <= uVar7) break;
        }
        psVar1 = psVar1 + 0xe;
      }
    }
    uVar2 = 0xff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

