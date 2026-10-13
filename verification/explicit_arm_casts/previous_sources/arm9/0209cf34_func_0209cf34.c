/* Decompiled C draft; module arm9; ROM address 0209cf34. No matching claim. */
#include "types.h"
#include "deps/0209cf34_func_0209cf34.h"

void func_0209cf34(undefined4 param_1,int param_2)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24 [3];
  uint uVar16;
  
  iVar4 = DAT_0209d37c;
  iVar6 = DAT_0209d374;
  uVar9 = DAT_0209d370;
  uVar7 = param_2 + 0xdcU & 3;
  uVar3 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
  switch(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) {
  case 0:
    if ((*(ushort *)(param_2 + 2) & 0x800) == 0) {
      uVar7 = 0;
      if (*(char *)((*(uint *)(DAT_0209d370 & 0xfffffffc) >> (DAT_0209d370 & 3) * 8 |
                    *(uint *)(DAT_0209d370 & 0xfffffffc) << (DAT_0209d370 & 3) * -8 + 0x20) + 0x3d0)
          != '\0') {
        do {
          iVar6 = func_0203c8c0(uVar7 & 0xffff);
          if (1 < iVar6) {
            bVar2 = true;
            goto LAB_0209cfd4;
          }
          uVar7 = uVar7 + 1;
        } while ((int)uVar7 <
                 (int)(uint)*(byte *)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                                      *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) +
                                     0x3d0));
      }
      bVar2 = false;
LAB_0209cfd4:
      if (bVar2) {
        *(undefined4 *)(param_2 + 0xdc) = 1;
      }
    }
    else {
      uVar7 = param_2 + 0xa8U & 3;
      uVar9 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
      *(uint *)(param_2 + 0xa8) = uVar7 - 1;
      if ((int)uVar7 < 1) {
        *(undefined4 *)(param_2 + 0xdc) = 1;
      }
    }
    break;
  case 1:
    *(undefined4 *)(param_2 + 0xbc) = 0x3c000;
    uVar7 = param_2 + 0xb8U & 3;
    uVar9 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    uVar3 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    uVar7 = param_2 + 0xc4U & 3;
    uVar8 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
    uVar9 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar7 = (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) * 0x54 +
            (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) + 0x34;
    uVar9 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    lVar1 = (ulonglong)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) * 0x3c000;
    *(uint *)(param_2 + 200) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    iVar6 = func_020d8cc8(param_2 + 0xb8);
    if (iVar6 != 0) {
      uVar7 = param_2 + 0xd4U & 3;
      uVar9 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
      uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
      iVar6 = (int)*(short *)(uVar7 + 0xe);
      if (iVar6 != 0) {
        if ((*(ushort *)(param_2 + 2) & 0x800) != 0) {
          uVar9 = (*(uint *)(DAT_0209d370 & 0xfffffffc) >> (DAT_0209d370 & 3) * 8 |
                  *(uint *)(DAT_0209d370 & 0xfffffffc) << (DAT_0209d370 & 3) * -8 + 0x20) + 8;
          uVar3 = uVar9 & 3;
          uVar9 = *(uint *)(uVar9 & 0xfffffffc);
          uVar9 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20;
          if (uVar9 == 1) {
            *(int *)(param_2 + 0xa8) = iVar6;
          }
          else if (uVar9 == 5) {
            *(int *)(param_2 + 0xa8) = (int)*(short *)(uVar7 + 0x10);
          }
        }
        *(undefined4 *)(param_2 + 0xdc) = 2;
      }
    }
    func_020d8a5c(param_2 + 0xb8,param_2 + 4);
    break;
  case 2:
    if ((*(ushort *)(param_2 + 2) & 0x800) == 0) {
      uVar7 = 0;
      if (*(char *)((*(uint *)(DAT_0209d370 & 0xfffffffc) >> (DAT_0209d370 & 3) * 8 |
                    *(uint *)(DAT_0209d370 & 0xfffffffc) << (DAT_0209d370 & 3) * -8 + 0x20) + 0x3d0)
          != '\0') {
        do {
          iVar4 = GetDriverEntry(uVar7 & 0xffff);
          uVar3 = iVar4 + 0x88U & 3;
          uVar12 = *(uint *)(iVar4 + 0x88U & 0xfffffffc);
          uVar8 = param_2 + 0xcU & 3;
          uVar15 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
          uVar11 = iVar4 + 0x80U & 3;
          uVar13 = *(uint *)(iVar4 + 0x80U & 0xfffffffc);
          iVar4 = (uVar12 >> uVar3 * 8 | uVar12 << uVar3 * -8 + 0x20) -
                  (uVar15 >> uVar8 * 8 | uVar15 << uVar8 * -8 + 0x20);
          uVar3 = param_2 + 4U & 3;
          uVar8 = *(uint *)(param_2 + 4U & 0xfffffffc);
          iVar10 = (uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20) -
                   (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20);
          if ((int)((ulonglong)
                    ((longlong)iVar10 * (longlong)iVar10 + (longlong)iVar4 * (longlong)iVar4) >>
                   0x20) < iVar6) {
            bVar2 = true;
            goto LAB_0209d148;
          }
          uVar7 = uVar7 + 1;
        } while ((int)uVar7 <
                 (int)(uint)*(byte *)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                                      *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) +
                                     0x3d0));
      }
      bVar2 = false;
LAB_0209d148:
      if (bVar2) {
        *(undefined2 *)(param_2 + 0xb0) = 0;
        *(uint *)(param_2 + 0xac) = (uint)*(ushort *)(param_2 + 0xb0);
        *(undefined4 *)(param_2 + 0xa8) = 5;
        *(undefined4 *)(param_2 + 0xdc) = 3;
      }
    }
    else {
      uVar7 = param_2 + 0xa8U & 3;
      uVar9 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
      uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
      *(uint *)(param_2 + 0xa8) = uVar7 - 1;
      if ((int)uVar7 < 1) {
        *(undefined2 *)(param_2 + 0xb0) = 0;
        *(uint *)(param_2 + 0xac) = (uint)*(ushort *)(param_2 + 0xb0);
        *(undefined4 *)(param_2 + 0xa8) = 5;
        *(undefined4 *)(param_2 + 0xdc) = 3;
      }
    }
    break;
  case 3:
    *(short *)(param_2 + 0xb0) = *(short *)(param_2 + 0xb0) + (short)DAT_0209d378;
    uVar7 = param_2 + 0xacU & 3;
    uVar9 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    if (uVar7 < 0x8000) {
      *(uint *)(param_2 + 0xac) = uVar7 + DAT_0209d37c;
    }
    uVar7 = param_2 + 0xa8U & 3;
    uVar9 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    *(uint *)(param_2 + 0xa8) = uVar7 - 1;
    if ((int)uVar7 < 1) {
      uVar7 = param_2 + 0xa0U & 3;
      uVar9 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      if (uVar9 >> uVar7 * 8 == 0 && uVar9 << uVar7 * -8 + 0x20 == 0) {
        piVar5 = (int *)func_020d22d0();
        uVar7 = (uint)(piVar5 + 2) & 3;
        uVar9 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
        uVar12 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
        uVar11 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                 *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
        uVar7 = (uint)(piVar5 + 1) & 3;
        uVar8 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
        lVar1 = (ulonglong)uVar11 * (ulonglong)uVar12;
        uVar14 = (uint)lVar1;
        uVar9 = (uint)(piVar5 + 3) & 3;
        uVar13 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
        uVar3 = (uint)(piVar5 + 4) & 3;
        uVar15 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
        uVar16 = uVar15 >> uVar3 * 8 | uVar15 << uVar3 * -8 + 0x20;
        uVar3 = (uint)(piVar5 + 5) & 3;
        uVar15 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
        *piVar5 = uVar16 + uVar14;
        piVar5[1] = (uVar15 >> uVar3 * 8 | uVar15 << uVar3 * -8 + 0x20) +
                    (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) * uVar11 +
                    uVar12 * (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) +
                    (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar16,uVar14);
        uVar7 = (uint)(piVar5 + 1) & 3;
        uVar9 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
        *(ushort *)(param_2 + 0xa4) =
             (ushort)((uVar9 >> uVar7 * 8) >> 0x10) | (ushort)((uVar9 << uVar7 * -8 + 0x20) >> 0x10)
        ;
      }
      else {
        *(short *)(param_2 + 0xa4) = *(short *)(param_2 + 0xa4) + -0x8000;
      }
      uVar7 = param_2 + 4U & 3;
      uVar9 = *(uint *)(param_2 + 4U & 0xfffffffc);
      local_30 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
      uVar7 = param_2 + 8U & 3;
      uVar9 = *(uint *)(param_2 + 8U & 0xfffffffc);
      local_2c = (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) - 0x1e000;
      uVar7 = param_2 + 0xcU & 3;
      uVar9 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
      local_28 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
      local_24[0] = (int)*(short *)(DAT_0209d380 + ((int)(uint)*(ushort *)(param_2 + 0xa4) >> 4) * 4
                                   );
      local_24[1] = 0;
      local_24[2] = (int)*(short *)(DAT_0209d380 +
                                   (((int)(uint)*(ushort *)(param_2 + 0xa4) >> 4) * 2 + 1) * 2);
      func_0209d694(&local_30,local_24);
      uVar7 = param_2 + 0xa0U & 3;
      uVar9 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      *(uint *)(param_2 + 0xa0) = (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + 1;
      uVar7 = param_2 + 0xa0U & 3;
      uVar9 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      if ((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) < 2) {
        *(undefined4 *)(param_2 + 0xa8) = 0x1e;
      }
      else {
        *(undefined4 *)(param_2 + 0xa0) = 0;
        *(undefined4 *)(param_2 + 0xdc) = 4;
      }
    }
    break;
  case 4:
    *(short *)(param_2 + 0xb0) = *(short *)(param_2 + 0xb0) + (short)DAT_0209d378;
    uVar7 = param_2 + 0xacU & 3;
    uVar9 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    *(uint *)(param_2 + 0xac) = (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + iVar4;
    uVar7 = param_2 + 0xacU & 3;
    uVar9 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if (0x10000 < (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa8) = 0x1e;
      *(undefined4 *)(param_2 + 0xdc) = 0;
    }
  }
  uVar7 = param_2 + 0x78U & 3;
  uVar9 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
  if (DAT_0209d384 <= (int)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) & 0x3fffffe0)) {
    return;
  }
  uVar7 = param_2 + 0xdcU & 3;
  uVar9 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
  if ((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) == 3) {
    uVar7 = param_2 + 0xb4U & 3;
    uVar9 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    iVar6 = (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + DAT_0209d388;
    if (0x7fff < iVar6) {
      iVar6 = 0x8000;
    }
    *(int *)(param_2 + 0xb4) = iVar6;
  }
  else {
    uVar7 = param_2 + 0xb4U & 3;
    uVar9 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    iVar6 = (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + DAT_0209d38c;
    if (iVar6 < 0x1001) {
      iVar6 = 0x1000;
    }
    *(int *)(param_2 + 0xb4) = iVar6;
  }
  uVar9 = DAT_0209d390;
  uVar7 = param_2 + 0xb4U & 3;
  uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
  *(short *)(param_2 + 0xb2) =
       *(short *)(param_2 + 0xb2) +
       (short)((int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) >> 0xc);
  uVar7 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar7 = StructMapObject_GetAnimationBCAFrameCount(uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20)
  ;
  if (uVar7 <= *(ushort *)(param_2 + 0xb2)) {
    *(undefined2 *)(param_2 + 0xb2) = 0;
  }
  return;
}

