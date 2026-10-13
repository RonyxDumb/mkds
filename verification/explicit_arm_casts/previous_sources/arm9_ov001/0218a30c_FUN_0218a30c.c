/* Decompiled C draft; module arm9_ov001; ROM address 0218a30c. No matching claim. */
#include "types.h"
#include "deps/0218a30c_FUN_0218a30c.h"

void FUN_0218a30c(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_02187218(param_1,8,0);
  FUN_02187af4(param_1);
  FUN_021875c0(param_1,0,DAT_0218a3c8,0,DAT_0218a3c4,0);
  FUN_021875c0(param_1,0,DAT_0218a3c8,0,DAT_0218a3cc,0);
  FUN_021875c0(param_1,0,DAT_0218a3c8,0,DAT_0218a3d0,0);
  FUN_021875c0(param_1,0,DAT_0218a3c8,0,DAT_0218a3d4,0);
  FUN_021875c0(param_1,0,DAT_0218a3c8,0,DAT_0218a3d8,0);
  local_18 = *DAT_0218a3dc;
  local_10 = DAT_0218a3dc[2];
  local_c = DAT_0218a3dc[3];
  local_14 = param_1 + 4;
  local_c = func_0x020d4ef4(local_14,local_c,&stack0xfffffff8,DAT_0218a3dc + 4);
  uVar1 = func_0x02108e7c();
  func_0x0210b734(&local_18,uVar1);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218a3e0;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218a3e4;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218a3e8;
  return;
}

