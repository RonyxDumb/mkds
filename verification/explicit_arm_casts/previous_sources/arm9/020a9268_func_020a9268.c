/* Decompiled C draft; module arm9; ROM address 020a9268. No matching claim. */
#include "types.h"
#include "deps/020a9268_func_020a9268.h"

void func_020a9268(undefined4 param_1,int param_2)

{
  longlong lVar1;
  bool bVar2;
  ushort *puVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  short sVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined4 *puVar19;
  uint uVar20;
  uint uVar21;
  uint uVar6;
  
  uVar6 = param_2 + 0xa8U & 3;
  uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (0 < (int)uVar6) {
    *(uint *)(param_2 + 0xa8) = uVar6 - 1;
  }
  uVar5 = uRam020a9a38;
  uVar6 = param_2 + 0x130U & 3;
  uVar7 = *(uint *)(param_2 + 0x130U & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if (uVar6 != 0) {
    if (uVar6 == 1) {
      uVar6 = param_2 + 0xa4U & 3;
      uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - 1;
      uVar6 = param_2 + 0xa4U & 3;
      uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      if ((int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < 1) {
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffd;
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfff7;
        *(undefined2 *)(param_2 + 0x66) = 0x1f;
        *(undefined4 *)(param_2 + 0x130) = 2;
        return;
      }
      return;
    }
    if (uVar6 != 2) {
      return;
    }
    uVar5 = func_0207a780();
    uVar6 = param_2 + 0x128U & 3;
    uVar7 = *(uint *)(param_2 + 0x128U & 0xfffffffc);
    if ((((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & uVar5) == 0) &&
       (uVar6 = param_2 + 0x78U & 3, uVar5 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
       ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 4) == 0)) {
      uVar6 = param_2 + 0x94U & 3;
      uVar7 = *(uint *)(param_2 + 0x94U & 0xfffffffc);
      uVar5 = param_2 + 0xb0U & 3;
      uVar11 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      func_0210b874(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,
                    uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20);
    }
    uVar6 = param_2 + 0xb0U & 3;
    uVar5 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    uVar18 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    *(uint *)(param_2 + 200) = uVar18;
    uVar6 = param_2 + 0xc4U & 3;
    uVar5 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
    uVar7 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar6 = param_2 + 0xd0U & 3;
    uVar11 = *(uint *)(param_2 + 0xd0U & 0xfffffffc);
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar6 = (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) * 0x54 +
            (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 0x34;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    lVar1 = (longlong)(int)uVar18 * (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20)
    ;
    *(uint *)(param_2 + 0xd4) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    iVar8 = func_020d8cc8(param_2 + 0xc4);
    if (iVar8 != 0) {
      uVar6 = param_2 + 0xdcU & 3;
      uVar7 = *(uint *)(param_2 + 0xdcU & 0xfffffffc);
      uVar5 = param_2 + 0xe0U & 3;
      uVar11 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
      puVar19 = (undefined4 *)(uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20);
      if (uVar7 >> uVar6 * 8 == 0 && uVar7 << uVar6 * -8 + 0x20 == 0) {
        if (*(short *)(puVar19 + 4) < 0) {
          uVar6 = param_2 + 0x9cU & 3;
          uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
          if (*(short *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x2c) == 0) {
            func_020d2398(param_2);
            return;
          }
          func_020d90a8(param_2 + 0xc4,0,1);
          puVar4 = puRam020a9a44;
          puVar3 = puRam020a9a40;
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *puRam020a9a3c;
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *puVar3;
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *puVar4;
          *(undefined4 *)(param_2 + 0x130) = 0;
          return;
        }
        func_020d90a8(param_2 + 0xc4,*(short *)(puVar19 + 4),1);
        uVar6 = param_2 + 0xe0U & 3;
        uVar5 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
        puVar19 = (undefined4 *)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
      }
      else if (-1 < *(short *)(puVar19 + 4)) {
        piVar9 = (int *)func_020d22d0();
        uVar6 = (uint)(piVar9 + 2) & 3;
        uVar5 = *(uint *)((uint)(piVar9 + 2) & 0xfffffffc);
        uVar16 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        uVar13 = *(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                 *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20;
        uVar6 = (uint)(piVar9 + 1) & 3;
        uVar11 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
        lVar1 = (ulonglong)uVar13 * (ulonglong)uVar16;
        uVar20 = (uint)lVar1;
        uVar5 = (uint)(piVar9 + 4) & 3;
        uVar7 = *(uint *)((uint)(piVar9 + 4) & 0xfffffffc);
        uVar21 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
        uVar5 = (uint)(piVar9 + 3) & 3;
        uVar18 = *(uint *)((uint)(piVar9 + 3) & 0xfffffffc);
        uVar7 = (uint)(piVar9 + 5) & 3;
        uVar17 = *(uint *)((uint)(piVar9 + 5) & 0xfffffffc);
        *piVar9 = uVar21 + uVar20;
        piVar9[1] = (uVar17 >> uVar7 * 8 | uVar17 << uVar7 * -8 + 0x20) +
                    (uVar18 >> uVar5 * 8 | uVar18 << uVar5 * -8 + 0x20) * uVar13 +
                    uVar16 * (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
                    (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar21,uVar20);
        uVar6 = (uint)(piVar9 + 1) & 3;
        uVar5 = *(uint *)((uint)(piVar9 + 1) & 0xfffffffc);
        if ((int)((ulonglong)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * 5 >> 0x20) != 0) {
          func_020d90a8(param_2 + 0xc4,*(undefined2 *)(puVar19 + 4),1);
          uVar6 = param_2 + 0xe0U & 3;
          uVar5 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
          puVar19 = (undefined4 *)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
        }
      }
      iVar8 = (int)(short)*(ushort *)((int)puVar19 + 0xe);
      if (*(ushort *)((int)puVar19 + 0xe) < 2) {
        uVar6 = param_2 + 0xb4U & 3;
        uVar5 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
        *(uint *)(param_2 + 0xb0) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        *(undefined4 *)(param_2 + 300) = 0;
      }
      else if (((iVar8 + -2) * 0x10000 >> 0x10 & 0xffffU) < 2) {
        uVar6 = param_2 + 0xb8U & 3;
        uVar5 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
        *(uint *)(param_2 + 0xb0) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        *(undefined4 *)(param_2 + 300) = 2;
      }
      else if (iVar8 == 10) {
        *(undefined4 *)(param_2 + 0xb0) = 0x8000;
        *(undefined4 *)(param_2 + 300) = 2;
        uVar6 = param_2 + 0x120U & 3;
        uVar5 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
        *(uint *)(param_2 + 0xbc) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        func_020d90a8(param_2 + 0xc4,*(byte *)(puVar19 + 3) + 1,1);
        func_020d8918(param_2 + 0xc4,param_2 + 0x11c,param_2 + 0x10);
        uVar6 = param_2 + 0x120U & 3;
        uVar5 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
        *(uint *)(param_2 + 0x120) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x1000;
        uVar6 = param_2 + 0xbcU & 3;
        uVar11 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        uVar5 = param_2 + 0x120U & 3;
        uVar7 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
        *(uint *)(param_2 + 0xbc) =
             (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) -
             (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
        *(undefined4 *)(param_2 + 0xc0) = 0xa000;
      }
      else if (iVar8 == 0xb) {
        *(undefined4 *)(param_2 + 0xb0) = 0x5000;
        *(undefined4 *)(param_2 + 300) = 2;
        uVar6 = param_2 + 0x120U & 3;
        uVar5 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
        *(uint *)(param_2 + 0xbc) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        func_020d90a8(param_2 + 0xc4,*(byte *)(puVar19 + 3) + 1,1);
        func_020d8918(param_2 + 0xc4,param_2 + 0x11c,param_2 + 0x10);
        uVar6 = param_2 + 0x120U & 3;
        uVar5 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
        *(uint *)(param_2 + 0x120) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x1000;
        uVar6 = param_2 + 0xbcU & 3;
        uVar11 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
        uVar5 = param_2 + 0x120U & 3;
        uVar7 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
        *(uint *)(param_2 + 0xbc) =
             (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) -
             (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
        *(undefined4 *)(param_2 + 0xc0) = 0xffffd000;
      }
      else if (99 < iVar8) {
        uVar12 = puVar19[1];
        uVar14 = puVar19[2];
        *(undefined4 *)(param_2 + 0x11c) = *puVar19;
        *(undefined4 *)(param_2 + 0x120) = uVar12;
        *(undefined4 *)(param_2 + 0x124) = uVar14;
        *(undefined4 *)(param_2 + 0x10) = 0;
        *(undefined4 *)(param_2 + 0x14) = 0;
        *(undefined4 *)(param_2 + 0x18) = 0;
        iVar8 = (int)*(short *)((int)puVar19 + 0xe);
        if (iVar8 < 200) {
          func_0209bfe0(iVar8 + -100);
          *(undefined4 *)(param_2 + 0xb0) = 0xf000;
          *(undefined4 *)(param_2 + 300) = 1;
        }
        else if (iVar8 < 300) {
          uVar6 = param_2 + 0xe4U & 3;
          uVar5 = *(uint *)(param_2 + 0xe4U & 0xfffffffc);
          if (iVar8 == *(short *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xe)) {
            func_0209753c();
          }
          else {
            *(undefined4 *)(param_2 + 0xb0) = 0x1e000;
          }
          *(undefined4 *)(param_2 + 300) = 1;
        }
      }
    }
    uVar6 = param_2 + 0xe0U & 3;
    uVar5 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
    if ((*(char *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xd) == '\0') ||
       (uVar6 = param_2 + 0xe4U & 3, uVar5 = *(uint *)(param_2 + 0xe4U & 0xfffffffc),
       *(char *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xd) == '\0')) {
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xffdf;
    }
    else {
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *puRam020a9a48;
    }
    uVar6 = param_2 + 0xbcU & 3;
    uVar5 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    if ((0 < (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) ||
       (uVar6 = param_2 + 0xc0U & 3, uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc),
       uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0)) {
      uVar6 = param_2 + 0xc0U & 3;
      uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      *(uint *)(param_2 + 0xc0) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - 0x1000;
      uVar6 = param_2 + 0xbcU & 3;
      uVar11 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      uVar5 = param_2 + 0xc0U & 3;
      uVar7 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      *(uint *)(param_2 + 0xbc) =
           (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
           (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
      uVar6 = param_2 + 0xbcU & 3;
      uVar5 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      if ((int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < 1) {
        uVar6 = param_2 + 0xc0U & 3;
        uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
        *(uint *)(param_2 + 0xc0) =
             (uint)((ulonglong)uVar6 * 0xfffff800) >> 0xc |
             (((int)uVar6 >> 0x1f) * -0x800 + ((int)((ulonglong)uVar6 * 0xfffff800 >> 0x20) - uVar6)
             ) * 0x100000;
        uVar6 = param_2 + 0xc0U & 3;
        uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
        if ((int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < 0x1000) {
          *(undefined4 *)(param_2 + 0xc0) = 0;
        }
        else {
          uVar5 = func_0207a780();
          uVar6 = param_2 + 0x128U & 3;
          uVar7 = *(uint *)(param_2 + 0x128U & 0xfffffffc);
          if ((((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & uVar5) == 0) &&
             (uVar6 = param_2 + 0x78U & 3, uVar5 = *(uint *)(param_2 + 0x78U & 0xfffffffc),
             ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 4) == 0)) {
            uVar6 = param_2 + 0x94U & 3;
            uVar7 = *(uint *)(param_2 + 0x94U & 0xfffffffc);
            uVar5 = param_2 + 0xc0U & 3;
            uVar11 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
            func_0210b8bc(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20,
                          uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20);
          }
        }
        uVar6 = param_2 + 0xc0U & 3;
        uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
        *(uint *)(param_2 + 0xbc) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      }
    }
    uVar6 = param_2 + 0xe0U & 3;
    uVar5 = *(uint *)(param_2 + 0xe0U & 0xfffffffc);
    iVar8 = (int)*(short *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xe);
    if (iVar8 < 100) {
      if (((iVar8 + -10) * 0x10000 >> 0x10 & 0xffffU) < 2) {
        func_020d8918(param_2 + 0xc4,param_2 + 0x11c,param_2 + 0x10);
        uVar6 = param_2 + 0x120U & 3;
        uVar5 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
        *(uint *)(param_2 + 0x120) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x1000;
      }
      else if ((iVar8 == 0) || (iVar8 == 2)) {
        func_020d8bf8(param_2 + 0xc4,param_2 + 0x11c,param_2 + 0x10);
        uVar6 = param_2 + 0x120U & 3;
        uVar5 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
        *(uint *)(param_2 + 0x120) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x1000;
      }
      else {
        func_020d8918(param_2 + 0xc4,param_2 + 0x11c,param_2 + 0x10);
        uVar6 = param_2 + 0x120U & 3;
        uVar5 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
        *(uint *)(param_2 + 0x120) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x1000;
      }
    }
    else {
      func_020d8918(param_2 + 0xc4,param_2 + 0x11c,param_2 + 0x10);
      iVar8 = iRam020a9a4c;
      uVar6 = param_2 + 0x120U & 3;
      uVar5 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
      *(uint *)(param_2 + 0x120) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x1000;
      uVar6 = param_2 + 0xb0U & 3;
      uVar5 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
      iVar8 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + iVar8;
      if (iVar8 < 0xa001) {
        iVar8 = 0xa000;
      }
      *(int *)(param_2 + 0xb0) = iVar8;
    }
    uVar6 = param_2 + 0x58U & 3;
    uVar5 = *(uint *)(param_2 + 0x58U & 0xfffffffc);
    sVar15 = (short)param_2 + 4;
    VecFx32_AddScale1(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20,param_2 + 0x34,param_2 + 0x11c
                     );
    uVar6 = param_2 + 8U & 3;
    uVar11 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar5 = param_2 + 0xbcU & 3;
    uVar7 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    *(uint *)(param_2 + 8) =
         (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
         (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    uVar6 = param_2 + 0xa0U & 3;
    uVar5 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((int)uVar6 < 0) {
      uVar12 = 0xffffffff;
      if (uVar6 == 0xffffffff) {
        uVar12 = uRam020a9a50;
      }
    }
    else {
      uVar12 = uRam020a9a54;
      if (uVar6 != 1) {
        uVar12 = 1;
      }
    }
    *(undefined4 *)(param_2 + 0xa0) = uVar12;
    uVar6 = param_2 + 300U & 3;
    uVar5 = *(uint *)(param_2 + 300U & 0xfffffffc);
    if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 2) {
      uVar6 = param_2 + 0x58U & 3;
      uVar5 = *(uint *)(param_2 + 0x58U & 0xfffffffc);
      sVar15 = 0x1c;
      func_020e516c(param_2 + 0xe8,param_2 + 0x11c,
                    (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) << 1);
      uVar6 = param_2 + 0x120U & 3;
      uVar5 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
      *(uint *)(param_2 + 0x120) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x1000;
      *(undefined4 *)(param_2 + 300) = 1;
    }
    uVar6 = param_2 + 300U & 3;
    uVar5 = *(uint *)(param_2 + 300U & 0xfffffffc);
    if (uVar5 >> uVar6 * 8 == 0 && uVar5 << uVar6 * -8 + 0x20 == 0) {
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *puRam020a9a3c;
      return;
    }
    uVar6 = param_2 + 0x78U & 3;
    uVar5 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
    if ((int)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x3fffffe0) < iRam020a9a58) {
      uVar6 = param_2 + 0xbcU & 3;
      uVar5 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      iVar8 = (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) >> 0xe;
      iVar10 = iVar8 + -7;
      if (iVar10 < 0) {
        sVar15 = 0x1c;
      }
      else {
        if (iVar10 < 0x1c) {
          sVar15 = 0x1c - (short)iVar10;
        }
        if (iVar8 + -0x23 < 0 == SBORROW4(iVar10,0x1c)) {
          sVar15 = 0;
        }
      }
      *(short *)(param_2 + 0x118) = sVar15;
      func_020e5634(param_2 + 0xe8,param_2 + 0x11c);
    }
    *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
    return;
  }
  if ((*(ushort *)(param_2 + 2) & 0x800) != 0) {
    uVar6 = param_2 + 0xa8U & 3;
    uVar5 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    *(uint *)(param_2 + 0xa8) = uVar6 - 1;
    if ((int)uVar6 < 1) {
      uVar6 = param_2 + 0x9cU & 3;
      uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
      *(uint *)(param_2 + 0xa8) =
           (uint)*(ushort *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x2c);
      uVar6 = param_2 + 0x9cU & 3;
      uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) =
           (uint)*(ushort *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x2e);
      func_020d90a8(param_2 + 0xc4,0,1);
      *(undefined4 *)(param_2 + 0x130) = 1;
      return;
    }
    return;
  }
  uVar6 = param_2 + 0xacU & 3;
  uVar11 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  uVar7 = 0;
  if (*(char *)((*(uint *)(uRam020a9a38 & 0xfffffffc) >> (uRam020a9a38 & 3) * 8 |
                *(uint *)(uRam020a9a38 & 0xfffffffc) << (uRam020a9a38 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      iVar8 = func_0203c8c0(uVar7 & 0xffff);
      if ((int)(uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) <= iVar8) {
        bVar2 = true;
        goto LAB_020a935c;
      }
      uVar18 = uVar5 & 3;
      uVar13 = *(uint *)(uVar5 & 0xfffffffc);
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 <
             (int)(uint)*(byte *)((uVar13 >> uVar18 * 8 | uVar13 << uVar18 * -8 + 0x20) + 0x3d0));
  }
  bVar2 = false;
LAB_020a935c:
  if (bVar2) {
    uVar6 = param_2 + 0xacU & 3;
    uVar5 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    *(uint *)(param_2 + 0xac) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 1;
    uVar6 = param_2 + 0x9cU & 3;
    uVar5 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    *(uint *)(param_2 + 0xa4) =
         (uint)*(ushort *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x2e);
    func_020d90a8(param_2 + 0xc4,0,1);
    *(undefined4 *)(param_2 + 0x130) = 1;
    return;
  }
  return;
}

