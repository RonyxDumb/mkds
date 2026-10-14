/* Decompiled C draft; module arm9; ROM address 020408f0. No matching claim. */
#include "types.h"
#include "deps/020408f0_ComputeDriverSkillRankpoints.h"

int ComputeDriverSkillRankpoints(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int *piVar19;
  int iStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  uint uVar7;
  
  uVar18 = *(uint *)(uRam02040a7c & 0xfffffffc) >> (uRam02040a7c & 3) * 8 |
           *(uint *)(uRam02040a7c & 0xfffffffc) << (uRam02040a7c & 3) * -8 + 0x20;
  piVar19 = (int *)(uVar18 + 0x500);
  if ((*(ushort *)(param_1 * 0x8c + uVar18 + 0x44) & 1) == 0) {
    return 0;
  }
  uVar11 = *(uint *)(uRam02040a80 & 0xfffffffc) >> (uRam02040a80 & 3) * 8 |
           *(uint *)(uRam02040a80 & 0xfffffffc) << (uRam02040a80 & 3) * -8 + 0x20;
  uVar7 = uVar11 + 8 & 3;
  uVar6 = *(uint *)(uVar11 + 8 & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (uVar7 == 0) {
    MaybeComputeGPScore(&iStack_38);
  }
  else {
    if (uVar7 != 4) {
      return 0;
    }
    iVar8 = GetGlobalRK();
    iStack_38 = FX_Div((int)*(short *)(uVar11 + 0x2c) *
                       ((uint)*(ushort *)(uVar11 + 0x2a) -
                       (*(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
                       *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20)) * 0x1000,
                       0x3e8000);
    iStack_38 = iStack_38 >> 0xc;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uVar7 = iVar8 + 8U & 3;
    uVar6 = *(uint *)(iVar8 + 8U & 0xfffffffc);
    iStack_28 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * -5;
    uStack_24 = 0;
    uVar7 = iVar8 + 0x10U & 3;
    uVar6 = *(uint *)(iVar8 + 0x10U & 0xfffffffc);
    iStack_20 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * -5;
    uVar7 = iVar8 + 0x14U & 3;
    uVar6 = *(uint *)(iVar8 + 0x14U & 0xfffffffc);
    iStack_1c = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * -10;
    uVar7 = iVar8 + 0x18U & 3;
    uVar6 = *(uint *)(iVar8 + 0x18U & 0xfffffffc);
    iStack_18 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * -0x14;
  }
  *piVar19 = iStack_38;
  *(undefined4 *)(uVar18 + 0x504) = uStack_34;
  *(undefined4 *)(uVar18 + 0x508) = uStack_30;
  *(undefined4 *)(uVar18 + 0x50c) = uStack_2c;
  *(int *)(uVar18 + 0x510) = iStack_28;
  *(undefined4 *)(uVar18 + 0x514) = uStack_24;
  *(int *)(uVar18 + 0x518) = iStack_20;
  *(int *)(uVar18 + 0x51c) = iStack_1c;
  iVar8 = iRam02040a84;
  *(int *)(uVar18 + 0x520) = iStack_18;
  uVar7 = uVar18 + 0x504 & 3;
  uVar9 = *(uint *)(uVar18 + 0x504 & 0xfffffffc);
  uVar6 = uVar18 + 0x508 & 3;
  uVar15 = *(uint *)(uVar18 + 0x508 & 0xfffffffc);
  uVar11 = uVar18 + 0x50c & 3;
  uVar12 = *(uint *)(uVar18 + 0x50c & 0xfffffffc);
  uVar1 = uVar18 + 0x510 & 3;
  uVar16 = *(uint *)(uVar18 + 0x510 & 0xfffffffc);
  uVar2 = uVar18 + 0x514 & 3;
  uVar13 = *(uint *)(uVar18 + 0x514 & 0xfffffffc);
  uVar3 = uVar18 + 0x518 & 3;
  uVar17 = *(uint *)(uVar18 + 0x518 & 0xfffffffc);
  uVar4 = uVar18 + 0x51c & 3;
  uVar14 = *(uint *)(uVar18 + 0x51c & 0xfffffffc);
  uVar5 = uVar18 + 0x520 & 3;
  uVar18 = *(uint *)(uVar18 + 0x520 & 0xfffffffc);
  iVar10 = (uVar18 >> uVar5 * 8 | uVar18 << uVar5 * -8 + 0x20) +
           (uVar14 >> uVar4 * 8 | uVar14 << uVar4 * -8 + 0x20) +
           (uVar17 >> uVar3 * 8 | uVar17 << uVar3 * -8 + 0x20) +
           (uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20) +
           (uVar16 >> uVar1 * 8 | uVar16 << uVar1 * -8 + 0x20) +
           (uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) +
           (uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20) +
           (*(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
           *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20) +
           (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20);
  if (iVar10 < iVar8) {
    iVar10 = iVar8;
  }
  if (iRam02040a88 < iVar10) {
    iVar10 = iRam02040a88;
  }
  return (int)(short)iVar10;
}

