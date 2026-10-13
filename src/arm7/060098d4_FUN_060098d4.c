/* Decompiled C draft; module arm7; ROM address 060098d4. No matching claim. */
#include "types.h"
#include "deps/060098d4_FUN_060098d4.h"

void FUN_060098d4(int param_1,undefined4 param_2)

{
  thunk_FUN_037fa564((*(uint *)(DAT_06009930 & 0xfffffffc) >> (DAT_06009930 & 3) * 8 |
                     *(uint *)(DAT_06009930 & 0xfffffffc) << (DAT_06009930 & 3) * -8 + 0x20) +
                     DAT_06009934);
  thunk_FUN_037fa670((*(uint *)(DAT_06009930 & 0xfffffffc) >> (DAT_06009930 & 3) * 8 |
                     *(uint *)(DAT_06009930 & 0xfffffffc) << (DAT_06009930 & 3) * -8 + 0x20) +
                     DAT_06009934,(uint)(param_1 * DAT_06009938) >> 6,0,param_2,0);
  return;
}

