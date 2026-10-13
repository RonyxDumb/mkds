/* Decompiled C draft; module arm7; ROM address 037f8850. No matching claim. */
#include "types.h"
#include "deps/037f8850_FUN_037f8850.h"

uint FUN_037f8850(uint param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint uVar3;
  
  puVar2 = DAT_037f8884;
  uVar1 = *DAT_037f8884;
  *DAT_037f8884 = 0;
  uVar3 = *(uint *)((uint)DAT_037f8888 & 0xfffffffc) >> ((uint)DAT_037f8888 & 3) * 8 |
          *(uint *)((uint)DAT_037f8888 & 0xfffffffc) << ((uint)DAT_037f8888 & 3) * -8 + 0x20;
  *DAT_037f8888 = uVar3 & ~param_1;
  *puVar2 = uVar1;
  return uVar3;
}

