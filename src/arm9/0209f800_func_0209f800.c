/* Decompiled C draft; module arm9; ROM address 0209f800. No matching claim. */
#include "types.h"
#include "deps/0209f800_func_0209f800.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0209f800(uint param_1,undefined4 param_2,int param_3,uint param_4)

{
  short sVar1;
  longlong lVar2;
  undefined2 uVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iStack_3c;
  int iStack_2c;
  
  if (param_1 == 0) {
    return;
  }
  iStack_2c = 0;
  iStack_3c = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iStack_3c) {
      return;
    }
    uVar8 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar10 = uVar8 + iStack_3c * 4;
    uVar4 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20;
    if (uVar10 == 0) break;
    *(undefined4 *)(uVar10 + 0xa4) = 0;
    *(undefined4 *)(uVar10 + 0xa8) = 0;
    uVar4 = StructMapObject_SomeFn_1
                      (*(uint *)(uRam0209fb04 & 0xfffffffc) >> (uRam0209fb04 & 3) * 8 |
                       *(uint *)(uRam0209fb04 & 0xfffffffc) << (uRam0209fb04 & 3) * -8 + 0x20,uVar8,
                       param_3,param_4);
    if (uVar4 == 0x10000) {
      piVar5 = (int *)func_020d22d0();
      uVar4 = (uint)(piVar5 + 2) & 3;
      uVar8 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
      uVar16 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
      uVar13 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
               *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
      uVar4 = (uint)(piVar5 + 4) & 3;
      uVar8 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
      uVar9 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
      uVar4 = (uint)(piVar5 + 5) & 3;
      uVar7 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
      uVar8 = (uint)(piVar5 + 3) & 3;
      uVar14 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
      uVar15 = (uint)(piVar5 + 1) & 3;
      uVar12 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)uVar13 * (ulonglong)uVar16;
      uVar18 = (uint)lVar2;
      *piVar5 = uVar9 + uVar18;
      piVar5[1] = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) +
                  (uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20) * uVar13 +
                  uVar16 * (uVar12 >> uVar15 * 8 | uVar12 << uVar15 * -8 + 0x20) +
                  (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar9,uVar18);
      uVar4 = (uint)(piVar5 + 1) & 3;
      uVar8 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      uVar11 = (ushort)((uVar8 >> uVar4 * 8) >> 0x10) |
               (ushort)((uVar8 << uVar4 * -8 + 0x20) >> 0x10);
    }
    else {
      piVar5 = (int *)func_020d22d0();
      uVar4 = uVar4 & 0xffff;
      if (uVar4 == 0) {
        uVar11 = 0;
      }
      else {
        uVar8 = (uint)(piVar5 + 2) & 3;
        uVar15 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
        uVar14 = uVar15 >> uVar8 * 8 | uVar15 << uVar8 * -8 + 0x20;
        uVar12 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                 *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
        uVar8 = (uint)(piVar5 + 1) & 3;
        uVar9 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
        lVar2 = (ulonglong)uVar12 * (ulonglong)uVar14;
        uVar16 = (uint)lVar2;
        uVar15 = (uint)(piVar5 + 3) & 3;
        uVar13 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
        uVar7 = (uint)(piVar5 + 4) & 3;
        uVar18 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
        uVar19 = uVar18 >> uVar7 * 8 | uVar18 << uVar7 * -8 + 0x20;
        uVar7 = (uint)(piVar5 + 5) & 3;
        uVar18 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
        *piVar5 = uVar19 + uVar16;
        piVar5[1] = (uVar18 >> uVar7 * 8 | uVar18 << uVar7 * -8 + 0x20) +
                    (uVar13 >> uVar15 * 8 | uVar13 << uVar15 * -8 + 0x20) * uVar12 +
                    uVar14 * (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) +
                    (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar19,uVar16);
        if (uVar4 == 0) {
          uVar4 = (uint)(piVar5 + 1) & 3;
          uVar8 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
          uVar11 = (ushort)(uVar8 >> uVar4 * 8) | (ushort)(uVar8 << uVar4 * -8 + 0x20);
        }
        else {
          uVar8 = (uint)(piVar5 + 1) & 3;
          uVar15 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
          uVar11 = (ushort)((ulonglong)uVar4 *
                            (ulonglong)(uVar15 >> uVar8 * 8 | uVar15 << uVar8 * -8 + 0x20) >> 0x20);
        }
      }
    }
    *(ushort *)(uVar10 + 0xa0) = uVar11;
    piVar5 = (int *)func_020d22d0();
    uVar7 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
            *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
    uVar4 = (uint)(piVar5 + 2) & 3;
    uVar8 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
    uVar18 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
    uVar4 = (uint)(piVar5 + 1) & 3;
    uVar16 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
    lVar2 = (ulonglong)uVar7 * (ulonglong)uVar18;
    uVar12 = (uint)lVar2;
    uVar8 = (uint)(piVar5 + 4) & 3;
    uVar15 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
    uVar14 = uVar15 >> uVar8 * 8 | uVar15 << uVar8 * -8 + 0x20;
    uVar8 = (uint)(piVar5 + 3) & 3;
    uVar9 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
    uVar15 = (uint)(piVar5 + 5) & 3;
    uVar13 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
    *piVar5 = uVar14 + uVar12;
    piVar5[1] = (uVar13 >> uVar15 * 8 | uVar13 << uVar15 * -8 + 0x20) +
                (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) * uVar7 +
                uVar18 * (uVar16 >> uVar4 * 8 | uVar16 << uVar4 * -8 + 0x20) +
                (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar14,uVar12);
    uVar4 = (uint)(piVar5 + 1) & 3;
    uVar8 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
    lVar2 = (ulonglong)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) * 0x1a;
    param_4 = (uint)lVar2;
    param_3 = (int)((ulonglong)lVar2 >> 0x20);
    if (param_3 != 0) {
      piVar5 = (int *)(uVar10 + 0xa4);
      iVar17 = iStack_2c;
      do {
        uVar4 = uVar10 + 0xa8 & 3;
        uVar8 = *(uint *)(uVar10 + 0xa8 & 0xfffffffc);
        puVar6 = (uint *)(uVar10 + 0xa8);
        *piVar5 = (*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                  *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20) +
                  (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20);
        uVar4 = uVar10 + 0xa8 & 3;
        uVar8 = *(uint *)(uVar10 + 0xa8 & 0xfffffffc);
        *(uint *)(uVar10 + 0xa8) = (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) + 0x4000;
        uVar4 = uVar10 + 0xa4 & 3;
        uVar8 = *(uint *)(uVar10 + 0xa4 & 0xfffffffc);
        param_4 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
        if (param_4 == 0) {
          uVar4 = uVar10 + 0xa8 & 3;
          uVar8 = *(uint *)(uVar10 + 0xa8 & 0xfffffffc);
          *piVar5 = (*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                    *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20) +
                    (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20);
          param_4 = (*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                    *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20) + 0x4000
          ;
          *puVar6 = param_4;
        }
        else if (0x16bfff < (int)param_4) {
          uVar4 = uVar10 + 0xa8 & 3;
          uVar8 = *(uint *)(uVar10 + 0xa8 & 0xfffffffc);
          *(uint *)(uVar10 + 0xa8) = 0x4000 - (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20);
          uVar4 = uVar10 + 0xac & 3;
          uVar8 = *(uint *)(uVar10 + 0xac & 0xfffffffc);
          *(uint *)(uVar10 + 0xac) =
               (uint)(uVar8 >> uVar4 * 8 == 0 && uVar8 << uVar4 * -8 + 0x20 == 0);
        }
        iVar17 = iVar17 + 1;
      } while (iVar17 < param_3);
    }
    uVar4 = uVar10 + 0x9c & 3;
    uVar8 = *(uint *)(uVar10 + 0x9c & 0xfffffffc);
    if (*(short *)((uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) + 0x28) != 0) {
      sVar1 = *(short *)(uVar10 + 0xa0);
      if (sVar1 == 0) {
        *(short *)(uVar10 + 0xa2) = (short)uRam0209fb08;
      }
      else if (sVar1 == 1) {
        *(undefined2 *)(uVar10 + 0xa2) = 0x1a8;
      }
      else if (sVar1 == 2) {
        piVar5 = (int *)func_020d22d0();
        uVar4 = (uint)(piVar5 + 2) & 3;
        uVar8 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
        uVar16 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
        uVar13 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                 *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
        uVar4 = (uint)(piVar5 + 1) & 3;
        uVar12 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
        lVar2 = (ulonglong)uVar13 * (ulonglong)uVar16;
        uVar18 = (uint)lVar2;
        uVar8 = (uint)(piVar5 + 4) & 3;
        uVar15 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
        uVar9 = uVar15 >> uVar8 * 8 | uVar15 << uVar8 * -8 + 0x20;
        uVar8 = (uint)(piVar5 + 3) & 3;
        uVar14 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
        uVar15 = (uint)(piVar5 + 5) & 3;
        uVar7 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
        param_3 = uVar9 + uVar18;
        *piVar5 = param_3;
        piVar5[1] = (uVar7 >> uVar15 * 8 | uVar7 << uVar15 * -8 + 0x20) +
                    (uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20) * uVar13 +
                    uVar16 * (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) +
                    (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar9,uVar18);
        uVar4 = (uint)(piVar5 + 1) & 3;
        uVar8 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
        param_4 = -((int)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) >> 0x1f);
        uVar4 = param_4;
        if (param_4 != 0) {
          uVar4 = uRam0209fb08;
        }
        uVar3 = (short)uVar4;
        if (param_4 == 0) {
          uVar3 = 0x1a8;
        }
        *(undefined2 *)(uVar10 + 0xa2) = uVar3;
      }
    }
    iStack_3c = iStack_3c + 1;
  }
  return;
}

