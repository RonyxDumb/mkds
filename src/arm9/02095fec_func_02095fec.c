/* Decompiled C draft; module arm9; ROM address 02095fec. No matching claim. */
#include "types.h"
#include "deps/02095fec_func_02095fec.h"

void func_02095fec(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  uint uVar3;
  
  *(undefined4 *)(param_2 + 0x14) = 0;
  uVar3 = param_2 + 0x104U & 3;
  uVar2 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    if (uVar3 == 1) {
      uVar3 = param_2 + 0xb8U & 3;
      uVar9 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
      uVar2 = param_2 + 0xc0U & 3;
      uVar4 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      *(uint *)(param_2 + 0xb8) =
           (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
           (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
      uVar3 = param_2 + 0xc0U & 3;
      uVar2 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      *(uint *)(param_2 + 0xc0) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0x800;
      iVar6 = DAT_020968a8;
      uVar3 = param_2 + 0xb4U & 3;
      uVar2 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if ((int)uVar3 < 0x2000) {
        *(undefined4 *)(param_2 + 0xb4) = 0x2000;
        uVar5 = 2;
        *(undefined4 *)(param_2 + 0x104) = 2;
        uVar3 = param_2 + 0x78U & 3;
        uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
        if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) == 0) {
          uVar3 = param_2 + 0x70U & 3;
          uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
          uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
          uVar3 = DAT_020968ac + 0x68U & 3;
          uVar2 = *(uint *)(DAT_020968ac + 0x68U & 0xfffffffc);
          if (uVar4 != (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
            uVar3 = DAT_020968ac + 0x8cU & 3;
            uVar2 = *(uint *)(DAT_020968ac + 0x8cU & 0xfffffffc);
            if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
              uVar5 = 3;
            }
            else {
              uVar5 = 4;
            }
          }
          local_5c = param_2 + 4;
          local_60 = 0x16c;
          local_58 = uVar5;
          local_54 = func_020d4ef4();
          func_0210b7a8((uint)(uintptr_t)(&local_60));
        }
      }
      else {
        uVar2 = param_2 + 0xbcU & 3;
        uVar4 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        *(uint *)(param_2 + 0xb4) = uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
        uVar3 = param_2 + 0xbcU & 3;
        uVar2 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        *(uint *)(param_2 + 0xbc) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - iVar6;
      }
    }
    else if (uVar3 == 2) {
      uVar3 = param_2 + 0xb8U & 3;
      uVar2 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if (0x1fff < (int)uVar3) {
        uVar2 = param_2 + 0xc0U & 3;
        uVar4 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
        *(uint *)(param_2 + 0xb8) = uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
        uVar3 = param_2 + 0xc0U & 3;
        uVar2 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
        *(uint *)(param_2 + 0xc0) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0x800;
      }
      uVar3 = param_2 + 0xdcU & 3;
      uVar2 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
      *(ushort *)(param_2 + 0xc4) =
           *(short *)(param_2 + 0xc4) +
           ((ushort)(uVar2 >> uVar3 * 8) | (ushort)(uVar2 << uVar3 * -8 + 0x20));
      uVar5 = Maybe_get_15d4b4_5(*(undefined2 *)(param_2 + 0xc4));
      uVar3 = param_2 + 0xd4U & 3;
      uVar2 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
      iVar6 = Maybe_calc_0968c0(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,uVar5);
      uVar3 = param_2 + 0xd0U & 3;
      uVar9 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
      uVar2 = param_2 + 200U & 3;
      uVar4 = *(uint *)(param_2 + 200U & 0xfffffffc);
      *(uint *)(param_2 + 0xcc) =
           ((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + iVar6) -
           (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
      uVar3 = param_2 + 200U & 3;
      uVar9 = *(uint *)(param_2 + 200U & 0xfffffffc);
      uVar2 = param_2 + 0xccU & 3;
      uVar4 = *(uint *)(param_2 + 0xccU & 0xfffffffc);
      *(uint *)(param_2 + 200) =
           (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
           (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
      uVar3 = param_2 + 0xd4U & 3;
      uVar2 = *(uint *)(param_2 + 0xd4U & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if ((int)uVar3 < 1) {
        if ((int)uVar3 < 0) {
          uVar2 = param_2 + 0xd8U & 3;
          uVar4 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
          iVar6 = uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
          if (-1 < iVar6) {
            iVar6 = 0;
          }
          *(int *)(param_2 + 0xd4) = iVar6;
        }
      }
      else {
        uVar2 = param_2 + 0xd8U & 3;
        uVar4 = *(uint *)(param_2 + 0xd8U & 0xfffffffc);
        iVar6 = uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
        if (iVar6 < 1) {
          iVar6 = 0;
        }
        *(int *)(param_2 + 0xd4) = iVar6;
      }
      uVar3 = param_2 + 0xdcU & 3;
      uVar2 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if ((int)uVar3 < 1) {
        if ((int)uVar3 < 0) {
          uVar2 = param_2 + 0xe0U & 3;
          uVar4 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
          iVar6 = uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
          if (-1 < iVar6) {
            iVar6 = 0;
          }
          *(int *)(param_2 + 0xdc) = iVar6;
        }
      }
      else {
        uVar2 = param_2 + 0xe0U & 3;
        uVar4 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
        iVar6 = uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
        if (iVar6 < 1) {
          iVar6 = 0;
        }
        *(int *)(param_2 + 0xdc) = iVar6;
      }
      uVar3 = param_2 + 0xfcU & 3;
      uVar2 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
      *(ushort *)(param_2 + 0xe4) =
           *(short *)(param_2 + 0xe4) +
           ((ushort)(uVar2 >> uVar3 * 8) | (ushort)(uVar2 << uVar3 * -8 + 0x20));
      uVar5 = Maybe_get_15d4b4_5(*(undefined2 *)(param_2 + 0xe4));
      uVar3 = param_2 + 0xf4U & 3;
      uVar2 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
      iVar6 = Maybe_calc_0968c0(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,uVar5);
      uVar3 = param_2 + 0xf0U & 3;
      uVar9 = *(uint *)(param_2 + 0xf0U & 0xfffffffc);
      uVar2 = param_2 + 0xe8U & 3;
      uVar4 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
      *(uint *)(param_2 + 0xec) =
           ((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) + iVar6) -
           (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
      uVar3 = param_2 + 0xe8U & 3;
      uVar9 = *(uint *)(param_2 + 0xe8U & 0xfffffffc);
      uVar2 = param_2 + 0xecU & 3;
      uVar4 = *(uint *)(param_2 + 0xecU & 0xfffffffc);
      *(uint *)(param_2 + 0xe8) =
           (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
           (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
      uVar3 = param_2 + 0xf4U & 3;
      uVar2 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if ((int)uVar3 < 1) {
        if ((int)uVar3 < 0) {
          uVar2 = param_2 + 0xf8U & 3;
          uVar4 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
          iVar6 = uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
          if (-1 < iVar6) {
            iVar6 = 0;
          }
          *(int *)(param_2 + 0xf4) = iVar6;
        }
      }
      else {
        uVar2 = param_2 + 0xf8U & 3;
        uVar4 = *(uint *)(param_2 + 0xf8U & 0xfffffffc);
        iVar6 = uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
        if (iVar6 < 1) {
          iVar6 = 0;
        }
        *(int *)(param_2 + 0xf4) = iVar6;
      }
      uVar3 = param_2 + 0xfcU & 3;
      uVar2 = *(uint *)(param_2 + 0xfcU & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if ((int)uVar3 < 1) {
        if ((int)uVar3 < 0) {
          uVar2 = param_2 + 0x100U & 3;
          uVar4 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
          iVar6 = uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
          if (-1 < iVar6) {
            iVar6 = 0;
          }
          *(int *)(param_2 + 0xfc) = iVar6;
        }
      }
      else {
        uVar2 = param_2 + 0x100U & 3;
        uVar4 = *(uint *)(param_2 + 0x100U & 0xfffffffc);
        iVar6 = uVar3 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
        if (iVar6 < 1) {
          iVar6 = 0;
        }
        *(int *)(param_2 + 0xfc) = iVar6;
      }
      uVar3 = param_2 + 0xf4U & 3;
      uVar2 = *(uint *)(param_2 + 0xf4U & 0xfffffffc);
      if (((uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) &&
          (uVar3 = param_2 + 0xb0U & 3, uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc),
          uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20, uVar3 != 2)) && (uVar3 != 5)) {
        *(undefined4 *)(param_2 + 0x104) = 0;
      }
    }
  }
  uVar3 = param_2 + 0xb0U & 3;
  uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 6 < 2) &&
     (uVar3 = param_2 + 0x104U & 3, uVar2 = *(uint *)(param_2 + 0x104U & 0xfffffffc),
     uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0)) {
    uVar3 = (*(uint *)(DAT_020968b0 & 0xfffffffc) >> (DAT_020968b0 & 3) * 8 |
            *(uint *)(DAT_020968b0 & 0xfffffffc) << (DAT_020968b0 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 4) {
      *(undefined4 *)(param_2 + 0xb0) = 3;
      *(undefined4 *)(param_2 + 0xa0) = 0x2000;
      *(undefined4 *)(param_2 + 0xa4) = 0xffff3000;
    }
    else {
      *(undefined4 *)(param_2 + 0xb0) = 0;
      *(undefined4 *)(param_2 + 0xa0) = 0x2000;
      *(undefined4 *)(param_2 + 0xa4) = 0xffff3000;
    }
  }
  iVar6 = DAT_020968b8;
  uVar3 = param_2 + 0xb0U & 3;
  uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  switch(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) {
  case 0:
    uVar3 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    puVar14 = &local_60;
    if (0 < (int)uVar3) {
      puVar14 = (undefined4 *)&stack0xfffffff4;
    }
    *(uint *)(param_2 + 0xac) = uVar3 - 1;
    if (0 < (int)uVar3) {
      return;
    }
    piVar7 = (int *)func_020d22d0();
    uVar3 = (uint)(piVar7 + 2) & 3;
    uVar2 = *(uint *)((uint)(piVar7 + 2) & 0xfffffffc);
    uVar11 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar10 = *(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
             *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20;
    uVar3 = (uint)(piVar7 + 1) & 3;
    uVar9 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar10 * (ulonglong)uVar11;
    uVar13 = (uint)lVar1;
    uVar2 = (uint)(piVar7 + 3) & 3;
    uVar8 = *(uint *)((uint)(piVar7 + 3) & 0xfffffffc);
    uVar4 = (uint)(piVar7 + 4) & 3;
    uVar12 = *(uint *)((uint)(piVar7 + 4) & 0xfffffffc);
    uVar15 = uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20;
    uVar4 = (uint)(piVar7 + 5) & 3;
    uVar12 = *(uint *)((uint)(piVar7 + 5) & 0xfffffffc);
    *piVar7 = uVar15 + uVar13;
    piVar7[1] = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) +
                (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) * uVar10 +
                uVar11 * (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar15,uVar13);
    uVar3 = (uint)(piVar7 + 1) & 3;
    uVar2 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
    *(int *)(param_2 + 0xac) =
         (int)((ulonglong)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0x1e >> 0x20) + 0x1e;
    *(undefined4 *)(param_2 + 0xb0) = 1;
    *(undefined4 *)(param_2 + 0x104) = 0;
    *(undefined1 *)(param_2 + 0x108) = 0;
    uVar3 = param_2 + 0x78U & 3;
    uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) != 0) {
      return;
    }
    uVar3 = param_2 + 0x70U & 3;
    uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = DAT_020968ac + 0x68U & 3;
    uVar2 = *(uint *)(DAT_020968ac + 0x68U & 0xfffffffc);
    if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      uVar5 = 2;
    }
    else {
      uVar3 = DAT_020968ac + 0x8cU & 3;
      uVar2 = *(uint *)(DAT_020968ac + 0x8cU & 0xfffffffc);
      if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
        uVar5 = 3;
      }
      else {
        uVar5 = 4;
      }
    }
    *(undefined4 *)((int)puVar14 + 0x10) = DAT_020968b4;
    *(int *)((int)puVar14 + 0x14) = param_2 + 4;
    *(undefined4 *)((int)puVar14 + 0x18) = uVar5;
    uVar5 = func_020d4ef4();
    *(undefined4 *)((int)puVar14 + 0x1c) = uVar5;
    func_0210b7a8((uint)(uintptr_t)((undefined1 *)((int)puVar14 + 0x10)));
    return;
  case 1:
    break;
  case 2:
    uVar3 = param_2 + 0xa0U & 3;
    uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (0x2000 < (int)uVar3) {
      *(uint *)(param_2 + 0xa0) = uVar3 - 0x400;
      uVar3 = param_2 + 0xa0U & 3;
      uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0xf000;
      return;
    }
    *(undefined4 *)(param_2 + 0xa0) = 0x2000;
    *(undefined4 *)(param_2 + 0xa4) = 0xffff3000;
    piVar7 = (int *)func_020d22d0();
    uVar3 = (uint)(piVar7 + 2) & 3;
    uVar2 = *(uint *)((uint)(piVar7 + 2) & 0xfffffffc);
    uVar11 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar10 = *(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
             *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20;
    uVar3 = (uint)(piVar7 + 1) & 3;
    uVar9 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar10 * (ulonglong)uVar11;
    uVar13 = (uint)lVar1;
    uVar2 = (uint)(piVar7 + 3) & 3;
    uVar8 = *(uint *)((uint)(piVar7 + 3) & 0xfffffffc);
    uVar4 = (uint)(piVar7 + 4) & 3;
    uVar12 = *(uint *)((uint)(piVar7 + 4) & 0xfffffffc);
    uVar15 = uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20;
    uVar4 = (uint)(piVar7 + 5) & 3;
    uVar12 = *(uint *)((uint)(piVar7 + 5) & 0xfffffffc);
    *piVar7 = uVar15 + uVar13;
    piVar7[1] = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) +
                (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) * uVar10 +
                uVar11 * (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar15,uVar13);
    uVar3 = (uint)(piVar7 + 1) & 3;
    uVar2 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
    *(int *)(param_2 + 0xac) =
         (int)((ulonglong)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0xf >> 0x20) + 0xf;
    uStack_38 = 3;
    *(undefined4 *)(param_2 + 0xb0) = 3;
    *(undefined1 *)(param_2 + 0x108) = 0;
    uVar3 = param_2 + 0x78U & 3;
    uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) != 0) {
      return;
    }
    uVar3 = param_2 + 0x70U & 3;
    uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = DAT_020968ac + 0x68U & 3;
    uVar2 = *(uint *)(DAT_020968ac + 0x68U & 0xfffffffc);
    if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      uStack_38 = 2;
    }
    else {
      uVar3 = DAT_020968ac + 0x8cU & 3;
      uVar2 = *(uint *)(DAT_020968ac + 0x8cU & 0xfffffffc);
      if (uVar4 != (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
        uStack_38 = 4;
      }
    }
    iStack_3c = param_2 + 4;
    uStack_40 = 0x1d4;
    uStack_34 = func_020d4ef4();
    func_0210b7a8((uint)(uintptr_t)(&uStack_40));
    return;
  case 3:
    uVar3 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    puVar14 = &local_60;
    if (0 < (int)uVar3) {
      puVar14 = (undefined4 *)&stack0xfffffff4;
    }
    *(uint *)(param_2 + 0xac) = uVar3 - 1;
    if (0 < (int)uVar3) {
      return;
    }
    *(undefined4 *)(param_2 + 0xa0) = 0x2000;
    *(undefined4 *)(param_2 + 0xa4) = 0xffff3000;
    piVar7 = (int *)func_020d22d0();
    uVar3 = (uint)(piVar7 + 2) & 3;
    uVar2 = *(uint *)((uint)(piVar7 + 2) & 0xfffffffc);
    uVar11 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar10 = *(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
             *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20;
    uVar3 = (uint)(piVar7 + 1) & 3;
    uVar9 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar10 * (ulonglong)uVar11;
    uVar13 = (uint)lVar1;
    uVar2 = (uint)(piVar7 + 3) & 3;
    uVar8 = *(uint *)((uint)(piVar7 + 3) & 0xfffffffc);
    uVar4 = (uint)(piVar7 + 4) & 3;
    uVar12 = *(uint *)((uint)(piVar7 + 4) & 0xfffffffc);
    uVar15 = uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20;
    uVar4 = (uint)(piVar7 + 5) & 3;
    uVar12 = *(uint *)((uint)(piVar7 + 5) & 0xfffffffc);
    *piVar7 = uVar15 + uVar13;
    piVar7[1] = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) +
                (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) * uVar10 +
                uVar11 * (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar15,uVar13);
    uVar3 = (uint)(piVar7 + 1) & 3;
    uVar2 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
    *(int *)(param_2 + 0xac) =
         (int)((ulonglong)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0x5a >> 0x20) + 0x5a;
    uVar5 = 4;
    *(undefined4 *)(param_2 + 0xb0) = 4;
    *(undefined4 *)(param_2 + 0x104) = 0;
    *(undefined1 *)(param_2 + 0x108) = 0;
    uVar3 = param_2 + 0x78U & 3;
    uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) != 0) {
      return;
    }
    uVar3 = param_2 + 0x70U & 3;
    uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = DAT_020968ac + 0x68U & 3;
    uVar2 = *(uint *)(DAT_020968ac + 0x68U & 0xfffffffc);
    if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      uVar5 = 2;
    }
    else {
      uVar3 = DAT_020968ac + 0x8cU & 3;
      uVar2 = *(uint *)(DAT_020968ac + 0x8cU & 0xfffffffc);
      if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
        uVar5 = 3;
      }
    }
    *(undefined4 *)((int)puVar14 + 0x30) = DAT_020968b4;
    *(int *)((int)puVar14 + 0x34) = param_2 + 4;
    *(undefined4 *)((int)puVar14 + 0x38) = uVar5;
    uVar5 = func_020d4ef4();
    *(undefined4 *)((int)puVar14 + 0x3c) = uVar5;
    func_0210b7a8((uint)(uintptr_t)((undefined1 *)((int)puVar14 + 0x30)));
    return;
  case 4:
    uVar3 = param_2 + 0xa0U & 3;
    uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if ((int)uVar3 < DAT_020968b8) {
      *(uint *)(param_2 + 0xa0) = uVar3 + 0xc00;
      uVar3 = param_2 + 0xa0U & 3;
      uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0xf000;
      return;
    }
    uVar3 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    *(uint *)(param_2 + 0xac) = uVar3 - 1;
    uVar5 = DAT_020968bc;
    if (0 < (int)uVar3) {
      *(int *)(param_2 + 0xa0) = iVar6;
      *(undefined4 *)(param_2 + 0xa4) = uVar5;
      return;
    }
    *(int *)(param_2 + 0xa0) = iVar6;
    *(undefined4 *)(param_2 + 0xa4) = uVar5;
    *(undefined4 *)(param_2 + 0xb0) = 5;
    return;
  case 5:
    uVar3 = param_2 + 0xa0U & 3;
    uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (0x2000 < (int)uVar3) {
      *(uint *)(param_2 + 0xa0) = uVar3 - 0xc00;
      uVar3 = param_2 + 0xa0U & 3;
      uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0xf000;
      return;
    }
    piVar7 = (int *)func_020d22d0();
    uVar3 = (uint)(piVar7 + 2) & 3;
    uVar2 = *(uint *)((uint)(piVar7 + 2) & 0xfffffffc);
    uVar11 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar10 = *(uint *)((uint)piVar7 & 0xfffffffc) >> ((uint)piVar7 & 3) * 8 |
             *(uint *)((uint)piVar7 & 0xfffffffc) << ((uint)piVar7 & 3) * -8 + 0x20;
    uVar3 = (uint)(piVar7 + 1) & 3;
    uVar9 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar10 * (ulonglong)uVar11;
    uVar15 = (uint)lVar1;
    uVar2 = (uint)(piVar7 + 4) & 3;
    uVar4 = *(uint *)((uint)(piVar7 + 4) & 0xfffffffc);
    uVar13 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    uVar2 = (uint)(piVar7 + 3) & 3;
    uVar8 = *(uint *)((uint)(piVar7 + 3) & 0xfffffffc);
    uVar4 = (uint)(piVar7 + 5) & 3;
    uVar12 = *(uint *)((uint)(piVar7 + 5) & 0xfffffffc);
    *piVar7 = uVar13 + uVar15;
    piVar7[1] = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) +
                (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) * uVar10 +
                uVar11 * (uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar13,uVar15);
    uVar4 = DAT_020968b0;
    uVar3 = param_2 + 0x9cU & 3;
    uVar8 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    uVar2 = (uint)(piVar7 + 1) & 3;
    uVar9 = *(uint *)((uint)(piVar7 + 1) & 0xfffffffc);
    *(uint *)(param_2 + 0xac) =
         ((int)*(short *)((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + 0x28) +
         (int)((ulonglong)(uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20) * 0x3c >> 0x20)) - 0x1eU
         & 0xffff;
    uVar3 = uVar4 & 3;
    uVar2 = *(uint *)(uVar4 & 0xfffffffc);
    uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 8;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 4) {
      *(undefined4 *)(param_2 + 0xb0) = 3;
      *(undefined4 *)(param_2 + 0xa0) = 0x2000;
      *(undefined4 *)(param_2 + 0xa4) = 0xffff3000;
    }
    else {
      *(undefined4 *)(param_2 + 0xb0) = 0;
      *(undefined4 *)(param_2 + 0xa0) = 0x2000;
      *(undefined4 *)(param_2 + 0xa4) = 0xffff3000;
    }
    *(undefined1 *)(param_2 + 0x108) = 0;
    uVar3 = param_2 + 0x78U & 3;
    uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) != 0) {
      return;
    }
    uVar3 = param_2 + 0x70U & 3;
    uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = DAT_020968ac + 0x68U & 3;
    uVar2 = *(uint *)(DAT_020968ac + 0x68U & 0xfffffffc);
    if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      uStack_18 = 2;
    }
    else {
      uVar3 = DAT_020968ac + 0x8cU & 3;
      uVar2 = *(uint *)(DAT_020968ac + 0x8cU & 0xfffffffc);
      if (uVar4 == (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
        uStack_18 = 3;
      }
      else {
        uStack_18 = 4;
      }
    }
    iStack_1c = param_2 + 4;
    uStack_20 = 0x1d4;
    uStack_14 = func_020d4ef4();
    func_0210b7a8((uint)(uintptr_t)(&uStack_20));
  default:
    return;
  }
  uVar3 = param_2 + 0xa0U & 3;
  uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 0x7800) {
    *(uint *)(param_2 + 0xa0) = uVar3 + 0x400;
    uVar3 = param_2 + 0xa0U & 3;
    uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    *(uint *)(param_2 + 0xa4) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0xf000;
    return;
  }
  uVar3 = param_2 + 0xacU & 3;
  uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  *(uint *)(param_2 + 0xac) = uVar3 - 1;
  if (0 < (int)uVar3) {
    *(undefined4 *)(param_2 + 0xa0) = 0x7800;
    *(undefined4 *)(param_2 + 0xa4) = 0xffff8800;
    return;
  }
  *(undefined4 *)(param_2 + 0xa0) = 0x7800;
  *(undefined4 *)(param_2 + 0xa4) = 0xffff8800;
  *(undefined4 *)(param_2 + 0xb0) = 2;
  return;
}

