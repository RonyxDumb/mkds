/* Decompiled C draft; module arm9_ov000; ROM address 0219496c. No matching claim. */
#include "types.h"
#include "deps/0219496c_FUN_0219496c.h"

undefined4 FUN_0219496c(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar2 = (undefined4 *)(*param_1 + DAT_021949fc);
  if (param_2 < 1) {
    func_0x0213442c(DAT_02194a00,DAT_02194a04,0,DAT_02194a08);
    return 0;
  }
  iVar1 = FUN_02194934(param_1,param_2,&local_30);
  if (iVar1 == 0) {
    local_24 = 0;
    local_28 = 0;
    local_20 = 0;
    local_1c = 0;
    local_14 = 0;
    local_18 = 0;
    local_2c = param_2;
    FUN_0218def0(*puVar2);
    puVar2[1] = puVar2[1] + 1;
    iVar1 = FUN_02194934(param_1,param_2,&local_30);
    if (iVar1 == 0) {
      return 0;
    }
    return local_30;
  }
  return local_30;
}

