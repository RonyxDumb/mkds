/* Decompiled C draft; module arm9; ROM address 0202f454. No matching claim. */
#include "types.h"
#include "deps/0202f454_SetSomeDispcntSubMask.h"

void SetSomeDispcntSubMask(uint param_1)

{
  *puRam0202f470 =
       (*(uint *)((uint)puRam0202f470 & 0xfffffffc) >> ((uint)puRam0202f470 & 3) * 8 |
       *(uint *)((uint)puRam0202f470 & 0xfffffffc) << ((uint)puRam0202f470 & 3) * -8 + 0x20) &
       uRam0202f474 | param_1;
  return;
}

