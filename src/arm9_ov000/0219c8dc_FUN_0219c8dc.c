/* Decompiled C draft; module arm9_ov000; ROM address 0219c8dc. No matching claim. */
#include "types.h"
#include "deps/0219c8dc_FUN_0219c8dc.h"

int FUN_0219c8dc(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = param_1;
    switch(param_1) {
    case 1:
      iVar1 = 0xb;
      param_2 = -1;
      break;
    case 2:
      iVar1 = 0xb;
      param_2 = -2;
      break;
    case 3:
      iVar1 = 6;
      param_2 = -10;
      break;
    case 4:
      iVar1 = 6;
      param_2 = -0x14;
    }
    FUN_0219c990(iVar1,param_2 - DAT_0219c938);
    return param_1;
  }
  return 0;
}

