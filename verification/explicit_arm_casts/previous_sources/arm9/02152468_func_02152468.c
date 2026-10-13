/* Decompiled C draft; module arm9; ROM address 02152468. No matching claim. */
#include "types.h"
#include "deps/02152468_func_02152468.h"

void func_02152468(undefined4 param_1,undefined4 param_2)

{
  Mem_CpuFill8(param_1,0,0xc);
  FriendCode_SetProfileId_from_thumb(param_1,param_2);
  FriendCode_SetState_from_thumb(param_1,3);
  return;
}

