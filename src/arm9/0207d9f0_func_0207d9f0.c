/* Decompiled C draft; module arm9; ROM address 0207d9f0. No matching claim. */
#include "types.h"
#include "deps/0207d9f0_func_0207d9f0.h"

void func_0207d9f0(int param_1,int param_2,int param_3)

{
  longlong lVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar15;
  uint uVar14;
  
  uVar12 = (uint)*(ushort *)(param_2 + 4);
  uVar11 = param_1 + 0x14U & 3;
  uVar13 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar14 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
  puVar15 = (undefined4 *)(param_1 + 0x1c);
  iVar3 = func_02085424();
  uVar13 = uRam0207de60;
  bVar8 = false;
  *(undefined4 *)(param_1 + 0x18) = 0;
  uVar11 = uVar13 & 3;
  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
  uVar11 = uVar12 * 0x30 + (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) + 0x70;
  uVar13 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar11 = uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20;
  if ((uVar11 < 4) && ((1 << (uVar11 & 0xff) & 0xdU) != 0)) {
    bVar8 = true;
  }
  if (bVar8) {
    return;
  }
  if ((2 < (int)(*(uint *)((uint)puVar15 & 0xfffffffc) >> ((uint)puVar15 & 3) * 8 |
                *(uint *)((uint)puVar15 & 0xfffffffc) << ((uint)puVar15 & 3) * -8 + 0x20)) &&
     (2 < (int)uVar14)) {
    *(uint *)(param_1 + 0x20) = uVar14;
  }
  if (((((*(uint *)((uint)puVar15 & 0xfffffffc) >> ((uint)puVar15 & 3) * 8 |
         *(uint *)((uint)puVar15 & 0xfffffffc) << ((uint)puVar15 & 3) * -8 + 0x20) == 1) &&
       (uVar11 = (*(uint *)(uRam0207de60 & 0xfffffffc) >> (uRam0207de60 & 3) * 8 |
                 *(uint *)(uRam0207de60 & 0xfffffffc) << (uRam0207de60 & 3) * -8 + 0x20) + 8,
       uVar13 = uVar11 & 3, uVar11 = *(uint *)(uVar11 & 0xfffffffc),
       uVar11 >> uVar13 * 8 == 0 && uVar11 << uVar13 * -8 + 0x20 == 0)) &&
      (iVar4 = func_020853a4(uVar12), iRam0207de64 <= iVar4)) &&
     (uVar11 = GetDriverPlace(uVar12), 3 < uVar11)) {
    uVar2 = 1;
    do {
      iVar4 = func_02085408(uVar2);
      if (-1 < iVar4) {
        iVar4 = GetDriverEntry();
        uVar11 = iVar4 + 0x310U & 3;
        uVar13 = *(uint *)(iVar4 + 0x310U & 0xfffffffc);
        uVar13 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
        uVar11 = uVar13 + 0x154 & 3;
        uVar9 = *(uint *)(uVar13 + 0x154 & 0xfffffffc);
        if ((uVar9 >> uVar11 * 8 != 0 || uVar9 << uVar11 * -8 + 0x20 != 0) &&
           (uVar11 = uVar13 + 0x104 & 3, uVar9 = *(uint *)(uVar13 + 0x104 & 0xfffffffc),
           (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) == 2)) {
          *puVar15 = 2;
          *(uint *)(param_1 + 0x20) =
               *(uint *)((uint)puVar15 & 0xfffffffc) >> ((uint)puVar15 & 3) * 8 |
               *(uint *)((uint)puVar15 & 0xfffffffc) << ((uint)puVar15 & 3) * -8 + 0x20;
          *(undefined4 *)(uVar13 + 0x108) = 1;
          uVar11 = uVar13 + 0x108 & 3;
          uVar9 = *(uint *)(uVar13 + 0x108 & 0xfffffffc);
          *(uint *)(uVar13 + 0x104) = uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20;
          break;
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
  }
  uVar11 = param_1 + 0x20U & 3;
  uVar13 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar11 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
  iVar4 = IsRacerFinishedRace(uVar12);
  if (iVar4 == 0) {
    uVar13 = *(uint *)(uRam0207de6c & 0xfffffffc) >> (uRam0207de6c & 3) * 8 |
             *(uint *)(uRam0207de6c & 0xfffffffc) << (uRam0207de6c & 3) * -8 + 0x20;
  }
  else {
    uVar13 = *(uint *)(uRam0207de68 & 0xfffffffc) >> (uRam0207de68 & 3) * 8 |
             *(uint *)(uRam0207de68 & 0xfffffffc) << (uRam0207de68 & 3) * -8 + 0x20;
  }
  uVar13 = uVar13 + (uVar14 - 1) * 4;
  uVar9 = uVar13 & 3;
  uVar10 = *(uint *)(uVar13 & 0xfffffffc);
  uVar13 = iVar3 + 4U & 3;
  uVar5 = *(uint *)(iVar3 + 4U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20) *
          (longlong)(int)(uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20);
  *(uint *)(param_1 + 0x24) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  iVar4 = func_02085390();
  if (iVar4 == 0) {
    if ((int)uVar14 < (int)uVar11) {
      uVar11 = param_1 + 0x10U & 3;
      uVar13 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      uVar11 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
      lVar1 = (ulonglong)uRam0207de74 * (ulonglong)uVar11;
      *(uint *)(param_1 + 0x10) =
           (uint)lVar1 >> 0xc |
           (((int)uVar11 >> 0x1f) * uRam0207de74 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
    else if (uVar14 == uVar11) {
      if (uVar14 == 1) {
        uVar11 = func_020854a0(1,*puRam0207de78);
        if (-1 < (int)uVar11) {
          iVar4 = func_020853a4(uVar12);
          iVar6 = func_020853a4(uVar11 & 0xffff);
          iVar7 = GetDriverEntry(uVar11);
          uVar11 = iVar7 + 0x310U & 3;
          uVar13 = *(uint *)(iVar7 + 0x310U & 0xfffffffc);
          uVar11 = (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) + 0x10c;
          uVar13 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          if ((int)(uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20) < iVar4 - iVar6) {
            uVar11 = param_1 + 0x10U & 3;
            uVar13 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
            uVar11 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
            lVar1 = (ulonglong)uRam0207de70 * (ulonglong)uVar11;
            *(uint *)(param_1 + 0x10) =
                 (uint)lVar1 >> 0xc |
                 (((int)uVar11 >> 0x1f) * uRam0207de70 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000
            ;
            *(undefined4 *)(param_1 + 0x18) = 1;
          }
        }
      }
      else {
        iVar4 = func_020853a4(uVar12);
        uVar11 = func_02085478();
        if (-1 < (int)uVar11) {
          iVar6 = func_020853a4(uVar11 & 0xffff);
          iVar7 = func_0208548c();
          uVar11 = param_1 + 0x24U & 3;
          uVar13 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
          lVar1 = (longlong)(int)(uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) *
                  (longlong)iVar7;
          uVar11 = (iVar6 - iVar4) - ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14);
          if ((int)uVar11 < 1) {
            uVar11 = func_02085458(uVar14);
            if ((-1 < (int)uVar11) &&
               (iVar6 = GetDriverEntry(), uVar13 = iVar3 + 8U & 3,
               uVar12 = *(uint *)(iVar3 + 8U & 0xfffffffc),
               uVar14 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20,
               lVar1 = (ulonglong)uVar14 * 0xcd0, uVar13 = iVar6 + 0x310U & 3,
               uVar12 = *(uint *)(iVar6 + 0x310U & 0xfffffffc),
               uVar13 = (uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20) + 0xec,
               uVar12 = uVar13 & 3, uVar13 = *(uint *)(uVar13 & 0xfffffffc),
               (int)((uint)lVar1 >> 0xc |
                    (((int)uVar14 >> 0x1f) * 0xcd0 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000) <
               (int)(uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20))) {
              iVar6 = func_020853a4(uVar11 & 0xffff);
              iVar7 = func_0208548c();
              uVar11 = param_1 + 0x24U & 3;
              uVar13 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
              lVar1 = (longlong)(int)(uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) *
                      (longlong)iVar7;
              if (iVar6 - iVar4 <
                  (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14)) {
                uVar11 = param_1 + 0x10U & 3;
                uVar13 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
                uVar11 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
                lVar1 = (ulonglong)uRam0207de7c * (ulonglong)uVar11;
                *(uint *)(param_1 + 0x10) =
                     (uint)lVar1 >> 0xc |
                     (((int)uVar11 >> 0x1f) * uRam0207de7c + (int)((ulonglong)lVar1 >> 0x20)) *
                     0x100000;
                *(undefined4 *)(param_1 + 0x18) = 1;
              }
            }
          }
          else {
            lVar1 = (ulonglong)uVar11 * 0x3000;
            uVar11 = param_1 + 0x10U & 3;
            uVar13 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
            *(uint *)(param_1 + 0x10) =
                 (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) +
                 ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
          }
        }
      }
    }
  }
  else {
    uVar11 = iVar3 + 4U & 3;
    uVar12 = *(uint *)(iVar3 + 4U & 0xfffffffc);
    uVar13 = func_02085434();
    if (-1 < (int)uVar13) {
      iVar4 = func_020853a4(*(undefined2 *)(param_2 + 4));
      iVar6 = func_020853a4(uVar13 & 0xffff);
      iVar7 = IsRacerFinishedRace(*(undefined2 *)(param_2 + 4));
      if (iVar7 == 0) {
        uVar14 = *(uint *)(uRam0207de6c & 0xfffffffc) >> (uRam0207de6c & 3) * 8 |
                 *(uint *)(uRam0207de6c & 0xfffffffc) << (uRam0207de6c & 3) * -8 + 0x20;
      }
      else {
        uVar14 = *(uint *)(uRam0207de68 & 0xfffffffc) >> (uRam0207de68 & 3) * 8 |
                 *(uint *)(uRam0207de68 & 0xfffffffc) << (uRam0207de68 & 3) * -8 + 0x20;
      }
      iVar7 = GetDriverPlace(uVar13 & 0xffff);
      uVar14 = uVar14 + iVar7 * 4;
      uVar13 = uVar14 & 3;
      uVar14 = *(uint *)(uVar14 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) *
              (longlong)(int)(uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20);
      if ((int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) < iVar4 - iVar6) {
        uVar11 = param_1 + 0x10U & 3;
        uVar13 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
        uVar11 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
        lVar1 = (ulonglong)uRam0207de70 * (ulonglong)uVar11;
        *(uint *)(param_1 + 0x10) =
             (uint)lVar1 >> 0xc |
             (((int)uVar11 >> 0x1f) * uRam0207de70 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
        *(undefined4 *)(param_1 + 0x18) = 1;
      }
    }
  }
  uVar11 = param_1 + 0x18U & 3;
  uVar13 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  if (uVar13 >> uVar11 * 8 != 0 || uVar13 << uVar11 * -8 + 0x20 != 0) {
    uVar11 = iVar3 + 8U & 3;
    uVar13 = *(uint *)(iVar3 + 8U & 0xfffffffc);
    uVar12 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
    uVar11 = param_1 + 0x10U & 3;
    uVar13 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    if ((int)(uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) < (int)uVar12) {
      *(uint *)(param_1 + 0x10) = uVar12;
    }
    return;
  }
  uVar11 = param_1 + 0x10U & 3;
  uVar13 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar11 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
  lVar1 = (ulonglong)uRam0207de80 * (ulonglong)uVar11;
  *(uint *)(param_1 + 0x10) =
       (uint)lVar1 >> 0xc |
       (((int)uVar11 >> 0x1f) * uRam0207de80 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar11 = param_1 + 0x10U & 3;
  uVar13 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  if (param_3 <= (int)(uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20)) {
    *(int *)(param_1 + 0x10) = param_3;
  }
  return;
}

