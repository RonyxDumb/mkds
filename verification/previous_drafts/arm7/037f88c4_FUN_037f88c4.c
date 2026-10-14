/* Decompiled C draft; module arm7; ROM address 037f88c4. No matching claim. */
#include "types.h"
#include "deps/037f88c4_FUN_037f88c4.h"

uint FUN_037f88c4(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  puVar3 = DAT_037f88f0;
  uVar1 = *DAT_037f88f0;
  *DAT_037f88f0 = 0;
  uVar2 = (uint)DAT_037f88f4 & 3;
  uVar4 = *(uint *)((uint)DAT_037f88f4 & 0xfffffffc);
  *DAT_037f88f4 = param_1;
  *puVar3 = uVar1;
  return uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
}

