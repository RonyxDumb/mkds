/* Decompiled C draft; module arm9_ov000; ROM address 021987c8. No matching claim. */
#include "types.h"
#include "deps/021987c8_FUN_021987c8.h"

undefined4 FUN_021987c8(int param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined1 auStack_40 [36];
  undefined4 local_c;
  int local_8;
  undefined4 *puStack_4;
  
  local_c = param_2;
  local_8 = param_3;
  puStack_4 = param_4;
  FUN_0219a61c(&local_c,&local_8);
  if (0 < local_8) {
    uVar1 = FUN_021a3690();
    *(undefined4 *)(param_1 + 0x38) = uVar1;
    if (*(int *)(param_1 + 0x38) == 0) {
      return 1;
    }
    func_0x02134eb8(*(int *)(param_1 + 0x38),local_c,local_8);
    *(int *)(param_1 + 0x3c) = local_8;
  }
  if (param_4 != (undefined4 *)0x0) {
    uVar1 = param_4[1];
    *(undefined4 *)(param_1 + 0x28) = *param_4;
    *(undefined4 *)(param_1 + 0x2c) = uVar1;
    uVar1 = param_4[3];
    *(undefined4 *)(param_1 + 0x30) = param_4[2];
    *(undefined4 *)(param_1 + 0x34) = uVar1;
  }
  FUN_02197be0(auStack_40);
  FUN_02197b34(param_1 + 0x68,auStack_40);
  FUN_02198f24(param_1,auStack_40);
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 0;
}

