/* Decompiled C draft; module arm9_ov000; ROM address 021aa7b4. No matching claim. */
#include "types.h"
#include "deps/021aa7b4_FUN_021aa7b4.h"

void FUN_021aa7b4(int *param_1)

{
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  undefined1 auStack_18 [16];
  
  FUN_021aa7f8((undefined4)(uintptr_t)(auStack_38),DAT_021aa7ec,param_1);
  FUN_021aa7f8((undefined4)(uintptr_t)(auStack_28),DAT_021aa7f0,param_1);
  FUN_021aa7f8((undefined4)(uintptr_t)(auStack_18),DAT_021aa7f4,param_1);
  func_0x0214d1fc((ushort *)(void *)(auStack_38),(uint *)(uintptr_t)(*param_1 + 0x20),0x30);
  return;
}

