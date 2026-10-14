/* Decompiled C draft; module arm7; ROM address 06008cec. No matching claim. */
#include "types.h"
#include "deps/06008cec_FUN_06008cec.h"

void FUN_06008cec(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_06008d44 & 0xfffffffc) >> (DAT_06008d44 & 3) * 8 |
          *(uint *)(DAT_06008d44 & 0xfffffffc) << (DAT_06008d44 & 3) * -8 + 0x20;
  FUN_06008c98(uVar1 + 0x194);
  FUN_06008c98(uVar1 + 0x1a0);
  FUN_06008c98(uVar1 + 0x1ac);
  FUN_06008c98(uVar1 + 0x1b8);
  FUN_06008c98(uVar1 + 0x1c4);
  FUN_06008c98(uVar1 + 0x1d0);
  FUN_06008c98(uVar1 + 0x1dc);
  FUN_06008c98(uVar1 + 0x1e8);
  return;
}

