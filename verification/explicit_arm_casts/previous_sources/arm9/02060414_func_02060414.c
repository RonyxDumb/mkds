/* Decompiled C draft; module arm9; ROM address 02060414. No matching claim. */
#include "types.h"
#include "deps/02060414_func_02060414.h"

uint func_02060414(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 auStack_28 [24];
  char local_10;
  byte bStack_f;
  
  CopyCupEntryTo_from_thumb(param_1,param_2,auStack_28);
  if (local_10 == '\0') {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (uint)bStack_f;
  }
  return uVar1;
}

