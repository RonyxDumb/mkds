/* Decompiled C draft; module arm7; ROM address 060086d0. No matching claim. */
#include "types.h"
#include "deps/060086d0_FUN_060086d0.h"

void FUN_060086d0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_06008724();
  iVar2 = thunk_FUN_037f9158();
  if (iVar2 != 1) {
    FUN_06008a8c(2,0x16);
    thunk_FUN_037f916c(uVar1);
    do {
      iVar2 = thunk_FUN_037f9158(uVar1);
    } while (iVar2 == 0);
  }
  return;
}

