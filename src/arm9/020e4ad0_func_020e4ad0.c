/* Decompiled C draft; module arm9; ROM address 020e4ad0. No matching claim. */
#include "types.h"
#include "deps/020e4ad0_func_020e4ad0.h"

void func_020e4ad0(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar6 = param_1 + 0x14U & 3;
  uVar7 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) - iRam020e4dd0;
  VecFx32_Add(param_1 + 4,param_1 + 0x10,(int *)(uintptr_t)(param_1 + 4));
  uVar6 = param_1 + 4U & 3;
  uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar7 = param_1 + 0xb8U & 3;
  uVar3 = *(uint *)(param_1 + 0xb8U & 0xfffffffc);
  uVar9 = param_1 + 0x104U & 3;
  uVar8 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
          (longlong)
          (int)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) -
               (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20));
  uVar6 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar7 = param_1 + 0xc0U & 3;
  uVar3 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
  uVar9 = param_1 + 0x108U & 3;
  uVar8 = *(uint *)(param_1 + 0x108U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
          (longlong)
          (int)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) -
               (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20));
  *(uint *)(param_1 + 0x100) =
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) +
       ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
  uVar6 = param_1 + 0xbcU & 3;
  uVar8 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
  uVar7 = param_1 + 0x100U & 3;
  uVar5 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
  uVar9 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  iVar12 = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) +
           (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
  if (iVar12 <= (int)(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20)) {
    return;
  }
  uVar6 = param_1 + 0x78U & 3;
  uVar7 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  if (((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 4) == 0) {
    uVar6 = param_1 + 0x70U & 3;
    uVar7 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    uVar9 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar6 = iRam020e4dd4 + 0x68U & 3;
    uVar7 = *(uint *)(iRam020e4dd4 + 0x68U & 0xfffffffc);
    if (uVar9 == (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20)) {
      uStack_18 = 2;
    }
    else {
      uVar6 = iRam020e4dd4 + 0x8cU & 3;
      uVar7 = *(uint *)(iRam020e4dd4 + 0x8cU & 0xfffffffc);
      if (uVar9 == (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20)) {
        uStack_18 = 3;
      }
      else {
        uStack_18 = 4;
      }
    }
    iStack_1c = param_1 + 4;
    uStack_20 = uRam020e4dd8;
    uStack_14 = func_020d4ef4();
    func_0210b7a8((uint)(uintptr_t)(&uStack_20));
  }
  *(int *)(param_1 + 8) = iVar12;
  *(short *)(param_1 + 0xc4) = *(short *)(param_1 + 0xc4) + -1;
  if (*(short *)(param_1 + 0xc4) == 0) {
    *(undefined4 *)(param_1 + 0x14) = uRam020e4ddc;
    piVar4 = (int *)func_020d22d0();
    uVar6 = (uint)(piVar4 + 2) & 3;
    uVar7 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
    uVar10 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar8 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
            *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
    uVar6 = (uint)(piVar4 + 1) & 3;
    uVar3 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar8 * (ulonglong)uVar10;
    uVar13 = (uint)lVar1;
    uVar7 = (uint)(piVar4 + 4) & 3;
    uVar9 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
    uVar14 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    uVar7 = (uint)(piVar4 + 3) & 3;
    uVar5 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
    uVar9 = (uint)(piVar4 + 5) & 3;
    uVar11 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
    *piVar4 = uVar14 + uVar13;
    piVar4[1] = (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) +
                (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * uVar8 +
                uVar10 * (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar14,uVar13);
    uVar6 = (uint)(piVar4 + 1) & 3;
    uVar7 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
    *(short *)(param_1 + 0xc4) =
         (short)((uint)((int)((ulonglong)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * 3 >>
                             0x20) * 0x10000) >> 0x10) + 4;
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = 0x2000;
    piVar4 = (int *)func_020d22d0();
    uVar6 = (uint)(piVar4 + 2) & 3;
    uVar7 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
    uVar10 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar5 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
            *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
    uVar6 = (uint)(piVar4 + 1) & 3;
    uVar3 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar5 * (ulonglong)uVar10;
    uVar13 = (uint)lVar1;
    uVar7 = (uint)(piVar4 + 4) & 3;
    uVar9 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
    uVar14 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    uVar7 = (uint)(piVar4 + 3) & 3;
    uVar11 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
    uVar9 = (uint)(piVar4 + 5) & 3;
    uVar8 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
    *piVar4 = uVar14 + uVar13;
    piVar4[1] = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) +
                (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20) * uVar5 +
                uVar10 * (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar14,uVar13);
    uVar6 = (uint)(piVar4 + 1) & 3;
    uVar9 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
    uVar7 = param_1 + 0x14U & 3;
    uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    *(uint *)(param_1 + 0x14) =
         (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) +
         ((uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) >> 0x15);
  }
  uVar6 = param_1 + 0xb8U & 3;
  uVar7 = *(uint *)(param_1 + 0xb8U & 0xfffffffc);
  uVar9 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 4U & 3;
  uVar7 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if ((int)(uVar9 + 0x14000) < (int)uVar6) {
    *(int *)(param_1 + 0x10) = iRam020e4de0;
  }
  else if ((int)uVar6 < (int)(uVar9 - 0x14000)) {
    *(undefined4 *)(param_1 + 0x10) = uRam020e4de4;
  }
  else {
    piVar4 = (int *)func_020d22d0();
    uVar6 = (uint)(piVar4 + 2) & 3;
    uVar7 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
    uVar10 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
    uVar8 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
            *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
    uVar6 = (uint)(piVar4 + 1) & 3;
    uVar3 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar8 * (ulonglong)uVar10;
    uVar13 = (uint)lVar1;
    uVar7 = (uint)(piVar4 + 4) & 3;
    uVar9 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
    uVar14 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    uVar7 = (uint)(piVar4 + 3) & 3;
    uVar5 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
    uVar9 = (uint)(piVar4 + 5) & 3;
    uVar11 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
    *piVar4 = uVar14 + uVar13;
    piVar4[1] = (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) +
                (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * uVar8 +
                uVar10 * (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) +
                (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar14,uVar13);
    uVar6 = (uint)(piVar4 + 1) & 3;
    uVar7 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
    *(int *)(param_1 + 0x10) =
         (int)((ulonglong)uRam020e4de8 *
               (ulonglong)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) >> 0x20) + iRam020e4de0;
  }
  uVar6 = param_1 + 0xc0U & 3;
  uVar7 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
  uVar9 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0xcU & 3;
  uVar7 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if ((int)uVar6 <= (int)(uVar9 + 0x14000)) {
    if ((int)(uVar9 - 0x14000) <= (int)uVar6) {
      piVar4 = (int *)func_020d22d0();
      uVar6 = (uint)(piVar4 + 2) & 3;
      uVar7 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
      uVar10 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      uVar8 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
              *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
      uVar6 = (uint)(piVar4 + 1) & 3;
      uVar3 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
      lVar1 = (ulonglong)uVar8 * (ulonglong)uVar10;
      uVar13 = (uint)lVar1;
      uVar7 = (uint)(piVar4 + 4) & 3;
      uVar9 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
      uVar14 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
      uVar7 = (uint)(piVar4 + 3) & 3;
      uVar5 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
      uVar9 = (uint)(piVar4 + 5) & 3;
      uVar11 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
      *piVar4 = uVar14 + uVar13;
      piVar4[1] = (uVar11 >> uVar9 * 8 | uVar11 << uVar9 * -8 + 0x20) +
                  (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * uVar8 +
                  uVar10 * (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) +
                  (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar14,uVar13);
      uVar6 = (uint)(piVar4 + 1) & 3;
      uVar7 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
      *(int *)(param_1 + 0x18) =
           (int)((ulonglong)uRam020e4de8 *
                 (ulonglong)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) >> 0x20) +
           iRam020e4de0;
      return;
    }
    *(undefined4 *)(param_1 + 0x18) = uRam020e4de4;
    return;
  }
  *(int *)(param_1 + 0x18) = iRam020e4de0;
  return;
}

