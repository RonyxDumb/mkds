/* Decompiled C draft; module arm9_ov000; ROM address 021a9228. No matching claim. */
#include "types.h"
#include "deps/021a9228_FUN_021a9228.h"

void FUN_021a9228(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  
  iVar2 = *(int *)(param_1 + 0xc);
  if (*(char *)(iVar2 + DAT_021a927c) == '\b') {
    local_2c = 0x15;
    local_2b = 3;
    local_2a = 0;
    local_29 = 0;
    local_28 = 2;
    local_27 = 1;
    local_26 = 0;
    uVar1 = FUN_021aa054(iVar2,&local_2c);
    FUN_021adcec(&local_2c,uVar1,0,0,param_1);
  }
  FUN_021ae0c4(param_1);
  *(undefined1 *)(iVar2 + DAT_021a927c) = 0;
  return;
}

