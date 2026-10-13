/* Decompiled C draft; module arm9; ROM address 020909cc. No matching claim. */
#include "types.h"
#include "deps/020909cc_func_020909cc.h"

undefined4 func_020909cc(void)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  uint uVar7;
  
  bVar1 = false;
  uVar5 = *(uint *)(uRam02090b20 & 0xfffffffc) >> (uRam02090b20 & 3) * 8 |
          *(uint *)(uRam02090b20 & 0xfffffffc) << (uRam02090b20 & 3) * -8 + 0x20;
  uVar10 = 0;
  uVar8 = uVar5 + 0x8c & 3;
  uVar3 = *(uint *)(uVar5 + 0x8c & 0xfffffffc);
  uVar7 = uVar5 + 0x88 & 3;
  uVar6 = *(uint *)(uVar5 + 0x88 & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (uVar3 >> uVar8 * 8 != 0 || uVar3 << uVar8 * -8 + 0x20 != 0) {
    uVar7 = 3;
  }
  uVar8 = uVar5 + 0x84 & 3;
  uVar3 = *(uint *)(uVar5 + 0x84 & 0xfffffffc);
  uVar8 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
  iVar12 = 0;
  do {
    iVar11 = 0;
    do {
      iVar4 = CupHasRecord(iVar12,iVar11);
      if ((iVar4 == 0) || (iVar4 = CupGetResult(iVar12,iVar11), iVar4 != 0)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (!bVar2) {
        bVar2 = false;
        goto LAB_02090a68;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 4);
    iVar12 = iVar12 + 1;
    if (7 < iVar12) {
      bVar2 = true;
LAB_02090a68:
      if ((bVar2) &&
         (((uVar8 == 3 || (uVar8 == 7)) &&
          (uVar3 = (*(uint *)(uRam02090b20 & 0xfffffffc) >> (uRam02090b20 & 3) * 8 |
                   *(uint *)(uRam02090b20 & 0xfffffffc) << (uRam02090b20 & 3) * -8 + 0x20) + 0x7c,
          uVar5 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
          uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0)))) {
        bVar1 = true;
      }
      if (bVar1) {
        uVar10 = 2;
      }
      else {
        bVar1 = false;
        if ((uVar8 == 3) || (uVar8 == 7)) {
          if (uVar8 == 7) {
            uVar9 = 3;
          }
          else {
            uVar9 = 7;
          }
          iVar12 = CupHasRecord(uVar9,uVar7);
          if ((iVar12 == 0) || (iVar12 = CupGetResult(uVar9,uVar7), 2 < iVar12)) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
          if ((bVar2) &&
             (uVar8 = (*(uint *)(uRam02090b20 & 0xfffffffc) >> (uRam02090b20 & 3) * 8 |
                      *(uint *)(uRam02090b20 & 0xfffffffc) << (uRam02090b20 & 3) * -8 + 0x20) + 0x7c
             , uVar7 = uVar8 & 3, uVar8 = *(uint *)(uVar8 & 0xfffffffc),
             (int)(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) < 3)) {
            bVar1 = true;
          }
        }
        if (bVar1) {
          uVar10 = 1;
        }
      }
      return uVar10;
    }
  } while( true );
}

