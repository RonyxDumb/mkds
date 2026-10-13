/* Decompiled C draft; module arm9_ov000; ROM address 02188508. No matching claim. */
#include "types.h"
#include "deps/02188508_FUN_02188508.h"

void FUN_02188508(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = FUN_02188584(1);
  *(undefined4 *)(iVar2 + 0xc) = param_1;
  uVar1 = FUN_02188528();
  *(undefined1 *)(iVar2 + 10) = uVar1;
  return;
}

