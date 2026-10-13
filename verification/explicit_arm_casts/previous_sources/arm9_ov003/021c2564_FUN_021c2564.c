/* Decompiled C draft; module arm9_ov003; ROM address 021c2564. No matching claim. */
#include "types.h"
#include "deps/021c2564_FUN_021c2564.h"

int * FUN_021c2564(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_10 [4];
  
  piVar1 = (int *)FUN_021d1cd4(*(undefined4 *)(*DAT_021c25a0 + 0x60));
  iVar2 = FUN_021d14b8(param_1,auStack_10,4);
  piVar1[2] = iVar2;
  iVar2 = piVar1[2];
  *piVar1 = iVar2 + 0x30;
  piVar1[1] = iVar2 + *(int *)(iVar2 + 0x24) + 0x28;
  return piVar1;
}

