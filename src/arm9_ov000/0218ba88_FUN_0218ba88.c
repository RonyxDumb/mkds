/* Decompiled C draft; module arm9_ov000; ROM address 0218ba88. No matching claim. */
#include "types.h"
#include "deps/0218ba88_FUN_0218ba88.h"

int FUN_0218ba88(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  undefined1 local_34;
  byte bStack_33;
  undefined1 local_32;
  byte local_31;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined1 local_8;
  undefined1 local_7;
  
  if (*param_1 == 1) {
    FUN_0218ca58(param_1,0,0,2,0);
  }
  if (*param_1 == 1) {
    return 3;
  }
  uVar2 = param_5 + 9U & 0xffff;
  bStack_33 = (byte)uVar2 & (byte)((uint)DAT_0218bb3c >> 8);
  local_34 = (undefined1)(uVar2 >> 8);
  local_32 = local_34;
  local_31 = bStack_33;
  local_30 = 2;
  local_c = (undefined1)param_2;
  local_2f = local_c;
  local_b = (undefined1)((uint)param_2 >> 8);
  local_2e = local_b;
  local_a = (undefined1)((uint)param_2 >> 0x10);
  local_2d = local_a;
  local_9 = (undefined1)((uint)param_2 >> 0x18);
  local_2c = local_9;
  local_8 = (undefined1)param_3;
  local_2b = local_8;
  local_7 = (undefined1)((uint)param_3 >> 8);
  local_2a = local_7;
  iVar1 = FUN_0218cc48((int)(uintptr_t)(param_1),(undefined4)(uintptr_t)(&local_32),9);
  if (iVar1 == 0) {
    iVar1 = FUN_0218e420(*(undefined4 *)((int)param_1 + DAT_0218bb40),param_4,param_5,0);
    if (iVar1 < 0) {
      return 3;
    }
    iVar1 = 0;
  }
  return iVar1;
}

