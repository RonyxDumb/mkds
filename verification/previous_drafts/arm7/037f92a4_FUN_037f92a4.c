/* Decompiled C draft; module arm7; ROM address 037f92a4. No matching claim. */
#include "types.h"
#include "deps/037f92a4_FUN_037f92a4.h"

void FUN_037f92a4(void)

{
  uint uVar1;
  uint uVar2;
  
  FUN_037faf70();
  uVar1 = DAT_037f92cc + 4U & 3;
  uVar2 = *(uint *)(DAT_037f92cc + 4U & 0xfffffffc);
  FUN_037f923c((uint *)(uintptr_t)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20),0);
  return;
}

