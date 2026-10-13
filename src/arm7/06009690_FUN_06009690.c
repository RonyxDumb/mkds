/* Decompiled C draft; module arm7; ROM address 06009690. No matching claim. */
#include "types.h"
#include "deps/06009690_FUN_06009690.h"

void FUN_06009690(ushort param_1,ushort param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_060096bc & 0xfffffffc) >> (DAT_060096bc & 3) * 8 |
          *(uint *)(DAT_060096bc & 0xfffffffc) << (DAT_060096bc & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x5f0) = ((ushort)DAT_060096c0 & param_1) + 5;
  *(ushort *)(uVar1 + 0x5f2) = param_2 | 1;
  return;
}

