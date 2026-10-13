/* Decompiled C draft; module arm9_ov000; ROM address 0219c990. No matching claim. */
#include "types.h"
#include "deps/0219c990_FUN_0219c990.h"

void FUN_0219c990(int param_1)

{
  code *pcVar1;
  
  if ((*DAT_0219c9c0 != 0) && (param_1 != 0)) {
    FUN_0219c384();
    pcVar1 = *(code **)(*DAT_0219c9c0 + 0x18);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(param_1,0,*(undefined4 *)(*DAT_0219c9c0 + 0x1c));
    }
    FUN_0219c93c();
  }
  return;
}

