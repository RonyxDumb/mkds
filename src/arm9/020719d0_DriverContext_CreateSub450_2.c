/* Decompiled C draft; module arm9; ROM address 020719d0. No matching claim. */
#include "types.h"
#include "deps/020719d0_DriverContext_CreateSub450_2.h"

void DriverContext_CreateSub450_2(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 unaff_r6;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  
  *(undefined4 *)(param_1 + 0x450) = 0xa5;
  *(undefined1 *)(param_1 + 0x454) = 100;
  *(undefined4 *)(param_1 + 0x458) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x45c) = 0;
  *(undefined4 *)(param_1 + 0x460) = 0;
  *(undefined4 *)(param_1 + 0x464) = 0;
  uVar7 = param_1 + 0x2ccU & 3;
  uVar6 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x10;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar4 = FX_Div(0x300000,0xd000 - (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20));
  *(undefined4 *)(param_1 + 0x468) = uVar4;
  uVar7 = param_1 + 0x2ccU & 3;
  uVar6 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x10;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar4 = FX_Div(0x580000,uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x46c) = uVar4;
  uVar7 = param_1 + 0x2ccU & 3;
  uVar6 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x10;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar4 = FX_Div(0x480000,uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x470) = uVar4;
  uVar7 = param_1 + 0x2ccU & 3;
  uVar6 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x10;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar4 = FX_Div(0x280000,uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
  *(undefined4 *)(param_1 + 0x474) = uVar4;
  *(undefined4 *)(param_1 + 0x478) = 0;
  *(undefined1 *)(param_1 + 0x47c) = 0;
  *(undefined4 *)(param_1 + 0x480) = 0;
  *(undefined4 *)(param_1 + 0x484) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x488) = 0xffffffff;
  uVar7 = param_1 + 0x590U & 3;
  uVar6 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  switch((int)((ulonglong)((longlong)DAT_02071bf4 * (longlong)(int)uVar7) >> 0x20) -
         ((int)uVar7 >> 0x1f)) {
  case 0:
    unaff_r6 = 4;
    break;
  case 1:
    unaff_r6 = 0;
    break;
  case 2:
    unaff_r6 = 1;
    break;
  case 3:
    unaff_r6 = 2;
    break;
  case 4:
    unaff_r6 = 5;
    break;
  case 5:
    unaff_r6 = 6;
    break;
  case 6:
    unaff_r6 = 7;
    break;
  case 7:
    unaff_r6 = 3;
    break;
  case 8:
    unaff_r6 = 10;
    break;
  case 9:
    unaff_r6 = 8;
    break;
  case 10:
    unaff_r6 = 9;
    break;
  case 0xb:
    unaff_r6 = 0xb;
    break;
  case 0xc:
    unaff_r6 = 0xc;
  }
  *(undefined4 *)(param_1 + 0x4b8) = unaff_r6;
  uVar7 = param_1 + 0x590U & 3;
  uVar6 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  iVar5 = func_0202578c(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
  iVar14 = iVar5 * 0x1c;
  uVar7 = DAT_02071bf8 + iVar14 & 3;
  uVar6 = *(uint *)(DAT_02071bf8 + iVar14 & 0xfffffffc);
  uVar12 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  uVar7 = DAT_02071bfc + iVar14 & 3;
  uVar6 = *(uint *)(DAT_02071bfc + iVar14 & 0xfffffffc);
  uVar11 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  uVar7 = DAT_02071c00 + iVar14 & 3;
  uVar6 = *(uint *)(DAT_02071c00 + iVar14 & 0xfffffffc);
  uVar16 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  uVar7 = DAT_02071c04 + iVar14 & 3;
  uVar10 = *(uint *)(DAT_02071c04 + iVar14 & 0xfffffffc);
  uVar6 = DAT_02071c08 + iVar14 & 3;
  uVar9 = *(uint *)(DAT_02071c08 + iVar14 & 0xfffffffc);
  uVar1 = DAT_02071c0c + iVar14 & 3;
  uVar8 = *(uint *)(DAT_02071c0c + iVar14 & 0xfffffffc);
  uVar2 = DAT_02071c14 + iVar14 & 3;
  uVar15 = *(uint *)(DAT_02071c14 + iVar14 & 0xfffffffc);
  uVar13 = uVar12;
  uVar3 = uVar11;
  if ((uint)*(ushort *)(param_1 + 0x74) !=
      (int)*(char *)((*(uint *)(DAT_02071c10 & 0xfffffffc) >> (DAT_02071c10 & 3) * 8 |
                     *(uint *)(DAT_02071c10 & 0xfffffffc) << (DAT_02071c10 & 3) * -8 + 0x20) + 0x62)
     ) {
    uVar13 = uVar16;
    uVar3 = uVar16;
  }
  *(int *)(param_1 + 0x490) = iVar5;
  *(uint *)(param_1 + 0x494) = uVar12;
  *(uint *)(param_1 + 0x498) = uVar11;
  *(uint *)(param_1 + 0x49c) = uVar16;
  *(uint *)(param_1 + 0x4a0) = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  *(uint *)(param_1 + 0x4a4) = uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20;
  *(uint *)(param_1 + 0x4a8) = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  *(uint *)(param_1 + 0x4ac) = uVar15 >> uVar2 * 8 | uVar15 << uVar2 * -8 + 0x20;
  *(uint *)(param_1 + 0x4b0) = uVar3;
  *(uint *)(param_1 + 0x4b4) = uVar13;
  return;
}

