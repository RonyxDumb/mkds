/* Decompiled C draft; module arm9; ROM address 020efc74. No matching claim. */
#include "types.h"
#include "deps/020efc74_func_020efc74.h"

void func_020efc74(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar8;
  
  iVar2 = func_020f4090(param_2);
  if (iVar2 != 0) {
    *(int *)(param_1 + 0x1f0) = iVar2;
    *(undefined4 *)(param_1 + 500) = 1;
  }
  uVar7 = param_1 + 0x1f0U & 3;
  uVar3 = *(uint *)(param_1 + 0x1f0U & 0xfffffffc);
  uVar9 = param_1 + 0x1f0;
  if (uVar3 >> uVar7 * 8 != 0 || uVar3 << uVar7 * -8 + 0x20 != 0) {
    uVar7 = param_1 + 0x1fcU & 3;
    uVar3 = *(uint *)(param_1 + 0x1fcU & 0xfffffffc);
    uVar10 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
    func_020f3c54(uVar9,(uint *)(uintptr_t)(uVar9),uVar10 + 0x98);
    uVar3 = uVar10 + 0xa0 & 3;
    uVar4 = *(uint *)(uVar10 + 0xa0 & 0xfffffffc);
    uVar7 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x18;
    uVar1 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar8 = uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20;
    uVar7 = uVar10 + 0x98 & 3;
    uVar11 = *(uint *)(uVar10 + 0x98 & 0xfffffffc);
    uVar1 = uVar8 + 8 & 3;
    uVar6 = *(uint *)(uVar8 + 8 & 0xfffffffc);
    iVar2 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) -
            (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
    iVar5 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) -
            (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20);
    if (iRam020efd18 <=
        (int)((ulonglong)((longlong)iVar5 * (longlong)iVar5 + (longlong)iVar2 * (longlong)iVar2) >>
             0x20)) {
      func_020f3a58(uVar9,(uint *)(uintptr_t)(uVar9),uVar10 + 0x98);
      return;
    }
    return;
  }
  return;
}

