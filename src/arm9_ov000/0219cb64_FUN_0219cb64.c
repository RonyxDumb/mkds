/* Decompiled C draft; module arm9_ov000; ROM address 0219cb64. No matching claim. */
#include "types.h"
#include "deps/0219cb64_FUN_0219cb64.h"

void FUN_0219cb64(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,uint param_7)

{
  int *piVar1;
  uint uVar2;
  
  FUN_0219cb00();
  uVar2 = param_7;
  if (param_7 == DAT_0219cbf0) {
    if (param_5 == 0) {
      FUN_0219d734(6,DAT_0219cbf8);
    }
    else {
      piVar1 = (int *)*DAT_0219cbf4;
      if (*piVar1 == 1) {
        *(char *)((int)piVar1 + 0x1f) = *(char *)((int)piVar1 + 0x1f) + '\x01';
      }
      else {
        uVar2 = 0;
      }
    }
  }
  if ((uVar2 & DAT_0219cbfc) == 0) {
    if (param_5 == 0) {
      FUN_0219d734(6,DAT_0219cbf8);
      if (*(code **)(*DAT_0219cbf4 + 0x4c) != (code *)0x0) {
        (**(code **)(*DAT_0219cbf4 + 0x4c))(0,0,param_7);
      }
    }
    else if (*(code **)(*DAT_0219cbf4 + 0x4c) != (code *)0x0) {
      (**(code **)(*DAT_0219cbf4 + 0x4c))(1,param_3 - 2U < 2,param_7);
      return;
    }
  }
  return;
}

