/* Decompiled C draft; module arm9_ov000; ROM address 0219e3e4. No matching claim. */
#include "types.h"
#include "deps/0219e3e4_FUN_0219e3e4.h"

int FUN_0219e3e4(int param_1,int param_2)

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
    case 5:
      iVar1 = 0;
      param_2 = 0;
      param_1 = 0;
      break;
    case 3:
      iVar1 = 6;
      param_2 = -10;
      break;
    case 4:
      iVar1 = 6;
      param_2 = -0x1e;
      break;
    case 6:
      iVar1 = 6;
      param_2 = -0x46;
      break;
    case 7:
      iVar1 = 6;
      param_2 = -0x50;
    }
    if (iVar1 != 0) {
      FUN_021a1a38(iVar1,param_2 - DAT_0219e458);
    }
    return param_1;
  }
  return 0;
}

