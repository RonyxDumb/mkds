/* Decompiled C draft; module arm9_ov000; ROM address 021a7064. No matching claim. */
#include "types.h"
#include "deps/021a7064_FUN_021a7064.h"

void FUN_021a7064(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_021a7088(param_3);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    *(char *)((int)puVar1 + 0xd) = (char)param_3;
    *(undefined1 *)(puVar1 + 3) = *(undefined1 *)(param_2 + 0x73);
  }
  return;
}

