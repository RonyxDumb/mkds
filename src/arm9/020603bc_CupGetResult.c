/* Decompiled C draft; module arm9; ROM address 020603bc. No matching claim. */
#include "types.h"
#include "deps/020603bc_CupGetResult.h"

undefined1 CupGetResult(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_28 [24];
  char local_10;
  undefined1 uStack_c;
  
  CopyCupEntryTo_from_thumb(param_1,param_2,(undefined4)(uintptr_t)(auStack_28));
  if (local_10 == '\0') {
    uStack_c = 3;
  }
  return uStack_c;
}

