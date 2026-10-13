/* Decompiled C draft; module arm9_ov000; ROM address 0219cfc0. No matching claim. */
#include "types.h"
#include "deps/0219cfc0_FUN_0219cfc0.h"

int FUN_0219cfc0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    switch(param_1) {
    case 1:
      uVar1 = 6;
      iVar2 = -0x32;
      break;
    case 2:
      uVar1 = 6;
      iVar2 = -0x1e;
      break;
    case 3:
      uVar1 = 6;
      iVar2 = -0x14;
      break;
    default:
      uVar1 = 0xb;
      iVar2 = -9;
      break;
    case 5:
      uVar1 = 6;
      iVar2 = -0x28;
      break;
    case 7:
      uVar1 = 6;
      iVar2 = -0x46;
    }
    FUN_0219d734(uVar1,iVar2 - DAT_0219d030);
    return param_1;
  }
  return 0;
}

