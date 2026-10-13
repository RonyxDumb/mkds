/* Decompiled C draft; module arm9; ROM address 020d6538. No matching claim. */
#include "types.h"
#include "deps/020d6538_func_020d6538.h"

void func_020d6538(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x5c) =
       *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
       *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  *(int *)(param_1 + 100) = (int)*(short *)(param_2 + 4);
  *(int *)(param_1 + 0x68) = (int)*(short *)(param_2 + 6);
  *(int *)(param_1 + 0x6c) = (int)*(short *)(param_2 + 8);
  return;
}

