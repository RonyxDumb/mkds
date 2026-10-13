/* Decompiled C draft; module arm9; ROM address 0204ece0. No matching claim. */
#include "types.h"
#include "deps/0204ece0_func_0204ece0.h"

void func_0204ece0(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = func_020501b0();
  if (iVar1 != 0) {
    *(undefined1 *)(*piRam0204ecfc + iRam0204ed00) = param_1;
  }
  return;
}

