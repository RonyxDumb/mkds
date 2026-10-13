/* Decompiled C draft; module arm9_ov001; ROM address 02187b2c. No matching claim. */
#include "types.h"
#include "deps/02187b2c_FUN_02187b2c.h"

void FUN_02187b2c(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_10;
  int iStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    local_3c = *DAT_02187b90;
    uStack_38 = DAT_02187b90[1];
    local_34 = DAT_02187b90[2];
    local_10 = param_1;
    iStack_c = param_2;
    iStack_8 = param_3;
    uStack_4 = param_4;
    func_0x020f4e78(param_1,&local_3c,param_2);
    if (param_3 != 0) {
      func_0x020f4dfc(&local_10,param_3,param_4);
      return;
    }
    local_30 = 0;
    local_2c = 0;
    local_28 = 0;
    func_0x020f4dfc(&local_10,&local_30,param_4);
  }
  return;
}

