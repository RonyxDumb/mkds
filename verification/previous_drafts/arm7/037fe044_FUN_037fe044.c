/* Decompiled C draft; module arm7; ROM address 037fe044. No matching claim. */
#include "types.h"
#include "deps/037fe044_FUN_037fe044.h"

void FUN_037fe044(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_037fe2e4(param_1,iVar2);
    if (iVar1 != 0) {
      FUN_037fe088(iVar1,param_1,1);
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  return;
}

