/* Decompiled C draft; module arm9_ov000; ROM address 021ae290. No matching claim. */
#include "types.h"
#include "deps/021ae290_FUN_021ae290.h"

void FUN_021ae290(int param_1,undefined2 param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(DAT_021ae2cc + 4) + 0xa4);
  if (iVar2 != 0) {
    if (param_3 == DAT_021ae2d0) {
      param_3 = *DAT_021ae2d4;
    }
    *(undefined2 *)(iVar2 + 0x1a) = param_2;
    *(undefined2 *)(iVar2 + 0x18) = *(undefined2 *)(iVar2 + 0x1a);
    *(int *)(iVar2 + 0x20) = param_3;
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x20);
    if (param_1 == 0) {
      uVar1 = FUN_021ae340();
      *(undefined2 *)(iVar2 + 10) = uVar1;
      return;
    }
    *(short *)(iVar2 + 10) = (short)param_1;
  }
  return;
}

