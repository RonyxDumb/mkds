/* Decompiled C draft; module arm7; ROM address 037f881c. No matching claim. */
#include "types.h"
#include "deps/037f881c_FUN_037f881c.h"

uint FUN_037f881c(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  puVar3 = DAT_037f8848;
  uVar1 = *DAT_037f8848;
  *DAT_037f8848 = 0;
  uVar2 = (uint)DAT_037f884c & 3;
  uVar4 = *(uint *)((uint)DAT_037f884c & 0xfffffffc);
  *DAT_037f884c = param_1;
  *puVar3 = uVar1;
  return uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
}

