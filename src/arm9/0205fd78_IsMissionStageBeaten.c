/* Decompiled C draft; module arm9; ROM address 0205fd78. No matching claim. */
#include "types.h"
#include "deps/0205fd78_IsMissionStageBeaten.h"

bool IsMissionStageBeaten(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  char local_10;
  byte bStack_f;
  
  GetMissionLevelStageInfoByIds_from_thumb(param_1,param_2,(undefined4)(uintptr_t)(&local_10));
  if (local_10 == '\x01') {
    *param_3 = (uint)bStack_f;
  }
  return local_10 == '\x01';
}

