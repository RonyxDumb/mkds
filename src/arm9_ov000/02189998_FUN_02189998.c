/* Decompiled C draft; module arm9_ov000; ROM address 02189998. No matching claim. */
#include "types.h"
#include "deps/02189998_FUN_02189998.h"

int FUN_02189998(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 3) {
    if ((*(char *)(param_1 + DAT_02189a1c) == '\0') && (*(short *)(param_1 + DAT_02189a20) == 0)) {
      if (((uint)*(byte *)(param_1 + DAT_02189a24) << 0x18) >> 0x1c == 0) {
        param_2 = FUN_02189c04();
      }
      else {
        param_2 = 6;
      }
    }
    else {
      iVar1 = FUN_0218973c(1);
      if (iVar1 == 0) {
        param_2 = FUN_02189888(param_1);
      }
      else {
        param_2 = 4;
      }
    }
  }
  else if (param_2 == 4) {
    param_2 = FUN_02189888();
  }
  else if (param_2 == 5) {
    if (((uint)*(byte *)(param_1 + DAT_02189a24) << 0x18) >> 0x1c == 0) {
      param_2 = FUN_02189c04();
    }
    else {
      param_2 = 6;
    }
  }
  FUN_02189d2c(param_2);
  return param_2;
}

