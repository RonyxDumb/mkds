/* Decompiled C draft; module arm7; ROM address 0600ede8. No matching claim. */
#include "types.h"
#include "deps/0600ede8_FUN_0600ede8.h"

uint FUN_0600ede8(ushort *param_1)

{
  short *psVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar9 = DAT_0600ef2c;
  uVar2 = *(uint *)(DAT_0600ef2c & 0xfffffffc) >> (DAT_0600ef2c & 3) * 8 |
          *(uint *)(DAT_0600ef2c & 0xfffffffc) << (DAT_0600ef2c & 3) * -8 + 0x20;
  uVar10 = uVar2 + 0x31c;
  if ((*param_1 & 1) == 0) {
    uVar7 = uVar2;
    if (*(ushort *)(uVar2 + 0x52c) < 2) {
      uVar3 = 1;
    }
    else {
      uVar6 = 0;
      uVar8 = 0;
      psVar1 = (short *)(*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                        *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20);
      for (uVar3 = 1; uVar3 < *(ushort *)(uVar2 + 0x322); uVar3 = uVar3 + 1) {
        if (psVar1[0xe] == 0) {
          if (uVar6 == 0) {
            uVar6 = uVar3;
          }
        }
        else {
          iVar5 = FUN_0600a578(psVar1 + 0x10,param_1);
          if (iVar5 != 0) {
            return uVar3;
          }
          uVar8 = uVar8 + 1;
          uVar7 = uVar9 & 3;
          uVar4 = *(uint *)(uVar9 & 0xfffffffc);
          uVar7 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
          if (*(ushort *)(uVar7 + 0x52c) <= uVar8) break;
        }
        psVar1 = psVar1 + 0xe;
      }
      if (uVar6 != 0) {
        uVar3 = uVar6;
      }
    }
    if (*(ushort *)(uVar7 + 0x322) <= uVar3) {
      uVar7 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
              *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
      uVar9 = 0x10000;
      uVar3 = 0;
      for (uVar10 = 1; uVar10 < *(ushort *)(uVar2 + 0x322); uVar10 = uVar10 + 1) {
        iVar5 = uVar7 + uVar10 * 0x1c;
        if (((*(ushort *)(uVar7 + uVar10 * 0x1c) < 0x30) && (*(short *)(iVar5 + 0x16) == 0)) &&
           (uVar6 = (uint)*(ushort *)(iVar5 + 0x18), uVar6 < uVar9)) {
          uVar3 = uVar10;
          uVar9 = uVar6;
        }
      }
      if (uVar3 == 0) {
        return 0xff;
      }
    }
    FUN_0600e248(uVar3,(undefined4)(uintptr_t)(param_1));
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

