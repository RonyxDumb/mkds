/* Decompiled C draft; module arm9_ov000; ROM address 0218f15c. No matching claim. */
#include "types.h"
#include "deps/0218f15c_FUN_0218f15c.h"

undefined4
FUN_0218f15c(int *param_1,char *param_2,char *param_3,undefined4 param_4,undefined4 param_5,
            code *param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    return 2;
  }
  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {
    return 2;
  }
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    return 2;
  }
  if (param_6 == (code *)0x0) {
    FUN_02196590(param_1,DAT_0218f210);
    return 2;
  }
  if (*(int *)(*param_1 + DAT_0218f214) != 0) {
    local_34 = 0;
    uStack_30 = 0;
    local_2c = 0;
    uStack_28 = 0;
    local_24 = 0;
    uStack_20 = 0;
    local_1c = 0;
    uStack_18 = 0;
    (*param_6)(param_1,&local_34,param_7);
    return 0;
  }
  uVar1 = FUN_02191cb0(param_1,DAT_0218f218,DAT_0218f218,DAT_0218f218,DAT_0218f218,param_2,param_3,0
                       ,param_4,0,param_5,param_6,param_7);
  return uVar1;
}

