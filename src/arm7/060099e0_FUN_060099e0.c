/* Decompiled C draft; module arm7; ROM address 060099e0. No matching claim. */
#include "types.h"
#include "deps/060099e0_FUN_060099e0.h"

void FUN_060099e0(int param_1,undefined4 param_2)

{
  uint uVar1;
  longlong lVar2;
  
  thunk_FUN_037fa564((*(uint *)(DAT_06009a54 & 0xfffffffc) >> (DAT_06009a54 & 3) * 8 |
                     *(uint *)(DAT_06009a54 & 0xfffffffc) << (DAT_06009a54 & 3) * -8 + 0x20) +
                     DAT_06009a58);
  uVar1 = (uint)(param_1 * DAT_06009a5c) >> 6;
  lVar2 = thunk_FUN_037fa278();
  lVar2 = lVar2 + (ulonglong)uVar1;
  thunk_FUN_037fa5f4((*(uint *)(DAT_06009a54 & 0xfffffffc) >> (DAT_06009a54 & 3) * 8 |
                     *(uint *)(DAT_06009a54 & 0xfffffffc) << (DAT_06009a54 & 3) * -8 + 0x20) +
                     DAT_06009a58,(int)lVar2,(int)((ulonglong)lVar2 >> 0x20),uVar1,0,param_2,0);
  return;
}

