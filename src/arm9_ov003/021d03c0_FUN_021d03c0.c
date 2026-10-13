/* Decompiled C draft; module arm9_ov003; ROM address 021d03c0. No matching claim. */
#include "types.h"
#include "deps/021d03c0_FUN_021d03c0.h"

void FUN_021d03c0(int param_1)

{
  int iVar1;
  
  if (*(short *)(param_1 + 2) != 0) {
    FUN_021d079c(*(short *)(param_1 + 2));
    FUN_021d07b0(9);
    return;
  }
  switch(*(undefined2 *)(param_1 + 4)) {
  case 10:
    break;
  case 0xb:
    return;
  default:
    if ((code *)*DAT_021d0494 == (code *)0x0) {
      return;
    }
    (*(code *)*DAT_021d0494)(DAT_021d0498,DAT_021d04a4);
    return;
  }
  iVar1 = *DAT_021d0490;
  if (*(int *)(iVar1 + 0x44) == 2) {
    if (*(int *)(iVar1 + 0x40) == 4) {
      iVar1 = FUN_021d0388();
      if (iVar1 != 0) {
        return;
      }
      if ((code *)*DAT_021d0494 != (code *)0x0) {
        (*(code *)*DAT_021d0494)(DAT_021d0498,DAT_021d049c);
      }
      FUN_021d07b0(9);
      return;
    }
    if (*(int *)(iVar1 + 0x40) == 6) {
      return;
    }
  }
  else if (*(int *)(iVar1 + 0x44) == 4) {
    iVar1 = func_0x021450ec(iVar1 + DAT_021d04a0,0xd,7,0x44,1);
    if (iVar1 == 0) {
      FUN_021d07b0(5);
      return;
    }
    FUN_021d079c();
    FUN_021d07b0(9);
    return;
  }
  FUN_021d07b0(4);
  return;
}

