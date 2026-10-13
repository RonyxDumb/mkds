/* Decompiled C draft; module arm9; ROM address 020603e8. No matching claim. */
#include "types.h"
#include "deps/020603e8_func_020603e8.h"

uint func_020603e8(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 auStack_28 [24];
  char local_10;
  byte bStack_e;
  
  CopyCupEntryTo_from_thumb(param_1,param_2,auStack_28);
  if (local_10 == '\0') {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)bStack_e;
  }
  return uVar1;
}

