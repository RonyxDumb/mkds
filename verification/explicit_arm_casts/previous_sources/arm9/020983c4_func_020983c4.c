/* Decompiled C draft; module arm9; ROM address 020983c4. No matching claim. */
#include "types.h"
#include "deps/020983c4_func_020983c4.h"

void func_020983c4(undefined4 param_1,int param_2)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint uVar16;
  
  uVar8 = param_2 + 0xb4U & 3;
  uVar4 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
  switch(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) {
  case 0:
    uVar8 = (uint)(ushort)(*(short *)(param_2 + 0x1ba) - 1);
    if (uVar8 == 0x10000) {
      piVar5 = (int *)func_020d22d0();
      uVar8 = (uint)(piVar5 + 2) & 3;
      uVar4 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
      uVar11 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
      uVar10 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
               *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
      uVar8 = (uint)(piVar5 + 1) & 3;
      uVar9 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)uVar10 * (ulonglong)uVar11;
      uVar13 = (uint)lVar2;
      uVar4 = (uint)(piVar5 + 4) & 3;
      uVar6 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
      uVar16 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
      uVar4 = (uint)(piVar5 + 3) & 3;
      uVar12 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
      uVar6 = (uint)(piVar5 + 5) & 3;
      uVar15 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
      *piVar5 = uVar16 + uVar13;
      piVar5[1] = (uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20) +
                  (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) * uVar10 +
                  uVar11 * (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) +
                  (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar16,uVar13);
      uVar8 = (uint)(piVar5 + 1) & 3;
      uVar4 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      uVar7 = (ushort)((uVar4 >> uVar8 * 8) >> 0x10) |
              (ushort)((uVar4 << uVar8 * -8 + 0x20) >> 0x10);
    }
    else {
      piVar5 = (int *)func_020d22d0();
      if (uVar8 == 0) {
        uVar7 = 0;
      }
      else {
        uVar4 = (uint)(piVar5 + 2) & 3;
        uVar6 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
        uVar13 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
        uVar12 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
                 *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
        uVar4 = (uint)(piVar5 + 1) & 3;
        uVar10 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
        lVar2 = (ulonglong)uVar12 * (ulonglong)uVar13;
        uVar14 = (uint)lVar2;
        uVar6 = (uint)(piVar5 + 3) & 3;
        uVar15 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
        uVar9 = (uint)(piVar5 + 4) & 3;
        uVar11 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
        uVar16 = uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20;
        uVar9 = (uint)(piVar5 + 5) & 3;
        uVar11 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
        *piVar5 = uVar16 + uVar14;
        piVar5[1] = (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) +
                    (uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20) * uVar12 +
                    uVar13 * (uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) +
                    (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar16,uVar14);
        if (uVar8 == 0) {
          uVar4 = (uint)(piVar5 + 1) & 3;
          uVar6 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
          uVar16 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
        }
        uVar7 = (ushort)uVar16;
        if (uVar8 != 0) {
          uVar4 = (uint)(piVar5 + 1) & 3;
          uVar6 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
          uVar7 = (ushort)((ulonglong)uVar8 *
                           (ulonglong)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) >> 0x20);
        }
      }
    }
    *(ushort *)(param_2 + 0x1b8) = *(short *)(param_2 + 0x1b8) + uVar7 + 1;
    if (*(ushort *)(param_2 + 0x1ba) <= *(ushort *)(param_2 + 0x1b8)) {
      *(short *)(param_2 + 0x1b8) = *(short *)(param_2 + 0x1b8) - *(ushort *)(param_2 + 0x1ba);
    }
    *(undefined4 *)(param_2 + 0xb4) = 1;
    goto LAB_02098510;
  case 1:
LAB_02098510:
    uVar8 = param_2 + 0x1dcU & 3;
    uVar4 = *(uint *)(param_2 + 0x1dcU & 0xfffffffc);
    uVar6 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    bVar1 = false;
    uVar8 = param_2 + (uint)*(ushort *)(param_2 + 0x1b8) * 4 + 0x1bc;
    uVar4 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    if ((int)uVar6 < (int)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20)) {
      *(uint *)(param_2 + 0x1dc) = uVar6 + 0x6d;
      uVar4 = param_2 + 0x1dcU & 3;
      uVar9 = *(uint *)(param_2 + 0x1dcU & 0xfffffffc);
      uVar8 = param_2 + (uint)*(ushort *)(param_2 + 0x1b8) * 4 + 0x1bc;
      uVar6 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      bVar1 = (int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) <=
              (int)(uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20);
    }
    else {
      *(uint *)(param_2 + 0x1dc) = uVar6 - 0x6d;
      uVar4 = param_2 + 0x1dcU & 3;
      uVar9 = *(uint *)(param_2 + 0x1dcU & 0xfffffffc);
      uVar8 = param_2 + (uint)*(ushort *)(param_2 + 0x1b8) * 4 + 0x1bc;
      uVar6 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      if ((int)(uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) <=
          (int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20)) {
        bVar1 = true;
      }
    }
    if (bVar1) {
      piVar5 = (int *)func_020d22d0();
      uVar8 = (uint)(piVar5 + 2) & 3;
      uVar4 = *(uint *)((uint)(piVar5 + 2) & 0xfffffffc);
      uVar11 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
      uVar10 = *(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
               *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20;
      uVar8 = (uint)(piVar5 + 1) & 3;
      uVar9 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)uVar10 * (ulonglong)uVar11;
      uVar13 = (uint)lVar2;
      uVar4 = (uint)(piVar5 + 3) & 3;
      uVar12 = *(uint *)((uint)(piVar5 + 3) & 0xfffffffc);
      uVar6 = (uint)(piVar5 + 4) & 3;
      uVar15 = *(uint *)((uint)(piVar5 + 4) & 0xfffffffc);
      uVar16 = uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20;
      uVar6 = (uint)(piVar5 + 5) & 3;
      uVar15 = *(uint *)((uint)(piVar5 + 5) & 0xfffffffc);
      *piVar5 = uVar16 + uVar13;
      piVar5[1] = (uVar15 >> uVar6 * 8 | uVar15 << uVar6 * -8 + 0x20) +
                  (uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) * uVar10 +
                  uVar11 * (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) +
                  (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar16,uVar13);
      uVar8 = (uint)(piVar5 + 1) & 3;
      uVar4 = *(uint *)((uint)(piVar5 + 1) & 0xfffffffc);
      if ((int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) < 0) {
        *(undefined4 *)(param_2 + 0xb4) = 0;
      }
      else {
        *(undefined4 *)(param_2 + 0xb4) = 2;
      }
    }
    break;
  case 2:
    uVar8 = param_2 + 0x1ecU & 3;
    uVar4 = *(uint *)(param_2 + 0x1ecU & 0xfffffffc);
    uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    if ((-5 < (int)uVar8) && ((int)uVar8 < 5)) {
      *(undefined4 *)(param_2 + 0x1b4) = 0x1e;
      *(undefined4 *)(param_2 + 0xb4) = 3;
    }
    break;
  case 3:
    uVar8 = param_2 + 0x1b4U & 3;
    uVar4 = *(uint *)(param_2 + 0x1b4U & 0xfffffffc);
    uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    *(uint *)(param_2 + 0x1b4) = uVar8 - 1;
    if ((int)uVar8 < 1) {
      *(undefined4 *)(param_2 + 0x1b4) = 0;
      uVar8 = param_2 + 0x1e8U & 3;
      uVar4 = *(uint *)(param_2 + 0x1e8U & 0xfffffffc);
      if (DAT_0209885c <= (int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20)) {
        *(undefined4 *)(param_2 + 0x1e8) = 0x1000;
        *(undefined4 *)(param_2 + 0x1e4) = 0;
        *(undefined4 *)(param_2 + 500) = 0x7b;
        *(undefined4 *)(param_2 + 0xb4) = 4;
      }
    }
    else {
      uVar8 = param_2 + 0x1e0U & 3;
      uVar4 = *(uint *)(param_2 + 0x1e0U & 0xfffffffc);
      *(uint *)(param_2 + 0x1e0) = (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) + 0xa4;
    }
    break;
  case 4:
    uVar8 = param_2 + 0x1f0U & 3;
    uVar9 = *(uint *)(param_2 + 0x1f0U & 0xfffffffc);
    uVar4 = param_2 + 500U & 3;
    uVar6 = *(uint *)(param_2 + 500U & 0xfffffffc);
    *(uint *)(param_2 + 0x1f0) =
         (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) +
         (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
    uVar8 = param_2 + 500U & 3;
    uVar4 = *(uint *)(param_2 + 500U & 0xfffffffc);
    *(uint *)(param_2 + 500) = (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) - 8;
    uVar8 = param_2 + 500U & 3;
    uVar4 = *(uint *)(param_2 + 500U & 0xfffffffc);
    if (((int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) < 1) &&
       (uVar8 = param_2 + 0x1f0U & 3, uVar4 = *(uint *)(param_2 + 0x1f0U & 0xfffffffc),
       (int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) <= DAT_02098860)) {
      *(undefined4 *)(param_2 + 0xb4) = 5;
    }
    break;
  case 5:
    uVar8 = param_2 + 0x1f0U & 3;
    uVar9 = *(uint *)(param_2 + 0x1f0U & 0xfffffffc);
    uVar4 = param_2 + 500U & 3;
    uVar6 = *(uint *)(param_2 + 500U & 0xfffffffc);
    *(uint *)(param_2 + 0x1f0) =
         (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) +
         (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
    uVar8 = param_2 + 500U & 3;
    uVar4 = *(uint *)(param_2 + 500U & 0xfffffffc);
    *(uint *)(param_2 + 500) = (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) - 8;
    uVar8 = param_2 + 0x1f0U & 3;
    uVar4 = *(uint *)(param_2 + 0x1f0U & 0xfffffffc);
    if ((int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) < 0x1001) {
      *(undefined4 *)(param_2 + 0x1f0) = 0x1000;
      *(undefined4 *)(param_2 + 0x1e4) = 1;
    }
    uVar8 = param_2 + 0xa4U & 3;
    uVar9 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar4 = param_2 + 0xa8U & 3;
    uVar6 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    *(uint *)(param_2 + 0xa4) =
         (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) +
         (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
    uVar8 = param_2 + 0xa4U & 3;
    uVar9 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar4 = param_2 + 0xb0U & 3;
    uVar6 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    if ((int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) <=
        (int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20)) {
      uVar8 = param_2 + 0xacU & 3;
      uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    }
    uVar8 = param_2 + 0xa4U & 3;
    uVar4 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    if ((int)uVar8 >> 0xc == 10) {
      uVar8 = param_2 + 0x1fcU & 3;
      uVar4 = *(uint *)(param_2 + 0x1fcU & 0xfffffffc);
      func_02098f18((uint)*(ushort *)(param_2 + 0x1b8) * 0x24 + param_2 + 0xb8,
                    (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) + 0x46000);
      uVar8 = param_2 + 0x78U & 3;
      uVar4 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
      if (((uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) & 4) == 0) {
        uVar8 = param_2 + 0x70U & 3;
        uVar4 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
        uVar6 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
        uVar8 = DAT_02098864 + 0x68U & 3;
        uVar4 = *(uint *)(DAT_02098864 + 0x68U & 0xfffffffc);
        if (uVar6 == (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20)) {
          local_20 = 2;
        }
        else {
          uVar8 = DAT_02098864 + 0x8cU & 3;
          uVar4 = *(uint *)(DAT_02098864 + 0x8cU & 0xfffffffc);
          if (uVar6 == (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20)) {
            local_20 = 3;
          }
          else {
            local_20 = 4;
          }
        }
        local_24 = param_2 + 4;
        local_28 = DAT_02098868;
        local_1c = func_020d4ef4();
        func_0210b7a8(&local_28);
      }
    }
    else if (uVar8 == 0) {
      *(undefined4 *)(param_2 + 0x1b4) = 0x1e;
      *(undefined4 *)(param_2 + 0xb4) = 6;
    }
    break;
  case 6:
    uVar8 = param_2 + 0x1b4U & 3;
    uVar4 = *(uint *)(param_2 + 0x1b4U & 0xfffffffc);
    uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    *(uint *)(param_2 + 0x1b4) = uVar8 - 1;
    if ((int)uVar8 < 1) {
      *(undefined4 *)(param_2 + 0x1b4) = 0;
      *(undefined4 *)(param_2 + 0xb4) = 0;
    }
    else {
      uVar8 = param_2 + 0x1e0U & 3;
      uVar4 = *(uint *)(param_2 + 0x1e0U & 0xfffffffc);
      *(uint *)(param_2 + 0x1e0) = (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) - 0xa4;
    }
  }
  uVar8 = param_2 + 0x1e4U & 3;
  uVar4 = *(uint *)(param_2 + 0x1e4U & 0xfffffffc);
  if (uVar4 >> uVar8 * 8 != 0 || uVar4 << uVar8 * -8 + 0x20 != 0) {
    uVar8 = param_2 + 0x1e8U & 3;
    uVar9 = *(uint *)(param_2 + 0x1e8U & 0xfffffffc);
    uVar4 = param_2 + 0x1ecU & 3;
    uVar6 = *(uint *)(param_2 + 0x1ecU & 0xfffffffc);
    *(uint *)(param_2 + 0x1e8) =
         (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) +
         (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
    uVar8 = param_2 + 0x1ecU & 3;
    uVar4 = *(uint *)(param_2 + 0x1ecU & 0xfffffffc);
    *(uint *)(param_2 + 0x1ec) = (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) + 4;
    uVar8 = param_2 + 0x1e8U & 3;
    uVar4 = *(uint *)(param_2 + 0x1e8U & 0xfffffffc);
    if (0xfff < (int)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0x1ec) = 0xffffffae;
    }
  }
  uVar8 = param_2 + 0x1f0U & 3;
  uVar4 = *(uint *)(param_2 + 0x1f0U & 0xfffffffc);
  uVar6 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
  uVar8 = param_2 + 0x1e8U & 3;
  uVar4 = *(uint *)(param_2 + 0x1e8U & 0xfffffffc);
  lVar2 = (ulonglong)(((uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) + uVar6) - 0x1000) *
          0x2f000;
  lVar3 = (ulonglong)uVar6 * 0x17000;
  *(uint *)(param_2 + 0x1f8) =
       ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
       ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000);
  return;
}

