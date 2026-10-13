/* Decompiled C draft; module arm9; ROM address 021284c0. No matching claim. */
#include "types.h"
#include "deps/021284c0_func_021284c0.h"

void func_021284c0(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = func_02128244(*(undefined4 *)(*piRam021284fc + 0xc));
  piVar1 = piRam021284fc;
  *(undefined4 *)(*piRam021284fc + iRam02128500) = uVar2;
  *(int *)(*piVar1 + 0xc) = *(int *)(*piVar1 + 0xc) + 1;
  if (9 < *(int *)(*piVar1 + 0xc)) {
    *(undefined4 *)(*piVar1 + 8) = 0;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
    *(undefined4 *)(*piVar1 + iRam02128504) = 0;
  }
  return;
}

