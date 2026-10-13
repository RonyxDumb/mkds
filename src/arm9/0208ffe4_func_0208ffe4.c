/* Decompiled C draft; module arm9; ROM address 0208ffe4. No matching claim. */
#include "types.h"
#include "deps/0208ffe4_func_0208ffe4.h"

void func_0208ffe4(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  uint uVar9;
  uint uVar12;
  
  iVar3 = func_0207c078();
  if (iVar3 == 0) {
    return;
  }
  piVar4 = (int *)func_0208537c();
  uVar1 = (uint)(piVar4 + 2) & 3;
  uVar8 = *(uint *)((uint)(piVar4 + 2) & 0xfffffffc);
  uVar9 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20;
  uVar7 = *(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
          *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20;
  uVar1 = (uint)(piVar4 + 1) & 3;
  uVar5 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
  lVar2 = (ulonglong)uVar7 * (ulonglong)uVar9;
  uVar13 = (uint)lVar2;
  uVar8 = (uint)(piVar4 + 4) & 3;
  uVar11 = *(uint *)((uint)(piVar4 + 4) & 0xfffffffc);
  uVar12 = uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20;
  uVar8 = (uint)(piVar4 + 3) & 3;
  uVar6 = *(uint *)((uint)(piVar4 + 3) & 0xfffffffc);
  uVar11 = (uint)(piVar4 + 5) & 3;
  uVar10 = *(uint *)((uint)(piVar4 + 5) & 0xfffffffc);
  *piVar4 = uVar12 + uVar13;
  piVar4[1] = (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) +
              (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) * uVar7 +
              uVar9 * (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
              (int)((ulonglong)lVar2 >> 0x20) + (uint)CARRY4(uVar12,uVar13);
  uVar1 = (uint)(piVar4 + 1) & 3;
  uVar8 = *(uint *)((uint)(piVar4 + 1) & 0xfffffffc);
  if (iRam02090084 <=
      (short)((ushort)((ushort)((uVar8 >> uVar1 * 8) >> 0x10) |
                      (ushort)((uVar8 << uVar1 * -8 + 0x20) >> 0x10)) >> 4)) {
    func_0207c47c(param_1,param_2);
    return;
  }
  func_0207c548(param_1,param_2);
  return;
}

