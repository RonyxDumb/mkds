/* Decompiled C draft; module arm9_ov000; ROM address 021a7378. No matching claim. */
#include "types.h"
#include "deps/021a7378_FUN_021a7378.h"

undefined4 FUN_021a7378(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  FUN_021ae304(iVar1);
  switch(*(undefined1 *)(iVar1 + 0x73)) {
  case 0:
  case 4:
    FUN_021ae244(*(int *)(iVar1 + 0x68) + 0x20);
    FUN_021ae270();
    break;
  case 1:
    FUN_021ae270();
    FUN_021ae2d8();
    FUN_021ae214(DAT_021a73d4);
    break;
  case 2:
    FUN_021ae2d8();
  }
  *(undefined2 *)(iVar1 + 0x70) = 1;
  return 0;
}

