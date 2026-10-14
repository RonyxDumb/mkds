/* Decompiled C draft; module arm7; ROM address 037fd3c0. No matching claim. */
#include "types.h"
#include "deps/037fd3c0_FUN_037fd3c0.h"

int FUN_037fd3c0(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_037fd400 & 0xfffffffc) >> (DAT_037fd400 & 3) * 8 |
          *(uint *)(DAT_037fd400 & 0xfffffffc) << (DAT_037fd400 & 3) * -8 + 0x20;
  if (uVar1 == 0) {
    return 0;
  }
  if (param_2 < 0x10) {
    return (uint)*(byte *)(param_1 + 1) * 0x24 + uVar1 + 0x20 + param_2 * 2;
  }
  return uVar1 + 0x260 + (param_2 + -0x10) * 2;
}

