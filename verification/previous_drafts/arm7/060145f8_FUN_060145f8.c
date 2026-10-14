/* Decompiled C draft; module arm7; ROM address 060145f8. No matching claim. */
#include "types.h"
#include "deps/060145f8_FUN_060145f8.h"

void FUN_060145f8(uint param_1)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  bVar2 = false;
  iVar3 = FUN_0600e824();
  if (iVar3 != 0) {
    uVar6 = 0;
    do {
      uVar8 = (*(uint *)(DAT_06014704 & 0xfffffffc) >> (DAT_06014704 & 3) * 8 |
              *(uint *)(DAT_06014704 & 0xfffffffc) << (DAT_06014704 & 3) * -8 + 0x20) + uVar6 * 0xc
              + 0x194;
      uVar4 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar8 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
      if (uVar8 != 0xffffffff) {
        do {
          uVar4 = FUN_06008e48(uVar8);
          uVar7 = uVar8 + 0x10;
          if (*(ushort *)(uVar8 + 0x12) == param_1) {
            if ((uVar6 == 1) ||
               (uVar5 = uVar6 * 0x14 +
                        (*(uint *)(DAT_06014704 & 0xfffffffc) >> (DAT_06014704 & 3) * 8 |
                        *(uint *)(DAT_06014704 & 0xfffffffc) << (DAT_06014704 & 3) * -8 + 0x20) +
                        0x438, uVar1 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
               uVar7 == (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20))) {
              FUN_0600ec88(uVar7);
              *(undefined2 *)(uVar8 + 0x12) = 0;
              FUN_0600ecf4(uVar7);
            }
            else {
              *(undefined2 *)(uVar8 + 0x18) = 2;
              FUN_0600ec88(uVar7);
              FUN_060125a8((*(uint *)(DAT_06014704 & 0xfffffffc) >> (DAT_06014704 & 3) * 8 |
                           *(uint *)(DAT_06014704 & 0xfffffffc) << (DAT_06014704 & 3) * -8 + 0x20) +
                           0x194 + uVar6 * 0xc,uVar8);
              if (!bVar2) {
                bVar2 = true;
              }
            }
          }
          uVar8 = uVar4;
        } while (uVar4 != 0xffffffff);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < 3);
  }
  return;
}

