/* Decompiled C draft; module arm9_ov000; ROM address 02193c74. No matching claim. */
#include "types.h"
#include "deps/02193c74_FUN_02193c74.h"

int FUN_02193c74(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  if (param_2 == 0) {
    func_0x0213442c(DAT_02193d40,DAT_02193d44,0,DAT_02193d48);
  }
  if (param_4 == 0) {
    func_0x0213442c(DAT_02193d4c,DAT_02193d44,0,DAT_02193d50);
  }
  uVar1 = func_0x0213a434(param_4);
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_18 = 0;
  local_1c = param_3;
  iVar2 = FUN_02190b80(param_1,&local_2c,DAT_02193d54);
  if ((((iVar2 == 0) && (iVar2 = FUN_02190b58(param_1,&local_2c,param_3), iVar2 == 0)) &&
      (iVar2 = FUN_02190b80(param_1,&local_2c,DAT_02193d58), iVar2 == 0)) &&
     ((iVar2 = FUN_02190b58(param_1,&local_2c,uVar1), iVar2 == 0 &&
      (iVar2 = FUN_02190b80(param_1,&local_2c,DAT_02193d5c), iVar2 == 0)))) {
    local_18 = local_24;
    iVar2 = FUN_02190ba0(param_1,&local_2c,param_4,uVar1);
    if ((iVar2 == 0) && (iVar2 = FUN_02190c64(param_1,&local_2c,0), iVar2 == 0)) {
      FUN_0218dbc0(*(undefined4 *)(param_2 + 0x38),&local_2c);
      iVar2 = FUN_0218e320(0);
      *(int *)(param_2 + 0x10) = iVar2 + DAT_02193d60;
      iVar2 = 0;
    }
  }
  return iVar2;
}

