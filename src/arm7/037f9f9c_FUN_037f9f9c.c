/* Decompiled C draft; module arm7; ROM address 037f9f9c. No matching claim. */
#include "types.h"
#include "deps/037f9f9c_FUN_037f9f9c.h"

uint FUN_037f9f9c(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  FUN_037faf70();
  uVar2 = DAT_037f9fd4 + param_1 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  puVar3 = (undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar2 = *(uint *)((uint)puVar3 & 0xfffffffc);
  *puVar3 = param_2;
  FUN_037faf84();
  return uVar2 >> ((uint)puVar3 & 3) * 8 | uVar2 << ((uint)puVar3 & 3) * -8 + 0x20;
}

