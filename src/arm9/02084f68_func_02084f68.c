/* Decompiled C draft; module arm9; ROM address 02084f68. No matching claim. */
#include "types.h"
#include "deps/02084f68_func_02084f68.h"

void func_02084f68(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 4U & 3;
  uVar1 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  uVar1 = 0;
  if (*(char *)(uVar2 + 0x18) == '\0') {
    return;
  }
  do {
    ModelBlock_SomeTexPltFn_1(uVar2,uVar1,1);
    uVar1 = uVar1 + 1;
  } while (uVar1 < *(byte *)(uVar2 + 0x18));
  return;
}

