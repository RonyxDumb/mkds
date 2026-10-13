/* Decompiled C draft; module arm9; ROM address 0208c4e8. No matching claim. */
#include "types.h"
#include "deps/0208c4e8_func_0208c4e8.h"

void func_0208c4e8(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x80U & 3;
  uVar2 = *(uint *)(param_1 + 0x80U & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
  return;
}

