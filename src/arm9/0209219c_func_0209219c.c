/* Decompiled C draft; module arm9; ROM address 0209219c. No matching claim. */
#include "types.h"
#include "deps/0209219c_func_0209219c.h"

void func_0209219c(int param_1,undefined4 *param_2,undefined4 *param_3,int param_4,
                  undefined4 param_5,undefined2 param_6)

{
  longlong lVar1;
  ushort *puVar2;
  ushort *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar15;
  undefined4 uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar7;
  uint uVar14;
  
  func_02100138(uRam02092458);
  iVar4 = func_0209bbfc();
  puVar3 = puRam02092464;
  puVar2 = puRam02092460;
  if (iVar4 != 0) {
    *(ushort *)(iVar4 + 2) = *(ushort *)(iVar4 + 2) | *puRam0209245c;
    *(ushort *)(iVar4 + 2) = *(ushort *)(iVar4 + 2) | *puVar2;
    *(ushort *)(iVar4 + 2) = *(ushort *)(iVar4 + 2) | *puVar3;
    *(undefined4 *)(iVar4 + 0xbc) = param_5;
    *(undefined2 *)(iVar4 + 0xc0) = param_6;
    piVar5 = (int *)func_020d22d0();
    uVar12 = (uint)(piVar5 + 2) & 3;
    uVar13 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
    uVar14 = uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20;
    uVar11 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
             *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
    uVar12 = (uint)(piVar5 + 1) & 3;
    uVar8 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar11 * (ulonglong)uVar14;
    uVar18 = (uint)lVar1;
    uVar13 = (uint)(piVar5 + 4) & 3;
    uVar6 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
    uVar7 = uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20;
    uVar13 = (uint)(piVar5 + 3) & 3;
    uVar9 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
    uVar6 = (uint)(piVar5 + 5) & 3;
    uVar15 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
    *piVar5 = uVar7 + uVar18;
    piVar5[1] = (uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20) +
                (uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) * uVar11 +
                uVar14 * (uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar7,uVar18);
    uVar12 = (uint)(param_4 << 0xc) >> 0x10;
    uVar13 = (uint)(piVar5 + 1) & 3;
    uVar6 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
    uVar13 = uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20;
    uVar10 = (undefined4)((ulonglong)uVar13 * 0x1e);
    uVar16 = (undefined4)((ulonglong)uVar13 * 0x1e >> 0x20);
    *(undefined4 *)(iVar4 + 0xb0) = uVar16;
    if (uVar12 == 0x10000) {
      piVar5 = (int *)func_020d22d0(uVar16,uVar13,uVar10);
      uVar12 = (uint)(piVar5 + 2) & 3;
      uVar13 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
      uVar15 = uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20;
      uVar11 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
               *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
      uVar12 = (uint)(piVar5 + 1) & 3;
      uVar9 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar11 * (ulonglong)uVar15;
      uVar7 = (uint)lVar1;
      uVar13 = (uint)(piVar5 + 4) & 3;
      uVar6 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
      uVar8 = uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20;
      uVar13 = (uint)(piVar5 + 3) & 3;
      uVar18 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
      uVar6 = (uint)(piVar5 + 5) & 3;
      uVar14 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
      *piVar5 = uVar8 + uVar7;
      piVar5[1] = (uVar14 >> uVar6 * 8 | uVar14 << uVar6 * -8 + 0x20) +
                  (uVar18 >> uVar13 * 8 | uVar18 << uVar13 * -8 + 0x20) * uVar11 +
                  uVar15 * (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar8,uVar7);
      uVar12 = (uint)(piVar5 + 1) & 3;
      uVar13 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      uVar12 = (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20) >> 0x10;
    }
    else {
      piVar5 = (int *)func_020d22d0(uVar16,uVar13,uVar10);
      if (uVar12 == 0) {
        uVar12 = 0;
      }
      else {
        uVar13 = (uint)(piVar5 + 2) & 3;
        uVar6 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
        uVar15 = uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20;
        uVar14 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                 *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
        uVar13 = (uint)(piVar5 + 1) & 3;
        uVar8 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
        lVar1 = (ulonglong)uVar14 * (ulonglong)uVar15;
        uVar17 = (uint)lVar1;
        uVar6 = (uint)(piVar5 + 3) & 3;
        uVar9 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
        uVar7 = (uint)(piVar5 + 4) & 3;
        uVar11 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
        uVar18 = uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20;
        uVar7 = (uint)(piVar5 + 5) & 3;
        uVar11 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
        *piVar5 = uVar18 + uVar17;
        piVar5[1] = (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) +
                    (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) * uVar14 +
                    uVar15 * (uVar8 >> uVar13 * 8 | uVar8 << uVar13 * -8 + 0x20) +
                    (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar18,uVar17);
        if (uVar12 == 0) {
          uVar12 = (uint)(piVar5 + 1) & 3;
          uVar13 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
          uVar12 = uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20;
        }
        else {
          uVar13 = (uint)(piVar5 + 1) & 3;
          uVar6 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
          uVar12 = (uint)((ulonglong)uVar12 *
                          (ulonglong)(uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) >> 0x20);
        }
      }
      uVar12 = uVar12 & 0xffff;
    }
    uVar13 = (uint)(param_1 << 0xc) >> 0x10;
    *(uint *)(iVar4 + 0xb4) = param_4 + uVar12;
    if (uVar13 == 0x10000) {
      piVar5 = (int *)func_020d22d0();
      uVar12 = (uint)(piVar5 + 2) & 3;
      uVar13 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
      uVar11 = uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20;
      uVar8 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
              *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
      uVar12 = (uint)(piVar5 + 1) & 3;
      uVar7 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar8 * (ulonglong)uVar11;
      uVar15 = (uint)lVar1;
      uVar13 = (uint)(piVar5 + 4) & 3;
      uVar6 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
      uVar18 = uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20;
      uVar13 = (uint)(piVar5 + 3) & 3;
      uVar14 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
      uVar6 = (uint)(piVar5 + 5) & 3;
      uVar9 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
      *piVar5 = uVar18 + uVar15;
      piVar5[1] = (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) +
                  (uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) * uVar8 +
                  uVar11 * (uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar18,uVar15);
      uVar12 = (uint)(piVar5 + 1) & 3;
      uVar13 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      uVar12 = (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20) >> 0x10;
    }
    else {
      piVar5 = (int *)func_020d22d0();
      if (uVar13 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = (uint)(piVar5 + 2) & 3;
        uVar6 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
        uVar15 = uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20;
        uVar14 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                 *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
        uVar12 = (uint)(piVar5 + 1) & 3;
        uVar8 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
        lVar1 = (ulonglong)uVar14 * (ulonglong)uVar15;
        uVar17 = (uint)lVar1;
        uVar6 = (uint)(piVar5 + 3) & 3;
        uVar9 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
        uVar7 = (uint)(piVar5 + 4) & 3;
        uVar11 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
        uVar18 = uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20;
        uVar7 = (uint)(piVar5 + 5) & 3;
        uVar11 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
        *piVar5 = uVar18 + uVar17;
        piVar5[1] = (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) +
                    (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) * uVar14 +
                    uVar15 * (uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20) +
                    (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar18,uVar17);
        if (uVar13 == 0) {
          uVar12 = (uint)(piVar5 + 1) & 3;
          uVar13 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
          uVar12 = uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20;
        }
        else {
          uVar12 = (uint)(piVar5 + 1) & 3;
          uVar6 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
          uVar12 = (uint)((ulonglong)uVar13 *
                          (ulonglong)(uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) >> 0x20);
        }
      }
      uVar12 = uVar12 & 0xffff;
    }
    *(uint *)(iVar4 + 0xb8) = param_1 + uVar12;
    uVar10 = param_2[1];
    uVar16 = param_2[2];
    *(undefined4 *)(iVar4 + 4) = *param_2;
    *(undefined4 *)(iVar4 + 8) = uVar10;
    *(undefined4 *)(iVar4 + 0xc) = uVar16;
    uVar10 = param_3[1];
    uVar16 = param_3[2];
    *(undefined4 *)(iVar4 + 0xa0) = *param_3;
    *(undefined4 *)(iVar4 + 0xa4) = uVar10;
    *(undefined4 *)(iVar4 + 0xa8) = uVar16;
    *(undefined4 *)(iVar4 + 0xd4) = 0;
    *(undefined1 *)(iVar4 + 0xd0) = 0;
    return;
  }
  return;
}

