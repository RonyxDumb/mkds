/* Decompiled C draft; module arm9; ROM address 02060440. No matching claim. */
#include "types.h"
#include "deps/02060440_CupHasRecord.h"

char CupHasRecord(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_28 [24];
  char local_10;
  
  CopyCupEntryTo_from_thumb(param_1,param_2,(undefined4)(uintptr_t)(auStack_28));
  if (local_10 == '\0') {
    local_10 = '\0';
  }
  return local_10;
}

