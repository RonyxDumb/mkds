/* Decompiled C draft; module arm9_ov000; ROM address 0219e4e8. No matching claim. */
#include "types.h"
#include "deps/0219e4e8_FUN_0219e4e8.h"

int FUN_0219e4e8(int param_1)

{
  int iVar1;
  undefined4 unaff_r4;
  int unaff_r5;
  
  if (param_1 != 0) {
    switch(param_1) {
    case 1:
      unaff_r4 = 6;
      unaff_r5 = -0x32;
      break;
    case 2:
      unaff_r4 = 6;
      unaff_r5 = -0x3c;
      break;
    case 3:
      unaff_r4 = 6;
      unaff_r5 = -0x1e;
      break;
    case 4:
      unaff_r4 = 6;
      unaff_r5 = -0x50;
      break;
    case 5:
      unaff_r4 = 6;
      unaff_r5 = -0x14;
    }
    iVar1 = FUN_0219bab4();
    if (iVar1 == 2) {
      FUN_0219c990(unaff_r4,unaff_r5 - DAT_0219e584);
    }
    else if (iVar1 == 4) {
      FUN_0219d734(unaff_r4,unaff_r5 - DAT_0219e588);
    }
    else if (iVar1 == 5) {
      FUN_021a1a38(unaff_r4,unaff_r5 - DAT_0219e58c);
    }
    else {
      FUN_0219c384(unaff_r4,unaff_r5 - DAT_0219e590);
    }
    return param_1;
  }
  return 0;
}

