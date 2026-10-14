/* Decompiled C draft; module arm9; ROM address 02060364. No matching claim. */
#include "types.h"
#include "deps/02060364_GetCupEntryRank.h"

undefined1 GetCupEntryRank(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_28 [24];
  char local_10;
  undefined1 uStack_a;
  
  CopyCupEntryTo_from_thumb(param_1,param_2,(undefined4)(uintptr_t)(auStack_28));
  if (local_10 == '\0') {
    uStack_a = 9;
  }
  return uStack_a;
}

