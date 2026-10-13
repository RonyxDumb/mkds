/* Decompiled C draft; module arm9; ROM address 020919e8. No matching claim. */
#include "types.h"
#include "deps/020919e8_func_020919e8.h"

/* WARNING: Removing unreachable block (ram,0x02091d4c) */

void func_020919e8(undefined4 param_1,int param_2)

{
  ushort uVar1;
  short sVar2;
  longlong lVar3;
  short sVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar23;
  uint uVar24;
  uint uVar25;
  bool bVar26;
  undefined4 local_6c;
  undefined4 local_58;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  uint uVar6;
  uint uVar17;
  uint uVar22;
  
  uVar6 = param_2 + 0xacU & 3;
  uVar5 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar6 != 0) {
    if (uVar6 != 1) {
      return;
    }
    if (*(short *)(param_2 + 0xa0) == 10) {
      local_6c = 3;
      iVar14 = 0;
      local_58 = 0;
      do {
        uVar6 = param_2 + 0xcU & 3;
        uVar7 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
        uVar5 = param_2 + 4U & 3;
        uVar15 = *(uint *)(param_2 + 4U & 0xfffffffc);
        uVar20 = param_2 + 8U & 3;
        uVar8 = *(uint *)(param_2 + 8U & 0xfffffffc);
        piVar9 = (int *)func_020d22d0();
        uVar12 = (uint)(piVar9 + 2) & 3;
        uVar16 = *(uint *)((uint)(piVar9 + 2) & 0xfffffffc);
        uVar17 = uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20;
        uVar24 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                 *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
        uVar12 = (uint)(piVar9 + 1) & 3;
        uVar13 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
        lVar3 = (ulonglong)uVar24 * (ulonglong)uVar17;
        uVar19 = (uint)lVar3;
        uVar16 = (uint)(piVar9 + 3) & 3;
        uVar25 = *(uint *)((uint)(piVar9 + 3) & 0xfffffffc);
        uVar18 = (uint)(piVar9 + 4) & 3;
        uVar21 = *(uint *)((uint)(piVar9 + 4) & 0xfffffffc);
        uVar22 = uVar21 >> uVar18 * 8 | uVar21 << uVar18 * -8 + 0x20;
        uVar18 = (uint)(piVar9 + 5) & 3;
        uVar21 = *(uint *)((uint)(piVar9 + 5) & 0xfffffffc);
        *piVar9 = uVar22 + uVar19;
        piVar9[1] = (uVar21 >> uVar18 * 8 | uVar21 << uVar18 * -8 + 0x20) +
                    (uVar25 >> uVar16 * 8 | uVar25 << uVar16 * -8 + 0x20) * uVar24 +
                    uVar17 * (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20) +
                    (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar22,uVar19);
        uVar12 = (uint)(piVar9 + 1) & 3;
        uVar16 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
        local_50 = ((uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) - 0x5000) +
                   (int)((ulonglong)(uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20) * 0xa000
                        >> 0x20);
        func_020d22d0();
        local_4c = (uVar8 >> uVar20 * 8 | uVar8 << uVar20 * -8 + 0x20) + 0x19000;
        piVar9 = (int *)func_020d22d0();
        uVar5 = (uint)(piVar9 + 2) & 3;
        uVar20 = *(uint *)((uint)(piVar9 + 2) & 0xfffffffc);
        uVar13 = uVar20 >> uVar5 * 8 | uVar20 << uVar5 * -8 + 0x20;
        uVar18 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                 *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
        uVar5 = (uint)(piVar9 + 1) & 3;
        uVar16 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
        lVar3 = (ulonglong)uVar18 * (ulonglong)uVar13;
        uVar15 = (uint)lVar3;
        uVar20 = (uint)(piVar9 + 3) & 3;
        uVar8 = *(uint *)((uint)(piVar9 + 3) & 0xfffffffc);
        uVar12 = (uint)(piVar9 + 4) & 3;
        uVar17 = *(uint *)((uint)(piVar9 + 4) & 0xfffffffc);
        uVar19 = uVar17 >> uVar12 * 8 | uVar17 << uVar12 * -8 + 0x20;
        uVar12 = (uint)(piVar9 + 5) & 3;
        uVar17 = *(uint *)((uint)(piVar9 + 5) & 0xfffffffc);
        *piVar9 = uVar19 + uVar15;
        piVar9[1] = (uVar17 >> uVar12 * 8 | uVar17 << uVar12 * -8 + 0x20) +
                    (uVar8 >> uVar20 * 8 | uVar8 << uVar20 * -8 + 0x20) * uVar18 +
                    uVar13 * (uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20) +
                    (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar19,uVar15);
        uVar5 = (uint)(piVar9 + 1) & 3;
        uVar20 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
        local_48 = ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) - 0x28000) +
                   (int)((ulonglong)(uVar20 >> uVar5 * 8 | uVar20 << uVar5 * -8 + 0x20) * 0x50000 >>
                        0x20);
        sVar2 = *(short *)(param_2 + 0x7e);
        uVar10 = func_020d22d0();
        iVar11 = func_02091f6c((int *)(uintptr_t)(uVar10),0x1000);
        uVar10 = func_020d22d0();
        sVar4 = func_02046524((int *)(uintptr_t)(uVar10),2000);
        sVar4 = sVar2 + -1000 + sVar4;
        uVar10 = Maybe_get_15d4b4(sVar4);
        local_44 = func_02091f44(iVar11 + 0x800,uVar10);
        uVar10 = func_020d22d0();
        local_40 = func_02091f6c((int *)(uintptr_t)(uVar10),0x400);
        local_40 = local_40 + 0x2200;
        uVar10 = Maybe_helper_091f24(sVar4);
        local_3c = func_02091f44(iVar11 + 0x800,uVar10);
        if ((iVar14 == 0) &&
           (uVar6 = param_2 + 0xa8U & 3, uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc),
           uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0)) {
          func_0209219c(0x50,&local_50,&local_44,0x28,1,3);
        }
        else {
          uVar10 = local_6c;
          if (iVar14 != 0) {
            uVar10 = local_58;
          }
          func_0209219c(0x50,&local_50,&local_44,0x28,0,uVar10);
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 < 3);
      uVar6 = param_2 + 0xa8U & 3;
      uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      *(uint *)(param_2 + 0xa8) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 1;
      uVar6 = param_2 + 0xa8U & 3;
      uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      if (2 < (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
        *(undefined4 *)(param_2 + 0xa8) = 0;
      }
    }
    iVar11 = *(ushort *)(param_2 + 0xa0) + 1;
    iVar14 = StructMapObject_GetAnimationBCAFrameCount
                       (*(uint *)(uRam02091f1c & 0xfffffffc) >> (uRam02091f1c & 3) * 8 |
                        *(uint *)(uRam02091f1c & 0xfffffffc) << (uRam02091f1c & 3) * -8 + 0x20);
    if (iVar14 <= iVar11) {
      iVar11 = 0;
    }
    *(short *)(param_2 + 0xa0) = (short)iVar11;
    if ((*(short *)(param_2 + 0xa0) == 0) &&
       (uVar6 = param_2 + 0xa4U & 3, uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc),
       uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,
       *(uint *)(param_2 + 0xa4) = uVar6 - 1, (int)uVar6 < 1)) {
      *(undefined4 *)(param_2 + 0xa8) = 0;
      *(undefined4 *)(param_2 + 0xac) = 0;
      if ((*(ushort *)(param_2 + 2) & 0x800) != 0) {
        piVar9 = (int *)func_020d22d0();
        uVar6 = (uint)(piVar9 + 2) & 3;
        uVar5 = *(uint *)((uint)(piVar9 + 2) & 0xfffffffc);
        uVar7 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        uVar18 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                 *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
        uVar6 = (uint)(piVar9 + 1) & 3;
        uVar12 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
        lVar3 = (ulonglong)uVar18 * (ulonglong)uVar7;
        uVar13 = (uint)lVar3;
        uVar5 = (uint)(piVar9 + 4) & 3;
        uVar20 = *(uint *)((uint)(piVar9 + 4) & 0xfffffffc);
        uVar15 = uVar20 >> uVar5 * 8 | uVar20 << uVar5 * -8 + 0x20;
        uVar5 = (uint)(piVar9 + 3) & 3;
        uVar16 = *(uint *)((uint)(piVar9 + 3) & 0xfffffffc);
        uVar20 = (uint)(piVar9 + 5) & 3;
        uVar8 = *(uint *)((uint)(piVar9 + 5) & 0xfffffffc);
        *piVar9 = uVar15 + uVar13;
        piVar9[1] = (uVar8 >> uVar20 * 8 | uVar8 << uVar20 * -8 + 0x20) +
                    (uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20) * uVar18 +
                    uVar7 * (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) +
                    (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar15,uVar13);
        uVar6 = (uint)(piVar9 + 1) & 3;
        uVar5 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
        *(int *)(param_2 + 0xa4) =
             (int)((ulonglong)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * 0x19 >> 0x20) +
             200;
      }
    }
    if (*(short *)(param_2 + 0xa0) == 0) {
      uVar6 = param_2 + 0x78U & 3;
      uVar5 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
      if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 4) == 0) {
        uVar6 = param_2 + 0x70U & 3;
        uVar5 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
        uVar20 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        uVar6 = iRam02091f20 + 0x68U & 3;
        uVar5 = *(uint *)(iRam02091f20 + 0x68U & 0xfffffffc);
        if (uVar20 == (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
          uStack_30 = 2;
        }
        else {
          uVar6 = iRam02091f20 + 0x8cU & 3;
          uVar5 = *(uint *)(iRam02091f20 + 0x8cU & 0xfffffffc);
          if (uVar20 == (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
            uStack_30 = 3;
          }
          else {
            uStack_30 = 4;
          }
        }
        iStack_34 = param_2 + 4;
        uStack_38 = 0x188;
        uStack_2c = func_020d4ef4();
        func_0210b7a8((uint)(uintptr_t)(&uStack_38));
        return;
      }
      return;
    }
    return;
  }
  iVar14 = func_02061818();
  uVar6 = uRam02091f14;
  if (iVar14 == 2) {
    *(undefined4 *)(param_2 + 0xac) = 1;
    return;
  }
  if ((*(ushort *)(param_2 + 2) & 0x800) != 0) {
    uVar6 = param_2 + 0xa4U & 3;
    uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    *(uint *)(param_2 + 0xa4) = uVar6 - 1;
    if ((int)uVar6 < 1) {
      *(undefined4 *)(param_2 + 0xa4) = 8;
      *(undefined4 *)(param_2 + 0xac) = 1;
    }
    return;
  }
  uVar1 = *(ushort *)(param_2 + 0x7e);
  uVar5 = *(uint *)(uRam02091f14 & 0xfffffffc) >> (uRam02091f14 & 3) * 8 |
          *(uint *)(uRam02091f14 & 0xfffffffc) << (uRam02091f14 & 3) * -8 + 0x20;
  uVar20 = 0;
  if (*(char *)(uVar5 + 0x3d0) != '\0') {
    do {
      uVar12 = (uVar20 & 0xffff) * 0x30 + uVar5 + 0x70;
      uVar16 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      uVar12 = uVar12 >> uVar16 * 8 | uVar12 << uVar16 * -8 + 0x20;
      bVar26 = false;
      if ((uVar12 < 4) && ((1 << (uVar12 & 0xff) & 0xdU) != 0)) {
        bVar26 = true;
      }
      if ((bVar26) || (uVar20 == (int)*(char *)(uVar5 + 0x62))) {
        iVar14 = GetDriverEntry(uVar20 & 0xffff);
        uVar5 = iVar14 + 0x88U & 3;
        uVar8 = *(uint *)(iVar14 + 0x88U & 0xfffffffc);
        uVar12 = param_2 + 0xcU & 3;
        uVar7 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
        uVar16 = iVar14 + 0x80U & 3;
        uVar18 = *(uint *)(iVar14 + 0x80U & 0xfffffffc);
        iVar23 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) -
                 (uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20);
        uVar5 = param_2 + 4U & 3;
        uVar12 = *(uint *)(param_2 + 4U & 0xfffffffc);
        iVar11 = (uVar18 >> uVar16 * 8 | uVar18 << uVar16 * -8 + 0x20) -
                 (uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20);
        lVar3 = (longlong)iVar11 * (longlong)iVar11 + (longlong)iVar23 * (longlong)iVar23;
        iVar11 = (int)((ulonglong)lVar3 >> 0x20);
        bVar26 = (uint)lVar3 < 0x10000000;
        if ((int)(iVar11 - (iRam02091f18 + (uint)bVar26)) < 0 !=
            (SBORROW4(iVar11,iRam02091f18) != SBORROW4(iVar11 - iRam02091f18,(uint)bVar26))) {
          uVar5 = iVar14 + 0x80U & 3;
          uVar15 = *(uint *)(iVar14 + 0x80U & 0xfffffffc);
          uVar12 = param_2 + 4U & 3;
          uVar13 = *(uint *)(param_2 + 4U & 0xfffffffc);
          uVar16 = iVar14 + 0x88U & 3;
          uVar8 = *(uint *)(iVar14 + 0x88U & 0xfffffffc);
          uVar18 = param_2 + 0xcU & 3;
          uVar7 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
          iVar14 = FX_Atan2((uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) -
                            (uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20),
                            (uVar8 >> uVar16 * 8 | uVar8 << uVar16 * -8 + 0x20) -
                            (uVar7 >> uVar18 * 8 | uVar7 << uVar18 * -8 + 0x20));
          iVar14 = iVar14 - (uint)uVar1;
          if ((-0x1f41 < iVar14) && (iVar14 < 0x1f41)) {
            bVar26 = true;
            goto LAB_02091b64;
          }
        }
      }
      uVar5 = uVar6 & 3;
      uVar12 = *(uint *)(uVar6 & 0xfffffffc);
      uVar5 = uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20;
      uVar20 = uVar20 + 1;
    } while ((int)uVar20 < (int)(uint)*(byte *)(uVar5 + 0x3d0));
  }
  bVar26 = false;
LAB_02091b64:
  if (bVar26) {
    *(undefined4 *)(param_2 + 0xa4) = 8;
    *(undefined4 *)(param_2 + 0xac) = 1;
  }
  return;
}

