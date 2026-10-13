/* Decompiled C draft; module arm9_ov001; ROM address 0218b928. No matching claim. */
#include "types.h"
#include "deps/0218b928_FUN_0218b928.h"

void FUN_0218b928(int param_1)

{
  undefined4 uVar1;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_02187218(param_1,8,0);
  func_0x0208b7bc(DAT_0218b998,param_1 + 4);
  func_0x0208b7bc(DAT_0218b99c,param_1 + 4);
  func_0x0208b7bc(DAT_0218b9a0,param_1 + 4);
  local_18 = *DAT_0218b9a4;
  local_10 = DAT_0218b9a4[2];
  local_c = DAT_0218b9a4[3];
  local_14 = param_1 + 4;
  local_c = func_0x020d4ef4(local_14,local_c,&stack0xfffffff8,DAT_0218b9a4 + 4);
  uVar1 = func_0x02108e7c();
  func_0x0210b734(&local_18,uVar1);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218b9a8;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218b9ac;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218b9b0;
  return;
}

