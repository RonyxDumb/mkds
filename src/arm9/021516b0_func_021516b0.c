/* Decompiled C draft; module arm9; ROM address 021516b0. No matching claim. */
#include "types.h"
#include "deps/021516b0_func_021516b0.h"

void func_021516b0(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    *(char *)(param_2 + iVar1) =
         (char)((0xffffffffU >> (param_1 & 0xff) ^ 0xffffffff) >> (0x18U - iVar2 & 0xff));
    iVar2 = iVar2 + 8;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  return;
}

