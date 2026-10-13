/* Decompiled C draft; module arm9; ROM address 02133ddc. No matching claim. */
#include "types.h"
#include "deps/02133ddc_ChangeSomeAlphaFlags.h"

uint ChangeSomeAlphaFlags(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = (uint *)GetAlphaFlagsRef();
  uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  *puVar1 = uVar2 & ~param_1 ^ param_2;
  return uVar2;
}

