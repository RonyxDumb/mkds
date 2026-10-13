/* Decompiled C draft; module arm9; ROM address 020dc7c0. No matching claim. */
#include "types.h"
#include "deps/020dc7c0_func_020dc7c0.h"

void func_020dc7c0(int param_1)

{
  ulonglong uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c [2];
  int local_24;
  
  uVar10 = param_1 + 0x84U & 3;
  uVar6 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((uint)*(ushort *)(param_1 + 0x1f8) < (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20)) {
    uVar10 = param_1 + 0x1f0U & 3;
    uVar6 = *(uint *)(param_1 + 0x1f0U & 0xfffffffc);
    VecFx32_Subtract(uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20,param_1 + 4,&local_38);
    uVar10 = param_1 + 500U & 3;
    uVar6 = *(uint *)(param_1 + 500U & 0xfffffffc);
    uVar7 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
    uVar6 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
    uVar10 = uVar7 + 8 & 3;
    uVar7 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    lVar2 = (longlong)(int)uVar6 * (longlong)(int)local_30;
    uVar12 = (uint)lVar2;
    lVar3 = (longlong)(int)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) *
            (longlong)(int)local_38;
    uVar10 = (uint)lVar3;
    uVar10 = (int)-(uVar12 - uVar10 >> 0xc |
                   ((int)((ulonglong)lVar2 >> 0x20) -
                   ((int)((ulonglong)lVar3 >> 0x20) + (uint)(uVar12 < uVar10))) * 0x100000) >> 0xc;
    if ((int)uVar10 < 0) {
      uVar10 = -uVar10;
    }
    uVar7 = (uint)((ulonglong)uVar10 * 0x7a) >> 0xc |
            (((int)uVar10 >> 0x1f) * 0x7a + (int)((ulonglong)uVar10 * 0x7a >> 0x20)) * 0x100000;
    local_2c[0] = uVar6 * uVar7;
    uVar10 = param_1 + 500U & 3;
    uVar6 = *(uint *)(param_1 + 500U & 0xfffffffc);
    uVar10 = (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) + 8;
    uVar6 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    local_24 = (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) * uVar7;
    uVar10 = param_1 + 0x1f0U & 3;
    uVar6 = *(uint *)(param_1 + 0x1f0U & 0xfffffffc);
    VecFx32_Add((uint)(uintptr_t)(local_2c),uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20,local_2c);
    VecFx32_Subtract((uint)(uintptr_t)(local_2c),param_1 + 0xa0,&local_38);
    uVar6 = func_020d6f78((uint)(uintptr_t)(&local_38),&local_38);
    uVar10 = param_1 + 0xf0U & 3;
    uVar7 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
    uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    if ((int)uVar10 < (int)uVar6) {
      uVar6 = uVar6 - ((int)uVar10 >> 1);
    }
    uVar10 = param_1 + 0x1ecU & 3;
    uVar7 = *(uint *)(param_1 + 0x1ecU & 0xfffffffc);
    uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    if ((int)uVar10 < (int)uVar6) {
      uVar6 = uVar10;
    }
    local_30 = (uint)((longlong)(int)local_30 * (longlong)(int)uVar6) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_30 * (longlong)(int)uVar6) >> 0x20) << 0x14;
    local_38 = (uint)((longlong)(int)local_38 * (longlong)(int)uVar6) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_38 * (longlong)(int)uVar6) >> 0x20) << 0x14;
    local_34 = (uint)((longlong)(int)local_34 * (longlong)(int)uVar6) >> 0xc |
               (int)((ulonglong)((longlong)(int)local_34 * (longlong)(int)uVar6) >> 0x20) << 0x14;
    VecFx32_Add((uint)(uintptr_t)(&local_38),param_1 + 0xa0,(int *)(uintptr_t)(param_1 + 0x1e0));
    *(short *)(param_1 + 0x1f8) = *(short *)(param_1 + 0x1f8) + 0xb4;
  }
  VecFx32_Subtract(param_1 + 0x1e0,param_1 + 4,&local_38);
  uVar10 = param_1 + 0x10U & 3;
  uVar6 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) =
       (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) +
       ((local_38 << 5) >> 0xc | (((int)local_38 >> 0x1f) << 5 | local_38 >> 0x1b) << 0x14);
  uVar10 = param_1 + 0x18U & 3;
  uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) =
       (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) +
       ((local_30 << 5) >> 0xc | (((int)local_30 >> 0x1f) << 5 | local_30 >> 0x1b) << 0x14);
  uVar6 = uRam020dcc00;
  uVar10 = param_1 + 0x18U & 3;
  uVar7 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar12 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
  uVar10 = param_1 + 0x10U & 3;
  uVar7 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar10 * (longlong)(int)uVar10 +
          (longlong)(int)uVar12 * (longlong)(int)uVar12;
  piVar8 = (int *)(param_1 + 0x10);
  piVar5 = (int *)(param_1 + 0x18);
  if ((int)(uint)((uint)lVar2 < 0x40000000) <= (int)((ulonglong)lVar2 >> 0x20)) {
    uVar10 = param_1 + 0x10U & 3;
    uVar7 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    lVar2 = (ulonglong)uRam020dcc00 * (ulonglong)uVar10;
    *piVar8 = (*(uint *)((uint)piVar8 & 0xfffffffc) >> ((uint)piVar8 & 3) * 8 |
              *(uint *)((uint)piVar8 & 0xfffffffc) << ((uint)piVar8 & 3) * -8 + 0x20) -
              ((uint)lVar2 >> 0xc |
              (((int)uVar10 >> 0x1f) * uRam020dcc00 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000);
    uVar10 = param_1 + 0x18U & 3;
    uVar7 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    lVar2 = (ulonglong)uVar6 * (ulonglong)uVar10;
    *piVar5 = (*(uint *)((uint)piVar5 & 0xfffffffc) >> ((uint)piVar5 & 3) * 8 |
              *(uint *)((uint)piVar5 & 0xfffffffc) << ((uint)piVar5 & 3) * -8 + 0x20) -
              ((uint)lVar2 >> 0xc |
              (((int)uVar10 >> 0x1f) * uVar6 + (int)((ulonglong)lVar2 >> 0x20)) * 0x100000);
  }
  uVar10 = param_1 + 0xf0U & 3;
  uVar6 = *(uint *)(param_1 + 0xf0U & 0xfffffffc);
  iVar9 = (int)(uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) >> 1;
  lVar2 = (longlong)(int)local_38 * (longlong)(int)local_38 +
          (longlong)(int)local_30 * (longlong)(int)local_30;
  iVar11 = (int)((ulonglong)lVar2 >> 0x20);
  lVar3 = (longlong)iVar9 * (longlong)iVar9;
  iVar9 = (int)((ulonglong)lVar3 >> 0x20);
  bVar13 = (uint)lVar2 < (uint)lVar3;
  if ((int)(iVar11 - (iVar9 + (uint)bVar13)) < 0 ==
      (SBORROW4(iVar11,iVar9) != SBORROW4(iVar11 - iVar9,(uint)bVar13))) {
    uVar10 = func_02148538(local_38,local_30);
    func_020d7b34((((int)uVar10 >> 0x1f) * uRam020dcc04 +
                   uVar10 * iRam020dcc08 +
                   (int)((ulonglong)uRam020dcc04 * (ulonglong)uVar10 >> 0x20) + 0x800) * 0x10 >>
                  0x10,(undefined4 *)(uintptr_t)(param_1 + 0xd4));
  }
  else {
    uVar10 = param_1 + 0x10U & 3;
    uVar6 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    *(int *)(param_1 + 0x10) = (int)(uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) >> 1;
    uVar10 = param_1 + 0x18U & 3;
    uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    *(int *)(param_1 + 0x18) = (int)(uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) >> 1;
  }
  uVar10 = param_1 + 0x18U & 3;
  uVar12 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar6 = param_1 + 0x10U & 3;
  uVar7 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  lVar2 = (longlong)(int)(uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) *
          (longlong)(int)local_38;
  lVar3 = (longlong)(int)uVar6 * (longlong)(int)local_30;
  uVar1 = (longlong)(int)local_38 * (longlong)(int)local_38 +
          (longlong)(int)local_30 * (longlong)(int)local_30;
  lVar4 = (uVar1 & 0xffffffff) * 10;
  iVar9 = ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14) -
          ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  lVar2 = (longlong)iVar9 * (longlong)iVar9;
  iVar9 = (int)((ulonglong)lVar2 >> 0x20);
  iVar11 = (int)(uVar1 >> 0x20) * 10 + (int)((ulonglong)lVar4 >> 0x20);
  bVar13 = (uint)lVar4 < (uint)lVar2;
  if ((int)(iVar11 - (iVar9 + (uint)bVar13)) < 0 !=
      (SBORROW4(iVar11,iVar9) != SBORROW4(iVar11 - iVar9,(uint)bVar13))) {
    *(int *)(param_1 + 0x10) = (int)uVar6 >> 1;
    uVar10 = param_1 + 0x18U & 3;
    uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    *(int *)(param_1 + 0x18) = (int)(uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) >> 1;
  }
  uVar10 = param_1 + 4U & 3;
  uVar12 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar6 = param_1 + 0x10U & 3;
  uVar7 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 4) =
       (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) +
       (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
  uVar10 = param_1 + 0xcU & 3;
  uVar12 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar6 = param_1 + 0x18U & 3;
  uVar7 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0xc) =
       (uVar12 >> uVar10 * 8 | uVar12 << uVar10 * -8 + 0x20) +
       (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20);
  VecFx32_Subtract(param_1 + 4,param_1 + 0xa0,&local_38);
  uVar10 = param_1 + 0x1ecU & 3;
  uVar6 = *(uint *)(param_1 + 0x1ecU & 0xfffffffc);
  uVar10 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
  lVar3 = (longlong)(int)uVar10 * (longlong)(int)uVar10;
  iVar9 = (int)((ulonglong)lVar3 >> 0x20);
  lVar2 = (longlong)(int)local_38 * (longlong)(int)local_38 +
          (longlong)(int)local_30 * (longlong)(int)local_30;
  iVar11 = (int)((ulonglong)lVar2 >> 0x20);
  bVar13 = (uint)lVar2 < (uint)lVar3;
  if ((int)(iVar11 - (iVar9 + (uint)bVar13)) < 0 ==
      (SBORROW4(iVar11,iVar9) != SBORROW4(iVar11 - iVar9,(uint)bVar13))) {
    func_020d6f78((uint)(uintptr_t)(&local_38),&local_38);
    uVar10 = param_1 + 0x1ecU & 3;
    uVar7 = *(uint *)(param_1 + 0x1ecU & 0xfffffffc);
    uVar6 = param_1 + 0xa0U & 3;
    uVar12 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
    lVar2 = (longlong)(int)local_38 *
            (longlong)(int)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20);
    *(uint *)(param_1 + 4) =
         (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) +
         ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    uVar10 = param_1 + 0x1ecU & 3;
    uVar7 = *(uint *)(param_1 + 0x1ecU & 0xfffffffc);
    uVar6 = param_1 + 0xa8U & 3;
    uVar12 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
    lVar2 = (longlong)(int)local_30 *
            (longlong)(int)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20);
    *(uint *)(param_1 + 0xc) =
         (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) +
         ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    uVar10 = param_1 + 0x10U & 3;
    uVar6 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar7 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
    uVar10 = param_1 + 0x18U & 3;
    uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    lVar2 = (longlong)(int)uVar7 * (longlong)(int)local_38;
    lVar3 = (longlong)(int)(uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) *
            (longlong)(int)local_30;
    uVar6 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uVar10 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
    if (0 < (int)(uVar6 + uVar10)) {
      *(uint *)(param_1 + 0x10) =
           uVar7 - ((uint)((ulonglong)local_38 * (ulonglong)uVar6) >> 0xc |
                   (((int)uVar6 >> 0x1f) * local_38 +
                   uVar6 * ((int)local_38 >> 0x1f) +
                   (int)((ulonglong)local_38 * (ulonglong)uVar6 >> 0x20)) * 0x100000);
      uVar6 = param_1 + 0x18U & 3;
      uVar7 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
      lVar2 = (longlong)(int)uVar10 * (longlong)(int)local_30;
      *(uint *)(param_1 + 0x18) =
           (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) -
           ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    }
  }
  uVar10 = param_1 + 0x84U & 3;
  uVar6 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  uVar10 = uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20;
  bVar13 = 0xb3 < uVar10;
  if (bVar13) {
    uVar10 = 3;
  }
  if (bVar13) {
    *(short *)(param_1 + 0x90) = (short)uVar10;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

