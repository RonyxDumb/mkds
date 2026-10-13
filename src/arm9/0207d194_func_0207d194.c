/* Decompiled C draft; module arm9; ROM address 0207d194. No matching claim. */
#include "types.h"
#include "deps/0207d194_func_0207d194.h"

void func_0207d194(int param_1,uint param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  short sVar10;
  uint uVar11;
  uint uVar13;
  uint uVar15;
  uint uVar12;
  uint uVar14;
  
  iVar3 = func_0207e654(param_2);
  if (iVar3 == 0) {
    func_0207cd74(param_1,param_2);
    return;
  }
  iVar3 = func_0207e64c(param_2);
  if (iVar3 == 0) {
    uVar4 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x78;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    func_0204360c(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,0x600);
    *(undefined4 *)(param_1 + 0x18) = 1;
    *(undefined2 *)(param_1 + 0x1e) = 2;
    *(undefined4 *)(param_1 + 0x10) = 0;
    uVar4 = param_1 + 8U & 3;
    uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    if (uVar4 != 0) {
      uVar4 = (uint)*(ushort *)(uVar4 + 10);
      piVar6 = (int *)func_0208537c();
      if (uVar4 == 0) {
        sVar10 = 0;
      }
      else {
        uVar5 = (uint)(piVar6 + 2) & 3;
        uVar11 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
        uVar12 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
        uVar9 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
                *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
        uVar5 = (uint)(piVar6 + 1) & 3;
        uVar7 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
        lVar2 = (ulonglong)uVar9 * (ulonglong)uVar12;
        uVar15 = (uint)lVar2;
        uVar11 = (uint)(piVar6 + 3) & 3;
        uVar8 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
        uVar1 = (uint)(piVar6 + 4) & 3;
        uVar13 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
        uVar14 = uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20;
        uVar1 = (uint)(piVar6 + 5) & 3;
        uVar13 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
        *piVar6 = uVar14 + uVar15;
        piVar6[1] = (uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) +
                    (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) * uVar9 +
                    uVar12 * (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) +
                    (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar14,uVar15);
        if (uVar4 == 0) {
          uVar5 = (uint)(piVar6 + 1) & 3;
          uVar11 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
          uVar14 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
        }
        sVar10 = (short)uVar14;
        if (uVar4 != 0) {
          uVar5 = (uint)(piVar6 + 1) & 3;
          uVar11 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
          sVar10 = (short)((ulonglong)uVar4 *
                           (ulonglong)(uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) >> 0x20);
        }
      }
      uVar4 = param_1 + 8U & 3;
      uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
      *(short *)(param_1 + 2) =
           *(short *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 8) + sVar10;
      return;
    }
    return;
  }
  uVar4 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 0x78;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  func_0204360c(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,0x600);
  *(undefined4 *)(param_1 + 0x14) = 1;
  *(undefined2 *)(param_1 + 0x1c) = 2;
  *(undefined4 *)(param_1 + 0x10) = 0;
  uVar4 = param_1 + 8U & 3;
  uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if (uVar4 != 0) {
    uVar4 = (uint)*(ushort *)(uVar4 + 10);
    piVar6 = (int *)func_0208537c();
    if (uVar4 == 0) {
      sVar10 = 0;
    }
    else {
      uVar5 = (uint)(piVar6 + 2) & 3;
      uVar11 = *(uint *)((uint)(piVar6 + 2) & 0xfffffffc);
      uVar12 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
      uVar9 = *(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
              *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20;
      uVar5 = (uint)(piVar6 + 1) & 3;
      uVar7 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
      lVar2 = (ulonglong)uVar9 * (ulonglong)uVar12;
      uVar15 = (uint)lVar2;
      uVar11 = (uint)(piVar6 + 3) & 3;
      uVar8 = *(uint *)((uint)(piVar6 + 3) & 0xfffffffc);
      uVar1 = (uint)(piVar6 + 4) & 3;
      uVar13 = *(uint *)((uint)(piVar6 + 4) & 0xfffffffc);
      uVar14 = uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20;
      uVar1 = (uint)(piVar6 + 5) & 3;
      uVar13 = *(uint *)((uint)(piVar6 + 5) & 0xfffffffc);
      *piVar6 = uVar14 + uVar15;
      piVar6[1] = (uVar13 >> uVar1 * 8 | uVar13 << uVar1 * -8 + 0x20) +
                  (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) * uVar9 +
                  uVar12 * (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) +
                  (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar14,uVar15);
      if (uVar4 == 0) {
        uVar5 = (uint)(piVar6 + 1) & 3;
        uVar11 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
        uVar14 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
      }
      sVar10 = (short)uVar14;
      if (uVar4 != 0) {
        uVar5 = (uint)(piVar6 + 1) & 3;
        uVar11 = *(uint *)((uint)(piVar6 + 1) & 0xfffffffc);
        sVar10 = (short)((ulonglong)uVar4 *
                         (ulonglong)(uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20) >> 0x20);
      }
    }
    uVar4 = param_1 + 8U & 3;
    uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
    *(short *)(param_1 + 2) =
         *(short *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 8) + sVar10;
    return;
  }
  return;
}

