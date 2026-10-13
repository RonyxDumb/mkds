/* Decompiled C draft; module arm7; ROM address 06009860. No matching claim. */
#include "types.h"
#include "deps/06009860_FUN_06009860.h"

void FUN_06009860(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  thunk_FUN_037fa564((*(uint *)(DAT_060098c8 & 0xfffffffc) >> (DAT_060098c8 & 3) * 8 |
                     *(uint *)(DAT_060098c8 & 0xfffffffc) << (DAT_060098c8 & 3) * -8 + 0x20) +
                     DAT_060098cc);
  uVar1 = thunk_FUN_03806d38((uint)(param_1 * DAT_060098d0) >> 6,1000);
  thunk_FUN_037fa670((*(uint *)(DAT_060098c8 & 0xfffffffc) >> (DAT_060098c8 & 3) * 8 |
                     *(uint *)(DAT_060098c8 & 0xfffffffc) << (DAT_060098c8 & 3) * -8 + 0x20) +
                     DAT_060098cc,uVar1,0,param_2,0);
  return;
}

