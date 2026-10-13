/* Decompiled C draft; module arm9_ov000; ROM address 0219cc30. No matching claim. */
#include "types.h"
#include "deps/0219cc30_FUN_0219cc30.h"

void FUN_0219cc30(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined1 auStack_50 [64];
  
  FUN_0219cb00();
  piVar1 = DAT_0219cc88;
  if ((param_3 != 0) && (param_1 == 0)) {
    *(undefined4 *)(*DAT_0219cc88 + 0x24) = param_2;
    func_0x0200d9e0((undefined4)(uintptr_t)(auStack_50),0x40,DAT_0219cc8c,*(undefined4 *)(*piVar1 + 0x28));
    FUN_0219cc00(*(undefined4 *)(*DAT_0219cc88 + 0x24),3,(undefined4)(uintptr_t)(auStack_50),DAT_0219cc90);
    return;
  }
  FUN_0219d734(6,DAT_0219cc84);
  return;
}

