/* Decompiled C draft; module arm9_ov000; ROM address 021a9534. No matching claim. */
#include "types.h"
#include "deps/021a9534_FUN_021a9534.h"

void FUN_021a9534(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = iVar2 + DAT_021a9590;
  while( true ) {
    FUN_021ae228(param_1);
    *(undefined1 *)(iVar2 + DAT_021a9594) = 0;
    *(undefined1 *)(iVar2 + DAT_021a9598) = 1;
    FUN_021abd2c(iVar3);
    FUN_021ab7b4(iVar2 + DAT_021a959c);
    iVar1 = FUN_021a95a0(param_1);
    if (iVar1 == 0) break;
    FUN_021ae0c4(param_1);
    *(undefined2 *)(param_1 + 0x18) = *(undefined2 *)(param_1 + 0x1a);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x20);
  }
  *(undefined1 *)(iVar2 + DAT_021a9594) = 8;
  return;
}

