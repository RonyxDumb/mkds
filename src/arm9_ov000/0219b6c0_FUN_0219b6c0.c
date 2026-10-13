/* Decompiled C draft; module arm9_ov000; ROM address 0219b6c0. No matching claim. */
#include "types.h"
#include "deps/0219b6c0_FUN_0219b6c0.h"

void FUN_0219b6c0(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  if (param_1 == 0) {
    *(undefined4 *)(*DAT_0219b700 + 0x30) = param_2;
    FUN_0219b8a8(3);
    FUN_0219d5bc();
  }
  else {
    FUN_0219b8a8(0);
  }
  pcVar1 = *(code **)(*DAT_0219b700 + 0x5c);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1,param_2,*(undefined4 *)(*DAT_0219b700 + 0x60));
  }
  return;
}

