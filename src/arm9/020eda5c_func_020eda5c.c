/* Decompiled C draft; module arm9; ROM address 020eda5c. No matching claim. */
#include "types.h"
#include "deps/020eda5c_func_020eda5c.h"

void func_020eda5c(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x20U & 3;
  uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  iVar2 = 0;
  if ((int)uVar4 < 1) {
    return;
  }
  while (uVar3 = param_1 + iVar2 * 4 + 0x14, uVar1 = uVar3 & 3,
        uVar3 = *(uint *)(uVar3 & 0xfffffffc),
        (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) != param_2) {
    iVar2 = iVar2 + 1;
    if ((int)uVar4 <= iVar2) {
      return;
    }
  }
  uVar4 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar4 = iRam020edad4 + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  (*(code *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20))(param_1);
  uVar4 = param_1 + 0x20U & 3;
  uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  if (uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) {
    func_020ee6a8((undefined4 *)(uintptr_t)(param_1));
    return;
  }
  return;
}

