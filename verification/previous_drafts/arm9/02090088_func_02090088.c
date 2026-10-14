/* Decompiled C draft; module arm9; ROM address 02090088. No matching claim. */
#include "types.h"
#include "deps/02090088_func_02090088.h"

void func_02090088(undefined4 param_1,int param_2)

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
  if (iVar3 != 0) {
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
    if (iRam0209018c <=
        (short)((ushort)((ushort)((uVar8 >> uVar1 * 8) >> 0x10) |
                        (ushort)((uVar8 << uVar1 * -8 + 0x20) >> 0x10)) >> 4)) {
      func_0207c47c(param_1,param_2);
      return;
    }
    func_0207c548(param_1,param_2);
    return;
  }
  uVar1 = param_2 + 0xb0U & 3;
  uVar8 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  if (uVar8 >> uVar1 * 8 == 0 && uVar8 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  uVar1 = param_2 + 0xb8U & 3;
  uVar8 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
  if (iRam02090190 <= (int)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20)) {
    return;
  }
  uVar1 = param_2 + 0xb4U & 3;
  uVar8 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
  if ((uVar8 >> uVar1 * 8 != 0 || uVar8 << uVar1 * -8 + 0x20 != 0) &&
     (uVar1 = param_2 + 0xbcU & 3, uVar8 = *(uint *)(param_2 + 0xbcU & 0xfffffffc),
     iRam0209018c < (int)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20))) {
    func_0207c548(param_1,param_2);
    return;
  }
  func_0207c47c(param_1,param_2);
  return;
}

