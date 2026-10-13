/* Decompiled C draft; module arm7; ROM address 037f9ca8. No matching claim. */
#include "types.h"
#include "deps/037f9ca8_FUN_037f9ca8.h"

int FUN_037f9ca8(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar7 = 0;
  iVar6 = 0;
  iVar5 = -1;
  FUN_037faf70();
  uVar9 = DAT_037f9e48 + param_1 * 4;
  uVar2 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar10 = uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
  uVar9 = uVar10 + 0x10 & 3;
  uVar2 = *(uint *)(uVar10 + 0x10 & 0xfffffffc);
  uVar9 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
  if (((uVar9 != 0) && (-1 < param_2)) &&
     (uVar2 = uVar10 + 4 & 3, uVar1 = *(uint *)(uVar10 + 4 & 0xfffffffc),
     param_2 < (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20))) {
    iVar3 = uVar9 + param_2 * 0xc;
    uVar9 = uVar9 + param_2 * 0xc;
    uVar2 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
    if ((-1 < (int)uVar9) &&
       ((uVar2 = iVar3 + 8, uVar1 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
        uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20, uVar2 == 0 ||
        (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 == 0 &&
         *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 == 0)))) {
      while (uVar2 != 0) {
        uVar1 = uVar10 + 8 & 3;
        uVar4 = *(uint *)(uVar10 + 8 & 0xfffffffc);
        if ((((uVar2 < (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) ||
             (uVar1 = uVar10 + 0xc & 3, uVar4 = *(uint *)(uVar10 + 0xc & 0xfffffffc),
             (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) <= uVar2)) ||
            (((uVar2 & 0x1f) != 0 ||
             ((((uVar1 = uVar2 + 4 & 3, uVar4 = *(uint *)(uVar2 + 4 & 0xfffffffc),
                uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20, uVar1 != 0 &&
                ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                 *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) != uVar2)) ||
               (uVar4 = uVar2 + 8 & 3, uVar2 = *(uint *)(uVar2 + 8 & 0xfffffffc),
               uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20, uVar2 < 0x40)) ||
              (((uVar2 & 0x1f) != 0 || (uVar7 = uVar7 + uVar2, (int)uVar7 < 1)))))))) ||
           (uVar2 = uVar1, (int)uVar9 < (int)uVar7)) goto LAB_037f9e38;
      }
      uVar2 = iVar3 + 4;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      if ((uVar2 == 0) ||
         (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 == 0 &&
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20 == 0)) goto LAB_037f9e28;
    }
  }
LAB_037f9e38:
  FUN_037faf84();
  return iVar5;
LAB_037f9e28:
  if (uVar2 == 0) {
    if (uVar7 == uVar9) {
      iVar5 = iVar6;
    }
    goto LAB_037f9e38;
  }
  uVar1 = uVar10 + 8 & 3;
  uVar4 = *(uint *)(uVar10 + 8 & 0xfffffffc);
  if (((((uVar2 < (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) ||
        (uVar1 = uVar10 + 0xc & 3, uVar4 = *(uint *)(uVar10 + 0xc & 0xfffffffc),
        (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) <= uVar2)) || ((uVar2 & 0x1f) != 0)) ||
      (((uVar1 = uVar2 + 4 & 3, uVar4 = *(uint *)(uVar2 + 4 & 0xfffffffc),
        uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20, uVar1 != 0 &&
        ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
         *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) != uVar2)) ||
       ((uVar4 = uVar2 + 8 & 3, uVar8 = *(uint *)(uVar2 + 8 & 0xfffffffc),
        uVar4 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20, uVar4 < 0x40 ||
        ((uVar4 & 0x1f) != 0)))))) || ((uVar1 != 0 && (uVar1 <= uVar2 + uVar4)))) goto LAB_037f9e38;
  uVar7 = uVar7 + uVar4;
  iVar6 = iVar6 + (uVar4 - 0x20);
  if (((int)uVar7 < 1) || (uVar2 = uVar1, (int)uVar9 < (int)uVar7)) goto LAB_037f9e38;
  goto LAB_037f9e28;
}

