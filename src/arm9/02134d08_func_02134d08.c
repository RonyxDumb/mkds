/* Decompiled C draft; module arm9; ROM address 02134d08. No matching claim. */
#include "types.h"
#include "deps/02134d08_func_02134d08.h"

void func_02134d08(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam02134d2c + 8U & 3;
  uVar2 = *(uint *)(iRam02134d2c + 8U & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
  return;
}

