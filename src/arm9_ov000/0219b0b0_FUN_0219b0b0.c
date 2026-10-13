/* Decompiled C draft; module arm9_ov000; ROM address 0219b0b0. No matching claim. */
#include "types.h"
#include "deps/0219b0b0_FUN_0219b0b0.h"

void FUN_0219b0b0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined1 uStack_18;
  undefined1 local_17;
  ushort local_16;
  undefined4 local_14;
  
  local_17 = 2;
  local_16 = (ushort)((uint)param_3 >> 8) & 0xff | (ushort)(param_3 << 8) & (ushort)DAT_0219b0e8;
  local_14 = param_2;
  FUN_0218e3e4(param_1,param_4,param_5,0,&uStack_18,8);
  return;
}

