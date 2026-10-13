/* Decompiled C draft; module arm7; ROM address 037f888c. No matching claim. */
#include "types.h"
#include "deps/037f888c_FUN_037f888c.h"

uint FUN_037f888c(uint param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  uint uVar3;
  
  puVar2 = DAT_037f88bc;
  uVar1 = *DAT_037f88bc;
  *DAT_037f88bc = 0;
  uVar3 = *(uint *)((uint)DAT_037f88c0 & 0xfffffffc) >> ((uint)DAT_037f88c0 & 3) * 8 |
          *(uint *)((uint)DAT_037f88c0 & 0xfffffffc) << ((uint)DAT_037f88c0 & 3) * -8 + 0x20;
  *DAT_037f88c0 = uVar3 | param_1;
  *puVar2 = uVar1;
  return uVar3;
}

