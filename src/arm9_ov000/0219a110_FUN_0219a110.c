/* Decompiled C draft; module arm9_ov000; ROM address 0219a110. No matching claim. */
#include "types.h"
#include "deps/0219a110_FUN_0219a110.h"

undefined4
FUN_0219a110(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_30;
  ushort uStack_2e;
  undefined4 local_2c;
  undefined4 local_4;
  
  local_4 = param_4;
  FUN_0219a61c(&local_4,&param_5);
  iVar1 = FUN_0218e644(*param_1);
  if (iVar1 == 0) {
    return 1;
  }
  _local_30 = CONCAT22((ushort)((uint)param_3 >> 8) & 0xff |
                       (ushort)(param_3 << 8) & (ushort)DAT_0219a21c,0x200);
  local_2c = param_2;
  iVar1 = FUN_0218e3e4(*param_1,local_4,param_5,0,&local_30,8);
  if (iVar1 == -1) {
    iVar1 = FUN_0218e368(*param_1);
    if (iVar1 == -0xf) {
      iVar1 = FUN_0219922c((int)(uintptr_t)(param_1),param_2,param_3);
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      if ((iVar1 == -0x2a) || (iVar1 == -6)) {
        return 1;
      }
      if (iVar1 != -0x23) {
        FUN_0219a044((int)(uintptr_t)(param_1));
        return 0;
      }
    }
  }
  else if (param_1[10] != 0) {
    uVar2 = FUN_0219a5b0((int)(uintptr_t)(param_1),param_2,param_3);
    iVar1 = FUN_02197f28((int)(uintptr_t)(param_1),uVar2,param_2,param_3,0,local_4,param_5,1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

