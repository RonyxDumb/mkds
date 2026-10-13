/* Decompiled C draft; module arm9_ov001; ROM address 02190ee0. No matching claim. */
#include "types.h"
#include "deps/02190ee0_FUN_02190ee0.h"

void FUN_02190ee0(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_02187218(param_1,8,0);
  FUN_02187af4(param_1);
  FUN_021875c0(param_1,0,DAT_02190f9c,DAT_02190fa0,DAT_02190f98,0);
  FUN_021875c0(param_1,0,DAT_02190f9c,DAT_02190fa0,DAT_02190fa4,0);
  FUN_021875c0(param_1,0,DAT_02190f9c,DAT_02190fa0,DAT_02190fa8,0);
  FUN_021875c0(param_1,0,DAT_02190f9c,DAT_02190fa0,DAT_02190fac,0);
  FUN_021875c0(param_1,0,DAT_02190f9c,DAT_02190fa0,DAT_02190fb0,0);
  local_18 = *DAT_02190fb4;
  local_10 = DAT_02190fb4[2];
  local_c = DAT_02190fb4[3];
  local_14 = param_1 + 4;
  local_c = func_0x020d4ef4(local_14,local_c,&stack0xfffffff8,DAT_02190fb4 + 4);
  uVar1 = func_0x02108e7c();
  func_0x0210b734((uint)(uintptr_t)(&local_18),uVar1);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_02190fb8;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_02190fbc;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_02190fc0;
  return;
}

