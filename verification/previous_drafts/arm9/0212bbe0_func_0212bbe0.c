/* Decompiled C draft; module arm9; ROM address 0212bbe0. No matching claim. */
#include "types.h"
#include "deps/0212bbe0_func_0212bbe0.h"

void func_0212bbe0(uint param_1)

{
  *puRam0212bbf8 =
       (*(uint *)((uint)puRam0212bbf8 & 0xfffffffc) >> ((uint)puRam0212bbf8 & 3) * 8 |
       *(uint *)((uint)puRam0212bbf8 & 0xfffffffc) << ((uint)puRam0212bbf8 & 3) * -8 + 0x20) &
       ~param_1;
  return;
}

