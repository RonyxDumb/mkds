/* Decompiled C draft; module arm9; ROM address 020d759c. No matching claim. */
#include "types.h"
#include "deps/020d759c_func_020d759c.h"

void func_020d759c(uint param_1,uint param_2,int *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar1 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar13 = param_2 + 4 & 3;
  uVar10 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar12 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
           *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar11 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar14 = param_1 + 0xc & 3;
  uVar9 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar2 = param_2 + 0xc & 3;
  uVar8 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  uVar3 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar4 = param_2 + 8 & 3;
  uVar6 = *(uint *)(param_2 + 8 & 0xfffffffc);
  if ((int)((uVar9 >> uVar14 * 8 | uVar9 << uVar14 * -8 + 0x20) *
            (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) +
           (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) *
           (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) +
           uVar11 * uVar12 +
           (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
           (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20)) < 0) {
    *param_3 = uVar11 + ((int)(param_4 * -(uVar12 + uVar11)) >> 0xc);
    uVar1 = param_1 + 4 & 3;
    uVar13 = *(uint *)(param_1 + 4 & 0xfffffffc);
    uVar14 = uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20;
    uVar1 = param_2 + 4 & 3;
    uVar13 = *(uint *)(param_2 + 4 & 0xfffffffc);
    param_3[1] = uVar14 + ((int)(param_4 *
                                -((uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) + uVar14)) >>
                          0xc);
    uVar1 = param_1 + 8 & 3;
    uVar13 = *(uint *)(param_1 + 8 & 0xfffffffc);
    uVar14 = uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20;
    uVar1 = param_2 + 8 & 3;
    uVar13 = *(uint *)(param_2 + 8 & 0xfffffffc);
    param_3[2] = uVar14 + ((int)(param_4 *
                                -((uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) + uVar14)) >>
                          0xc);
    uVar1 = param_1 + 0xc & 3;
    uVar13 = *(uint *)(param_1 + 0xc & 0xfffffffc);
    uVar14 = uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20;
    uVar1 = param_2 + 0xc & 3;
    uVar13 = *(uint *)(param_2 + 0xc & 0xfffffffc);
    param_3[3] = uVar14 + ((int)(param_4 *
                                -((uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) + uVar14)) >>
                          0xc);
    return;
  }
  *param_3 = uVar11 + ((int)(param_4 * (uVar12 - uVar11)) >> 0xc);
  uVar1 = param_1 + 4 & 3;
  uVar13 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar14 = uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 4 & 3;
  uVar13 = *(uint *)(param_2 + 4 & 0xfffffffc);
  param_3[1] = uVar14 + ((int)(param_4 *
                              ((uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) - uVar14)) >> 0xc
                        );
  uVar1 = param_1 + 8 & 3;
  uVar13 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar14 = uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 8 & 3;
  uVar13 = *(uint *)(param_2 + 8 & 0xfffffffc);
  param_3[2] = uVar14 + ((int)(param_4 *
                              ((uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) - uVar14)) >> 0xc
                        );
  uVar1 = param_1 + 0xc & 3;
  uVar13 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar14 = uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0xc & 3;
  uVar13 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  param_3[3] = uVar14 + ((int)(param_4 *
                              ((uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) - uVar14)) >> 0xc
                        );
  return;
}

