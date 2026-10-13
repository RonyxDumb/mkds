/* Decompiled C draft; module arm9; ROM address 02060390. No matching claim. */
#include "types.h"
#include "deps/02060390_func_02060390.h"

int func_02060390(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 auStack_28 [24];
  char local_10;
  char cStack_b;
  
  CopyCupEntryTo_from_thumb(param_1,param_2,(undefined4)(uintptr_t)(auStack_28));
  if (local_10 == '\0') {
    iVar1 = -1;
  }
  else {
    iVar1 = (int)cStack_b;
  }
  return iVar1;
}

