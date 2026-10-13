/* Decompiled C draft; module arm9_ov000; ROM address 021a8bc0. No matching claim. */
#include "types.h"
#include "deps/021a8bc0_FUN_021a8bc0.h"

undefined4 FUN_021a8bc0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 local_14;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  if (param_1 != 2) {
    return 0;
  }
  if (param_4 < 0x10) {
    return 0;
  }
  func_0x0214d1fc((ushort *)(uintptr_t)(param_2),&local_14,4);
  FUN_021a8bb0(local_14,&local_10);
  func_0x0200d9e0(param_3,0x10,DAT_021a8c18,local_d,local_e,local_f,local_10);
  return param_3;
}

