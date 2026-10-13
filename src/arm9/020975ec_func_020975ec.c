/* Decompiled C draft; module arm9; ROM address 020975ec. No matching claim. */
#include "types.h"
#include "deps/020975ec_func_020975ec.h"

void func_020975ec(undefined4 param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar3;
  
  uVar3 = param_2 + 0xebcU & 3;
  uVar2 = *(uint *)(param_2 + 0xebcU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  iVar7 = param_2;
  if (0 < (int)uVar3) {
    iVar7 = 1;
  }
  uVar2 = param_2 + 0xebcU & 3;
  uVar4 = *(uint *)(param_2 + 0xebcU & 0xfffffffc);
  if ((int)uVar3 < 1) {
    iVar7 = 0;
  }
  *(uint *)(param_2 + 0xebc) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) - iVar7;
  uVar3 = param_2 + 0xeccU & 3;
  uVar2 = *(uint *)(param_2 + 0xeccU & 0xfffffffc);
  switch(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) {
  case 0:
    uVar5 = func_0208b7bc(0x5f,param_2 + 4);
    *(undefined4 *)(param_2 + 0xed0) = uVar5;
    *(undefined4 *)(param_2 + 0xecc) = 1;
    break;
  case 1:
    uVar3 = param_2 + 0xebcU & 3;
    uVar2 = *(uint *)(param_2 + 0xebcU & 0xfffffffc);
    if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
      uVar3 = param_2 + 0xeb8U & 3;
      uVar2 = *(uint *)(param_2 + 0xeb8U & 0xfffffffc);
      *(uint *)(param_2 + 0xeb8) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 1;
      uVar3 = param_2 + 0xeb8U & 3;
      uVar2 = *(uint *)(param_2 + 0xeb8U & 0xfffffffc);
      if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 1) {
        *(undefined4 *)(param_2 + 0xec0) = 0;
        *(undefined4 *)(param_2 + 0xecc) = 2;
      }
    }
    else {
      *(undefined4 *)(param_2 + 0xecc) = 4;
    }
    *(undefined4 *)(param_2 + 0xec8) = 0;
    break;
  case 2:
    *(short *)(param_2 + 0x7e) = *(short *)(param_2 + 0x7e) + -0x16c;
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    *(uint *)(param_2 + 0xec0) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1;
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    if (0x1c < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xec0) = 0x1d;
      *(undefined4 *)(param_2 + 0xecc) = 3;
    }
    *(undefined4 *)(param_2 + 0xec8) = 1;
    break;
  case 3:
    *(short *)(param_2 + 0x7e) = *(short *)(param_2 + 0x7e) + 0x16c;
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 0xf) {
      *(undefined4 *)(param_2 + 0xec8) = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0xec8) = 1;
    }
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    *(uint *)(param_2 + 0xec0) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 1;
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 1) {
      *(undefined4 *)(param_2 + 0xec0) = 0;
      piVar6 = (int *)func_020d22d0();
      uVar3 = (uint)(piVar6 + 2) & 3;
      uVar2 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
      uVar11 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar10 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
               *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
      uVar3 = (uint)(piVar6 + 1) & 3;
      uVar8 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar10 * (ulonglong)uVar11;
      uVar13 = (uint)lVar1;
      uVar2 = (uint)(piVar6 + 4) & 3;
      uVar4 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
      uVar15 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
      uVar2 = (uint)(piVar6 + 3) & 3;
      uVar9 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
      uVar4 = (uint)(piVar6 + 5) & 3;
      uVar12 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
      *piVar6 = uVar15 + uVar13;
      piVar6[1] = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) +
                  (uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20) * uVar10 +
                  uVar11 * (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar15,uVar13);
      uVar3 = (uint)(piVar6 + 1) & 3;
      uVar2 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
      *(int *)(param_2 + 0xeb8) =
           (int)((ulonglong)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0xc >> 0x20) * 0x14;
      *(undefined4 *)(param_2 + 0xecc) = 1;
    }
    break;
  case 4:
    uVar3 = param_2 + 0xebcU & 3;
    uVar2 = *(uint *)(param_2 + 0xebcU & 0xfffffffc);
    if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 1) {
      *(undefined4 *)(param_2 + 0xec0) = 0;
      *(undefined4 *)(param_2 + 0xecc) = 5;
    }
    *(undefined4 *)(param_2 + 0xec8) = 0;
    break;
  case 5:
    *(short *)(param_2 + 0x7e) = *(short *)(param_2 + 0x7e) + -0x2d8;
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    *(uint *)(param_2 + 0xec0) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 2;
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    if (0x1b < (int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xec0) = 0x1c;
      *(undefined4 *)(param_2 + 0xecc) = 6;
    }
    *(undefined4 *)(param_2 + 0xec8) = 1;
    break;
  case 6:
    *(short *)(param_2 + 0x7e) = *(short *)(param_2 + 0x7e) + 0x2d8;
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 0xf) {
      *(undefined4 *)(param_2 + 0xec8) = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0xec8) = 1;
    }
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    *(uint *)(param_2 + 0xec0) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 2;
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    if ((int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) < 1) {
      *(undefined4 *)(param_2 + 0xec0) = 0;
      piVar6 = (int *)func_020d22d0();
      uVar3 = (uint)(piVar6 + 2) & 3;
      uVar2 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
      uVar11 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar10 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
               *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
      uVar3 = (uint)(piVar6 + 1) & 3;
      uVar8 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar10 * (ulonglong)uVar11;
      uVar15 = (uint)lVar1;
      uVar2 = (uint)(piVar6 + 4) & 3;
      uVar4 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
      uVar13 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
      uVar2 = (uint)(piVar6 + 3) & 3;
      uVar9 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
      uVar4 = (uint)(piVar6 + 5) & 3;
      uVar12 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
      *piVar6 = uVar13 + uVar15;
      piVar6[1] = (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) +
                  (uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20) * uVar10 +
                  uVar11 * (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar13,uVar15);
      uVar3 = (uint)(piVar6 + 1) & 3;
      uVar2 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
      *(int *)(param_2 + 0xeb8) =
           (int)((ulonglong)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0xc >> 0x20) * 0x14;
      *(undefined4 *)(param_2 + 0xecc) = 1;
    }
  }
  uVar3 = param_2 + 0xec8U & 3;
  uVar2 = *(uint *)(param_2 + 0xec8U & 0xfffffffc);
  if ((uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) ||
     ((*(ushort *)(param_2 + 2) & 0x12) != 0)) {
    *(undefined2 *)(param_2 + 0xec4) = 0;
    *(undefined2 *)(param_2 + 0xec6) = 0;
    uVar3 = param_2 + 0xed0U & 3;
    uVar2 = *(uint *)(param_2 + 0xed0U & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = uVar4 + 0x24;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar4 + 0x24) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20 | 2;
  }
  else {
    iVar14 = *(ushort *)(param_2 + 0xec4) + 1;
    iVar7 = StructMapObject_SomeFn_1
                      (*(uint *)(DAT_020979bc & 0xfffffffc) >> (DAT_020979bc & 3) * 8 |
                       *(uint *)(DAT_020979bc & 0xfffffffc) << (DAT_020979bc & 3) * -8 + 0x20);
    if (iVar7 <= iVar14) {
      iVar14 = 1;
    }
    *(short *)(param_2 + 0xec4) = (short)iVar14;
    iVar14 = *(ushort *)(param_2 + 0xec6) + 1;
    iVar7 = StructMapObject_SomeFn_2
                      (*(uint *)(DAT_020979bc & 0xfffffffc) >> (DAT_020979bc & 3) * 8 |
                       *(uint *)(DAT_020979bc & 0xfffffffc) << (DAT_020979bc & 3) * -8 + 0x20);
    if (iVar7 <= iVar14) {
      iVar14 = 1;
    }
    *(short *)(param_2 + 0xec6) = (short)iVar14;
    iVar7 = DAT_020979c0;
    uVar3 = param_2 + 0xed0U & 3;
    uVar2 = *(uint *)(param_2 + 0xed0U & 0xfffffffc);
    uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    uVar3 = uVar4 + 0x24;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar4 + 0x24) = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xfffffffd;
    uVar3 = param_2 + 0xec0U & 3;
    uVar2 = *(uint *)(param_2 + 0xec0U & 0xfffffffc);
    iVar14 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0xc;
    uVar3 = param_2 + 0xed0U & 3;
    uVar2 = *(uint *)(param_2 + 0xed0U & 0xfffffffc);
    func_02018f94(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,param_2 + iVar7 + iVar14,
                  param_2 + 0xd50 + iVar14);
  }
  iVar7 = 0;
  uVar3 = (uint)*(byte *)((*(uint *)(DAT_020979c4 & 0xfffffffc) >> (DAT_020979c4 & 3) * 8 |
                          *(uint *)(DAT_020979c4 & 0xfffffffc) << (DAT_020979c4 & 3) * -8 + 0x20) +
                         0x3d0);
  if (uVar3 == 0) {
    return;
  }
  do {
    iVar14 = param_2 + iVar7 * 4;
    uVar2 = iVar14 + 0xed4;
    uVar4 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    iVar7 = iVar7 + 1;
    if (0 < (int)uVar2) {
      *(uint *)(iVar14 + 0xed4) = uVar2 - 1;
    }
  } while (iVar7 < (int)uVar3);
  return;
}

