/* Decompiled C draft; module arm9; ROM address 0204cf5c. No matching claim. */
#include "types.h"
#include "deps/0204cf5c_SomeFileAsyncReadFunc.h"

void SomeFileAsyncReadFunc(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_20;
  int local_1c;
  undefined1 local_18;
  uint uVar8;
  
  iVar6 = iRam0204d0b0;
  uVar8 = param_1 + 0x38U & 3;
  uVar7 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if ((int)uVar8 < 0) {
    uVar8 = iRam0204d0b0 + 0xb04U & 3;
    uVar7 = *(uint *)(iRam0204d0b0 + 0xb04U & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    *(undefined4 *)(iRam0204d0b0 + 0xb04) = 0;
  }
  uVar7 = iVar6 + 0xb04U & 3;
  uVar1 = *(uint *)(iVar6 + 0xb04U & 0xfffffffc);
  if ((uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20) < uVar8) {
    *(uint *)(iVar6 + 0xb04) = uVar8;
    uVar8 = iVar6 + 0xafcU & 3;
    uVar7 = *(uint *)(iVar6 + 0xafcU & 0xfffffffc);
    uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
    if (uVar8 != 0) {
      uVar2 = Os_DisableIrq();
      uVar7 = iRam0204d0b4 + 0x18U & 3;
      uVar3 = *(uint *)(iRam0204d0b4 + 0x18U & 0xfffffffc);
      uVar1 = iRam0204d0b4 + 0x14U & 3;
      uVar9 = *(uint *)(iRam0204d0b4 + 0x14U & 0xfffffffc);
      (*(code *)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20))
                (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,0,uVar8);
      Os_RestoreIrq(uVar2);
    }
    uVar8 = iVar6 + 0xb04U & 3;
    uVar3 = *(uint *)(iVar6 + 0xb04U & 0xfffffffc);
    uVar7 = iRam0204d0b4 + 0x28U & 3;
    uVar1 = *(uint *)(iRam0204d0b4 + 0x28U & 0xfffffffc);
    iVar4 = MaybeBoundsCheck((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) +
                             (uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20) + -0xf);
    uVar2 = Os_DisableIrq();
    uVar8 = iRam0204d0b4 + 0x18U & 3;
    uVar1 = *(uint *)(iRam0204d0b4 + 0x18U & 0xfffffffc);
    uVar7 = iRam0204d0b4 + 0x14U & 3;
    uVar3 = *(uint *)(iRam0204d0b4 + 0x14U & 0xfffffffc);
    uVar5 = (*(code *)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20))
                      (uVar1 >> uVar8 * 8 | uVar1 << uVar8 * -8 + 0x20,(iVar4 + 0x1fU >> 2) << 4,0);
    Os_RestoreIrq(uVar2);
    *(undefined4 *)(iVar6 + 0xafc) = uVar5;
    uVar8 = iVar6 + 0xafcU & 3;
    uVar7 = *(uint *)(iVar6 + 0xafcU & 0xfffffffc);
    *(uint *)(iVar6 + 0x80) = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  }
  iVar4 = iRam0204d0b4;
  *(int *)(iRam0204d0b4 + 0x1c) = param_1;
  uVar8 = param_1 + 0x38U & 3;
  uVar11 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  uVar7 = iVar4 + 0x28U & 3;
  uVar1 = *(uint *)(iVar4 + 0x28U & 0xfffffffc);
  uVar10 = uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20;
  uVar7 = iVar6 + 0xb00U & 3;
  uVar9 = *(uint *)(iVar6 + 0xb00U & 0xfffffffc);
  uVar1 = param_1 + 0x2cU & 3;
  uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  local_1c = (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
             (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  local_20 = (uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20) << 8 |
             ((int)uVar10 >> 8 & 0xfU) << 4;
  local_18 = (undefined1)uVar10;
  iVar6 = func_02006d3c(1,&local_20,9,uRam0204d0b8);
  if (iVar6 == 0) {
    Os_Terminate();
    return;
  }
  return;
}

