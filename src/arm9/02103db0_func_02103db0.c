/* Decompiled C draft; module arm9; ROM address 02103db0. No matching claim. */
#include "types.h"
#include "deps/02103db0_func_02103db0.h"

void func_02103db0(int param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar12;
  uint uVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar23;
  uint uVar11;
  uint uVar22;
  
  uVar13 = *(uint *)(uRam02103fe0 & 0xfffffffc) >> (uRam02103fe0 & 3) * 8 |
           *(uint *)(uRam02103fe0 & 0xfffffffc) << (uRam02103fe0 & 3) * -8 + 0x20;
  piVar15 = (int *)(uVar13 + iRam02103fe8);
  uVar8 = (uint)(piVar15 + 2) & 3;
  uVar21 = *(uint *)((uint)(piVar15 + 2) & 0xfffffffc);
  uVar22 = uVar21 >> uVar8 * 8 | uVar21 << uVar8 * -8 + 0x20;
  uVar8 = uVar13 + 0x498 & 3;
  uVar21 = *(uint *)(uVar13 + 0x498 & 0xfffffffc);
  uVar20 = uVar21 >> uVar8 * 8 | uVar21 << uVar8 * -8 + 0x20;
  uVar8 = (uint)(piVar15 + 1) & 3;
  uVar17 = *(uint *)((uint)(piVar15 + 1) & 0xfffffffc);
  lVar4 = (ulonglong)uVar20 * (ulonglong)uVar22;
  uVar23 = (uint)lVar4;
  uVar21 = (uint)(piVar15 + 4) & 3;
  uVar10 = *(uint *)((uint)(piVar15 + 4) & 0xfffffffc);
  uVar11 = uVar10 >> uVar21 * 8 | uVar10 << uVar21 * -8 + 0x20;
  uVar21 = (uint)(piVar15 + 3) & 3;
  uVar18 = *(uint *)((uint)(piVar15 + 3) & 0xfffffffc);
  iVar9 = param_1 * 0x34 +
          (*(uint *)(uRam02103fe4 & 0xfffffffc) >> (uRam02103fe4 & 3) * 8 |
          *(uint *)(uRam02103fe4 & 0xfffffffc) << (uRam02103fe4 & 3) * -8 + 0x20);
  uVar10 = (uint)(piVar15 + 5) & 3;
  uVar19 = *(uint *)((uint)(piVar15 + 5) & 0xfffffffc);
  *(uint *)(uVar13 + 0x498) = uVar11 + uVar23;
  piVar15[1] = (uVar19 >> uVar10 * 8 | uVar19 << uVar10 * -8 + 0x20) +
               (uVar18 >> uVar21 * 8 | uVar18 << uVar21 * -8 + 0x20) * uVar20 +
               uVar22 * (uVar17 >> uVar8 * 8 | uVar17 << uVar8 * -8 + 0x20) +
               (int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar11,uVar23);
  uVar8 = (uint)(piVar15 + 1) & 3;
  uVar21 = *(uint *)((uint)(piVar15 + 1) & 0xfffffffc);
  uVar10 = uVar21 >> uVar8 * 8 | uVar21 << uVar8 * -8 + 0x20;
  iVar12 = (int)(uVar10 >> 0x10) >> 4;
  puVar6 = (undefined2 *)(iVar9 + 0x10);
  uVar8 = uVar13 + 0x498 & 3;
  uVar21 = *(uint *)(uVar13 + 0x498 & 0xfffffffc);
  uVar8 = uVar21 >> uVar8 * 8 | uVar21 << uVar8 * -8 + 0x20;
  iVar14 = (int)*(short *)(iRam02103fec + iVar12 * 4);
  iVar12 = (int)*(short *)(iRam02103fec + (iVar12 * 2 + 1) * 2);
  if (param_3 == 0) {
    uVar21 = (uint)(piVar15 + 2) & 3;
    uVar11 = *(uint *)((uint)(piVar15 + 2) & 0xfffffffc);
    uVar18 = uVar11 >> uVar21 * 8 | uVar11 << uVar21 * -8 + 0x20;
    uVar21 = (uint)(piVar15 + 3) & 3;
    uVar17 = *(uint *)((uint)(piVar15 + 3) & 0xfffffffc);
    lVar4 = (ulonglong)uVar8 * (ulonglong)uVar18;
    uVar20 = (uint)lVar4;
    uVar11 = (uint)(piVar15 + 4) & 3;
    uVar13 = *(uint *)((uint)(piVar15 + 4) & 0xfffffffc);
    uVar19 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(piVar15 + 5) & 3;
    uVar13 = *(uint *)((uint)(piVar15 + 5) & 0xfffffffc);
    *piVar15 = uVar19 + uVar20;
    piVar15[1] = (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) +
                 (uVar17 >> uVar21 * 8 | uVar17 << uVar21 * -8 + 0x20) * uVar8 +
                 uVar18 * uVar10 + (int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar19,uVar20);
    uVar8 = (uint)(piVar15 + 1) & 3;
    uVar21 = *(uint *)((uint)(piVar15 + 1) & 0xfffffffc);
    sVar7 = (short)uRam02103ff0 +
            (short)((uint)((int)((ulonglong)(uVar21 >> uVar8 * 8 | uVar21 << uVar8 * -8 + 0x20) *
                                 0x52 >> 0x20) * 0x10000) >> 0x10);
  }
  else {
    uVar21 = (uint)(piVar15 + 2) & 3;
    uVar11 = *(uint *)((uint)(piVar15 + 2) & 0xfffffffc);
    uVar18 = uVar11 >> uVar21 * 8 | uVar11 << uVar21 * -8 + 0x20;
    uVar21 = (uint)(piVar15 + 3) & 3;
    uVar17 = *(uint *)((uint)(piVar15 + 3) & 0xfffffffc);
    lVar4 = (ulonglong)uVar8 * (ulonglong)uVar18;
    uVar20 = (uint)lVar4;
    uVar11 = (uint)(piVar15 + 4) & 3;
    uVar13 = *(uint *)((uint)(piVar15 + 4) & 0xfffffffc);
    uVar19 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
    uVar11 = (uint)(piVar15 + 5) & 3;
    uVar13 = *(uint *)((uint)(piVar15 + 5) & 0xfffffffc);
    *piVar15 = uVar19 + uVar20;
    piVar15[1] = (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) +
                 (uVar17 >> uVar21 * 8 | uVar17 << uVar21 * -8 + 0x20) * uVar8 +
                 uVar18 * uVar10 + (int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar19,uVar20);
    uVar8 = (uint)(piVar15 + 1) & 3;
    uVar21 = *(uint *)((uint)(piVar15 + 1) & 0xfffffffc);
    sVar7 = (short)((uint)((int)((ulonglong)(uVar21 >> uVar8 * 8 | uVar21 << uVar8 * -8 + 0x20) *
                                 0xcd >> 0x20) * 0x10000) >> 0x10) + 0x800;
  }
  iVar16 = (int)sVar7;
  if (*(uint *)(uRam02103ff4 & 0xfffffffc) >> (uRam02103ff4 & 3) * 8 != 0 ||
      *(uint *)(uRam02103ff4 & 0xfffffffc) << (uRam02103ff4 & 3) * -8 + 0x20 != 0) {
    iVar16 = (int)(short)((uint)(iVar16 << 0xb) >> 0xc);
  }
  uVar8 = iRam02103ff8 + param_1 * 4;
  uVar21 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  *(uint *)(iVar9 + 0x2c) = uVar8 >> uVar21 * 8 | uVar8 << uVar21 * -8 + 0x20;
  uVar2 = (undefined2)((uint)(iVar16 * -0x10000) >> 0x10);
  *puVar6 = uVar2;
  *(undefined2 *)(iVar9 + 0x12) = uVar2;
  *(undefined2 *)(iVar9 + 0x14) = uVar2;
  uVar3 = (undefined2)iVar16;
  *(undefined2 *)(iVar9 + 0x16) = uVar3;
  *(undefined2 *)(iVar9 + 0x18) = uVar3;
  *(undefined2 *)(iVar9 + 0x1a) = uVar3;
  *(undefined2 *)(iVar9 + 0x1c) = uVar3;
  *(undefined2 *)(iVar9 + 0x1e) = uVar2;
  iVar16 = 0;
  do {
    sVar7 = puVar6[iVar16 * 2 + 1];
    sVar1 = puVar6[iVar16 * 2];
    puVar6[iVar16 * 2] = (short)(iVar12 * sVar1 - iVar14 * sVar7 >> 0xc);
    puVar6[iVar16 * 2 + 1] = (short)(iVar14 * sVar1 + iVar12 * sVar7 >> 0xc);
    *(undefined4 *)(iVar9 + iVar16 * 4) = param_2;
    uVar5 = uRam02103ffc;
    iVar16 = iVar16 + 1;
  } while (iVar16 < 4);
  *(undefined4 *)(iVar9 + 0x20) = param_2;
  *(undefined4 *)(iVar9 + 0x24) = uVar5;
  *(undefined4 *)(iVar9 + 0x30) = 0xffffffff;
  *(undefined4 *)(iVar9 + 0x28) = 0;
  return;
}

