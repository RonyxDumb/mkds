/* Decompiled C draft; module arm9; ROM address 02025954. No matching claim. */
#include "types.h"
#include "deps/02025954_func_02025954.h"

void func_02025954(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_r5;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xf;
    switch(param_3) {
    case 0:
      param_1 = 4;
      unaff_r5 = 8;
      break;
    case 1:
      param_1 = 5;
      unaff_r5 = 9;
      break;
    case 2:
      param_1 = 6;
      unaff_r5 = 10;
      break;
    case 3:
      param_1 = 7;
      unaff_r5 = 0xb;
    }
  }
  else {
    uVar2 = 0x1f;
    switch(param_3) {
    case 0:
      param_1 = 0x14;
      unaff_r5 = 0x18;
      break;
    case 1:
      param_1 = 0x15;
      unaff_r5 = 0x19;
      break;
    case 2:
      param_1 = 0x16;
      unaff_r5 = 0x1a;
      break;
    case 3:
      param_1 = 0x17;
      unaff_r5 = 0x1b;
    }
  }
  iVar1 = *(int *)(param_2 + param_3 * 4);
  AllocateReserveTEQSub(param_1,0,*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x10));
  AllocateReserveTEQSub(uVar2,0,*(undefined4 *)(*(int *)(param_2 + 0x10) + 0xc),DAT_020259fc);
  iVar1 = *(int *)(param_2 + param_3 * 4 + 0x14);
  AllocateReserveTEQSub(unaff_r5,0,iVar1 + 0xc,*(undefined4 *)(iVar1 + 8));
  return;
}

