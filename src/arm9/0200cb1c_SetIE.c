/* Decompiled C draft; module arm9; ROM address 0200cb1c. No matching claim. */
#include "types.h"
#include "deps/0200cb1c_SetIE.h"

uint SetIE(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  puVar3 = puRam0200cb4c;
  puVar2 = puRam0200cb48;
  uVar1 = *puRam0200cb48;
  *puRam0200cb48 = 0;
  uVar4 = *(uint *)((uint)puVar3 & 0xfffffffc);
  *puVar3 = param_1;
  *puVar2 = uVar1;
  return uVar4 >> ((uint)puVar3 & 3) * 8 | uVar4 << ((uint)puVar3 & 3) * -8 + 0x20;
}

