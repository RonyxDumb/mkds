/* Decompiled C draft; module arm9; ROM address 0208c504. No matching claim. */
#include "types.h"
#include "deps/0208c504_func_0208c504.h"

void func_0208c504(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
  return;
}

