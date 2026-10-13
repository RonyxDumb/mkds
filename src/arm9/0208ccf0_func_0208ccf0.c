/* Decompiled C draft; module arm9; ROM address 0208ccf0. No matching claim. */
#include "types.h"
#include "deps/0208ccf0_func_0208ccf0.h"

void func_0208ccf0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x38U & 3;
  uVar2 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined2 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined2 *)(param_1 + 0x62) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  return;
}

