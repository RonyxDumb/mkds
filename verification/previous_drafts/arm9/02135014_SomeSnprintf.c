/* Decompiled C draft; module arm9; ROM address 02135014. No matching claim. */
#include "types.h"
#include "deps/02135014_SomeSnprintf.h"

void SomeSnprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  SomeSnprintfImpl(param_1,0xffffffff,param_2,&uStack_8);
  return;
}

