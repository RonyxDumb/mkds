/* Decompiled C draft; module arm7; ROM address 037fe83c. No matching claim. */
#include "types.h"
#include "deps/037fe83c_FUN_037fe83c.h"

void FUN_037fe83c(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_037fe874;
  uVar2 = param_1 & 0xfffffffc;
  *DAT_037fe874 = uVar2;
  puVar1[1] = uVar2 + 0x10;
  puVar1[2] = *(uint *)(param_1 & 0xfffffffc);
  puVar1[3] = *(uint *)(uVar2 + 4);
  puVar1[4] = *(uint *)(uVar2 + 8);
  puVar1[5] = *(uint *)(uVar2 + 0xc);
  return;
}

