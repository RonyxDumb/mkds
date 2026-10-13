/* Decompiled C draft; module arm9; ROM address 020c43c4. No matching claim. */
#include "types.h"
#include "deps/020c43c4_func_020c43c4.h"

void func_020c43c4(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  bool bVar18;
  undefined8 uVar19;
  uint uStack_38;
  undefined4 uStack_34;
  
  uVar3 = (*(uint *)(uRam020c4750 & 0xfffffffc) >> (uRam020c4750 & 3) * 8 |
          *(uint *)(uRam020c4750 & 0xfffffffc) << (uRam020c4750 & 3) * -8 + 0x20) + 8;
  uVar13 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar13 * 8 | uVar3 << uVar13 * -8 + 0x20) != 1) {
    return;
  }
  iVar4 = IsRaceCountdownEnded();
  if (iVar4 == 0) {
    return;
  }
  iVar4 = GetDirectInputUnitIndex();
  if ((*(ushort *)(iRam020c4754 + iVar4 * 0x5c) & 4) != 0) {
    puVar7 = (uint *)(*(uint *)(uRam020c4758 & 0xfffffffc) >> (uRam020c4758 & 3) * 8 |
                     *(uint *)(uRam020c4758 & 0xfffffffc) << (uRam020c4758 & 3) * -8 + 0x20);
    *puVar7 = (uint)(*(uint *)((uint)puVar7 & 0xfffffffc) >> ((uint)puVar7 & 3) * 8 == 0 &&
                    *(uint *)((uint)puVar7 & 0xfffffffc) << ((uint)puVar7 & 3) * -8 + 0x20 == 0);
  }
  iVar4 = iRam020c475c;
  uVar13 = uRam020c4758;
  uVar3 = 0;
  if (*(char *)((*(uint *)(uRam020c4750 & 0xfffffffc) >> (uRam020c4750 & 3) * 8 |
                *(uint *)(uRam020c4750 & 0xfffffffc) << (uRam020c4750 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      uVar5 = uVar3 * 0x210 +
              (*(uint *)(uRam020c4760 & 0xfffffffc) >> (uRam020c4760 & 3) * 8 |
              *(uint *)(uRam020c4760 & 0xfffffffc) << (uRam020c4760 & 3) * -8 + 0x20) + 0x204;
      uVar16 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      if (uVar5 >> uVar16 * 8 != 0 || uVar5 << uVar16 * -8 + 0x20 != 0) {
        iVar12 = (*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                 *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + uVar3 * 0x40;
        uVar5 = iVar12 + 0x790;
        uVar16 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar5 = uVar5 >> uVar16 * 8 | uVar5 << uVar16 * -8 + 0x20;
        *(uint *)(iVar12 + 0x790) = uVar5 + 1;
        GetDriverVec354((undefined4 *)(uintptr_t)((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                        *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + iVar4 +
                        uVar3 * 0x40 + uVar5 * 0xc),uVar3);
        uVar19 = CheckVectorBounds_Clock_Airship
                           ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                            *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + iVar4 +
                            uVar3 * 0x40 + uVar5 * 0xc);
        uVar8 = (undefined4)((ulonglong)uVar19 >> 0x20);
        bVar18 = (int)uVar19 != 0;
        if (bVar18) {
          uVar8 = 2;
        }
        if (!bVar18) {
          uVar8 = 3;
        }
        *(undefined4 *)
         ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
          *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + uVar3 * 0x40 + uVar5 * 4 +
         0x7b8) = uVar8;
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < *(byte *)((*(uint *)(uRam020c4750 & 0xfffffffc) >> (uRam020c4750 & 3) * 8 |
                               *(uint *)(uRam020c4750 & 0xfffffffc) <<
                               (uRam020c4750 & 3) * -8 + 0x20) + 0x3d0));
  }
  uVar16 = uRam020c4758;
  uVar5 = *(uint *)(uRam020c4758 & 0xfffffffc) >> (uRam020c4758 & 3) * 8 |
          *(uint *)(uRam020c4758 & 0xfffffffc) << (uRam020c4758 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0xc;
  uVar13 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar5 + 0xc) = (uVar3 >> uVar13 * 8 | uVar3 << uVar13 * -8 + 0x20) + 1;
  uVar5 = uRam020c4750;
  uVar9 = *(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
          *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20;
  uVar3 = uVar9 + 0xc;
  uVar13 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((int)(uVar3 >> uVar13 * 8 | uVar3 << uVar13 * -8 + 0x20) < 0x10) {
    return;
  }
  uVar3 = 0;
  *(undefined4 *)(uVar9 + 0xc) = 0;
  if (*(char *)((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x3d0) != '\0') {
    do {
      uVar15 = *(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
               *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20;
      uVar13 = 0;
      uVar9 = uVar15 + uVar3 * 0x40 + 0x790;
      uVar1 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      if (0 < (int)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20)) {
        do {
          iVar4 = uVar3 * 0x40 + uVar15 + uVar13 * 4;
          uVar9 = iVar4 + 0x7c4;
          uVar1 = uVar9 & 3;
          uVar9 = *(uint *)(uVar9 & 0xfffffffc);
          uVar9 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
          if ((int)uVar9 < 0x28) {
            *(uint *)(iVar4 + 0x7c4) = uVar9 + 1;
          }
          uVar15 = *(uint *)(uVar16 & 0xfffffffc) >> (uVar16 & 3) * 8 |
                   *(uint *)(uVar16 & 0xfffffffc) << (uVar16 & 3) * -8 + 0x20;
          uVar9 = uVar3 * 0x40 + uVar15 + 0x790;
          uVar1 = uVar9 & 3;
          uVar9 = *(uint *)(uVar9 & 0xfffffffc);
          uVar13 = uVar13 + 1 & 0xffff;
        } while ((int)uVar13 < (int)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20));
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < *(byte *)((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                               *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x3d0));
  }
  func_020b1d50();
  func_020b1d50();
  uVar13 = uRam020c4758;
  uVar3 = 0;
  if (*(char *)((*(uint *)(uRam020c4750 & 0xfffffffc) >> (uRam020c4750 & 3) * 8 |
                *(uint *)(uRam020c4750 & 0xfffffffc) << (uRam020c4750 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    uStack_34 = 3;
    uStack_38 = 0x27;
    do {
      iVar4 = GetDriverEntry(uVar3);
      iVar12 = uVar3 * 0x3c0;
      uVar16 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
               *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
      iVar17 = uVar16 + iVar12;
      uVar5 = uStack_38;
      do {
        iVar10 = uVar5 * 0x18 + iVar17;
        iVar6 = (uVar5 - 1) * 0x18 + iVar17;
        uVar5 = uVar5 - 1 & 0xffff;
        uVar11 = *(undefined4 *)(iVar6 + 0x14);
        uVar8 = *(undefined4 *)(iVar6 + 0x18);
        uVar14 = *(undefined4 *)(iVar6 + 0x1c);
        *(undefined4 *)(iVar10 + 0x10) = *(undefined4 *)(iVar6 + 0x10);
        *(undefined4 *)(iVar10 + 0x14) = uVar11;
        *(undefined4 *)(iVar10 + 0x18) = uVar8;
        *(undefined4 *)(iVar10 + 0x1c) = uVar14;
        uVar11 = *(undefined4 *)(iVar6 + 0x24);
        *(undefined4 *)(iVar10 + 0x20) = *(undefined4 *)(iVar6 + 0x20);
        *(undefined4 *)(iVar10 + 0x24) = uVar11;
      } while (uVar5 != 0);
      GetDriverVec354((undefined4 *)(uintptr_t)(uVar16 + 0x10 + iVar12),uVar3 & 0xff);
      iVar17 = CheckVectorBounds_Clock_Airship
                         ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                          *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0x10 +
                          iVar12);
      if (iVar17 != 0) {
        uVar8 = 2;
      }
      if (iVar17 == 0) {
        uVar8 = uStack_34;
      }
      *(undefined4 *)
       ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
        *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + iVar12 + 0x24) = uVar8;
      uVar2 = func_020b6338(uVar3);
      *(undefined2 *)
       ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
        *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + iVar12 + 0x1c) = uVar2;
      uVar5 = iVar4 + 0x44U & 3;
      uVar16 = *(uint *)(iVar4 + 0x44U & 0xfffffffc);
      if (((uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20) & 10) == 0) {
        uVar5 = iVar4 + 0x48U & 3;
        uVar16 = *(uint *)(iVar4 + 0x48U & 0xfffffffc);
        if (((uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20) & uRam020c4764) == 0) {
          *(undefined4 *)
           ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
            *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + iVar12 + 0x20) = 1;
        }
        else {
          *(undefined4 *)
           ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
            *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + iVar12 + 0x20) = 3;
        }
      }
      else {
        *(undefined4 *)
         ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
          *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + iVar12 + 0x20) = 2;
      }
      uVar5 = (*(uint *)(uRam020c4768 & 0xfffffffc) >> (uRam020c4768 & 3) * 8 |
              *(uint *)(uRam020c4768 & 0xfffffffc) << (uRam020c4768 & 3) * -8 + 0x20) + 0x4cc;
      uVar16 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      if (uVar5 >> uVar16 * 8 != 0 || uVar5 << uVar16 * -8 + 0x20 != 0) {
        *(undefined4 *)
         ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
          *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + iVar12 + 0x20) = 0;
        *(undefined4 *)
         ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
          *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + uVar3 * 4 + 4) = 0;
      }
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < *(byte *)((*(uint *)(uRam020c4750 & 0xfffffffc) >> (uRam020c4750 & 3) * 8 |
                               *(uint *)(uRam020c4750 & 0xfffffffc) <<
                               (uRam020c4750 & 3) * -8 + 0x20) + 0x3d0));
    return;
  }
  return;
}

