/* Decompiled C draft; module arm9_ov000; ROM address 0219caac. No matching claim. */
#include "types.h"
#include "deps/0219caac_FUN_0219caac.h"

void FUN_0219caac(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  
  *DAT_0219caec = param_1;
  func_0x0214d168(param_1,0,DAT_0219caf0);
  piVar1 = DAT_0219caec;
  *(undefined4 *)*DAT_0219caec = param_3;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = param_4;
  *(undefined4 *)(*piVar1 + 0xc) = param_5;
  *(undefined4 *)(*piVar1 + 0x18) = param_6;
  *(undefined4 *)(*piVar1 + 0x1c) = param_7;
  *(undefined4 *)(*piVar1 + 0x20) = param_2;
  return;
}

