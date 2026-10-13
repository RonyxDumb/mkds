/* Decompiled C draft; module arm9; ROM address 021527ac. No matching claim. */
#include "types.h"
#include "deps/021527ac_PlayerProfileInfo_Create_from_thumb.h"

void PlayerProfileInfo_Create_from_thumb(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 auStack_410 [1028];
  
  Mem_CpuFill8(param_1,0,0x40);
  *param_1 = 0x40;
  param_1[7] = 0;
  param_1[9] = param_2;
  FriendCode_CreateFrom_from_thumb(param_1 + 1);
  FriendCode_SetState_from_thumb(param_1 + 4,0);
  GenerateProfileInfoCrcLookupTable(auStack_410,uRam02152804);
  uVar1 = ComputeProfileInfoCrc(auStack_410,param_1,0x3c);
  param_1[0xf] = uVar1;
  param_1[8] = param_1[8] | 1;
  return;
}

