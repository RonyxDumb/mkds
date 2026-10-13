/* Decompiled C draft; module arm7; ROM address 06008980. No matching claim. */
#include "types.h"
#include "deps/06008980_FUN_06008980.h"

void FUN_06008980(uint param_1)

{
  if (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 != 0 ||
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20 != 0) {
    FUN_06008fc8((*(uint *)(DAT_060089bc & 0xfffffffc) >> (DAT_060089bc & 3) * 8 |
                 *(uint *)(DAT_060089bc & 0xfffffffc) << (DAT_060089bc & 3) * -8 + 0x20) + 0x200);
    FUN_06008a8c(2,0xb);
  }
  return;
}

