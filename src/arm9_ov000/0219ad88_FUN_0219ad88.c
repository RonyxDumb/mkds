/* Decompiled C draft; module arm9_ov000; ROM address 0219ad88. No matching claim. */
#include "types.h"
#include "deps/0219ad88_FUN_0219ad88.h"

void FUN_0219ad88(undefined1 *param_1,undefined4 param_2)

{
  undefined1 auStack_84 [132];
  
  if (param_1 == (undefined1 *)0x0) {
    func_0x02135048(auStack_84,0x80,DAT_0219adac,DAT_0219adb0,param_2);
    param_1 = auStack_84;
  }
  FUN_0219adb4((undefined4)(uintptr_t)(param_1));
  return;
}

