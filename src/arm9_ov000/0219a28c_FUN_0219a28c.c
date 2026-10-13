/* Decompiled C draft; module arm9_ov000; ROM address 0219a28c. No matching claim. */
#include "types.h"
#include "deps/0219a28c_FUN_0219a28c.h"

undefined4 FUN_0219a28c(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *local_18;
  
  local_18 = (undefined4 *)0x0;
  iVar1 = FUN_0219a5b0(param_1,param_3,param_4);
  if (iVar1 != 0) {
    return 5;
  }
  local_18 = (undefined4 *)FUN_0219a3e8();
  if (local_18 != (undefined4 *)0x0) {
    func_0x02134de0(local_18,0,0xa0);
    *local_18 = param_3;
    *(short *)(local_18 + 1) = (short)param_4;
    local_18[2] = param_1;
    uVar2 = FUN_0218e8c4();
    local_18[7] = uVar2;
    local_18[0x22] = local_18[7];
    *(undefined2 *)(local_18 + 0x19) = 0;
    *(undefined2 *)((int)local_18 + 0x66) = 0;
    iVar1 = FUN_02197e60(local_18 + 0x11,*(undefined4 *)(param_1 + 0x3c));
    if ((iVar1 != 0) &&
       (iVar1 = FUN_02197e60(local_18 + 0x14,*(undefined4 *)(param_1 + 0x38)), iVar1 != 0)) {
      uVar2 = FUN_0218dc94(0x10,0x40,0);
      local_18[0x17] = uVar2;
      if (local_18[0x17] != 0) {
        uVar2 = FUN_0218dc94(0x10,0x40,0);
        local_18[0x18] = uVar2;
        if (local_18[0x18] != 0) {
          uVar2 = FUN_0218dc94(4,2,0);
          local_18[0x26] = uVar2;
          if (local_18[0x26] != 0) {
            uVar2 = FUN_0218dc94(4,2,0);
            local_18[0x27] = uVar2;
            if (local_18[0x27] != 0) {
              FUN_0218def0((int *)(uintptr_t)(*(undefined4 *)(param_1 + 0xc)),(undefined4)(uintptr_t)(&local_18));
              iVar1 = FUN_0219a5b0(param_1,param_3,param_4);
              *param_2 = iVar1;
              if (*param_2 != 0) {
                return 0;
              }
            }
          }
        }
      }
    }
  }
  if (local_18 != (undefined4 *)0x0) {
    FUN_021a3668(local_18[0x11]);
    FUN_021a3668(local_18[0x14]);
    if (local_18[0x17] != 0) {
      FUN_0218dc48();
    }
    if (local_18[0x18] != 0) {
      FUN_0218dc48();
    }
    if (local_18[0x26] != 0) {
      FUN_0218dc48();
    }
    if (local_18[0x27] != 0) {
      FUN_0218dc48();
    }
    FUN_021a3668((undefined4)(uintptr_t)(local_18));
  }
  return 1;
}

