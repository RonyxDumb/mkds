/* Decompiled C draft; module arm7; ROM address 037f8db0. No matching claim. */
#include "types.h"
#include "deps/037f8db0_FUN_037f8db0.h"

uint FUN_037f8db0(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  FUN_037faf70();
  uVar1 = DAT_037f8de0 + 0xcU & 3;
  uVar2 = *(uint *)(DAT_037f8de0 + 0xcU & 0xfffffffc);
  *(undefined4 *)(DAT_037f8de0 + 0xc) = param_1;
  FUN_037faf84();
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

