/* Decompiled C draft; module arm7; ROM address 037fa04c. No matching claim. */
#include "types.h"
#include "deps/037fa04c_FUN_037fa04c.h"

int FUN_037fa04c(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = FUN_037faf70();
  uVar6 = DAT_037fa160 + param_1 * 4;
  uVar3 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  if (uVar6 == 0) {
    FUN_037faf84();
    iVar2 = 0;
  }
  else {
    if ((int)param_2 < 0) {
      param_2 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    }
    uVar3 = uVar6 + 0x10 & 3;
    uVar6 = *(uint *)(uVar6 + 0x10 & 0xfffffffc);
    iVar2 = param_2 * 0xc + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
    uVar9 = param_3 + 0x3fU & 0xffffffe0;
    uVar6 = iVar2 + 4U & 3;
    uVar3 = *(uint *)(iVar2 + 4U & 0xfffffffc);
    uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
    uVar6 = uVar3;
    while ((uVar6 != 0 &&
           (uVar8 = uVar6 + 8 & 3, uVar7 = *(uint *)(uVar6 + 8 & 0xfffffffc),
           (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) < (int)uVar9))) {
      uVar8 = uVar6 + 4 & 3;
      uVar6 = *(uint *)(uVar6 + 4 & 0xfffffffc);
      uVar6 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
    }
    if (uVar6 == 0) {
      FUN_037faf84(uVar1);
      iVar2 = 0;
    }
    else {
      uVar8 = uVar6 + 8 & 3;
      uVar7 = *(uint *)(uVar6 + 8 & 0xfffffffc);
      uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) - uVar9;
      if (uVar8 < 0x40) {
        uVar4 = FUN_037fa218(uVar3,uVar6);
        *(undefined4 *)(iVar2 + 4) = uVar4;
      }
      else {
        *(uint *)(uVar6 + 8) = uVar9;
        uVar7 = uVar6 + uVar9;
        *(uint *)(uVar7 + 8) = uVar8;
        *(uint *)(uVar6 + uVar9) =
             *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
             *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
        uVar3 = uVar6 + 4 & 3;
        uVar9 = *(uint *)(uVar6 + 4 & 0xfffffffc);
        *(uint *)(uVar7 + 4) = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
        uVar3 = uVar7 + 4 & 3;
        uVar9 = *(uint *)(uVar7 + 4 & 0xfffffffc);
        puVar5 = (uint *)(uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20);
        if (puVar5 != (uint *)0x0) {
          *puVar5 = uVar7;
        }
        uVar3 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
        if (uVar3 == 0) {
          *(uint *)(iVar2 + 4) = uVar7;
        }
        else {
          *(uint *)(uVar3 + 4) = uVar7;
        }
      }
      uVar3 = iVar2 + 8U & 3;
      uVar9 = *(uint *)(iVar2 + 8U & 0xfffffffc);
      uVar4 = FUN_037fa240(uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20,uVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
      FUN_037faf84(uVar1);
      iVar2 = uVar6 + 0x20;
    }
  }
  return iVar2;
}

