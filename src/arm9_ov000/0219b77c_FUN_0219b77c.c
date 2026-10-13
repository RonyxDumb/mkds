/* Decompiled C draft; module arm9_ov000; ROM address 0219b77c. No matching claim. */
#include "types.h"
#include "deps/0219b77c_FUN_0219b77c.h"

int FUN_0219b77c(int param_1)

{
  int unaff_r4;
  int iVar1;
  undefined4 unaff_r5;
  
  if (param_1 != 0) {
    switch(param_1) {
    case 1:
      unaff_r5 = 0xb;
      unaff_r4 = -1;
      break;
    case 2:
      unaff_r5 = 0xb;
      unaff_r4 = -2;
      break;
    case 3:
      unaff_r5 = 6;
      unaff_r4 = -10;
      break;
    case 4:
      unaff_r5 = 6;
      unaff_r4 = -0x14;
    }
    switch(*(undefined4 *)(*DAT_0219b830 + 0x24)) {
    default:
      iVar1 = unaff_r4 - DAT_0219b840;
      break;
    case 1:
      iVar1 = unaff_r4 - DAT_0219b834;
      FUN_0219c990(unaff_r5,iVar1);
      break;
    case 2:
      iVar1 = unaff_r4 - DAT_0219b834;
      FUN_0219c990(unaff_r5,iVar1);
      break;
    case 4:
      iVar1 = unaff_r4 - DAT_0219b83c;
      break;
    case 5:
      iVar1 = unaff_r4 - DAT_0219b838;
      FUN_021a1a38(unaff_r5,iVar1);
    }
    FUN_0219d734(unaff_r5,iVar1);
    return param_1;
  }
  return 0;
}

