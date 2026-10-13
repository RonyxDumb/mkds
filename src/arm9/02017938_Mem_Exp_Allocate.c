/* Decompiled C draft; module arm9; ROM address 02017938. No matching claim. */
#include "types.h"
#include "deps/02017938_Mem_Exp_Allocate.h"

void Mem_Exp_Allocate(undefined4 param_1,int param_2,int param_3)

{
  if (param_2 == 0) {
    param_2 = 1;
  }
  if (-1 < param_3) {
    Mem_Exp_AllocFromHead();
    return;
  }
  Mem_Exp_AllocFromTail(param_1,param_2 + 3U & 0xfffffffc,-param_3);
  return;
}

