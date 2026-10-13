/* Decompiled C draft; module arm9; ROM address 02060318. No matching claim. */
#include "types.h"
#include "deps/02060318_func_02060318.h"

undefined4 func_02060318(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_28 [24];
  char local_10;
  
  CopyCupEntryTo_from_thumb(param_1,param_2,auStack_28);
  if (local_10 != '\0') {
    Mem_CpuCopy8(auStack_28,param_3,4);
    return 1;
  }
  return 0;
}

