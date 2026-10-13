/* Decompiled C draft; module arm9_ov000; ROM address 0218f0a8. No matching claim. */
#include "types.h"
#include "deps/0218f0a8_FUN_0218f0a8.h"

undefined4 FUN_0218f0a8(int *param_1)

{
  undefined4 uVar1;
  code *in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    return 2;
  }
  if (in_stack_00000010 == (code *)0x0) {
    FUN_02196590(param_1,DAT_0218f124);
    return 2;
  }
  if (*(int *)(*param_1 + DAT_0218f128) != 0) {
    local_24 = 0;
    local_20 = 0;
    local_18 = 0;
    local_1c = DAT_0218f12c;
    (*in_stack_00000010)(param_1,&local_24,in_stack_00000014);
    return 0;
  }
  uVar1 = FUN_021960a4();
  return uVar1;
}

