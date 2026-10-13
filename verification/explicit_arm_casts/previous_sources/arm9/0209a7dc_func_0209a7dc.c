/* Decompiled C draft; module arm9; ROM address 0209a7dc. No matching claim. */
#include "types.h"
#include "deps/0209a7dc_func_0209a7dc.h"

void func_0209a7dc(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint local_18;
  uint local_14;
  uint local_10;
  
  uVar7 = DAT_0209af4c;
  uVar8 = param_2 + 0x114U & 3;
  uVar2 = *(uint *)(param_2 + 0x114U & 0xfffffffc);
  switch(uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) {
  case 0:
    uVar8 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    *(uint *)(param_2 + 0xac) = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) + 0x200;
    iVar4 = StructMapObject_SomeFn_1
                      (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                       *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20);
    if (iVar4 == 0) {
      iVar4 = StructMapObject_SomeFn_1
                        (*(uint *)(DAT_0209af4c & 0xfffffffc) >> (DAT_0209af4c & 3) * 8 |
                         *(uint *)(DAT_0209af4c & 0xfffffffc) << (DAT_0209af4c & 3) * -8 + 0x20);
      uVar5 = FUN_02132440(iVar4 << 0xc);
      func_021329f8(uVar5,0x3f000000);
    }
    else {
      iVar4 = StructMapObject_SomeFn_1
                        (*(uint *)(DAT_0209af4c & 0xfffffffc) >> (DAT_0209af4c & 3) * 8 |
                         *(uint *)(DAT_0209af4c & 0xfffffffc) << (DAT_0209af4c & 3) * -8 + 0x20);
      uVar5 = FUN_02132440(iVar4 << 0xc);
      func_02131234(0x3f000000,uVar5);
    }
    iVar4 = func_021322c8();
    uVar8 = param_2 + 0xacU & 3;
    uVar7 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if (iVar4 <= (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xac) = 0;
    }
    uVar8 = param_2 + 0xa4U & 3;
    uVar7 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    *(uint *)(param_2 + 0xa4) = uVar8 - 1;
    if ((int)uVar8 < 1) {
      uVar8 = param_2 + 0xacU & 3;
      uVar7 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
      if (uVar7 >> uVar8 * 8 == 0 && uVar7 << uVar8 * -8 + 0x20 == 0) {
        *(undefined4 *)(param_2 + 0x114) = 1;
      }
      return;
    }
    return;
  case 1:
    *(undefined4 *)(param_2 + 0xf4) = 0x800;
    uVar8 = param_2 + 0xf0U & 3;
    uVar7 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
    uVar2 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    uVar8 = param_2 + 0xfcU & 3;
    uVar10 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
    uVar7 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar8 = (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) * 0x54 +
            (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + 0x34;
    uVar7 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    *(uint *)(param_2 + 0x100) =
         (uVar8 << 0xb) >> 0xc | (((int)uVar8 >> 0x1f) << 0xb | uVar8 >> 0x15) << 0x14;
    iVar4 = func_020d8cc8(param_2 + 0xf0);
    if (iVar4 != 0) {
      *(undefined2 *)(param_2 + 0xd0) = 0;
      uVar5 = DAT_0209af50;
      *(undefined4 *)(param_2 + 0xdc) = 0;
      *(undefined4 *)(param_2 + 0xe0) = uVar5;
      uVar5 = DAT_0209af54;
      *(undefined4 *)(param_2 + 0xe4) = 0;
      *(undefined4 *)(param_2 + 0xe8) = uVar5;
      *(undefined4 *)(param_2 + 0xec) = 0;
      piVar6 = (int *)func_020d22d0();
      uVar8 = (uint)(piVar6 + 2) & 3;
      uVar7 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
      uVar12 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      uVar11 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
               *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
      uVar8 = (uint)(piVar6 + 1) & 3;
      uVar10 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar11 * (ulonglong)uVar12;
      uVar14 = (uint)lVar1;
      uVar7 = (uint)(piVar6 + 4) & 3;
      uVar2 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
      uVar15 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
      uVar7 = (uint)(piVar6 + 3) & 3;
      uVar9 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
      uVar2 = (uint)(piVar6 + 5) & 3;
      uVar13 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
      *piVar6 = uVar15 + uVar14;
      piVar6[1] = (uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20) +
                  (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) * uVar11 +
                  uVar12 * (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar15,uVar14);
      uVar8 = (uint)(piVar6 + 1) & 3;
      uVar7 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
      *(int *)(param_2 + 0xa4) =
           (int)((ulonglong)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) * 0x3c >> 0x20) + 0x1e
      ;
      *(undefined4 *)(param_2 + 0x114) = 0;
    }
    uVar7 = DAT_0209af58;
    uVar8 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa8) = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) + 0x200;
    uVar8 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    iVar4 = StructMapObject_SomeFn_1(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20);
    if (iVar4 == 0) {
      iVar4 = StructMapObject_SomeFn_1
                        (*(uint *)(DAT_0209af58 & 0xfffffffc) >> (DAT_0209af58 & 3) * 8 |
                         *(uint *)(DAT_0209af58 & 0xfffffffc) << (DAT_0209af58 & 3) * -8 + 0x20);
      uVar5 = FUN_02132440(iVar4 << 0xc);
      func_021329f8(uVar5,0x3f000000);
    }
    else {
      iVar4 = StructMapObject_SomeFn_1
                        (*(uint *)(DAT_0209af58 & 0xfffffffc) >> (DAT_0209af58 & 3) * 8 |
                         *(uint *)(DAT_0209af58 & 0xfffffffc) << (DAT_0209af58 & 3) * -8 + 0x20);
      uVar5 = FUN_02132440(iVar4 << 0xc);
      func_02131234(0x3f000000,uVar5);
    }
    iVar4 = func_021322c8();
    uVar8 = param_2 + 0xa8U & 3;
    uVar7 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    if (iVar4 <= (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xa8) = 0;
    }
    uVar8 = param_2 + 0xe8U & 3;
    uVar7 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    *(ushort *)(param_2 + 0xd0) =
         *(short *)(param_2 + 0xd0) +
         ((ushort)(uVar7 >> uVar8 * 8) | (ushort)(uVar7 << uVar8 * -8 + 0x20));
    uVar5 = Maybe_get_15d4b4_6(*(undefined2 *)(param_2 + 0xd0));
    uVar8 = param_2 + 0xe0U & 3;
    uVar7 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
    iVar4 = func_0209af64(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20,uVar5);
    uVar8 = param_2 + 0xdcU & 3;
    uVar10 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
    uVar7 = param_2 + 0xd4U & 3;
    uVar2 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
    *(uint *)(param_2 + 0xd8) =
         ((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + iVar4) -
         (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
    uVar8 = param_2 + 0xd4U & 3;
    uVar10 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
    uVar7 = param_2 + 0xd8U & 3;
    uVar2 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
    *(uint *)(param_2 + 0xd4) =
         (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) +
         (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
    uVar8 = param_2 + 0xe0U & 3;
    uVar7 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if ((int)uVar8 < 1) {
      if ((int)uVar8 < 0) {
        uVar7 = param_2 + 0xe4U & 3;
        uVar2 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
        iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
        if (-1 < iVar4) {
          iVar4 = 0;
        }
        *(int *)(param_2 + 0xe0) = iVar4;
      }
    }
    else {
      uVar7 = param_2 + 0xe4U & 3;
      uVar2 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
      iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
      if (iVar4 < 1) {
        iVar4 = 0;
      }
      *(int *)(param_2 + 0xe0) = iVar4;
    }
    uVar8 = param_2 + 0xe8U & 3;
    uVar7 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if ((int)uVar8 < 1) {
      if ((int)uVar8 < 0) {
        uVar7 = param_2 + 0xecU & 3;
        uVar2 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
        iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
        if (-1 < iVar4) {
          iVar4 = 0;
        }
        *(int *)(param_2 + 0xe8) = iVar4;
      }
    }
    else {
      uVar7 = param_2 + 0xecU & 3;
      uVar2 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
      iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
      if (iVar4 < 1) {
        iVar4 = 0;
      }
      *(int *)(param_2 + 0xe8) = iVar4;
    }
    func_020d8a5c(param_2 + 0xf0,param_2 + 4);
    puVar3 = (uint *)func_020d88fc(param_2 + 0xf0);
    local_18 = *puVar3;
    local_14 = puVar3[1];
    local_10 = puVar3[2];
    VecFx32_Subtract(&local_18,param_2 + 0x34,&local_18);
    local_18 = (local_18 << 0xb) >> 0xc |
               (((int)local_18 >> 0x1f) << 0xb | local_18 >> 0x15) << 0x14;
    local_14 = (local_14 << 0xb) >> 0xc |
               (((int)local_14 >> 0x1f) << 0xb | local_14 >> 0x15) << 0x14;
    local_10 = (local_10 << 0xb) >> 0xc |
               (((int)local_10 >> 0x1f) << 0xb | local_10 >> 0x15) << 0x14;
    VecFx32_Add(param_2 + 0x34,&local_18,param_2 + 0x34);
    uVar8 = param_2 + 0x38U & 3;
    uVar7 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    uVar10 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    uVar8 = param_2 + 0x34U & 3;
    uVar7 = *(uint *)(param_2 + 0x34U & 0xfffffffc);
    uVar7 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    uVar8 = param_2 + 0x3cU & 3;
    uVar2 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    uVar8 = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
    lVar1 = (longlong)(int)uVar8 * (longlong)(int)uVar8 +
            (longlong)(int)uVar7 * (longlong)(int)uVar7 +
            (longlong)(int)uVar10 * (longlong)(int)uVar10;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize(param_2 + 0x34,param_2 + 0x34);
      return;
    }
    return;
  case 2:
    uVar8 = param_2 + 0xa4U & 3;
    uVar7 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    *(uint *)(param_2 + 0xa4) = uVar8 - 1;
    if ((int)uVar8 < 1) {
      func_020d90a8(param_2 + 0xf0,0,0);
      func_020d879c(param_2 + 0xf0,param_2 + 4);
      uVar5 = DAT_0209af5c;
      uVar8 = param_2 + 0x9cU & 3;
      uVar7 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
      uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 4;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      *(uint *)(param_2 + 8) = (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) - 0x5000;
      *(undefined2 *)(param_2 + 0xb0) = 0;
      *(undefined4 *)(param_2 + 0xbc) = 0;
      *(undefined4 *)(param_2 + 0xc0) = uVar5;
      uVar5 = DAT_0209af60;
      *(undefined4 *)(param_2 + 0xc4) = 0xffffff4a;
      *(undefined4 *)(param_2 + 200) = uVar5;
      *(undefined4 *)(param_2 + 0xcc) = 0;
      uVar8 = param_2 + 200U & 3;
      uVar7 = *(uint *)(param_2 + 200U & 0xfffffffc);
      *(ushort *)(param_2 + 0xb0) =
           *(short *)(param_2 + 0xb0) +
           ((ushort)(uVar7 >> uVar8 * 8) | (ushort)(uVar7 << uVar8 * -8 + 0x20));
      uVar5 = Maybe_get_15d4b4_6(*(undefined2 *)(param_2 + 0xb0));
      uVar8 = param_2 + 0xc0U & 3;
      uVar7 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      iVar4 = func_0209af64(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20,uVar5);
      uVar8 = param_2 + 0xbcU & 3;
      uVar10 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      uVar7 = param_2 + 0xb4U & 3;
      uVar2 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
      *(uint *)(param_2 + 0xb8) =
           ((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + iVar4) -
           (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
      uVar8 = param_2 + 0xb4U & 3;
      uVar10 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
      uVar7 = param_2 + 0xb8U & 3;
      uVar2 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
      *(uint *)(param_2 + 0xb4) =
           (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) +
           (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
      uVar8 = param_2 + 0xc0U & 3;
      uVar7 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      if ((int)uVar8 < 1) {
        if ((int)uVar8 < 0) {
          uVar7 = param_2 + 0xc4U & 3;
          uVar2 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
          iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
          if (-1 < iVar4) {
            iVar4 = 0;
          }
          *(int *)(param_2 + 0xc0) = iVar4;
        }
      }
      else {
        uVar7 = param_2 + 0xc4U & 3;
        uVar2 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
        iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
        if (iVar4 < 1) {
          iVar4 = 0;
        }
        *(int *)(param_2 + 0xc0) = iVar4;
      }
      uVar8 = param_2 + 200U & 3;
      uVar7 = *(uint *)(param_2 + 200U & 0xfffffffc);
      uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
      if ((int)uVar8 < 1) {
        if ((int)uVar8 < 0) {
          uVar7 = param_2 + 0xccU & 3;
          uVar2 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
          iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
          if (-1 < iVar4) {
            iVar4 = 0;
          }
          *(int *)(param_2 + 200) = iVar4;
        }
      }
      else {
        uVar7 = param_2 + 0xccU & 3;
        uVar2 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
        iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
        if (iVar4 < 1) {
          iVar4 = 0;
        }
        *(int *)(param_2 + 200) = iVar4;
      }
      uVar8 = param_2 + 0xb4U & 3;
      uVar7 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
      *(ushort *)(param_2 + 0xa2) =
           (ushort)(uVar7 >> uVar8 * 8) | (ushort)(uVar7 << uVar8 * -8 + 0x20);
      *(undefined4 *)(param_2 + 0x114) = 3;
      return;
    }
    uVar8 = param_2 + 0x14U & 3;
    uVar7 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
    *(uint *)(param_2 + 0x14) = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) - 0x400;
    VecFx32_Add(param_2 + 4,param_2 + 0x10,param_2 + 4);
    *(short *)(param_2 + 0xa2) = *(short *)(param_2 + 0xa2) + *(short *)(param_2 + 0xa0);
    return;
  case 3:
    uVar8 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    *(uint *)(param_2 + 0xac) = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) + 0x200;
    iVar4 = StructMapObject_SomeFn_1
                      (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                       *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20);
    if (iVar4 == 0) {
      iVar4 = StructMapObject_SomeFn_1
                        (*(uint *)(DAT_0209af4c & 0xfffffffc) >> (DAT_0209af4c & 3) * 8 |
                         *(uint *)(DAT_0209af4c & 0xfffffffc) << (DAT_0209af4c & 3) * -8 + 0x20);
      uVar5 = FUN_02132440(iVar4 << 0xc);
      func_021329f8(uVar5,0x3f000000);
    }
    else {
      iVar4 = StructMapObject_SomeFn_1
                        (*(uint *)(DAT_0209af4c & 0xfffffffc) >> (DAT_0209af4c & 3) * 8 |
                         *(uint *)(DAT_0209af4c & 0xfffffffc) << (DAT_0209af4c & 3) * -8 + 0x20);
      uVar5 = FUN_02132440(iVar4 << 0xc);
      func_02131234(0x3f000000,uVar5);
    }
    iVar4 = func_021322c8();
    uVar8 = param_2 + 0xacU & 3;
    uVar7 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if (iVar4 <= (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xac) = 0;
    }
    uVar8 = param_2 + 200U & 3;
    uVar7 = *(uint *)(param_2 + 200U & 0xfffffffc);
    *(ushort *)(param_2 + 0xb0) =
         *(short *)(param_2 + 0xb0) +
         ((ushort)(uVar7 >> uVar8 * 8) | (ushort)(uVar7 << uVar8 * -8 + 0x20));
    uVar5 = Maybe_get_15d4b4_6(*(undefined2 *)(param_2 + 0xb0));
    uVar8 = param_2 + 0xc0U & 3;
    uVar7 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    iVar4 = func_0209af64(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20,uVar5);
    uVar8 = param_2 + 0xbcU & 3;
    uVar10 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    uVar7 = param_2 + 0xb4U & 3;
    uVar2 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    *(uint *)(param_2 + 0xb8) =
         ((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + iVar4) -
         (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
    uVar8 = param_2 + 0xb4U & 3;
    uVar10 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    uVar7 = param_2 + 0xb8U & 3;
    uVar2 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    *(uint *)(param_2 + 0xb4) =
         (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) +
         (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
    uVar8 = param_2 + 0xc0U & 3;
    uVar7 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if ((int)uVar8 < 1) {
      if ((int)uVar8 < 0) {
        uVar7 = param_2 + 0xc4U & 3;
        uVar2 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
        iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
        if (-1 < iVar4) {
          iVar4 = 0;
        }
        *(int *)(param_2 + 0xc0) = iVar4;
      }
    }
    else {
      uVar7 = param_2 + 0xc4U & 3;
      uVar2 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
      if (iVar4 < 1) {
        iVar4 = 0;
      }
      *(int *)(param_2 + 0xc0) = iVar4;
    }
    uVar8 = param_2 + 200U & 3;
    uVar7 = *(uint *)(param_2 + 200U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if ((int)uVar8 < 1) {
      if ((int)uVar8 < 0) {
        uVar7 = param_2 + 0xccU & 3;
        uVar2 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
        iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
        if (-1 < iVar4) {
          iVar4 = 0;
        }
        *(int *)(param_2 + 200) = iVar4;
      }
    }
    else {
      uVar7 = param_2 + 0xccU & 3;
      uVar2 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
      iVar4 = uVar8 + (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
      if (iVar4 < 1) {
        iVar4 = 0;
      }
      *(int *)(param_2 + 200) = iVar4;
    }
    uVar8 = param_2 + 0xb4U & 3;
    uVar7 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    *(ushort *)(param_2 + 0xa2) =
         (ushort)(uVar7 >> uVar8 * 8) | (ushort)(uVar7 << uVar8 * -8 + 0x20);
    uVar8 = param_2 + 8U & 3;
    uVar7 = *(uint *)(param_2 + 8U & 0xfffffffc);
    *(uint *)(param_2 + 8) = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 0x200;
    uVar8 = param_2 + 0x9cU & 3;
    uVar2 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    uVar7 = param_2 + 8U & 3;
    uVar10 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar8 = (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) + 4;
    uVar2 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20;
    if ((int)(uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) < (int)uVar8) {
      return;
    }
    *(uint *)(param_2 + 8) = uVar8;
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined2 *)(param_2 + 0xa2) = 0;
    *(undefined2 *)(param_2 + 0xd0) = 0;
    uVar5 = DAT_0209af50;
    *(undefined4 *)(param_2 + 0xdc) = 0;
    *(undefined4 *)(param_2 + 0xe0) = uVar5;
    uVar5 = DAT_0209af54;
    *(undefined4 *)(param_2 + 0xe4) = 0;
    *(undefined4 *)(param_2 + 0xe8) = uVar5;
    *(undefined4 *)(param_2 + 0xec) = 0;
    piVar6 = (int *)func_020d22d0();
    uVar8 = (uint)(piVar6 + 2) & 3;
    uVar7 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
    uVar12 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    uVar11 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
             *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
    uVar8 = (uint)(piVar6 + 1) & 3;
    uVar10 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar11 * (ulonglong)uVar12;
    uVar15 = (uint)lVar1;
    uVar7 = (uint)(piVar6 + 4) & 3;
    uVar2 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
    uVar14 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
    uVar7 = (uint)(piVar6 + 3) & 3;
    uVar9 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
    uVar2 = (uint)(piVar6 + 5) & 3;
    uVar13 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
    *piVar6 = uVar14 + uVar15;
    piVar6[1] = (uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20) +
                (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) * uVar11 +
                uVar12 * (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar14,uVar15);
    uVar8 = (uint)(piVar6 + 1) & 3;
    uVar7 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
    *(int *)(param_2 + 0xa4) =
         (int)((ulonglong)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) * 0x3c >> 0x20) + 0x1e;
    *(undefined4 *)(param_2 + 0x114) = 0;
    *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
  }
  return;
}

