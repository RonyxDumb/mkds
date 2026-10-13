/* Decompiled C draft; module arm9; ROM address 02015fa0. No matching claim. */
#include "types.h"
#include "deps/02015fa0_func_02015fa0.h"

uint func_02015fa0(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  int iVar8;
  uint uVar9;
  uint unaff_r8;
  int *piVar7;
  
  if (param_1 == 0) {
    uVar9 = 0x10;
  }
  else {
    uVar9 = param_1 + 0xfU & 0xfffffff0;
  }
  if (uRam0201611c <= uVar9) {
    return 0;
  }
  if (param_2 == 0) {
    iVar8 = 0;
    do {
      uVar6 = iRam0201612c + iVar8 * 4;
      uVar4 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar2 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
      uVar6 = uVar2 + 8 & 3;
      uVar4 = *(uint *)(uVar2 + 8 & 0xfffffffc);
      if ((uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0) &&
         (uVar6 = uVar2 + 4 & 3, uVar4 = *(uint *)(uVar2 + 4 & 0xfffffffc),
         uVar9 <= (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) -
                  (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                  *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20))) {
        uVar6 = uVar2 + 4 & 3;
        uVar4 = *(uint *)(uVar2 + 4 & 0xfffffffc);
        bVar1 = true;
        *(uint *)(uVar2 + 4) = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) - uVar9;
        uVar6 = uVar2 + 4 & 3;
        uVar3 = *(uint *)(uVar2 + 4 & 0xfffffffc);
        uVar4 = uVar2 + 0x14 & 3;
        uVar2 = *(uint *)(uVar2 + 0x14 & 0xfffffffc);
        unaff_r8 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) +
                   (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
        goto LAB_020160f0;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 5);
    bVar1 = false;
  }
  else {
    iVar8 = 0;
    do {
      uVar6 = iRam02016128 + iVar8 * 4;
      uVar4 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      piVar7 = (int *)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
      uVar6 = (uint)(piVar7 + 2) & 3;
      uVar4 = *(uint *)((uint)(piVar7 + 2) & 0xfffffffc);
      if ((uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0) &&
         (uVar6 = (uint)(piVar7 + 1) & 3, uVar4 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc),
         uVar9 <= (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) -
                  (*(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
                  *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20))) {
        piVar5 = piRam02016124;
        if (((short)piVar7[4] != 0) && (piVar5 = piRam02016120, (short)piVar7[4] != 3)) {
          piVar5 = (int *)0x0;
        }
        uVar6 = (uint)(piVar5 + 2) & 3;
        uVar4 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
        if ((uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0) &&
           (uVar6 = (uint)(piVar5 + 1) & 3, uVar4 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc),
           uVar9 >> 1 <=
           (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) -
           (*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
           *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20))) {
          uVar2 = *(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
                  *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20;
          bVar1 = true;
          *piVar7 = uVar2 + uVar9;
          *piVar5 = (*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                    *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20) +
                    (uVar9 >> 1);
          uVar6 = (uint)(piVar7 + 5) & 3;
          uVar4 = *(uint *)((uint)(piVar7 + 5) & 0xfffffffc);
          unaff_r8 = uVar2 + (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
          goto LAB_020160f0;
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
    bVar1 = false;
  }
LAB_020160f0:
  if (!bVar1) {
    return 0;
  }
  return uRam02016130 & unaff_r8 >> 3 | (uVar9 >> 4) << 0x10 | param_2 << 0x1f;
}

