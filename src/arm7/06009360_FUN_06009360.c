/* Decompiled C draft; module arm7; ROM address 06009360. No matching claim. */
#include "types.h"
#include "deps/06009360_FUN_06009360.h"

void FUN_06009360(ushort param_1)

{
  uint uVar1;
  
  thunk_FUN_037f8850(0x1000000);
  uVar1 = *(uint *)(DAT_060093a0 & 0xfffffffc) >> (DAT_060093a0 & 3) * 8 |
          *(uint *)(DAT_060093a0 & 0xfffffffc) << (DAT_060093a0 & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x3f4) = *(ushort *)(uVar1 + 0x3f4) | param_1;
  thunk_FUN_037f888c();
  FUN_06008a8c(2,0x15);
  return;
}

