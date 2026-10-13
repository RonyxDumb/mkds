/* Decompiled C draft; module arm9; ROM address 02020b2c. No matching claim. */
#include "types.h"
#include "deps/02020b2c_func_02020b2c.h"

void func_02020b2c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = SetMDValue(param_1,param_4,param_5);
  MaybeSoundSendCommand(0x12,param_1,param_2,param_3,uVar1);
  return;
}

