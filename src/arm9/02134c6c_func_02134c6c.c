/* Decompiled C draft; module arm9; ROM address 02134c6c. No matching claim. */
#include "types.h"
#include "deps/02134c6c_func_02134c6c.h"

void func_02134c6c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam02134c90 + 8U & 3;
  uVar1 = *(uint *)(iRam02134c90 + 8U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
  return;
}

