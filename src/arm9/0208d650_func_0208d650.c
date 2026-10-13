/* Decompiled C draft; module arm9; ROM address 0208d650. No matching claim. */
#include "types.h"
#include "deps/0208d650_func_0208d650.h"

void func_0208d650(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x3cU & 3;
  uVar2 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0) {
    uVar4 = 0;
    do {
      uVar2 = param_1 + uVar4 * 4;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
      uVar2 = uVar3 + 0x24;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(uVar3 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffe | 1;
      *(undefined4 *)(param_1 + uVar4 * 4) = 0;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < 2);
    *(undefined4 *)(param_1 + 0x3c) = 0;
    return;
  }
  return;
}

