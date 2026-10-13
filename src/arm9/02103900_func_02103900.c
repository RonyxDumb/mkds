/* Decompiled C draft; module arm9; ROM address 02103900. No matching claim. */
#include "types.h"
#include "deps/02103900_func_02103900.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_02103900(int param_1,int param_2,int param_3)

{
  longlong lVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar17;
  int iVar18;
  int *piVar19;
  uint uVar20;
  undefined4 uStack_28;
  uint uVar16;
  
  piVar19 = (int *)((*(uint *)(uRam02103d7c & 0xfffffffc) >> (uRam02103d7c & 3) * 8 |
                    *(uint *)(uRam02103d7c & 0xfffffffc) << (uRam02103d7c & 3) * -8 + 0x20) +
                   iRam02103d80);
  GetDriverEntry();
  if (param_1 !=
      *(char *)((*(uint *)(uRam02103d84 & 0xfffffffc) >> (uRam02103d84 & 3) * 8 |
                *(uint *)(uRam02103d84 & 0xfffffffc) << (uRam02103d84 & 3) * -8 + 0x20) + 0x62)) {
    return;
  }
  uVar17 = (uint)piRam02103d88 & 3;
  uVar6 = *(uint *)((uint)piRam02103d88 & 0xfffffffc);
  *puRam02103d8c = (short)param_1;
  piVar2 = piRam02103d90;
  if ((uVar6 >> uVar17 * 8 != 0 || uVar6 << uVar17 * -8 + 0x20 != 0) && (param_3 != 0)) {
    return;
  }
  *piRam02103d88 = 0;
  *piVar2 = 0;
  uVar7 = func_02108e6c(6);
  func_0212c6f0(uVar7,1);
  puVar11 = puRam02103d94;
  *piRam02103d90 = param_3;
  iVar8 = 0;
  iVar18 = 0;
  do {
    iVar8 = iVar8 + 1;
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  } while (iVar8 < 8);
  iVar8 = 0;
  while ((puVar4 = puRam02103d9c, puVar3 = puRam02103d98, iVar18 < 0x10 && (iVar8 < param_2))) {
    if (*(uint *)((uint)piRam02103d90 & 0xfffffffc) >> ((uint)piRam02103d90 & 3) * 8 == 0 &&
        *(uint *)((uint)piRam02103d90 & 0xfffffffc) << ((uint)piRam02103d90 & 3) * -8 + 0x20 == 0) {
      if (*(uint *)((uint)piRam02103d88 & 0xfffffffc) >> ((uint)piRam02103d88 & 3) * 8 == 0 &&
          *(uint *)((uint)piRam02103d88 & 0xfffffffc) << ((uint)piRam02103d88 & 3) * -8 + 0x20 == 0)
      {
        uVar17 = (uint)(piVar19 + 2) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 2) & 0xfffffffc);
        uVar15 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
        uVar12 = *(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
                 *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20;
        uVar17 = (uint)(piVar19 + 1) & 3;
        uVar9 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
        lVar1 = (ulonglong)uVar12 * (ulonglong)uVar15;
        uVar16 = (uint)lVar1;
        uVar6 = (uint)(piVar19 + 4) & 3;
        uVar13 = *(uint *)((uint)(piVar19 + 4) & 0xfffffffc);
        uVar10 = uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20;
        uVar6 = (uint)(piVar19 + 5) & 3;
        uVar20 = *(uint *)((uint)(piVar19 + 5) & 0xfffffffc);
        uVar13 = (uint)(piVar19 + 3) & 3;
        uVar14 = *(uint *)((uint)(piVar19 + 3) & 0xfffffffc);
        *piVar19 = uVar10 + uVar16;
        piVar19[1] = (uVar20 >> uVar6 * 8 | uVar20 << uVar6 * -8 + 0x20) +
                     (uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) * uVar12 +
                     uVar15 * (uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20) +
                     (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar10,uVar16);
        uVar17 = (uint)(piVar19 + 1) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
        uVar12 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
        uVar10 = *(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
                 *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20;
        uVar17 = (uint)(piVar19 + 4) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 4) & 0xfffffffc);
        uVar9 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
        uVar17 = (uint)(piVar19 + 5) & 3;
        uVar16 = *(uint *)((uint)(piVar19 + 5) & 0xfffffffc);
        uVar6 = (uint)(piVar19 + 2) & 3;
        uVar13 = *(uint *)((uint)(piVar19 + 2) & 0xfffffffc);
        uVar13 = uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20;
        uVar6 = (uint)(piVar19 + 3) & 3;
        uVar15 = *(uint *)((uint)(piVar19 + 3) & 0xfffffffc);
        lVar1 = (ulonglong)uVar10 * (ulonglong)uVar13;
        uVar14 = (uint)lVar1;
        *piVar19 = uVar9 + uVar14;
        piVar19[1] = (uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20) +
                     (uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20) * uVar10 +
                     uVar13 * uVar12 + (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar9,uVar14);
        uVar10 = *(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
                 *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20;
        uVar17 = (uint)(piVar19 + 1) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
        uVar9 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
        MKDS_SLICE_2(uStack_28,0) = (ushort)(uVar12 >> 0x14) + (ushort)(uVar9 >> 0x14);
        uVar17 = (uint)(piVar19 + 4) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 4) & 0xfffffffc);
        uVar16 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
        uVar17 = (uint)(piVar19 + 5) & 3;
        uVar14 = *(uint *)((uint)(piVar19 + 5) & 0xfffffffc);
        uVar6 = (uint)(piVar19 + 2) & 3;
        uVar13 = *(uint *)((uint)(piVar19 + 2) & 0xfffffffc);
        uVar12 = uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20;
        uVar6 = (uint)(piVar19 + 3) & 3;
        uVar13 = *(uint *)((uint)(piVar19 + 3) & 0xfffffffc);
        lVar1 = (ulonglong)uVar10 * (ulonglong)uVar12;
        uVar15 = (uint)lVar1;
        *piVar19 = uVar16 + uVar15;
        piVar19[1] = (uVar14 >> uVar17 * 8 | uVar14 << uVar17 * -8 + 0x20) +
                     (uVar13 >> uVar6 * 8 | uVar13 << uVar6 * -8 + 0x20) * uVar10 +
                     uVar12 * uVar9 + (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar15);
        uVar9 = *(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
                *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20;
        uVar17 = (uint)(piVar19 + 1) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
        uVar13 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
        uVar17 = (uint)(piVar19 + 4) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 4) & 0xfffffffc);
        uVar16 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
        uVar17 = (uint)(piVar19 + 5) & 3;
        uVar14 = *(uint *)((uint)(piVar19 + 5) & 0xfffffffc);
        uVar6 = (uint)(piVar19 + 2) & 3;
        uVar10 = *(uint *)((uint)(piVar19 + 2) & 0xfffffffc);
        uVar12 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
        uVar6 = (uint)(piVar19 + 3) & 3;
        uVar10 = *(uint *)((uint)(piVar19 + 3) & 0xfffffffc);
        lVar1 = (ulonglong)uVar9 * (ulonglong)uVar12;
        uVar15 = (uint)lVar1;
        *piVar19 = uVar16 + uVar15;
        piVar19[1] = (uVar14 >> uVar17 * 8 | uVar14 << uVar17 * -8 + 0x20) +
                     (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) * uVar9 +
                     uVar12 * uVar13 + (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar15)
        ;
        uVar17 = (uint)(piVar19 + 1) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
        MKDS_SLICE_2(uStack_28,2) =
             (short)((ulonglong)uVar13 * 0xc00 >> 0x20) +
             (short)((uint)((int)((ulonglong)(uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20) *
                                  0xc00 >> 0x20) * 0x10000) >> 0x10);
      }
      else {
        uVar17 = (uint)(piVar19 + 2) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 2) & 0xfffffffc);
        uVar14 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
        uVar12 = *(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
                 *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20;
        uVar17 = (uint)(piVar19 + 1) & 3;
        uVar9 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
        lVar1 = (ulonglong)uVar12 * (ulonglong)uVar14;
        uVar20 = (uint)lVar1;
        uVar6 = (uint)(piVar19 + 3) & 3;
        uVar10 = *(uint *)((uint)(piVar19 + 3) & 0xfffffffc);
        uVar13 = (uint)(piVar19 + 4) & 3;
        uVar15 = *(uint *)((uint)(piVar19 + 4) & 0xfffffffc);
        uVar16 = uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20;
        uVar13 = (uint)(piVar19 + 5) & 3;
        uVar15 = *(uint *)((uint)(piVar19 + 5) & 0xfffffffc);
        *piVar19 = uVar16 + uVar20;
        piVar19[1] = (uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20) +
                     (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) * uVar12 +
                     uVar14 * (uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20) +
                     (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar20);
        uVar17 = (uint)(piVar19 + 1) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
        uVar13 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
        uVar9 = *(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
                *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20;
        MKDS_SLICE_2(uStack_28,0) = (ushort)(uVar13 >> 0x13);
        uVar17 = (uint)(piVar19 + 4) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 4) & 0xfffffffc);
        uVar16 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
        uVar17 = (uint)(piVar19 + 5) & 3;
        uVar14 = *(uint *)((uint)(piVar19 + 5) & 0xfffffffc);
        uVar6 = (uint)(piVar19 + 2) & 3;
        uVar10 = *(uint *)((uint)(piVar19 + 2) & 0xfffffffc);
        uVar12 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
        uVar6 = (uint)(piVar19 + 3) & 3;
        uVar10 = *(uint *)((uint)(piVar19 + 3) & 0xfffffffc);
        lVar1 = (ulonglong)uVar9 * (ulonglong)uVar12;
        uVar15 = (uint)lVar1;
        *piVar19 = uVar16 + uVar15;
        piVar19[1] = (uVar14 >> uVar17 * 8 | uVar14 << uVar17 * -8 + 0x20) +
                     (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) * uVar9 +
                     uVar12 * uVar13 + (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar15)
        ;
        uVar17 = (uint)(piVar19 + 1) & 3;
        uVar6 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
        MKDS_SLICE_2(uStack_28,2) =
             (short)((ulonglong)(uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20) * 0x1800 >> 0x20
                    );
      }
    }
    else {
      uVar17 = (uint)(piVar19 + 2) & 3;
      uVar6 = *(uint *)((uint)(piVar19 + 2) & 0xfffffffc);
      uVar14 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
      uVar12 = *(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
               *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20;
      uVar17 = (uint)(piVar19 + 1) & 3;
      uVar9 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar12 * (ulonglong)uVar14;
      uVar20 = (uint)lVar1;
      uVar6 = (uint)(piVar19 + 3) & 3;
      uVar10 = *(uint *)((uint)(piVar19 + 3) & 0xfffffffc);
      uVar13 = (uint)(piVar19 + 4) & 3;
      uVar15 = *(uint *)((uint)(piVar19 + 4) & 0xfffffffc);
      uVar16 = uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20;
      uVar13 = (uint)(piVar19 + 5) & 3;
      uVar15 = *(uint *)((uint)(piVar19 + 5) & 0xfffffffc);
      *piVar19 = uVar16 + uVar20;
      piVar19[1] = (uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20) +
                   (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) * uVar12 +
                   uVar14 * (uVar9 >> uVar17 * 8 | uVar9 << uVar17 * -8 + 0x20) +
                   (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar20);
      uVar17 = (uint)(piVar19 + 1) & 3;
      uVar6 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
      uVar13 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
      uVar9 = *(uint *)((uint)piVar19 & 0xfffffffc) >> ((uint)piVar19 & 3) * 8 |
              *(uint *)((uint)piVar19 & 0xfffffffc) << ((uint)piVar19 & 3) * -8 + 0x20;
      MKDS_SLICE_2(uStack_28,0) = (ushort)((int)((uVar13 >> 0x14) << 0x10) >> 0xf);
      uVar17 = (uint)(piVar19 + 4) & 3;
      uVar6 = *(uint *)((uint)(piVar19 + 4) & 0xfffffffc);
      uVar16 = uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20;
      uVar17 = (uint)(piVar19 + 5) & 3;
      uVar14 = *(uint *)((uint)(piVar19 + 5) & 0xfffffffc);
      uVar6 = (uint)(piVar19 + 2) & 3;
      uVar10 = *(uint *)((uint)(piVar19 + 2) & 0xfffffffc);
      uVar12 = uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20;
      uVar6 = (uint)(piVar19 + 3) & 3;
      uVar10 = *(uint *)((uint)(piVar19 + 3) & 0xfffffffc);
      lVar1 = (ulonglong)uVar9 * (ulonglong)uVar12;
      uVar15 = (uint)lVar1;
      *piVar19 = uVar16 + uVar15;
      piVar19[1] = (uVar14 >> uVar17 * 8 | uVar14 << uVar17 * -8 + 0x20) +
                   (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) * uVar9 +
                   uVar12 * uVar13 + (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar15);
      uVar17 = (uint)(piVar19 + 1) & 3;
      uVar6 = *(uint *)((uint)(piVar19 + 1) & 0xfffffffc);
      MKDS_SLICE_2(uStack_28,2) =
           (short)((int)((ulonglong)(uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20) * 0xc00 >>
                        0x20) * 0x10000 >> 0xf);
    }
    uVar17 = (int)(short)(ushort)uStack_28 >> 10;
    if ((((2 < (uint)((int)MKDS_SLICE_2(uStack_28,2) >> 10)) || (uVar17 < 3)) || (4 < uVar17)) &&
       (((uint)(byte)puRam02103d94[(int)MKDS_SLICE_2(uStack_28,2) >> 10] & 1 << uVar17) == 0)) {
      uVar7 = func_02104000();
      uStack_28 = CONCAT22(MKDS_SLICE_2(uStack_28,2) + -0x600,(ushort)uStack_28 - 0x1000);
      func_02103db0(iVar8,uStack_28,uVar7);
      iVar8 = iVar8 + 1;
    }
    iVar18 = iVar18 + 1;
  }
  uVar17 = (uint)piRam02103d90 & 3;
  uVar6 = *(uint *)((uint)piRam02103d90 & 0xfffffffc);
  *piRam02103d88 = iVar8;
  *puVar3 = 0;
  *puVar4 = 0x1f;
  iVar18 = iRam02103dac;
  puVar5 = puRam02103da8;
  puVar3 = puRam02103da4;
  iVar8 = iRam02103da0;
  if (uVar6 >> uVar17 * 8 == 0 && uVar6 << uVar17 * -8 + 0x20 == 0) {
    uVar17 = iRam02103dac + 4U & 3;
    uVar6 = *(uint *)(iRam02103dac + 4U & 0xfffffffc);
    uVar17 = (uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20) & 0xffe0ffff;
    *(uint *)(iRam02103dac + 4) = uVar17;
    *puVar3 = 0x184;
    *puVar5 = 0x2d;
    *(uint *)(iVar18 + 4) = uVar17 | 0x1f0000;
    return;
  }
  uVar17 = iRam02103da0 + 4U & 3;
  uVar6 = *(uint *)(iRam02103da0 + 4U & 0xfffffffc);
  uVar17 = (uVar6 >> uVar17 * 8 | uVar6 << uVar17 * -8 + 0x20) & 0xffe0ffff;
  *(uint *)(iRam02103da0 + 4) = uVar17;
  puVar5 = puRam02103da8;
  *(uint *)(iVar8 + 4) = uVar17 | 0x1f0000;
  *puVar3 = 0x96;
  *puVar5 = 0x1e;
  return;
}

