/* Decompiled C draft; module arm9; ROM address 0208ceac. No matching claim. */
#include "types.h"
#include "deps/0208ceac_func_0208ceac.h"

void func_0208ceac(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x38U & 3;
  uVar2 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
    uVar4 = 0;
    do {
      uVar2 = param_1 + uVar4 * 4 + 0x10;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar2 = uVar3 + 0x24;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar4 = uVar4 + 1 & 0xffff;
      *(uint *)(uVar3 + 0x24) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 8;
    } while (uVar4 < 2);
  }
  func_0208cf5c();
  return;
}

