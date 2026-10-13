/* Decompiled C draft; module arm7; ROM address 06009710. No matching claim. */
#include "types.h"
#include "deps/06009710_FUN_06009710.h"

void FUN_06009710(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  FUN_0600979c(param_1,param_2,0x12);
  if (param_4 != 0) {
    FUN_0600979c(param_1 + 0x28,param_3,param_4 + 1U >> 1);
  }
  return;
}

