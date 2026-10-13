/* Decompiled C draft; module arm9; ROM address 02133e04. No matching claim. */
#include "types.h"
#include "deps/02133e04_func_02133e04.h"

uint func_02133e04(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)GetAlphaFlagsRef();
  uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  *puVar1 = uVar2 & ~(param_1 & 0x1f | (param_1 & 0x1f0000) >> 8) ^
            (param_2 & 0x1f | (param_2 & 0x1f0000) >> 8);
  return uVar2 & 0x1f | (uVar2 & 0x1f00) << 8 | 0x40000000;
}

