/* Decompiled C draft; module arm7; ROM address 037fbf70. No matching claim. */
#include "types.h"
#include "deps/037fbf70_FUN_037fbf70.h"

uint FUN_037fbf70(void)

{
  uint uVar1;
  
  uVar1 = (*(uint *)((uint)DAT_037fbf98 & 0xfffffffc) >> ((uint)DAT_037fbf98 & 3) * 8 |
          *(uint *)((uint)DAT_037fbf98 & 0xfffffffc) << ((uint)DAT_037fbf98 & 3) * -8 + 0x20) *
          DAT_037fbf9c + DAT_037fbfa0;
  *DAT_037fbf98 = uVar1;
  return uVar1 >> 0x10;
}

