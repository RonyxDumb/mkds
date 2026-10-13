/* Decompiled C draft; module arm9; ROM address 0208cd7c. No matching claim. */
#include "types.h"
#include "deps/0208cd7c_func_0208cd7c.h"

void func_0208cd7c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = param_1 + 0x38U & 3;
  uVar2 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  if (uVar2 >> uVar5 * 8 != 0 || uVar2 << uVar5 * -8 + 0x20 != 0) {
    uVar5 = 0;
    do {
      iVar4 = param_1 + uVar5 * 4;
      uVar2 = iVar4 + 0x10;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar2 = uVar3 + 0x24;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar3 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffff7;
      uVar2 = iVar4 + 0x18;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar5 = uVar5 + 1 & 0xffff;
      uVar2 = uVar3 + 0x24;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar3 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffff7;
    } while (uVar5 < 2);
  }
  func_0208cddc();
  return;
}

